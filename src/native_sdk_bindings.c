#include "psx.h"
#include "xport.h"
#include <stdlib.h>
#include <string.h>
uint32 sub_8007DE14(void);
void native_sdk_dispatch_callback(uint32 target, uint32 argument0, uint32 argument1);
void native_sdk_stream_start(void);
void native_sdk_stream_stop(void);

/* Reviewed image-specific SDK state slots */
const uint32 xport_cd_ready_callback_address = 0x800925C4u;
const uint32 xport_cd_sync_callback_address = 0x800925C0u;
const uint32 xport_cd_status_address = 0x800925D0u;
const uint32 xport_cd_setloc_table_address = 0x80092538u;
const uint32 xport_spu_register_pointer_address = 0x800A4E14u;

/* Native CD module exports missing from the shared public header */
extern sint32 CdRead(sint32 count, uint32 *destination, sint32 mode);
extern sint32 CdReadSync(sint32 mode, uint8 *result);
extern sint32 CdInit(void);
extern sint32 CD_getsector(uint32 destination, uint32 words);

static void *native_guest_pointer(uint32 address, size_t bytes)
{
    return address ? psx_addr(address, bytes) : NULL;
}

uint32 sub_8007F438(uint32 mode) { return ChangeClearPAD(mode); }
uint32 sub_8007FF6C(uint32 mode)
{
    return (uint32)DrawSync((sint32)mode);
}

uint32 sub_8007FED0(uint32 enabled)
{
    if (r_u8(0x80093B66u) >= 2u)
        fprintf(stderr, "SetDispMask(%d)...\n", (sint32)enabled);
    if (!enabled)
        xport_guest_fill(0x80093BD0u, 255u, 20u);
    SetDispMask((sint32)enabled);
    w_u8(0x800B3273u, enabled ? 0u : 1u);
    return 3u;
}
uint32 sub_8007F8C8(uint32 mode)
{
    /* Use the existing native VSync scheduler for the original SDK boundary */
    return (uint32)VSync((sint32)mode);
}

uint32 sub_8007B7B4(uint32 sector, uint32 position)
{
    sint32 value = (sint32)(sector + 150u);
    sint32 seconds = value / 75;
    sint32 minutes = seconds / 60;
    sint32 frame = value % 75;
    seconds %= 60;
    w_u8(position + 2u, (uint32)(16 * (frame / 10) + frame % 10));
    w_u8(position + 1u, (uint32)(16 * (seconds / 10) + seconds % 10));
    w_u8(position, (uint32)(16 * (minutes / 10) + minutes % 10));
    return position;
}
static uint32 native_sdk_draw_area_word(uint32 command, sint16 x, sint16 y)
{
    sint16 max_x = (sint16)(r_u16(0x80093B68u) - 1u);
    sint16 max_y = (sint16)(r_u16(0x80093B6Au) - 1u);
    uint32 wide = (uint32)(r_u8(0x80093B64u) - 1u) < 2u;
    uint32 mask = wide ? 0xFFFu : 0x3FFu;
    uint32 shift = wide ? 12u : 10u;
    x = x < 0 ? 0 : x > max_x ? max_x : x;
    y = y < 0 ? 0 : y > max_y ? max_y : y;
    return command | ((uint32)x & mask) | (((uint32)y & mask) << shift);
}

uint32 sub_80080D84(uint32 packet, uint32 rectangle)
{
    uint32 end;
    w_u8(packet + 3u, 2u);
    w_u32(packet + 4u, native_sdk_draw_area_word(0xE3000000u,
        (sint16)r_u16(rectangle), (sint16)r_u16(rectangle + 2u)));
    end = native_sdk_draw_area_word(0xE4000000u,
        (sint16)(r_u16(rectangle) + r_u16(rectangle + 4u) - 1u),
        (sint16)(r_u16(rectangle + 2u) + r_u16(rectangle + 6u) - 1u));
    w_u32(packet + 8u, end);
    return end;
}
uint32 sub_80080800(uint32 destination)
{
    if (destination != 0u)
        memcpy(psx_addr(destination, 92u), psx_addr(0x80093B74u, 92u), 92u);
    return destination;
}
uint32 sub_800899C0(uint32 on_off, uint32 voice_mask)
{
    uint32 mask = voice_mask & 0xFFFFFFu;
    uint32 high = mask >> 16u;
    uint32 pending, opposite, result;
    if (on_off != 0u && on_off != 1u)
        return 1u;
    if ((r_u32(0x800A52DCu) & 1u) == 0u)
    {
        SpuSetKey((sint32)on_off, mask);
        result = r_u32(0x800A4E7Cu);
        result = on_off ? result | mask : result & ~mask;
        w_u32(0x800A4E7Cu, result);
        return result;
    }
    pending = on_off ? 0x800B6898u : 0x800B689Cu;
    opposite = on_off ? 0x800B689Cu : 0x800B6898u;
    w_u16(pending, mask);
    w_u16(pending + 2u, high);
    w_u32(0x800A4EA8u, r_u32(0x800A4EA8u) | 1u);
    result = r_u32(0x800A4EA4u);
    w_u32(0x800A4EA4u, on_off ? result | mask : result & ~mask);
    if ((r_u16(opposite) & mask) != 0u)
        w_u16(opposite, r_u16(opposite) & ~mask);
    result = r_u16(opposite + 2u) & high;
    if (result != 0u)
    {
        result = r_u16(opposite + 2u) & ~high;
        w_u16(opposite + 2u, result);
    }
    return result;
}
uint32 sub_80086EBC(uint32 attributes)
{
    SpuSetVoiceAttr((SpuVoiceAttr *)psx_addr(attributes, sizeof(SpuVoiceAttr)));
    return 0u;
}
uint32 sub_80086EE4(uint32 voice_mask)
{
    return (uint32)SpuGetKeyStatus(voice_mask);
}
uint32 sub_80080294(uint32 rectangle, uint32 buffer)
{
    PSX_RECT *rect = psx_addr(rectangle, sizeof(PSX_RECT));
    size_t bytes = rect->w > 0 && rect->h > 0 ? (size_t)rect->w * (size_t)rect->h * 2u : 0u;
    return (uint32)StoreImage(rect, native_guest_pointer(buffer, bytes));
}
uint32 sub_80085CC4(void) { return r_u32(0x80093CB8u); }
uint32 sub_8007D3F0(uint32 destination, uint32 filename) { return CdSearchFile(destination, filename); }
uint32 sub_8007B368(uint32 command, uint32 argument, uint32 result)
{
    return (uint32)CdControl((uint8)command, native_guest_pointer(argument, 8u), native_guest_pointer(result, 8u));
}
uint32 sub_8007B4A0(uint32 command, uint32 argument)
{
    uint8 opcode = (uint8)command;
    uint8 *parameter = native_guest_pointer(argument, 8u);
    uint32 previous_callback = r_u32(0x800925C0u);
    uint32 setloc_entry = 0x80092538u + 4u * opcode;
    sint32 retries = 3;

    for (;;)
    {
        w_u32(0x800925C0u, 0u);
        if (opcode != 1u && (r_u8(0x800925D0u) & 0x10u) != 0u)
            CD_cw(1u, NULL, NULL, 0u);
        if (parameter == NULL || r_u32(setloc_entry) == 0u ||
            CD_cw(2u, parameter, NULL, 0u) == 0)
        {
            w_u32(0x800925C0u, previous_callback);
            if (CD_cw(opcode, parameter, NULL, 1u) == 0)
                return 1u;
        }
        if (--retries == -1)
        {
            w_u32(0x800925C0u, previous_callback);
            return 0u;
        }
    }
}
uint32 sub_8007B5CC(uint32 command, uint32 argument, uint32 result)
{
    return (uint32)CdControlB((uint8)command, native_guest_pointer(argument, 8u), native_guest_pointer(result, 8u));
}
uint32 sub_8007A7AC(uint32 mode) { return (uint32)CdDiskReady((sint32)mode); }
extern void cd_bind_guest_dispatch_native(void (*dispatch)(uint32, uint32, uint32));
uint32 sub_8007D110(void) { cd_bind_guest_dispatch_native(native_sdk_dispatch_callback); return (uint32)CdInit(); }
uint32 sub_8007D2B4(uint32 mode) { uint32 result = (uint32)CdRead2((sint16)mode); if (result) native_sdk_stream_start(); return result; }
uint32 sub_8007B350(uint32 callback) { return CdReadyCallbackPSX(callback); }
uint32 sub_8007A438(uint32 sectors, uint32 destination, uint32 mode)
{
    size_t bytes = (size_t)sectors * ((mode & 0x20u) ? 2340u : 2048u);
    return (uint32)CdRead((sint32)sectors, native_guest_pointer(destination, bytes), (sint32)mode);
}
uint32 sub_8007A53C(uint32 mode, uint32 result)
{
    return (uint32)CdReadSync((sint32)mode, native_guest_pointer(result, 8u));
}
uint32 sub_8007CE2C(uint32 destination, uint32 words)
{
    /* The original low-level helper returns zero after a completed DMA */
    if (!CD_getsector(destination, words))
        abort();
    return 0u;
}
uint32 sub_80080230(uint32 rectangle, uint32 buffer)
{
    PSX_RECT *rect = native_guest_pointer(rectangle, sizeof(PSX_RECT));
    size_t bytes = (size_t)(uint16)rect->w * (uint16)rect->h * 2u;
    return (uint32)LoadImagePSX(rect, native_guest_pointer(buffer, bytes));
}
uint32 sub_80080474(uint32 ordering, uint32 count)
{
    ClearOTagR(native_guest_pointer(ordering, (size_t)count * 4u), (sint32)count);
    /* The reviewed image uses its static terminator at the head */
    w_u32(ordering, 0x00093C20u);
    return ordering;
}
uint32 sub_8008056C(uint32 ordering)
{
    DrawOTag(native_guest_pointer(ordering, 4u));
    /* The synchronous queue path returns zero at original 8008216C */
    return 0u;
}
void sub_80083868(uint32 matrix)
{
    uint32 index;
    for (index = 0u; index < 5u; ++index)
        xport_gte_write_control(16u + index, r_u32(matrix + 4u * index));
}
void sub_80083898(uint32 distance, uint32 projection)
{
    SetFogNear((sint32)distance, (sint32)projection);
}
void SetFogNear(sint32 distance, sint32 projection)
{
    uint32 product = 0u - 320u * (uint32)distance;
    if (projection == 0 || (projection == -1 && product == 0x80000000u))
        abort();
    xport_gte_write_control(27u, (uint32)((sint32)product / projection));
    xport_gte_write_control(28u, 0x01400000u);
}

uint32 sub_8007ECE0(uint32 callback)
{
    uint32 previous = r_u32(0x800BCD00u);
    w_u32(0x800BCD00u, callback);
    return previous;
}
void sub_8007E9D0(uint32 buffer, uint32 count)
{
    uint32 index;
    w_u32(0x800C15E0u, buffer);
    w_u32(0x800C15E4u, count);
    w_u32(0x800BE514u, 0u);
    w_u32(0x800BE50Cu, 0u);
    w_u32(0x800BE508u, 0u);
    w_u32(0x800BBEF8u, 0u);
    for (index = 0u; index < count; ++index)
        w_u32(r_u32(0x800C15E0u) + 32u * index, 0u);
    w_u32(0x800B5894u, 0u);
    w_u16(0x800B4880u, 0u);
    w_u32(0x800B347Cu, 0u);
}
uint32 sub_8007EA60(uint32 data_out, uint32 header_out)
{
    for (uint32 pump = 0u; pump < r_u32(0x800C15E4u); ++pump) {
        uint32 available = r_u32(0x800C15E0u) + 32u * r_u32(0x800BE514u);
        if (r_u16(available) == 2u) break;
        if (sub_8007DE14() == 4u) break;
    }
    uint32 header = r_u32(0x800C15E0u) + 32u * r_u32(0x800BE514u);
    if (r_u16(header) == 1u) {
        w_u32(0x800BE514u, 0u);
        if (r_u32(0x800C15D4u))
            w_u16(header, 0u);
        header = r_u32(0x800C15E0u) + 32u * r_u32(0x800BE514u);
    }
    if (r_u16(header) != 2u)
        return 1u;
    w_u16(header, 4u);
    w_u32(data_out, r_u32(0x800C15E0u) + 32u * r_u32(0x800C15E4u) + 2016u * r_u32(0x800BE514u));
    w_u32(header_out, header);
    return 0u;
}
uint32 sub_8007EC14(uint32 data)
{
    uint32 delta = data - (r_u32(0x800C15E0u) + 32u * r_u32(0x800C15E4u));
    sint32 slot = ((sint32)delta >> 2) / 504;
    uint32 header = r_u32(0x800C15E0u) + 32u * (uint32)slot;
    sint32 count = (sint16)r_u16(header + 6u);
    sint32 index = 0;
    if ((sint16)r_u16(header) != 4)
        return 1u;
    for (; index < count; ++index)
        w_u16(r_u32(0x800C15E0u) + 32u * ((uint32)slot + (uint32)index), 0u);
    w_u32(0x800BE514u, (uint32)slot + (uint32)index);
    return 0u;
}

extern void sub_8007E9B0(uint32 first, uint32 second, uint32 third);
void sub_8007D368(uint32 mode, uint32 channel, uint32 limit, uint32 mask, uint32 entry_sp)
{
    uint32 callback = r_u32(entry_sp + 0x10u);
    sub_8007E9B0(1u, channel, limit);
    w_u32(0x800C15D0u, 0u);
    w_u32(0x800B588Cu, mask);
    w_u32(0x800B4884u, mode & 1u);
    w_u32(0x800BA8B4u, 0u);
    w_u32(0x800B68ACu, 0u);
    w_u16(0x800B4880u, 0u);
    w_u32(0x800B347Cu, 0u);
    w_u32(0x800B5890u, callback);
}

#include "game_scene.h"
#include "draft_adapters.h"
extern uint32 sub_80042130(GameSceneCallContext *context);
extern sint32 cd_read_sector_native(uint8 output[2352]);
static uint32 native_data_callback;
static uint32 native_stream_active;
static void native_stream_complete(void)
{
    uint32 header = r_u32(0x800C15E0u) + 32u * r_u32(0x800BE50Cu);
    w_u16(header, 2u);
    w_u32(0x800B3224u, r_u32(header + 28u));
    w_u32(0x800B3228u, r_u32(header + 8u));
    w_u32(0x800BE50Cu, r_u32(0x800BE508u));
    uint32 callback = r_u32(0x800B588Cu);
    if (callback) native_sdk_dispatch_callback(callback, 0u, 0u);
    w_u32(0x800BBEF8u, 0u);
}
void native_sdk_dispatch_callback(uint32 target, uint32 argument0, uint32 argument1)
{
    (void)argument0; (void)argument1;
    switch (target) {
    case 0u: return;
    case 0x8007EB24u: native_stream_complete(); return;
    case 0x8007D348u: sub_8007DE14(); return;
    case 0x80042130u: {
        uint32 mark = draft_scratch_mark();
        uint32 stack = draft_scratch_adapter(4096u);
        GameSceneCallContext context = {0}; context.stack_pointer = stack + 4096u;
        sub_80042130(&context); draft_scratch_release(mark); return;
    }
    default: fprintf(stderr, "Unbound SDK guest callback %08X\n", target); abort();
    }
}
uint32 sub_8007B770(uint32 callback)
{
    uint32 previous = native_data_callback; native_data_callback = callback; return previous;
}
uint32 sub_8007ECF4(uint32 callback) { return sub_8007B770(callback); }
static void native_ring_clear(uint32 first, uint32 count)
{
    for (uint32 i = 0u; i < count; ++i)
        w_u32(r_u32(0x800C15E0u) + 32u * (first + i), 0u);
}
static uint32 native_stream_error(uint32 status)
{
    if (r_u32(0x800C15D0u)) w_u32(0x800BCD04u, r_u32(0x800BCD04u) + 1u);
    w_u32(0x80092940u, status); return status;
}
uint32 sub_8007DE14(void)
{
    uint8 sector[2352] = {0};
    uint32 memory = r_u32(0x800C15D0u);
    if (r_u32(0x800BBEF8u) == 1u) return 1u;
    uint32 index = r_u32(0x800BE508u);
    uint32 header = r_u32(0x800C15E0u) + 32u * index;
    w_u32(0x800B3220u, header);
    if (r_u16(header)) return native_stream_error(4u);
    if (memory) {
        memcpy(sector + 24u, psx_addr(memory + 2048u * r_u32(0x800BCD04u), 2048u), 2048u);
    } else if (!native_stream_active || !cd_read_sector_native(sector)) {
        w_u32(0x80092940u, 5u); return 5u;
    }
    for (uint32 i = 0u; i < 32u; ++i) w_u8(header + i, sector[24u + i]);
    uint32 sector_header = (uint32)sector[12u] | ((uint32)sector[13u] << 8) | ((uint32)sector[14u] << 16) | ((uint32)sector[15u] << 24);
    if (!memory) w_u32(header + 28u, sector_header);
    if (r_u32(0x800C15D8u) == 1u && r_u32(0x800B68B0u)) {
        if (r_u32(0x800B68B0u) != r_u16(header + 8u)) {
            w_u16(header, 0u);
            if (memory) w_u32(0x800BCD04u, r_u32(0x800BCD04u) + 1u);
            return memory ? r_u32(0x800BCD04u) : 0u;
        }
        w_u32(0x800C15D8u, 0u);
    }
    if (r_u16(header) != 352u || ((r_u16(header + 2u) >> 10) & 31u) != r_u32(0x800BA8B4u)) {
        if (memory) w_u32(0x800BCD04u, 0u);
        w_u16(header, 0u); w_u32(0x80092940u, 5u); return 5u;
    }
    if ((sint16)r_u16(0x800B4880u) != r_u16(header + 4u) ||
        (r_u32(0x800B347Cu) && r_u32(0x800B347Cu) != r_u16(header + 8u))) {
        w_u32(0x800B347Cu, 0u); w_u16(0x800B4880u, 0u);
        native_ring_clear(r_u32(0x800BE50Cu), index - r_u32(0x800BE50Cu));
        w_u32(0x800BE508u, r_u32(0x800BE50Cu)); w_u16(header, 0u);
        return native_stream_error(6u);
    }
    if (!r_u16(header + 4u)) {
        uint32 frame = r_u16(header + 8u), limit = r_u32(0x800C15D4u);
        w_u16(0x800B4880u, 0u); w_u32(0x800B347Cu, frame);
        if (limit && frame >= limit) {
            w_u32(0x800B347Cu, 0u); w_u16(0x800B4880u, 0u);
            native_ring_clear(r_u32(0x800BE50Cu), index - r_u32(0x800BE50Cu));
            w_u32(0x800BE508u, r_u32(0x800BE50Cu)); w_u16(header, 0u);
            w_u32(0x800C15D8u, 1u);
            native_sdk_dispatch_callback(r_u32(0x800B5890u), 0u, 0u);
            return native_stream_error(7u);
        }
        if (r_u32(0x800C15E4u) - index - 1u < r_u16(header + 6u)) {
            if (!limit) {
                w_u16(header, 1u); w_u32(0x800C15D8u, 1u);
                native_sdk_dispatch_callback(r_u32(0x800B5890u), 0u, 0u);
                return native_stream_error(8u);
            }
            uint32 base = r_u32(0x800C15E0u);
            if ((sint16)r_u16(base)) { w_u16(header, 0u); return native_stream_error(9u); }
            w_u16(header, 1u); w_u32(0x800BE508u, 0u);
            for (uint32 i = 0u; i < 8u; ++i) w_u32(base + 4u * i, r_u32(header + 4u * i));
            header = base; w_u32(0x800B3220u, header); index = 0u;
        }
        w_u32(0x800BE50Cu, index);
    }
    w_u32(0x80092940u, 10u);
    w_u16(0x800B4880u, r_u16(0x800B4880u) + 1u);
    uint32 payload = r_u32(0x800C15E0u) + 32u * r_u32(0x800C15E4u) + 2016u * index;
    w_u32(0x800C15DCu, payload);
    for (uint32 i = 0u; i < 2016u; ++i) w_u8(payload + i, sector[56u + i]);
    uint32 final = r_u16(header + 6u) - 1u == r_u16(header + 4u);
    if (final) {
        w_u32(0x800BBEF8u, 1u); w_u16(0x800B4880u, 0u); w_u32(0x800B347Cu, 0u);
        w_u32(0x800BA8B4u, r_u32(0x800B68ACu));
    }
    if (memory) w_u32(0x800BCD04u, r_u32(0x800BCD04u) + 1u);
    w_u16(header, 3u); w_u32(0x800BE508u, index + 1u);
    if (final) native_stream_complete();
    return index + 1u;
}
void native_sdk_stream_start(void) { native_stream_active = 1u; }
void native_sdk_stream_stop(void) { native_stream_active = 0u; }




