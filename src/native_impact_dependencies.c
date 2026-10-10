#include "draft_signatures.h"

uint32 sub_80040B54(uint32 position)
{
    uint32 effect;
    uint32 z;
    FUNCTION_MARKER(0x80040B54u, "1.EXE");
    effect = sub_800227C4(40u);
    w_u8(effect + 34u, 11u);
    w_u16(effect + 36u, 288u);
    w_u16(effect + 38u, 0u);
    w_u32(effect + 20u, r_u32(position));
    w_u32(effect + 24u, r_u32(position + 4u));
    z = r_u32(position + 8u);
    w_u32(effect, 0x80040BC4u);
    w_u16(effect + 8u, 288u);
    w_u32(effect + 28u, z);
    return effect;
}

uint32 sub_80060D20(uint32 object, uint32 previous)
{
    uint32 mark = draft_scratch_mark();
    uint32 vector = draft_scratch_adapter(6u);
    uint32 effect = sub_800227C4(40u);
    FUNCTION_MARKER(0x80060D20u, "1.EXE");
    w_u8(effect + 34u, 8u);
    w_u16(effect + 36u, 288u);
    w_u16(effect + 38u, 0u);
    w_u32(effect + 20u, r_u32(object + 20u));
    w_u32(effect + 24u, r_u32(object + 24u));
    w_u32(effect, 0x80060E20u);
    w_u32(effect + 28u, r_u32(object + 28u));
    w_u16(vector, (sub_80069A50() & 31u) - 15u);
    w_u16(vector + 2u, (sub_80069A50() & 31u) + 15u);
    w_u16(vector + 4u, (sub_80069A50() & 31u) - 15u);
    sub_8005EE38(vector, previous);
    w_u16(effect + 8u, 128u);
    w_u16(effect + 10u, r_u16(vector));
    w_u16(effect + 16u, r_u16(vector + 2u));
    w_u16(effect + 18u, r_u16(vector + 4u));
    w_u8(effect + 13u, sub_80069A50() + 129u);
    w_u8(effect + 35u, 1u);
    return (uint32)draft_scratch_result(mark, 1u);
}

uint32 sub_80040BC4(uint32 object)
{
    uint32 i, effect, scale, model;
    sint32 x, y, z;
    FUNCTION_MARKER(0x80040BC4u, "1.EXE");
    for (i = 0u; i < 5u; ++i)
    {
        effect = sub_800227C4(40u);
        w_u8(effect + 34u, 11u);
        scale = (uint32)(sint32)(sint16)r_u16(object + 8u) * 21760u;
        w_u16(effect + 38u, 0u);
        model = r_u32(0x800A62ECu);
        w_u16(effect + 36u, scale >> 15u);
        model = r_u16(model + 88u);
        w_u8(effect + 14u, r_u8(effect + 14u) | 2u);
        w_u32(effect, 0x80040DACu);
        w_u16(effect + 32u, model);
        x = (sint32)(sub_80069A50() & 63u) - 31;
        y = (sint32)(sub_80069A50() & 63u) - 31;
        z = (sint32)(sub_80069A50() & 63u) - 31;
        w_u32(effect + 20u, (uint32)((sint32)((uint32)x * 163840u) >> 16u) + r_u32(object + 20u));
        w_u32(effect + 24u, (uint32)((sint32)((uint32)y * 163840u) >> 16u) + r_u32(object + 24u));
        w_u32(effect + 28u, (uint32)((sint32)((uint32)z * 163840u) >> 16u) + r_u32(object + 28u));
        w_u16(effect + 8u, (uint32)((sint32)((uint32)x * 22784u) >> 16u));
        w_u16(effect + 10u, (uint32)((sint32)((uint32)y * 22784u) >> 16u));
        w_u16(effect + 16u, (uint32)((sint32)((uint32)z * 22784u) >> 16u));
        w_u16(effect + 18u, (sub_80069A50() & 31u) - 15u);
    }
    return sub_8002289C(object);
}

uint32 sub_80060E20(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 previous = draft_scratch_adapter(12u);
    uint32 ticks, rotation, result;
    sint32 remaining;
    FUNCTION_MARKER(0x80060E20u, "1.EXE");
    w_u32(previous, r_u32(object + 20u));
    ticks = r_u32(0x800A9010u);
    w_u32(previous + 4u, r_u32(object + 24u));
    w_u32(previous + 8u, r_u32(object + 28u));
    remaining = (sint32)ticks;
    while (remaining > 0)
    {
        --remaining;
        w_u32(object + 20u, r_u32(object + 20u) + (uint32)(sint32)(sint16)r_u16(object + 10u));
        w_u32(object + 24u, r_u32(object + 24u) - (uint32)(sint32)(sint16)r_u16(object + 16u));
        w_u32(object + 28u, r_u32(object + 28u) + (uint32)(sint32)(sint16)r_u16(object + 18u));
        w_u16(object + 16u, r_u16(object + 16u) - 1u);
        if ((sint8)r_u8(object + 35u) < 0)
        {
            draft_call_adapter(0x80060F6Cu, object, r_u16(r_u32(0x800A62ECu) + 46u), 100u);
            draft_call_adapter(0x80060F6Cu, object, r_u16(r_u32(0x800A62ECu) + 60u), 200u);
            w_u8(object + 35u, 1u);
        }
        w_u8(object + 35u, r_u8(object + 35u) + 255u);
    }
    rotation = ticks * (uint32)(sint32)(sint8)r_u8(object + 13u);
    w_u16(object + 8u, r_u16(object + 8u) - ticks);
    w_u16(object + 38u, r_u16(object + 38u) + rotation);
    result = sub_80030678(previous, object + 20u) << 16u;
    if (result != 0u)
        return (uint32)draft_scratch_result(mark, sub_8002289C(object));
    result = (uint32)(sint32)(sint16)r_u16(object + 8u);
    if ((sint32)result < 0)
        result = sub_8002289C(object);
    return (uint32)draft_scratch_result(mark, result);
}
