#include "native_call_dispatch.h"

static uint32 native_common_volume(uint32 attr, uint32 offset, uint32 mode_offset, uint32 use_mode)
{
    uint32 mode = 0u, volume;
    sint32 signed_volume;
    if (use_mode)
    {
        sint32 requested = (sint16)r_u16(attr + mode_offset);
        if (requested >= 1 && requested <= 7)
            mode = 0x7000u + ((uint32)requested << 12);
    }
    if (mode == 0u)
        volume = r_u16(attr + offset) & 0x7FFFu;
    else
    {
        signed_volume = (sint16)r_u16(attr + offset);
        volume = signed_volume < 0 ? 0u : signed_volume >= 128 ? 127u : (uint32)signed_volume;
    }
    return volume | mode;
}

uint32 sub_8008757C(uint32 attr)
{
    uint32 mask = r_u32(attr), all = mask == 0u;
    uint32 base, value, result;
    FUNCTION_MARKER(0x8008757Cu, "1.EXE");
    if (all || (mask & 1u) != 0u)
    {
        value = native_common_volume(attr, 4u, 8u, all || (mask & 4u) != 0u);
        base = r_u32(0x800A4E14u);
        w_u16(base + 0x180u, (uint16)value);
    }
    if (all || (mask & 2u) != 0u)
    {
        value = native_common_volume(attr, 6u, 10u, all || (mask & 8u) != 0u);
        base = r_u32(0x800A4E14u);
        w_u16(base + 0x182u, (uint16)value);
    }
    if (all || (mask & 0x40u) != 0u)
    {
        base = r_u32(0x800A4E14u);
        w_u16(base + 0x1B0u, r_u16(attr + 16u));
    }
    if (all || (mask & 0x80u) != 0u)
    {
        base = r_u32(0x800A4E14u);
        w_u16(base + 0x1B2u, r_u16(attr + 18u));
    }
    if (all || (mask & 0x400u) != 0u)
    {
        base = r_u32(0x800A4E14u);
        w_u16(base + 0x1B4u, r_u16(attr + 28u));
    }
    if (all || (mask & 0x800u) != 0u)
    {
        base = r_u32(0x800A4E14u);
        w_u16(base + 0x1B6u, r_u16(attr + 30u));
    }
    if (all || (mask & 0x100u) != 0u)
    {
        value = r_u32(attr + 20u);
        base = r_u32(0x800A4E14u);
        value = value != 0u ? r_u16(base + 0x1AAu) | 4u : r_u16(base + 0x1AAu) & 0xFFFBu;
        w_u16(base + 0x1AAu, (uint16)value);
    }
    if (all || (mask & 0x200u) != 0u)
    {
        value = r_u32(attr + 24u);
        base = r_u32(0x800A4E14u);
        value = value != 0u ? r_u16(base + 0x1AAu) | 1u : r_u16(base + 0x1AAu) & 0xFFFEu;
        w_u16(base + 0x1AAu, (uint16)value);
    }
    if (all || (mask & 0x1000u) != 0u)
    {
        value = r_u32(attr + 32u);
        base = r_u32(0x800A4E14u);
        value = value != 0u ? r_u16(base + 0x1AAu) | 8u : r_u16(base + 0x1AAu) & 0xFFF7u;
        w_u16(base + 0x1AAu, (uint16)value);
    }
    result = mask & 0x2000u;
    if (all || result != 0u)
    {
        value = r_u32(attr + 36u);
        result = r_u32(0x800A4E14u);
        value = value != 0u ? r_u16(result + 0x1AAu) | 2u : r_u16(result + 0x1AAu) & 0xFFFDu;
        w_u16(result + 0x1AAu, (uint16)value);
    }
    return result;
}
