#include "native_data_cd.h"
#include "psx_spu.h"
#include <stdio.h>
#include <string.h>

typedef struct AdCdFile
{
    const char *path;
    uint32 first_sector;
    uint32 sectors;
    uint32 header_bytes;
} AdCdFile;

#include "native_data_cd_files.h"

static FILE *ad_cd_files[sizeof(ad_cd_index) / sizeof(ad_cd_index[0])];
static XportCleanup ad_cd_previous_cleanup;

static sint32 ad_cd_find_sector(uint32 sector)
{
    for (uint32 i = 0u; i < sizeof(ad_cd_index) / sizeof(ad_cd_index[0]); ++i)
        if (sector >= ad_cd_index[i].first_sector && sector - ad_cd_index[i].first_sector < ad_cd_index[i].sectors)
            return (sint32)i;
    return -1;
}

static sint32 ad_cd_read(void *context, uint32 sector, uint8 buffer[2352], uint32 *sector_bytes)
{
    sint32 index = ad_cd_find_sector(sector);
    const AdCdFile *entry;
    FILE *file;
    if (index < 0 || !(file = ad_cd_files[index]))
        return 0;
    entry = &ad_cd_index[index];
    if (fseek(file, (long)(entry->header_bytes + (sector - entry->first_sector) * 2352u), SEEK_SET) != 0 ||
        xport_fread(buffer, 1u, 2352u, file) != 2352u)
        return 0;
    *sector_bytes = 2352u;
    return 1;
}

static CdlFILE *ad_cd_search(void *context, CdlFILE *output, const char *name)
{
    char normalized[260];
    uint32 length = 0u;
    while (*name == '/' || *name == '\\')
        ++name;
    if (strncmp(name, "DATA/", 5u) == 0)
        name += 5u;
    while (*name && *name != ';' && length < sizeof(normalized) - 1u)
    {
        char c = *name++;
        if (c >= 'a' && c <= 'z')
            c -= 'a' - 'A';
        normalized[length++] = c == '\\' ? '/' : c;
    }
    normalized[length] = 0;
    if (*name && *name != ';')
        return NULL;
    for (uint32 i = 0u; i < sizeof(ad_cd_index) / sizeof(ad_cd_index[0]); ++i)
    {
        const AdCdFile *entry = &ad_cd_index[i];
        if (strcmp(normalized, entry->path + 5u) == 0)
        {
            const char *base = strrchr(entry->path, '/') + 1;
            memset(output, 0, sizeof(*output));
            CdIntToPos((sint32)entry->first_sector, &output->pos);
            output->size = entry->sectors * 2048u;
            strncpy(output->name, base, sizeof(output->name) - 1u);
            return output;
        }
    }
    return NULL;
}

static void ad_cd_close(void *context)
{
    for (uint32 i = 0u; i < sizeof(ad_cd_files) / sizeof(ad_cd_files[0]); ++i)
    {
        if (ad_cd_files[i])
            fclose(ad_cd_files[i]);
        ad_cd_files[i] = NULL;
    }
}

static void ad_cd_cleanup(void)
{
    cd_unmount_image();
    if (ad_cd_previous_cleanup)
        ad_cd_previous_cleanup();
}

sint32 ad_data_cd_mount(void)
{
    XPORT_CD_SOURCE source = {0};
    const AdCdFile *last = &ad_cd_index[sizeof(ad_cd_index) / sizeof(ad_cd_index[0]) - 1u];
    source.sectors = last->first_sector + last->sectors;
    source.read_sector = ad_cd_read;
    source.search_file = ad_cd_search;
    source.close = ad_cd_close;
    return xport_cd_mount_source(&source);
}

sint32 ad_data_cd_install(void)
{
    if (!ad_data_cd_mount())
        return 0;
    ad_cd_previous_cleanup = xport_get_cleanup();
    xport_set_cleanup(ad_cd_cleanup);
    return 1;
}

sint32 ad_data_cd_prepare(uint32 command, uint32 argument)
{
    CdlLOC position;
    sint32 sector, index;
    FILE *file;
    if ((command != 2u && command != 6u && command != 27u) || !argument)
        return 1;
    position.minute = r_u8(argument);
    position.second = r_u8(argument + 1u);
    position.sector = r_u8(argument + 2u);
    position.track = 0;
    sector = CdPosToInt(&position);
    index = sector < 0 ? -1 : ad_cd_find_sector((uint32)sector);
    if (index < 0)
        return 0;
    if (ad_cd_files[index])
        return 1;
    // Prepare Web assets on the main thread before entering the CD owner's lock
    file = xport_fopen(ad_cd_index[index].path, "rb");
    if (!file)
        return 0;
    xport_audio_lock();
    ad_cd_files[index] = file;
    xport_audio_unlock();
    return 1;
}
