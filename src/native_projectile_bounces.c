#include "native_call_dispatch.h"

static uint32 projectile_advance_age(uint32 object)
{
    uint32 tick = (uint32)((sint32)(r_u32(0x800A63D8) + 512) >> 10);
    uint32 increment = (uint32)((sint32)(tick + 32) >> 6);
    uint32 age = r_u16(object + 82) + increment;
    w_u16(object + 82, age);
    return age;
}

uint32 sub_8006CF20(uint32 owner, uint32 damage)
{
    uint32 mark = draft_scratch_mark();
    uint32 offset = draft_scratch_adapter(8);
    uint32 projectile, models, flags, model, result;
    FUNCTION_MARKER(0x8006CF20, "1.EXE");
    w_u32(offset, r_u32(0x800A6410));
    w_u32(offset + 4, r_u32(0x800A6414));
    projectile = sub_8006C094(owner, offset, 30720, 0, (uint32)-600, 1, (uint32)-16, 0, 0, 0);
    models = r_u32(0x800A62EC);
    w_u32(projectile + 76, 1024);
    w_u32(projectile, 0x8006CE00);
    flags = r_u8(projectile + 14);
    w_u32(projectile + 72, 0);
    w_u16(projectile + 82, 0);
    w_u32(projectile + 16, owner);
    w_u16(projectile + 58, damage);
    model = r_u16(models + 0xF2);
    w_u8(projectile + 14, flags | 2);
    w_u16(projectile + 32, model);
    result = (uint32)draft_call_adapter(0x80035A08, 17, 2048, 0xFF, projectile + 20, 0);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_8006D3D4(uint32 owner, uint32 damage)
{
    uint32 mark = draft_scratch_mark();
    uint32 offset = draft_scratch_adapter(8);
    uint32 projectile, models, flags, model, result;
    FUNCTION_MARKER(0x8006D3D4, "1.EXE");
    w_u32(offset, r_u32(0x800A6410));
    w_u32(offset + 4, r_u32(0x800A6414));
    projectile = sub_8006C094(owner, offset, 30720, 0, (uint32)-600, 1, (uint32)-16, 0, 0, 0);
    models = r_u32(0x800A62EC);
    w_u32(projectile + 76, 1024);
    w_u32(projectile, 0x8006D010);
    flags = r_u8(projectile + 14);
    w_u32(projectile + 72, 0);
    w_u16(projectile + 82, 0);
    w_u32(projectile + 16, owner);
    w_u16(projectile + 58, damage);
    w_u16(projectile + 128, 0);
    model = r_u16(models + 0xF2);
    w_u8(projectile + 14, flags | 2);
    w_u16(projectile + 32, model);
    result = (uint32)draft_call_adapter(0x80035A08, 17, 2048, 0xFF, projectile + 20, 0);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_8006CE00(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 previous, x, y, z, result;
    sint32 surface;
    FUNCTION_MARKER(0x8006CE00, "1.EXE");
    if (r_u16(object + 56))
    {
        result = sub_8002A5DC(object, (uint32)r_s16(object + 56));
        goto finished;
    }
    projectile_advance_age(object);
    previous = draft_scratch_adapter(12);
    x = r_u32(object + 20);
    y = r_u32(object + 24);
    z = r_u32(object + 28);
    w_u32(previous, x);
    w_u32(previous + 4, y);
    w_u32(previous + 8, z);
    sub_8006C94C(object, 102400, 512);
    if ((uint16)sub_8002F3FC(previous, object + 20))
        sub_8002A8F0(object);
    else
    {
        surface = (sint16)sub_80030678(previous, object + 20);
        if (surface == 6)
        {
            sub_80054934(object, 3);
            result = sub_8002289C(object);
            goto finished;
        }
        if (surface)
            sub_8002A8F0(object);
    }
    result = sub_80029970(object, 136, 6, 1, previous);
finished:
    draft_scratch_release(mark);
    return result;
}

uint32 sub_8006D010(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 scratch, x, y, z, value, ground_y, grounded = 0, result;
    uint32 first_difference, difference, velocity, heading;
    FUNCTION_MARKER(0x8006D010, "1.EXE");
    if (!r_u8(object + 12))
    {
        result = sub_8002289C(object);
        goto finished;
    }
    if (r_u16(object + 56))
    {
        result = sub_8002A5DC(object, (uint32)r_s16(object + 56));
        goto finished;
    }
    value = projectile_advance_age(object);
    if ((sint16)value >= 1201)
        goto destroy;
    scratch = draft_scratch_adapter(32);
    x = r_u32(object + 20);
    y = r_u32(object + 24);
    z = r_u32(object + 28);
    w_u32(0x800A74E4, x);
    w_u32(0x800A74E8, y);
    w_u32(0x800A74EC, z);
    x = r_u32(0x800A74E4);
    y = r_u32(0x800A74E8);
    w_u32(0x800A74D8, x);
    w_u32(0x800A74DC, y);
    w_u32(0x800A74E0, r_u32(0x800A74EC));
    value = (uint32)draft_call_adapter(0x8002E310, 0x800A74D8, scratch, scratch + 8);
    first_difference = value + r_u32(object + 24);
    // Both original paths repeat the height query before the near-surface test
    value = (uint32)draft_call_adapter(0x8002E310, 0x800A74D8, scratch, scratch + 8);
    difference = value + r_u32(object + 24);
    if ((sint32)first_difference < 0)
        difference = 0 - difference;
    if ((sint32)difference < 10)
    {
        velocity = r_u32(object + 64);
        if ((sint32)velocity < 0)
            velocity = 0 - velocity;
        if ((sint32)velocity < 5120)
        {
            sub_8006A5AC(object, 5120, 0x800A74F0, scratch + 16);
            grounded = 1;
            ground_y = r_u32(object + 24);
            value = sub_80069BE0(r_u32(0x800A74D8) - r_u32(object + 20), r_u32(0x800A74E0) - r_u32(object + 28));
            x = r_u32(object + 60);
            y = r_u16(object + 128);
            z = r_u32(object + 68);
            w_u16(object + 128, y - (value << 4));
            heading = sub_80055A9C(x, z);
            draft_call_adapter(0x80054D38, r_u16(object + 128), heading, 0, object + 36);
            goto moved;
        }
    }
    sub_8006C94C(object, 102400, 512);
    ground_y = 0 - (uint32)draft_call_adapter(0x8002E310, object + 20, 0x800A74F0, scratch + 16);
moved:
    w_u32(0x800A74E8, r_u32(0x800A74E8) - 20);
    if ((uint16)sub_8002F3FC(0x800A74E4, object + 20))
    {
        x = r_u32(0x800A74E4);
        z = r_u32(0x800A74EC);
        w_u32(scratch + 20, r_u32(object + 60) << 6);
        w_u32(scratch + 24, r_u32(object + 68) << 6);
        sub_80023918(x, z, scratch + 20, scratch + 24);
        x = (uint32)((sint32)(r_u32(scratch + 20) + 32) >> 6);
        z = (uint32)((sint32)(r_u32(scratch + 24) + 32) >> 6);
        w_u32(object + 60, x);
        value = r_u8(object + 12);
        w_u32(object + 68, z);
    }
    else
    {
        if (!ground_y)
            goto destroy;
        if (r_s32(object + 24) < (sint32)ground_y)
            goto effects;
        if (r_s16(scratch + 16) == 6)
        {
            sub_80054934(object, 3);
            result = sub_8002289C(object);
            goto finished;
        }
        if (grounded)
            goto effects;
        sub_8006CC30(0x800A74F0, object + 60);
        w_u32(object + 24, ground_y);
        value = r_u8(object + 12);
    }
    result = value < 3;
    if (result)
        goto finished;
    draft_call_adapter(0x80035A08, 2, 2048, 0, object + 20, 0);
effects:
    result = grounded;
    if (r_u8(object + 12) >= 3)
        result = sub_80029970(object, 136, grounded ? 4 : 6, 1, 0x800A74D8);
    goto finished;
destroy:
    sub_8002A8F0(object);
    result = sub_8002A5DC(object, (uint32)r_s16(object + 56));
finished:
    draft_scratch_release(mark);
    return result;
}
