#include "xport.h"
#include "psx.h"
#include "game_scene.h"
#include "game_entry.h"
uint32 sub_8007FAAC(uint32 mode);

const uint32 xport_gpu_graph_type_address = 0x80093C84u;

sint32 sub_8003915C(void)
{
    FUNCTION_MARKER(0x8003915Cu, "1.EXE");
    w_u16(0x800A7BECu, 1u);
    w_u32(0x800A8B30u, 0u);
    w_u16(0x800A6D6Cu, 0u);
    w_u16(0x800A6D68u, 0u);
    w_u16(0x800A901Cu, 0u);
    w_u32(0x800A8E70u, 1u);
    w_u32(0x800A6E30u, 0u);
    w_u32(0x800A6E5Cu, 0u);
    w_u32(0x800A6E2Cu, 0u);
    w_u32(0x800A7FB0u, 0u);
    return 1;
}

void sub_800836DC(uint32 center_x, uint32 center_y)
{
    FUNCTION_MARKER(0x800836DCu, "1.EXE");
    SetGeomOffset((sint16)(uint16)center_x, (sint16)(uint16)center_y);
}

void sub_8008358C(uint32 projection)
{
    FUNCTION_MARKER(0x8008358Cu, "1.EXE");
    gte_write_h((uint16)projection);
}

sint32 sub_800212EC(sint32 center_x, sint32 center_y, sint32 projection)
{
    FUNCTION_MARKER(0x800212ECu, "1.EXE");
    w_u16(0x800A8218u, 0x1000u);
    w_u16(0x800A8224u, 0x140u);
    w_u16(0x800A821Cu, (uint16)center_x);
    w_u16(0x800A821Eu, (uint16)center_y);
    w_u16(0x800A821Au, (uint16)projection);
    w_u16(0x800A8220u, 0u);
    w_u16(0x800A8222u, 0u);
    w_u16(0x800A8226u, 0xF0u);
    return 0xF0;
}

uint32 sub_80082B68(void)
{
    FUNCTION_MARKER(0x80082B68u, "1.EXE");
    return r_u32(xport_gpu_graph_type_address);
}

uint32 sub_8008A3E4(uint32 value)
{
    uint32 previous;

    FUNCTION_MARKER(0x8008A3E4u, "1.EXE");
    previous = r_u32(0x800A7B84u);
    w_u32(0x800A7B84u, value);
    return previous;
}

uint32 sub_80064200(uint32 destination, uint32 entry_sp)
{
    uint32 local = entry_sp - 0x10u;
    uint32 component;

    FUNCTION_MARKER(0x80064200u, "1.EXE");
    // Entry SP is explicit guest context, not an original second argument
    w_u8(local, 0x7Fu);
    w_u8(local + 1u, 0x7Fu);
    w_u8(local + 2u, 0x7Fu);
    w_u32(destination, 0xC350u);
    w_u32(destination + 4u, 0x31CEu);
    component = r_u8(local);
    w_u8(destination + 0x10u, component);
    component = r_u8(local + 1u);
    w_u8(destination + 0x11u, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0x12u, component);
    w_u8(local, 0x80u);
    w_u8(local + 1u, 0x80u);
    w_u8(local + 2u, 0x80u);
    w_u8(destination + 0xCu, 0x80u);
    component = r_u8(local + 1u);
    w_u8(destination + 0xDu, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0xEu, component);
    w_u8(local, 0u);
    w_u8(local + 1u, 0u);
    w_u8(local + 2u, 0u);
    w_u8(destination + 0x14u, 0u);
    component = r_u8(local + 1u);
    w_u8(destination + 0x15u, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0x16u, component);
    w_u8(local, 0x40u);
    w_u8(local + 1u, 0x40u);
    w_u8(local + 2u, 0x40u);
    w_u16(destination + 0x18u, 0x2000u);
    component = r_u8(local + 1u);
    w_u16(destination + 0x1Au, component << 7);
    component = r_u8(local + 2u);
    w_u16(destination + 0x1Cu, component << 7);
    w_u16(destination + 0x34u, 0x800u);
    w_u16(destination + 0x30u, 0u);
    w_u16(destination + 0x32u, 0u);
    w_u16(destination + 0x38u, 0u);
    w_u16(destination + 0x3Au, 0u);
    w_u16(destination + 0x3Cu, 0u);
    w_u16(destination + 0x40u, 0u);
    w_u16(destination + 0x42u, 0u);
    w_u16(destination + 0x44u, 0u);
    w_u16(local + 8u, 0xFC00u);
    w_u16(local + 0xAu, 0u);
    w_u16(local + 0xCu, 0u);
    w_u16(destination + 0x48u, 0xFC00u);
    component = r_u16(local + 0xAu);
    w_u16(destination + 0x4Au, component);
    component = r_u16(local + 0xCu);
    w_u8(destination + 0x9Cu, 0u);
    w_u16(destination + 0x4Cu, component);
    return component;
}

uint32 sub_80063E28(uint32 destination, uint32 entry_sp)
{
    uint32 local = entry_sp - 0x10u;
    uint32 component;

    FUNCTION_MARKER(0x80063E28u, "1.EXE");
    // Entry SP is explicit guest context, not an original second argument
    w_u8(local, 0x7Fu);
    w_u8(local + 1u, 0x7Fu);
    w_u8(local + 2u, 0x7Fu);
    w_u32(destination, 0xC350u);
    w_u32(destination + 4u, 0x31CEu);
    component = r_u8(local);
    w_u8(destination + 0x10u, component);
    component = r_u8(local + 1u);
    w_u8(destination + 0x11u, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0x12u, component);
    w_u8(local, 0x80u);
    w_u8(local + 1u, 0x80u);
    w_u8(local + 2u, 0x80u);
    w_u8(destination + 0xCu, 0x80u);
    component = r_u8(local + 1u);
    w_u8(destination + 0xDu, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0xEu, component);
    w_u8(local, 0u);
    w_u8(local + 1u, 0u);
    w_u8(local + 2u, 0u);
    w_u8(destination + 0x14u, 0u);
    component = r_u8(local + 1u);
    w_u8(destination + 0x15u, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0x16u, component);
    w_u8(local, 0x28u);
    w_u8(local + 1u, 0x28u);
    w_u8(local + 2u, 0x28u);
    w_u16(destination + 0x18u, 0x1400u);
    component = r_u8(local + 1u);
    w_u16(destination + 0x1Au, component << 7);
    component = r_u8(local + 2u);
    w_u16(destination + 0x1Cu, component << 7);
    w_u8(local, 4u);
    w_u8(local + 2u, 8u);
    w_u8(local + 1u, 0x10u);
    w_u16(destination + 0x20u, 0x200u);
    component = r_u8(local + 1u);
    w_u16(destination + 0x22u, component << 7);
    component = r_u8(local + 2u);
    w_u16(destination + 0x24u, component << 7);
    w_u8(local + 1u, 0x30u);
    w_u8(local, 0x10u);
    w_u8(local + 2u, 0x20u);
    w_u16(destination + 0x28u, 0x800u);
    component = r_u8(local + 1u);
    w_u16(destination + 0x2Au, component << 7);
    component = r_u8(local + 2u);
    w_u16(destination + 0x34u, 0x800u);
    w_u16(destination + 0x3Cu, 0x800u);
    w_u16(destination + 0x44u, 0x800u);
    w_u16(destination + 0x30u, 0u);
    w_u16(destination + 0x32u, 0u);
    w_u16(destination + 0x38u, 0u);
    w_u16(destination + 0x3Au, 0u);
    w_u16(destination + 0x40u, 0u);
    w_u16(destination + 0x42u, 0u);
    w_u16(destination + 0x2Cu, component << 7);
    w_u16(local + 8u, 0x100u);
    w_u16(local + 0xAu, 0xFF00u);
    w_u16(local + 0xCu, 0u);
    w_u16(destination + 0x48u, 0x100u);
    component = r_u16(local + 0xAu);
    w_u16(destination + 0x4Au, component);
    component = r_u16(local + 0xCu);
    w_u16(destination + 0x4Cu, component);
    w_u16(local + 8u, 0u);
    w_u16(local + 0xAu, 0x400u);
    w_u16(destination + 0x50u, 0u);
    component = r_u16(local + 0xAu);
    w_u16(destination + 0x52u, component);
    component = r_u16(local + 0xCu);
    w_u16(destination + 0x54u, component);
    w_u16(local + 8u, 0xFC00u);
    w_u16(local + 0xAu, 0u);
    w_u16(destination + 0x58u, 0xFC00u);
    component = r_u16(local + 0xAu);
    w_u16(destination + 0x5Au, component);
    component = r_u16(local + 0xCu);
    w_u8(destination + 0x9Cu, 0u);
    w_u16(destination + 0x5Cu, component);
    return component;
}

uint32 sub_80064020(uint32 destination, uint32 entry_sp)
{
    uint32 local = entry_sp - 0x10u;
    uint32 component;
    uint32 retained;

    FUNCTION_MARKER(0x80064020u, "1.EXE");
    // Entry SP is explicit guest context, not an original second argument
    w_u8(local, 0x7Fu);
    w_u8(local + 1u, 0x7Fu);
    w_u8(local + 2u, 0x7Fu);
    w_u32(destination, 0xC350u);
    w_u32(destination + 4u, 0x31CEu);
    component = r_u8(local);
    w_u8(destination + 0x10u, component);
    component = r_u8(local + 1u);
    w_u8(destination + 0x11u, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0x12u, component);
    w_u8(local, 0x80u);
    w_u8(local + 1u, 0x80u);
    w_u8(local + 2u, 0x80u);
    w_u8(destination + 0xCu, 0x80u);
    component = r_u8(local + 1u);
    w_u8(destination + 0xDu, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0xEu, component);
    w_u8(local, 0u);
    w_u8(local + 1u, 0u);
    w_u8(local + 2u, 0u);
    w_u8(destination + 0x14u, 0u);
    component = r_u8(local + 1u);
    w_u8(destination + 0x15u, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0x16u, component);
    w_u8(local, 0x30u);
    w_u8(local + 1u, 5u);
    w_u8(local + 2u, 5u);
    w_u16(destination + 0x18u, 0x1800u);
    component = r_u8(local + 1u);
    w_u16(destination + 0x1Au, component << 7);
    component = r_u8(local + 2u);
    w_u16(destination + 0x1Cu, component << 7);
    w_u8(local, 5u);
    w_u8(local + 1u, 0x30u);
    w_u16(destination + 0x20u, 0x280u);
    component = r_u8(local + 1u);
    w_u16(destination + 0x22u, component << 7);
    component = r_u8(local + 2u);
    w_u16(destination + 0x24u, component << 7);
    component = r_u8(local);
    w_u8(local + 1u, 5u);
    w_u8(local + 2u, 0x30u);
    w_u16(destination + 0x28u, component << 7);
    component = r_u8(local + 1u);
    w_u16(destination + 0x2Au, component << 7);
    retained = r_u8(local + 2u);
    w_u16(destination + 0x34u, 0x800u);
    w_u16(destination + 0x3Cu, 0x800u);
    w_u16(destination + 0x44u, 0x800u);
    w_u16(destination + 0x30u, 0u);
    w_u16(destination + 0x32u, 0u);
    w_u16(destination + 0x38u, 0u);
    w_u16(destination + 0x3Au, 0u);
    w_u16(destination + 0x40u, 0u);
    w_u16(destination + 0x42u, 0u);
    w_u16(destination + 0x2Cu, retained << 7);
    w_u16(local + 8u, 0x100u);
    w_u16(local + 0xAu, 0u);
    w_u16(local + 0xCu, 0u);
    w_u16(destination + 0x48u, 0x100u);
    component = r_u16(local + 0xAu);
    w_u16(destination + 0x4Au, component);
    component = r_u16(local + 0xCu);
    w_u16(destination + 0x4Cu, component);
    retained = r_u16(local + 8u);
    w_u16(local + 0xAu, 0x400u);
    w_u16(destination + 0x50u, retained);
    component = r_u16(local + 0xAu);
    w_u16(destination + 0x52u, component);
    component = r_u16(local + 0xCu);
    w_u16(destination + 0x54u, component);
    retained = r_u16(local + 8u);
    w_u16(local + 0xAu, 0xFC00u);
    w_u16(destination + 0x58u, retained);
    component = r_u16(local + 0xAu);
    w_u16(destination + 0x5Au, component);
    component = r_u16(local + 0xCu);
    w_u8(destination + 0x9Cu, 0u);
    w_u16(destination + 0x5Cu, component);
    return component;
}

uint32 sub_80063AFC(uint32 destination, uint32 entry_sp)
{
    uint32 local = entry_sp - 0x10u;
    uint32 component;

    FUNCTION_MARKER(0x80063AFCu, "1.EXE");
    // Entry SP is explicit guest context, not an original second argument
    w_u8(local, 0x7Fu);
    w_u8(local + 1u, 0x7Fu);
    w_u8(local + 2u, 0x7Fu);
    w_u32(destination, 0xC350u);
    w_u32(destination + 4u, 0x31CEu);
    component = r_u8(local);
    w_u8(destination + 0x10u, component);
    component = r_u8(local + 1u);
    w_u8(destination + 0x11u, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0x12u, component);
    w_u8(local, 0x80u);
    w_u8(local + 1u, 0x80u);
    w_u8(local + 2u, 0x80u);
    w_u8(destination + 0xCu, 0x80u);
    component = r_u8(local + 1u);
    w_u8(destination + 0xDu, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0xEu, component);
    w_u8(local, 0x46u);
    w_u8(local + 1u, 0x3Cu);
    w_u8(local + 2u, 0x3Cu);
    w_u8(destination + 0x14u, 0x46u);
    component = r_u8(local + 1u);
    w_u8(destination + 0x15u, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0x16u, component);
    w_u8(local, 0x64u);
    w_u8(local + 1u, 0x3Fu);
    w_u8(local + 2u, 0x27u);
    w_u16(destination + 0x18u, 0x3200u);
    component = r_u8(local + 1u);
    w_u16(destination + 0x1Au, component << 7);
    component = r_u8(local + 2u);
    w_u16(destination + 0x1Cu, component << 7);
    w_u16(destination + 0x34u, 0x800u);
    w_u16(destination + 0x30u, 0u);
    w_u16(destination + 0x32u, 0u);
    w_u16(destination + 0x38u, 0u);
    w_u16(destination + 0x3Au, 0u);
    w_u16(destination + 0x3Cu, 0u);
    w_u16(destination + 0x40u, 0u);
    w_u16(destination + 0x42u, 0u);
    w_u16(destination + 0x44u, 0u);
    w_u16(local + 8u, 0x12Cu);
    w_u16(local + 0xAu, 0x400u);
    w_u16(local + 0xCu, 0u);
    w_u16(destination + 0x48u, 0x12Cu);
    component = r_u16(local + 0xAu);
    w_u16(destination + 0x4Au, component);
    component = r_u16(local + 0xCu);
    w_u8(destination + 0x9Cu, 0u);
    w_u16(destination + 0x4Cu, component);
    return component;
}

uint32 sub_80063C3C(uint32 destination, uint32 entry_sp)
{
    uint32 local = entry_sp - 0x10u;
    uint32 component;
    uint32 retained;

    FUNCTION_MARKER(0x80063C3Cu, "1.EXE");
    // Entry SP is explicit guest context, not an original second argument
    w_u8(local, 0x7Fu);
    w_u8(local + 1u, 0x7Fu);
    w_u8(local + 2u, 0x7Fu);
    w_u32(destination, 0xC350u);
    w_u32(destination + 4u, 0x31CEu);
    component = r_u8(local);
    w_u8(destination + 0x10u, component);
    component = r_u8(local + 1u);
    w_u8(destination + 0x11u, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0x12u, component);
    w_u8(local, 0x80u);
    w_u8(local + 1u, 0x80u);
    w_u8(local + 2u, 0x80u);
    w_u8(destination + 0xCu, 0x80u);
    component = r_u8(local + 1u);
    w_u8(destination + 0xDu, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0xEu, component);
    w_u8(local + 1u, 0x52u);
    w_u8(local, 0x42u);
    w_u8(local + 2u, 0x5Au);
    w_u8(destination + 0x14u, 0x42u);
    component = r_u8(local + 1u);
    w_u8(destination + 0x15u, component);
    component = r_u8(local + 2u);
    w_u8(destination + 0x16u, component);
    w_u8(local, 0x40u);
    w_u8(local + 1u, 0x40u);
    w_u8(local + 2u, 0x40u);
    w_u16(destination + 0x18u, 0x2000u);
    component = r_u8(local + 1u);
    w_u16(destination + 0x1Au, component << 7);
    component = r_u8(local + 2u);
    w_u16(destination + 0x1Cu, component << 7);
    w_u8(local, 0x10u);
    w_u8(local + 1u, 0x10u);
    w_u8(local + 2u, 0x10u);
    w_u16(destination + 0x20u, 0x800u);
    component = r_u8(local + 1u);
    w_u16(destination + 0x22u, component << 7);
    component = r_u8(local + 2u);
    w_u16(destination + 0x24u, component << 7);
    component = r_u8(local);
    w_u16(destination + 0x28u, component << 7);
    component = r_u8(local + 1u);
    w_u16(destination + 0x2Au, component << 7);
    component = r_u8(local + 2u);
    w_u16(destination + 0x34u, 0x800u);
    w_u16(destination + 0x3Cu, 0x800u);
    w_u16(destination + 0x44u, 0x800u);
    w_u16(destination + 0x30u, 0u);
    w_u16(destination + 0x32u, 0u);
    w_u16(destination + 0x38u, 0u);
    w_u16(destination + 0x3Au, 0u);
    w_u16(destination + 0x40u, 0u);
    w_u16(destination + 0x42u, 0u);
    w_u16(destination + 0x2Cu, component << 7);
    w_u16(local + 8u, 0x12Cu);
    w_u16(local + 0xAu, 0x700u);
    w_u16(local + 0xCu, 0u);
    w_u16(destination + 0x48u, 0x12Cu);
    component = r_u16(local + 0xAu);
    w_u16(destination + 0x4Au, component);
    component = r_u16(local + 0xCu);
    w_u16(destination + 0x4Cu, component);
    w_u16(local + 8u, 0u);
    w_u16(local + 0xAu, 0x300u);
    w_u16(destination + 0x50u, 0u);
    component = r_u16(local + 0xAu);
    w_u16(destination + 0x52u, component);
    component = r_u16(local + 0xCu);
    w_u16(destination + 0x54u, component);
    retained = r_u16(local + 8u);
    w_u16(local + 0xAu, 0xB00u);
    w_u16(destination + 0x58u, retained);
    component = r_u16(local + 0xAu);
    w_u16(destination + 0x5Au, component);
    component = r_u16(local + 0xCu);
    w_u8(destination + 0x9Cu, 0u);
    w_u16(destination + 0x5Cu, component);
    return component;
}

// XPORT REVISION: 2026-09-29T20:00:00Z
extern sint32 cd_mount_cue(const char *path);
void native_spu_init_binding(void);
void native_bios_init_callbacks(void);
void sub_800394B8(GameMainCallContext *context);

void xport_main(void)
{
    PSX_EXE image = { "../orig/1.EXE", 0x80010000u,
        0x800A6720u, 0x800C15E8u, 0x8009242Cu,
        0x800C15E8u, 0x001FFBF8u - 0x000C15E8u };
    GameMainCallContext context = {0};
    if (!xport_psx_exe_load(&image))
    {
        xport_message_error("Auto Destruct", "Cannot load ../orig/1.EXE");
        xport_set_exit_code(1);
        return;
    }
    if (!cd_mount_cue("../iso/Auto Destruct (USA).cue"))
    {
        xport_message_error("Auto Destruct", "Cannot mount Auto Destruct disc image");
        xport_set_exit_code(1);
        return;
    }
    context.stack_pointer = (r_u32(0x80092450u) - 8u) | 0x80000000u;
    context.caller_fp = context.stack_pointer;
    psx_root_counter_bind(0x80092454u, 0x8009245Cu);
    native_bios_init_callbacks();
    native_spu_init_binding();
    psx_bios_init_user_heap(0x800C15ECu, image.heap_size);
    sub_800394B8(&context);
}

uint32 sub_80079C60(uint32 replacement, uint32 *guest_sp)
{
    uint32 previous;

    FUNCTION_MARKER(0x80079C60u, "1.EXE");
    // Guest SP is explicit machine context, not an original A1 argument
    previous = *guest_sp;
    *guest_sp = replacement;
    return previous;
}

uint32 sub_80078830(void)
{
    FUNCTION_MARKER(0x80078830u, "1.EXE");
    w_u32(0x800A84E0u, 0x400u);
    w_u32(0x800A7AC0u, 0u);
    w_u32(0x800A7AC4u, 0u);
    w_u32(0x800A7AD0u, 0u);
    w_u32(0x800A7AD4u, 2u);
    return 2u;
}

uint32 sub_80064334(uint32 force_default, GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 mode = 0u;
    uint32 target;
    uint32 source;
    uint32 destination;
    uint32 limit;
    uint32 first, second, third, fourth;
    GameSceneCallContext child = *context;

    FUNCTION_MARKER(0x80064334u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    child.caller_s0 = 0x800A8E74u;
    w_u32(frame + 0x14u, context->return_address);
    child.stack_pointer = frame;
    if (force_default == 0u)
        mode = r_u32(0x800A9A38u);
    if (force_default == 0u && mode != 0u && mode < 5u)
    {
        target = r_u32(0x80091090u + ((mode - 1u) << 2u));
        child.return_address = 0x80064384u;
        game_call_scene_initializer_context(target, child.caller_s0, &child);
    }
    else
    {
        child.return_address = 0x80064394u;
        sub_80064200(child.caller_s0, frame);
    }
    destination = child.caller_s0 + 0xA4u;
    source = child.caller_s0;
    limit = source + 0xA0u;
    do
    {
        first = r_u32(source);
        second = r_u32(source + 4u);
        third = r_u32(source + 8u);
        fourth = r_u32(source + 0xCu);
        w_u32(destination, first);
        w_u32(destination + 4u, second);
        w_u32(destination + 8u, third);
        w_u32(destination + 0xCu, fourth);
        source += 0x10u;
        destination += 0x10u;
    } while (source != limit);
    first = r_u32(source);
    w_u32(destination, first);
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return first;
}

void game_call_scene_initializer(uint32 target, uint32 destination, uint32 entry_sp)
{
    switch (target)
    {
        case 0x80063AFCu:
            sub_80063AFC(destination, entry_sp);
            return;
        case 0x80063E28u:
            sub_80063E28(destination, entry_sp);
            return;
        case 0x80063C3Cu:
            sub_80063C3C(destination, entry_sp);
            return;
        case 0x80064020u:
            sub_80064020(destination, entry_sp);
            return;
        case 0x80064200u:
            sub_80064200(destination, entry_sp);
            return;
        default:
            game_call_scene_initializer_other(target, destination, entry_sp);
            return;
    }
}

sint32 sub_8003C058(uint32 width, uint32 height, uint32 projection, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 center_x;
    uint32 center_y;
    sint32 result;

    FUNCTION_MARKER(0x8003C058u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->caller_s1);
    w_u32(frame + 0x18u, context->caller_s2);
    w_u32(frame + 0x1Cu, context->return_address);
    InitGeom();
    // Unsigned operations preserve SRA for every 32-bit argument
    center_x = (width >> 1) | (width & 0x80000000u);
    center_y = (height >> 1) | (height & 0x80000000u);
    sub_800836DC(center_x, center_y);
    sub_8008358C(projection);
    result = sub_800212EC((sint32)center_x, (sint32)center_y, (sint32)projection);
    context->return_address = r_u32(frame + 0x1Cu);
    context->caller_s2 = r_u32(frame + 0x18u);
    context->caller_s1 = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8003C0C4(GameGeometryCallContext *context)
{
    uint32 loaded;
    uint32 frame;
    uint32 result;
    GameSceneCallContext child;
    GameGeometryCallContext display;

    FUNCTION_MARKER(0x8003C0C4u, "1.EXE");
    loaded = r_u32(0x800A87E4u);
    frame = context->stack_pointer - 0x18u;
    w_u32(frame + 0x10u, context->return_address);
    w_u32(0x800A98F4u, 0u);
    loaded &= 2u;
    w_u32(0x800A87E4u, loaded);
    sub_8007FAAC(loaded ? 3u : 0u);
    display = *context;
    display.stack_pointer = frame;
    display.return_address = 0x8003C0FCu;
    sub_8003C114(&display);
    context->caller_s1 = display.caller_s1;
    context->caller_s2 = display.caller_s2;
    child.stack_pointer = frame;
    child.return_address = 0x8003C104u;
    child.caller_s0 = display.caller_s0;
    result = sub_80064334(1u, &child);
    context->caller_s0 = child.caller_s0;
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8003806C(GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;

    FUNCTION_MARKER(0x8003806Cu, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    InitTAP(0x800A9984u, 0x800A99A8u, 8, 7);
    result = StartTAP();
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8003C114(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 page;
    uint32 first;
    uint32 second;
    uint32 debug_frame;
    GameGeometryCallContext geometry;

    FUNCTION_MARKER(0x8003C114u, "1.EXE");
    w_u32(frame + 0x1Cu, context->return_address);
    w_u32(frame + 0x18u, context->caller_s0);
    w_u32(0x800A98F4u, 0u);
    geometry = *context;
    geometry.stack_pointer = frame;
    geometry.return_address = 0x8003C138u;
    sub_8003C058(320u, 240u, 125u, &geometry);
    context->caller_s1 = geometry.caller_s1;
    context->caller_s2 = geometry.caller_s2;
    debug_frame = frame - 0x18u;
    w_u32(debug_frame + 0x14u, 0x8003C140u);
    w_u32(debug_frame + 0x10u, geometry.caller_s0);
    (void)r_u8(0x80093B66u);
    w_u8(0x80093B66u, 0u);
    (void)r_u32(debug_frame + 0x14u);
    context->caller_s0 = r_u32(debug_frame + 0x10u);
    w_u32(frame + 0x10u, 240u);
    SetDefDispEnv((DISPENV *)psx_addr(0x800A85C8u, sizeof(DISPENV)), 0, 256, 320, (sint32)r_u32(frame + 0x10u));
    w_u32(frame + 0x10u, 240u);
    SetDefDispEnv((DISPENV *)psx_addr(0x800A8640u, sizeof(DISPENV)), 0, 0, 320, (sint32)r_u32(frame + 0x10u));
    w_u32(frame + 0x10u, 240u);
    SetDefDrawEnv((DRAWENV *)psx_addr(0x800A856Cu, sizeof(DRAWENV)), 0, 0, 320, (sint32)r_u32(frame + 0x10u));
    w_u32(frame + 0x10u, 240u);
    SetDefDrawEnv((DRAWENV *)psx_addr(0x800A85E4u, sizeof(DRAWENV)), 0, 256, 320, (sint32)r_u32(frame + 0x10u));
    w_u8(0x800A85D8u, 0u);
    w_u8(0x800A8650u, 0u);
    w_u8(0x800A85D9u, 0u);
    w_u8(0x800A8651u, 0u);
    page = GetTPage(0, 0, 320, 0);
    w_u16(0x800A8580u, page);
    w_u16(0x800A85F8u, page);
    w_u8(0x800A8582u, 1u);
    w_u8(0x800A85FAu, 1u);
    first = r_u32(0x800A822Cu);
    second = r_u32(0x800A8230u);
    w_u8(0x800A8584u, 0u);
    w_u8(0x800A85FCu, 0u);
    w_u8(0x800A8583u, 0u);
    w_u8(0x800A85FBu, 0u);
    w_u32(0x800A85DCu, 0x800B68B4u);
    w_u32(0x800A8654u, 0x800B88B4u);
    w_u32(0x800A85E0u, first);
    w_u32(0x800A8658u, second);
    ClearOTagR((uint32 *)psx_addr(0x800B68B4u, 0x2000u), 0x800);
    ClearOTagR((uint32 *)psx_addr(0x800B88B4u, 0x2000u), 0x800);
    first = r_u32(0x800A85DCu);
    second = r_u32(0x800A85E0u);
    w_u32(0x800A562Cu, 0u);
    w_u32(0x800A9A74u, first);
    w_u32(0x800A865Cu, second);
    context->return_address = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
    return first;
}

void game_main_initialize_globals(uint32 initial_state)
{
    uint32 startup_0;
    uint32 startup_1;
    uint32 startup_2;
    uint32 startup_3;
    uint32 startup_4;
    uint32 startup_5;
    uint32 startup_6;
    uint32 startup_7;

    w_u32(0x800A6DE4u, 0x8015FFF0u);
    w_u32(0x800A6DE4u, 0x8015FFE0u);
    w_u32(0x800A9D58u, 0u);
    w_u32(0x800A9D60u, 0u);
    startup_0 = r_u32(0x8015FFF0u);
    startup_1 = r_u32(0x8015FFF4u);
    startup_2 = r_u32(0x8015FFF8u);
    startup_3 = r_u32(0x8015FFFCu);
    startup_4 = r_u32(0x8015FFE0u);
    startup_5 = r_u32(0x8015FFE4u);
    startup_6 = r_u32(0x8015FFE8u);
    startup_7 = r_u32(0x8015FFECu);
    w_u32(0x800A854Cu, initial_state);
    w_u32(0x800A6E50u, 0u);
    w_u32(0x800A87F8u, startup_0);
    w_u32(0x800A87E4u, startup_1);
    w_u32(0x800A8698u, startup_2);
    w_u32(0x800A8FD4u, startup_3);
    w_u32(0x800A8504u, startup_4);
    w_u32(0x800A8508u, startup_5);
    w_u32(0x800A850Cu, startup_6);
    w_u32(0x800A8510u, startup_7);
    w_u32(0x800A8698u, 0u);
    w_u32(0x800A8FD4u, 0u);
}

#include <stdlib.h>
#include "game_scene.h"



uint32 sub_80063AFC(uint32 destination, uint32 entry_sp);
uint32 sub_80063C3C(uint32 destination, uint32 entry_sp);
uint32 sub_80063E28(uint32 destination, uint32 entry_sp);
uint32 sub_80064020(uint32 destination, uint32 entry_sp);
void game_call_scene_initializer_context(uint32 target, uint32 destination, GameSceneCallContext *context);
uint32 sub_80064334(uint32 force_default, GameSceneCallContext *context);
sint32 sub_8003C058(uint32 width, uint32 height, uint32 projection, GameGeometryCallContext *context);
uint32 sub_8003C0C4(GameGeometryCallContext *context);
uint32 sub_8003C114(GameGeometryCallContext *context);
void sub_800796DC(GameMainCallContext *context);
void sub_80079C20(GameMainCallContext *context);
void sub_800836DC(uint32 center_x, uint32 center_y);
void sub_8008358C(uint32 projection);
sint32 sub_800212EC(sint32 center_x, sint32 center_y, sint32 projection);
uint32 sub_8008A3E4(uint32 value);
uint32 sub_8003806C(GameSceneCallContext *context);
sint32 sub_8003915C(void);
uint32 sub_80082B68(void);
uint32 sub_80064200(uint32 destination, uint32 entry_sp);
uint32 sub_80079C60(uint32 replacement, uint32 *guest_sp);

void sub_800394B8(GameMainCallContext *context);

// Draft interfaces for later recorded game translations
uint32 sub_8001F850(void);
uint32 sub_800205C8(uint32 argument_0, uint32 argument_1, uint32 argument_2);
uint32 sub_8002133C(void);
uint32 sub_80022A68(uint32 argument_0);
uint32 sub_80030E18(uint32 argument_0);
uint32 sub_80031290(void);
uint32 sub_800313EC(uint32 argument_0);
void sub_80031754(void);
uint32 sub_800330E0(void);
uint32 sub_80033100(void);
uint32 sub_800333C4(void);
uint32 sub_80033400(void);
uint32 sub_80033478(void);
uint32 sub_800334A8(void);
uint32 sub_800339D0(uint32 argument_0);
uint32 sub_80034CA8(uint32 argument_0);
uint32 sub_800352C4(uint32 argument_0);
uint32 sub_80035664(uint32 argument_0);
uint32 sub_800356D8(void);
uint32 sub_8003570C(void);
uint32 sub_80035988(uint32 argument_0);
void sub_800360BC(GameGeometryCallContext *context);
uint32 sub_80036D6C(void);
uint32 sub_80036F0C(void);
uint32 sub_8003708C(void);
uint32 sub_80037150(GameGeometryCallContext *context);
uint32 sub_800374BC(uint32 argument_0);
uint32 sub_800375A4(void);
uint32 sub_800376C0(void);
uint32 sub_80037BB8(void);
uint32 sub_800389E8(uint32 argument_0);
uint32 sub_800390E4(void);
uint32 sub_80039198(void);
uint32 sub_800392B4(GameGeometryCallContext *context);
uint32 sub_8003AB60(uint32 argument_0);
uint32 sub_8003AD54(GameGeometryCallContext *context);
uint32 sub_8003B1EC(void);
uint32 sub_8003B574(uint32 selected, uint32 mode, GameGeometryCallContext *context);
uint32 sub_8003B864(GameGeometryCallContext *context);
uint32 sub_8003B8E8(uint32 argument_0, uint32 argument_1);
uint32 sub_8003BEFC(GameGeometryCallContext *context);
uint32 sub_8003C2B8(uint32 mode, GameGeometryCallContext *context);
void sub_8003C374(GameMainCallContext *context);
uint32 sub_8003C394(GameGeometryCallContext *context);
uint32 sub_8003C87C(GameGeometryCallContext *context);
uint32 sub_8003C958(GameGeometryCallContext *context);
uint32 sub_8003CA20(void);
uint32 sub_8003CA68(uint32 argument_0);
uint32 sub_8003CAB4(uint32 argument_0);
uint32 sub_8003D0F4(GameGeometryCallContext *context);
uint32 sub_8003D270(void);
void sub_8003D27C(uint32 value);
void sub_8003D324(uint32 value);
void sub_8003D694(uint32 value);
uint32 sub_8003D6A0(uint32 argument_0);
uint32 sub_8003D6B8(uint32 argument_0);
uint32 sub_800428B0(void);
uint32 sub_80042D64(uint32 argument_0, GameGeometryCallContext *context);
uint32 sub_80042E14(GameGeometryCallContext *context);
uint32 sub_80042ED4(GameGeometryCallContext *context);
uint32 sub_8004307C(GameGeometryCallContext *context);
uint32 sub_80044E68(void);
uint32 sub_8004F938(uint32 source, GameGeometryCallContext *context);
uint32 sub_800510D0(void);
uint32 sub_80057A90(void);
uint32 sub_800595B8(uint32 argument_0);
uint32 sub_80059E2C(GameSceneCallContext *context);
void sub_8005B668(GameGeometryCallContext *context);
uint32 sub_8005E640(void);
uint32 sub_8005E6CC(void);
uint32 sub_800649E4(GameGeometryCallContext *context);
uint32 sub_8006525C(void);
uint32 sub_80069B84(uint32 index, GameSceneCallContext *context);
uint32 sub_80069BC0(uint32 argument_0);
uint32 sub_8006F178(void);
uint32 sub_8006F27C(void);
uint32 sub_8006F2F4(uint32 argument_0);
uint32 sub_80073438(void);
uint32 sub_800734C0(void);
uint32 sub_80089218(GameGeometryCallContext *context);

void sub_800796DC(GameMainCallContext *context)
{
    FUNCTION_MARKER(0x800796DCu, "1.EXE");
    // BIOS syscall 1 disables callback interruption on the host thread
    (void)context;
    xport_bios_enter_critical();
}

void sub_80079C20(GameMainCallContext *context)
{
    FUNCTION_MARKER(0x80079C20u, "1.EXE");
    // BIOS syscall 2 restores callback interruption on the host thread
    (void)context;
    xport_bios_exit_critical();
}

void sub_800394B8(GameMainCallContext *context)
{
  int v0; // $v0
  int v1; // $v0
  uint32 v2; // $v0
  sint16 v4; // $v0
  int v5; // $v1
  uint32 v6; // $v0
  int v7; // $v1
  int v8; // $v0
  uint32 v9; // $v0
  int v10; // $v1
  uint32 v12; // $v0
  int v13; // $v0
  int v14; // $v1

  uint32 frame = context->stack_pointer - 0x28u;
  context->stack_pointer = frame;
  FUNCTION_MARKER(0x800394B8u, "1.EXE");
  w_u32(frame + 0x20u, context->return_address);
  w_u32(frame + 0x1Cu, context->caller_s3);
  w_u32(frame + 0x18u, context->caller_s2);
  w_u32(frame + 0x14u, context->caller_s1);
  w_u32(frame + 0x10u, context->caller_s0);
  context->return_address = 0x800394D4u;
  {
    uint32 initialized = r_u32(0x80092428u);
    uint32 startup_frame = context->stack_pointer - 0x10u;
    w_u32(startup_frame + 4u, context->caller_s0);
    w_u32(startup_frame + 8u, context->caller_s1);
    w_u32(startup_frame + 0xCu, context->return_address);
    if (initialized == 0u)
      w_u32(0x80092428u, 1u);
    context->return_address = r_u32(startup_frame + 0xCu);
    context->caller_s1 = r_u32(startup_frame + 8u);
    context->caller_s0 = r_u32(startup_frame + 4u);
  }
  w_u32(0x80092450u, 0x200000);
  w_u32(0x8009244Cu, 1024);
  context->caller_s0 = 1u;
  context->return_address = 0x800394F4u;
  sub_800796DC(context);
  SetConf(16, 4, 0x801FFFF0u);
  sub_80079C60(0x801FFFF0u, &context->stack_pointer);
  ResetCallback();
  sub_80079C20(context);
  _96_init();
  FlushCache();
  w_u32(0x800A6DE4u, 0x8015FFF0u);
  w_u32(0x800A6DE4u, 0x8015FFE0u);
  w_u32(0x800A9D58u, 0u);
  w_u32(0x800A9D60u, 0u);
  {
    uint32 boot_first = r_u32(0x8015FFF0u);
    uint32 boot_flags = r_u32(0x8015FFF4u);
    uint32 boot_third = r_u32(0x8015FFF8u);
    uint32 boot_fourth = r_u32(0x8015FFFCu);
    uint32 data_first = r_u32(0x8015FFE0u);
    uint32 data_second = r_u32(0x8015FFE4u);
    uint32 data_third = r_u32(0x8015FFE8u);
    uint32 data_fourth = r_u32(0x8015FFECu);
    w_u32(0x800A854Cu, 1u);
    w_u32(0x800A6E50u, 0u);
    w_u32(0x800A87F8u, boot_first);
    w_u32(0x800A87E4u, boot_flags);
    w_u32(0x800A8698u, boot_third);
    w_u32(0x800A8FD4u, boot_fourth);
    w_u32(0x800A8504u, data_first);
    w_u32(0x800A8508u, data_second);
    w_u32(0x800A850Cu, data_third);
    w_u32(0x800A8510u, data_fourth);
  }
  w_u32(0x800A8698u, 0u);
  w_u32(0x800A8FD4u, 0u);
  sub_8003915C();
  {
    GameGeometryCallContext graphics;
    graphics.stack_pointer = context->stack_pointer;
    graphics.return_address = 0x800395DCu;
    graphics.caller_s0 = context->caller_s0;
    graphics.caller_s1 = context->caller_s1;
    graphics.caller_s2 = context->caller_s2;
    sub_8003C0C4(&graphics);
    context->caller_s0 = graphics.caller_s0;
    context->caller_s1 = graphics.caller_s1;
    context->caller_s2 = graphics.caller_s2;
  }
  {
    GameSceneCallContext controller;
    controller.stack_pointer = context->stack_pointer;
    controller.return_address = 0x800395E4u;
    controller.caller_s0 = context->caller_s0;
    sub_8003806C(&controller);
    context->caller_s0 = controller.caller_s0;
  }
  MemCardInitPSX();
  MemCardStartPSX();
  {
      GameSceneCallContext call_context;
      call_context.stack_pointer = context->stack_pointer;
      call_context.return_address = 0x800395FCu;
      call_context.caller_s0 = context->caller_s0;
      sub_80059E2C(&call_context);
      context->caller_s0 = call_context.caller_s0;
  }
  {
      GameSceneCallContext call_context;
      call_context.stack_pointer = context->stack_pointer;
      call_context.return_address = 0x80039604u;
      call_context.caller_s0 = context->caller_s0;
      sub_80069B84(5, &call_context);
      context->caller_s0 = call_context.caller_s0;
  }
  {
      GameSceneCallContext call_context;
      call_context.stack_pointer = context->stack_pointer;
      call_context.return_address = 0x8003960Cu;
      call_context.caller_s0 = context->caller_s0;
      sub_80069B84(7, &call_context);
      context->caller_s0 = call_context.caller_s0;
  }
  w_u32(0x800A6444u, 1);
  sub_80069BC0(7);
  {
      GameSceneCallContext call_context;
      call_context.stack_pointer = context->stack_pointer;
      call_context.return_address = 0x80039624u;
      call_context.caller_s0 = context->caller_s0;
      sub_80059E2C(&call_context);
      context->caller_s0 = call_context.caller_s0;
  }
  {
    uint32 boot_flags = r_u32(0x800A87E4u);
    w_u32(0x800A6D70u, 0u);
    if ((boot_flags & 10u) == 0u)
      {
          GameGeometryCallContext call_context;
          call_context.stack_pointer = context->stack_pointer;
          call_context.return_address = 0x80039648u;
          call_context.caller_s0 = context->caller_s0; call_context.caller_s1 = context->caller_s1;
          call_context.caller_s2 = context->caller_s2;
      call_context.caller_s3 = context->caller_s3;
      call_context.caller_s4 = context->caller_s4;
      call_context.caller_s5 = context->caller_s5;
      call_context.caller_s6 = context->caller_s6;
      call_context.caller_s7 = context->caller_s7;
          sub_8003C87C(&call_context);
          context->caller_s0 = call_context.caller_s0; context->caller_s1 = call_context.caller_s1;
          context->caller_s2 = call_context.caller_s2;
      }
  }
  {
      GameSceneCallContext call_context;
      call_context.stack_pointer = context->stack_pointer;
      call_context.return_address = 0x80039650u;
      call_context.caller_s0 = context->caller_s0;
      sub_80059E2C(&call_context);
      context->caller_s0 = call_context.caller_s0;
  }
  sub_80069BC0(7);
  SetDispMask(0);
  {
      GameGeometryCallContext call_context;
      call_context.stack_pointer = context->stack_pointer;
      call_context.return_address = 0x80039668u;
      call_context.caller_s0 = context->caller_s0;
      call_context.caller_s1 = context->caller_s1;
      call_context.caller_s2 = context->caller_s2;
      call_context.caller_s3 = context->caller_s3;
      call_context.caller_s4 = context->caller_s4;
      call_context.caller_s5 = context->caller_s5;
      call_context.caller_s6 = context->caller_s6;
      call_context.caller_s7 = context->caller_s7;
      sub_8003BEFC(&call_context);
      context->caller_s0 = call_context.caller_s0;
      context->caller_s1 = call_context.caller_s1;
      context->caller_s2 = call_context.caller_s2;
  }
  w_u16(0x800A6DE0u, 3);
  w_u32(0x800A854Cu, 1);
  w_u32(0x800A6E18u, 0);
  w_u32(0x800A6E1Cu, 2);
  w_u32(0x800A8660u, 0);
  if ( r_u32(0x800A87E4u) )
  {
    sub_8006F2F4(r_u32(0x800A87F8u));
    w_u8(0x800A9872u, 1);
    w_u16(0x800A906Au, 1);
    w_u8(0x800A9878u, 1);
    w_u16(0x800A906Cu, 1);
    sub_80039198();
  }
  context->caller_s0 = 1u;
  context->caller_s3 = 3u;
  context->caller_s1 = 2u;
  context->caller_s2 = 0xFFFFFFFFu;
  while ( 1 )
  {
    {
      GameGeometryCallContext call_context;
      call_context.stack_pointer = context->stack_pointer;
      call_context.return_address = 0x800396E4u;
      call_context.caller_s0 = context->caller_s0;
      call_context.caller_s1 = context->caller_s1;
      call_context.caller_s2 = context->caller_s2;
      call_context.caller_s3 = context->caller_s3;
      call_context.caller_s4 = context->caller_s4;
      call_context.caller_s5 = context->caller_s5;
      call_context.caller_s6 = context->caller_s6;
      call_context.caller_s7 = context->caller_s7;
      sub_8003B864(&call_context);
      context->caller_s1 = call_context.caller_s1;
      context->caller_s2 = call_context.caller_s2;
      context->caller_s0 = call_context.caller_s0;
  }
    { GameMainCallContext bios_context = *context; bios_context.return_address = 0x800396ECu; sub_8003C374(&bios_context); bios_context.return_address = context->return_address; *context = bios_context; }
    w_u32(0x800A9D60u, 1);
    w_u32(0x800A6E34u, 0);
    w_u32(0x800A9758u, 1);
    while ( 1 )
    {
      do
      {
        w_u32(0x800A563Cu, 0);
        if ( !r_u32(0x800A6E34u) )
        {
          sub_8003915C();
          sub_8001F850();
          { GameGeometryCallContext reset_context; reset_context.stack_pointer = context->stack_pointer; reset_context.return_address = 0x80039724u; reset_context.caller_s0 = context->caller_s0; reset_context.caller_s1 = context->caller_s1; reset_context.caller_s2 = context->caller_s2; reset_context.caller_s3 = context->caller_s3; reset_context.caller_s4 = context->caller_s4; reset_context.caller_s5 = context->caller_s5; reset_context.caller_s6 = context->caller_s6; reset_context.caller_s7 = context->caller_s7; sub_8003AD54(&reset_context); context->caller_s0 = reset_context.caller_s0; context->caller_s1 = reset_context.caller_s1; context->caller_s2 = reset_context.caller_s2; context->caller_s3 = reset_context.caller_s3; context->caller_s4 = reset_context.caller_s4; context->caller_s5 = reset_context.caller_s5; context->caller_s6 = reset_context.caller_s6; context->caller_s7 = reset_context.caller_s7; }
          { GameGeometryCallContext scene_context; scene_context.stack_pointer = context->stack_pointer; scene_context.return_address = 0x8003972Cu; scene_context.caller_s0 = context->caller_s0; scene_context.caller_s1 = context->caller_s1; scene_context.caller_s2 = context->caller_s2; scene_context.caller_s3 = context->caller_s3; scene_context.caller_s4 = context->caller_s4; scene_context.caller_s5 = context->caller_s5; scene_context.caller_s6 = context->caller_s6; scene_context.caller_s7 = context->caller_s7; sub_8003C394(&scene_context); context->caller_s0 = scene_context.caller_s0; context->caller_s1 = scene_context.caller_s1; context->caller_s2 = scene_context.caller_s2; context->caller_s3 = scene_context.caller_s3; context->caller_s4 = scene_context.caller_s4; context->caller_s5 = scene_context.caller_s5; context->caller_s6 = scene_context.caller_s6; context->caller_s7 = scene_context.caller_s7; }
          sub_800205C8(1, 12, 3);
          w_u32(0x800A9760u, 0);
          w_u32(0x800A84A0u, 4);
          w_u32(0x800A6D74u, 0);
          { GameGeometryCallContext call_context; call_context.stack_pointer = context->stack_pointer; call_context.return_address = 0x80039754u; call_context.caller_s0 = context->caller_s0; call_context.caller_s1 = context->caller_s1; call_context.caller_s2 = context->caller_s2; call_context.caller_s3 = context->caller_s3; call_context.caller_s4 = context->caller_s4; call_context.caller_s5 = context->caller_s5; call_context.caller_s6 = context->caller_s6; call_context.caller_s7 = context->caller_s7; sub_8003D0F4(&call_context); context->caller_s0 = call_context.caller_s0; context->caller_s1 = call_context.caller_s1; context->caller_s2 = call_context.caller_s2; context->caller_s3 = call_context.caller_s3; context->caller_s4 = call_context.caller_s4; context->caller_s5 = call_context.caller_s5; context->caller_s6 = call_context.caller_s6; context->caller_s7 = call_context.caller_s7; }
          w_u32(0x800A9758u, 1);
          w_u32(0x800A9A30u, 0);
          if ( r_u32(0x800A87E4u) )
          {
            w_u8(0x800A9872u, 1);
            w_u16(0x800A906Au, 1);
            w_u8(0x800A9878u, 1);
            w_u16(0x800A906Cu, 1);
            sub_80039198();
            w_u32(0x800A87E4u, 0);
          }
LABEL_21:
          v0 = r_u32(0x800A9758u);
          do
          {
            if ( !v0 )
              goto LABEL_23;
            w_u32(0x800A563Cu, 0);
            if ( r_u32(0x800A9758u) == 3 )
            {
              {
      GameGeometryCallContext call_context;
      call_context.stack_pointer = context->stack_pointer;
      call_context.return_address = 0x800397B8u;
      call_context.caller_s0 = context->caller_s0;
      call_context.caller_s1 = context->caller_s1;
      call_context.caller_s2 = context->caller_s2;
      call_context.caller_s3 = context->caller_s3;
      call_context.caller_s4 = context->caller_s4;
      call_context.caller_s5 = context->caller_s5;
      call_context.caller_s6 = context->caller_s6;
      call_context.caller_s7 = context->caller_s7;
      sub_8003B864(&call_context);
      context->caller_s1 = call_context.caller_s1;
      context->caller_s2 = call_context.caller_s2;
      context->caller_s0 = call_context.caller_s0;
  }
              w_u32(0x800A9758u, 1);
              sub_800205C8(1, 12, 1);
            }
            if ( r_u32(0x800A9758u) == 2 )
              sub_800205C8(1, 12, 1);
            sub_80069BC0(3);
            { GameGeometryCallContext memory_context; memory_context.stack_pointer = context->stack_pointer; memory_context.return_address = 0x800397F8u; memory_context.caller_s0 = context->caller_s0; memory_context.caller_s1 = context->caller_s1; memory_context.caller_s2 = context->caller_s2; memory_context.caller_s3 = context->caller_s3; memory_context.caller_s4 = context->caller_s4; memory_context.caller_s5 = context->caller_s5; memory_context.caller_s6 = context->caller_s6; memory_context.caller_s7 = context->caller_s7; sub_800649E4(&memory_context); context->caller_s0 = memory_context.caller_s0; context->caller_s1 = memory_context.caller_s1; context->caller_s2 = memory_context.caller_s2; context->caller_s3 = memory_context.caller_s3; context->caller_s4 = memory_context.caller_s4; context->caller_s5 = memory_context.caller_s5; context->caller_s6 = memory_context.caller_s6; context->caller_s7 = memory_context.caller_s7; }
            { GameGeometryCallContext scene_context; scene_context.stack_pointer = context->stack_pointer; scene_context.return_address = 0x80039800u; scene_context.caller_s0 = context->caller_s0; scene_context.caller_s1 = context->caller_s1; scene_context.caller_s2 = context->caller_s2; scene_context.caller_s3 = context->caller_s3; scene_context.caller_s4 = context->caller_s4; scene_context.caller_s5 = context->caller_s5; scene_context.caller_s6 = context->caller_s6; scene_context.caller_s7 = context->caller_s7; sub_8003C2B8(0u, &scene_context); context->caller_s0 = scene_context.caller_s0; context->caller_s1 = scene_context.caller_s1; context->caller_s2 = scene_context.caller_s2; context->caller_s3 = scene_context.caller_s3; context->caller_s4 = scene_context.caller_s4; context->caller_s5 = scene_context.caller_s5; context->caller_s6 = scene_context.caller_s6; context->caller_s7 = scene_context.caller_s7; }
            { GameGeometryCallContext load_context; load_context.stack_pointer = context->stack_pointer; load_context.return_address = 0x80039808u; load_context.caller_fp = context->caller_fp; load_context.caller_s0 = context->caller_s0; load_context.caller_s1 = context->caller_s1; load_context.caller_s2 = context->caller_s2; load_context.caller_s3 = context->caller_s3; load_context.caller_s4 = context->caller_s4; load_context.caller_s5 = context->caller_s5; load_context.caller_s6 = context->caller_s6; load_context.caller_s7 = context->caller_s7; sub_8004F938(0u, &load_context); context->caller_fp = load_context.caller_fp; context->caller_s0 = load_context.caller_s0; context->caller_s1 = load_context.caller_s1; context->caller_s2 = load_context.caller_s2; context->caller_s3 = load_context.caller_s3; context->caller_s4 = load_context.caller_s4; context->caller_s5 = load_context.caller_s5; context->caller_s6 = load_context.caller_s6; context->caller_s7 = load_context.caller_s7; }
            if ( r_u32(0x800A9758u) != 2 )
            {
              w_u16(0x800A9A64u, 1);
              { GameGeometryCallContext cd_context; cd_context.stack_pointer = context->stack_pointer; cd_context.return_address = 0x80039828u; cd_context.caller_s0 = context->caller_s0; cd_context.caller_s1 = context->caller_s1; cd_context.caller_s2 = context->caller_s2; cd_context.caller_s3 = context->caller_s3; cd_context.caller_s4 = context->caller_s4; cd_context.caller_s5 = context->caller_s5; cd_context.caller_s6 = context->caller_s6; cd_context.caller_s7 = context->caller_s7; cd_context.caller_fp = context->caller_fp; sub_80037150(&cd_context); context->caller_s0 = cd_context.caller_s0; context->caller_s1 = cd_context.caller_s1; context->caller_s2 = cd_context.caller_s2; context->caller_s3 = cd_context.caller_s3; context->caller_s4 = cd_context.caller_s4; context->caller_s5 = cd_context.caller_s5; context->caller_s6 = cd_context.caller_s6; context->caller_s7 = cd_context.caller_s7; context->caller_fp = cd_context.caller_fp; }
              sub_800376C0();
              sub_800374BC(r_u32(0x800A7F44u));
            }
            w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
            sub_800428B0();
            {
              uint32 restored_stack = r_u32(0x800A9CE0u);
              w_u32(0x800A576Cu, 0u);
              sub_80079C60(restored_stack, &context->stack_pointer);
            }
            w_u32(0x800A9684u, r_u32(0x800A9CD0u));
            sub_8006525C();
            sub_8003CA20();
            sub_800510D0();
            if ( r_u32(0x800A9A30u) != 1 )
              goto LABEL_21;
            v0 = r_u32(0x800A9758u);
          }
          while ( r_u32(0x800A9758u) != 2 );
          sub_8003AB60(1u);
          sub_80069BC0(7);
          {
              GameSceneCallContext call_context;
              call_context.stack_pointer = context->stack_pointer;
              call_context.return_address = 0x800398D4u;
              call_context.caller_s0 = context->caller_s0;
              sub_80059E2C(&call_context);
              context->caller_s0 = call_context.caller_s0;
          }
          if ( r_u32(0x800A9D60u) == 1 )
          {
            sub_8006F178();
            w_u32(0x800A9D60u, 0);
          }
          {
              GameGeometryCallContext call_context;
              call_context.stack_pointer = context->stack_pointer;
              call_context.return_address = 0x800398F8u;
              call_context.caller_s0 = context->caller_s0; call_context.caller_s1 = context->caller_s1;
              call_context.caller_s2 = context->caller_s2;
      call_context.caller_s3 = context->caller_s3;
      call_context.caller_s4 = context->caller_s4;
      call_context.caller_s5 = context->caller_s5;
      call_context.caller_s6 = context->caller_s6;
      call_context.caller_s7 = context->caller_s7;
              sub_8003C87C(&call_context);
              context->caller_s0 = call_context.caller_s0; context->caller_s1 = call_context.caller_s1;
              context->caller_s2 = call_context.caller_s2;
          }
          w_u32(0x800A6E1Cu, 1);
          sub_8003AB60(0u);
          {
              GameSceneCallContext call_context;
              call_context.stack_pointer = context->stack_pointer;
              call_context.return_address = 0x8003990Cu;
              call_context.caller_s0 = context->caller_s0;
              sub_80059E2C(&call_context);
              context->caller_s0 = call_context.caller_s0;
          }
          ResetCallback();
          {
      GameGeometryCallContext call_context;
      call_context.stack_pointer = context->stack_pointer;
      call_context.return_address = 0x8003991Cu;
      call_context.caller_s0 = context->caller_s0;
      call_context.caller_s1 = context->caller_s1;
      call_context.caller_s2 = context->caller_s2;
      call_context.caller_s3 = context->caller_s3;
      call_context.caller_s4 = context->caller_s4;
      call_context.caller_s5 = context->caller_s5;
      call_context.caller_s6 = context->caller_s6;
      call_context.caller_s7 = context->caller_s7;
      sub_8003BEFC(&call_context);
      context->caller_s0 = call_context.caller_s0;
      context->caller_s1 = call_context.caller_s1;
      context->caller_s2 = call_context.caller_s2;
  }
          w_u32(0x800A854Cu, 1);
          w_u32(0x800A6E34u, 0);
          w_u32(0x800A6E18u, 0);
          w_u16(0x800A6DE0u, 3);
LABEL_23:
          if ( r_u32(0x800A9A30u) == 1 && r_u32(0x800A9758u) == 2 )
            goto LABEL_175;
          {
            uint32 selected_mode = r_u32(0x800A7F0Cu);
            if (selected_mode - 1u >= 4u)
            {
              w_u32(0x800A9760u, 0u);
              w_u32(0x800A9864u, 0u);
              w_u32(0x800A6E60u, 1u);
            }
            else
            {
              if (selected_mode == 3u)
                w_u32(0x800A9764u, 3u);
              if (selected_mode == 2u)
                w_u32(0x800A9764u, 2u);
              if (selected_mode == 1u)
                w_u32(0x800A9764u, 1u);
              if (selected_mode == 4u)
                w_u32(0x800A9764u, selected_mode);
              uint32 mode_halfword = r_u16(0x800A9764u);
              w_u32(0x800A9760u, 1u);
              w_u32(0x800A9768u, 1u);
              w_u32(0x800A6E60u, 0u);
              w_u16(0x800A6DE0u, mode_halfword);
            }
          }
          w_u32(0x800A9CD8u, 60);
          sub_8003D27C(255);
          if ( r_u32(0x800A7F0Cu) == 5 )
          {
            w_u32(0x800A7C6Cu, 0);
            w_u32(0x800A6E28u, 0);
          }
          else
          {
            w_u32(0x800A6E28u, r_u32(0x800A7C6Cu));
          }
          sub_8003D6A0(0);
          sub_8003D694(0);
          if ( (sint32)r_u32(0x800A854Cu) >= 10 )
          {
            w_u8(0x800A9872u, 1);
            w_u16(0x800A906Au, 1);
          }
          if ( (sint32)r_u32(0x800A854Cu) >= 17 )
          {
            w_u8(0x800A9878u, 1);
            w_u16(0x800A906Cu, 1);
          }
          sub_800734C0();
          w_u32(0x800A9758u, 3);
        }
        w_u32(0x800A6E48u, 1);
        while ( 1 )
        {
          w_u32(0x800A563Cu, 0);
          if ( r_u32(0x800A9760u) == 1 )
          {
            w_u32(0x800A8690u, 0);
            sub_8003B8E8(r_u32(0x800A9768u), 0);
          }
          if ( !r_u32(0x800A9760u) )
          {
            w_u32(0x800A8690u, 2);
            w_u32(0x800A6E68u, sub_8003B8E8(r_u32(0x800A854Cu), 2));
          }
          if ( r_u32(0x800A6E18u) != (sint32)(sint16)r_u16(0x800A6DE0u) )
          {
            {
      uint32 selected;
      GameGeometryCallContext call_context;
      call_context.stack_pointer = context->stack_pointer;
      call_context.return_address = 0x80039B2Cu;
      call_context.caller_s0 = context->caller_s0;
      call_context.caller_s1 = context->caller_s1;
      call_context.caller_s2 = context->caller_s2;
      call_context.caller_s3 = context->caller_s3;
      call_context.caller_s4 = context->caller_s4;
      call_context.caller_s5 = context->caller_s5;
      call_context.caller_s6 = context->caller_s6;
      call_context.caller_s7 = context->caller_s7;
      selected = sub_8003B574((uint32)(sint32)(sint16)r_u16(0x800A6DE0u), 0u, &call_context);
      context->caller_s0 = call_context.caller_s0;
      context->caller_s1 = call_context.caller_s1;
      context->caller_s2 = call_context.caller_s2;
      w_u16(0x800A6DE0u, selected);
  }
            { GameGeometryCallContext scene_context; scene_context.stack_pointer = context->stack_pointer; scene_context.return_address = 0x80039B38u; scene_context.caller_s0 = context->caller_s0; scene_context.caller_s1 = context->caller_s1; scene_context.caller_s2 = context->caller_s2; scene_context.caller_s3 = context->caller_s3; scene_context.caller_s4 = context->caller_s4; scene_context.caller_s5 = context->caller_s5; scene_context.caller_s6 = context->caller_s6; scene_context.caller_s7 = context->caller_s7; sub_8003C394(&scene_context); context->caller_s0 = scene_context.caller_s0; context->caller_s1 = scene_context.caller_s1; context->caller_s2 = scene_context.caller_s2; context->caller_s3 = scene_context.caller_s3; context->caller_s4 = scene_context.caller_s4; context->caller_s5 = scene_context.caller_s5; context->caller_s6 = scene_context.caller_s6; context->caller_s7 = scene_context.caller_s7; }
            w_u32(0x800A8690u, 0);
          }
          if ( r_u32(0x800A6E60u) != 1 )
            goto LABEL_65;
          v1 = r_u32(0x800A9760u);
          if ( !r_u32(0x800A9760u) )
          {
            if ( r_u32(0x800A6E68u) != 0xFFFFFFFFu )
            {
              w_u32(0x800A9D5Cu, 30);
              w_u32(0x800A9A48u, 0);
              w_u32(0x800A8690u, 2);
              sub_8003CA68(0x800A6D84u);
              w_u32(0x800A6E34u, 0);
              sub_80069BC0(3);
              { GameGeometryCallContext memory_context; memory_context.stack_pointer = context->stack_pointer; memory_context.return_address = 0x80039B9Cu; memory_context.caller_s0 = context->caller_s0; memory_context.caller_s1 = context->caller_s1; memory_context.caller_s2 = context->caller_s2; memory_context.caller_s3 = context->caller_s3; memory_context.caller_s4 = context->caller_s4; memory_context.caller_s5 = context->caller_s5; memory_context.caller_s6 = context->caller_s6; memory_context.caller_s7 = context->caller_s7; sub_800649E4(&memory_context); context->caller_s0 = memory_context.caller_s0; context->caller_s1 = memory_context.caller_s1; context->caller_s2 = memory_context.caller_s2; context->caller_s3 = memory_context.caller_s3; context->caller_s4 = memory_context.caller_s4; context->caller_s5 = memory_context.caller_s5; context->caller_s6 = memory_context.caller_s6; context->caller_s7 = memory_context.caller_s7; }
              { GameGeometryCallContext scene_context; scene_context.stack_pointer = context->stack_pointer; scene_context.return_address = 0x80039BA4u; scene_context.caller_s0 = context->caller_s0; scene_context.caller_s1 = context->caller_s1; scene_context.caller_s2 = context->caller_s2; scene_context.caller_s3 = context->caller_s3; scene_context.caller_s4 = context->caller_s4; scene_context.caller_s5 = context->caller_s5; scene_context.caller_s6 = context->caller_s6; scene_context.caller_s7 = context->caller_s7; sub_8003C2B8(0u, &scene_context); context->caller_s0 = scene_context.caller_s0; context->caller_s1 = scene_context.caller_s1; context->caller_s2 = scene_context.caller_s2; context->caller_s3 = scene_context.caller_s3; context->caller_s4 = scene_context.caller_s4; context->caller_s5 = scene_context.caller_s5; context->caller_s6 = scene_context.caller_s6; context->caller_s7 = scene_context.caller_s7; }
              { GameGeometryCallContext load_context; load_context.stack_pointer = context->stack_pointer; load_context.return_address = 0x80039BACu; load_context.caller_fp = context->caller_fp; load_context.caller_s0 = context->caller_s0; load_context.caller_s1 = context->caller_s1; load_context.caller_s2 = context->caller_s2; load_context.caller_s3 = context->caller_s3; load_context.caller_s4 = context->caller_s4; load_context.caller_s5 = context->caller_s5; load_context.caller_s6 = context->caller_s6; load_context.caller_s7 = context->caller_s7; sub_8004F938(0u, &load_context); context->caller_fp = load_context.caller_fp; context->caller_s0 = load_context.caller_s0; context->caller_s1 = load_context.caller_s1; context->caller_s2 = load_context.caller_s2; context->caller_s3 = load_context.caller_s3; context->caller_s4 = load_context.caller_s4; context->caller_s5 = load_context.caller_s5; context->caller_s6 = load_context.caller_s6; context->caller_s7 = load_context.caller_s7; }
              w_u16(0x800A9A64u, 1);
              { GameGeometryCallContext cd_context; cd_context.stack_pointer = context->stack_pointer; cd_context.return_address = 0x80039BBCu; cd_context.caller_s0 = context->caller_s0; cd_context.caller_s1 = context->caller_s1; cd_context.caller_s2 = context->caller_s2; cd_context.caller_s3 = context->caller_s3; cd_context.caller_s4 = context->caller_s4; cd_context.caller_s5 = context->caller_s5; cd_context.caller_s6 = context->caller_s6; cd_context.caller_s7 = context->caller_s7; cd_context.caller_fp = context->caller_fp; sub_80037150(&cd_context); context->caller_s0 = cd_context.caller_s0; context->caller_s1 = cd_context.caller_s1; context->caller_s2 = cd_context.caller_s2; context->caller_s3 = cd_context.caller_s3; context->caller_s4 = cd_context.caller_s4; context->caller_s5 = cd_context.caller_s5; context->caller_s6 = cd_context.caller_s6; context->caller_s7 = cd_context.caller_s7; context->caller_fp = cd_context.caller_fp; }
              sub_800376C0();
              sub_800374BC(r_u32(0x800A7F44u));
              VSync(3);
              VSync(3);
              VSync(3);
              VSync(3);
              w_u32(0x800A6E30u, 1);
              w_u32(0x800A7E04u, 0);
              w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
              sub_80035664(2);
              sub_80079C60(r_u32(0x800A9CE0u), &context->stack_pointer);
              sub_800356D8();
              sub_800205C8(180, 12, 3);
              w_u32(0x800A6D80u, 1);
              w_u16(0x800A9D70u, 0);
              w_u32(0x800A7E50u, 0);
              do
              {
                v2 = sub_80030E18(0);
                w_u32(0x800A6D80u, v2);
                if ( !v2 )
                  break;
                uint32 object_index = (uint32)(sint32)(sint16)r_u16(v2);
                uint32 object_table = r_u32(0x800A851Cu);
                uint32 object_record = r_u32(object_table + (object_index << 2u));
                uint32 object_flag = r_u8(object_record + 17u);
                if (object_flag != 0u)
                {
                  uint32 old_stack = sub_80079C60(0x1F8003FCu, &context->stack_pointer);
                  uint32 current_object = r_u32(0x800A6D80u);
                  w_u32(0x800A9CE0u, old_stack);
                  w_u32(0x800A9020u, current_object);
                  sub_800352C4(0x1F8003FCu);
                  {
                    uint32 restored_stack = r_u32(0x800A9CE0u);
                    w_u32(0x800A576Cu, 0u);
                    sub_80079C60(restored_stack, &context->stack_pointer);
                  }
                }
                if ( r_u16(0x800A5C04u) )
                  sub_800313EC(r_u32(0x800A6D80u));
              }
              while ( r_u32(0x800A6D80u) );
              sub_80036F0C();
              sub_8006525C();
              sub_8003570C();
              sub_800390E4();
              w_u32(0x800A6E30u, 0);
              w_u32(0x800A8690u, 0);
              sub_8003CA20();
              sub_800510D0();
              sub_8003B8E8(r_u32(0x800A854Cu), 0);
              if ( r_u32(0x800A6E18u) != (sint32)(sint16)r_u16(0x800A6DE0u) )
              {
                {
      uint32 selected;
      GameGeometryCallContext call_context;
      call_context.stack_pointer = context->stack_pointer;
      call_context.return_address = 0x80039D60u;
      call_context.caller_s0 = context->caller_s0;
      call_context.caller_s1 = context->caller_s1;
      call_context.caller_s2 = context->caller_s2;
      call_context.caller_s3 = context->caller_s3;
      call_context.caller_s4 = context->caller_s4;
      call_context.caller_s5 = context->caller_s5;
      call_context.caller_s6 = context->caller_s6;
      call_context.caller_s7 = context->caller_s7;
      selected = sub_8003B574((uint32)(sint32)(sint16)r_u16(0x800A6DE0u), 0u, &call_context);
      context->caller_s0 = call_context.caller_s0;
      context->caller_s1 = call_context.caller_s1;
      context->caller_s2 = call_context.caller_s2;
      w_u16(0x800A6DE0u, selected);
  }
                { GameGeometryCallContext scene_context; scene_context.stack_pointer = context->stack_pointer; scene_context.return_address = 0x80039D6Cu; scene_context.caller_s0 = context->caller_s0; scene_context.caller_s1 = context->caller_s1; scene_context.caller_s2 = context->caller_s2; scene_context.caller_s3 = context->caller_s3; scene_context.caller_s4 = context->caller_s4; scene_context.caller_s5 = context->caller_s5; scene_context.caller_s6 = context->caller_s6; scene_context.caller_s7 = context->caller_s7; sub_8003C394(&scene_context); context->caller_s0 = scene_context.caller_s0; context->caller_s1 = scene_context.caller_s1; context->caller_s2 = scene_context.caller_s2; context->caller_s3 = scene_context.caller_s3; context->caller_s4 = scene_context.caller_s4; context->caller_s5 = scene_context.caller_s5; context->caller_s6 = scene_context.caller_s6; context->caller_s7 = scene_context.caller_s7; }
              }
            }
            w_u32(0x800A6E60u, 0);
LABEL_65:
            v1 = r_u32(0x800A9760u);
          }
          if ( v1 == 1 )
            w_u32(0x800A6E68u, -1);
          sub_8003CA68(0x800A6D84u);
          w_u32(0x800A6E34u, 0);
          sub_80069BC0(3);
          { GameGeometryCallContext memory_context; memory_context.stack_pointer = context->stack_pointer; memory_context.return_address = 0x80039DA8u; memory_context.caller_s0 = context->caller_s0; memory_context.caller_s1 = context->caller_s1; memory_context.caller_s2 = context->caller_s2; memory_context.caller_s3 = context->caller_s3; memory_context.caller_s4 = context->caller_s4; memory_context.caller_s5 = context->caller_s5; memory_context.caller_s6 = context->caller_s6; memory_context.caller_s7 = context->caller_s7; sub_800649E4(&memory_context); context->caller_s0 = memory_context.caller_s0; context->caller_s1 = memory_context.caller_s1; context->caller_s2 = memory_context.caller_s2; context->caller_s3 = memory_context.caller_s3; context->caller_s4 = memory_context.caller_s4; context->caller_s5 = memory_context.caller_s5; context->caller_s6 = memory_context.caller_s6; context->caller_s7 = memory_context.caller_s7; }
          { GameGeometryCallContext scene_context; scene_context.stack_pointer = context->stack_pointer; scene_context.return_address = 0x80039DB0u; scene_context.caller_s0 = context->caller_s0; scene_context.caller_s1 = context->caller_s1; scene_context.caller_s2 = context->caller_s2; scene_context.caller_s3 = context->caller_s3; scene_context.caller_s4 = context->caller_s4; scene_context.caller_s5 = context->caller_s5; scene_context.caller_s6 = context->caller_s6; scene_context.caller_s7 = context->caller_s7; sub_8003C2B8(0u, &scene_context); context->caller_s0 = scene_context.caller_s0; context->caller_s1 = scene_context.caller_s1; context->caller_s2 = scene_context.caller_s2; context->caller_s3 = scene_context.caller_s3; context->caller_s4 = scene_context.caller_s4; context->caller_s5 = scene_context.caller_s5; context->caller_s6 = scene_context.caller_s6; context->caller_s7 = scene_context.caller_s7; }
          { GameGeometryCallContext load_context; load_context.stack_pointer = context->stack_pointer; load_context.return_address = 0x80039DB8u; load_context.caller_fp = context->caller_fp; load_context.caller_s0 = context->caller_s0; load_context.caller_s1 = context->caller_s1; load_context.caller_s2 = context->caller_s2; load_context.caller_s3 = context->caller_s3; load_context.caller_s4 = context->caller_s4; load_context.caller_s5 = context->caller_s5; load_context.caller_s6 = context->caller_s6; load_context.caller_s7 = context->caller_s7; sub_8004F938(0u, &load_context); context->caller_fp = load_context.caller_fp; context->caller_s0 = load_context.caller_s0; context->caller_s1 = load_context.caller_s1; context->caller_s2 = load_context.caller_s2; context->caller_s3 = load_context.caller_s3; context->caller_s4 = load_context.caller_s4; context->caller_s5 = load_context.caller_s5; context->caller_s6 = load_context.caller_s6; context->caller_s7 = load_context.caller_s7; }
          w_u16(0x800A9A64u, 1);
          if ( r_u32(0x800A6E68u) == 0xFFFFFFFFu )
          {
            { GameGeometryCallContext cd_context; cd_context.stack_pointer = context->stack_pointer; cd_context.return_address = 0x80039DD8u; cd_context.caller_s0 = context->caller_s0; cd_context.caller_s1 = context->caller_s1; cd_context.caller_s2 = context->caller_s2; cd_context.caller_s3 = context->caller_s3; cd_context.caller_s4 = context->caller_s4; cd_context.caller_s5 = context->caller_s5; cd_context.caller_s6 = context->caller_s6; cd_context.caller_s7 = context->caller_s7; cd_context.caller_fp = context->caller_fp; sub_80037150(&cd_context); context->caller_s0 = cd_context.caller_s0; context->caller_s1 = cd_context.caller_s1; context->caller_s2 = cd_context.caller_s2; context->caller_s3 = cd_context.caller_s3; context->caller_s4 = cd_context.caller_s4; context->caller_s5 = cd_context.caller_s5; context->caller_s6 = cd_context.caller_s6; context->caller_s7 = cd_context.caller_s7; context->caller_fp = cd_context.caller_fp; }
            sub_800376C0();
            sub_800374BC(r_u32(0x800A7F44u));
          }
          else
          {
            { GameGeometryCallContext cd_context; cd_context.stack_pointer = context->stack_pointer; cd_context.return_address = 0x80039E00u; cd_context.caller_s0 = context->caller_s0; cd_context.caller_s1 = context->caller_s1; cd_context.caller_s2 = context->caller_s2; cd_context.caller_s3 = context->caller_s3; cd_context.caller_s4 = context->caller_s4; cd_context.caller_s5 = context->caller_s5; cd_context.caller_s6 = context->caller_s6; cd_context.caller_s7 = context->caller_s7; cd_context.caller_fp = context->caller_fp; sub_80037150(&cd_context); context->caller_s0 = cd_context.caller_s0; context->caller_s1 = cd_context.caller_s1; context->caller_s2 = cd_context.caller_s2; context->caller_s3 = cd_context.caller_s3; context->caller_s4 = cd_context.caller_s4; context->caller_s5 = cd_context.caller_s5; context->caller_s6 = cd_context.caller_s6; context->caller_s7 = cd_context.caller_s7; context->caller_fp = cd_context.caller_fp; }
            sub_800376C0();
            sub_8003708C();
          }
          w_u32(0x800A6E20u, 0);
          w_u32(0x800A6E24u, 0);
          { GameGeometryCallContext call_context; call_context.stack_pointer = context->stack_pointer; call_context.return_address = 0x80039E28u; call_context.caller_s0 = context->caller_s0; call_context.caller_s1 = context->caller_s1; call_context.caller_s2 = context->caller_s2; call_context.caller_s3 = context->caller_s3; call_context.caller_s4 = context->caller_s4; call_context.caller_s5 = context->caller_s5; call_context.caller_s6 = context->caller_s6; call_context.caller_s7 = context->caller_s7; sub_8003D0F4(&call_context); context->caller_s0 = call_context.caller_s0; context->caller_s1 = call_context.caller_s1; context->caller_s2 = call_context.caller_s2; context->caller_s3 = call_context.caller_s3; context->caller_s4 = call_context.caller_s4; context->caller_s5 = call_context.caller_s5; context->caller_s6 = call_context.caller_s6; context->caller_s7 = call_context.caller_s7; }
          sub_8003D6B8(0);
          sub_800595B8(1);
          sub_80057A90();
          w_u32(0x800A7E10u, 100);
          w_u32(0x800A86A0u, 2048);
          sub_8003D324(2048);
          v4 = sub_8003D270();
          sub_8003D27C((sint32)(sint16)((uint32)v4 | 0xFFu));
          w_u32(0x800A9CD8u, 60);
          w_u32(0x800A9A34u, 0);
          w_u32(0x800A6258u, 0);
          w_u32(0x800A7C6Cu, r_u32(0x800A6E28u));
          sub_800205C8(180, 12, 3);
          w_u32(0x800A6E54u, 1);
          do
          {
            if ( r_u32(0x800A9760u) == 1 )
            {
              sub_8003D6B8(0);
              sub_80031754();
              w_u32(0x800A7BF4u, 0);
            }
            else
            {
              w_u32(0x800A7BF4u, 1);
            }
            w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
            sub_8003B1EC();
            {
              uint32 restored_stack = r_u32(0x800A9CE0u);
              w_u32(0x800A576Cu, 0u);
              w_u32(0x800A6E14u, 0u);
              sub_80079C60(restored_stack, &context->stack_pointer);
            }
            v5 = r_u32(0x800A6E20u);
            if ( r_u32(0x800A6E20u) == 11 )
            {
              sub_80036D6C();
              sub_800375A4();
              sub_8005E640();
              sub_800205C8(180, 12, 1);
              sub_80031290();
              sub_800330E0();
              sub_800333C4();
              w_u32(0x800A8398u, 0);
              w_u32(0x800A98F4u, 0);
              w_u32(0x800A84D4u, 1);
              w_u32(0x800A7E04u, 0);
              sub_80022A68(2);
              sub_80036D6C();
              sub_800375A4();
              sub_8001F850();
              w_u32(0x800A8B30u, 1);
              sub_800356D8();
              sub_800339D0(0x2000);
              w_u32(0x800A7E50u, 0);
              do
              {
                w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
                w_u32(0x800A6DF0u, sub_80034CA8(r_u32(0x800A9020u)));
                {
                  uint32 restored_stack = r_u32(0x800A9CE0u);
                  w_u32(0x800A576Cu, 0u);
                  sub_80079C60(restored_stack, &context->stack_pointer);
                }
                w_u32(0x800A8398u, 0);
                w_u32(0x800A98F4u, 0);
              }
              while ( (sint32)r_u32(0x800A6DF0u) >= 0 );
              sub_800390E4();
              if ( r_u32(0x800A6DF0u) == -1 || (sint16)sub_80037BB8() != 2 )
                w_u32(0x800A8B30u, 0);
              w_u32(0x800A8398u, 0);
              w_u32(0x800A98F4u, 0);
              w_u16(0x800A901Cu, 0);
              sub_80033400();
              sub_80033100();
              w_u16(0x800A967Cu, 0);
              w_u32(0x800A84D4u, 0);
              sub_800205C8(1, 12, 3);
              sub_8005E6CC();
              w_u32(0x800A6E24u, 5);
              w_u32(0x800A6E54u, 1);
              v5 = r_u32(0x800A6E20u);
            }
            if ( v5 == 9 )
            {
              w_u32(0x800A9D5Cu, 30);
              w_u32(0x800A6E30u, 1);
              w_u32(0x800A8398u, 0);
              w_u32(0x800A98F4u, 0);
              sub_8005E640();
              sub_80022A68(2);
              sub_80036D6C();
              sub_800375A4();
              sub_8001F850();
              sub_80033478();
              sub_800389E8(64);
              w_u16(0x800A866Cu, 1);
              w_u32(0x800A7E04u, 0);
              sub_800356D8();
              w_u32(0x800A7E50u, 0);
              w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
              sub_80034CA8(r_u32(0x800A6D78u));
              {
                uint32 restored_stack = r_u32(0x800A9CE0u);
                w_u32(0x800A576Cu, 0u);
                sub_80079C60(restored_stack, &context->stack_pointer);
              }
              if ( r_u16(0x800A5C04u) )
                sub_800313EC(r_u32(0x800A6D78u));
              w_u32(0x800A6D80u, 1);
              do
              {
                v6 = sub_80030E18(1);
                w_u32(0x800A6D80u, v6);
                if ( !v6 )
                  break;
                uint32 object_index = (uint32)(sint32)(sint16)r_u16(v6);
                uint32 object_table = r_u32(0x800A851Cu);
                uint32 object_record = r_u32(object_table + (object_index << 2u));
                uint32 object_flag = r_u8(object_record + 17u);
                if (object_flag != 0u)
                {
                  w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
                  sub_80034CA8(r_u32(0x800A6D80u));
                  {
                    uint32 restored_stack = r_u32(0x800A9CE0u);
                    w_u32(0x800A576Cu, 0u);
                    sub_80079C60(restored_stack, &context->stack_pointer);
                  }
                }
                if ( r_u16(0x800A5C04u) )
                  sub_800313EC(r_u32(0x800A6D80u));
              }
              while ( r_u32(0x800A6D80u) );
              sub_8003570C();
              sub_800334A8();
              sub_800390E4();
              w_u16(0x800A8B34u, 0);
              w_u32(0x800A6E30u, 0);
              sub_80036D6C();
              sub_800375A4();
              { GameGeometryCallContext sound_context; sound_context.stack_pointer = context->stack_pointer; sound_context.return_address = 0x8003A248u; sound_context.caller_s0 = context->caller_s0; sound_context.caller_s1 = context->caller_s1; sound_context.caller_s2 = context->caller_s2; sound_context.caller_s3 = context->caller_s3; sound_context.caller_s4 = context->caller_s4; sound_context.caller_s5 = context->caller_s5; sound_context.caller_s6 = context->caller_s6; sound_context.caller_s7 = context->caller_s7; sub_8005B668(&sound_context); context->caller_s0 = sound_context.caller_s0; context->caller_s1 = sound_context.caller_s1; context->caller_s2 = sound_context.caller_s2; context->caller_s3 = sound_context.caller_s3; context->caller_s4 = sound_context.caller_s4; context->caller_s5 = sound_context.caller_s5; context->caller_s6 = sound_context.caller_s6; context->caller_s7 = sound_context.caller_s7; }
              sub_8002133C();
              sub_8005E6CC();
              w_u32(0x800A6E24u, 5);
              w_u32(0x800A6E54u, 1);
              sub_800205C8(1, 12, 3);
            }
            v7 = r_u32(0x800A6E20u);
            if ( r_u32(0x800A6E20u) == 6 || r_u32(0x800A6E20u) == 31 )
            {
              sub_80035988((sint32)(sint16)r_u16(0x800A56ACu));
              {
                sint32 second_sound = (sint32)(sint16)r_u16(0x800A56B4u);
                w_u16(0x800A56ACu, 0xFFFFu);
                sub_80035988(second_sound);
              }
              w_u16(0x800A56B4u, -1);
              if ( (sint32)r_u32(0x800A9A34u) >= 40 || (v8 = (sint32)(sint16)r_u16(0x800A9734u), v8 == 2) )
              {
                {
      GameGeometryCallContext bridge = {0};
      bridge.stack_pointer = context->stack_pointer;
      bridge.return_address = context->return_address;
      bridge.caller_s0 = context->caller_s0;
      bridge.caller_s1 = context->caller_s1;
      bridge.caller_s2 = context->caller_s2;
      bridge.caller_s3 = context->caller_s3;
      bridge.caller_s4 = context->caller_s4;
      bridge.caller_s5 = context->caller_s5;
      bridge.caller_s6 = context->caller_s6;
      bridge.caller_s7 = context->caller_s7;
      bridge.caller_fp = context->caller_fp;
      sub_80042D64(2, &bridge);
      context->caller_s0 = bridge.caller_s0;
      context->caller_s1 = bridge.caller_s1;
      context->caller_s2 = bridge.caller_s2;
      context->caller_s3 = bridge.caller_s3;
      context->caller_s4 = bridge.caller_s4;
      context->caller_s5 = bridge.caller_s5;
      context->caller_s6 = bridge.caller_s6;
      context->caller_s7 = bridge.caller_s7;
      context->caller_fp = bridge.caller_fp;
    }
                v8 = (sint32)(sint16)r_u16(0x800A9734u);
              }
              w_u32(0x800A8E70u, 0);
              w_u32(0x800A7E04u, 1);
              if ( v8 == 3 )
                w_u32(0x800A6E14u, 1);
              sub_800356D8();
              w_u32(0x800A6D80u, 1);
              w_u32(0x800A7E50u, 0);
              do
              {
                if ( r_u16(0x800A9D70u) )
                {
                  w_u16(0x800A9D70u, 0);
                }
                else
                {
                  v9 = sub_80030E18(0);
                  w_u32(0x800A6D80u, v9);
                  if ( !v9 )
                    break;
                  uint32 object_index = (uint32)(sint32)(sint16)r_u16(v9);
                  uint32 object_table = r_u32(0x800A851Cu);
                  uint32 object_record = r_u32(object_table + (object_index << 2u));
                  uint32 object_flag = r_u8(object_record + 17u);
                  if (object_flag != 0u)
                  {
                    w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
                    w_u32(0x800A7E04u, 2);
                    sub_80034CA8(r_u32(0x800A6D80u));
                    {
                      uint32 restored_stack = r_u32(0x800A9CE0u);
                      w_u32(0x800A576Cu, 0u);
                      sub_80079C60(restored_stack, &context->stack_pointer);
                    }
                  }
                  if ( r_u16(0x800A5C04u) )
                    sub_800313EC(r_u32(0x800A6D80u));
                }
              }
              while ( r_u32(0x800A6D80u) );
              w_u16(0x800A9A64u, 1);
              sub_8003708C();
              sub_8003570C();
              sub_8003CA20();
              if ( r_u32(0x800A9760u) == 1 )
                w_u32(0x800A6E20u, 31);
              if ( r_u32(0x800A6E20u) != 31 )
              {
                w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
                if ( !r_u8(0x800A7BDCu) )
                  {
      GameGeometryCallContext bridge = {0};
      bridge.stack_pointer = context->stack_pointer;
      bridge.return_address = context->return_address;
      bridge.caller_s0 = context->caller_s0;
      bridge.caller_s1 = context->caller_s1;
      bridge.caller_s2 = context->caller_s2;
      bridge.caller_s3 = context->caller_s3;
      bridge.caller_s4 = context->caller_s4;
      bridge.caller_s5 = context->caller_s5;
      bridge.caller_s6 = context->caller_s6;
      bridge.caller_s7 = context->caller_s7;
      bridge.caller_fp = context->caller_fp;
      sub_80042E14(&bridge);
      context->caller_s0 = bridge.caller_s0;
      context->caller_s1 = bridge.caller_s1;
      context->caller_s2 = bridge.caller_s2;
      context->caller_s3 = bridge.caller_s3;
      context->caller_s4 = bridge.caller_s4;
      context->caller_s5 = bridge.caller_s5;
      context->caller_s6 = bridge.caller_s6;
      context->caller_s7 = bridge.caller_s7;
      context->caller_fp = bridge.caller_fp;
    }
                {
                  uint32 restored_stack = r_u32(0x800A9CE0u);
                  w_u32(0x800A576Cu, 0u);
                  sub_80079C60(restored_stack, &context->stack_pointer);
                }
                sub_800510D0();
                sub_80069BC0(3);
                { GameGeometryCallContext memory_context; memory_context.stack_pointer = context->stack_pointer; memory_context.return_address = 0x8003A488u; memory_context.caller_s0 = context->caller_s0; memory_context.caller_s1 = context->caller_s1; memory_context.caller_s2 = context->caller_s2; memory_context.caller_s3 = context->caller_s3; memory_context.caller_s4 = context->caller_s4; memory_context.caller_s5 = context->caller_s5; memory_context.caller_s6 = context->caller_s6; memory_context.caller_s7 = context->caller_s7; sub_800649E4(&memory_context); context->caller_s0 = memory_context.caller_s0; context->caller_s1 = memory_context.caller_s1; context->caller_s2 = memory_context.caller_s2; context->caller_s3 = memory_context.caller_s3; context->caller_s4 = memory_context.caller_s4; context->caller_s5 = memory_context.caller_s5; context->caller_s6 = memory_context.caller_s6; context->caller_s7 = memory_context.caller_s7; }
              }
              sub_8006F27C();
              w_u16(0x800A901Cu, 0);
              w_u32(0x800A6E30u, 0);
              w_u32(0x800A8E70u, 1);
              w_u16(0x800A9734u, 4);
              sub_8003CAB4(0x800A6D84u);
              w_u32(0x800A6E60u, 1);
              if ( !r_u32(0x800A9760u) && !r_u32(0x800A8660u) )
              {
                w_u32(0x800A84A0u, r_u32(0x800A84A0u) - 1u);
                if ( (sint32)r_u32(0x800A84A0u) <= 0 )
                  w_u32(0x800A6E40u, 1);
                w_u32(0x800A9CD8u, 60);
              }
              w_u32(0x800A6E54u, 0);
              sub_80057A90();
              v7 = r_u32(0x800A6E20u);
            }
            if ( v7 == 5 )
            {
              sub_80035988((sint32)(sint16)r_u16(0x800A56ACu));
              {
                sint32 second_sound = (sint32)(sint16)r_u16(0x800A56B4u);
                w_u16(0x800A56ACu, 0xFFFFu);
                sub_80035988(second_sound);
              }
              w_u16(0x800A56B4u, -1);
              w_u32(0x800A6E28u, r_u32(0x800A7C6Cu));
              sub_80044E68();
              w_u32(0x800A8E70u, 0);
              w_u32(0x800A7E04u, 2);
              v10 = (sint32)(r_u32(0x800A854Cu) + 1u);
              w_u32(0x800A854Cu, (uint32)v10);
              if (v10 >= 10)
              {
                w_u8(0x800A9872u, 1);
                w_u16(0x800A906Au, 1);
              }
              if ( v10 >= 17 )
              {
                w_u8(0x800A9878u, 1);
                w_u16(0x800A906Cu, 1);
              }
              if ( v10 < 26 )
              {
                sub_800356D8();
                w_u32(0x800A6D80u, 1);
                w_u32(0x800A7E50u, 0);
                do
                {
                  if ( r_u16(0x800A9D70u) )
                  {
                    w_u16(0x800A9D70u, 0);
                  }
                  else
                  {
                    v12 = sub_80030E18(0);
                    w_u32(0x800A6D80u, v12);
                    if ( !v12 )
                      break;
                    uint32 object_index = (uint32)(sint32)(sint16)r_u16(v12);
                    uint32 object_table = r_u32(0x800A851Cu);
                    uint32 object_record = r_u32(object_table + (object_index << 2u));
                    uint32 object_flag = r_u8(object_record + 17u);
                    if (object_flag != 0u)
                    {
                      w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
                      w_u32(0x800A7E04u, 2);
                      sub_80034CA8(r_u32(0x800A6D80u));
                      {
                        uint32 restored_stack = r_u32(0x800A9CE0u);
                        w_u32(0x800A576Cu, 0u);
                        sub_80079C60(restored_stack, &context->stack_pointer);
                      }
                    }
                    if ( r_u16(0x800A5C04u) )
                      sub_800313EC(r_u32(0x800A6D80u));
                  }
                }
                while ( r_u32(0x800A6D80u) );
                w_u16(0x800A9A64u, 1);
                sub_8003708C();
                sub_8003570C();
                sub_8003CA20();
                w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
                sub_800734C0();
                {
      GameGeometryCallContext bridge = {0};
      bridge.stack_pointer = context->stack_pointer;
      bridge.return_address = context->return_address;
      bridge.caller_s0 = context->caller_s0;
      bridge.caller_s1 = context->caller_s1;
      bridge.caller_s2 = context->caller_s2;
      bridge.caller_s3 = context->caller_s3;
      bridge.caller_s4 = context->caller_s4;
      bridge.caller_s5 = context->caller_s5;
      bridge.caller_s6 = context->caller_s6;
      bridge.caller_s7 = context->caller_s7;
      bridge.caller_fp = context->caller_fp;
      sub_8004307C(&bridge);
      context->caller_s0 = bridge.caller_s0;
      context->caller_s1 = bridge.caller_s1;
      context->caller_s2 = bridge.caller_s2;
      context->caller_s3 = bridge.caller_s3;
      context->caller_s4 = bridge.caller_s4;
      context->caller_s5 = bridge.caller_s5;
      context->caller_s6 = bridge.caller_s6;
      context->caller_s7 = bridge.caller_s7;
      context->caller_fp = bridge.caller_fp;
    }
              }
              else
              {
                w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
                {
      GameGeometryCallContext bridge = {0};
      bridge.stack_pointer = context->stack_pointer;
      bridge.return_address = context->return_address;
      bridge.caller_s0 = context->caller_s0;
      bridge.caller_s1 = context->caller_s1;
      bridge.caller_s2 = context->caller_s2;
      bridge.caller_s3 = context->caller_s3;
      bridge.caller_s4 = context->caller_s4;
      bridge.caller_s5 = context->caller_s5;
      bridge.caller_s6 = context->caller_s6;
      bridge.caller_s7 = context->caller_s7;
      bridge.caller_fp = context->caller_fp;
      sub_80042E14(&bridge);
      context->caller_s0 = bridge.caller_s0;
      context->caller_s1 = bridge.caller_s1;
      context->caller_s2 = bridge.caller_s2;
      context->caller_s3 = bridge.caller_s3;
      context->caller_s4 = bridge.caller_s4;
      context->caller_s5 = bridge.caller_s5;
      context->caller_s6 = bridge.caller_s6;
      context->caller_s7 = bridge.caller_s7;
      context->caller_fp = bridge.caller_fp;
    }
              }
              {
                uint32 restored_stack = r_u32(0x800A9CE0u);
                w_u32(0x800A576Cu, 0u);
                sub_80079C60(restored_stack, &context->stack_pointer);
              }
              sub_8003CA20();
              if ( r_u32(0x800A9760u) == 1 )
                w_u32(0x800A6E20u, 31);
              if ( r_u32(0x800A6E20u) != 31 )
              {
                sub_800510D0();
                sub_80069BC0(3);
                { GameGeometryCallContext memory_context; memory_context.stack_pointer = context->stack_pointer; memory_context.return_address = 0x8003A750u; memory_context.caller_s0 = context->caller_s0; memory_context.caller_s1 = context->caller_s1; memory_context.caller_s2 = context->caller_s2; memory_context.caller_s3 = context->caller_s3; memory_context.caller_s4 = context->caller_s4; memory_context.caller_s5 = context->caller_s5; memory_context.caller_s6 = context->caller_s6; memory_context.caller_s7 = context->caller_s7; sub_800649E4(&memory_context); context->caller_s0 = memory_context.caller_s0; context->caller_s1 = memory_context.caller_s1; context->caller_s2 = memory_context.caller_s2; context->caller_s3 = memory_context.caller_s3; context->caller_s4 = memory_context.caller_s4; context->caller_s5 = memory_context.caller_s5; context->caller_s6 = memory_context.caller_s6; context->caller_s7 = memory_context.caller_s7; }
              }
              sub_8006F27C();
              w_u16(0x800A901Cu, 0);
              w_u32(0x800A6E30u, 0);
              w_u32(0x800A8E70u, 1);
              w_u32(0x800A6E34u, 1);
              if ( r_u32(0x800A9760u) == 1 )
                w_u32(0x800A985Cu, 0);
              else
                w_u32(0x800A6E20u, 22);
              w_u32(0x800A6E54u, 0);
              sub_80057A90();
              if ( (r_u32(0x800A854Cu) & 1) != 0 )
              {
                w_u32(0x800A84A0u, r_u32(0x800A84A0u) + 1u);
                if ( (sint32)r_u32(0x800A84A0u) >= 4 )
                  w_u32(0x800A84A0u, 4);
              }
            }
            if ( (unsigned int)(r_u32(0x800A6E20u) - 30) < 2 )
            {
              sub_800205C8(1, 12, 3);
              sub_8003CA20();
              w_u32(0x800A9CE0u, sub_80079C60(0x1F8003FCu, &context->stack_pointer));
              {
      GameGeometryCallContext bridge = {0};
      bridge.stack_pointer = context->stack_pointer;
      bridge.return_address = context->return_address;
      bridge.caller_s0 = context->caller_s0;
      bridge.caller_s1 = context->caller_s1;
      bridge.caller_s2 = context->caller_s2;
      bridge.caller_s3 = context->caller_s3;
      bridge.caller_s4 = context->caller_s4;
      bridge.caller_s5 = context->caller_s5;
      bridge.caller_s6 = context->caller_s6;
      bridge.caller_s7 = context->caller_s7;
      bridge.caller_fp = context->caller_fp;
      sub_80042ED4(&bridge);
      context->caller_s0 = bridge.caller_s0;
      context->caller_s1 = bridge.caller_s1;
      context->caller_s2 = bridge.caller_s2;
      context->caller_s3 = bridge.caller_s3;
      context->caller_s4 = bridge.caller_s4;
      context->caller_s5 = bridge.caller_s5;
      context->caller_s6 = bridge.caller_s6;
      context->caller_s7 = bridge.caller_s7;
      context->caller_fp = bridge.caller_fp;
    }
              {
                uint32 restored_stack = r_u32(0x800A9CE0u);
                w_u32(0x800A576Cu, 0u);
                sub_80079C60(restored_stack, &context->stack_pointer);
              }
              if ( r_u32(0x800A84DCu) == 1 )
              {
                w_u32(0x800A6E20u, 2);
                w_u32(0x800A6E40u, 1);
                w_u32(0x800A6E34u, 0);
              }
              else
              {
                sub_8003CA20();
                sub_800510D0();
                w_u32(0x800A6E60u, 1);
                sub_8003CAB4(0x800A6D84u);
                w_u32(0x800A6E54u, 0);
                sub_80057A90();
                sub_80073438();
                w_u32(0x800A9CD8u, 60);
                w_u32(0x800A6E40u, 0);
                w_u32(0x800A6E34u, 1);
                w_u32(0x800A6E20u, 22);
              }
            }
            v13 = r_u32(0x800A6E20u);
            if (v13 == 2)
            {
              sub_8003CA20();
              sub_800510D0();
              w_u32(0x800A6E60u, 1);
              sub_8003CAB4(0x800A6D84u);
              if ( !r_u32(0x800A9760u) && !r_u32(0x800A8660u) )
              {
                w_u32(0x800A84A0u, r_u32(0x800A84A0u) - 1u);
                if ( (sint32)r_u32(0x800A84A0u) <= 0 )
                  w_u32(0x800A6E40u, 1);
                w_u32(0x800A9CD8u, 60);
              }
              w_u32(0x800A6E54u, 0);
              sub_80057A90();
              v13 = r_u32(0x800A6E20u);
            }
            if ( v13 == 3 )
            {
              w_u16(0x800A9A64u, 1);
              sub_8003708C();
              w_u32(0x800A6E54u, 0);
              sub_80057A90();
            }
            if (v14 == 4)
            {
              w_u16(0x800A9A64u, 1);
              sub_8003708C();
              w_u32(0x800A6E54u, 0);
              sub_80057A90();
            }
          }
          while ( r_u32(0x800A6E54u) );
          sub_8006525C();
          { GameGeometryCallContext sound_context; sound_context.stack_pointer = context->stack_pointer; sound_context.return_address = 0x8003A9A0u; sound_context.caller_s0 = context->caller_s0; sound_context.caller_s1 = context->caller_s1; sound_context.caller_s2 = context->caller_s2; sound_context.caller_s3 = context->caller_s3; sound_context.caller_s4 = context->caller_s4; sound_context.caller_s5 = context->caller_s5; sound_context.caller_s6 = context->caller_s6; sound_context.caller_s7 = context->caller_s7; sub_800360BC(&sound_context); context->caller_s0 = sound_context.caller_s0; context->caller_s1 = sound_context.caller_s1; context->caller_s2 = sound_context.caller_s2; context->caller_s3 = sound_context.caller_s3; context->caller_s4 = sound_context.caller_s4; context->caller_s5 = sound_context.caller_s5; context->caller_s6 = sound_context.caller_s6; context->caller_s7 = sound_context.caller_s7; }
          if ( r_u32(0x800A6E34u) == 1 )
            goto LABEL_167;
          if ( r_u32(0x800A6E40u) == 1 )
            break;
          if ( !r_u32(0x800A6E48u) )
            goto LABEL_167;
        }
        SetDispMask(0);
        w_u32(0x800A6E48u, 0);
        w_u32(0x800A6E34u, 0);
        w_u32(0x800A854Cu, 1);
        sub_8006F178();
        w_u32(0x800A9D60u, 0);
LABEL_167:
        if ( r_u32(0x800A6E40u) == 1 )
          goto LABEL_175;
        v14 = r_u32(0x800A6E20u);
        if (v14 == 3)
        {
          w_u32(0x800A9760u, 0);
          SetDispMask(0);
          sub_8003CA20();
          sub_800510D0();
          sub_8006F178();
          w_u32(0x800A9D60u, 0);
          SetDispMask(1);
          w_u32(0x800A854Cu, 1);
          w_u32(0x800A6E34u, 0);
          goto LABEL_175;
        }
        if (v14 == 4)
        {
          w_u32(0x800A9760u, 0);
          SetDispMask(0);
          sub_8003CA20();
          sub_800510D0();
          SetDispMask(1);
          w_u32(0x800A6E20u, 22);
          w_u32(0x800A6E34u, 1);
          v14 = (sint32)r_u32(0x800A6E20u);
        }
      }
      while ( v14 != 22 );
      sub_80069BC0(2);
      if ( (sint32)r_u32(0x800A854Cu) >= 26 )
        break;
      w_u32(0x800A6E24u, 0);
      w_u32(0x800A6E60u, 1);
    }
    w_u32(0x800A6E50u, 1);
LABEL_175:
    if ( r_u32(0x800A6E50u) == 1 )
    {
      uint32 completion_flags = r_u32(0x800A87E4u);
      w_u32(0x800A576Cu, 0u);
      w_u32(0x800A87E4u, completion_flags | 8u);
      sub_8003AB60(1u);
      sub_80069BC0(7);
      if ( r_u32(0x800A9D60u) == 1 )
      {
        sub_8006F178();
        w_u32(0x800A9D60u, 0);
      }
      {
          GameSceneCallContext call_context;
          call_context.stack_pointer = context->stack_pointer;
          call_context.return_address = 0x8003AAC0u;
          call_context.caller_s0 = context->caller_s0;
          sub_80059E2C(&call_context);
          context->caller_s0 = call_context.caller_s0;
      }
      {
      GameGeometryCallContext bridge = {0};
      bridge.stack_pointer = context->stack_pointer;
      bridge.return_address = context->return_address;
      bridge.caller_s0 = context->caller_s0;
      bridge.caller_s1 = context->caller_s1;
      bridge.caller_s2 = context->caller_s2;
      bridge.caller_s3 = context->caller_s3;
      bridge.caller_s4 = context->caller_s4;
      bridge.caller_s5 = context->caller_s5;
      bridge.caller_s6 = context->caller_s6;
      bridge.caller_s7 = context->caller_s7;
      bridge.caller_fp = context->caller_fp;
      sub_8003C958(&bridge);
      context->caller_s0 = bridge.caller_s0;
      context->caller_s1 = bridge.caller_s1;
      context->caller_s2 = bridge.caller_s2;
      context->caller_s3 = bridge.caller_s3;
      context->caller_s4 = bridge.caller_s4;
      context->caller_s5 = bridge.caller_s5;
      context->caller_s6 = bridge.caller_s6;
      context->caller_s7 = bridge.caller_s7;
      context->caller_fp = bridge.caller_fp;
    }
      { GameGeometryCallContext sound_context; sound_context.stack_pointer = context->stack_pointer; sound_context.return_address = 0x8003AAD0u; sound_context.caller_s0 = context->caller_s0; sound_context.caller_s1 = context->caller_s1; sound_context.caller_s2 = context->caller_s2; sound_context.caller_s3 = context->caller_s3; sound_context.caller_s4 = context->caller_s4; sound_context.caller_s5 = context->caller_s5; sound_context.caller_s6 = context->caller_s6; sound_context.caller_s7 = context->caller_s7; sub_800360BC(&sound_context); context->caller_s0 = sound_context.caller_s0; context->caller_s1 = sound_context.caller_s1; context->caller_s2 = sound_context.caller_s2; context->caller_s3 = sound_context.caller_s3; context->caller_s4 = sound_context.caller_s4; context->caller_s5 = sound_context.caller_s5; context->caller_s6 = sound_context.caller_s6; context->caller_s7 = sound_context.caller_s7; }
      {
          GameGeometryCallContext call_context;
          call_context.stack_pointer = context->stack_pointer;
          call_context.return_address = 0x8003AAD8u;
          call_context.caller_s0 = context->caller_s0; call_context.caller_s1 = context->caller_s1;
          call_context.caller_s2 = context->caller_s2; call_context.caller_s3 = context->caller_s3;
          call_context.caller_s4 = context->caller_s4; call_context.caller_s5 = context->caller_s5;
          call_context.caller_s6 = context->caller_s6; call_context.caller_s7 = context->caller_s7;
          sub_80089218(&call_context);
          context->caller_s0 = call_context.caller_s0; context->caller_s1 = call_context.caller_s1;
          context->caller_s2 = call_context.caller_s2; context->caller_s3 = call_context.caller_s3;
          context->caller_s4 = call_context.caller_s4; context->caller_s5 = call_context.caller_s5;
          context->caller_s6 = call_context.caller_s6; context->caller_s7 = call_context.caller_s7;
      }
      sub_8003AB60(0u);
      w_u32(0x800A87E4u, r_u32(0x800A87E4u) | (4u));
      {
      GameGeometryCallContext bridge = {0};
      bridge.stack_pointer = context->stack_pointer;
      bridge.return_address = context->return_address;
      bridge.caller_s0 = context->caller_s0;
      bridge.caller_s1 = context->caller_s1;
      bridge.caller_s2 = context->caller_s2;
      bridge.caller_s3 = context->caller_s3;
      bridge.caller_s4 = context->caller_s4;
      bridge.caller_s5 = context->caller_s5;
      bridge.caller_s6 = context->caller_s6;
      bridge.caller_s7 = context->caller_s7;
      bridge.caller_fp = context->caller_fp;
      sub_800392B4(&bridge);
      context->caller_s0 = bridge.caller_s0;
      context->caller_s1 = bridge.caller_s1;
      context->caller_s2 = bridge.caller_s2;
      context->caller_s3 = bridge.caller_s3;
      context->caller_s4 = bridge.caller_s4;
      context->caller_s5 = bridge.caller_s5;
      context->caller_s6 = bridge.caller_s6;
      context->caller_s7 = bridge.caller_s7;
      context->caller_fp = bridge.caller_fp;
    }
    }
  }
}

void game_call_scene_initializer_context(uint32 target, uint32 destination, GameSceneCallContext *context)
{
    switch (target)
    {
        case 0x80063AFCu:
            sub_80063AFC(destination, context->stack_pointer);
            return;
        case 0x80063C3Cu:
            sub_80063C3C(destination, context->stack_pointer);
            return;
        case 0x80063E28u:
            sub_80063E28(destination, context->stack_pointer);
            return;
        case 0x80064020u:
            sub_80064020(destination, context->stack_pointer);
            return;
        case 0x80064200u:
            sub_80064200(destination, context->stack_pointer);
            return;
        default:
            game_call_scene_initializer_other(target, destination, context->stack_pointer);
            return;
    }
}

void game_call_scene_initializer_other(uint32 target, uint32 destination, uint32 entry_sp)
{
    (void)destination;
    (void)entry_sp;
    fprintf(stderr, "Unbound scene initializer %08X\n", target);
    abort();
}
