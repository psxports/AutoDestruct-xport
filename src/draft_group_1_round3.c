#include "psx.h"
#include "draft_signatures.h"
#include "draft_adapters.h"
#include <stdlib.h>

static sint32 draft_r3_abs(sint32 x)
{
    return x < 0 ? -x : x;
}

/* FUNCTION_MARKER sub_800628E4 */
uint32 sub_800628E4(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 tick = (sint32)r_u32(0x800A9010), result;
    uint32 local = draft_scratch_adapter(24);
    w_u16(object + 54, r_u16(object + 54) - tick);
    if ((sint16)r_u16(object + 54) < 0)
        return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(object)));
    for (uint32 i = 0; i < 3; ++i)
        w_u32(local + 8 + i * 4, r_u32(object + 20 + i * 4));
    w_u16(local, r_u16(object + 8));
    w_u16(local + 2, r_u16(object + 10));
    sub_80055288(local, object + 36);
    w_u16(object + 10, r_u16(object + 10) + tick * r_u16(object + 16));
    w_u16(object + 8, r_u16(object + 8) + tick * (sint8)r_u8(object + 13));
    w_u32(object + 20, r_u32(object + 20) + tick * (sint16)r_u16(object + 18));
    w_u32(object + 24, r_u32(object + 24) - tick * (sint16)r_u16(object + 56));
    w_u32(object + 28, r_u32(object + 28) + tick * (sint16)r_u16(object + 58));
    if ((sub_80030678(local + 8, object + 20) & 0xFFFF) != 0)
    {
        sint32 v = (sint8)r_u8(object + 13);
        w_u8(object + 13, v == -1 ? 0 : v >> 1);
        const uint32 offsets[3] = {16, 18, 58};
        for (uint32 i = 0; i < 3; ++i)
        {
            v = (sint16)r_u16(object + offsets[i]);
            w_u16(object + offsets[i], v == -1 ? 0 : v >> 1);
        }
        v = -((sint16)r_u16(object + 56) >> 1);
        w_u16(object + 56, v);
        if (v < tick)
            return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(object)));
    }
    result = r_u16(object + 56) - tick;
    w_u16(object + 56, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_80057FFC */
uint32 sub_80057FFC(uint32 index, uint32 enabled, uint32 current, uint32 maximum)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 gauge = (uint32)-2146799448 + index * 24, result = 1;
    sint32 tick = (sint32)r_u32(0x800A9010);
    if (!r_u32(gauge + 12))
        w_u32(gauge + 12, current);
    if (((sint32)current < (sint32)r_u32(gauge + 12) && enabled == 1) || (sint32)maximum >= (sint32)current)
    {
        w_u32(gauge, 1);
        w_u32(gauge + 16, 1);
    }
    if ((sint32)r_u32(gauge + 12) < (sint32)current)
    {
        w_u32(gauge, 1);
        w_u32(gauge + 16, 256);
    }
    if (r_u32(gauge) == 1)
    {
        if (!r_u32(gauge + 4))
        {
            sint32 value = r_u32(gauge + 8) + 10 * r_u32(gauge + 16) * tick;
            w_u32(gauge + 8, value);
            if (value >= (sint32)(r_u32(gauge + 16) << 7))
            {
                w_u32(gauge + 4, 1);
                w_u32(gauge + 8, r_u32(gauge + 16) << 7);
                if ((sint32)maximum < (sint32)current)
                    w_u32(gauge + 20, 0);
                else if ((sint32)r_u32(gauge + 20) < 11)
                {
                    w_u32(gauge + 20, r_u32(gauge + 20) + 1);
                    /* TODO Original sound boundary 80035A08 */
                    draft_call_adapter(0x80035A08, 0, 2048, 255, 0);
                }
            }
        }
        if (r_u32(gauge + 4) == 1)
        {
            result = r_u32(gauge + 8) - 10 * r_u32(gauge + 16) * tick;
            w_u32(gauge + 8, result);
            if ((sint32)result <= (sint32)r_u32(gauge + 16))
            {
                result = r_u32(gauge + 16);
                w_u32(gauge + 4, 0);
                w_u32(gauge, 0);
                w_u32(gauge + 16, 0);
                w_u32(gauge + 12, current);
                w_u32(gauge + 8, result);
            }
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_8005C31C */
uint32 sub_8005C31C(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 button = r_u32(0x800A7C74), choice = r_u8(object + 47), secondary = r_u8(object + 48);
    if (!(sub_80037BB8() & 65535) || (sint16)sub_80037BB8() == 3)
    {
        if ((button & 4) && ((choice < 3 && !secondary) || (secondary && !choice)))
        {
            w_u8(object + 45, 255);
            ++choice;
            w_u8(object + 47, choice);
            w_u8(object + 44, choice);
            if (secondary)
                w_u8(object + 50, choice);
            return draft_scratch_result(native_stack_mark, (uint64)(1));
        }
        if ((button & 1) && ((choice && !secondary) || (secondary && choice < 2 && choice)))
        {
            w_u8(object + 45, 255);
            --choice;
            w_u8(object + 47, choice);
            if (secondary)
                w_u8(object + 50, choice);
            return draft_scratch_result(native_stack_mark, (uint64)(1));
        }
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    }
    if ((sint16)sub_80037BB8() != 2 || !(button & 4))
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    if (choice >= 4 || secondary)
    {
        if (!secondary || choice >= 2)
            return draft_scratch_result(native_stack_mark, (uint64)(0));
    }
    ++choice;
    w_u8(object + 47, choice);
    uint32 update = 1;
    if (choice == 4)
    {
        choice = 0;
        w_u8(object + 47, 0);
        w_u16(object + 38, 10000);
        update = 0;
    }
    if (choice == 2 && secondary)
    {
        choice = 0;
        w_u8(object + 47, 0);
        update = 0;
    }
    if (update)
        w_u8(object + 44, choice);
    if (secondary)
        w_u8(object + 50, choice);
    return draft_scratch_result(native_stack_mark, (uint64)(1));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_80063654 */
uint32 sub_80063654(uint32 matrix, uint32 positions, uint32 angle, uint32 resource)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 y0 = r_u32(positions + 4), y1 = r_u32(positions + 16), y2 = r_u32(positions + 28), extra = r_u32(positions + 40);
    sint32 span = (sint16)r_u16(resource + 36), center;
    uint32 changed = 0;
    sint16 pitch = -(sint16)sub_80055A9C(y0 - y1, span), roll;
    if (draft_r3_abs(pitch) < 513)
        center = (y0 + y1) >> 1;
    else
    {
        sint32 delta = y0 - extra;
        if (draft_r3_abs(extra - y1) < draft_r3_abs(extra - y0))
            delta = extra - y1;
        changed = 1;
        pitch = sub_80055A9C(delta, span);
        center = extra;
    }
    span = (sint16)r_u16(resource + 34);
    roll = -(sint16)sub_80055A9C(center - y2, span);
    if (draft_r3_abs(roll) >= 513)
    {
        sint32 delta = extra - y2;
        if (draft_r3_abs(delta) >= draft_r3_abs(extra - center))
            delta = center - extra;
        changed = 1;
        roll = -(sint16)sub_80055A9C(delta, span);
    }
    /* TODO Original matrix boundary 80054D38 */
    draft_call_adapter(0x80054D38, (sint32)roll, (sint32)(sint16)angle, (sint32)pitch, matrix);
    return draft_scratch_result(native_stack_mark, (uint64)(changed));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_800440E0 */
uint32 sub_800440E0(uint32 first, uint32 second, uint32 yoffset)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 start = 2, end = 4;
    if ((sint16)sub_80037BB8() == 2)
    {
        start = 7;
        end = 9;
        if (!second)
        {
            start = 11;
            end = 13;
        }
        if (!first && !second)
        {
            start = 8;
            end = 9;
        }
        if (r_s16(0x800A967C) == 1)
        {
            start = 4;
            end = 7;
            if (!first && !second)
            {
                start = 13;
                end = 15;
            }
        }
    }
    else
    {
        if (!second)
        {
            start = 9;
            end = 11;
        }
        if (r_s16(0x800A967C) == 1)
        {
            start = 0;
            end = 2;
            if (!first)
                start = !second;
        }
    }
    for (uint32 row = start; row < end; ++row)
    {
        uint32 offset = row * 12;
        uint32 text = r_u32(0x800909D0 + offset);
        uint32 x = r_u8(0x800909D8 + offset);
        uint32 y = r_u8(0x800909D9 + offset) + yoffset;
        sub_800436D4(8421504, text, x, (uint32)(sint32)(sint16)y, 10);
        y = r_u8(0x800909D9 + offset);
        uint32 index = r_u32(0x800909D4 + offset);
        x = r_u8(0x800909DA + offset);
        text = r_u32(0x800A8B38 + 4 * index);
        sub_800436D4(8421504, text, x, (uint32)(sint32)(sint16)(y + yoffset), 10);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_8003AF20 */
uint32 sub_8003AF20(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    const uint32 gp = 0x800A5628;
    uint32 countdown = r_u32(gp + 0x17CC);
    if (countdown)
        w_u32(gp + 0x17CC, countdown - 1);
    else if (!r_u32(gp + 0x17C0) && r_s16(gp + 0x4054) == 1 && !r_u32(gp + 0x4138))
        return draft_scratch_result(native_stack_mark, (uint64)(11));
    /* TODO Original menu service boundaries */
    if (!r_u32(gp + 0x17C0) && r_u32(gp + 0x3508) == 1)
        draft_call_adapter(0x80042598);
    if (r_u32(gp + 0x4058) == 1 && (sint32)draft_call_adapter(0x8003AC24) == -1)
        return draft_scratch_result(native_stack_mark, (uint64)(4));
    if (r_u32(0x800A84DC) == 1 && (sint32)draft_call_adapter(0x8003AC84) == -1)
        return draft_scratch_result(native_stack_mark, (uint64)(3));
    if (r_u32(gp + 0x474C) == 1)
    {
        if (r_u32(gp + 0x2E78) == 1)
            return draft_scratch_result(native_stack_mark, (uint64)(30));
        if ((sint32)draft_call_adapter(0x8003ACE4) == -1)
            return draft_scratch_result(native_stack_mark, (uint64)(2));
    }
    if (!r_u32(gp + 0x17C0))
    {
        uint32 selection = draft_call_adapter(0x8003ABE4);
        w_u32(gp + 0x1830, selection);
        if (selection)
        {
            if (selection - 2 < 2 && r_u32(gp + 0x2E78) == 1)
                return draft_scratch_result(native_stack_mark, (uint64)(31));
            w_u32(gp + 0x17E4, 1);
            w_u32(gp + 0x17C0, 1);
        }
    }
    uint32 stopped = r_u32(gp + 0x17C0);
    if (stopped == 1)
    {
        uint32 counter = r_u32(gp + 0x17E4);
        if (counter)
        {
            sint32 delay = (sint32)(counter + 1);
            w_u32(gp + 0x17E4, delay);
            if (delay >= 3)
            {
                uint32 selection = r_u32(gp + 0x1830);
                if (selection == 3)
                {
                    w_u32(gp + 0x1820, 4);
                    return draft_scratch_result(native_stack_mark, (uint64)(6));
                }
                if (selection == 2)
                {
                    w_u32(gp + 0x1820, 2);
                    return draft_scratch_result(native_stack_mark, (uint64)(6));
                }
                if (selection == stopped)
                {
                    w_u32(gp + 0x1820, 3);
                    return draft_scratch_result(native_stack_mark, (uint64)(5));
                }
            }
        }
    }
    if (!r_u32(gp + 0x17C0) && (sint32)draft_call_adapter(0x8003B3B0) == -1)
    {
        w_u32(gp + 0x17C0, 1);
        w_u32(gp + 0x17E8, 1);
    }
    if (r_u32(gp + 0x17C0) == 1)
    {
        uint32 counter = r_u32(gp + 0x17E8);
        if (counter)
        {
            sint32 delay = (sint32)(counter + 1);
            w_u32(gp + 0x17E8, delay);
            if (delay >= 3)
            {
                w_u32(gp + 0x17C0, 0);
                w_u32(gp + 0x17E8, 0);
                w_u16(gp + 0x4054, 0);
                return draft_scratch_result(native_stack_mark, (uint64)(9));
            }
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_8006268C */
uint32 sub_8006268C(uint32 position, uint32 transform, uint32 rotated, uint32 resource, uint32 life, uint32 force, uint32 count)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = force, vector = draft_scratch_adapter(8);
    sint32 scale = (sint32)force >> 8;
    for (sint32 remaining = (sint16)count; remaining > 0; --remaining)
    {
        /* TODO Original allocation boundary 800226E4 */
        uint32 object = draft_call_adapter(0x800226E4, 60);
        for (uint32 i = 0; i < 3; ++i)
            w_u32(object + 20 + i * 4, r_u32(position + i * 4));
        w_u16(object + 32, resource);
        w_u16(object + 54, life);
        w_u8(object + 14, r_u8(object + 14) | 2);
        w_u8(object + 34, 11);
        w_u32(object, 0x800628E4);
        w_u16(object + 8, sub_80069A50());
        w_u16(object + 10, sub_80069A50());
        w_u8(object + 13, sub_80069A50() - 127);
        w_u16(object + 16, (uint8)sub_80069A50() - 127);
        sint32 x = (sub_80069A50() & 31) - 15, y = (sub_80069A50() & 31) + ((rotated & 65535) ? 15 : 7), z = (sub_80069A50() & 31) - 15;
        w_u16(vector, ((uint32)(x * 256 * scale)) >> 16);
        w_u16(vector + 2, ((uint32)(y * 256 * scale)) >> 16);
        w_u16(vector + 4, ((uint32)(z * 256 * scale)) >> 16);
        if (rotated & 65535)
        {
            if (transform)
                sub_8005EE38(vector, transform);
            w_u16(object + 18, r_u16(vector));
            w_u16(object + 56, r_u16(vector + 2));
            result = r_u16(vector + 4);
        }
        else
        {
            w_u16(object + 18, r_u16(vector));
            w_u16(object + 56, r_u16(vector + 2));
            result = (z * 256 * scale) >> 16;
        }
        w_u16(object + 58, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_80066380 */
uint32 sub_80066380(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    if (r_u8(object + 12) < 4)
        return draft_scratch_result(native_stack_mark, (uint64)(1));
    /* TODO Original effect and sound boundaries */
    if (r_u16(object + 56))
    {
        uint32 child = r_u32(object + 8);
        draft_call_adapter(0x80060B84, object, 0, 128, 98304, 9);
        sub_8006268C(object + 20, 0, 0, (sint16)r_u16(r_u32(0x800A62EC) + 76), 160, 114688, 15);
        draft_call_adapter(0x800665E0, object, object + 60);
        sub_800652C0(child);
        w_u16(object + 58, 0);
        draft_call_adapter(0x80035A08, 63, 1024, 255, object + 20);
        draft_call_adapter(0x80035A08, 61, 1536, 255, object + 20);
        draft_call_adapter(0x80035A08, 13, 2048, 255, object + 20);
        draft_call_adapter(0x80035A08, 14, 2048, 128, object + 20);
        draft_call_adapter(0x8006108C, object);
        draft_call_adapter(0x8005F69C, object);
        return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(object)));
    }
    uint32 position_x = r_u32(object + 20);
    uint32 reference_x = r_u32(0x800A7E14);
    uint32 position_z = r_u32(object + 28);
    uint32 position_y = r_u32(object + 24);
    sint32 dx = (sint32)(position_x - reference_x);
    sint32 dz = (sint32)(position_z - r_u32(0x800A7E20));
    sint32 dy = (sint32)(position_y - r_u32(0x800A7E1C));
    sint32 distance = draft_call_adapter(0x80069BE0, dx, dz);
    uint32 angles = draft_scratch_adapter(8);
    w_u16(angles + 2, sub_80055A9C(dx, dz));
    uint32 pitch = 0 - (uint32)sub_80055A9C(dy, distance);
    w_u16(angles, pitch);
    w_u16(object + 60, pitch);
    uint32 yaw = r_u16(angles + 2);
    w_u16(object + 64, 0);
    w_u16(object + 62, yaw);
    sub_80055288(angles, object + 36);
    if (distance < 6500)
    {
        uint32 countdown = r_u16(object + 66);
        countdown -= r_u16(0x800A9010);
        w_u16(object + 66, countdown);
        if ((sint16)countdown < 0 && r_u32(0x800A9760) != 1)
        {
            if (!r_s16(0x800A9734))
                draft_call_adapter(0x8003E2F0, object, 22);
            w_u16(object + 66, 25);
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(draft_call_adapter(0x80029970, object, 0, 8, 0, object + 20)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_8006ED00 */
uint32 sub_8006ED00(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 kind = r_u8(object + 35), owner = r_u32(object + 16), out = draft_scratch_adapter(8), target, result;
    if (kind == 4)
    {
        target = sub_8006A258(r_u32(object + 8), out);
        if (r_u16(out) == 2)
            w_u16(out, 1);
        w_u16(out, r_u16(out) + 2);
        result = r_u16(out);
    }
    else
        result = target = sub_8006E6AC(owner, out);
    uint32 category = r_u16(out), state = r_u8(object + 34);
    /* TODO Original sound and interaction boundaries */
    switch (state)
    {
        case 0:
            if (!target)
                return draft_scratch_result(native_stack_mark, (uint64)(1));
            if (kind != 1 && !category)
                return draft_scratch_result(native_stack_mark, (uint64)(0));
            result = (sint32)sub_8006E748(0x800A7EE4, target + 20) < 12001;
            if (!result)
                return draft_scratch_result(native_stack_mark, (uint64)(result));
            for (uint32 i = 0; i < 3; ++i)
                w_u32(object + 20 + i * 4, r_u32(0x800A7EE4 + i * 4));
            w_u8(object + 14, r_u8(object + 14) | 2);
            sub_8006E7BC(object, target, (sint8)category);
            w_u8(object + 34, 1);
            uint32 sound = 0;
            if (r_u8(object + 13) == 1 || kind != 1)
            {
                sound = 27;
                draft_call_adapter(0x8006E7D8, object, r_u32(object + 16), 6, (sint16)category);
                draft_call_adapter(0x8006E7D8, object, r_u32(object + 16), 12, (sint16)category);
            }
            draft_call_adapter(0x80035A08, sound, 2048, 255, 0);
            return draft_scratch_result(native_stack_mark, (uint64)(sub_8006EA48(object)));
        case 1:
            return draft_scratch_result(native_stack_mark, (uint64)(sub_8006EA48(object)));
        case 2:
            if (r_u8(object + 13) != 1 && kind == 1)
                w_u32(0x800A7558, owner);
            else
            {
                draft_call_adapter(0x80035A08, 28, 2048, 255, 0);
                if (kind == 1)
                    w_u32(0x800A7558, owner);
            }
            w_u8(object + 34, 20);
            /* Fall through */
        case 20:
            if (owner == target || !target)
                return draft_scratch_result(native_stack_mark, (uint64)(sub_8006EB64(object, 0x800A7EE4, kind)));
            sint32 playerdistance = sub_8006E748(0x800A7EE4, target + 20), ownerdistance = sub_8006E748(owner + 20, target + 20);
            if (kind == 1)
            {
                if ((!r_u8(object + 13) && category == 1) || playerdistance < ownerdistance)
                    result = sub_8006E790(object);
                else
                {
                    w_u8(object + 34, 3);
                    w_u8(owner + 15, r_u8(owner + 15) - 1);
                    result = sub_8006E7BC(object, target, category);
                }
                w_u32(0x800A7558, 0);
                return draft_scratch_result(native_stack_mark, (uint64)(result));
            }
            if (category == 1 || kind == 4)
            {
                if (playerdistance >= ownerdistance)
                {
                    w_u8(object + 34, 3);
                    w_u8(owner + 15, r_u8(owner + 15) - 1);
                    return draft_scratch_result(native_stack_mark, (uint64)(sub_8006E7BC(object, target, category)));
                }
                return draft_scratch_result(native_stack_mark, (uint64)(sub_8006E790(object)));
            }
            return draft_scratch_result(native_stack_mark, (uint64)(sub_8006EB64(object, 0x800A7EE4, kind)));
        case 3:
            return draft_scratch_result(native_stack_mark, (uint64)(draft_call_adapter(0x8006EC70, object, 0x800A7EE4, target)));
        default:
            return draft_scratch_result(native_stack_mark, (uint64)(result));
    }

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_8003B1EC */
uint32 sub_8003B1EC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    const uint32 gp = 0x800A5628;
    uint32 result = 1, exit_code;
    sub_8003ADF4(r_u32(gp + 0x17FC));
    do
    {
        sub_800327C8();
        sub_800697BC();
        if (r_u32(gp + 0x17FC) == 5)
            sub_80021718(0x800A7EE4, 0);
        if ((sint32)sub_8003B170() != -1)
        {
            sub_8002DC94();
            sub_80022A68(0);
        }
        if (r_u32(0x800A644C))
            sub_8005DC0C((uint32)-2146795948);
        else
            sub_8005C8E4((uint32)-2146795948);
        if (r_u32(gp + 0x17FC) != 5)
            sub_80021718(0x800A7EE4, 0);
        w_u32(gp + 0x17FC, 4);
        /* TODO Original frame service boundaries */
        draft_call_adapter(0x8005E31C);
        draft_call_adapter(0x8005E7DC);
        draft_call_adapter(0x8005982C);
        draft_call_adapter(0x8003CB14);
        draft_call_adapter(0x80020E30);
        draft_call_adapter(0x8001F690);
        sub_8001F968();
        draft_call_adapter(0x80036BE4);
        if (r_u32(gp + 0x17C0) != 1)
            draft_call_adapter(0x80059420);
        draft_call_adapter(0x8001FF7C, 1);
        draft_call_adapter(0x8001F850);
        draft_call_adapter(0x8005A944);
        if (r_u32(gp + 0x3D1C) == 1)
            w_u16(0x800A9734, 1);
        exit_code = sub_8003AF20();
        w_u32(gp + 0x17D0, exit_code);
        w_u32(gp + 0x17F8, exit_code);
    } while (!exit_code);
    if (r_s16(gp + 0x4054) == 1)
        do
        {
            draft_call_adapter(0x8001FF7C, 1);
            draft_call_adapter(0x8001F850);
            result = r_u32(0x800A562C);
        } while (result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

static void draft_r3_skid_wheels(uint32 object, uint32 first, uint32 second)
{
    if (r_s32(object + 532) > -150000)
        w_u8(object + first, 1);
    if (r_s32(object + 532) <= 149999)
        w_u8(object + second, 1);
}

static int draft_r3_skid_active(uint32 object, uint32 mask)
{
    if (r_u32(object + 580) & mask)
        return 1;
    sint32 speed = r_s32(object + 472);
    if (speed > 0x100000 && r_u32(object + 484))
        return 1;
    return speed > 1500000;
}

/* FUNCTION_MARKER sub_8002349C */
uint32 sub_8002349C(uint32 object, uint32 tags)
{
    uint32 mark = draft_scratch_mark();
    const uint32 gp = 0x800A5628;
    sint32 coefficient = 1024, speed, channel;
    uint32 angle0 = (uint32)r_s16(object + 564), angle1 = (uint32)r_s16(object + 566);
    sint32 cosine0 = (sint16)r_u16(0x800102E0 + 2 * (angle0 & 4095));
    sint32 cosine1 = (sint16)r_u16(0x800102E0 + 2 * (angle1 & 4095));
    for (sint32 i = 3; i >= 0; --i)
        w_u8(object + 588 + (uint32)i, 0);
    if ((sub_80025874(6, tags, 1) & 65535) || r_u8(object + 67) == 15)
        goto stop_sound;
    speed = r_s32(object + 472);
    if (!speed && !r_u32(object + 484))
        goto stop_sound;
    uint32 terrain = r_u16(tags + 8);
    if (terrain == 2313)
        goto stop_sound;
    sint32 previous = (sint16)r_u16(gp + 0x8E);
    if (terrain == 257)
        w_u16(gp + 0x8E, 55);
    else if (terrain != 2056)
        w_u16(gp + 0x8E, 56);
    else if (speed > 0x40000)
    {
        coefficient = (speed >> 12) + 736;
        w_u16(gp + 0x8E, 62);
        w_u8(object + 588, 1);
        w_u8(object + 589, 1);
    }
    sint32 sound = r_s16(gp + 0x8E);
    if (previous != sound)
    {
        draft_call_adapter(0x80035988, (uint32)r_s16(gp + 0x8C));
        w_u16(gp + 0x8C, -1);
        sound = r_s16(gp + 0x8E);
    }
    if (sound != 62)
    {
        if (r_s32(object + 504) > 65535)
        {
            if (r_u32(object + 580) & 0x2000000)
                draft_r3_skid_wheels(object, 590, 591);
            if (r_u32(object + 580) & 0x1000000)
                draft_r3_skid_wheels(object, 589, 588);
            if (r_s32(object + 472) > 0x100000)
                w_u32(object + 580, r_u32(object + 580) | 0x3000000);
        }
        if (draft_r3_abs(cosine0) >= 1537 && draft_r3_skid_active(object, 0x1000000))
        {
            angle0 = (uint32)r_s16(object + 564);
            coefficient = draft_r3_abs((sint16)r_u16(0x80010AE0 + 2 * (angle0 & 4095))) >> 2;
            draft_r3_skid_wheels(object, 590, 591);
        }
        if (draft_r3_abs(cosine1) >= 1537 && draft_r3_skid_active(object, 0x2000000))
        {
            angle1 = (uint32)r_s16(object + 566);
            coefficient = draft_r3_abs((sint16)r_u16(0x80010AE0 + 2 * (angle1 & 4095))) >> 2;
            draft_r3_skid_wheels(object, 589, 588);
        }
    }
    uint32 result = r_u32(object + 588);
    if (result)
    {
        channel = r_s16(gp + 0x8C);
        if (channel != -1)
            return draft_scratch_result(mark, draft_call_adapter(0x80036188, (uint32)channel, (uint32)(sint32)(sint16)coefficient));
        result = draft_call_adapter(0x80035A08, (uint32)r_s16(gp + 0x8E), (uint32)(sint32)(sint16)coefficient, 64, 0, 0);
        w_u16(gp + 0x8C, result);
        return draft_scratch_result(mark, result);
    }
    channel = r_s16(gp + 0x8C);
    if (channel == -1)
        return draft_scratch_result(mark, result);
    goto stop_channel;
stop_sound:
    channel = r_s16(gp + 0x8C);
stop_channel:
    draft_call_adapter(0x80035988, (uint32)channel);
    w_u16(gp + 0x8C, -1);
    return draft_scratch_result(mark, (uint32)-1);
}

/* FUNCTION_MARKER sub_8005BA64 */
uint32 sub_8005BA64(uint32 camera)
{
    uint32 native_stack_mark = draft_scratch_mark();

    const uint32 gp = 0x800A5628;
    uint32 temporary = draft_scratch_adapter(80), matrix = temporary + 48;
    uint32 owner = r_u32(gp + 0x4430), callbacks = r_u32(owner + 16);
    sint32 heading = (sint16)r_u16(gp + 0xD04);
    w_u32(temporary + 8, r_u32(0x800A633C));
    w_u32(temporary + 12, r_u32(0x800A6340));
    /* TODO Original indirect camera callbacks */
    sint32 speed = (sint32)draft_call_adapter(r_u32(callbacks), owner) >> 16;
    if (speed < 10)
        speed = 15;
    else if (speed >= 21)
        speed = 20;
    draft_call_adapter(r_u32(callbacks + 20), owner, temporary);
    uint32 difference = (heading - (sint16)r_u16(temporary + 2)) & 4095;
    if (difference > 1024 && difference < 3072)
        heading += 2048;
    /* TODO Original angle and matrix boundaries */
    sint16 angle = draft_call_adapter(0x80055764, (sint16)r_u16(camera + 40), (sint16)heading, speed);
    w_u16(camera + 40, angle);
    sint32 viewangle = angle + (r_u16(0x800A974C) ? 2048 : 0);
    draft_call_adapter(0x800551CC, viewangle, matrix);
    for (uint32 i = 0; i < 5; ++i)
        xport_gte_write_control(i, r_u32(matrix + i * 4));
    for (uint32 i = 0; i < 3; ++i)
        xport_gte_write_control(5 + i, r_u32(owner + 20 + i * 4));
    xport_gte_write_data(0, r_u32(camera + 12));
    xport_gte_write_data(1, r_u32(camera + 16));
    draft_gte_command_adapter(0x480012);
    for (uint32 i = 0; i < 3; ++i)
    {
        w_u32(temporary + 16 + i * 4, r_u32(0x800A7EE4 + i * 4));
        w_u32(camera + i * 4, xport_gte_read_data(25 + i));
    }
    xport_gte_write_data(2, r_u32(temporary + 8));
    xport_gte_write_data(3, r_u32(temporary + 12));
    draft_gte_command_adapter(0x48E012);
    for (uint32 i = 0; i < 3; ++i)
    {
        w_u32(0x800A7EE4 + i * 4, r_u32(camera + i * 4));
        w_u32(temporary + 32 + i * 4, xport_gte_read_data(25 + i));
    }
    uint32 height = sub_8005BA08(r_u32(0x800A7EE8));
    w_u32(0x800A7EE8, height);
    w_u32(camera + 4, height);
    sub_8005BD4C(owner + 20, 0x800A7EE4, temporary + 16, camera, matrix, viewangle, 0);
    w_u32(0x800A8554, r_u32(owner + 20) - r_u32(0x800A7EE4) - r_u32(temporary + 32));
    w_u32(0x800A8558, r_u32(owner + 24) - r_u32(0x800A7EE8) - r_u32(temporary + 36));
    w_u32(0x800A855C, r_u32(owner + 28) - r_u32(0x800A7EEC) - r_u32(temporary + 40));
    w_u32(0x800A84E8, r_u32(0x800A7EE8));
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A7EEC)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_80033EF8 */
void sub_80033EF8(uint32 unused, uint32 x, uint32 y)
{
    uint32 native_stack_mark = draft_scratch_mark();

    const uint32 sprite = 0x800A6C94;
    sub_8002133C();
    /* TODO Original sprite and rectangle service boundaries */
    for (uint32 i = 0; i < 4; ++i)
    {
        uint32 font = r_u32(0x800A5F68) + 5 * r_u8(r_u32(0x800A8D74) + r_u8(0x800A5C1C + i));
        draft_call_adapter(0x80041C9C, sprite, 1409286208, r_u8(font + 2), r_u8(font + 3), 13u, r_u8(font), r_u8(font + 1), (sint32)(sint16)r_u16(0x800903C4u + 2u * r_u8(font + 4)), 481u);
        draft_call_adapter(0x80041D90, sprite, 32896);
        draft_call_adapter(0x80041DB4, sprite, x + r_u8(0x800A5C14 + i), y + r_u8(0x800A5C18 + i), 0);
        draft_call_adapter(0x80020AB4, sprite, r_u32(0x800A9A74) + 720, 1);
    }
    draft_call_adapter(0x80041C9C, sprite, 1409286208, 64, 64, 8u, 64u, 0u, 672u, 480u);
    draft_call_adapter(0x80041DB4, sprite, x + 20, y + 19, 0);
    sub_80041DF8(sprite, 64, 32, 1024, 256);
    sub_80041E1C(sprite, r_u32(0x800A8518) + 3072);
    draft_call_adapter(0x80041D90, sprite, 8421504);
    sub_80020764(sprite, r_u32(0x800A9A74) + 720, 1, 0);
    for (uint32 i = 0; i < 4; ++i)
    {
        draft_call_adapter(0x80041C9C, sprite, 1409286208, 64, 64, r_u8(0x800A5C20u + i), r_u8(0x800A5C24u + i), 0u, 336u, 480u);
        draft_call_adapter(0x80041DB4, sprite, x + r_u8(0x800A5C28 + i), y + r_u8(0x800A5C2C + i), 0);
        draft_call_adapter(0x80041D90, sprite, 0xFFFFFF);
        draft_call_adapter(0x80020AB4, sprite, r_u32(0x800A9A74) + 720, 1);
    }
    draft_call_adapter(0x80020C60, 0, r_u32(0x800A9A74) + 720, 1052688, 2, (sint16)x, -120, 129, 240, 480);
    draft_call_adapter(0x80020C60, 0, r_u32(0x800A9A74) + 720, 0xFFFFFF, 2, -160, -92, 320, 62);

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_80020764 */
uint32 sub_80020764(uint32 objects, uint32 ordering, uint32 count, uint32 depth)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 packet = r_u32(0x800A865C), matrix = draft_scratch_adapter(32);
    while (count & 65535)
    {
        /* TODO Original Z rotation matrix boundary 80055228 */
        draft_call_adapter(0x80055228, r_u32(objects + 28), matrix);
        for (uint32 i = 0; i < 5; ++i)
            xport_gte_write_control(i, r_u32(matrix + i * 4));
        xport_gte_write_control(5, (sint16)r_u16(objects + 12) + 160);
        xport_gte_write_control(6, (sint16)r_u16(objects + 14) + 120);
        xport_gte_write_control(7, 0);
        sint16 left = ((uint32)(-(sint16)r_u16(objects + 20) * (sint16)r_u16(objects + 24))) >> 12;
        sint16 top = ((uint32)(-(sint16)r_u16(objects + 22) * (sint16)r_u16(objects + 26))) >> 12;
        sint16 right = ((r_u16(objects + 16) - (sint16)r_u16(objects + 20)) * (sint16)r_u16(objects + 24)) >> 12;
        sint16 bottom = ((r_u16(objects + 18) - (sint16)r_u16(objects + 22)) * (sint16)r_u16(objects + 26)) >> 12;
        const sint16 xs[4] = {left, right, left, right}, ys[4] = {top, top, bottom, bottom};
        for (uint32 i = 0; i < 3; ++i)
        {
            xport_gte_write_data(i * 2, (uint16)xs[i] | ((uint32)(uint16)ys[i] << 16));
            xport_gte_write_data(i * 2 + 1, 0);
        }
        const uint32 commands[4] = {0x480012, 0x488012, 0x490012, 0x480012};
        for (uint32 i = 0; i < 4; ++i)
        {
            if (i == 3)
            {
                xport_gte_write_data(0, (uint16)right | ((uint32)(uint16)bottom << 16));
                xport_gte_write_data(1, 0);
            }
            draft_gte_command_adapter(commands[i]);
            w_u16(packet + 8 + i * 8, xport_gte_read_data(9));
            w_u16(packet + 10 + i * 8, xport_gte_read_data(10));
            w_u16(packet + 12 + i * 8, xport_gte_read_data(11));
        }
        w_u32(packet + 4, r_u32(objects));
        uint32 bucket = ordering + 4 * (r_u16(objects + 10) + depth);
        w_u32(packet, (r_u32(bucket) & 0xFFFFFF) | 0x9000000);
        w_u32(bucket, (r_u32(bucket) & 0xFF000000) | (packet & 0xFFFFFF));
        uint32 u = r_u8(objects + 6), v = r_u8(objects + 7), width = r_u8(objects + 16), height = r_u8(objects + 18);
        w_u8(packet + 12, u);
        w_u8(packet + 13, v);
        w_u8(packet + 20, u + width);
        w_u8(packet + 21, v);
        w_u8(packet + 28, u);
        w_u8(packet + 29, v + height);
        w_u8(packet + 36, u + width);
        w_u8(packet + 37, v + height);
        w_u16(packet + 14, r_u16(objects + 4));
        w_u16(packet + 22, r_u16(objects + 8));
        --count;
        packet += 40;
        objects += 32;
    }
    w_u32(0x800A865C, packet);
    return draft_scratch_result(native_stack_mark, (uint64)(count & 65535));

    draft_scratch_release(native_stack_mark);
}

static uint32 draft_r3_reflect(uint32 object, uint32 contacts, uint32 offset)
{
    uint32 x = r_u32(contacts + offset);
    uint32 z = r_u32(contacts + offset + 8);
    uint32 heading = sub_80055A9C(x, z);
    x = r_u32(object + 476);
    z = r_u32(object + 480);
    uint32 difference = (heading - sub_80055A9C((uint32)((sint32)x >> 8), (uint32)((sint32)z >> 8))) & 4095;
    sint32 signed_difference = difference >= 2049 ? difference - 4096 : difference;
    sint32 scale = 24 * draft_r3_abs(signed_difference) + 16384;
    w_u32(0x800A56A8, scale);
    uint32 result = heading + difference;
    if (difference - 1025 >= 2047)
    {
        uint32 angle = result & 4095;
        x = r_u32(object + 476);
        z = r_u32(object + 480);
        sint32 length = (sint32)draft_call_adapter(0x80069BE0, x, z) >> 8;
        sint32 sine = r_s16(0x800102E0 + angle * 2) >> 4;
        sint32 attenuation = r_s32(0x800A56A8) >> 8;
        sint32 component = (sint32)((uint32)length * (uint32)sine) >> 8;
        w_u32(object + 476, 0 - (uint32)component * (uint32)attenuation);
        sint32 cosine = r_s16(0x80010AE0 + angle * 2) >> 4;
        component = (sint32)((uint32)length * (uint32)cosine) >> 8;
        result = 0 - (uint32)component * (uint32)attenuation;
        w_u32(object + 480, result);
    }
    return result;
}

/* FUNCTION_MARKER sub_80023C20 */
uint32 sub_80023C20(uint32 object, uint32 contacts, uint32 unused0, uint32 unused1, uint32 forcex, uint32 forcez)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 speed = r_u32(object + 472), limit = speed >> 2;
    if (limit > 65536)
        limit = 65536;
    if (limit < 2048)
        limit = 2048;
    if (r_u16(object + 32) == (uint32)(sint16)r_u16(r_u32(0x800A62EC) + 26))
    {
        if (speed <= 0x7FFFF && r_u16(object + 562))
            return draft_scratch_result(native_stack_mark, (uint64)(196608));
        if (speed <= 0x3FFFF)
            return draft_scratch_result(native_stack_mark, (uint64)(0));
    }
    sint32 factor = r_s16(object + 474);
    sint32 sx = (sint32)(forcex * (uint32)factor) >> 4, sz = (sint32)(forcez * (uint32)factor) >> 4;
    uint32 flags = r_u16(contacts + 96), result;
    if (flags & 0x40)
    {
        if ((flags & 12) == 12)
            goto reflect_side;
        sub_80023A7C(object, 4, 2, sx, limit);
        sub_80023A7C(object, 8, 3, 0 - (uint32)sx, limit);
        draft_r3_reflect(object, contacts, 72);
    }
    flags = r_u16(contacts + 96);
    if (flags & 0x10)
    {
        if ((flags & 3) == 3)
            goto reflect_front;
        sub_80023A7C(object, 1, 0, sz, limit);
        sub_80023A7C(object, 2, 1, 0 - (uint32)sz, limit);
        draft_r3_reflect(object, contacts, 48);
    }
    flags = r_u16(contacts + 96);
    if (flags & 0x20)
    {
        result = draft_r3_reflect(object, contacts, 60);
        if ((flags & 6) != 6)
            return draft_scratch_result(native_stack_mark, (uint64)(result));
        sint32 force = (sint32)(0 - (uint32)sz) >> 8;
        uint32 attenuation = ((65536 - r_u32(0x800A56A8)) & 65535) >> 8;
        sint32 impulse = (sint32)((uint32)force * attenuation) >> 8;
        result = (uint32)impulse * (uint32)(limit >> 8) + r_u32(object + 516);
        w_u32(object + 516, result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    if (flags & 0x80)
    {
        result = draft_r3_reflect(object, contacts, 84);
        if ((flags & 9) != 9)
            return draft_scratch_result(native_stack_mark, (uint64)(result));
        uint32 attenuation = ((65536 - r_u32(0x800A56A8)) & 65535) >> 8;
        sint32 impulse = (sint32)((uint32)(sz >> 8) * attenuation) >> 8;
        result = (uint32)impulse * (uint32)(limit >> 8) + r_u32(object + 516);
        w_u32(object + 516, result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    if ((flags & 12) == 12)
        goto reflect_side;
    if ((flags & 3) != 3)
    {
        sub_80023A7C(object, 1, 0, sz, limit);
        sub_80023A7C(object, 2, 1, 0 - (uint32)sz, limit);
        sub_80023A7C(object, 4, 2, sx, limit);
        return draft_scratch_result(native_stack_mark, (uint64)(sub_80023A7C(object, 8, 3, 0 - (uint32)sx, limit)));
    }
reflect_front:
    draft_r3_reflect(object, contacts, 0);
    return draft_scratch_result(native_stack_mark, (uint64)(draft_r3_reflect(object, contacts, 12)));
reflect_side:
    draft_r3_reflect(object, contacts, 24);
    return draft_scratch_result(native_stack_mark, (uint64)(draft_r3_reflect(object, contacts, 36)));

    draft_scratch_release(native_stack_mark);
}

static uint32 draft_r3_vehicle_model(uint32 object, uint32 table_address)
{
    uint32 index = r_u16(object + 32);
    uint32 table = r_u32(0x800A8548);
    index = r_u8(table + index);
    return r_u32(table_address) + 40 * index;
}

static int draft_r3_vehicle_special(uint32 object)
{
    uint32 table = r_u32(0x800A62EC);
    uint32 model = r_u16(object + 32);
    return model == (uint32)r_s16(table + 26);
}

static sint32 draft_r3_vehicle_impact(uint32 object, uint32 bit, uint32 offset, uint32 primary)
{
    uint32 angle, vector;
    if (primary)
        vector = 0x800A6BA4 + offset;
    else if ((uint32)r_s16(0x800A8704) & bit)
        vector = 0x800A86A4 + offset;
    else
        vector = 0;
    if (vector)
    {
        uint32 x = r_u32(vector);
        uint32 z = r_u32(vector + 8);
        uint32 bearing = sub_80055A9C(x, z);
        angle = (uint32)r_s16(object + 560) - bearing;
    }
    else
        angle = 2048;
    sint32 cosine = r_s16(0x80010AE0 + 2 * (angle & 4095));
    return (sint32)((uint32)cosine * r_u32(0x800A84AC));
}

static int draft_r3_vehicle_surface(uint32 kind)
{
    uint32 first = r_u8(0x800A6BA0);
    if (first != kind)
        return 0;
    uint32 second = r_u8(0x800A6BA1);
    if (second != first)
        return 0;
    uint32 third = r_u8(0x800A6BA2);
    return third == second && r_u8(0x800A6BA3) == third;
}

/* FUNCTION_MARKER sub_80027024 */
uint32 sub_80027024(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();
    const uint32 gp = 0x800A5628, tags = 0x800A6B98, collisions = 0x800A6BA4;
    uint32 local = draft_scratch_adapter(88), old = local, corners = local + 16, heights = local + 48, surface = local + 56, normal = local + 64, terrainout = local + 72;
    uint32 x, y, z, model, result, value, table, index;
    sint32 mission = r_s16(0x800A9734);
    w_u32(0x800A5C4C, 8191);
    if (mission)
    {
        sint32 handle = r_s16(object + 68);
        if (handle != 16383)
        {
            if (mission == 1)
                draft_call_adapter(0x80030F08, (uint32)r_s16(object + 76), (uint32)handle, 2);
            if (r_s16(0x800A9734) == 2)
                draft_call_adapter(0x80030F08, (uint32)r_s16(object + 78), (uint32)r_s16(object + 68), 3);
            w_u16(object + 68, 16383);
        }
    }
    sub_80024C9C(object);
    if (!r_u32(0x800A9864) || !r_u32(0x800A9760))
        draft_call_adapter(0x800255FC, object);
    draft_call_adapter(0x8003D27C, (uint32)r_s16(0x800A8514));
    x = r_u32(object + 244);
    y = r_u32(object + 248);
    z = r_u32(object + 252);
    w_u32(old, x);
    w_u32(old + 4, y);
    w_u32(old + 8, z);
    w_u16(gp + 0x15DC, 0);
    w_u16(gp + 0x15DE, 0);
    index = r_u16(object + 32);
    table = r_u32(0x800A8548);
    model = r_u8(table + index);
    draft_call_adapter(0x80029DDC, object, object + 160, model);
    if (r_u32(gp))
        draft_call_adapter(0x80030040, collisions, old, object + 20, object + 160);
    model = draft_r3_vehicle_model(object, 0x800A9750);
    draft_call_adapter(0x80029EEC, object, model, corners);
    draft_call_adapter(0x8002FC90, object, tags, corners, 1);
    sub_8002349C(object, tags);
    if (!r_u16(gp + 0x1570) && !r_u16(gp + 0x1572) && !r_u16(gp + 0x1574) && !r_u16(gp + 0x1576))
        w_u16(0x800A9734, 2);
    if ((!r_s16(gp + 0x15DC) && !r_s16(0x800A8704)) || !r_u32(gp))
    {
        if (!r_u32(gp + 0x12C))
        {
            x = r_u32(object + 244);
            y = r_u32(object + 248);
            z = r_u32(object + 252);
            w_u32(0x800A6C08, x);
            w_u32(0x800A6C0C, y);
            w_u32(0x800A6C10, z);
            w_u32(gp + 0x15EC, r_u32(object + 516));
        }
        w_u16(object + 592, 0);
        w_u32(gp + 0x12C, 0);
    }
    else
    {
        sint32 speed = r_s32(object + 472);
        sint32 shield = r_u8(0x800A8514);
        if (speed > 0x40000)
            for (uint32 i = 0; i < 8; ++i)
            {
                uint32 bit = 1 << i;
                uint32 primary = (uint32)r_s16(gp + 0x15DC) & bit;
                if (!primary && !((uint32)r_s16(0x800A8704) & bit))
                    continue;
                if (r_u32(0x800A6450))
                    continue;
                uint32 multiplier = 256 - (uint32)shield;
                sint32 impact = draft_r3_vehicle_impact(object, bit, 12 * i, primary);
                sint32 magnitude;
                if (impact < 0)
                    magnitude = (sint32)(0 - (uint32)(draft_r3_vehicle_impact(object, bit, 12 * i, (uint32)r_s16(gp + 0x15DC) & bit) >> 12));
                else
                    magnitude = draft_r3_vehicle_impact(object, bit, 12 * i, (uint32)r_s16(gp + 0x15DC) & bit) >> 12;
                sint32 damage = (sint32)(multiplier * (uint32)magnitude) / 128;
                uint32 health = r_u32(0x800A86A0) - (uint32)damage;
                primary = (uint32)r_s16(gp + 0x15DC) & bit;
                w_u32(0x800A86A0, health);
                impact = draft_r3_vehicle_impact(object, bit, 12 * i, primary);
                if (impact < 0)
                    shield = (sint32)((uint32)shield + (uint32)(draft_r3_vehicle_impact(object, bit, 12 * i, (uint32)r_s16(gp + 0x15DC) & bit) >> 14));
                else
                    shield = (sint32)((uint32)shield - (uint32)(draft_r3_vehicle_impact(object, bit, 12 * i, (uint32)r_s16(gp + 0x15DC) & bit) >> 14));
            }
        uint32 shield_byte = shield < 0 ? 0 : (uint32)shield & 255;
        uint32 shield_word = r_u32(0x800A8514);
        sint32 health = r_s32(0x800A86A0);
        w_u32(0x800A8514, (shield_word & 0xFF00) | shield_byte);
        if (health <= 0)
        {
            value = r_u8(0x800A7E83);
            w_u32(0x800A86A0, 0);
            w_u16(gp + 0x3A08, value);
            draft_call_adapter(0x8005E2BC, 2);
            value = draft_r3_vehicle_special(object) ? 0x82 : 0x80;
            w_u8(object + 14, r_u8(object + 14) | value);
            draft_call_adapter(0x800608F8, object);
            return draft_scratch_result(native_stack_mark, draft_call_adapter(0x80028F78, object, 1));
        }
        draft_call_adapter(0x8003D324, (uint32)r_s16(0x800A86A0));
        draft_call_adapter(0x8003D27C, (uint32)r_s16(0x800A8514));
        value = r_u16(0x800A86A0);
        sint32 contact = r_s16(object + 592);
        w_u16(object + 58, value);
        if (!contact)
            draft_call_adapter(0x80023228, object + 20, collisions, object + 160, 1, r_u32(object + 472));
        value = r_u16(gp + 0x15DC);
        uint32 secondary = r_u16(0x800A8704);
        uint32 attempts = r_u32(gp + 0x12C) + 1;
        w_u32(gp + 0x12C, attempts);
        w_u16(object + 592, value | secondary);
        if ((sint32)attempts >= 5)
        {
            if (!draft_r3_vehicle_special(object))
            {
                x = r_u32(0x800A6C08);
                y = r_u32(0x800A6C0C);
                z = r_u32(0x800A6C10);
                w_u32(object + 20, x);
                w_u32(object + 24, y);
                w_u32(object + 28, z);
                w_u32(object + 516, r_u32(gp + 0x15EC));
            }
            w_u32(object + 484, 0);
            w_u32(object + 472, 0);
            w_u32(object + 476, 0);
            w_u32(object + 480, 0);
            w_u32(gp + 0x12C, 0);
        }
    }
    if (r_s16(object + 592))
    {
        x = r_u32(object + 20);
        y = r_u32(object + 24);
        z = r_u32(object + 28);
        w_u32(object + 232, x);
        w_u32(object + 236, y);
        w_u32(object + 240, z);
    }
    x = r_u32(object + 20);
    y = r_u32(object + 24);
    z = r_u32(object + 28);
    w_u32(object + 244, x);
    w_u32(object + 248, y);
    w_u32(object + 252, z);
    draft_call_adapter(0x80025924, object);
    x = r_u32(object + 232);
    z = r_u32(object + 240);
    w_u32(object + 20, x);
    w_u32(object + 28, z);
    sub_800283D4(object, object + 88, tags);
    draft_call_adapter(0x80024820, object, heights);
    result = sub_800287B4(object, object + 88, r_u32(object + 472), heights);
    w_u8(object + 67, result);
    // The original doubled model-height argument is unused by 80022FF8
    draft_call_adapter(0x80022FF8, object, object + 88, object + 592, object + 160);
    index = r_u16(object + 32);
    table = r_u32(0x800A8548);
    sint32 h3 = r_s16(heights + 6);
    index = r_u8(table + index);
    sint32 h2 = r_s16(heights + 4);
    model = r_u32(0x800A9750) + 40 * index;
    sint32 dimension = r_s16(model + 34);
    sint32 h0 = r_s16(heights), h1 = r_s16(heights + 2);
    result = sub_80055A9C((uint32)((h3 + h2 - h0 - h1) >> 1), (uint32)dimension);
    index = r_u16(object + 32);
    table = r_u32(0x800A8548);
    w_u16(object + 224, result);
    h1 = r_s16(heights + 2);
    index = r_u8(table + index);
    h2 = r_s16(heights + 4);
    model = r_u32(0x800A9750) + 40 * index;
    dimension = r_s16(model + 36);
    h3 = r_s16(heights + 6);
    h0 = r_s16(heights);
    result = sub_80055A9C((uint32)((h2 + h1 - h3 - h0) >> 1), (uint32)dimension);
    value = r_u16(object + 560);
    uint32 airborne = r_u8(object + 67);
    w_u16(object + 228, result);
    w_u16(object + 226, value);
    if (airborne)
        w_u16(object + 80, r_u16(object + 224));
    else
    {
        draft_call_adapter(0x80023388, object);
        index = r_u16(object + 32);
        table = r_u32(0x800A8548);
        h3 = r_s16(object + 140);
        index = r_u8(table + index);
        h2 = r_s16(object + 124);
        model = r_u32(0x800A9750) + 40 * index;
        dimension = r_s16(model + 34);
        h0 = r_s16(object + 92);
        h1 = r_s16(object + 108);
        w_u16(object + 80, sub_80055A9C((uint32)((h3 + h2 - h0 - h1) >> 1), (uint32)dimension));
    }
    x = (uint32)r_s16(object + 224);
    y = (uint32)r_s16(object + 226);
    z = (uint32)r_s16(object + 228);
    value = r_u16(object + 226);
    result = r_u16(object + 228);
    w_u16(object + 82, value);
    w_u16(object + 84, result);
    draft_call_adapter(0x80054D38, x, y, z, object + 36);
    uint32 time = r_u32(0x800A63D8);
    if (time)
        w_u32(gp + 0x128, time);
    sint32 vertical = (sint32)((r_u32(object + 24) - r_u32(object + 248)) << 16), divisor = (sint32)time >> 16;
    w_u32(object + 492, (uint32)vertical);
    if (divisor)
    {
        if (vertical == (sint32)0x80000000 && divisor == -1)
            abort();
        w_u32(object + 492, (uint32)(vertical / divisor));
    }
    model = draft_r3_vehicle_model(object, 0x800A90AC);
    draft_call_adapter(0x80029970, object, (uint32)r_s16(model + 32), 0, 1, object + 244);
    sint32 sound;
    if (r_u32(gp + 0x94) && r_s32(object + 484) > 0 && r_s32(0x800A7E10) > 0)
    {
        draft_call_adapter(0x80063450, object);
        sound = r_s16(gp + 0x84);
        draft_call_adapter(0x800361FC, (uint32)sound, 192);
    }
    else
    {
        sound = r_s16(gp + 0x84);
        if (sound != -1)
            draft_call_adapter(0x800361FC, (uint32)sound, 0);
    }
    x = r_u32(object + 244);
    y = r_u32(object + 20);
    z = r_u32(object + 252);
    value = r_u32(object + 28);
    uint32 distance = (uint32)draft_call_adapter(0x80069BE0, x - y, z - value);
    uint32 factor = (uint32)(r_s32(object + 472) >> 19) + 1;
    value = r_u32(gp + 0x74) + distance * factor;
    w_u32(gp + 0x74, value);
    if (value > 100000)
    {
        if (!r_u32(gp + 0x6C))
            w_u32(0x800A7E10, r_u32(0x800A7E10) - 1);
        w_u32(gp + 0x74, 0);
    }
    if (r_s32(0x800A7E10) <= 0)
    {
        w_u32(0x800A8538, 728160);
        w_u32(gp + 0x9C, 728160);
    }
    uint32 force_mask = 0, excluded_mask = 0;
    for (uint32 i = 0; i < 4; ++i)
    {
        value = r_u16(object + 98 + 16 * i);
        sint32 forced = r_s16(object + 594);
        excluded_mask |= (value & 15) << i;
        uint32 material;
        if (forced)
        {
            value = r_u8(object + 584 + i);
            material = r_u8(object + 582);
        }
        else
        {
            value = r_u8(object + 588 + i);
            material = r_u8(0x800A6BA0 + i);
        }
        force_mask |= value << i;
        w_u8(surface + i, material);
    }
    // The original old-position argument is unused by 80061A78
    draft_call_adapter(0x80061A78, object, object + 596, surface, force_mask, excluded_mask, 4);
    w_u8(object + 581, 0);
    if (!(r_u32(0x800A8398) & 64))
        w_u32(gp + 0x156C, 0);
    else if (!(r_u32(gp + 0x156C) & 64))
    {
        if ((sint16)draft_call_adapter(0x8003CB98, object) == -1)
            w_u32(gp + 0x156C, r_u32(0x800A8398));
        else
            w_u32(gp + 0x156C, 0);
    }
    uint32 buttons = r_u32(0x800A8398);
    if (buttons & 1)
        w_u8(object + 581, 1);
    else if (buttons & 2)
        w_u8(object + 581, 255);
    buttons = r_u32(0x800A8398);
    w_u32(object + 580, (r_u32(object + 580) & 0xFFFFFFF) | ((buttons & 4) ? 0x10000000 : 0));
    sint32 scaled_speed = r_s32(object + 472) >> 8;
    uint32 owner = r_u32(0x800A7BAC);
    z = r_u32(object + 28);
    y = r_u32(object + 24);
    result = (uint32)r_s16(object + 226);
    x = r_u32(object + 20);
    w_u32(0x800A84AC, (uint32)((sint32)((uint32)scaled_speed * 409) >> 16));
    w_u32(0x800A7E20, z);
    w_u32(0x800A7E1C, y);
    w_u32(0x800A8518, result);
    w_u32(0x800A7E14, x);
    draft_call_adapter(0x80026BC4, owner);
    if (!r_u32(0x800A9760))
    {
        if (r_s16(gp + 0x7C) == 1 && r_s32(0x800A86A0) < 513)
        {
            w_u16(gp + 0x7C, 2);
            draft_call_adapter(0x80062D90, object + 552, object, 1);
        }
        if (!r_s16(gp + 0x7C) && r_s32(0x800A86A0) < 1025)
        {
            w_u16(gp + 0x7C, 1);
            draft_call_adapter(0x80062D90, object + 552, object, 0);
        }
        sint32 state = r_s16(gp + 0x7C);
        if (state == 2 && r_s32(0x800A86A0) >= 513)
        {
            w_u16(gp + 0x7C, 1);
            draft_call_adapter(0x80062D90, object + 552, object, 0);
            state = r_s16(gp + 0x7C);
        }
        if (state == 1 && r_s32(0x800A86A0) >= 1025)
        {
            w_u16(gp + 0x7C, 0);
            w_u32(object + 552, 0);
        }
    }
    sint32 timer = r_s32(gp + 0x94);
    if (timer <= 0)
    {
        value = r_u32(gp + 0x9C);
        sound = r_s16(gp + 0x84);
        w_u32(0x800A8538, value);
        draft_call_adapter(0x80035988, (uint32)sound);
        w_u16(gp + 0x84, -1);
    }
    else
    {
        timer = (sint32)((uint32)timer - r_u32(0x800A9010));
        w_u32(gp + 0x94, (uint32)timer);
        if (timer <= 0)
        {
            value = r_u32(gp + 0x9C);
            w_u32(gp + 0x94, 0);
            w_u32(0x800A8538, value);
        }
    }
    if (r_u8(gp + 0x1578) < 10 && r_u8(gp + 0x1579) < 10 && r_u8(gp + 0x157A) < 10 && r_u8(gp + 0x157B) < 10)
    {
        draft_call_adapter(0x8002E310, object + 20, normal, terrainout);
        int water = r_u8(gp + 0x1578) == 6 || r_u8(gp + 0x1579) == 6 || r_u8(gp + 0x157A) == 6 || r_u8(gp + 0x157B) == 6;
        if (water && r_s16(terrainout) == 6 && !r_u8(object + 67))
        {
            w_u32(object, 0x80029968);
            w_u16(gp + 0x3A08, r_u8(0x800A7E83));
            draft_call_adapter(0x8005E2BC, 2);
            sound = r_s16(gp + 0x86);
            w_u16(gp + 0x7C, 0);
            w_u32(object + 552, 0);
            draft_call_adapter(0x80035988, (uint32)sound);
            draft_call_adapter(0x80035988, (uint32)r_s16(gp + 0x8C));
            x = (uint32)r_s16(object + 74);
            y = (uint32)r_s16(object + 68);
            w_u16(0x800A9734, 3);
            w_u32(object + 476, 0);
            w_u32(object + 480, 0);
            draft_call_adapter(0x80030F08, x, y, 1);
            w_u32(gp + 0xA0, 0);
            return draft_scratch_result(native_stack_mark, draft_call_adapter(0x80054934, object, 0));
        }
    }
    else
    {
        if (r_s32(0x800A7E10) < 100 && r_s32(0x800A7C6C) > 0 && draft_r3_vehicle_surface(17))
        {
            sint32 step = r_s16(0x800A63DA);
            value = r_u16(gp + 0x78) - (uint32)step;
            w_u16(gp + 0x78, value);
            if ((sint16)value <= 0)
            {
                w_u16(gp + 0x78, 8);
                uint32 fuel = r_u32(0x800A7E10);
                uint32 money = r_u32(0x800A7C6C);
                w_u32(0x800A7E10, fuel + 1);
                w_u32(0x800A7C6C, money - 5);
                draft_call_adapter(0x80035A08, 54, 6000, 128, 0);
                if (r_u32(0x800A8538) == 728160)
                {
                    uint32 speed = 18204 * (uint32)(sint32)(sint16)draft_call_adapter(0x8003D654);
                    w_u32(0x800A8538, speed);
                    w_u32(gp + 0x9C, speed);
                }
            }
        }
        if (r_s32(0x800A86A0) < 2048 && r_s32(0x800A7C6C) > 0 && draft_r3_vehicle_surface(18))
        {
            value = r_u32(0x800A63D8);
            uint32 health = r_u32(0x800A86A0);
            w_u32(0x800A5C4C, 4095);
            sint32 step = (sint32)(value << 2) >> 16;
            health += (uint32)step;
            sint32 cost = (sint32)((uint32)step * 5) >> 2;
            uint32 money = r_u32(0x800A7C6C);
            w_u32(0x800A86A0, health);
            w_u32(0x800A7C6C, money - (uint32)cost);
            if ((sint32)health >= 2049)
                w_u32(0x800A86A0, 2048);
            draft_call_adapter(0x80035A08, 54, 6000, 128, 0);
        }
    }
    if (r_s32(0x800A7C6C) < 0)
        w_u32(0x800A7C6C, 0);
    uint32 visible = r_u8(0x800A7E80);
    w_u16(0x800A8704, 0);
    w_u16(0x800A8706, 0);
    if (visible)
        value = draft_r3_vehicle_special(object) ? 0x82 : 2;
    else
        value = 0;
    result = r_u8(object + 14);
    result = visible ? result | value : result & 0x7D;
    w_u8(object + 14, result);
    return draft_scratch_result(native_stack_mark, result);
}
