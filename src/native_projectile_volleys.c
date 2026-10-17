#include "native_call_dispatch.h"

static uint32 volley_find_target(uint32 owner, uint32 angles, uint32 category)
{
    uint32 yaw;
    draft_call_adapter(r_u32(r_u32(owner + 16) + 20), owner, angles);
    yaw = (r_u16(angles + 2) + 2048) & 0xFFF;
    if (yaw >= 0x801)
        yaw |= 0xF000;
    w_u16(angles + 2, yaw);
    return sub_8006BD08(owner + 20, (uint32)r_s16(angles), (uint32)(sint32)(sint16)yaw, r_u8(owner + 13), category);
}

static uint32 volley_create_projectile(uint32 owner, uint32 target, uint32 angles, uint32 offset, uint32 speed, uint32 lateral, uint32 vertical, uint32 event, uint32 acceleration, uint32 turn_rate)
{
    // The native 6C094 contract omits the unread original argument at SP+18
    uint32 projectile = sub_8006C094(owner, offset, speed, lateral, vertical, 1, event, 0, 0, 0);
    uint32 value, models, model;
    w_u16(projectile + 80, acceleration);
    w_u32(projectile + 88, target);
    if (target)
    {
        w_u8(target + 15, r_u8(target + 15) + 1);
        value = 0xFFFFFFFF;
    }
    else
        value = (sub_80069A50() & 0x1F) + 5;
    w_u8(projectile + 84, value);
    models = r_u32(0x800A62EC);
    w_u32(projectile, 0x8006C3D4);
    value = r_u8(projectile + 14);
    w_u32(projectile + 16, owner);
    model = r_u16(models + 0x104);
    w_u8(projectile + 14, value | 2);
    w_u16(projectile + 32, model);
    w_u32(projectile + 72, (uint32)r_s16(angles + 2));
    value = (uint32)r_s16(angles);
    w_u16(projectile + 82, turn_rate);
    w_u8(projectile + 104, 0);
    w_u32(projectile + 76, value);
    if (target)
        sub_8006AFF4(projectile);
    else
        sub_8006AF08(projectile);
    return projectile;
}

uint32 sub_8006D4C8(uint32 owner, uint32 damage)
{
    uint32 mark = draft_scratch_mark();
    uint32 scratch = draft_scratch_adapter(40);
    uint32 angles = scratch, category = scratch + 8;
    uint32 first = scratch + 16, second = scratch + 24, third = scratch + 32;
    uint32 target, projectile;
    FUNCTION_MARKER(0x8006D4C8, "1.EXE");
    target = volley_find_target(owner, angles, category);
    w_u32(first, r_u32(0x800A6418));
    w_u32(first + 4, r_u32(0x800A641C));
    projectile = volley_create_projectile(owner, target, angles, first, 0x2000, 1024, (uint32)-200, 0, (uint32)-200, (uint32)-30);
    w_u16(projectile + 58, damage);
    w_u8(projectile + 13, 0);
    w_u8(projectile + 130, 0xFF);
    draft_call_adapter(0x80035A08, 20, 2048, 0xFF, 0, 0);
    w_u32(second, r_u32(0x800A6420));
    w_u32(second + 4, r_u32(0x800A6424));
    projectile = volley_create_projectile(owner, target, angles, second, 0x2000, (uint32)-1024, (uint32)-200, 0, (uint32)-200, (uint32)-40);
    w_u16(projectile + 58, damage);
    w_u8(projectile + 13, 0);
    w_u8(projectile + 130, 0xFF);
    w_u32(third, r_u32(0x800A6428));
    w_u32(third + 4, r_u32(0x800A642C));
    projectile = volley_create_projectile(owner, target, angles, third, 0x2000, 0, (uint32)-900, (uint32)-16, (uint32)-300, (uint32)-30);
    w_u16(projectile + 58, damage);
    w_u8(projectile + 13, 0);
    w_u8(projectile + 130, 0xFF);
    draft_scratch_release(mark);
    return 0xFFFFFFFF;
}

uint32 sub_8006D908(uint32 owner, uint32 damage)
{
    uint32 mark = draft_scratch_mark();
    uint32 scratch = draft_scratch_adapter(56);
    uint32 angles = scratch, category = scratch + 8;
    uint32 first = scratch + 16, second = scratch + 24, third = scratch + 32;
    uint32 fourth = scratch + 40, fifth = scratch + 48;
    uint32 target, projectile;
    FUNCTION_MARKER(0x8006D908, "1.EXE");
    target = volley_find_target(owner, angles, category);
    w_u32(first, r_u32(0x800A6428));
    w_u32(first + 4, r_u32(0x800A642C));
    projectile = volley_create_projectile(owner, target, angles, first, 0x3800, 0, (uint32)-800, 0, (uint32)-400, (uint32)-40);
    w_u8(projectile + 130, 0xFF);
    w_u8(projectile + 13, 0);
    w_u16(projectile + 58, damage);
    draft_call_adapter(0x80035A08, 20, 2048, 0xFF, 0, 0);
    w_u32(second, r_u32(0x800A6430));
    w_u32(second + 4, r_u32(0x800A6434));
    projectile = volley_create_projectile(owner, target, angles, second, 0x3800, (uint32)-600, (uint32)-300, 0, (uint32)-300, (uint32)-35);
    w_u16(projectile + 58, damage);
    w_u8(projectile + 13, 0);
    w_u8(projectile + 130, 0xFF);
    w_u32(third, r_u32(0x800A6438));
    w_u32(third + 4, r_u32(0x800A643C));
    projectile = volley_create_projectile(owner, target, angles, third, 0x3800, 600, (uint32)-300, 0, (uint32)-300, (uint32)-35);
    w_u16(projectile + 58, damage);
    w_u8(projectile + 13, 0);
    w_u8(projectile + 130, 0xFF);
    w_u32(fourth, r_u32(0x800A6420));
    w_u32(fourth + 4, r_u32(0x800A6424));
    projectile = volley_create_projectile(owner, target, angles, fourth, 0x3800, (uint32)-1024, (uint32)-100, 0, (uint32)-200, (uint32)-30);
    w_u16(projectile + 58, damage);
    w_u8(projectile + 13, 0);
    w_u8(projectile + 130, 0xFF);
    w_u32(fifth, r_u32(0x800A6418));
    w_u32(fifth + 4, r_u32(0x800A641C));
    projectile = volley_create_projectile(owner, target, angles, fifth, 0x3800, 1024, (uint32)-100, (uint32)-16, (uint32)-200, (uint32)-30);
    w_u16(projectile + 58, damage);
    w_u8(projectile + 13, 0);
    w_u8(projectile + 130, 0xFF);
    draft_scratch_release(mark);
    return 0xFFFFFFFF;
}
