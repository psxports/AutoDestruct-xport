#include "native_call_dispatch.h"

uint32 sub_80046DD4(uint32 object)
{
    uint32 result = r_u16(object + 70) - r_u16(0x800A9010);
    FUNCTION_MARKER(0x80046DD4, "1.EXE");
    w_u16(object + 70, result);
    result <<= 16;
    if ((sint32)result <= 0)
    {
        result = r_u8(object + 14);
        w_u32(object, 0x80046E9C);
        result |= 2;
        w_u8(object + 14, result);
    }
    return result;
}

uint32 sub_8004674C(uint32 object)
{
    uint32 result;
    FUNCTION_MARKER(0x8004674C, "1.EXE");
    result = sub_800465A8(object, 1);
    if (!result)
    {
        uint32 x, y, z;
        result = r_u32(0x800A7BAC);
        x = r_u32(result + 20);
        y = r_u32(result + 24);
        z = r_u32(result + 28);
        w_u32(object + 20, x);
        w_u32(object + 24, y);
        w_u32(object + 28, z);
    }
    return result;
}

uint32 sub_80061FF8(uint32 object)
{
    sint32 scale = r_s16(object + 10);
    uint32 row = object + 18;
    uint32 result, count;
    FUNCTION_MARKER(0x80061FF8, "1.EXE");
    if (scale < 500)
        return sub_8002289C(object);
    for (count = 3; count; --count)
    {
        sint32 z, x;
        row -= 6;
        z = r_s16(row + 38) * scale;
        x = r_s16(row + 36) * scale;
        w_u16(row + 38, (uint32)(z >> 12));
        w_u16(row + 36, (uint32)(x >> 12));
    }
    result = 100 * r_u32(0x800A9010);
    result = r_u16(object + 10) - result;
    w_u16(object + 10, result);
    return result;
}

uint32 sub_80045F94(uint32 object)
{
    FUNCTION_MARKER(0x80045F94, "1.EXE");
    if (r_s8(object + 66) <= 0)
    {
        sint32 index = r_s16(object + 62);
        w_u8(object + 65, 0);
        if (index != -1)
        {
            uint32 other = r_u32(r_u32(0x800A851C) + 4 * (uint32)index);
            if (!r_u8(other + 64))
            {
                w_u8(other + 66, r_u8(other + 66) - 1);
                w_u16(object + 62, 0xFFFF);
            }
        }
        w_u32(object, 0x80029968);
        return 0x80029968;
    }
    return 0xFFFFFFFF;
}

uint32 sub_80040E94(uint32 object)
{
    uint32 step = r_u32(0x800A9010) << 2;
    uint32 remaining = r_u32(object + 8) - step;
    FUNCTION_MARKER(0x80040E94, "1.EXE");
    w_u32(object + 8, remaining);
    if ((sint32)remaining < 0)
        sub_8002289C(object);
    step = r_u32(0x800A9010) << 2;
    w_u32(object + 24, r_u32(object + 24) - step);
    return step;
}

uint32 sub_80068DD8(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 previous = draft_scratch_adapter(12);
    uint32 tick, result, turn_x, turn_y;
    sint32 speed;
    FUNCTION_MARKER(0x80068DD8, "1.EXE");
    w_u32(previous, r_u32(object + 20));
    w_u32(previous + 4, r_u32(object + 24));
    w_u32(previous + 8, r_u32(object + 28));
    speed = r_s16(object + 66);
    tick = r_u32(0x800A9010);
    if (speed <= 0)
    {
        uint32 next_speed = r_u16(object + 66) + tick;
        w_u32(object + 24, r_u32(object + 24) + (uint32)speed);
        w_u16(object + 66, next_speed);
    }
    else
    {
        uint32 heading = r_u16(object + 74) & 0xFFF;
        uint32 component, z;
        w_u32(object + 24, r_u32(object + 24) + 2 * tick);
        component = (uint32)((r_s16(object + 80) * r_s16(0x80010AE0 + 2 * heading)) >> 12);
        w_u16(object + 72, component);
        heading = r_u16(object + 74) & 0xFFF;
        component = (uint32)(r_s16(object + 80) * r_s16(0x800102E0 + 2 * heading));
        z = r_u32(object + 28);
        result = (uint32)r_s16(object + 72);
        w_u16(object + 74, r_u16(object + 74) + 20 * tick);
        result += z;
        z = result + (uint32)r_s16(object + 72);
        w_u32(object + 28, result);
        w_u32(object + 28, z);
        z = r_u32(object + 20);
        component = (uint32)((sint32)component >> 12);
        w_u16(object + 68, component);
        w_u32(object + 20, z + (uint32)(sint32)(sint16)component);
        if ((uint16)sub_80030678(previous, object + 20))
            sub_8002289C(object);
    }
    turn_x = (uint32)r_s16(object + 78) * tick;
    turn_y = (uint32)r_s16(object + 76) * tick;
    w_u16(object + 60, r_u16(object + 60) + turn_x);
    w_u16(object + 62, r_u16(object + 62) + turn_y);
    result = sub_80055288(object + 60, object + 36);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_80062E70(uint32 object)
{
    uint32 slot_owner = r_u32(r_u32(object + 16));
    uint32 owner = r_u32(object + 8);
    uint32 x, y, z, result, particle, kind;
    FUNCTION_MARKER(0x80062E70, "1.EXE");
    if (slot_owner != object || (!(r_u8(owner + 14) & 2) && (r_u8(owner + 13) & 0x7F) != 1))
        return sub_8002289C(object);
    if (r_u8(object + 12) < 4)
        return 1;
    owner = r_u32(object + 8);
    x = r_u32(owner + 20);
    y = r_u32(owner + 24);
    z = r_u32(owner + 28);
    w_u32(object + 20, x);
    w_u32(object + 24, y);
    w_u32(object + 28, z);
    result = r_u8(object + 13) - r_u8(0x800A9010);
    w_u8(object + 13, result);
    result <<= 24;
    if ((sint32)result >= 0)
        return result;
    kind = r_u8(object + 35);
    particle = sub_800227C4(40);
    x = r_u32(object + 20);
    y = r_u32(object + 24);
    z = r_u32(object + 28);
    w_u32(particle + 20, x);
    w_u32(particle + 24, y);
    w_u32(particle + 28, z);
    w_u8(particle + 34, 8);
    w_u16(particle + 36, 75);
    w_u16(particle + 38, 0);
    w_u16(particle + 32, r_u16(r_u32(0x800A62EC) + (kind ? 0x50 : 0x58)));
    result = r_u8(particle + 14);
    w_u32(particle, 0x80063008);
    w_u8(particle + 14, result | 2);
    w_u16(particle + 8, (sub_80069A50() & 0x1F) + 48);
    w_u16(particle + 10, (sub_80069A50() & 0x3F) - 31);
    w_u16(particle + 18, 8);
    w_u16(particle + 16, kind);
    w_u8(object + 13, 8);
    return 8;
}

uint32 sub_80067690(uint32 object)
{
    uint32 remaining, offset = 0;
    FUNCTION_MARKER(0x80067690, "1.EXE");
    if (r_u8(object + 12) < 4)
        return 1;
    remaining = r_u32(0x800A9010);
    while ((sint32)remaining > 0)
    {
        uint32 particle = sub_800227C4(40);
        uint32 result, models, model, x, y, z;
        w_u8(particle + 34, 11);
        w_u16(particle + 36, 100);
        result = sub_80069A50();
        models = r_u32(0x800A62EC);
        --remaining;
        w_u16(particle + 38, result);
        result = r_u8(particle + 14);
        model = r_u16(models + 0x15E);
        w_u8(particle + 14, result | 2);
        w_u16(particle + 32, model);
        x = r_u32(object + 20);
        y = r_u32(object + 24);
        z = r_u32(object + 28);
        w_u32(particle + 20, x);
        w_u32(particle + 24, y);
        w_u32(particle + 28, z);
        w_u32(particle, 0x800677A4);
        w_u16(particle + 8, sub_80069A50());
        result = sub_80069A50() & 7;
        y = r_u32(particle + 24);
        w_u16(particle + 10, result + 48);
        result = r_u16(object + 24);
        y -= offset;
        offset += 50;
        w_u16(particle + 16, result);
        w_u32(particle + 24, y);
    }
    return sub_800369E0(object + 20, object + 13, 2048, 68);
}

uint32 sub_800677A4(uint32 object)
{
    uint32 heading = r_u16(object + 8) & 0xFFF;
    uint32 tick = r_u32(0x800A9010);
    uint32 step = tick << 2;
    uint32 product = step * (uint32)r_s16(0x80010AE0 + 2 * heading);
    uint32 result, fall;
    sint32 speed;
    FUNCTION_MARKER(0x800677A4, "1.EXE");
    heading = r_u16(object + 8) & 0xFFF;
    w_u32(object + 20, r_u32(object + 20) + (uint32)((sint32)product >> 12));
    product = step * (uint32)r_s16(0x800102E0 + 2 * heading);
    fall = (uint32)r_s16(object + 10) * tick;
    speed = r_s16(object + 10);
    w_u32(object + 28, r_u32(object + 28) + (uint32)((sint32)product >> 12));
    w_u32(object + 24, r_u32(object + 24) - fall);
    result = r_u16(object + 36);
    result = speed > 0 ? result + 2 * tick : result - 2 * tick;
    w_u16(object + 36, result);
    result = r_u16(object + 10) - tick;
    speed = r_s16(object + 16);
    fall = r_u32(object + 24);
    w_u16(object + 10, result);
    if (speed < (sint32)fall)
        return sub_8002289C(object);
    return result;
}

uint32 sub_8003E454(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 previous, velocity, result, x, y, z;
    sint32 timer = r_s16(object + 56);
    FUNCTION_MARKER(0x8003E454, "1.EXE");
    if (timer)
    {
        result = sub_8002A5DC(object, (uint32)timer);
        draft_scratch_release(mark);
        return result;
    }
    previous = draft_scratch_adapter(12);
    velocity = draft_scratch_adapter(12);
    x = r_u32(object + 20);
    y = r_u32(object + 24);
    z = r_u32(object + 28);
    w_u32(previous, x);
    w_u32(previous + 4, y);
    w_u32(previous + 8, z);
    result = (0u - r_u32(0x800A9010)) * (uint32)r_s16(object + 8);
    w_u32(velocity, 0);
    w_u32(velocity + 4, 0);
    w_u32(velocity + 8, result);
    sub_80031E30(object + 36, object + 20, velocity);
    w_u16(object + 10, r_u16(object + 10) - r_u16(velocity + 8));
    x = r_u32(previous);
    y = r_u32(previous + 4);
    z = r_u32(previous + 8);
    w_u32(velocity, x);
    w_u32(velocity + 4, y);
    w_u32(velocity + 8, z);
    if (r_s16(object + 10) >= 20000)
        result = sub_8002289C(object);
    else if ((uint16)sub_8002F3FC(velocity, object + 20))
    {
        if (!(sub_80069A50() & 0x3F))
        {
            w_u16(object + 56, 7);
            result = 7;
        }
        else
        {
            sub_80060D20(object, velocity);
            sub_8002A8F0(object);
            result = sub_80029970(object, 136, 6, 1, previous);
        }
    }
    else
    {
        if ((uint16)sub_80030678(velocity, object + 20))
            sub_8002A8F0(object);
        result = sub_80029970(object, 136, 6, 1, previous);
    }
    draft_scratch_release(mark);
    return result;
}
