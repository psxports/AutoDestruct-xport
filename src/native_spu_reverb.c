#include "native_call_dispatch.h"

uint32 sub_8008A1DC(uint32 on, uint32 mask, uint32 low_index, uint32 high_index)
{
    uint32 base, low, high, voices, pending, shift;
    FUNCTION_MARKER(0x8008A1DCu, "1.EXE");
    base = (r_u32(0x800A52DCu) & 1u) != 0u ? 0x800B6710u : r_u32(0x800A4E14u);
    high = r_u16(base + 2u * high_index);
    low = r_u16(base + 2u * low_index);
    voices = low | ((high & 255u) << 16);
    if (on == 0u || on == 1u)
    {
        pending = r_u32(0x800A52DCu) & 1u;
        base = pending != 0u ? 0x800B6710u : r_u32(0x800A4E14u);
        low = r_u16(base + 2u * low_index);
        w_u16(base + 2u * low_index, (uint16)(on == 1u ? low | mask : low & ~mask));
        high = r_u16(base + 2u * high_index);
        w_u16(base + 2u * high_index, (uint16)(on == 1u ? high | ((mask >> 16) & 255u) : high & ~((mask >> 16) & 255u)));
        if (pending != 0u)
        {
            shift = (uint32)((sint32)(low_index - 198u) >> 1) & 31u;
            w_u32(0x800A4EA8u, r_u32(0x800A4EA8u) | (1u << shift));
        }
        voices = on == 1u ? voices | (mask & 0xFFFFFFu) : voices & ~(mask & 0xFFFFFFu);
    }
    return voices & 0xFFFFFFu;
}

uint32 sub_800891B0(uint32 on, uint32 voice_mask)
{
    FUNCTION_MARKER(0x800891B0u, "1.EXE");
    return sub_8008A1DC(on, voice_mask, 204u, 205u);
}
