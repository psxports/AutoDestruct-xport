#include "draft_signatures.h"

/* FUNCTION_MARKER: sub_800375A4 */
uint32 sub_800375A4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800899C0u, 0u, 0xFFFFFFu)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800461BC */
uint32 sub_800461BC(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    return draft_scratch_result(native_stack_mark, (uint64)(sub_80046004(a1, 0u)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8004557C */
uint32 sub_8004557C(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 owner = (int16)r_u16(a5);
    uint32 result = a4 << 16;
    if ((owner != -1 && !r_u8(r_u32(r_u32(0x800A851Cu) + (uint32)owner * 4u) + 65u)) || (int8)r_u8(a1 + 66u) <= 0)
    {
        if (result)
            w_u8(a1 + 14u, r_u8(a1 + 14u) | 2u);
        w_u8(a1 + 64u, 1u);
        w_u16(a5, 0xFFFFu);
        w_u32(a1, a3);
        w_u8(a1 + 66u, 1u);
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80030F08u, (uint32)(int32)(int16)r_u16(a2), (uint32)(int32)(int16)r_u16(a1 + 68u), 0u)));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800469E8 */
uint32 sub_800469E8(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = sub_80045E18(a1, a1 + 72u);
    if (!result)
        return draft_scratch_result(native_stack_mark, (uint64)(sub_8004557C(a1, a1 + 72u, 0x800467A4u, 1u, a1 + 56u)));
    result = r_u8(a1 + 14u) | 2u;
    w_u8(a1 + 14u, (uint8)result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8002DFF8 */
uint32 sub_8002DFF8(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    if (a2 & 0x41u)
        w_u16(a1 + 80u, (uint16)(0u - (r_u16(a3 + 8u) << 4)));
    if (a2 & 0x208u)
        w_u16(a1 + 80u, (uint16)(0u - (r_u16(a3) << 4)));
    if (a2 & 0x104u)
        w_u16(a1 + 80u, (uint16)(r_u16(a3 + 8u) << 4));
    if (a2 & 0x820u)
        w_u16(a1 + 80u, (uint16)(r_u16(a3) << 4));
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8002ACCC(a1, a2 & 0xFFFFu, a3)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80063008 */
uint32 sub_80063008(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 dt = r_u32(0x800A9010u), result;
    w_u16(a1 + 8u, (uint16)(r_u16(a1 + 8u) - dt));
    w_u16(a1 + 36u, (uint16)(r_u16(a1 + 36u) + dt * 2u));
    w_u32(a1 + 24u, r_u32(a1 + 24u) - dt * (uint32)(int32)(int16)r_u16(a1 + 18u));
    result = r_u16(a1 + 38u) + dt * (uint32)(int32)(int16)r_u16(a1 + 10u);
    w_u16(a1 + 38u, (uint16)result);
    if ((int16)r_u16(a1 + 8u) < 0)
    {
        int32 index = (int16)r_u16(0x80091080u + (uint32)(int32)(int16)r_u16(a1 + 16u) * 2u);
        if (index < 0)
            return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(a1)));
        result = (uint32)(int32)(int16)r_u16(r_u32(0x800A62ECu) + (uint32)index * 2u);
        w_u16(a1 + 16u, r_u16(a1 + 16u) + 1u);
        w_u16(a1 + 32u, (uint16)result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800630DC */
uint32 sub_800630DC(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object = sub_800227C4(40u);
    w_u8(object + 34u, 11u);
    w_u32(object + 20u, r_u32(a1));
    w_u32(object + 24u, r_u32(a1 + 4u));
    w_u32(object + 28u, r_u32(a1 + 8u));
    w_u8(object + 14u, r_u8(object + 14u) | 2u);
    w_u16(object + 36u, 50u);
    w_u16(object + 32u, r_u16(r_u32(0x800A62ECu) + 88u));
    w_u16(object + 38u, (uint16)sub_80069A50());
    w_u32(object, 0x80063008u);
    w_u16(object + 8u, 16u);
    w_u8(object + 14u, r_u8(object + 14u) | 0x40u);
    w_u16(object + 10u, (uint16)((sub_80069A50() & 63u) - 31u));
    w_u16(object + 16u, 0u);
    w_u16(object + 18u, 4u);
    return draft_scratch_result(native_stack_mark, (uint64)(4u));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8005F1E0 */
uint32 sub_8005F1E0(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 dt = r_u32(0x800A9010u), result;
    w_u32(a1 + 20u, r_u32(a1 + 20u) + dt * (uint32)(int32)(int16)r_u16(a1 + 8u));
    w_u8(a1 + 13u, (uint8)(r_u8(a1 + 13u) - dt));
    w_u32(a1 + 24u, r_u32(a1 + 24u) + dt * (uint32)(int32)(int16)r_u16(a1 + 10u));
    w_u32(a1 + 28u, r_u32(a1 + 28u) + dt * (uint32)(int32)(int16)r_u16(a1 + 16u));
    result = r_u16(a1 + 38u) + dt * (uint32)(int32)(int16)r_u16(a1 + 18u);
    w_u16(a1 + 38u, (uint16)result);
    if ((int8)r_u8(a1 + 13u) < 0)
    {
        w_u8(a1 + 13u, (uint8)(sub_80069A50() & 7u));
        w_u32(a1, 0x8005F2D8u);
        w_u16(a1 + 8u, (uint16)((int16)r_u16(a1 + 8u) >> 2));
        w_u16(a1 + 10u, (uint16)((int16)r_u16(a1 + 10u) >> 2));
        result = (uint32)((int16)r_u16(a1 + 16u) >> 2);
        w_u16(a1 + 16u, (uint16)result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8005612C */
uint32 sub_8005612C(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 base = r_u32(0x800A84FCu), first = r_u32(base + a2 * 8u), second = r_u32(base + a3 * 8u);
    uint32 lateral = 500u * r_u32(0x800A6224u), angle = sub_80055A9C((second & 1023u) - (first & 1023u), ((second >> 10) & 1023u) - ((first >> 10) & 1023u)) & 4095u;
    uint32 sine = (uint32)(int32)(int16)r_u16(0x800102E0u + angle * 2u), cosine = (uint32)(int32)(int16)r_u16(0x80010AE0u + angle * 2u), result;
    w_u16(a1 + 76u, (uint16)angle);
    first = r_u32(r_u32(0x800A84FCu) + a2 * 8u);
    w_u32(a1 + 68u, ((first & 1023u) << 9) + (uint32)((int32)(900u * sine + lateral * cosine) >> 12));
    result = (((first >> 10) & 1023u) << 9) + (uint32)((int32)(900u * cosine - lateral * sine) >> 12);
    w_u32(a1 + 72u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80066984 */
uint32 sub_80066984(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object = (uint32)draft_call_adapter(0x800226E4u, 84u), packed = r_u32(a1), i;
    w_u32(object + 20u, a2 + (packed & 4095u));
    w_u32(object + 28u, a3 + ((packed >> 12) & 4095u));
    w_u32(object + 24u, 0u - r_u16(a1 + 4u));
    w_u8(object + 14u, r_u8(object + 14u) | 2u);
    w_u8(object + 34u, 17u);
    w_u32(object, 0x80066AECu);
    w_u16(object + 32u, r_u16(r_u32(0x800A8FD8u) + r_u8(a1 + 11u) * 2u));
    w_u8(object + 14u, r_u8(object + 14u) | 0x20u);
    draft_call_adapter(0x800551CCu, (r_u32(a1 + 4u) >> 14) & 0xF80u, object + 36u);
    w_u32(object + 8u, a1);
    w_u32(object + 16u, 0x800910B4u);
    w_u16(object + 60u, 0u);
    w_u16(object + 54u, (uint16)(((int32)r_u32(object + 20u) >> 12) + 80 * ((int32)r_u32(object + 28u) >> 12)));
    for (i = 0; i < 6u; ++i)
    {
        static const uint32 offsets[6] = {64u, 68u, 70u, 72u, 76u, 78u};
        w_u16(object + offsets[i], 0u);
    }
    w_u16(object + 62u, (uint16)((r_u32(a1 + 4u) >> 14) & 0xF80u));
    if (r_u32(0x800A9A38u) == 4u)
        w_u16(object + 80u, 0u);
    w_u16(object + 80u, 3u);
    w_u16(object + 56u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(object));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8002AF4C */
uint32 sub_8002AF4C(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    static const uint32 zmask[4] = {0x11u, 0x12u, 0x44u, 0x48u};
    static const uint32 xmask[4] = {0x81u, 0x22u, 0x24u, 0x88u};
    uint32 i, result = 136u;
    for (i = 0; i < 4u; ++i)
    {
        uint32 entry = a1 + i * 16u, delta, value;
        if ((a2 & zmask[i]) == zmask[i] && !(r_u32(entry + 8u) & 0xF0000u))
            delta = r_u32(a3 + 8u);
        else if ((a2 & xmask[i]) == xmask[i])
        {
            result = r_u32(entry + 8u) & 0xF0000u;
            if (result)
                continue;
            delta = r_u32(a3);
        }
        else
        {
            if (i == 3u)
                result = 136u;
            continue;
        }
        value = r_u32(entry + 12u);
        result = ((uint32)((int32)(value << 4) >> 4) - (delta << 16)) & 0xFFFFFFFu;
        w_u32(entry + 12u, (value & 0xF0000000u) | result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80023918 */
uint32 sub_80023918(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 bearing, delta, index, magnitude, sine, cosine, scale, result;
    int32 difference;
    w_u32(a3, 0u - r_u32(a3));
    w_u32(a4, 0u - r_u32(a4));
    bearing = sub_80055A9C(a1, a2);
    delta = (bearing - sub_80055A9C((uint32)((int32)r_u32(a3) >> 8), (uint32)((int32)r_u32(a4) >> 8))) & 4095u;
    difference = (int32)delta;
    if (delta >= 2049u)
        difference -= 4096;
    if (difference < 0)
        difference = (int32)(0u - (uint32)difference);
    w_u32(0x800A56A8u, (uint32)difference * 24u + 0x4000u);
    if (delta - 1025u >= 2047u)
    {
        index = (bearing + delta) & 4095u;
        magnitude = (uint32)((int32)sub_80069BE0(r_u32(a3), r_u32(a4)) >> 8);
        sine = (uint32)((int16)r_u16(0x800102E0u + index * 2u) >> 4);
        cosine = (uint32)((int16)r_u16(0x80010AE0u + index * 2u) >> 4);
        scale = (uint32)((int32)r_u32(0x800A56A8u) >> 8);
        w_u32(a3, 0u - (uint32)((int32)(magnitude * sine) >> 8) * scale);
        w_u32(a4, 0u - (uint32)((int32)(magnitude * cosine) >> 8) * scale);
    }
    w_u32(a3, 0u - r_u32(a3));
    result = 0u - r_u32(a4);
    w_u32(a4, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8002A38C */
uint32 sub_8002A38C(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 x = r_u32(a1), z = r_u32(a1 + 8u), tx = r_u32(a2), tz = r_u32(a2 + 8u), slopeX = 0u, slopeZ = 0u;
    uint32 scratch = draft_scratch_adapter(12u), result = 0u, i;
    if (tx != x)
        slopeX = (uint32)((int64)(int32)((z - tz) << 10) / (int32)(tx - x));
    if (tz != z)
        slopeZ = (uint32)((int64)(int32)((tx - x) << 10) / (int32)(tz - z));
    for (i = 0; i < 4u; ++i)
    {
        uint32 next = (i + 1u) & 3u;
        uint32 hit = sub_8002F7E0(x, z, a2, (uint32)(int32)(int16)r_u16(a3 + i * 8u), (uint32)(int32)(int16)r_u16(a3 + i * 8u + 4u), (uint32)(int32)(int16)r_u16(a3 + next * 8u), (uint32)(int32)(int16)r_u16(a3 + next * 8u + 4u), scratch, slopeX, slopeZ);
        if (i == 0u || (hit << 16))
        {
            if (i == 0u)
                result = hit;
            else
                result = hit << (i * 3u);
        }
    }
    result = (uint32)(int32)(int16)result;
    if (result)
    {
        w_u32(a1, r_u32(scratch));
        w_u32(a1 + 8u, r_u32(scratch + 8u));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8005780C */
uint32 sub_8005780C(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(12u), result;
    w_u32(a1, 0x80056AA8u);
    w_u32(a1 + 16u, 0x80090B6Cu);
    w_u16(a1 + 56u, (uint16)a2);
    w_u16(a1 + 78u, (uint16)a3);
    w_u16(a1 + 10u, 0u);
    w_u32(a1 + 80u, sub_80069BE0(r_u32(a1 + 68u) - r_u32(a1 + 20u), r_u32(a1 + 72u) - r_u32(a1 + 28u)));
    w_u8(a1 + 91u, r_u8(a1 + 91u) | 0x80u);
    w_u32(scratch, r_u32(a1 + 68u));
    w_u32(scratch + 4u, r_u32(a1 + 24u));
    w_u32(scratch + 8u, r_u32(a1 + 72u));
    if (r_u8(a1 + 90u) != 7u)
    {
        result = sub_8002EAE4(a1 + 20u, scratch, 0u);
        if ((result << 16) && (int16)r_u16(a1 + 58u) > 0)
            return draft_scratch_result(native_stack_mark, (uint64)((uint32)(int32)(int16)r_u16(a1 + 58u)));
        draft_call_adapter(0x8005792Cu, a1);
        w_u8(a1 + 90u, 8u);
    }
    result = (sub_80069A50() % 30u + 30u) * r_u32(0x800A56C0u);
    w_u32(a1 + 80u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8006AFF4 */
uint32 sub_8006AFF4(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(12u), target, distance, targetY, objectY, rise, localRise, result;
    int32 span, difference, targetSlope, localSlope;
    w_u32(scratch, r_u32(0x800A6400u));
    w_u32(scratch + 4u, r_u32(0x800A6404u));
    w_u32(scratch + 8u, r_u32(0x800A6408u));
    sub_80031EA8(a1 + 36u, a1 + 20u, scratch);
    target = r_u32(a1 + 88u);
    distance = sub_80069BE0(r_u32(target + 20u) - r_u32(a1 + 20u), r_u32(target + 28u) - r_u32(a1 + 28u));
    span = (int32)(distance * 2u) / 3;
    targetY = r_u32(target + 24u);
    objectY = r_u32(a1 + 24u);
    difference = (int32)(targetY - objectY);
    if (difference < 0)
        difference = (int32)(objectY - targetY);
    if (span < (int32)((uint32)difference * 2u))
        span = (int32)((uint32)difference * 2u);
    localRise = (r_u32(scratch + 4u) - objectY) << 10;
    rise = (targetY - objectY) << 10;
    targetSlope = (int32)((int64)(int32)rise / span);
    localSlope = (int32)localRise / 200;
    if (localSlope < targetSlope)
    {
        w_u32(a1 + 120u, r_u32(scratch + 4u) << 10);
        w_u32(a1 + 116u, 200u);
        w_u32(a1 + 112u, (uint32)localSlope);
    }
    else
    {
        w_u32(a1 + 120u, targetY << 10);
        w_u32(a1 + 116u, (uint32)span);
        w_u32(a1 + 112u, (uint32)targetSlope);
    }
    w_u32(a1 + 108u, r_u32(a1 + 24u) << 10);
    w_u16(a1 + 128u, r_u16(a1 + 116u));
    if ((int32)r_u32(a1 + 120u) < (int32)r_u32(a1 + 108u))
    {
        result = 1u;
        w_u16(a1 + 124u, 1u);
    }
    else
    {
        result = 0xFFFFFFFFu;
        w_u16(a1 + 124u, r_u32(a1 + 120u) == r_u32(a1 + 108u) ? 0u : 0xFFFFu);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8002C9D4 */
uint32 sub_8002C9D4(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch, result;
    int32 dx = (int32)(r_u32(a2 + 20u) - r_u32(a1 + 20u)), dz = (int32)(r_u32(a2 + 28u) - r_u32(a1 + 28u)), dy = (int32)(r_u32(a2 + 24u) - r_u32(a1 + 24u));
    if (dx < 0)
        dx = (int32)(0u - (uint32)dx);
    if (dz < 0)
        dz = (int32)(0u - (uint32)dz);
    if (dy < 0)
        dy = (int32)(0u - (uint32)dy);
    if (dx >= 220 || dz >= 220 || dy >= 300)
    {
        result = (uint32)(int32)(int16)r_u16(a2 + 58u);
        if ((int32)result < 0)
        {
            result = sub_80069BE0(r_u32(a1 + 20u) - r_u32(a2 + 20u), r_u32(a1 + 28u) - r_u32(a2 + 28u)) < 600u;
            if (result)
            {
                result = sub_80055A9C(r_u32(a1 + 20u) - r_u32(a2 + 20u), r_u32(a1 + 28u) - r_u32(a2 + 28u)) + 2048u;
                w_u16(a2 + 56u, 128u);
                w_u16(a2 + 446u, (uint16)result);
            }
        }
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    scratch = draft_scratch_adapter(12u);
    w_u16(a2 + 56u, 255u);
    draft_call_adapter(r_u32(r_u32(a1 + 16u) + 4u), a1, scratch);
    draft_call_adapter(r_u32(r_u32(a2 + 16u) + 24u), a2, scratch);
    result = (uint32)(int32)(int16)r_u16(a2 + 58u);
    if ((int32)result > 0)
    {
        uint32 health = r_u16(a2 + 58u) - (sub_80069BE0(r_u32(scratch), r_u32(scratch + 8u)) >> 16);
        w_u16(a2 + 58u, (uint16)health);
        if ((int16)r_u16(a2 + 70u) == 1)
        {
            w_u16(0x800A930Eu, (uint16)health);
            w_u16(0x800A930Cu, r_u16(a2 + 166u));
            w_u16(0x800A9310u, r_u8(a2 + 176u));
        }
        result = (uint32)(int32)(int16)r_u16(a2 + 58u);
        if ((int32)result < 0)
        {
            w_u16(a2 + 58u, 0u);
            w_u16(0x800A9310u, 0u);
            w_u16(0x800A930Eu, 0u);
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8003B990 */
uint32 sub_8003B990(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(24u), i;
    int32 number = (int16)(a1 + 50u), tens = number / 10;
    for (i = 0; i < 24u; ++i)
        w_u8(scratch + i, r_u8(0x800A5D58u + i));
    w_u8(scratch + 10u, (uint8)(r_u32(0x800A8FD4u) + 48u));
    w_u8(scratch + 12u, (uint8)(tens + 48));
    w_u8(scratch + 14u, (uint8)(tens + 48));
    w_u8(scratch + 15u, (uint8)(number % 10 + 48));
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)(int32)(int16)sub_8005A54C(scratch)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80071148 */
void sub_80071148(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 buttons = (uint32)draft_call_adapter(0x800389DCu), entry = r_u32(0x80091EE0u + r_u32(0x800A645Cu) * 12u) + a1 * 16u;
    int32 value = (int16)r_u16(entry + 14u);
    uint32 kind;
    if (buttons & 0x8000u)
        value -= 2;
    if (buttons & 0x2000u)
        value += 2;
    value = (int32)sub_80071960((uint32)value, 64u);
    entry = r_u32(0x80091EE0u + r_u32(0x800A645Cu) * 12u) + a1 * 16u;
    w_u16(entry + 14u, (uint16)value);
    kind = r_u32(entry);
    if (kind == 128u)
    {
        w_u32(0x800A9CD0u, (uint32)value << 9);
        draft_call_adapter(0x80036EDCu, (uint32)(int32)(int16)((uint32)value << 9));
    }
    else if (kind == 129u)
    {
        w_u16(0x800A9D6Cu, (uint16)((uint32)value << 8));
        draft_call_adapter(0x80036E9Cu, (uint32)(int32)(int16)((uint32)value << 8));
    }
    else
    {
        w_u32(0x800A975Cu, (uint32)value << 9);
        if (!r_u16(0x800A9A64u))
            draft_call_adapter(0x80036EDCu, (uint32)(int32)(int16)((uint32)value << 9));
    }

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800717A8 */
uint32 sub_800717A8(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(2u), taps, held, old = r_u32(a4), selected = old, code = r_u8(a2 + old), result;
    w_u8(scratch, r_u8(0x800A647Cu));
    w_u8(scratch + 1u, r_u8(0x800A647Du));
    taps = (uint32)draft_call_adapter(0x80038970u, 0xFFFF8000u);
    taps |= (uint32)draft_call_adapter(0x80038970u, 0x2000u);
    held = (uint32)draft_call_adapter(0x800389DCu);
    if (held & 0x5000u)
    {
        if (held & 0x4000u)
            ++code;
        if (held & 0x1000u)
            --code;
        code &= 63u;
        w_u8(a1 + old, r_u8(0x800A5B78u + (code >> 1)));
        if ((code >> 1) != (r_u8(a2 + old) >> 1))
            draft_call_adapter(0x80035A08u, 36u, 2048u, 192u, 0u, 0u);
        w_u8(a2 + old, (uint8)code);
    }
    else
    {
        if (taps & 0x2000u)
            ++selected;
        if (taps & 0x8000u)
            --selected;
        selected = sub_80071960(selected, a3);
        if (selected != old)
            draft_call_adapter(0x80035A08u, 29u, 2048u, 255u, 0u, 0u);
    }
    w_u8(scratch, r_u8(a1 + old));
    result = sub_80043820(scratch, 0x7F7F7Fu, old * 15u + 125u, 87u, 99u, 1u);
    w_u32(a4, selected);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800714A4 */
void sub_800714A4(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 menu = r_u32(0x800A645Cu), entry, buttons, state, timer;
    buttons = (uint32)draft_call_adapter(0x80038970u, 64u);
    buttons |= (uint32)draft_call_adapter(0x80038970u, 16u);
    entry = r_u32(0x80091EE0u + r_u32(0x800A645Cu) * 12u) + a1 * 16u;
    if (buttons & 16u)
    {
        w_u16(entry + 14u, 0u);
        sub_800703B4();
        {
            draft_scratch_release(native_stack_mark);
            return;
        }
    }
    state = r_u16(entry + 14u) & 255u;
    timer = r_u16(entry + 14u) >> 8;
    sub_80070D6C(95u, 70u, 186u, 50u, 101u);
    switch (state)
    {
        case 0u:
            if (r_u32(0x800A7F0Cu) != 6u)
            {
                timer = 0u;
                state = 1u;
            }
            break;
        case 1u:
            sub_800717A8(0x8009206Cu, 0x80092078u, 8u, 0x800A6478u);
            if (buttons & 64u)
            {
                timer = 0u;
                state = draft_call_adapter(0x80032388u, 0x8009206Cu) ? 3u : 2u;
            }
            break;
        case 2u:
        case 3u:
            sub_80043820(sub_8006F554(r_u32(0x800A8D44u), state == 3u), 0x7F7F7Fu, 125u, 100u, 100u, 0u);
            timer += r_u32(0x800A9010u);
            if ((int32)timer >= 64)
                state = state == 2u ? 4u : 5u;
            break;
        case 4u:
            w_u32(0x800A7F0Cu, 6u);
            w_u16(entry + 14u, 0u);
            sub_8007040C();
            {
                draft_scratch_release(native_stack_mark);
                return;
            }
        case 5u:
            w_u16(entry + 14u, 0u);
            sub_800703B4();
            {
                draft_scratch_release(native_stack_mark);
                return;
            }
        default:
            break;
    }
    sub_80043820(0x8009206Cu, 5197647u, 125u, 87u, 100u, 1u);
    if (menu == r_u32(0x800A645Cu))
        w_u16(r_u32(0x80091EE0u + menu * 12u) + a1 * 16u + 14u, (uint16)((timer << 8) | state));

    draft_scratch_release(native_stack_mark);
}

static uint32 draft_round2_matrix_element(uint32 matrix, uint32 row, uint32 column)
{
    return (uint32)(int32)(int16)r_u16(matrix + row * 6u + column * 2u);
}

/* FUNCTION_MARKER: sub_8005536C */
uint32 sub_8005536C(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 invert = (a2 >> 2) & 1u, first = r_u8(0x800A61D8u + ((a2 >> 3) & 3u)), second = r_u8(0x800A61E0u + first + invert), third = r_u8(0x800A61E0u + first + 1u - invert);
    uint32 n, d, cosine, result, x, y;
    int32 length;
    if (a2 & 2u)
    {
        n = draft_round2_matrix_element(a1, first, third);
        d = draft_round2_matrix_element(a1, first, second);
        cosine = (uint32)(int32)(int16)r_u16(0x80010AE0u + (sub_80055A9C(n, d) & 4095u) * 2u);
        length = cosine ? (int32)((int64)(int32)(d << 12) / (int32)cosine) : (int32)n;
        if (length > 0)
        {
            w_u16(a3, (uint16)sub_80055A9C(draft_round2_matrix_element(a1, first, second), draft_round2_matrix_element(a1, first, third)));
            w_u16(a3 + 2u, (uint16)sub_80055A9C((uint32)length, draft_round2_matrix_element(a1, first, first)));
            x = draft_round2_matrix_element(a1, second, first);
            y = 0u - draft_round2_matrix_element(a1, third, first);
            result = sub_80055A9C(x, y);
            w_u16(a3 + 4u, (uint16)result);
        }
        else
        {
            w_u16(a3, (uint16)sub_80055A9C(0u - draft_round2_matrix_element(a1, second, third), draft_round2_matrix_element(a1, second, second)));
            result = sub_80055A9C((uint32)length, draft_round2_matrix_element(a1, first, first));
            w_u16(a3 + 2u, (uint16)result);
            w_u16(a3 + 4u, 0u);
        }
    }
    else
    {
        n = draft_round2_matrix_element(a1, second, first);
        d = draft_round2_matrix_element(a1, first, first);
        cosine = (uint32)(int32)(int16)r_u16(0x80010AE0u + (sub_80055A9C(n, d) & 4095u) * 2u);
        length = cosine ? (int32)((int64)(int32)(d << 12) / (int32)cosine) : (int32)n;
        if (length > 0)
        {
            w_u16(a3, (uint16)sub_80055A9C(draft_round2_matrix_element(a1, third, second), draft_round2_matrix_element(a1, third, third)));
            w_u16(a3 + 2u, (uint16)sub_80055A9C(0u - draft_round2_matrix_element(a1, third, first), (uint32)length));
            result = sub_80055A9C(draft_round2_matrix_element(a1, second, first), draft_round2_matrix_element(a1, first, first));
            w_u16(a3 + 4u, (uint16)result);
        }
        else
        {
            w_u16(a3, (uint16)sub_80055A9C(0u - draft_round2_matrix_element(a1, second, third), draft_round2_matrix_element(a1, second, second)));
            result = sub_80055A9C(0u - draft_round2_matrix_element(a1, third, first), (uint32)length);
            w_u16(a3 + 2u, (uint16)result);
            w_u16(a3 + 4u, 0u);
        }
    }
    if (invert)
    {
        w_u16(a3, (uint16)(0u - r_u16(a3)));
        w_u16(a3 + 4u, (uint16)(0u - r_u16(a3 + 4u)));
        result = 0u - r_u16(a3 + 2u);
        w_u16(a3 + 2u, (uint16)result);
    }
    if (a2 & 1u)
    {
        uint16 value = r_u16(a3);
        result = r_u16(a3 + 4u);
        w_u16(a3, (uint16)result);
        w_u16(a3 + 4u, value);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80034868 */
uint32 sub_80034868(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object, follower, mode, rejected = 0u;
    if (r_u32(0x800A8E70u) == 1u)
        sub_80033E90();
    if (!r_u16(0x800A6D10u))
    {
        if ((int32)r_u32(0x800A9A34u) >= 40 && !r_u32(0x800A8E70u))
        {
            sub_80034820(2u, r_u32(r_u32(0x800A851Cu)) + 20u);
            goto record;
        }
        object = r_u32(r_u32(0x800A851Cu) + (uint32)(int32)(int16)r_u16(a1) * 4u);
        follower = r_u32(r_u32(0x800A851Cu) + (uint32)(int32)(int16)r_u16(r_u32(a1 + 8u)) * 4u);
        if (!r_u8(object + 17u))
        {
            uint32 flags = r_u8(follower + 14u), type = r_u8(follower + 13u) & 15u;
            rejected = !(flags & 8u) || (!(flags & 2u) && type != 5u && type != 13u);
        }
        if (rejected)
        {
            if (!r_u32(0x800A84D4u))
            {
                if (r_u32(0x800A8E70u) == 1u)
                    sub_80034820((uint32)(int32)(int16)r_u16(object + 6u) - 1u, r_u32(r_u32(0x800A851Cu)) + 20u);
                if (!r_u32(0x800A84D4u) && !r_u32(0x800A8E70u))
                    draft_call_adapter(0x8005CBC8u, 2u, r_u32(r_u32(0x800A851Cu)) + 20u);
            }
        }
        else
        {
            if (!r_u32(0x800A84D4u) && r_u32(0x800A8E70u) == 1u)
                sub_80034820((uint32)(int32)(int16)r_u16(object + 6u) - 1u, follower + 20u);
            if (!r_u32(0x800A84D4u) && !r_u32(0x800A8E70u))
                draft_call_adapter(0x8005CBC8u, 2u, follower + 20u);
        }
        mode = r_u32(0x800A84D4u);
        if (mode == 1u)
        {
            if (r_u32(0x800A9A38u) != 4u)
                sub_80034820(2u, rejected ? r_u32(r_u32(0x800A851Cu)) + 20u : follower + 20u);
            if (mode == r_u32(0x800A84D4u) && r_u32(0x800A9A38u) == 4u)
                sub_80034820(2u, r_u32(r_u32(0x800A851Cu)) + 20u);
        }
    record:
        w_u32(0x800A9020u, a1);
    }
    if (!r_u16(0x800A6D00u))
    {
        if (r_u32(0x800A8E70u) == 1u)
        {
            w_u16(0x800A7E7Au, 10000u);
            object = r_u32(r_u32(0x800A851Cu) + (uint32)(int32)(int16)r_u16(a1) * 4u);
            draft_call_adapter(0x8005E258u, (uint32)(int32)(int16)r_u16(object + 6u));
            sub_8005CB7C();
        }
        else
            draft_call_adapter(0x8005CC08u, r_u32(0x800A9A58u) + 20u);
        w_u16(0x800A6D00u, 1u);
    }
    if (r_u32(0x800A8690u) == 2u)
    {
        object = r_u32(r_u32(0x800A851Cu) + (uint32)(int32)(int16)r_u16(r_u32(a1 + 8u)) * 4u);
        w_u32(0x800A622Cu, object);
        w_u32(0x800A9A58u, object);
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8005BF3Cu, object)));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(2u));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8006C094 */
uint32 sub_8006C094(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8, uint32 a9, uint32 a10)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object = (uint32)draft_call_adapter(0x800226E4u, 132u), scratch = draft_scratch_adapter(24u), i, pitch, heading;
    w_u8(object + 34u, 8u);
    if ((int16)a7)
        draft_call_adapter(r_u32(r_u32(a1 + 16u) + 32u), a1, (uint32)(int32)(int16)a7, (uint32)(int32)(int16)a8);
    if ((int16)a9)
        draft_call_adapter(r_u32(r_u32(a1 + 16u) + 36u), a1, (uint32)(int32)(int16)a9, (uint32)(int32)(int16)a10);
    draft_call_adapter(r_u32(r_u32(a1 + 16u) + 20u), a1, scratch);
    draft_call_adapter(0x80054D38u, (uint32)(int32)(int16)r_u16(scratch), (uint32)(int32)(int16)r_u16(scratch + 2u), (uint32)(int32)(int16)r_u16(scratch + 4u), object + 36u);
    for (i = 0; i < 5u; ++i)
        xport_gte_write_control(i, r_u32(object + 36u + i * 4u));
    xport_gte_write_data(0u, r_u32(a2));
    xport_gte_write_data(1u, r_u32(a2 + 4u));
    draft_gte_command_adapter(0x486012u);
    for (i = 0; i < 3u; ++i)
        w_u32(object + 20u + i * 4u, r_u32(a1 + 20u + i * 4u) + xport_gte_read_data(25u + i));
    pitch = (a5 + r_u16(scratch)) & 4095u;
    heading = (a4 + r_u16(scratch + 2u) + 2048u) & 4095u;
    w_u32(object + 60u, (uint32)((int32)(a3 * (uint32)(int32)(int16)r_u16(0x800102E0u + heading * 2u) + 2048u) >> 12));
    w_u32(object + 68u, (uint32)((int32)(a3 * (uint32)(int32)(int16)r_u16(0x80010AE0u + heading * 2u) + 2048u) >> 12));
    w_u32(object + 64u, (uint32)((int32)(a3 * (uint32)(int32)(int16)r_u16(0x800102E0u + pitch * 2u) + 2048u) >> 12));
    if (a6)
    {
        draft_call_adapter(r_u32(r_u32(a1 + 16u) + 4u), a1, scratch + 12u);
        for (i = 0; i < 3u; ++i)
            w_u32(object + 60u + i * 4u, r_u32(object + 60u + i * 4u) + (uint32)((int32)(r_u32(scratch + 12u + i * 4u) + 32u) >> 6));
    }
    w_u16(object + 56u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(object));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8006A948 */
uint32 sub_8006A948(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(36u), vector = scratch + 12u, normal = scratch + 20u, extra = scratch + 28u, result;
    int32 speed = (int32)(a2 * 10u), offset = (int32)((uint32)(int32)(int16)r_u16(a1 + 80u) << 10), terrain, savedY = (int32)r_u32(a1 + 24u), candidate, current;
    w_u32(vector, r_u32(0x800A63ECu));
    w_u32(vector + 4u, r_u32(0x800A63F0u));
    terrain = (int32)(0u - (uint32)draft_call_adapter(0x8002E310u, a1 + 20u, normal, extra) * 1024u);
    w_u32(a1 + 24u, (uint32)savedY - 1360u);
    if ((int32)r_u32(a1 + 108u) >= (int32)(0u - (uint32)draft_call_adapter(0x8002E310u, a1 + 20u, normal, extra) * 1024u) && speed >= 401)
        speed = 400;
    if ((int32)(r_u16(a1 + 128u) + 100u) < speed)
        speed = (int32)(r_u16(a1 + 128u) + 100u);
    if (speed < (int32)a2)
        speed = (int32)a2;
    if (speed < 400)
        speed = 400;
    w_u32(a1 + 24u, (uint32)savedY);
    w_u16(vector + 4u, (uint16)(0u - (uint32)speed));
    draft_call_adapter(0x80031CE8u, a1 + 36u, a1 + 20u, vector, scratch);
    w_u32(scratch + 4u, (uint32)((int32)(r_u32(a1 + 120u) + 512u) >> 10));
    candidate = (int32)((uint32)offset - ((uint32)draft_call_adapter(0x8002E310u, scratch, normal, extra) << 10));
    current = (int32)r_u32(a1 + 120u);
    if (candidate == offset)
    {
        result = (int32)a2 < (int32)r_u32(a1 + 116u);
        if (!result)
            w_u32(a1 + 116u, (uint32)speed);
    }
    else if (candidate < current && (int32)(current - (uint32)candidate) < (int32)((uint32)speed << 10))
    {
        w_u32(a1 + 120u, (uint32)candidate);
        w_u16(a1 + 124u, 1u);
        result = (uint32)((int32)((uint32)speed * 4u) / 5);
        w_u32(a1 + 116u, result);
    }
    else if (current < candidate && ((int16)r_u16(a1 + 124u) < 0 || current < (int32)((uint32)terrain + (uint32)offset)))
    {
        w_u32(a1 + 116u, (uint32)((int32)((uint32)speed * 3u) / 2));
        w_u32(a1 + 120u, (uint32)candidate);
        w_u16(a1 + 124u, 0xFFFFu);
        result = 0xFFFFFFFFu;
    }
    else
    {
        result = (int32)a2 < (int32)r_u32(a1 + 116u);
        if (!result)
        {
            w_u32(a1 + 116u, (uint32)speed);
            w_u16(a1 + 124u, 0u);
        }
        else
        {
            result = (uint32)speed * 2u;
            if ((int32)r_u32(a1 + 108u) < (int32)(r_u32(a1 + 120u) - (uint32)offset))
            {
                result = (uint32)((int32)((uint32)speed * 3u) / 2);
                w_u32(a1 + 116u, result);
            }
        }
    }
    w_u16(a1 + 128u, (uint16)speed);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8006ABE8 */
uint32 sub_8006ABE8(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(36u), vector = scratch + 12u, normal = scratch + 20u, extra = scratch + 28u, target = r_u32(a1 + 88u), result;
    int32 offset = (int32)((uint32)(int32)(int16)r_u16(a1 + 80u) << 10), speed = (int32)(a2 * 10u), maximum, savedY = (int32)r_u32(a1 + 24u), candidate, ground, current, difference;
    w_u32(vector, r_u32(0x800A63ECu));
    w_u32(vector + 4u, r_u32(0x800A63F0u));
    maximum = (int32)((sub_80069BE0(r_u32(target + 20u) - r_u32(a1 + 20u), r_u32(target + 28u) - r_u32(a1 + 28u)) * 2u) / 3u);
    w_u32(a1 + 24u, (uint32)savedY - 1360u);
    if ((int32)r_u32(a1 + 108u) >= (int32)(0u - (uint32)draft_call_adapter(0x8002E310u, a1 + 20u, normal, extra) * 1024u))
        maximum = 400;
    if ((int32)(r_u16(a1 + 128u) + 100u) < speed)
        speed = (int32)(r_u16(a1 + 128u) + 100u);
    if (speed < (int32)a2)
        speed = (int32)a2;
    if (speed < 400)
        speed = 400;
    if (maximum < speed)
        speed = maximum;
    w_u32(a1 + 24u, (uint32)savedY);
    w_u16(vector + 4u, (uint16)(0u - (uint32)speed));
    draft_call_adapter(0x80031CE8u, a1 + 36u, a1 + 20u, vector, scratch);
    current = (int32)(r_u32(a1 + 120u) + 512u) >> 10;
    if ((int32)r_u32(target + 24u) < current)
        current = (int32)r_u32(target + 24u);
    w_u32(scratch + 4u, (uint32)current);
    candidate = (int32)((uint32)offset - ((uint32)draft_call_adapter(0x8002E310u, scratch, normal, extra) << 10));
    ground = (int32)((uint32)offset - ((uint32)draft_call_adapter(0x8002E310u, a1 + 20u, normal, extra) << 10));
    current = (int32)(r_u32(target + 24u) << 10);
    if (current < candidate)
        candidate = (int32)((uint32)current + 10u);
    current = (int32)r_u32(a1 + 120u);
    if (candidate == offset)
        w_u32(a1 + 116u, (uint32)speed);
    else if (candidate < current)
    {
        w_u32(a1 + 120u, (uint32)candidate);
        w_u16(a1 + 124u, 1u);
        w_u32(a1 + 116u, (uint32)((int32)((uint32)speed * 4u) / 5));
    }
    else if (current < candidate && ((int16)r_u16(a1 + 124u) < 0 || current < ground))
    {
        w_u32(a1 + 120u, (uint32)candidate);
        w_u16(a1 + 124u, 0xFFFFu);
        w_u32(a1 + 116u, (uint32)((int32)((uint32)speed * 4u) / 5));
    }
    else if ((int32)a2 >= (int32)r_u32(a1 + 116u))
    {
        w_u32(a1 + 116u, (uint32)speed);
        w_u16(a1 + 124u, 0u);
    }
    else if ((int32)r_u32(a1 + 108u) < (int32)(r_u32(a1 + 120u) - (uint32)offset))
        w_u32(a1 + 116u, (uint32)((int32)((uint32)speed * 3u) / 2));
    difference = (int32)(r_u32(a1 + 120u) - r_u32(a1 + 108u));
    if (difference < 0)
        difference = (int32)(0u - (uint32)difference);
    maximum = (int32)((uint32)difference * 2u + 512u) >> 10;
    result = (int32)r_u32(a1 + 116u) < maximum;
    if (result)
        w_u32(a1 + 116u, (uint32)maximum);
    w_u16(a1 + 128u, (uint16)speed);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8005D8D4 */
uint32 sub_8005D8D4(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(68u), vector = scratch, output = scratch + 8u, position = scratch + 20u, matrix = scratch + 36u;
    uint32 saved[3] = {r_u32(0x800A7EE4u), r_u32(0x800A7EE8u), r_u32(0x800A7EECu)}, object = r_u32(0x800A9A58u), angle, result, i;
    angle = (uint32)draft_call_adapter(r_u32(r_u32(object + 16u) + 12u), object) + 2048u;
    if (((int32)draft_call_adapter(r_u32(r_u32(object + 16u)), object) >> 16) < 2)
        angle = a1;
    draft_call_adapter(0x800551CCu, (uint32)(int32)(int16)angle, matrix);
    sub_8005D7C8(vector);
    draft_call_adapter(0x80031CE8u, matrix, object + 20u, vector, position);
    for (i = 0; i < 3u; ++i)
        w_u32(position + i * 4u, r_u32(object + 20u + i * 4u));
    result = sub_8005D6CC(position, output);
    if (!result)
    {
        sub_8005D7C8(vector);
        w_u16(vector, (uint16)(0u - r_u16(vector)));
        draft_call_adapter(0x80031CE8u, matrix, object + 20u, vector, position);
        for (i = 0; i < 3u; ++i)
            w_u32(position + i * 4u, r_u32(object + 20u + i * 4u));
        result = sub_8005D6CC(position, output);
    }
    if (result)
    {
        w_u32(0x800A7EE4u, r_u32(output));
        w_u32(0x800A7EECu, r_u32(output + 8u));
        result = sub_8005D800(a2);
        if (result)
            w_u16(0x800A8566u, 0u);
        else
            for (i = 0; i < 3u; ++i)
                w_u32(0x800A7EE4u + i * 4u, saved[i]);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8002D7D4 */
uint32 sub_8002D7D4(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 random = sub_80069A50(), row = 0x800A8828u + ((uint32)(int32)(int16)a3 << 4), scratch = draft_scratch_adapter(48u), impulse = scratch, velocity = scratch + 16u, extent = scratch + 32u, angle, kind, result;
    int32 strength = (int32)(r_u32(row + 12u) - a4);
    uint32 x, z;
    if (strength < 0)
        strength = (int32)(a4 - r_u32(row + 12u));
    if (strength >= 9)
        strength = 8;
    angle = sub_80055A9C(r_u32(a1 + 20u) - r_u32(row), r_u32(a1 + 28u) - r_u32(row + 8u)) & 4095u;
    x = (uint32)((int32)((uint32)strength * (uint32)(int32)(int16)r_u16(0x800102E0u + angle * 2u)) >> 8);
    z = (uint32)((int32)((uint32)strength * (uint32)(int32)(int16)r_u16(0x80010AE0u + angle * 2u)) >> 8);
    w_u32(impulse, x);
    w_u32(impulse + 8u, z);
    x = (uint32)((int32)x < 0 ? 0u - x : x) >> 7;
    z = (uint32)((int32)z < 0 ? 0u - z : z) >> 7;
    w_u32(extent, x < 19u ? x : 18u);
    w_u32(extent + 8u, z < 19u ? z : 18u);
    draft_call_adapter(r_u32(r_u32(a1 + 16u) + 4u), a1, velocity);
    if ((int32)draft_call_adapter(r_u32(r_u32(a1 + 16u)), a1) <= 1310719)
    {
        w_u32(velocity, r_u32(velocity) + r_u32(impulse));
        w_u32(velocity + 8u, r_u32(velocity + 8u) + r_u32(impulse + 8u));
    }
    kind = r_u8(0x800B34D0u + (uint32)(int32)(int16)a2 * 20u);
    if (kind == 2u)
    {
        draft_call_adapter(r_u32(r_u32(a1 + 16u) + 24u), a1, velocity);
        result = r_u8(a1 + 197u) - 8u < 2u;
        if (!result)
            return draft_scratch_result(native_stack_mark, (uint64)(sub_8002AF4C(a1 + 200u, random & 0xEFu, extent)));
    }
    else
    {
        result = 1u;
        if (kind >= 3u)
        {
            result = 10u;
            if (kind == 3u || kind == 10u)
            {
                w_u16(a1 + 56u, 255u);
                return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(r_u32(r_u32(a1 + 16u) + 24u), a1, impulse)));
            }
        }
        else if (kind == 1u)
            return draft_scratch_result(native_stack_mark, (uint64)(sub_8002B224(a1, (uint32)(int32)(int16)a2, random & 0xBEFu, velocity, extent, 0x8002DFF8u)));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8002AA2C */
uint32 sub_8002AA2C(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 mode = (int16)a3;
    uint32 target = a2, result = 0u, damage, scratch;
    w_u16(a1 + 56u, r_u8(0x800A5774u + (uint32)(int32)(int16)r_u16(a1 + 58u)));
    if (mode == 1)
    {
        scratch = draft_scratch_adapter(16u);
        damage = (uint32)draft_call_adapter(0x8003D338u, scratch, (uint32)(int32)(int16)r_u16(a1 + 58u));
        result = (uint32)(int32)(int16)r_u16(target + 58u);
        if (!result)
            return draft_scratch_result(native_stack_mark, (uint64)(result));
        w_u16(target + 58u, (uint16)(result - damage));
        result = (result - damage) << 16;
        if ((int32)result > 0)
            return draft_scratch_result(native_stack_mark, (uint64)(result));
        w_u16(target + 58u, 0u);
        sub_80036CFC(target + 8u);
        if (r_u32(a1 + 16u) == r_u32(0x800A7BACu))
        {
            uint32 kills;
            if (!r_u32(0x800A9734u))
                w_u32(0x800A9A34u, r_u32(0x800A9A34u) + 1u);
            kills = r_u32(0x800A9A34u);
            if (kills == 10u || kills == 20u || kills == 40u)
            {
                w_u32(0x800A6258u, 90u);
                if (kills == 40u)
                    w_u32(0x800A9734u, 2u);
            }
        }
    }
    else if (mode < 2)
    {
        if (mode == 0)
        {
            result = 1u;
            if (r_u32(0x800A86A0u) && !r_u32(0x800A6450u))
            {
                damage = (uint32)(int32)(int16)draft_call_adapter(0x8003D338u, 0x800A8514u, (uint32)(int32)(int16)r_u16(a1 + 58u));
                draft_call_adapter(0x8003D27Cu, r_u32(0x800A8514u));
                w_u32(0x800A86A0u, r_u32(0x800A86A0u) - damage);
                draft_call_adapter(0x8003D324u, r_u32(0x800A86A0u));
                if ((int32)r_u32(0x800A86A0u) <= 0)
                {
                    w_u32(0x800A86A0u, 0u);
                    result = 0u;
                }
            }
            if (result)
                return draft_scratch_result(native_stack_mark, (uint64)(result));
        }
    }
    else if (mode == 2)
    {
        result = sub_8002A908(a1, a2);
        if (result)
            return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    else if (mode == 9)
    {
        target = r_u32(r_u32(0x800A851Cu) + (uint32)(int32)(int16)r_u16(a2 + 58u) * 4u);
        mode = (int16)r_u16(target + 56u);
        result = (uint32)(int32)(int16)r_u16(target + 58u);
        if (!result)
            return draft_scratch_result(native_stack_mark, (uint64)(result));
        result = sub_8002A908(a1, target);
        if (result)
            return draft_scratch_result(native_stack_mark, (uint64)(result));
        w_u16(a2 + 56u, 9u);
        w_u16(a2 + 58u, 0u);
        w_u8(a2 + 13u, 2u);
        draft_call_adapter(0x80052988u, a2);
        draft_call_adapter(0x800608F8u, a2);
    }
    w_u16(target + 56u, (uint16)mode);
    w_u16(a1 + 56u, 4u);
    draft_call_adapter(0x80052988u, target);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800608F8u, target)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800467A4 */
uint32 sub_800467A4(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = sub_800465A8(a1, 0u), player, row;
    int32 dx, dz, dy, height, kind;
    if (result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    result = r_u8(a1 + 12u) < 6u;
    if (result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    w_u16(a1 + 58u, (uint16)(r_u16(a1 + 58u) + ((5120u * (uint32)((int32)r_u32(0x800A63D8u) >> 8)) >> 16)));
    draft_call_adapter(0x800551CCu, (uint32)(int32)(int16)r_u16(a1 + 58u), a1 + 104u);
    draft_call_adapter(0x80031B20u, a1 + 36u, a1 + 104u, a1 + 104u);
    player = r_u32(0x800A7BACu);
    dx = (int32)(r_u32(a1 + 20u) - r_u32(player + 20u));
    if (dx < 0)
        dx = (int32)(0u - (uint32)dx);
    result = dx < 501;
    if (!result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    dz = (int32)(r_u32(a1 + 28u) - r_u32(player + 28u));
    if (dz < 0)
        dz = (int32)(0u - (uint32)dz);
    result = dz < 501;
    if (!result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    dy = (int32)(r_u32(a1 + 24u) - r_u32(player + 24u));
    if (dy < 0)
        dy = (int32)(0u - (uint32)dy);
    row = r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u));
    height = (int16)r_u16(r_u32(0x800A90ACu) + row * 40u + 32u) + 400;
    result = height < dy;
    if (result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    sub_800595F0(4u, 28u);
    if (r_u8(a1 + 67u) && r_u32(r_u32(0x800A851Cu) + (uint32)(int32)(int16)r_u16(0x800A9730u) * 4u) == a1)
        sub_8004525C();
    kind = (int8)r_u8(a1 + 67u);
    if (kind == 1 || kind == 2)
    {
        row = 0x800A7F18u + (kind == 1 ? 0u : 4u);
        w_u16(row + 52u, r_u16(row + 52u) - 1u);
        sub_80044F8C(0u);
    }
    w_u8(a1 + 64u, 1u);
    w_u16(a1 + 84u, 0xFFFFu);
    w_u32(a1, 0x8004674Cu);
    w_u16(a1 + 70u, r_u16(0x800A6EE4u));
    result = 0x8004674Cu;
    if (!r_u16(a1 + 60u))
    {
        draft_call_adapter(0x80030F08u, (uint32)(int32)(int16)r_u16(a1 + 74u), (uint32)(int32)(int16)r_u16(a1 + 68u), 1u);
        result = 1u;
        w_u16(a1 + 60u, 1u);
    }
    w_u8(a1 + 14u, 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8001C114 */
uint32 sub_8001C114(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 cursor = a1, source = a3, i;
    for (i = 0; i < a7; ++i)
    {
        uint32 vertex, j, depth, screen[3];
        int32 area;
        for (j = 0; j < 3u; ++j)
        {
            vertex = a2 + r_u16(source + 20u + j * 2u) * 8u;
            xport_gte_write_data(j * 2u, r_u32(vertex));
            xport_gte_write_data(j * 2u + 1u, r_u32(vertex + 4u));
        }
        draft_gte_command_adapter(0x280030u);
        draft_gte_command_adapter(0x158002Du);
        depth = xport_gte_read_data(7u);
        source += 28u;
        if (!depth)
            continue;
        draft_gte_command_adapter(0x1400006u);
        area = (int32)xport_gte_read_data(24u);
        if (area < 0)
            continue;
        for (j = 0; j < 3u; ++j)
            screen[j] = xport_gte_read_data(12u + j);
        w_u32(cursor + 8u, screen[0]);
        w_u32(cursor + 16u, screen[1]);
        w_u32(cursor + 24u, screen[2]);
        w_u32(cursor + 12u, r_u32(source - 24u));
        w_u32(cursor + 20u, r_u32(source - 20u));
        w_u32(cursor + 28u, r_u32(source - 16u));
        w_u32(cursor + 4u, r_u32(source - 12u));
        vertex = a4 + (a6 + (depth >> 3)) * 4u;
        w_u32(cursor, (r_u32(vertex) & 0xFFFFFFu) | 0x07000000u);
        w_u32(vertex, (r_u32(vertex) & 0xFF000000u) | (cursor & 0xFFFFFFu));
        cursor += 32u;
    }
    w_u32(a8, source);
    return draft_scratch_result(native_stack_mark, (uint64)(cursor));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800410E4 */
uint32 sub_800410E4(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(48u), previous = scratch, origin = scratch + 12u, normal = scratch + 24u, i, state, result, time;
    for (i = 0; i < 3u; ++i)
    {
        w_u32(previous + i * 4u, r_u32(a1 + 20u + i * 4u));
        w_u32(origin + i * 4u, r_u32(a1 + 20u + i * 4u));
    }
    state = (uint32)(int32)(int16)r_u16(a1 + 424u);
    if (state != 3u)
    {
        uint32 trigger = r_u16(a1 + 56u);
        if (trigger == 255u)
        {
            w_u16(a1 + 56u, 0u);
            w_u16(a1 + 424u, 3u);
            w_u32(a1 + 428u, 0u);
            w_u16(a1 + 448u, (uint16)(sub_80055A9C(r_u32(a1 + 432u), r_u32(a1 + 440u)) + 2048u));
            draft_call_adapter(0x80035A08u, r_u16(a1 + 72u) == r_u16(r_u32(0x800A62ECu) + 168u) ? 44u : 45u, 2048u, 255u, previous, 0u);
        }
        else if (trigger == 128u && state != 4u)
        {
            w_u16(a1 + 56u, 0u);
            sub_80040F94(a1);
            w_u32(a1 + 428u, 0u);
            w_u16(a1 + 424u, 5u);
        }
    }
    state = (uint32)(int32)(int16)r_u16(a1 + 424u);
    if (state != 7u)
    {
        w_u32(a1 + 428u, r_u32(a1 + 428u) + ((uint32)((int32)r_u32(0x800A63D8u) >> 8) << 7));
        state = (uint32)(int32)(int16)r_u16(a1 + 424u);
    }
    if (state == 3u)
    {
        time = r_u32(a1 + 428u);
        if ((int32)time < (int32)((uint32)(int32)(int16)r_u16(0x8008FD22u) << 16))
        {
            uint32 dt = r_u32(0x800A9010u);
            w_u32(a1 + 20u, r_u32(a1 + 20u) + r_u32(a1 + 432u) * dt);
            w_u32(a1 + 28u, r_u32(a1 + 28u) + r_u32(a1 + 440u) * dt);
            w_u32(a1 + 432u, (uint32)((int32)(r_u32(a1 + 432u) * 4u) / 5));
            w_u32(a1 + 440u, (uint32)((int32)(r_u32(a1 + 440u) * 4u) / 5));
            if (sub_8002F3FC(origin, a1 + 20u) << 16)
                sub_80023918(r_u32(origin), r_u32(origin + 8u), a1 + 432u, a1 + 440u);
        }
        else
        {
            w_u32(a1 + 428u, time - ((uint32)((int32)r_u32(0x800A63D8u) >> 8) << 7));
            w_u32(a1, 0x800416CCu);
            w_u32(a1 + 24u, 0u - (uint32)draft_call_adapter(0x8002E310u, a1 + 20u, normal, a2) - 50u);
            if (r_u32(0x800A6358u))
                sub_80063418(a1);
            w_u32(a1 + 24u, 0u - (uint32)draft_call_adapter(0x8002E310u, a1 + 20u, normal, a2) - (uint32)(int32)(int16)r_u16(r_u32(0x800A5D24u) + (uint32)(int32)(int16)r_u16(a1 + 430u) * 64u));
            if (r_u32(0x800A6358u))
                sub_80040EF4(a1);
        }
    }
    else
    {
        uint32 duration = (uint32)(int32)(int16)r_u16(0x8008FD1Cu + state * 2u) << 16;
        if ((int32)r_u32(a1 + 428u) >= (int32)duration)
        {
            w_u32(a1 + 428u, state == 4u ? 0u : r_u32(a1 + 428u) - duration);
            w_u16(a1 + 424u, 7u);
        }
        state = (uint32)(int32)(int16)r_u16(a1 + 424u);
        {
            uint32 speed = (uint32)(int32)(int16)r_u16(0x8008FD2Cu + state * 2u), dt = r_u32(0x800A9010u), angle = r_u16(a1 + 448u) & 4095u;
            w_u32(a1 + 20u, r_u32(a1 + 20u) + (uint32)((int32)(speed * dt * (uint32)(int32)(int16)r_u16(0x800102E0u + angle * 2u)) >> 12));
            w_u32(a1 + 28u, r_u32(a1 + 28u) + (uint32)((int32)(speed * dt * (uint32)(int32)(int16)r_u16(0x80010AE0u + angle * 2u)) >> 12));
        }
    }
    state = (uint32)(int32)(int16)r_u16(a1 + 424u);
    w_u16(a1 + 444u, (uint16)(r_u16(a1 + 444u) - (uint32)(int32)(int16)r_u16(0x8008FD2Cu + state * 2u) * r_u32(0x800A9010u)));
    w_u32(0x800A5D24u, r_u32(0x8008FCFCu + state * 4u));
    w_u32(a1 + 24u, 0u - (uint32)draft_call_adapter(0x8002E310u, a1 + 20u, normal, a2) - (uint32)(int32)(int16)r_u16(r_u32(0x800A5D24u) + (uint32)(int32)(int16)r_u16(a1 + 430u) * 64u));
    sub_80055D54(a1, a1 + 60u, r_u16(a1 + 448u) & 4095u);
    if (r_u16(a1 + 424u) != 3u)
        return draft_scratch_result(native_stack_mark, (uint64)(sub_80029970(a1, 200u, 3u, 1u, previous)));
    result = r_u32(a1 + 428u);
    {
        int32 half = (int16)r_u16(0x8008FD22u);
        half /= 2;
        if ((int32)((uint32)half << 16) >= (int32)result)
            return draft_scratch_result(native_stack_mark, (uint64)(sub_80029970(a1, 200u, 3u, 1u, previous)));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8006B410 */
uint32 sub_8006B410(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 dx = r_u32(a2) - r_u32(a1 + 20u), dz = r_u32(a2 + 8u) - r_u32(a1 + 28u), oldX = r_u32(a1 + 60u), oldZ = r_u32(a1 + 68u), speed = sub_80069BE0(oldX, oldZ), bearing = sub_80055A9C(dx, dz), dt = r_u32(0x800A9010u), correction = 0u;
    int32 difference = (int16)((sub_80055A9C(oldX, oldZ) - bearing) & 4095u), turn, limit;
    uint32 heading, accelerationX, accelerationZ, velocityX, velocityZ, distance, displacementX, displacementZ, result;
    if (difference >= 2049)
        difference -= 4096;
    w_u32(a1 + 72u, r_u32(a1 + 72u) - (uint32)(int32)(int16)bearing);
    if ((int32)speed >= 10240 && (difference < 0 ? -difference : difference) < 1025)
    {
        uint32 index = ((uint32)(307 * difference) + 512u) >> 10;
        int32 lateral = (int32)(speed * (uint32)(int32)(int16)r_u16(0x800102E0u + (index & 4095u) * 2u) + 2048u) >> 12;
        int32 required = (int32)((int64)(int32)(0u - (uint32)lateral * 2u) / (int32)(dt + 1u));
        int32 magnitude = required < 0 ? (int32)(0u - (uint32)required) : required;
        if (magnitude >= (int32)a4)
            correction = lateral < 0 ? 1024u : (uint32)-1024;
        else if (a4)
        {
            int32 position = (int32)((int64)(int32)((uint32)magnitude << 9) / (int32)a4);
            correction = (uint32)(int32)(int16)r_u16(0x800132E4u + (uint32)position * 2u);
            if (required <= 0)
                correction = 0u - correction;
        }
    }
    difference = (int16)((correction - r_u16(a1 + 72u)) & 4095u);
    if (difference >= 2049)
        difference -= 4096;
    if (((int32)dx < 0 ? (int32)(0u - dx) : (int32)dx) < 2720 && ((int32)dz < 0 ? (int32)(0u - dz) : (int32)dz) < 2720)
        limit = (int32)(61u * dt) / 2;
    else
    {
        int32 handling = (int16)r_u16(a1 + 82u);
        if (handling <= 0)
            limit = (int16)dt;
        else if (handling >= 20)
            limit = (int16)(60u * dt);
        else
            limit = (int16)(((uint32)(int32)(int16)((59u * (uint32)((handling << 10) / 20) + 1u) * dt) + 512u) >> 10);
    }
    turn = difference < 0 ? (int32)(0u - (uint32)difference) : difference;
    if ((int16)limit < turn)
        heading = difference >= 0 ? r_u32(a1 + 72u) + (uint32)(int32)(int16)limit : r_u32(a1 + 72u) - (uint32)(int32)(int16)limit;
    else
        heading = correction;
    heading += (uint32)(int32)(int16)bearing;
    w_u32(a1 + 72u, heading);
    heading &= 4095u;
    accelerationX = (uint32)((int32)(a4 * (uint32)(int32)(int16)r_u16(0x800102E0u + heading * 2u) + 2048u) >> 12);
    accelerationZ = (uint32)((int32)(a4 * (uint32)(int32)(int16)r_u16(0x80010AE0u + heading * 2u) + 2048u) >> 12);
    velocityX = accelerationX * dt + oldX;
    velocityZ = accelerationZ * dt + oldZ;
    distance = sub_80069BE0(velocityX, velocityZ);
    if ((int32)a3 < (int32)distance && (int32)distance >= 17)
    {
        int32 scale = (int32)((int64)(int32)(a3 << 10) / (int32)distance);
        uint32 nextX, nextZ;
        if (scale < 0)
            scale = (int32)(0u - (uint32)scale);
        nextX = (uint32)((int32)((uint32)scale * velocityX + 512u) >> 10);
        nextZ = (uint32)((int32)((uint32)scale * velocityZ + 512u) >> 10);
        accelerationX = (uint32)((int64)(int32)(nextX - velocityX) / (int32)dt);
        accelerationZ = (uint32)((int64)(int32)(nextZ - velocityZ) / (int32)dt);
        velocityX = nextX;
        velocityZ = nextZ;
    }
    displacementX = (uint32)((int32)((velocityX + oldX + accelerationX) * dt + 1024u) >> 11);
    displacementZ = (uint32)((int32)((velocityZ + oldZ + accelerationZ) * dt + 1024u) >> 11);
    w_u32(a1 + 60u, velocityX);
    w_u32(a1 + 64u, 0u);
    w_u32(a1 + 68u, velocityZ);
    w_u32(a1 + 20u, r_u32(a1 + 20u) + displacementX);
    w_u32(a1 + 28u, r_u32(a1 + 28u) + displacementZ);
    distance = sub_80069BE0(displacementX, displacementZ);
    if ((int32)distance < 30)
        distance = 30u;
    sub_8006ABE8(a1, distance);
    w_u32(a1 + 24u, sub_8006B198(a1 + 108u, distance));
    w_u32(a1 + 64u, 0u);
    result = sub_80055A9C(r_u32(a1 + 112u), 1024u);
    w_u32(a1 + 76u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
