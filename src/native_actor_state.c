#include "native_call_dispatch.h"

uint32 sub_8004DBD4(uint32 object)
{
    FUNCTION_MARKER(0x8004DBD4, "1.EXE");
    if (r_u8(object + 12) < 4)
    {
        w_u8(object + 14, 1);
        w_u32(object, 0x80045510);
        return 0x80045510;
    }
    return 1;
}

uint32 sub_8004DC00(uint32 object)
{
    FUNCTION_MARKER(0x8004DC00, "1.EXE");
    w_u8(object + 14, r_u8(object + 14) & 0xF7);
    sub_8004D8B4(object);
    sub_80030F08((uint32)r_s16(object + 74), (uint32)r_s16(object + 68), 1);
    sub_80063418(object);
    w_u32(object, 0x8004DBD4);
    return 0x8004DBD4;
}

static uint32 actor_animation_step(void)
{
    return 4 * (uint32)(r_s32(0x800A63D8) / 5);
}

static uint32 actor_animation_length(uint32 object)
{
    return (uint32)r_s16(0x8008FD1C + 2 * (uint32)r_s16(object + 564));
}

static void actor_animation_sound(uint32 object)
{
    uint32 pitch = (sub_80069A50() & 0x3FF) + 1536;
    draft_call_adapter(0x80035A08, 45, pitch, 0, object + 20, 0);
}

uint32 sub_8004DC5C(uint32 object)
{
    uint32 mark, scratch, clock, limit, value, surface, frame;
    sint32 animation, speed;
    FUNCTION_MARKER(0x8004DC5C, "1.EXE");
    if (r_u8(object + 12) < 4)
        return 1;
    speed = (sint32)sub_80069BE0(r_u32(object + 100), r_u32(object + 104));
    if (r_u16(object + 56) || r_s16(object + 566))
    {
        if (!r_s16(object + 566))
        {
            if (r_s16(object + 564) != 3)
            {
                actor_animation_sound(object);
                w_u32(object + 568, 0);
            }
            w_u16(object + 564, 3);
            w_u16(object + 566, 1);
        }
    }
    else if (speed)
        w_u16(object + 564, speed >= 1024);
    else
    {
        if (r_s16(object + 70) || r_s16(object + 164))
            w_u32(object + 568, 0);
        animation = r_s16(object + 564);
        if (animation != 2 && animation != 6)
            w_u16(object + 564, 2);
    }
    animation = r_s16(object + 564);
    switch (animation)
    {
        case 3:
            clock = r_u32(object + 568) + actor_animation_step();
            w_u32(object + 568, clock);
            value = (uint32)r_u16(0x8008FD1C + 2 * (uint32)r_s16(object + 564)) << 16;
            value = (uint32)((sint32)value >> 17) << 16;
            if ((sint32)clock >= (sint32)value)
                w_u16(object + 566, 2);
            limit = (actor_animation_length(object) - 1) << 16;
            if (r_s32(object + 568) >= (sint32)limit)
            {
                value = r_u16(object + 56);
                w_u32(object + 568, limit);
                if (!value)
                {
                    w_u16(object + 566, 1);
                    w_u32(object + 568, 0);
                    w_u16(object + 564, 4);
                }
                if (r_s16(object + 58) <= 0)
                    return sub_8004DC00(object);
            }
            break;
        case 4:
            value = r_u16(object + 56);
            w_u32(object + 100, 0);
            w_u32(object + 104, 0);
            if (!value && r_s16(object + 566) != 2)
            {
                clock = r_u32(object + 568) + actor_animation_step();
                w_u32(object + 568, clock);
                limit = (actor_animation_length(object) - 1) << 16;
                if ((sint32)clock >= (sint32)limit)
                {
                    w_u32(object + 568, limit);
                    w_u16(object + 566, 0);
                }
            }
            else
            {
                if (!r_s16(object + 566))
                    actor_animation_sound(object);
                value = actor_animation_step();
                w_u16(object + 566, 2);
                clock = r_u32(object + 568) - value;
                w_u32(object + 568, clock);
                if ((sint32)clock <= 0)
                {
                    value = r_u16(object + 56);
                    w_u32(object + 568, 0);
                    if (!value)
                        w_u16(object + 566, 1);
                    if (r_s16(object + 58) <= 0)
                        return sub_8004DC00(object);
                }
            }
            break;
        case 2:
            clock = r_u32(object + 568) + actor_animation_step();
            w_u32(object + 568, clock);
            limit = actor_animation_length(object) << 16;
            if ((sint32)clock >= (sint32)limit)
            {
                w_u16(object + 564, 6);
                w_u32(object + 568, 0);
            }
            break;
        case 6:
            w_u32(object + 568, 0);
            if ((sub_80069A50() & 0xFF) < 5)
                w_u16(object + 564, 2);
            break;
        default:
            clock = r_u32(object + 568) + actor_animation_step();
            w_u32(object + 568, clock);
            limit = actor_animation_length(object) << 16;
            if ((sint32)clock >= (sint32)limit)
                w_u32(object + 568, clock - limit);
            else if ((sint32)clock < 0)
                w_u32(object + 568, limit + clock);
            break;
    }
    mark = draft_scratch_mark();
    scratch = draft_scratch_adapter(24);
    w_u16(scratch, 0);
    surface = (uint32)draft_call_adapter(0x8002E310, object + 20, scratch + 8, scratch);
    animation = r_s16(object + 564);
    frame = r_u32(0x8008FCFC + 4 * (uint32)animation) + 64 * (uint32)r_s16(object + 570);
    surface = 0u - surface - (uint32)r_s16(frame);
    value = r_u32(object + 24) - surface;
    if ((sint32)value < 0)
        value = surface - r_u32(object + 24);
    if ((sint32)value < 400)
        w_u32(object + 24, surface);
    value = r_s16(scratch) == 6;
    draft_scratch_release(mark);
    if (value)
        return sub_8004BBBC(object, 1);
    return 6;
}

uint32 sub_8004E130(uint32 object, uint32 velocity)
{
    uint32 mark = draft_scratch_mark();
    uint32 previous = draft_scratch_adapter(12);
    uint32 x, y, z, result;
    FUNCTION_MARKER(0x8004E130, "1.EXE");
    x = r_u32(object + 128);
    y = r_u32(object + 132);
    z = r_u32(object + 136);
    w_u32(previous, x);
    w_u32(previous + 4, y);
    w_u32(previous + 8, z);
    if ((uint16)sub_8002F3FC(previous, object + 20))
    {
        if (!r_u8(object + 88))
        {
            x = r_u32(object + 128);
            y = r_u32(object + 132);
            z = r_u32(object + 136);
            w_u32(object + 20, x);
            w_u32(object + 24, y);
            w_u32(object + 28, z);
            sub_8004C8A8(object);
        }
        x = r_u32(velocity) << 8;
        z = r_u32(velocity + 8) << 8;
        w_u32(velocity, x);
        w_u32(velocity + 8, z);
        sub_80023918(r_u32(previous), r_u32(previous + 8), velocity, velocity + 8);
        x = (uint32)(r_s32(velocity) >> 8);
        z = (uint32)(r_s32(velocity + 8) >> 8);
        w_u32(velocity, x);
        w_u32(velocity + 8, z);
    }
    else
        w_u8(object + 88, 0);
    if (r_s16(object + 566) != 2)
        sub_80029970(object, 250, 3, 1, object + 20);
    result = sub_80055D54(object, object + 200, (uint32)r_s16(object + 182));
    draft_scratch_release(mark);
    return result;
}

uint32 sub_8004E244(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 result, velocity, target, x, y, z;
    FUNCTION_MARKER(0x8004E244, "1.EXE");
    result = sub_8004D04C(object);
    if (result)
    {
        if ((sint32)result >= 0)
        {
            w_u32(object, 0x80029968);
            draft_scratch_release(mark);
            return 0x80029968;
        }
        w_u32(object, 0x8004E3F0);
    }
    w_u32(0x800A6EF4, 0);
    sub_8004DC5C(object);
    w_u32(0x800A6F9C, object);
    w_u16(0x800A6FB4, 0);
    sub_8004BC94(0x800A6F9C);
    velocity = draft_scratch_adapter(12);
    target = draft_scratch_adapter(12);
    w_u32(velocity, r_u32(object + 100));
    w_u32(velocity + 8, r_u32(object + 104));
    if (r_s16(object + 566) == 1 || r_u8(object + 198) == 12)
        sub_80048F9C(object + 20, velocity, object + 182, r_u8(object + 198));
    else
    {
        w_u32(0x800A6FC4, r_u16(object + 178));
        result = r_u16(object + 178);
        w_u32(0x800A6FB8, object);
        w_u32(0x800A6FC0, velocity);
        w_u32(0x800A6FC8, result >> 6);
        w_u32(target, r_u32(object + 92));
        y = r_u32(object + 96);
        w_u32(0x800A6FBC, target);
        w_u32(target + 8, y);
        if (r_s16(object + 566) != 2 && r_u8(object + 198) != 12)
            sub_800487C0(0x800A6FB8);
    }
    if (r_u8(object + 12) < 4)
        w_u8(object + 14, r_u8(object + 14) & 0xFD);
    else
    {
        w_u8(object + 14, r_u8(object + 14) | 2);
        sub_8004E130(object, velocity);
    }
    w_u32(object + 100, r_u32(velocity));
    w_u32(object + 104, r_u32(velocity + 8));
    x = r_u32(object + 20);
    y = r_u32(object + 24);
    z = r_u32(object + 28);
    w_u32(object + 128, x);
    w_u32(object + 132, y);
    w_u32(object + 136, z);
    w_u16(object + 56, 0);
    draft_scratch_release(mark);
    return x;
}

uint32 sub_8004E3F0(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 result, velocity, y, z;
    FUNCTION_MARKER(0x8004E3F0, "1.EXE");
    result = sub_80045AD8(object, 0x8004E244);
    if (!result)
    {
        result = r_u8(object + 14) & 2;
        if (result)
        {
            result = r_u8(object + 12) < 4;
            if (!result)
            {
                sub_8004DC5C(object);
                velocity = draft_scratch_adapter(12);
                w_u32(velocity, r_u32(object + 100));
                w_u32(velocity + 8, r_u32(object + 104));
                sub_80048F9C(object + 20, velocity, object + 182, r_u8(object + 198));
                sub_8004E130(object, velocity);
                w_u32(object + 100, r_u32(velocity));
                w_u32(object + 104, r_u32(velocity + 8));
                result = r_u32(object + 20);
                y = r_u32(object + 24);
                z = r_u32(object + 28);
                w_u32(object + 128, result);
                w_u32(object + 132, y);
                w_u32(object + 136, z);
            }
        }
    }
    w_u16(object + 56, 0);
    draft_scratch_release(mark);
    return result;
}
