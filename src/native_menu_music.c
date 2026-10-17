#include "psx.h"
#include "xport.h"
#include "draft_adapters.h"

extern uint32 sub_8003708C(void);
extern uint32 sub_80036EDC(uint32 volume);
extern uint32 sub_8007B368(uint32 command, uint32 argument, uint32 result);
extern uint32 sub_8007B4A0(uint32 command, uint32 argument);
extern uint32 sub_8007B7B4(uint32 sector, uint32 position);

uint32 sub_80037BD0(void)
{
    sint32 type = (sint16)r_u16(0x800A5C70u);
    sint32 divisor, value;
    uint32 product, magnitude;
    FUNCTION_MARKER(0x80037BD0u, "1.EXE");
    if (type == 2)
    {
        divisor = (sint32)r_u32(0x800A5C78u);
        if (!divisor)
            xport_mips_break(7u);
        value = (sint32)((uint32)((sint32)r_u8(0x800A6D30u) - 128) * (uint32)(128 / divisor));
    }
    else if (type == 3)
    {
        divisor = (sint32)r_u32(0x800A5C84u);
        if (!divisor)
            xport_mips_break(7u);
        product = (uint32)((sint32)r_u8(0x800A6D40u) - 128) * (uint32)(128 / divisor);
        magnitude = (sint32)product < 0 ? 0u - product : product;
        product *= magnitude;
        if ((sint32)product < 0)
            product += 127u;
        product = (uint32)((sint32)product >> 3) & 0x1FF0u;
        value = (sint32)((uint32)r_u16(0x800102E0u + product) << 16) >> 21;
    }
    else
    {
        return 3u;
    }
    if (value >= 128)
        value = 127;
    if (value < -127)
        value = -127;
    return ((uint32)value - 128u) & 255u;
}

uint32 sub_80037D14(void)
{
    sint32 type = (sint16)r_u16(0x800A5C70u);
    FUNCTION_MARKER(0x80037D14u, "1.EXE");
    if (type == 2)
        return r_u8(0x800A6D34u);
    if (type == 3)
        return r_u8(0x800A6D3Cu);
    return 3u;
}

uint32 sub_80037D44(void)
{
    FUNCTION_MARKER(0x80037D44u, "1.EXE");
    return r_u8(0x800A6D38u);
}

uint32 sub_80037B3C(void)
{
    uint32 result;
    FUNCTION_MARKER(0x80037B3Cu, "1.EXE");
    if (r_u32(0x800A5C60u))
        return sub_8003708C();
    for (uint32 attempt = 0u; attempt < 10u; ++attempt)
    {
        result = sub_8007B368(6u, 0u, 0u);
        w_u32(0x800A7BE0u, result);
        if (result == 1u)
            return result;
        VSync(3);
    }
    return 0u;
}

uint32 sub_800371C4(uint32 track)
{
    uint32 mark = draft_scratch_mark();
    uint32 position, result, start, offset, repeated_start;
    sint32 selected, group;
    FUNCTION_MARKER(0x800371C4u, "1.EXE");
    draft_call_adapter(0x80037150u);
    selected = (sint16)r_u16(r_u32(0x800A7C68u) + track * 2u - 2u);
    w_u32(0x800A966Cu, 60u);
    group = selected / 8;
    w_u8(0x800A9A40u, 1u);
    w_u8(0x800A9A41u, (uint32)selected & 7u);
    for (uint32 attempt = 0u; attempt < 10u; ++attempt)
    {
        result = sub_8007B4A0(13u, 0x800A9A40u);
        w_u32(0x800A7BE0u, result);
        if (result == 1u)
            break;
        VSync(3);
    }
    start = r_u32(0x800BB8B8u + (uint32)group * 4u);
    selected = (sint16)r_u16(r_u32(0x800A7C68u) + track * 2u - 2u);
    offset = (uint32)(sint32)(sint16)r_u16(r_u32(0x800A7BF0u) + (uint32)selected * 2u);
    repeated_start = r_u32(0x800BB8B8u + (uint32)group * 4u);
    w_u32(0x800A9308u, start);
    w_u32(0x800A7FA8u, start);
    w_u32(0x800A7EE0u, offset + repeated_start - 37u);
    position = draft_scratch_adapter(8u);
    sub_8007B7B4(start, position);
    for (uint32 attempt = 0u; attempt < 10u; ++attempt)
    {
        result = sub_8007B368(6u, position, 0u);
        w_u32(0x800A7BE0u, result);
        if (result == 1u)
            break;
        VSync(3);
    }
    result = sub_80036EDC(r_u32(0x800A975Cu));
    w_u16(0x800A9A64u, 0u);
    w_u32(0x800A5C48u, 0u);
    draft_scratch_release(mark);
    return result;
}
