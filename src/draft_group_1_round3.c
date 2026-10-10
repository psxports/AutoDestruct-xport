#include "psx.h"
#include "draft_signatures.h"
#include "draft_adapters.h"

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
        if (r_u32(0x800A967C) == 1)
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
        if (r_u32(0x800A967C) == 1)
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
        sint32 y = r_u8(0x800909D9 + offset) + (sint16)yoffset;
        sub_800436D4(8421504, r_u32(0x800909D0 + offset), r_u8(0x800909D8 + offset), y, 10);
        sub_800436D4(8421504, r_u32((uint32)-2146792648 + 4 * r_u32(0x800909D4 + offset)), r_u8(0x800909DA + offset), y, 10);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_8003AF20 */
uint32 sub_8003AF20(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    const uint32 gp = 0x800A5628;
    if (r_u32(gp + 0x17CC))
        w_u32(gp + 0x17CC, r_u32(gp + 0x17CC) - 1);
    else if (!r_u32(gp + 0x17C0) && r_u32(gp + 0x4054) == 1 && !r_u32(gp + 0x4138))
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
    if (r_u32(gp + 0x17C0) == 1 && r_u32(gp + 0x17E4))
    {
        sint32 delay = r_u32(gp + 0x17E4) + 1;
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
            if (selection == r_u32(gp + 0x17C0))
            {
                w_u32(gp + 0x1820, 3);
                return draft_scratch_result(native_stack_mark, (uint64)(5));
            }
        }
    }
    if (!r_u32(gp + 0x17C0) && (sint32)draft_call_adapter(0x8003B3B0) == -1)
    {
        w_u32(gp + 0x17C0, 1);
        w_u32(gp + 0x17E8, 1);
    }
    if (r_u32(gp + 0x17C0) == 1 && r_u32(gp + 0x17E8))
    {
        sint32 delay = r_u32(gp + 0x17E8) + 1;
        w_u32(gp + 0x17E8, delay);
        if (delay >= 3)
        {
            w_u32(gp + 0x17C0, 0);
            w_u32(gp + 0x17E8, 0);
            w_u32(gp + 0x4054, 0);
            return draft_scratch_result(native_stack_mark, (uint64)(9));
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
    sint32 dx = r_u32(object + 20) - r_u32(0x800A7E14), dz = r_u32(object + 28) - r_u32(0x800A7E20), dy = r_u32(object + 24) - r_u32(0x800A7E1C);
    sint32 distance = draft_call_adapter(0x80069BE0, dx, dz);
    uint32 angles = draft_scratch_adapter(8);
    w_u16(angles + 2, sub_80055A9C(dx, dz));
    w_u16(angles, -(sint16)sub_80055A9C(dy, distance));
    w_u16(object + 60, r_u16(angles));
    w_u16(object + 62, r_u16(angles + 2));
    w_u16(object + 64, 0);
    sub_80055288(angles, object + 36);
    if (distance < 6500)
    {
        w_u16(object + 66, r_u16(object + 66) - r_u32(0x800A9010));
        if ((sint16)r_u16(object + 66) < 0 && r_u32(0x800A9760) != 1)
        {
            if (!r_u32(0x800A9734))
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
    uint32 result = 1;
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
            w_u32(0x800A9734, 1);
        w_u32(gp + 0x17D0, sub_8003AF20());
        w_u32(gp + 0x17F8, r_u32(gp + 0x17D0));
    } while (!r_u32(gp + 0x17D0));
    if (r_u32(gp + 0x4054) == 1)
        do
        {
            draft_call_adapter(0x8001FF7C, 1);
            draft_call_adapter(0x8001F850);
            result = r_u32(0x800A562C);
        } while (result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_8002349C */
uint32 sub_8002349C(uint32 object, uint32 tags)
{
    uint32 native_stack_mark = draft_scratch_mark();

    const uint32 gp = 0x800A5628;
    sint32 coefficient = 1024;
    sint32 cosine0 = (sint16)r_u16(0x800102E0 + 2 * (r_u16(object + 564) & 4095));
    sint32 cosine1 = (sint16)r_u16(0x800102E0 + 2 * (r_u16(object + 566) & 4095));
    w_u32(object + 588, 0);
    sint32 speed = r_u32(object + 472);
    /* TODO Original sound service boundaries */
    if ((sub_80025874(6, tags, 1) & 65535) || r_u8(object + 67) == 15 || (!speed && !r_u32(object + 484)) || r_u16(tags + 8) == 2313)
    {
        draft_call_adapter(0x80035988, r_u16(gp + 0x8C));
        w_u16(gp + 0x8C, 65535);
        return draft_scratch_result(native_stack_mark, (uint64)(-1));
    }
    sint16 previous = r_u16(gp + 0x8E);
    uint32 terrain = r_u16(tags + 8);
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
    if (previous != (sint16)r_u16(gp + 0x8E))
    {
        draft_call_adapter(0x80035988, (sint16)r_u16(gp + 0x8C));
        w_u16(gp + 0x8C, 65535);
    }
    if (r_u16(gp + 0x8E) != 62)
    {
        sint32 steering = r_u32(object + 532);
        if ((sint32)r_u32(object + 504) > 65535)
        {
            if (r_u32(object + 580) & 0x2000000)
            {
                if (steering > -150000)
                    w_u8(object + 590, 1);
                if (steering <= 149999)
                    w_u8(object + 591, 1);
            }
            if (r_u32(object + 580) & 0x1000000)
            {
                if (steering > -150000)
                    w_u8(object + 589, 1);
                if (steering <= 149999)
                    w_u8(object + 588, 1);
            }
            if (speed > 0x100000)
                w_u32(object + 580, r_u32(object + 580) | 0x3000000);
        }
        if (draft_r3_abs(cosine0) >= 1537 && ((r_u32(object + 580) & 0x1000000) || (speed > 0x100000 && r_u32(object + 484)) || speed > 1500000))
        {
            coefficient = draft_r3_abs((sint16)r_u16(0x80010AE0 + 2 * (r_u16(object + 564) & 4095))) >> 2;
            if (steering > -150000)
                w_u8(object + 590, 1);
            if (steering <= 149999)
                w_u8(object + 591, 1);
        }
        if (draft_r3_abs(cosine1) >= 1537 && ((r_u32(object + 580) & 0x2000000) || (speed > 0x100000 && r_u32(object + 484)) || speed > 1500000))
        {
            coefficient = draft_r3_abs((sint16)r_u16(0x80010AE0 + 2 * (r_u16(object + 566) & 4095))) >> 2;
            if (steering > -150000)
                w_u8(object + 589, 1);
            if (steering <= 149999)
                w_u8(object + 588, 1);
        }
    }
    sint32 channel = (sint16)r_u16(gp + 0x8C);
    if (r_u32(object + 588))
    {
        if (channel != -1)
            return draft_scratch_result(native_stack_mark, (uint64)(draft_call_adapter(0x80036188, channel, (sint16)coefficient)));
        uint32 result = draft_call_adapter(0x80035A08, (sint16)r_u16(gp + 0x8E), (sint16)coefficient, 64, 0);
        w_u16(gp + 0x8C, result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    if (channel == -1)
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    draft_call_adapter(0x80035988, channel);
    w_u16(gp + 0x8C, 65535);
    return draft_scratch_result(native_stack_mark, (uint64)(-1));

    draft_scratch_release(native_stack_mark);
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
    sint32 heading = (sint16)sub_80055A9C(r_u32(contacts + offset), r_u32(contacts + offset + 8));
    uint32 difference = (heading - (uint16)sub_80055A9C((sint32)r_u32(object + 476) >> 8, (sint32)r_u32(object + 480) >> 8)) & 4095;
    sint32 signed_difference = difference >= 2049 ? difference - 4096 : difference;
    sint32 scale = 24 * draft_r3_abs(signed_difference) + 16384;
    w_u32(0x800A56A8, scale);
    uint32 result = heading + difference;
    if (difference - 1025 >= 2047)
    {
        uint32 angle = result & 4095;
        /* TODO Original vector length boundary 80069BE0 */
        sint32 length = (sint32)draft_call_adapter(0x80069BE0, r_u32(object + 476), r_u32(object + 480)) >> 8;
        sint32 attenuation = (sint32)r_u32(0x800A56A8) >> 8;
        sint32 vx = -(((length * ((sint16)r_u16(0x800102E0 + angle * 2) >> 4)) >> 8) * attenuation);
        result = -(((length * ((sint16)r_u16(0x80010AE0 + angle * 2) >> 4)) >> 8) * attenuation);
        w_u32(object + 476, vx);
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
    sint32 sx = ((sint32)forcex * (sint16)r_u16(object + 474)) >> 4, sz = ((sint32)forcez * (sint16)r_u16(object + 474)) >> 4;
    uint32 flags = r_u16(contacts + 96), result;
    if (flags & 0x40)
    {
        if ((flags & 12) == 12)
            goto reflect_side;
        sub_80023A7C(object, 4, 2, sx, limit);
        sub_80023A7C(object, 8, 3, -sx, limit);
        draft_r3_reflect(object, contacts, 72);
    }
    flags = r_u16(contacts + 96);
    if (flags & 0x10)
    {
        if ((flags & 3) == 3)
            goto reflect_front;
        sub_80023A7C(object, 1, 0, sz, limit);
        sub_80023A7C(object, 2, 1, -sz, limit);
        draft_r3_reflect(object, contacts, 48);
    }
    flags = r_u16(contacts + 96);
    if (flags & 0x20)
    {
        result = draft_r3_reflect(object, contacts, 60);
        if ((flags & 6) != 6)
            return draft_scratch_result(native_stack_mark, (uint64)(result));
        sint32 impulse = ((-sz >> 8) * ((uint16)-r_u16(0x800A56A8) >> 8)) >> 8;
        result = impulse * (limit >> 8) + r_u32(object + 516);
        w_u32(object + 516, result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    if (flags & 0x80)
    {
        result = draft_r3_reflect(object, contacts, 84);
        if ((flags & 9) != 9)
            return draft_scratch_result(native_stack_mark, (uint64)(result));
        sint32 impulse = ((sz >> 8) * ((uint16)-r_u16(0x800A56A8) >> 8)) >> 8;
        result = impulse * (limit >> 8) + r_u32(object + 516);
        w_u32(object + 516, result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    if ((flags & 12) == 12)
        goto reflect_side;
    if ((flags & 3) != 3)
    {
        sub_80023A7C(object, 1, 0, sz, limit);
        sub_80023A7C(object, 2, 1, -sz, limit);
        sub_80023A7C(object, 4, 2, sx, limit);
        return draft_scratch_result(native_stack_mark, (uint64)(sub_80023A7C(object, 8, 3, -sx, limit)));
    }
reflect_front:
    draft_r3_reflect(object, contacts, 0);
    return draft_scratch_result(native_stack_mark, (uint64)(draft_r3_reflect(object, contacts, 12)));
reflect_side:
    draft_r3_reflect(object, contacts, 24);
    return draft_scratch_result(native_stack_mark, (uint64)(draft_r3_reflect(object, contacts, 36)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER sub_80027024 */
uint32 sub_80027024(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    const uint32 gp = 0x800A5628, tags = (uint32)-2146800744, collisions = (uint32)-2146800732;
    uint32 local = draft_scratch_adapter(88), old = local, corners = local + 16, heights = local + 48, surface = local + 56, normal = local + 64, terrainout = local + 72;
    uint32 resource = r_u32(0x800A62EC), special = (uint32)(sint16)r_u16(resource + 26);
    /* TODO Original vehicle, HUD, sound and terrain service boundaries */
    w_u32(0x800A5C4C, 8191);
    if (r_u16(0x800A9734) && (sint16)r_u16(object + 68) != 16383)
    {
        if (r_u16(0x800A9734) == 1)
            draft_call_adapter(0x80030F08, (sint16)r_u16(object + 76), (sint16)r_u16(object + 68), 2);
        if (r_u16(0x800A9734) == 2)
            draft_call_adapter(0x80030F08, (sint16)r_u16(object + 78), (sint16)r_u16(object + 68), 3);
        w_u16(object + 68, 16383);
    }
    sub_80024C9C(object);
    if (!r_u8(0x800A9864) || !r_u32(0x800A9760))
        draft_call_adapter(0x800255FC, object);
    draft_call_adapter(0x8003D27C, r_u16(0x800A8514));
    for (uint32 i = 0; i < 3; ++i)
        w_u32(old + i * 4, r_u32(object + 244 + i * 4));
    w_u16(gp + 0x15DC, 0);
    w_u16(gp + 0x15DE, 0);
    uint32 model = r_u8(r_u32(0x800A8548) + r_u16(object + 32));
    draft_call_adapter(0x80029DDC, object, object + 160, model);
    if (r_u32(gp))
        draft_call_adapter(0x80030040, collisions, old, object + 20, object + 160);
    draft_call_adapter(0x80029EEC, object, r_u32(0x800A9750) + model * 40, corners);
    draft_call_adapter(0x8002FC90, object, tags, corners, 1);
    sub_8002349C(object, tags);
    if (!r_u16(gp + 0x1570) && !r_u16(gp + 0x1572) && !r_u16(gp + 0x1574) && !r_u16(gp + 0x1576))
        w_u16(0x800A9734, 2);
    if ((!r_u16(gp + 0x15DC) && !r_u16(0x800A8704)) || !r_u32(gp))
    {
        if (!r_u32(gp + 0x12C))
        {
            for (uint32 i = 0; i < 3; ++i)
                w_u32(0x800A6C08 + i * 4, r_u32(object + 244 + i * 4));
            w_u32(gp + 0x15EC, r_u32(object + 516));
        }
        w_u16(object + 592, 0);
        w_u32(gp + 0x12C, 0);
    }
    else
    {
        sint32 shield = r_u16(0x800A8514);
        if ((sint32)r_u32(object + 472) > 0x40000)
            for (uint32 i = 0; i < 8; ++i)
            {
                uint32 bit = 1u << i;
                if ((!((r_u16(gp + 0x15DC) | r_u16(0x800A8704)) & bit)) || r_u32(0x800A6450))
                    continue;
                uint32 vector = (r_u16(gp + 0x15DC) & bit) ? collisions + 12 * i : (uint32)-2146793820 + 12 * i;
                uint32 angle = (r_u16(object + 560) - sub_80055A9C(r_u32(vector), r_u32(vector + 8))) & 4095;
                sint32 impact = (sint16)r_u16(0x80010AE0 + angle * 2) * (sint16)r_u16(0x800A84AC);
                w_u32(0x800A86A0, r_u32(0x800A86A0) - (256 - shield) * draft_r3_abs(impact >> 12) / 128);
                if (impact < 0)
                    shield += impact >> 14;
                else
                    shield -= impact >> 14;
            }
        w_u16(0x800A8514, (r_u16(0x800A8514) & 0xFF00) | (shield < 0 ? 0 : (uint8)shield));
        if ((sint32)r_u32(0x800A86A0) <= 0)
        {
            w_u32(0x800A86A0, 0);
            w_u32(gp + 0x3A08, r_u8(0x800A7E83));
            draft_call_adapter(0x8005E2BC, 2);
            w_u8(object + 14, r_u8(object + 14) | (r_u16(object + 32) == special ? 0x82 : 0x80));
            draft_call_adapter(0x800608F8, object);
            return draft_scratch_result(native_stack_mark, (uint64)(draft_call_adapter(0x80028F78, object, 1)));
        }
        draft_call_adapter(0x8003D324, r_u32(0x800A86A0));
        draft_call_adapter(0x8003D27C, r_u16(0x800A8514));
        w_u16(object + 58, r_u32(0x800A86A0));
        if (!r_u16(object + 592))
            draft_call_adapter(0x80023228, object + 20, collisions, object + 160, 1, r_u32(object + 472));
        uint32 attempts = r_u32(gp + 0x12C) + 1;
        w_u32(gp + 0x12C, attempts);
        w_u16(object + 592, r_u16(gp + 0x15DC) | r_u16(0x800A8704));
        if (attempts >= 5)
        {
            if (r_u16(object + 32) != special)
            {
                for (uint32 i = 0; i < 3; ++i)
                    w_u32(object + 20 + i * 4, r_u32(0x800A6C08 + i * 4));
                w_u32(object + 516, r_u32(gp + 0x15EC));
            }
            w_u32(object + 484, 0);
            w_u32(object + 472, 0);
            w_u32(object + 476, 0);
            w_u32(object + 480, 0);
            w_u32(gp + 0x12C, 0);
        }
    }
    if (r_u16(object + 592))
        for (uint32 i = 0; i < 3; ++i)
            w_u32(object + 232 + i * 4, r_u32(object + 20 + i * 4));
    for (uint32 i = 0; i < 3; ++i)
        w_u32(object + 244 + i * 4, r_u32(object + 20 + i * 4));
    draft_call_adapter(0x80025924, object);
    w_u32(object + 20, r_u32(object + 232));
    w_u32(object + 28, r_u32(object + 240));
    sub_800283D4(object, object + 88, tags);
    draft_call_adapter(0x80024820, object, heights);
    w_u8(object + 67, sub_800287B4(object, object + 88, r_u32(object + 472), heights));
    model = r_u8(r_u32(0x800A8548) + r_u16(object + 32));
    uint32 shape = r_u32(0x800A9750) + model * 40, physical = r_u32(0x800A90AC) + model * 40;
    draft_call_adapter(0x80022FF8, object, object + 88, object + 592, object + 160);
    sint32 h0 = (sint16)r_u16(heights), h1 = (sint16)r_u16(heights + 2), h2 = (sint16)r_u16(heights + 4), h3 = (sint16)r_u16(heights + 6);
    w_u16(object + 224, sub_80055A9C((h3 + h2 - h0 - h1) >> 1, (sint16)r_u16(shape + 34)));
    w_u16(object + 228, sub_80055A9C((h2 + h1 - h3 - h0) >> 1, (sint16)r_u16(shape + 36)));
    w_u16(object + 226, r_u16(object + 560));
    if (r_u8(object + 67))
        w_u16(object + 80, r_u16(object + 224));
    else
    {
        draft_call_adapter(0x80023388, object);
        w_u16(object + 80, sub_80055A9C(((sint16)r_u16(object + 140) + (sint16)r_u16(object + 124) - (sint16)r_u16(object + 92) - (sint16)r_u16(object + 108)) >> 1, (sint16)r_u16(shape + 34)));
    }
    w_u16(object + 82, r_u16(object + 226));
    w_u16(object + 84, r_u16(object + 228));
    draft_call_adapter(0x80054D38, (sint16)r_u16(object + 224), (sint16)r_u16(object + 226), (sint16)r_u16(object + 228), object + 36);
    sint32 time = r_u32(0x800A63D8);
    if (time)
        w_u32(gp + 0x128, time);
    sint32 vertical = (r_u32(object + 24) - r_u32(object + 248)) << 16, divisor = time >> 16;
    if (divisor)
    {
        if (vertical == (sint32)0x80000000 && divisor == -1)
            abort();
        else
            vertical /= divisor;
    }
    w_u32(object + 492, vertical);
    draft_call_adapter(0x80029970, object, (sint16)r_u16(physical + 32), 0, 1, object + 244);
    if (r_u32(gp + 0x94) && (sint32)r_u32(object + 484) > 0 && (sint32)r_u32(0x800A7E10) > 0)
    {
        draft_call_adapter(0x80063450, object);
        draft_call_adapter(0x800361FC, r_u32(gp + 0x84), 192);
    }
    else if (r_u32(gp + 0x84) != 0xFFFFFFFF)
        draft_call_adapter(0x800361FC, r_u32(gp + 0x84), 0);
    uint32 distance = draft_call_adapter(0x80069BE0, r_u32(object + 244) - r_u32(object + 20), r_u32(object + 252) - r_u32(object + 28));
    w_u32(gp + 0x74, r_u32(gp + 0x74) + distance * (((sint32)r_u32(object + 472) >> 19) + 1));
    if (r_u32(gp + 0x74) > 100000)
    {
        if (!r_u32(gp + 0x6C))
            w_u16(0x800A7E10, r_u16(0x800A7E10) - 1);
        w_u32(gp + 0x74, 0);
    }
    if ((sint16)r_u16(0x800A7E10) <= 0)
    {
        w_u32(0x800A8538, 728160);
        w_u32(gp + 0x9C, 728160);
    }
    uint32 force_mask = 0, excluded_mask = 0;
    for (uint32 i = 0; i < 4; ++i)
    {
        excluded_mask |= (r_u16(object + 98 + 16 * i) & 15u) << i;
        force_mask |= (uint32)r_u8(object + (r_u16(object + 594) ? 584 : 588) + i) << i;
        w_u8(surface + i, r_u16(object + 594) ? r_u8(object + 582) : r_u8((uint32)-2146800736 + i));
    }
    draft_call_adapter(0x80061A78, object, object + 596, surface, force_mask, excluded_mask, 4u);
    w_u8(object + 581, 0);
    uint32 buttons = r_u16(0x800A8398);
    if (!(buttons & 64))
        w_u16(gp + 0x156C, 0);
    else if (!(r_u16(gp + 0x156C) & 64))
    {
        if ((sint16)draft_call_adapter(0x8003CB98, object) == -1)
            w_u16(gp + 0x156C, buttons);
        else
            w_u16(gp + 0x156C, 0);
    }
    if (buttons & 1)
        w_u8(object + 581, 1);
    else if (buttons & 2)
        w_u8(object + 581, 255);
    w_u32(object + 580, (r_u32(object + 580) & 0xFFFFFFF) | ((buttons & 4) ? 0x10000000 : 0));
    w_u16(0x800A84AC, (409 * ((sint32)r_u32(object + 472) >> 8)) >> 16);
    w_u32(0x800A7E20, r_u32(object + 28));
    w_u32(0x800A7E1C, r_u32(object + 24));
    w_u16(0x800A8518, r_u16(object + 226));
    w_u32(0x800A7E14, r_u32(object + 20));
    draft_call_adapter(0x80026BC4, r_u32(0x800A7BAC));
    if (!r_u32(0x800A9760))
    {
        if (r_u32(gp + 0x7C) == 1 && (sint32)r_u32(0x800A86A0) < 513)
        {
            w_u32(gp + 0x7C, 2);
            draft_call_adapter(0x80062D90, object + 552, object, 1);
        }
        if (!r_u32(gp + 0x7C) && (sint32)r_u32(0x800A86A0) < 1025)
        {
            w_u32(gp + 0x7C, 1);
            draft_call_adapter(0x80062D90, object + 552, object, 0);
        }
        if (r_u32(gp + 0x7C) == 2 && (sint32)r_u32(0x800A86A0) >= 513)
        {
            w_u32(gp + 0x7C, 1);
            draft_call_adapter(0x80062D90, object + 552, object, 0);
        }
        if (r_u32(gp + 0x7C) == 1 && (sint32)r_u32(0x800A86A0) >= 1025)
        {
            w_u32(gp + 0x7C, 0);
            w_u32(object + 552, 0);
        }
    }
    sint32 timer = r_u32(gp + 0x94);
    if (timer <= 0)
    {
        w_u32(0x800A8538, r_u32(gp + 0x9C));
        draft_call_adapter(0x80035988, r_u32(gp + 0x84));
        w_u32(gp + 0x84, -1);
    }
    else
    {
        timer -= r_u32(0x800A9010);
        w_u32(gp + 0x94, timer);
        if (timer <= 0)
        {
            w_u32(gp + 0x94, 0);
            w_u32(0x800A8538, r_u32(gp + 0x9C));
        }
    }
    uint32 below = 1, water = 0, fuel = 1, repair = 1;
    for (uint32 i = 0; i < 4; ++i)
    {
        uint32 t = r_u8(gp + 0x1578 + i);
        below &= t < 10;
        water |= t == 6;
        fuel &= t == 17;
        repair &= t == 18;
    }
    if (below)
    {
        draft_call_adapter(0x8002E310, object + 20, normal, terrainout);
        if (water && r_u16(terrainout) == 6 && !r_u8(object + 67))
        {
            w_u32(object, 0x80029968);
            w_u32(gp + 0x3A08, r_u8(0x800A7E83));
            draft_call_adapter(0x8005E2BC, 2);
            w_u32(gp + 0x7C, 0);
            w_u32(object + 552, 0);
            draft_call_adapter(0x80035988, r_u16(gp + 0x86));
            draft_call_adapter(0x80035988, r_u16(gp + 0x8C));
            w_u16(0x800A9734, 3);
            w_u32(object + 476, 0);
            w_u32(object + 480, 0);
            draft_call_adapter(0x80030F08, (sint16)r_u16(object + 74), (sint16)r_u16(object + 68), 1);
            w_u32(gp + 0xA0, 0);
            return draft_scratch_result(native_stack_mark, (uint64)(draft_call_adapter(0x80054934, object, 0)));
        }
    }
    else
    {
        if ((sint16)r_u16(0x800A7E10) < 100 && (sint32)r_u32(0x800A7C6C) > 0 && fuel)
        {
            sint16 countdown = r_u16(gp + 0x78) - (time >> 16);
            w_u16(gp + 0x78, countdown);
            if (countdown <= 0)
            {
                w_u16(gp + 0x78, 8);
                w_u16(0x800A7E10, r_u16(0x800A7E10) + 1);
                w_u32(0x800A7C6C, r_u32(0x800A7C6C) - 5);
                draft_call_adapter(0x80035A08, 54, 6000, 128, 0);
                if (r_u32(0x800A8538) == 728160)
                {
                    uint32 speed = 18204 * (sint16)draft_call_adapter(0x8003D654);
                    w_u32(0x800A8538, speed);
                    w_u32(gp + 0x9C, speed);
                }
            }
        }
        if ((sint32)r_u32(0x800A86A0) < 2048 && (sint32)r_u32(0x800A7C6C) > 0 && repair)
        {
            w_u32(0x800A5C4C, 4095);
            sint32 step = (sint16)(time >> 14), health = r_u32(0x800A86A0) + step;
            w_u32(0x800A86A0, health >= 2049 ? 2048 : health);
            w_u32(0x800A7C6C, r_u32(0x800A7C6C) - ((5 * step) >> 2));
            draft_call_adapter(0x80035A08, 54, 6000, 128, 0);
        }
    }
    if ((sint32)r_u32(0x800A7C6C) < 0)
        w_u32(0x800A7C6C, 0);
    w_u16(0x800A8704, 0);
    w_u16(0x800A8706, 0);
    uint32 result = r_u8(object + 14);
    if (r_u8(0x800A7E80))
        result |= r_u16(object + 32) == special ? 0x82 : 2;
    else
        result &= 0x7D;
    w_u8(object + 14, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
