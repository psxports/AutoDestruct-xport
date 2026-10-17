#include "native_call_dispatch.h"

uint32 sub_80040224(uint32 owner, uint32 damage)
{
    FUNCTION_MARKER(0x80040224, "1.EXE");
    damage = (uint32)(sint32)(sint16)damage;
    if (sub_80040088(owner, damage))
        return sub_8003F79C(owner, damage, 1);
    return (uint32)draft_call_adapter(0x80035A08, 34, 2048, 0x80, 0, 0);
}

uint32 sub_80040294(uint32 owner, uint32 damage)
{
    FUNCTION_MARKER(0x80040294, "1.EXE");
    damage = (uint32)(sint32)(sint16)damage;
    if (sub_80040088(owner, damage))
        return sub_8003F79C(owner, damage, 1);
    return (uint32)draft_call_adapter(0x80035A08, 34, 1024, 0x80, 0, 0);
}

uint32 sub_8003E8C8(uint32 owner, uint32 damage)
{
    uint32 object;
    FUNCTION_MARKER(0x8003E8C8, "1.EXE");
    object = sub_8003E690(owner, (uint32)(sint32)(sint16)damage, 2);
    draft_call_adapter(0x80035A08, 35, 2048, 0xFF, 0, 0);
    return sub_800369E0(object + 20, object + 86, 1800, 49);
}

uint32 sub_8003E928(uint32 owner, uint32 damage)
{
    uint32 object;
    FUNCTION_MARKER(0x8003E928, "1.EXE");
    object = sub_8003E690(owner, (uint32)(sint32)(sint16)damage, 1);
    draft_call_adapter(0x80035A08, 35, 2048, 0xFF, 0, 0);
    return sub_800369E0(object + 20, object + 86, 1600, 26);
}

uint32 sub_8003DE24(uint32 owner, uint32 damage)
{
    FUNCTION_MARKER(0x8003DE24, "1.EXE");
    sub_8003DE6C(owner, (uint32)(sint32)(sint16)damage);
    return (uint32)draft_call_adapter(0x80035A08, 32, 2048, 0xFF, owner + 20, 0);
}

uint32 sub_8003DDC4(uint32 owner, uint32 damage)
{
    FUNCTION_MARKER(0x8003DDC4, "1.EXE");
    damage = (uint32)(sint32)(sint16)damage;
    sub_8003DE6C(owner, damage);
    sub_8003DE6C(owner, damage);
    return (uint32)draft_call_adapter(0x80035A08, 31, 2048, 0xFF, 0, 0);
}

uint32 sub_8003EDF4(uint32 owner, uint32 damage)
{
    FUNCTION_MARKER(0x8003EDF4, "1.EXE");
    sub_8003EC9C(owner, (uint32)(sint32)(sint16)damage, 2);
    return (uint32)draft_call_adapter(0x80035A08, 24, 2048, 0xC0, 0, 0);
}

uint32 sub_8003EDB4(uint32 owner, uint32 damage)
{
    FUNCTION_MARKER(0x8003EDB4, "1.EXE");
    sub_8003EC9C(owner, (uint32)(sint32)(sint16)damage, 4);
    return (uint32)draft_call_adapter(0x80035A08, 24, 1540, 0xC0, 0, 0);
}

uint32 sub_8003E278(uint32 owner, uint32 damage)
{
    FUNCTION_MARKER(0x8003E278, "1.EXE");
    damage = (uint32)(sint32)(sint16)damage;
    sub_8003E338(owner, damage);
    sub_8003E338(owner, damage);
    draft_call_adapter(0x80035A08, 22, 1024, 0xC0, 0, 0);
    return (uint32)draft_call_adapter(0x80035A08, 22, 1536, 0xC0, 0, 0);
}

uint32 sub_8003F038(uint32 owner, uint32 damage)
{
    uint32 mark = draft_scratch_mark();
    uint32 offset = draft_scratch_adapter(8), result;
    FUNCTION_MARKER(0x8003F038, "1.EXE");
    damage = (uint32)(sint32)(sint16)damage;
    w_u16(offset, 125);
    w_u16(offset + 4, (uint32)-600);
    w_u16(offset + 2, 0);
    // The original fourth stack word is not read by 3F1B8
    sub_8003F1B8(owner, 16, damage, (uint32)-700, offset, 21, 0x80);
    w_u16(offset, (uint32)-125);
    result = sub_8003F1B8(owner, 16, damage, (uint32)-700, offset, 21, 0x80);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_80040088(uint32 owner, uint32 damage)
{
    uint32 mark = draft_scratch_mark();
    uint32 scratch = draft_scratch_adapter(32);
    uint32 point = scratch, tag = scratch + 16, normal = scratch + 24;
    uint32 model, physical, surface, difference, speed, object, a, b, c, d, flags;
    sint32 reach;
    FUNCTION_MARKER(0x80040088, "1.EXE");
    model = r_u8(r_u32(0x800A8548) + r_u16(owner + 32));
    physical = r_u32(0x800A90AC) + 40 * model;
    reach = (sint32)((uint32)r_u16(physical + 34) << 16) >> 17;
    if (reach >= 151)
        reach -= 150;
    sub_8003F7D8(owner, point, (uint32)reach);
    surface = sub_8002E640(point, normal, 0, tag) + 30;
    difference = surface + r_u32(point + 4);
    if ((sint32)difference < 0)
        difference = 0 - difference;
    speed = (uint32)((sint32)draft_call_adapter(r_u32(r_u32(owner + 16)), owner) >> 16);
    if ((sint32)difference >= 300 || (sint32)speed < 5)
    {
        draft_scratch_release(mark);
        return 1;
    }
    object = (uint32)draft_call_adapter(0x800226E4, 60);
    w_u8(object + 34, 8);
    a = r_u32(owner + 36);
    b = r_u32(owner + 40);
    c = r_u32(owner + 44);
    d = r_u32(owner + 48);
    w_u32(object + 36, a);
    w_u32(object + 40, b);
    w_u32(object + 44, c);
    w_u32(object + 48, d);
    w_u16(object + 52, r_u16(owner + 52));
    w_u16(object + 58, damage);
    w_u32(object, 0x80040304);
    w_u32(object + 16, owner);
    w_u32(object + 20, r_u32(point));
    a = r_u32(point + 8);
    w_u32(object + 24, 0 - surface);
    w_u16(object + 8, 1024);
    w_u32(object + 28, a);
    model = r_u32(0x800A62EC);
    flags = r_u8(object + 14);
    model = r_u16(model + 0xF0);
    w_u8(object + 14, flags | 2);
    w_u16(object + 56, 0);
    w_u16(object + 32, model);
    w_u8(owner + 15, r_u8(owner + 15) + 1);
    draft_scratch_release(mark);
    return 0;
}

uint32 sub_80040304(uint32 object)
{
    uint32 owner = r_u32(object + 16);
    uint32 model = r_u8(r_u32(0x800A8548) + r_u16(owner + 32));
    uint32 tick = r_u16(0x800A9010);
    uint32 physical = r_u32(0x800A90AC) + 40 * model;
    uint32 remaining = r_u16(object + 8);
    uint32 extent = (uint32)((sint32)((uint32)r_u16(physical + 34) << 16) >> 17);
    uint32 result;
    FUNCTION_MARKER(0x80040304, "1.EXE");
    remaining -= tick;
    w_u16(object + 8, remaining);
    extent += 100;
    if ((sint16)remaining < 0)
        return sub_8002289C(object);
    result = extent < sub_80069BE0(r_u32(object + 20) - r_u32(owner + 20), r_u32(object + 28) - r_u32(owner + 28));
    if (result)
    {
        w_u32(object, 0x800403EC);
        result = r_u8(owner + 15) - 1;
        w_u8(owner + 15, result);
    }
    return result;
}

uint32 sub_800403EC(uint32 object)
{
    sint32 state = r_s16(object + 56);
    uint32 remaining = (uint32)r_s16(object + 8), result;
    FUNCTION_MARKER(0x800403EC, "1.EXE");
    if (state)
        return sub_8002A5DC(object, (uint32)state);
    remaining -= r_u32(0x800A9010);
    if ((sint32)remaining < 0)
        return sub_8002289C(object);
    result = sub_80029970(object, 30, 4, 1, object + 20);
    w_u16(object + 8, remaining);
    return result;
}

void sub_8003DE6C(uint32 owner, uint32 damage)
{
    uint32 mark = draft_scratch_mark();
    uint32 scratch = draft_scratch_adapter(32);
    uint32 angles = scratch, offset = scratch + 8;
    uint32 toggle = (uint32)r_s16(owner + 54);
    uint32 object, value, model;
    FUNCTION_MARKER(0x8003DE6C, "1.EXE");
    draft_call_adapter(r_u32(r_u32(owner + 16) + 20), owner, angles);
    object = (uint32)draft_call_adapter(0x800226E4, 60);
    draft_call_adapter(0x80054D38, (uint32)r_s16(angles), (uint32)r_s16(angles + 2), (uint32)r_s16(angles + 4), object + 36);
    w_u8(object + 34, 8);
    w_u32(offset, toggle ? 125 : (uint32)-125);
    w_u32(offset + 4, (uint32)-25);
    value = sub_8003DB0C(owner) ? (uint32)-150 : 50;
    w_u32(offset + 8, value);
    sub_80031D50(object + 36, owner + 20, offset, object + 20);
    w_u32(object, 0x8003E0C8);
    w_u16(object + 58, damage);
    w_u32(object + 16, owner);
    w_u16(object + 8, 600);
    w_u16(object + 10, 0);
    w_u16(object + 56, 0);
    value = sub_80069A50();
    w_u16(angles + 4, r_u16(angles + 4) + value);
    model = (uint32)r_s16(r_u32(0x800A62EC) + 0x108);
    sub_8003DFB0(owner, object + 36, angles, offset, model);
    w_u16(owner + 54, (toggle + 1) & 1);
    draft_scratch_release(mark);
}

void sub_8003EC9C(uint32 owner, uint32 damage, uint32 count)
{
    uint32 mark = draft_scratch_mark();
    uint32 scratch = draft_scratch_adapter(32);
    uint32 offset = scratch, angles = scratch + 16;
    uint32 object, value, model;
    FUNCTION_MARKER(0x8003EC9C, "1.EXE");
    draft_call_adapter(r_u32(r_u32(owner + 16) + 20), owner, angles);
    object = (uint32)draft_call_adapter(0x800226E4, 60);
    w_u8(object + 34, 8);
    w_u32(object + 20, r_u32(owner + 20));
    w_u32(object + 24, r_u32(owner + 24));
    w_u32(object + 28, r_u32(owner + 28));
    draft_call_adapter(0x80054D38, (uint32)r_s16(angles), (uint32)r_s16(angles + 2), (uint32)r_s16(angles + 4), object + 36);
    w_u16(object + 8, 600);
    w_u32(object, 0x8003EE34);
    w_u16(object + 58, damage);
    w_u8(object + 13, count);
    w_u16(object + 10, 0);
    w_u32(object + 16, owner);
    w_u16(object + 56, 0);
    w_u32(offset, 0);
    w_u32(offset + 4, (uint32)-80);
    value = sub_8003DB0C(owner) ? (uint32)-200 : (uint32)-250;
    w_u32(offset + 8, value);
    model = (uint32)r_s16(r_u32(0x800A62EC) + 0x74);
    sub_8003DFB0(owner, object + 36, angles, offset, model);
    draft_scratch_release(mark);
}

void sub_8003DFB0(uint32 owner, uint32 ignored_matrix, uint32 angles, uint32 offset, uint32 model)
{
    uint32 object = (uint32)draft_call_adapter(0x800226E4, 56);
    uint32 z, flags;
    FUNCTION_MARKER(0x8003DFB0, "1.EXE");
    w_u8(object + 34, 8);
    w_u32(object + 20, r_u32(owner + 20));
    w_u32(object + 24, r_u32(owner + 24));
    z = r_u32(owner + 28);
    flags = r_u8(object + 14);
    w_u16(object + 32, model);
    w_u8(object + 14, flags | 2);
    w_u32(object + 28, z);
    draft_call_adapter(0x80054D38, (uint32)r_s16(angles), (uint32)r_s16(angles + 2), (uint32)r_s16(angles + 4), object + 36);
    w_u32(object, 0x8003E07C);
    w_u16(object + 8, 1);
    sub_80031E30(owner + 36, object + 20, offset);
}

uint32 sub_8003E07C(uint32 object)
{
    uint32 result = (uint32)r_s16(object + 8);
    FUNCTION_MARKER(0x8003E07C, "1.EXE");
    if ((sint32)result < 0)
        return sub_8002289C(object);
    result -= r_u16(0x800A9010);
    w_u16(object + 8, result);
    return result;
}

uint32 sub_8003E0C8(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 scratch, previous, movement, x, y, z, result, model;
    FUNCTION_MARKER(0x8003E0C8, "1.EXE");
    if (r_s16(object + 56))
    {
        model = (uint32)r_s16(r_u32(0x800A62EC) + 0x4C);
        sub_8006268C(object + 20, 0, 0, model, 64, 0x8000, 1);
        result = sub_8002A5DC(object, (uint32)r_s16(object + 56));
        goto finished;
    }
    scratch = draft_scratch_adapter(32);
    previous = scratch;
    movement = scratch + 16;
    x = r_u32(object + 20);
    y = r_u32(object + 24);
    z = r_u32(object + 28);
    w_u32(previous, x);
    w_u32(previous + 4, y);
    w_u32(previous + 8, z);
    w_u32(movement, 0);
    w_u32(movement + 4, 0);
    w_u32(movement + 8, 0 - (uint32)r_s16(object + 8) * r_u32(0x800A9010));
    sub_80031E30(object + 36, object + 20, movement);
    w_u16(object + 10, r_u16(object + 10) - r_u16(movement + 8));
    x = r_u32(previous);
    y = r_u32(previous + 4);
    z = r_u32(previous + 8);
    w_u32(movement, x);
    w_u32(movement + 4, y);
    w_u32(movement + 8, z);
    if (r_s16(object + 10) >= 20000)
    {
        result = sub_8002289C(object);
        goto finished;
    }
    if ((uint16)sub_8002F3FC(movement, object + 20) || (uint16)sub_80030678(movement, object + 20))
    {
        model = (uint32)r_s16(r_u32(0x800A62EC) + 0x4C);
        sub_8006268C(object + 20, movement, 0, model, 64, 0x8000, 1);
        sub_8002A8F0(object);
    }
    result = sub_80029970(object, 136, 6, 1, previous);
finished:
    draft_scratch_release(mark);
    return result;
}

uint32 sub_8003EE34(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 scratch, previous, movement, x, y, z, result, hit;
    sint32 count;
    FUNCTION_MARKER(0x8003EE34, "1.EXE");
    if (r_s16(object + 56))
    {
        result = sub_8002A5DC(object, (uint32)r_s16(object + 56));
        goto finished;
    }
    scratch = draft_scratch_adapter(32);
    movement = scratch;
    previous = scratch + 16;
    x = r_u32(object + 20);
    y = r_u32(object + 24);
    z = r_u32(object + 28);
    w_u32(previous, x);
    w_u32(previous + 4, y);
    w_u32(previous + 8, z);
    x = (uint32)r_s16(object + 8) << 8;
    y = (uint32)(r_s32(0x800A63D8) >> 8);
    z = 0 - (uint32)((sint32)(x * y) >> 16);
    w_u32(movement, 0);
    w_u32(movement + 4, 0);
    w_u32(movement + 8, z);
    sub_80031E30(object + 36, object + 20, movement);
    w_u16(object + 10, r_u16(object + 10) - r_u16(movement + 8));
    x = r_u32(previous);
    y = r_u32(previous + 4);
    z = r_u32(previous + 8);
    w_u32(movement, x);
    w_u32(movement + 4, y);
    w_u32(movement + 8, z);
    hit = (uint16)sub_8002F3FC(movement, object + 20);
    if (hit)
    {
        if (!(sub_80069A50() & 0xF))
        {
            w_u16(object + 56, 7);
            result = 7;
            goto finished;
        }
    }
    if (hit || r_s16(object + 10) >= 10240)
    {
        count = r_s8(object + 13);
        for (; count > 0; --count)
            sub_80060D20(object, movement);
        sub_8002A8F0(object);
    }
    else if ((uint16)sub_80030678(movement, object + 20))
        sub_8002A8F0(object);
    result = sub_80029970(object, 136, 6, 1, previous);
finished:
    draft_scratch_release(mark);
    return result;
}
