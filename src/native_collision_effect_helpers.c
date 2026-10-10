#include "native_call_dispatch.h"

uint32 sub_80062B3C(uint32 position, uint32 material, uint32 scale, uint32 count)
{
    sint32 remaining = (sint16)count;
    uint32 multiplier = (uint32)((sint32)scale >> 8), result;
    FUNCTION_MARKER(0x80062B3Cu, "1.EXE");
    /* TODO Nonpositive count preserves an unspecified incoming v0 */
    if (remaining <= 0)
        abort();
    do
    {
        uint32 effect = sub_800227C4(40u), x, y, z;
        w_u8(effect + 34u, 11u);
        w_u16(effect + 32u, material);
        w_u8(effect + 14u, r_u8(effect + 14u) | 2u);
        w_u32(effect + 20u, r_u32(position));
        result = r_u32(position + 4u);
        w_u32(effect + 24u, result);
        w_u16(effect + 18u, result);
        w_u16(effect + 36u, 200u);
        w_u32(effect + 28u, r_u32(position + 8u));
        w_u16(effect + 38u, sub_80069A50());
        w_u32(effect, 0x80062CA0u);
        x = (uint32)(sint32)(sint16)((sub_80069A50() & 255u) + 0xFF81u);
        y = (uint32)(sint32)(sint16)(0xFF01u - (sub_80069A50() & 127u));
        z = (uint32)(sint32)(sint16)((sub_80069A50() & 255u) + 0xFF81u);
        w_u16(effect + 8u, (uint32)((sint32)((x << 8) * multiplier) >> 16));
        w_u16(effect + 10u, (uint32)((sint32)((y << 8) * multiplier) >> 16));
        --remaining;
        w_u16(effect + 16u, (uint32)((sint32)((z << 8) * multiplier) >> 16));
        result = sub_80069A50() + 129u;
        w_u8(effect + 13u, result);
    } while (remaining > 0);
    return result;
}

uint32 sub_80054594(uint32 object)
{
    uint32 y = r_u32(object + 24u), step, angle;
    uint32 limit = r_u32(object + 60u) + (uint32)(sint32)(sint16)r_u16(object + 56u);
    FUNCTION_MARKER(0x80054594u, "1.EXE");
    if ((sint32)y >= (sint32)limit)
        return 1u;
    step = (uint32)((sint32)r_u32(0x800A63D8u) >> 8);
    w_u32(object + 24u, y + (uint32)((sint32)(step * 768u) >> 16));
    angle = r_u16(object + 58u) + (uint32)((sint32)(step * 3584u) >> 16);
    w_u16(object + 58u, angle);
    sub_80055168((uint32)((sint32)((uint32)r_u16(0x800102E0u + 2u * (angle & 4095u)) << 16) >> 20), object + 36u);
    sub_80031B20(object + 64u, object + 36u, object + 36u);
    return 0u;
}

static uint32 collision_effect_model(uint32 object)
{
    return r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
}

uint32 sub_800542C0(uint32 object, uint32 mode, uint32 count)
{
    uint32 result = sub_80069A50(), radius, index = 0u;
    FUNCTION_MARKER(0x800542C0u, "1.EXE");
    if (result % 5u != 0u)
        return result;
    result = r_u8(object + 12u) < 5u;
    if (result != 0u)
        return result;
    result = sub_80069A50();
    if (mode != 0u)
    {
        uint32 divisor = (uint32)(sint32)(sint16)r_u16(collision_effect_model(object) + 34u);
        if (divisor == 0u)
            abort();
        radius = (result % divisor) >> 1;
    }
    else
        radius = result % 100u;
    while ((sint32)index < (sint32)count)
    {
        uint32 effect = (uint32)draft_call_adapter(0x80022820u, 44u, object), angle, speed;
        sint32 product;
        result = 11u;
        if (effect == 0u)
            break;
        w_u8(effect + 34u, 11u);
        w_u16(effect + 38u, 0u);
        w_u16(effect + 36u, (sub_80069A50() & 15u) + 26u);
        w_u8(effect + 14u, r_u8(effect + 14u) | 0x42u);
        w_u32(effect, 0x8005414Cu);
        w_u16(effect + 32u, r_u16(r_u32(0x800A62ECu) + 112u));
        angle = (sub_80069A50() & 4095u) * 2u;
        product = (sint32)(radius * (uint32)(sint32)(sint16)r_u16(0x800102E0u + angle));
        w_u32(effect + 20u, r_u32(object + 20u) + (uint32)(product >> 12));
        product = (sint32)(radius * (uint32)(sint32)(sint16)r_u16(0x80010AE0u + angle));
        w_u32(effect + 28u, r_u32(object + 28u) + (uint32)(product >> 12));
        result = r_u32(object + 24u) + 100u;
        if (mode != 0u)
            result += (uint32)(sint32)(sint16)r_u16(collision_effect_model(object) + 32u);
        w_u32(effect + 24u, result);
        if ((sint32)result >= 0)
            w_u32(effect + 24u, 0xFFFFFFFFu);
        w_u16(effect + 40u, (uint32)((sint32)r_u32(effect + 20u) >> 4));
        w_u16(effect + 42u, (uint32)((sint32)r_u32(effect + 28u) >> 4));
        w_u8(effect + 16u, sub_80069A50() & 15u);
        if (r_u8(effect + 16u) == 0u)
            w_u8(effect + 16u, 1u);
        ++index;
        w_u8(effect + 13u, sub_80069A50() & 63u);
        result = sub_80069A50();
        speed = r_u8(effect + 16u);
        w_u8(effect + 35u, result & 127u);
        result = (sint32)index < (sint32)count;
        w_u32(effect + 16u, speed);
    }
    return result;
}

uint32 sub_800546D4(uint32 object)
{
    uint32 mark = draft_scratch_mark(), scratch = draft_scratch_adapter(8u), index;
    FUNCTION_MARKER(0x800546D4u, "1.EXE");
    for (index = 0u; index < 5u; ++index)
        xport_gte_write_control(index, r_u32(object + 36u + 4u * index));
    for (index = 0u; index < 3u; ++index)
        xport_gte_write_control(index + 5u, r_u32(object + 20u + 4u * index));
    for (index = 0u; index < 4u; ++index)
    {
        uint32 entry = object + 84u + 36u * index, word;
        w_u32(scratch, r_u32(0x800A5720u + 8u * index));
        w_u32(scratch + 4u, r_u32(0x800A5724u + 8u * index));
        sub_80031CC0(scratch, entry);
        for (word = 0u; word < 4u; ++word)
            w_u32(entry + 16u + 4u * word, r_u32(object + 36u + 4u * word));
        w_u16(entry + 32u, r_u16(object + 52u));
    }
    return (uint32)draft_scratch_result(mark, 0u);
}
