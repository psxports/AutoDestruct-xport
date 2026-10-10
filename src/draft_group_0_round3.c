#include "draft_signatures.h"
#include <stdlib.h>

static uint32 d03_call(uint32 target, uint32 a, uint32 b, uint32 c, uint32 d)
{
    // TODO Bind the external original boundary
    return (uint32)draft_call_adapter(target, a, b, c, d);
}

static int32 d03_div(uint32 n, uint32 d)
{
    if (!d || (d == 0xFFFFFFFFu && n == 0x80000000u))
        abort();
    return (int32)n / (int32)d;
}

static int32 d03_trig(uint32 base, uint32 angle)
{
    return (int16)r_u16(base + 2u * (angle & 4095u));
}

static int32 d03_angle(uint32 value)
{
    value &= 4095u;
    return value >= 2049u ? (int32)value - 4096 : (int32)value;
}

static uint32 d03_model(uint32 object)
{
    return r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
}

// FUNCTION_MARKER sub_80023A7C
uint32 sub_80023A7C(uint32 object, uint32 mask, uint32 index, uint32 impulse, uint32 scale)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = (uint32)(int32)(int16)r_u16(0x800A6C04u) & mask, heading, difference, reflection, amount;
    int32 angle;
    if (!result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    heading = sub_80055A9C(r_u32(0x800A6BA4u + 12u * index), r_u32(0x800A6BACu + 12u * index));
    difference = (heading - sub_80055A9C((uint32)((int32)r_u32(object + 476u) >> 8), (uint32)((int32)r_u32(object + 480u) >> 8))) & 4095u;
    angle = d03_angle(difference);
    if (angle < 0)
        angle = -angle;
    w_u32(0x800A56A8u, 24u * (uint32)angle + 0x4000u);
    if (difference - 1025u >= 2047u)
    {
        reflection = (heading + difference) & 4095u;
        amount = (uint32)((int32)d03_call(0x80069BE0u, r_u32(object + 476u), r_u32(object + 480u), 0u, 0u) >> 8);
        w_u32(object + 476u, 0u - (uint32)((int32)(amount * (uint32)(d03_trig(0x800102E0u, reflection) >> 4)) >> 8) * (uint32)((int32)r_u32(0x800A56A8u) >> 8));
        w_u32(object + 480u, 0u - (uint32)((int32)(amount * (uint32)(d03_trig(0x80010AE0u, reflection) >> 4)) >> 8) * (uint32)((int32)r_u32(0x800A56A8u) >> 8));
    }
    result = (uint32)((int32)((uint32)((int32)impulse >> 8) * ((uint16)(0u - r_u32(0x800A56A8u)) >> 8)) >> 8) * (uint32)((int32)scale >> 8) + r_u32(object + 516u);
    w_u32(object + 516u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006A258
uint32 sub_8006A258(uint32 object, uint32 output)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(8u), i, best = 0u, distance = 27200u, heading;
    draft_call_adapter(r_u32(r_u32(object + 16u) + 20u), object, scratch);
    heading = r_u16(scratch + 2u) + 2048u;
    for (i = 0; i < r_u32(0x800A5690u); ++i)
    {
        uint32 candidate = r_u32(r_u32(0x800A568Cu) + 4u * i), kind = r_u8(candidate + 13u) & 127u;
        if (r_u8(candidate + 14u) & 2u)
        {
            switch (kind)
            {
                case 3:
                case 4:
                case 6:
                case 11:
                case 12:
                case 14:
                {
                    uint32 dx = r_u32(candidate + 20u) - r_u32(object + 20u), dz = r_u32(candidate + 28u) - r_u32(object + 28u), length;
                    int32 angle = d03_angle(sub_80055A9C(dx, dz) - heading);
                    if (angle < 0)
                        angle = -angle;
                    if (angle < 1024)
                    {
                        length = d03_call(0x80069BE0u, dx, dz, 0u, 0u);
                        if (!best || (!r_u8(best + 67u) && (int32)length < (int32)distance) || (r_u8(best + 67u) == 1u && r_u8(candidate + 67u) == 1u && (int32)length < (int32)distance) || (r_u8(best + 67u) == 2u && r_u8(candidate + 67u) && (int32)length < (int32)distance))
                        {
                            best = candidate;
                            distance = length;
                        }
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
    if (best)
        w_u16(output, (uint16)(int16)(int8)r_u8(best + 67u));
    return draft_scratch_result(native_stack_mark, (uint64)(best));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80022FF8
uint32 sub_80022FF8(uint32 object, uint32 contacts, uint32 flags, uint32 corners)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(40u), i, height = 0u;
    if ((int32)r_u32(object + 492u) > -327680)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    for (i = 0; i < 4u; ++i)
    {
        uint32 corner = corners + 8u * i, j, ground, otherground;
        int32 model_height = (int16)r_u16(d03_model(object) + 32u);
        for (j = 0; j < 3u; ++j)
            w_u32(scratch + 12u + 4u * j, (uint32)(int32)(int16)r_u16(corner + 2u * j) + r_u32(object + 20u + 4u * j));
        w_u32(scratch, r_u32(scratch + 12u));
        w_u32(scratch + 8u, r_u32(scratch + 20u));
        height = (uint32)(int32)(int16)r_u16(corner + 2u) + r_u32(object + 248u) - (uint32)model_height;
        w_u32(scratch + 4u, height);
        ground = 0u - d03_call(0x8002E310u, scratch, scratch + 24u, scratch + 32u, 0u);
        otherground = 0u - d03_call(0x8002E310u, scratch + 12u, scratch + 24u, scratch + 32u, 0u);
        if ((int32)height < (int32)ground && (int32)r_u32(scratch + 16u) < (int32)ground && (int32)otherground < (int32)height && (int32)r_u32(scratch + 16u) < (int32)height)
        {
            for (j = 0; j < 4u; ++j)
            {
                uint32 p = contacts + 16u * j, word = r_u32(p + 12u);
                int32 magnitude = (int32)(word << 4) >> 4;
                if (magnitude < 0)
                    magnitude = -magnitude;
                w_u32(p + 12u, (word & 0xF0000000u) | ((uint32)magnitude & 0x0FFFFFFFu));
            }
            w_u16(contacts + 64u, (uint16)height);
            w_u32(object + 24u, (uint32)(int32)(int16)height + (uint32)model_height);
            w_u32(object + 476u, (uint32)((int32)r_u32(object + 476u) >> 1));
            w_u32(object + 480u, (uint32)((int32)r_u32(object + 480u) >> 1));
            w_u16(flags, r_u16(flags) | 256u);
            return draft_scratch_result(native_stack_mark, (uint64)(1u));
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800345B0
uint32 sub_800345B0(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result, player;
    if (r_u32(0x800A6D18u) == 1u)
    {
        if ((int32)r_u32(0x800A6CF4u) < 2)
        {
            if (r_u32(0x800A8690u) == 2u)
            {
                player = r_u32(r_u32(0x800A851Cu) + 4u * (uint32)(int32)(int16)r_u16(object));
                if ((int16)r_u16(player + 12u) != -1)
                {
                    w_u8(r_u32(r_u32(0x800A851Cu) + 4u * (uint32)(int32)(int16)r_u16(player + 12u)) + 66u, 0u);
                    w_u16(player + 12u, 0xFFFFu);
                }
            }
            if (!r_u16(0x800A6CE0u))
                w_u16(0x800A6CE0u, 1u);
            if (!r_u32(0x800A84D4u) && r_u32(0x800A975Cu))
            {
                player = r_u32(r_u32(0x800A851Cu) + 4u * (uint32)(int32)(int16)r_u16(object));
                if ((int16)r_u16(player + 8u) <= 0 && ((int32)r_u32(0x800A9A34u) < 40 || r_u32(0x800A8E70u)))
                    w_u32(0x800A9A68u, 0u);
                else if (r_u32(0x800A6CF4u) == 1u)
                {
                    w_u32(0x800A9A68u, (int32)r_u32(0x800A9A34u) >= 40 && !r_u32(0x800A8E70u) ? 402u : (uint32)(int32)(int16)r_u16(player + 8u));
                    draft_call_adapter(0x80033120u);
                }
            }
            if (!r_u32(0x800A8E70u))
                draft_call_adapter(0x80033418u, object);
            w_u32(0x800A6CF4u, r_u32(0x800A6CF4u) + 1u);
        }
        if (r_u32(0x800A6CF4u) == 2u && r_u32(0x800A9A68u) && r_u16(r_u32(r_u32(0x800A851Cu) + 4u * (uint32)(int32)(int16)r_u16(object)) + 8u) && r_u16(0x800A9A64u) == 1u)
            w_u32(0x800A6CFCu, 1u);
    }
    result = r_u32(0x800A84D4u);
    if (!result && r_u32(0x800A9A68u))
    {
        result = r_u32(0x800A975Cu);
        if (result)
            return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8003315Cu, r_u32(0x800A9A68u))));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8003438C
uint32 sub_8003438C(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result, show = r_u32(0x800A8E70u);
    if (show == 1u)
    {
        uint32 text = (r_u32(0x800A84D4u) && r_u32(0x800A9020u) == r_u32(0x800A6098u)) ? r_u32(0x800A8D70u) : r_u32(r_u32(0x800A851Cu) + 4u * (uint32)(int32)(int16)r_u16(object)) + 19u;
        result = sub_800788D4((uint32)(int32)(int16)r_u16(object), r_u32(object + 4u), r_u32(0x800A9D5Cu), r_u32(0x800A6CF8u), r_u32(0x800A6D14u), text, 0u - 104u);
        w_u32(0x800A6D04u, result);
    }
    else if (r_u32(0x800A6D18u) == 1u)
    {
        uint32 n = 13u * r_u32(0x800A6C90u);
        result = d03_call(0x80043DF4u, 0u - (uint32)((int32)n / 2) - 7u, 0u, 0u, 0u);
    }
    if (r_u32(0x800A8E70u) == 1u)
    {
        sub_80033D40();
        draft_call_adapter(0x80033EF8u, r_u32(0x800A9A74u), 0u - 152u, 0u - 22u);
        draft_call_adapter(0x80020D98u, 2000u, r_u32(0x800A9A74u), 0x202020u, 0u - 160u, 0u - 120u, 320u, 240u);
    }
    if (r_u32(0x800A8540u) & 1u)
        draft_call_adapter(0x800446D8u);
    result = r_u32(0x800A84D4u);
    if (!result)
    {
        result = r_u32(0x800A8E70u);
        if (!result)
            return draft_scratch_result(native_stack_mark, (uint64)(d03_call(0x80044074u, 83u, 0u, 0u, 0u)));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80047480
uint32 sub_80047480(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result, kind;
    uint16 timer;
    if (d03_call(0x80045DD4u, object, 0u, 0u, 0u))
    {
        w_u16(object + 56u, 4u);
        w_u8(object + 65u, 1u);
        w_u32(object, 0x80047438u);
        return draft_scratch_result(native_stack_mark, (uint64)(0x80047438u));
    }
    timer = (uint16)(r_u16(object + 56u) - r_u16(0x800A63DAu));
    w_u16(object + 56u, timer);
    if (timer & 0x8000u)
    {
        uint32 count = r_u32(object + 8u) - 1u;
        w_u16(object + 56u, timer + r_u16(0x800A6EE4u));
        w_u32(object + 8u, count);
        if ((int32)count < 0)
        {
            w_u32(0x800A7E18u, 0u);
            w_u32(object + 8u, 0u);
            w_u8(object + 65u, 0u);
            w_u8(object + 64u, 0u);
            kind = r_u8(object + 67u);
            if (!kind)
            {
                int32 slot = (int16)r_u16(object + 62u);
                w_u16(object + 60u, 0xFFFFu);
                if (slot != -1)
                {
                    uint32 other = r_u32(r_u32(0x800A851Cu) + 4u * (uint32)slot);
                    if (!r_u8(other + 64u))
                        w_u8(other + 66u, r_u8(other + 66u) - 1u);
                }
                w_u16(object + 62u, 0xFFFFu);
            }
            else if (r_u32(object + 52u))
            {
                uint32 id = r_u16(object + 58u);
                if (id <= 1u)
                {
                    w_u16(0x800A6ED8u, r_u16(0x800A6ED8u) - 1u);
                    draft_call_adapter(0x80044F8Cu, id);
                }
            }
            else if (kind == 1u || kind == 2u)
            {
                uint32 p = 0x800A7F80u + (kind == 1u ? 0u : 4u);
                w_u16(p, r_u16(p) - 1u);
                draft_call_adapter(0x80044F8Cu, 0u);
            }
            w_u16(object + 56u, 4u);
            w_u32(object, 0x80047438u);
        }
    }
    result = r_u32(object + 52u);
    if (result)
    {
        if (r_u16(0x800A60ACu))
        {
            w_u32(object + 8u, (uint32)(int32)(int16)r_u16(0x800A60ACu));
            w_u16(0x800A60ACu, 0u);
        }
        result = r_u32(object + 8u);
        w_u32(0x800A7E18u, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80046E9C
uint32 sub_80046E9C(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result, player, dx, dz, dy;
    if (r_u16(object + 58u) == 1u)
        w_u32(0x800A6138u, r_u32(0x800A6138u) + (uint32)(int32)(int16)r_u16(object + 80u));
    if (d03_call(0x80045E18u, object, object + 72u, 0u, 0u) || d03_call(0x80045DD4u, object, 0u, 0u, 0u))
    {
        if (r_u8(object + 67u) && r_u32(r_u32(0x800A851Cu) + 4u * r_u32(0x800A9730u)) == object)
            draft_call_adapter(0x8004525Cu);
        goto remove;
    }
    if (r_u8(object + 67u) && !r_u32(0x800A9760u))
        draft_call_adapter(0x800451B4u, object + 20u, (uint32)(int32)(int16)r_u16(object + 68u));
    result = r_u8(object + 12u) < 5u;
    if (result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    w_u16(object + 70u, r_u16(object + 70u) + ((5120u * (r_u32(0x800A63D8u) >> 8)) >> 16));
    draft_call_adapter(0x800551CCu, (uint32)(int32)(int16)r_u16(object + 70u), object + 104u);
    sub_80031B20(object + 36u, object + 104u, object + 104u);
    player = r_u32(0x800A7BACu);
    dx = r_u32(object + 20u) - r_u32(player + 20u);
    if ((int32)dx < 0)
        dx = 0u - dx;
    result = (int32)dx < 501;
    if (!result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    dz = r_u32(object + 28u) - r_u32(player + 28u);
    if ((int32)dz < 0)
        dz = 0u - dz;
    result = (int32)dz < 501;
    if (!result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    dy = r_u32(object + 24u) - r_u32(player + 24u);
    if ((int32)dy < 0)
        dy = 0u - dy;
    result = (int32)((uint32)(int32)(int16)r_u16(d03_model(object) + 32u) + 400u) < (int32)dy;
    if (result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    draft_call_adapter(0x80046A58u, object);
    if (r_u16(object + 86u))
    {
        result = (uint32)(int32)(int16)r_u16(object + 86u) * r_u32(0x800A6EE4u);
        w_u32(object, 0x80046DD4u);
        w_u16(object + 70u, (uint16)result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    if (r_u16(object + 58u) == 1u && (int16)r_u16(object + 80u) < 1001)
    {
        w_u32(object, 0x80046E18u);
        return draft_scratch_result(native_stack_mark, (uint64)(0x80046E18u));
    }
remove:
    w_u32(object, 0x80029968u);
    return draft_scratch_result(native_stack_mark, (uint64)(0x80029968u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800255FC
uint32 sub_800255FC(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result, type = sub_80037BB8();
    int32 angle = (int16)r_u16(object + 562u), step;
    if ((int16)type == 2)
    {
        result = (uint32)(((int32)(uint8)draft_call_adapter(0x80037BD0u) - 128) * 4);
        w_u16(object + 562u, (uint16)result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    if ((int16)sub_80037BB8() == 3)
    {
        int32 v = (uint8)draft_call_adapter(0x80037BD0u) - 128;
        result = (uint32)(v + v / 2);
        w_u16(object + 562u, (uint16)result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    step = d03_div(60u * ((1536u * (r_u32(0x800A63D8u) >> 8)) >> 16), r_u32(0x800A56C0u));
    if (r_u32(0x800A8398u) & 16u)
    {
        if (angle < 0)
        {
            angle = 0;
            w_u16(object + 562u, 0u);
        }
        if ((int32)r_u32(object + 472u) <= 0x3FFFF)
        {
            if (!r_u32(0x800A5758u))
                w_u32(object + 484u, 0x40000u - r_u32(object + 472u));
            angle += 4 * step;
        }
        else
            angle += step;
        w_u16(object + 562u, (uint16)angle);
        result = (int16)angle > 512;
        if (result)
            w_u16(object + 562u, 512u);
    }
    else if (r_u32(0x800A8398u) & 8u)
    {
        if (angle > 0)
        {
            angle = 0;
            w_u16(object + 562u, 0u);
        }
        if ((int32)r_u32(object + 472u) <= 0x3FFFF)
        {
            if (!r_u32(0x800A5758u))
                w_u32(object + 484u, 0x40000u - r_u32(object + 472u));
            angle -= 4 * step;
        }
        else
            angle -= step;
        w_u16(object + 562u, (uint16)angle);
        result = (uint32)-512;
        if ((int16)angle < -512)
            w_u16(object + 562u, (uint16)-512);
    }
    else
    {
        result = 4u * (uint32)step;
        if (angle < 0)
        {
            angle += (int32)result;
            w_u16(object + 562u, (uint16)angle);
            result = (uint32)angle << 16;
            if ((int32)result > 0)
                w_u16(object + 562u, 0u);
        }
        else if (angle > 0)
        {
            angle -= (int32)result;
            w_u16(object + 562u, (uint16)angle);
            result = (uint32)angle << 16;
            if ((int32)result < 0)
                w_u16(object + 562u, 0u);
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800433D4
uint32 sub_800433D4(uint32 x, uint32 y, uint32 icon_x, uint32 icon_y)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 score = r_u32(0x800A7C6Cu), digits[5], i = 0u, cursor = x + 14u, kind;
    if ((int32)score > 99999)
    {
        score = 99999u;
        w_u32(0x800A7C6Cu, score);
    }
    digits[0] = score / 10000u;
    digits[1] = score % 10000u / 1000u;
    digits[2] = score % 1000u / 100u;
    digits[3] = score % 100u / 10u;
    digits[4] = score % 10u;
    while (i < 4u && !digits[i])
        ++i;
    sub_800436D4(0x808080u, 0x800A5F6Cu, (uint32)(int32)(int16)(x + 1u), (uint32)(int32)(int16)y, 150u);
    for (; i < 5u; ++i)
    {
        draft_call_adapter(0x8004328Cu, 0x8009091Cu, 0x54000040u, digits[i], 0x808080u, cursor, y + 1u, 180u);
        draft_call_adapter(0x8004328Cu, 0x8009091Cu, 0x64000040u, digits[i], 0x202020u, cursor + 1u, y + 2u, 180u);
        cursor += r_u8(0x8009091Eu + 5u * digits[i]);
    }
    kind = (uint32)(int32)(int16)draft_call_adapter(0x8003D6ACu);
    if ((int32)kind >= 6)
        kind = 5u;
    kind &= 15u;
    draft_call_adapter(0x8004328Cu, 0x8009091Cu, 0x54000040u, kind, 0x808080u, icon_x, icon_y, 180u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8004328Cu, 0x8009091Cu, 0x64000040u, kind, 0x202020u, icon_x + 1u, icon_y + 1u, 180u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800782D8
uint32 sub_800782D8(uint32 glyph, uint32 x, uint32 y, uint32 depth, uint32 selector)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 entry = r_u32(0x800A5F68u) + 5u * glyph, index = r_u8(entry + 4u), color;
    draft_call_adapter(0x80041C9Cu, 0x800A98D4u, 0x54000040u, r_u8(entry + 2u), r_u8(entry + 3u), r_u16(0x800903B4u + 2u * index), r_u8(entry), r_u8(entry + 1u), (uint32)(int32)(int16)r_u16(0x800903C4u + 2u * index), 481u);
    color = (int32)r_u32(0x800A84E0u) >= 1024 && selector == r_u32(0x800A9A70u) ? 0x808080u : 0x404040u;
    draft_call_adapter(0x80041D90u, 0x800A98D4u, color);
    draft_call_adapter(0x80041DB4u, 0x800A98D4u, (uint32)(int32)(int16)x, (uint32)(int32)(int16)(y + 1u), 0u);
    draft_call_adapter(0x80020AB4u, 0x800A98D4u, r_u32(0x800A9A74u) + 596u, 1u, depth);
    entry = r_u32(0x800A5F68u) + 5u * glyph;
    index = r_u8(entry + 4u);
    draft_call_adapter(0x80041C9Cu, 0x800A98D4u, 0x64000040u, r_u8(entry + 2u), r_u8(entry + 3u), r_u16(0x800903B4u + 2u * index), r_u8(entry), r_u8(entry + 1u), (uint32)(int32)(int16)r_u16(0x800903C4u + 2u * index), 481u);
    draft_call_adapter(0x80041D90u, 0x800A98D4u, 0x808080u);
    draft_call_adapter(0x80041DB4u, 0x800A98D4u, (uint32)(int32)(int16)(x + 1u), (uint32)(int32)(int16)(y + 2u), 0u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80020AB4u, 0x800A98D4u, r_u32(0x800A9A74u) + 596u, 1u, depth)));

    draft_scratch_release(native_stack_mark);
}

static void d03_vertices(uint32 a, uint32 b, uint32 c)
{
    xport_gte_write_data(0u, r_u32(a));
    xport_gte_write_data(1u, r_u32(a + 4u));
    xport_gte_write_data(2u, r_u32(b));
    xport_gte_write_data(3u, r_u32(b + 4u));
    xport_gte_write_data(4u, r_u32(c));
    xport_gte_write_data(5u, r_u32(c + 4u));
}

static void d03_packet(uint32 packet, uint32 table, uint32 bias, uint32 depth)
{
    uint32 link = table + 4u * bias + 4u * (depth >> 3);
    w_u32(packet, (r_u32(link) & 0xFFFFFFu) | 0x05000000u);
    w_u32(link, (r_u32(link) & 0xFF000000u) | (packet & 0xFFFFFFu));
}

// FUNCTION_MARKER sub_8001DDA4
uint32 sub_8001DDA4(uint32 screen, uint32 packet, uint32 table, uint32 vertices, uint32 bias)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 start = 0u, j;
    do
    {
        uint32 a = vertices + 8u * start, b = a + 8u, c = a + 24u, d = a + 32u, flag, depth, nclip;
        d03_vertices(a, b, c);
        draft_gte_command_adapter(0x280030u);
        xport_gte_write_data(0u, r_u32(d));
        xport_gte_write_data(1u, r_u32(d + 4u));
        flag = draft_gte_control_adapter(31u);
        draft_gte_command_adapter(0x1400006u);
        nclip = xport_gte_read_data(24u);
        if ((int32)flag >= 0 && nclip + 1023u < 2047u)
        {
            for (j = 0; j < 3u; ++j)
                w_u32(packet + 8u + 4u * j, xport_gte_read_data(12u + j));
            draft_gte_command_adapter(0x180001u);
            w_u32(packet + 4u, xport_gte_read_data(22u));
            draft_gte_command_adapter(0x168002Eu);
            w_u32(packet + 20u, xport_gte_read_data(14u));
            depth = xport_gte_read_data(7u);
            d03_packet(packet, table, bias, depth);
            packet += 24u;
            goto next;
        }
        for (j = 0; j < 3u; ++j)
            w_u32(screen + 4u * j, xport_gte_read_data(12u + j));
        xport_gte_write_data(0u, r_u32(d));
        xport_gte_write_data(1u, r_u32(d + 4u));
        draft_gte_command_adapter(0x180001u);
        w_u32(screen + 12u, xport_gte_read_data(14u));
        {
            uint32 right = 1u, left = 1u, bottom = 1u, top = 1u;
            for (j = 0; j < 4u; ++j)
            {
                int32 x = (int16)r_u16(screen + 4u * j), y = (int16)r_u16(screen + 4u * j + 2u);
                right &= x >= 320;
                left &= x <= 0;
                bottom &= y >= 240;
                top &= y <= 0;
            }
            if (right || left || bottom || top)
                goto next;
        }
        for (j = 0; j < 3u; ++j)
        {
            int32 va = (int16)r_u16(a + 2u * j), vb = (int16)r_u16(b + 2u * j), vc = (int16)r_u16(c + 2u * j), vd = (int16)r_u16(d + 2u * j);
            w_u16(vertices + 72u + 2u * j, (uint16)((va + vb) >> 1));
            w_u16(vertices + 80u + 2u * j, (uint16)((va + vc) >> 1));
            w_u16(vertices + 88u + 2u * j, (uint16)((vb + vc) >> 1));
            w_u16(vertices + 104u + 2u * j, (uint16)((vd + vc) >> 1));
            w_u16(vertices + 96u + 2u * j, (uint16)((vb + vd) >> 1));
        }
        {
            uint32 indices[4][4] = {{start, 9u, 10u, 11u}, {9u, start + 1u, 11u, 12u}, {10u, 11u, start + 3u, 13u}, {11u, 12u, 13u, start + 4u}}, part;
            for (part = 0; part < 4u; ++part)
            {
                d03_vertices(vertices + 8u * indices[part][0], vertices + 8u * indices[part][1], vertices + 8u * indices[part][2]);
                draft_gte_command_adapter(0x280030u);
                d = vertices + 8u * indices[part][3];
                xport_gte_write_data(0u, r_u32(d));
                xport_gte_write_data(1u, r_u32(d + 4u));
                draft_gte_command_adapter(0x1400006u);
                if (1)
                {
                    for (j = 0; j < 3u; ++j)
                        w_u32(packet + 8u + 4u * j, xport_gte_read_data(12u + j));
                    draft_gte_command_adapter(0x180001u);
                    draft_gte_command_adapter(0x168002Eu);
                    depth = xport_gte_read_data(7u);
                    if (depth)
                    {
                        w_u32(packet + 20u, xport_gte_read_data(14u));
                        d03_packet(packet, table, bias, depth);
                        w_u32(packet + 4u, xport_gte_read_data(22u));
                        packet += 24u;
                    }
                }
            }
        }
    next:
        ++start;
        if (start == 2u)
            start = 3u;
    } while (start < 5u);
    return draft_scratch_result(native_stack_mark, (uint64)(packet));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80020300
uint32 sub_80020300(uint32 object, uint32 parameter, uint32 detail, uint32 screen_x, uint32 screen_y)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i, j, words[5] = {0u, 0u, 0u, 0u, 0u}, origin_x, origin_y, model, packet, cursor, count, done = 0u, result;
    uint16 light[9];
    uint32 ot = r_u32(r_u32(0x800A7E08u)), scratch = draft_scratch_adapter(4u);
    for (i = 0; i < 5u; ++i)
        xport_gte_write_control(i, r_u32(0x800A84B4u + 4u * i));
    for (i = 0; i < 3u; ++i)
    {
        for (j = 0; j < 3u; ++j)
            xport_gte_write_data(9u + j, r_u16(object + 16u + 2u * i + 6u * j));
        draft_gte_command_adapter(0x49E012u);
        for (j = 0; j < 3u; ++j)
            light[3u * j + i] = (uint16)xport_gte_read_data(9u + j);
    }
    for (i = 0; i < 9u; ++i)
        words[i >> 1] |= (uint32)light[i] << ((i & 1u) * 16u);
    for (i = 0; i < 5u; ++i)
        xport_gte_write_control(8u + i, words[i]);
    for (i = 0; i < 5u; ++i)
        xport_gte_write_control(i, r_u32(object + 16u + 4u * i));
    for (i = 0; i < 3u; ++i)
        xport_gte_write_control(5u + i, r_u32(object + 4u * i));
    origin_x = draft_gte_control_adapter(24u);
    origin_y = draft_gte_control_adapter(25u);
    xport_gte_write_control(24u, (screen_x + (uint32)((int32)origin_x >> 16)) << 16);
    xport_gte_write_control(25u, (screen_y + (uint32)((int32)origin_y >> 16)) << 16);
    model = r_u32(0x800C0E00u + 4u * r_u16(object + 12u));
    cursor = r_u32(model);
    count = r_u32(model + 4u);
    packet = r_u32(0x800A865Cu);
    result = model;
    w_u32(scratch, cursor);
    while (done < count)
    {
        uint32 command = r_u32(r_u32(scratch)), length = command & 2047u, target = r_u32(0x8008B728u + 4u * (command >> 24));
        done += length;
        // TODO The original dispatch receives the packet iterator by guest address
        packet = (uint32)draft_call_adapter(target, packet, ot, r_u32(scratch), parameter, 0u, (uint32)(int32)(int16)detail, length, scratch);
        result = done < count;
    }
    w_u32(0x800A865Cu, packet);
    xport_gte_write_control(24u, origin_x & 0xFFFF0000u);
    xport_gte_write_control(25u, origin_y & 0xFFFF0000u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80026BC4
uint32 sub_80026BC4(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = r_u32(0x800A56C8u), scratch = draft_scratch_adapter(8u), i, j;
    int32 velocity;
    if (!result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    velocity = (((int32)r_u32(object + 484u) >> 31) | 1) * ((int32)r_u32(object + 472u) >> 10);
    if (r_u32(object + 580u) & 0x1000000u)
        velocity = (int16)(velocity + 253);
    if ((!r_u32(0x800A8B30u) && !r_u32(0x800A967Cu)) || r_u32(0x800A9760u))
    {
        w_u16(object + 558u, (r_u16(object + 558u) + (uint32)((d03_trig(0x80010AE0u, r_u16(object + 566u)) >> 15) | 1) * (uint32)velocity) & 4095u);
        if ((int32)r_u32(object + 472u) < (int32)r_u32(object + 484u))
        {
            velocity = (int32)r_u32(object + 484u) >> 10;
            if (velocity < 0)
                velocity = -velocity;
        }
        w_u16(object + 556u, (r_u16(object + 556u) + (uint32)((d03_trig(0x80010AE0u, r_u16(object + 564u)) >> 15) | 1) * (uint32)velocity) & 4095u);
    }
    for (i = 0; i < 5u; ++i)
        xport_gte_write_control(i, r_u32(object + 36u + 4u * i));
    for (i = 0; i < 3u; ++i)
        xport_gte_write_control(5u + i, r_u32(object + 20u + 4u * i));
    for (i = 0; i < 4u; ++i)
    {
        uint32 p = 0x800A5720u + 8u * i;
        int32 limit = (int16)r_u16(p + 6u), value = (int16)r_u16(0x800A8688u + 2u * i);
        w_u32(scratch, r_u32(p));
        w_u32(scratch + 4u, r_u32(p + 4u));
        if (limit < value)
            value = limit;
        if (value < -limit)
            value = -limit;
        w_u16(0x800A8688u + 2u * i, (uint16)value);
        draft_call_adapter(0x80031CC0u, scratch, object + 256u + 36u * i);
    }
    for (i = 0; i < 2u; ++i)
    {
        uint32 p = object + 256u + 72u * i, q = object + 292u + 72u * i;
        w_u16(scratch, r_u16(object + 556u + 2u * i) & 4095u);
        draft_call_adapter(0x80055288u, scratch, p + 16u);
        draft_call_adapter(0x80031A54u, p + 16u, p + 16u);
        for (j = 0; j < 4u; ++j)
            w_u32(q + 16u + 4u * j, r_u32(p + 16u + 4u * j));
        w_u16(q + 32u, r_u16(p + 32u));
    }
    if (r_u32(object + 504u))
    {
        w_u32(object + 8u, (r_u32(object + 8u) & 0xFFFF0FFFu) | 0x6000u);
        w_u16(scratch, 70u);
        w_u16(scratch + 4u, 315u);
        draft_call_adapter(0x80031CC0u, scratch, object + 400u);
        w_u16(scratch, (uint16)-70);
        draft_call_adapter(0x80031CC0u, scratch, object + 436u);
        for (i = 0; i < 2u; ++i)
        {
            uint32 p = object + 416u + 36u * i;
            for (j = 0; j < 4u; ++j)
                w_u32(p + 4u * j, r_u32(object + 36u + 4u * j));
            w_u16(p + 16u, r_u16(object + 52u));
        }
        result = (uint32)(int32)(int16)r_u16(object + 52u);
    }
    else
    {
        result = (r_u32(object + 8u) & 0xFFFF0FFFu) | 0x4000u;
        w_u32(object + 8u, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002D348
uint32 sub_8002D348(uint32 object, uint32 first, uint32 other, uint32 second)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(272u), polygon = scratch, corners = scratch + 64u, contacts = scratch + 96u, velocity = scratch + 200u, extra = scratch + 224u;
    uint32 bound = sub_8002B6A8(other) + sub_8002B6A8(object), dy = r_u32(other + 24u) - r_u32(object + 24u), result, old_flags = r_u16(0x800A8704u), old_code = r_u16(0x800A8706u), x = r_u32(object + 20u), z = r_u32(object + 28u), mode, entry, i, bounce = 0u;
    if ((int32)dy < 0)
        dy = 0u - dy;
    result = (int32)bound < (int32)dy;
    if (result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    sub_8002A090(other, d03_model(other), corners);
    entry = 0x800B3484u + 20u * (uint32)(int32)(int16)first;
    mode = r_u8(entry + 12u);
    if (mode)
    {
        w_u16(contacts + 96u, 0u);
        w_u16(contacts + 98u, 0u);
        sub_80029EEC(object, d03_model(object), polygon);
        draft_call_adapter(0x80029D44u, polygon);
        for (i = 0; i < 3u; ++i)
        {
            xport_gte_write_control(2u * i, (uint32)((int16)r_u16(polygon + 8u + 2u * i) - (int16)r_u16(polygon + 2u * i)));
            xport_gte_write_data(9u + i, r_u32(extra + 4u * i));
        }
        draft_gte_command_adapter(0x170000Cu);
        for (i = 0; i < 3u; ++i)
            w_u32(extra + 4u * i, xport_gte_read_data(25u + i));
        sub_8002B93C(contacts, entry, object + 20u, other + 20u, polygon, corners);
        result = (uint32)(int32)(int16)r_u16(contacts + 98u);
    }
    else
    {
        w_u16(0x800A8706u, 0u);
        sub_8002B93C(0x800A86A4u, object + 244u, object + 20u, other + 20u, object + 160u, corners);
        result = (uint32)(int32)(int16)r_u16(0x800A8706u);
    }
    if (result)
    {
        draft_call_adapter(r_u32(r_u32(object + 16u) + 4u), object, velocity);
        draft_call_adapter(r_u32(r_u32(other + 16u) + 24u), other, velocity);
        w_u16(other + 56u, 11u);
        entry = 0x800B3484u + 20u * (uint32)(int32)(int16)second;
        if (r_u8(entry + 12u) == 7u)
        {
            if (d03_call(0x80069BE0u, r_u32(velocity), r_u32(velocity + 8u), 0u, 0u) <= 0x3BFFFFu || r_u16(entry + 14u) == 1u)
            {
                bounce = 1u;
                w_u32(velocity, 0u - (uint32)((int32)r_u32(velocity) >> 1));
                w_u32(velocity + 8u, 0u - (uint32)((int32)r_u32(velocity + 8u) >> 1));
            }
            if (r_u32(0x800A9760u))
                bounce = 0u;
            result = mode < 2u;
            if (mode == 1u)
            {
                if (bounce)
                    result = sub_8002B224(object, 0u, r_u16(contacts + 96u), velocity, extra, 0x8002E0B4u);
            }
            else
            {
                result = mode >= 2u ? 1u : 2u;
                if (mode == 2u)
                {
                    w_u8(object + 88u, 1u);
                    w_u16(object + 114u, (uint16)((3u * (r_u32(0x800A63D8u) >> 8)) >> 7));
                    result = 0u - (uint32)(int32)(int8)r_u8(object + 87u);
                    w_u8(object + 87u, (uint8)result);
                }
                if (bounce)
                    result = (uint32)draft_call_adapter(r_u32(r_u32(object + 16u) + 24u), object, velocity);
            }
        }
        else
        {
            uint32 moved_x = r_u32(object + 20u), moved_z = r_u32(object + 28u);
            w_u32(object + 20u, x);
            w_u32(object + 28u, z);
            w_u32(other + 20u, r_u32(other + 20u) + x - moved_x);
            result = r_u32(other + 28u);
            w_u32(other + 28u, result + z - moved_z);
        }
    }
    w_u16(0x800A8706u, (uint16)old_code);
    w_u16(0x800A8704u, (uint16)old_flags);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800784F4
uint32 sub_800784F4(uint32 text, uint32 top, uint32 baseline)
{
    uint32 native_stack_mark = draft_scratch_mark();

    // Keep the eight-byte RECT beside the complete 92-byte DRAWENV
    uint32 scratch = draft_scratch_adapter(100u), cursor, ot, result, index = 0u, glyph, control, width;
    int32 x = -144;
    uint16 y = (uint16)baseline;
    if ((int32)r_u32(0x800A84E0u) >= 2048)
        w_u32(0x800A84E0u, 2048u);
    else
    {
        int32 value = d03_trig(0x800102E0u, r_u32(0x800A84E0u));
        if (value >= 4001)
            value = 4000;
        w_u32(0x800A8200u, (uint32)value);
    }
    w_u32(0x800A84E0u, 1024u);
    draft_call_adapter(0x80080800u, scratch + 8u);
    w_u32(scratch, r_u32(scratch + 8u) ^ 0x01000000u);
    w_u32(scratch + 4u, r_u32(scratch + 12u));
    cursor = r_u32(0x800A865Cu);
    w_u32(0x800A7AB4u, cursor);
    draft_call_adapter(0x80080D84u, cursor, scratch);
    ot = r_u32(0x800A9A74u);
    w_u32(cursor, (r_u32(cursor) & 0xFF000000u) | (r_u32(ot + 580u) & 0xFFFFFFu));
    w_u32(ot + 580u, (r_u32(ot + 580u) & 0xFF000000u) | (cursor & 0xFFFFFFu));
    w_u32(0x800A7AB4u, cursor + 12u);
    w_u32(0x800A865Cu, cursor + 12u);
    w_u32(scratch, r_u32(scratch + 8u));
    w_u32(scratch + 4u, r_u32(scratch + 12u));
    draft_call_adapter(0x80077AC0u, text, 1u, 2u, 210u);
    w_u32(0x800A9D64u, 304u);
    do
    {
        glyph = r_u8(0x800BC4FCu + index);
        control = 0u;
        if (!glyph)
        {
            ++index;
            control = 1u;
        }
        if (glyph == 1u)
        {
            x = (int32)r_u8(0x800BC4FDu + index) - 160;
            index += 2u;
            control = 1u;
        }
        if (glyph == 2u)
        {
            ++index;
            control = 1u;
            width = r_u32(0x800A9D64u);
            x = ((int32)((width > 0u) - width) >> 1) + 16;
        }
        if (glyph == 3u)
        {
            x = 144 - (int32)r_u8(0x800BC4FDu + index);
            index += 2u;
            control = 1u;
        }
        if (glyph == 32u)
        {
            ++index;
            control = 1u;
            x += (int32)r_u8(r_u32(0x800A5F68u) + 2u);
        }
        if (glyph == 10u)
        {
            y += 13u;
            ++index;
            x = -144;
            control = 1u;
        }
        if (!control)
        {
            w_u32(0x800A9A70u, 0u);
            sub_800782D8(glyph, (uint32)x, (uint32)(int32)(int16)y, 150u, 0u);
            ++index;
            x += r_u8(r_u32(0x800A5F68u) + 5u * glyph + 2u);
        }
    } while (glyph);
    w_u32(0x800A8664u, 218u);
    w_u16(scratch + 4u, 304u);
    width = r_u32(0x800A9D64u);
    w_u16(scratch, (uint16)(((int32)((width > 0u) - width) >> 1) + 160));
    w_u16(scratch + 2u, (r_u16(scratch + 2u) ^ 256u) + (uint16)top + 136u);
    w_u16(scratch + 6u, r_u32(0x800A9D68u) - 20u);
    cursor = r_u32(0x800A865Cu);
    w_u32(0x800A7AB4u, cursor);
    draft_call_adapter(0x80080D84u, cursor, scratch);
    ot = r_u32(0x800A9A74u);
    w_u32(cursor, (r_u32(cursor) & 0xFF000000u) | (r_u32(ot + 600u) & 0xFFFFFFu));
    result = (r_u32(ot + 600u) & 0xFF000000u) | (cursor & 0xFFFFFFu);
    w_u32(ot + 600u, result);
    w_u32(0x800A7AB4u, cursor + 12u);
    w_u32(0x800A865Cu, cursor + 12u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

static int32 d03_mul(int32 a, int32 b)
{
    return (int32)((uint32)a * (uint32)b);
}

static int32 d03_abs(int32 value)
{
    return value < 0 ? (int32)(0u - (uint32)value) : value;
}

static int32 d03_clamp(int32 value, int32 limit)
{
    if (value > limit)
        value = limit;
    if (value < -limit)
        value = -limit;
    return value;
}

// FUNCTION_MARKER sub_80025924
uint32 sub_80025924(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 step = d03_div(r_u32(0x800A63D8u), (uint32)((int32)r_u32(0x800A56C0u) / 5));
    int32 speed = (int32)r_u32(object + 472u), quarter = speed >> 2, steer = 0, pitch = 0, roll = 0;
    int32 cos_heading, sin_heading, cos_steer, sin_steer, sin_front, sin_rear, slope, energy, front_load, rear_load, transfer, front_total, rear_total;
    int32 front_drag, rear_drag, front_lateral, rear_lateral, front_limit, rear_limit, front_brake = 0, rear_brake = 0, fx = 0, fz = 0, rx = 0, rz = 0;
    int32 damping, coefficient, front_grip, rear_grip, old_x = (int32)r_u32(object + 476u), old_z = (int32)r_u32(object + 480u), value, x, z, y, yaw, angle;
    uint32 kind = r_u8(object + 67u), heading = r_u16(object + 560u), terrain = r_u32(0x800A575Cu), i, result, model;
    if (kind < 4u)
        steer = (int16)r_u16(object + 562u);
    cos_heading = 16 * d03_trig(0x80010AE0u, heading);
    sin_heading = 16 * d03_trig(0x800102E0u, heading);
    cos_steer = 16 * d03_trig(0x80010AE0u, heading + (uint32)steer);
    sin_steer = 16 * d03_trig(0x800102E0u, heading + (uint32)steer);
    sin_front = d03_trig(0x800102E0u, r_u16(object + 564u));
    sin_rear = d03_trig(0x800102E0u, r_u16(object + 566u));
    if ((!kind || kind == 3u || kind == 6u || kind == 12u || kind == 9u) && !r_u8(object + 154u))
    {
        pitch = (int16)r_u16(object + 80u);
        roll = (int16)r_u16(object + 84u);
        if (d03_abs(pitch) >= 64)
            pitch = pitch < 0 ? -64 : 64;
        if (d03_abs(roll) >= 64)
            roll = roll < 0 ? -64 : 64;
    }
    draft_call_adapter(0x80024B28u, object);
    slope = d03_mul(d03_trig(0x80010AE0u, (uint32)pitch) >> 4, d03_trig(0x80010AE0u, (uint32)roll) >> 4);
    energy = d03_mul(d03_mul(589, speed >> 8) >> 16, speed >> 8) >> 1;
    front_load = d03_div((uint32)d03_mul(energy, (int32)r_u32(object + 524u)), r_u32(object + 508u));
    rear_load = d03_div((uint32)d03_mul(energy, (int32)r_u32(object + 528u)), r_u32(object + 508u));
    model = r_u32(0x800A9750u) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
    transfer = d03_div((uint32)d03_mul((int16)r_u16(model + 32u) >> 1, (int32)r_u32(object + 536u)), r_u32(object + 508u));
    front_total = d03_div((uint32)d03_mul(d03_mul(slope >> 8, 2511), (int32)r_u32(object + 524u)), r_u32(object + 508u)) + transfer + rear_load;
    rear_total = d03_div((uint32)d03_mul(d03_mul(slope >> 8, 2511), (int32)r_u32(object + 528u)), r_u32(object + 508u)) + front_load - transfer;
    front_drag = 15 * (front_total >> 8) + (int32)r_u32(object + 504u);
    rear_drag = 15 * (rear_total >> 8) + (int32)r_u32(object + 504u);
    value = r_u32(0x800A9760u) ? 1 : (int16)draft_call_adapter(0x8003D688u);
    w_u32(0x800A5698u, (uint32)value);
    for (i = 0; i < 4u; ++i)
    {
        uint32 byte = r_u8(0x800A6BA0u + i);
        if (byte < 10u)
            terrain = (terrain & ~(255u << (8u * i))) | (byte << (8u * i));
    }
    if ((int16)r_u16(object + 594u) <= 0 || speed < 16385)
    {
        front_grip = (int32)(r_u32(0x800A56E0u + 4u * (terrain & 255u)) + r_u32(0x800A56E0u + 4u * ((terrain >> 8) & 255u))) >> 1;
        rear_grip = (int32)(r_u32(0x800A56E0u + 4u * ((terrain >> 16) & 255u)) + r_u32(0x800A56E0u + 4u * (terrain >> 24))) >> 1;
    }
    else
    {
        int32 a = r_u8(object + 584u) ? 8192 : (int32)r_u32(0x800A56E0u + 4u * (terrain & 255u));
        int32 b = r_u8(object + 585u) ? 8192 : (int32)r_u32(0x800A56E0u + 4u * ((terrain >> 8) & 255u));
        int32 c = r_u8(object + 586u) ? 8192 : (int32)r_u32(0x800A56E0u + 4u * ((terrain >> 16) & 255u));
        int32 d = r_u8(object + 587u) ? 8192 : (int32)r_u32(0x800A56E0u + 4u * (terrain >> 24));
        front_grip = (a + b) / 2;
        rear_grip = (c + d) / 2;
    }
    coefficient = (int32)r_u32(0x800A56D4u + 4u * (uint32)value) >> 8;
    damping = d03_mul(d03_mul(rear_grip >> 8, coefficient) >> 8, rear_total >> 8);
    rear_lateral = d03_mul(sin_rear >> 4, damping >> 8);
    rear_limit = d03_abs(d03_mul(d03_trig(0x80010AE0u, r_u16(object + 566u)) >> 4, damping >> 8));
    value = d03_mul(d03_mul(front_grip >> 8, coefficient) >> 8, front_total >> 8) >> 8;
    front_lateral = d03_mul(sin_front >> 4, value);
    front_limit = d03_abs(d03_mul(d03_trig(0x80010AE0u, r_u16(object + 564u)) >> 4, value));
    if ((int16)r_u16(object + 594u) <= 0)
    {
        w_u16(object + 594u, 0u);
        for (i = 0; i < 4u; ++i)
            w_u8(object + 584u + i, 0u);
    }
    else
        w_u16(object + 594u, r_u16(object + 594u) - r_u16(0x800A63DAu));
    if (d03_trig(0x80010AE0u, r_u16(object + 564u)) >= 0)
        front_drag = -front_drag;
    if (d03_trig(0x80010AE0u, r_u16(object + 566u)) >= 0)
        rear_drag = -rear_drag;
    if (!r_u32(object + 504u))
    {
        int32 distribution = (int32)r_u32(object + 548u);
        value = (d03_mul(d03_mul(2511, slope >> 8) >> 8, (int16)r_u16(0x80010AE0u + 2u * ((uint32)pitch & 4095u) - 2048u) >> 4) + (int32)r_u32(object + 484u)) >> 8;
        front_brake = d03_mul(distribution >> 8, value);
        rear_brake = d03_mul((65536 - distribution) >> 8, value);
        if (d03_abs(front_brake) < 3000)
            front_brake = 0;
        if (d03_abs(rear_brake) < 3000)
            rear_brake = 0;
    }
    front_brake = d03_clamp(front_brake, front_limit);
    rear_brake = d03_clamp(rear_brake, rear_limit);
    if (kind == 15u)
    {
        front_brake = 0;
        front_lateral = 0;
        front_drag = 0;
        rear_brake = 0;
        rear_lateral = 0;
        rear_drag = 0;
    }
    if (speed <= 0x3FFFF)
    {
        rear_lateral = d03_mul(quarter >> 8, rear_lateral >> 8);
        front_lateral = d03_mul(quarter >> 8, front_lateral >> 8);
        front_drag = d03_mul(quarter >> 8, front_drag >> 8);
        rear_drag = d03_mul(quarter >> 8, rear_drag >> 8);
    }
    if (r_u16(object + 592u))
    {
        front_brake = 0;
        rear_brake = 0;
        w_u32(object + 520u, !r_u32(object + 504u) && r_u16(object + 32u) == r_u16(r_u32(0x800A62ECu) + 26u) ? 32u * (uint32)(int32)(int16)r_u16(object + 562u) : 0u);
        if (r_u16(0x800A6C04u))
        {
            uint32 sound = speed > 1820400 ? 25u : speed > 1456320 ? 23u : speed > 910200 ? 48u : 0u;
            if (sound)
                draft_call_adapter(0x80035A08u, sound, 2048u, 128u, 0u);
            sub_80023C20(object, 0x800A6BA4u, (uint32)old_x, (uint32)old_z, 0x4000u, 4096u);
        }
        if (r_u16(0x800A8704u))
            sub_800245AC(object, 0x800A86A4u, (uint32)old_x, (uint32)old_z);
        if (r_u16(0x800A6C04u) || r_u16(0x800A8704u))
        {
            value = d03_mul((int32)(0x10000u - r_u32(0x800A56A8u)) >> 8, (int32)r_u32(object + 472u) >> 8);
            w_u16(object + 574u, 0u);
            w_u16(object + 572u, (uint16)((uint32)value >> 16));
        }
    }
    else
    {
        rx = d03_mul(rear_lateral >> 8, cos_steer >> 8) + d03_mul((rear_brake + rear_drag) >> 8, sin_steer >> 8);
        rz = d03_mul((rear_brake + rear_drag) >> 8, cos_steer >> 8) - d03_mul(rear_lateral >> 8, sin_steer >> 8);
        fx = d03_mul(front_lateral >> 8, cos_heading >> 8) + d03_mul((front_brake + front_drag) >> 8, sin_heading >> 8);
        fz = d03_mul((front_brake + front_drag) >> 8, cos_heading >> 8) - d03_mul(front_lateral >> 8, sin_heading >> 8);
        w_u32(object + 476u, r_u32(object + 476u) + (uint32)d03_mul((rx + fx) >> 8, step >> 8));
        w_u32(object + 480u, r_u32(object + 480u) + (uint32)d03_mul((rz + fz) >> 8, step >> 8));
    }
    if ((int32)r_u32(object + 472u) >= 0x4000 || d03_abs(rear_drag) + d03_abs(front_drag) < d03_abs(front_brake) + d03_abs(rear_brake))
    {
        value = d03_mul(d03_mul(rx >> 8, cos_heading >> 8) - d03_mul(rz >> 8, sin_heading >> 8), (int32)r_u32(object + 524u)) - d03_mul(d03_mul(fx >> 8, cos_heading >> 8) - d03_mul(fz >> 8, sin_heading >> 8), (int32)r_u32(object + 528u));
        yaw = d03_mul(d03_div((uint32)value, r_u32(object + 512u)) >> 8, step >> 8) >> 1;
        yaw += (int32)r_u32(object + 520u);
        w_u32(object + 520u, (uint32)yaw);
        if (!r_u32(object + 484u) && !r_u32(object + 504u))
        {
            if (yaw > 20000)
                w_u32(object + 520u, 20000u);
            if (yaw < -20000)
                w_u32(object + 520u, (uint32)-20000);
        }
    }
    else
    {
        w_u32(object + 520u, !r_u32(object + 504u) && r_u16(object + 32u) == r_u16(r_u32(0x800A62ECu) + 26u) ? 32u * (uint32)(int32)(int16)r_u16(object + 562u) : 0u);
        w_u32(object + 476u, 0u);
        w_u32(object + 480u, 0u);
    }
    angle = d03_mul((int32)r_u32(object + 520u) >> 8, step >> 8) + (int32)r_u32(object + 516u);
    w_u32(object + 516u, (uint32)angle);
    if (angle > 205886)
        w_u32(object + 516u, (uint32)(angle - 411775));
    angle = (int32)r_u32(object + 516u);
    if (angle < -205887)
        w_u32(object + 516u, (uint32)(angle + 411775));
    value = d03_div((uint32)d03_mul((int32)r_u32(object + 520u), (int32)r_u32(object + 524u)), 136u) >> 8;
    x = (d03_mul(value, cos_heading >> 8) + (int32)r_u32(object + 476u)) >> 8;
    z = ((int32)r_u32(object + 480u) - d03_mul(value, sin_heading >> 8)) >> 8;
    w_u16(object + 560u, (uint16)((163u * r_u32(object + 516u)) >> 14));
    w_u16(object + 568u, (uint16)sub_80055A9C((uint32)x, (uint32)z));
    if (!x && !z)
        w_u16(object + 568u, r_u16(object + 560u));
    value = d03_div((uint32)d03_mul((int32)r_u32(object + 520u), (int32)r_u32(object + 528u)), 136u) >> 8;
    x = ((int32)r_u32(object + 476u) - d03_mul(value, cos_heading >> 8)) >> 8;
    z = (d03_mul(value, sin_heading >> 8) + (int32)r_u32(object + 480u)) >> 8;
    w_u16(object + 570u, (uint16)sub_80055A9C((uint32)x, (uint32)z));
    if (!x && !z)
        w_u16(object + 570u, r_u16(object + 560u));
    w_u16(object + 564u, r_u16(object + 560u) - r_u16(object + 570u));
    w_u16(object + 566u, r_u16(object + 560u) - r_u16(object + 568u) + (uint16)steer);
    w_u32(object + 472u, d03_call(0x80069BE0u, (uint32)((int32)r_u32(object + 476u) >> 8), (uint32)((int32)r_u32(object + 480u) >> 8), 0u, 0u) << 8);
    w_u32(object + 496u, r_u32(object + 480u));
    w_u32(object + 488u, r_u32(object + 476u));
    z = (int32)r_u32(object + 496u) >> 8;
    w_u32(object + 496u, (uint32)d03_mul(z, d03_trig(0x80010AE0u, (uint32)pitch) >> 4));
    y = d03_mul(z, d03_trig(0x800102E0u, (uint32)pitch) >> 4);
    w_u32(object + 492u, (uint32)y);
    x = (int32)r_u32(object + 488u) >> 8;
    w_u32(object + 488u, (uint32)(d03_mul(x, d03_trig(0x80010AE0u, (uint32)roll) >> 4) - d03_mul(y >> 8, d03_trig(0x800102E0u, (uint32)roll) >> 4)));
    w_u32(object + 492u, (uint32)(d03_mul(x, d03_trig(0x800102E0u, (uint32)roll) >> 4) + d03_mul(y >> 8, d03_trig(0x80010AE0u, (uint32)roll) >> 4)));
    x = ((int32)(r_u32(object + 476u) - (uint32)old_x)) >> 8;
    z = ((int32)(r_u32(object + 480u) - (uint32)old_z)) >> 8;
    w_u32(object + 532u, (uint32)(d03_mul(x, cos_heading >> 8) - d03_mul(z, sin_heading >> 8)));
    w_u32(object + 536u, 4u * (uint32)(d03_mul(x, sin_heading >> 8) + d03_mul(z, cos_heading >> 8)));
    w_u32(object + 232u, r_u32(object + 232u) - (uint32)(d03_mul(27, d03_mul((int32)r_u32(object + 488u) >> 8, step >> 8)) >> 16));
    w_u32(object + 240u, r_u32(object + 240u) - (uint32)(d03_mul(d03_mul(27, (int32)r_u32(object + 496u) >> 8), step >> 8) >> 16));
    if ((int32)r_u32(object + 472u) > 99999)
        result = r_u16(object + 570u);
    else
    {
        w_u32(object + 536u, (uint32)d03_mul(quarter >> 10, (int32)r_u32(object + 536u) >> 8));
        w_u32(object + 532u, (uint32)d03_mul(quarter >> 10, (int32)r_u32(object + 532u) >> 8));
        w_u16(0x800A632Cu, r_u16(object + 560u));
        result = r_u32(object + 504u);
        if (!result)
            return draft_scratch_result(native_stack_mark, (uint64)(result));
        result = r_u16(object + 560u);
    }
    w_u16(0x800A632Cu, (uint16)result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
