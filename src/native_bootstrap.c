#include "native_bootstrap.h"
#include "psx_spu.h"
#include "draft_adapters.h"
#include <stdlib.h>

static uint32 boot_upload_image(PSX_RECT *rectangle, uint32 pixels)
{
    size_t bytes = (size_t)(uint16)rectangle->w * (uint16)rectangle->h * 2u;
    return (uint32)LoadImagePSX(rectangle, (uint32 *)psx_addr(pixels, bytes));
}

uint32 sub_8014B9DC(uint32 image)
{
    uint32 flags, block = image + 8u, pixels;
    PSX_RECT rectangle, first_rectangle, palette = {0};
    FUNCTION_MARKER(0x8014B9DCu, "SLUS_005.22");
    flags = r_u32(image + 4u);
    if ((r_u32(image + 4u) & 8u) != 0u)
    {
        uint32 palette_bytes;
        palette.x = (sint16)r_u16(image + 12u);
        palette_bytes = r_u32(image + 8u);
        palette.y = (sint16)r_u16(image + 14u);
        block = image + 8u + palette_bytes;
        palette.w = (sint16)r_u16(image + 16u);
        palette.h = (sint16)r_u16(image + 18u);
    }
    first_rectangle.x = (sint16)r_u16(block + 4u);
    first_rectangle.y = (sint16)r_u16(block + 6u);
    first_rectangle.w = (sint16)r_u16(block + 8u);
    first_rectangle.h = (sint16)r_u16(block + 10u);
    pixels = block + 12u;
    rectangle = first_rectangle;
    DrawSync(0);
    VSync(0);
    boot_upload_image(&rectangle, pixels);
    rectangle = first_rectangle;
    rectangle.y = (sint16)((uint32)(uint16)rectangle.y + 256u);
    DrawSync(0);
    VSync(0);
    boot_upload_image(&rectangle, pixels);
    DrawSync(0);
    VSync(0);
    if ((flags & 8u) != 0u)
    {
        rectangle = palette;
        DrawSync(0);
        return boot_upload_image(&rectangle, image + 20u);
    }
    return 0u;
}

static void boot_stop_pad(void)
{
    /* TODO Bind the missing StopPAD adapter for the legacy bootstrap */
#ifndef NDEBUG
    fprintf(stderr, "Unbound bootstrap StopPAD adapter\n");
#endif
    abort();
}

static uint32 boot_load_executable(uint32 filename, uint32 header)
{
    /* TODO Bind BIOS Load without extending the shared runtime in this pass */
#ifndef NDEBUG
    fprintf(stderr, "Unbound bootstrap BIOS Load %08X -> %08X\n", filename, header);
#endif
    abort();
}

uint32 sub_8014B8D8(void)
{
    uint32 mark, header, result;
    FUNCTION_MARKER(0x8014B8D8u, "SLUS_005.22");
    /* The reviewed constructor table is empty and native CRT startup is complete */
    w_u32(0x80154C4Cu, 0x200000u);
    w_u32(0x80154C48u, 1024u);
    w_u32(0x80156BD4u, 0x80080000u);
    SetDispMask(0);
    sub_8014BB40();
    SetDispMask(1);
    SpuInit();
    VSync(0);
    w_u32(0x8015FFF4u, 0u);
    w_u32(0x8015FFF8u, 0u);
    w_u32(0x8015FFFCu, 0u);
    w_u32(0x8015FFF0u, 0u);
    w_u32(0x8015FFE0u, 0x50000u);
    w_u32(0x8015FFE4u, 0x50000u);
    w_u32(0x8015FFE8u, 0x50000u);
    w_u32(0x8015FFECu, 0x50000u);
    ResetGraph(3);
    CdInit();
    boot_stop_pad();
    ResetCallback();
    _96_init();
    mark = draft_scratch_mark();
    header = draft_scratch_adapter(64u);
    while (boot_load_executable(0x80156B8Cu, header) == 0u)
    {
    }
    ResetGraph(3);
    result = (uint32)Exec(header, 0u, 0u);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_8014BB40(void)
{
    uint32 buffer;
    FUNCTION_MARKER(0x8014BB40u, "SLUS_005.22");
    ResetCallback();
    ResetGraph(0);
    PadInit(0);
    w_u32(0x80156B84u, 0u);
    w_u32(0x80156B88u, 0u);
    SetGraphDebug(0);
    SetDefDispEnv((DISPENV *)psx_addr(0x80156C90u, sizeof(DISPENV)), 0, 256, 640, 240);
    SetDefDrawEnv((DRAWENV *)psx_addr(0x80156BD8u, sizeof(DRAWENV)), 0, 0, 640, 240);
    SetDefDispEnv((DISPENV *)psx_addr(0x80156CA4u, sizeof(DISPENV)), 0, 0, 640, 240);
    SetDefDrawEnv((DRAWENV *)psx_addr(0x80156C34u, sizeof(DRAWENV)), 0, 256, 640, 240);
    w_u8(0x80156CA0u, 0u);
    w_u8(0x80156CA1u, 0u);
    w_u8(0x80156BEEu, 1u);
    w_u8(0x80156BEFu, 0u);
    w_u8(0x80156BF0u, 1u);
    w_u8(0x80156BF1u, 0u);
    w_u8(0x80156BF2u, 0u);
    w_u8(0x80156BF3u, 0u);
    w_u8(0x80156CB4u, 0u);
    w_u8(0x80156CB5u, 0u);
    w_u8(0x80156C4Au, 1u);
    w_u8(0x80156C4Bu, 0u);
    w_u8(0x80156C4Cu, 1u);
    sub_8014B9DC(0x80100000u);
    w_u16(0x80156BD0u, 1u - r_u16(0x80156BD0u));
    DrawSync(0);
    VSync(0);
    buffer = (uint32)r_s16(0x80156BD0u);
    PutDrawEnv((DRAWENV *)psx_addr(0x80156BD8u + buffer * 92u, sizeof(DRAWENV)));
    buffer = (uint32)r_s16(0x80156BD0u);
    PutDispEnv((DISPENV *)psx_addr(0x80156C90u + buffer * 20u, sizeof(DISPENV)));
    DrawSync(0);
    return (uint32)VSync(0);
}
