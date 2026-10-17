#include "native_call_dispatch.h"

static uint32 actor_remaining_near(uint32 first, uint32 second, sint32 limit)
{
    uint32 difference = first - second;
    if ((sint32)difference < 0)
        difference = second - first;
    return (sint32)difference < limit;
}

static uint32 actor_remaining_half_height(uint32 object, uint32 mapping, uint32 physics)
{
    uint32 model = r_u16(object + 32);
    uint32 index = r_u8(mapping + model);
    return (uint32)(r_s16(physics + 40 * index + 32) >> 1);
}

static uint32 actor_remaining_height(uint32 object)
{
    uint32 model = r_u16(object + 32);
    uint32 mapping = r_u32(0x800A8548);
    uint32 index = r_u8(mapping + model);
    uint32 physics = r_u32(0x800A90AC);
    return (uint32)(r_s16(physics + 40 * index + 32) >> 1);
}

uint32 sub_8004EDF0(uint32 object)
{
    uint32 result, mark, scratch, velocity, previous, collision, normal, flags;
    uint32 x, y, z, mode, half, target_y, mapping, physics, model;
    FUNCTION_MARKER(0x8004EDF0, "1.EXE");
    result = sub_8004D04C(object);
    if (result)
    {
        if ((sint32)result >= 0)
        {
            w_u32(object, 0x80029968);
            return 0x80029968;
        }
        w_u32(object, 0x8004EC84);
    }
    mark = draft_scratch_mark();
    scratch = draft_scratch_adapter(72);
    velocity = scratch;
    previous = scratch + 16;
    collision = scratch + 32;
    normal = scratch + 48;
    flags = scratch + 56;
    x = r_u32(object + 128);
    y = r_u32(object + 132);
    z = r_u32(object + 136);
    w_u32(previous, x);
    w_u32(previous + 4, y);
    w_u32(previous + 8, z);
    w_u32(0x800A6EF4, previous);
    w_u32(0x800A6F9C, object);
    w_u16(0x800A6FB4, 1);
    sub_8004BC94(0x800A6F9C);
    w_u32(velocity, r_u32(object + 100));
    w_u32(velocity + 8, r_u32(object + 104));
    mode = r_u8(object + 198);
    if (mode == 12 || (r_u8(object + 12) >= 4 && (r_u32(object + 208) & 0xF0000) && (r_u32(object + 224) & 0xF0000) && (r_u32(object + 240) & 0xF0000) && (r_u32(object + 256) & 0xF0000)))
        sub_80048F9C(object + 20, velocity, object + 182, mode);
    else
    {
        w_u32(0x800A6FC4, r_u16(object + 178));
        result = r_u16(object + 178);
        w_u32(0x800A6FB8, object);
        w_u32(0x800A6FC0, velocity);
        w_u32(0x800A6FC8, result >> 6);
        w_u32(collision, r_u32(object + 92));
        w_u32(collision + 8, r_u32(object + 96));
        y = r_u32(object + 24);
        w_u32(0x800A6FBC, collision);
        w_u32(collision + 4, y);
        result = sub_80055764((uint32)r_s16(object + 360), (uint32)r_s16(object + 180), 20);
        w_u16(object + 360, result);
        sub_80047CF0(0x800A6FB8);
    }
    if (r_u8(object + 12) >= 4)
    {
        // Original fifth stack argument is unread by 4CAD4
        sub_8004CAD4(object, velocity, previous, object + 200);
        sub_8004ED64(object);
        model = r_u16(object + 32);
        mapping = r_u32(0x800A8548);
        model = r_u8(mapping + model);
        physics = r_u32(0x800A90AC);
        sub_80029970(object, (uint32)r_s16(physics + 40 * model + 32), 2, 1, previous);
        sub_800369E0(object + 20, object + 194, 1536, 52);
    }
    else
    {
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
            result = (uint32)r_s16(object + 170);
            if ((sint32)result > 0)
                w_u16(object + 170, result - 1);
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
        half = actor_remaining_height(object);
        w_u32(object + 24, r_u32(object + 24) + half);
        result = (uint32)draft_call_adapter(0x8002E310, object + 20, normal, flags);
        half = actor_remaining_height(object);
        y = r_u32(object + 24);
        target_y = 0 - result - half;
        if (!actor_remaining_near(y, target_y, 512))
            target_y = r_u32(object + 24) - actor_remaining_height(object);
        w_u32(object + 24, target_y);
        mapping = r_u32(0x800A8548);
        physics = r_u32(0x800A90AC);
        for (uint32 i = 0; i < 4; ++i)
        {
            uint32 contact = object + 16 * i;
            w_u16(contact + 202, target_y);
            w_u16(contact + 200, target_y);
            half = actor_remaining_half_height(object, mapping, physics);
            result = r_u32(contact + 208) & 0xFFF0FFFF;
            w_u32(contact + 208, result);
            w_u16(contact + 204, target_y + half);
        }
        model = r_u16(object + 32);
        w_u8(object + 266, 0);
        w_u8(object + 267, 0);
        mapping = r_u32(0x800A8548);
        w_u16(object + 264, target_y);
        model = r_u8(mapping + model);
        physics = r_u32(0x800A90AC);
        half = (uint32)(r_s16(physics + 40 * model + 32) >> 1);
        w_u32(object + 268, target_y + half);
        sub_80036CFC(object + 194);
    }
    w_u32(object + 100, r_u32(velocity));
    w_u32(object + 104, r_u32(velocity + 8));
    result = r_u32(object + 20);
    y = r_u32(object + 24);
    z = r_u32(object + 28);
    w_u32(object + 128, result);
    w_u32(object + 132, y);
    w_u32(object + 136, z);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_80047194(uint32 object)
{
    uint32 result, phase, limit, player, x, z, mark, local, height, animation, frame;
    FUNCTION_MARKER(0x80047194, "1.EXE");
    if (sub_80045E18(object, object + 72) || sub_80045DD4(object))
    {
        result = 0x80029968;
        phase = r_u8(object + 67);
        w_u32(object, result);
        if (phase)
        {
            phase = (uint32)r_s16(0x800A9730);
            result = r_u32(r_u32(0x800A851C) + 4 * phase);
            if (result == object)
                return sub_8004525C();
        }
        return result;
    }
    if (r_u8(object + 67) && !r_u32(0x800A9760))
        sub_800451B4(object + 20, (uint32)r_s16(object + 68));
    if (r_u8(object + 12) < 5)
        return 1;
    phase = ((uint32)(r_s32(0x800A63D8) >> 8) << 7) + r_u32(object + 456);
    animation = (uint32)r_s16(object + 452);
    w_u32(object + 456, phase);
    limit = (uint32)r_s16(0x8008FD1C + 2 * animation) << 16;
    if ((sint32)phase >= (sint32)limit)
        w_u32(object + 456, phase - limit);
    player = r_u32(0x800A7BAC);
    x = r_u32(player + 20) - r_u32(object + 20);
    z = r_u32(player + 28) - r_u32(object + 28);
    result = sub_80055A9C(x, z);
    sub_80055D54(object, object + 88, (uint32)(sint32)(sint16)result);
    mark = draft_scratch_mark();
    local = draft_scratch_adapter(16);
    height = (uint32)draft_call_adapter(0x8002E310, object + 20, local, local + 8);
    animation = (uint32)r_s16(object + 452);
    frame = (uint32)r_s16(object + 458);
    animation = r_u32(0x8008FCFC + 4 * animation);
    height = 0 - height - (uint32)r_s16(animation + 64 * frame) + 40;
    w_u32(object + 24, height);
    draft_scratch_release(mark);
    player = r_u32(0x800A7BAC);
    if (!actor_remaining_near(r_u32(object + 20), r_u32(player + 20), 501))
        return 0;
    player = r_u32(0x800A7BAC);
    if (!actor_remaining_near(r_u32(object + 28), r_u32(player + 28), 501))
        return 0;
    player = r_u32(0x800A7BAC);
    if (!actor_remaining_near(r_u32(object + 24), r_u32(player + 24), 401))
        return 0;
    sub_80046A58(object);
    w_u32(object, 0x80029968);
    return 0x80029968;
}

uint32 sub_8004F3D4(void)
{
    uint32 values[26];
    FUNCTION_MARKER(0x8004F3D4, "1.EXE");
    for (uint32 i = 0; i < 26; ++i)
        values[i] = r_u32(0x800A6158 + 4 * i);
    for (uint32 i = 0; i < 26; ++i)
        w_u32(0x800A602C + 4 * i, values[i]);
    return values[20];
}

uint32 sub_8002E0B4(uint32 object, uint32 mask, uint32 velocity)
{
    FUNCTION_MARKER(0x8002E0B4, "1.EXE");
    if ((mask & 0x81) == 0x81 || (mask & 0x24) == 0x24)
        w_u16(object + 80, (uint32)r_u16(velocity) << 4);
    if ((mask & 0x48) == 0x48 || (mask & 0x12) == 0x12)
        w_u16(object + 80, (uint32)r_u16(velocity + 8) << 4);
    if ((mask & 0x11) == 0x11 || (mask & 0x88) == 0x88)
        w_u16(object + 80, 0 - ((uint32)r_u16(velocity + 8) << 4));
    if ((mask & 0x22) == 0x22 || (mask & 0x44) == 0x44)
        w_u16(object + 80, 0 - ((uint32)r_u16(velocity) << 4));
    return sub_8002AF4C(object, mask & 0xFFFF, velocity);
}
