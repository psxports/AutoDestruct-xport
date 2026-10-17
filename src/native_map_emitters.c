#include "native_call_dispatch.h"

uint32 sub_80065610(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object, z, flags, height;
    FUNCTION_MARKER(0x80065610, "1.EXE");
    object = sub_800227C4(40);
    w_u32(object + 20, base_x + (r_u32(record) & 0xFFF));
    z = base_z + ((r_u32(record) >> 12) & 0xFFF);
    flags = r_u8(object + 14);
    w_u32(object + 28, z);
    height = r_u16(record + 4);
    w_u8(object + 14, flags | 0x20);
    w_u32(object, 0x800656AC);
    w_u8(object + 13, 127);
    w_u32(object + 24, 0 - height);
    return object;
}

uint32 sub_800656AC(uint32 object)
{
    uint32 remaining;
    FUNCTION_MARKER(0x800656AC, "1.EXE");
    if (r_u8(object + 12) < 4)
        return 1;
    remaining = r_u8(object + 13) - (uint32)r_u8(0x800A9010);
    w_u8(object + 13, remaining);
    if ((sint8)remaining >= 0)
        return 127;
    w_u8(object + 13, 127);
    return sub_80065704(object);
}

uint32 sub_80065704(uint32 owner)
{
    uint32 object, models, flags, model, mark, angles, result;
    FUNCTION_MARKER(0x80065704, "1.EXE");
    object = (uint32)draft_call_adapter(0x800226E4, 88);
    w_u8(object + 34, 8);
    result = r_u32(owner + 20);
    models = r_u32(0x800A62EC);
    w_u32(object + 20, result);
    w_u32(object + 24, r_u32(owner + 24));
    w_u32(object + 28, r_u32(owner + 28));
    flags = r_u8(object + 14);
    model = r_u16(models + 260);
    w_u8(object + 14, flags | 2);
    w_u16(object + 32, model);
    mark = draft_scratch_mark();
    angles = draft_scratch_adapter(4);
    w_u16(angles, 0xFC7C);
    w_u16(angles + 2, 0);
    sub_80055288(angles, object + 36);
    flags = r_u8(object + 14);
    w_u32(object, 0x800657F8);
    w_u8(object + 14, flags | 0x40);
    w_u16(object + 72, sub_80069A50() & 63);
    w_u16(object + 74, (sub_80069A50() & 3) + 1);
    w_u16(object + 76, 0);
    w_u16(object + 78, r_u16(angles));
    result = r_u16(angles + 2);
    w_u16(object + 82, 0xFFFF);
    w_u16(object + 80, result);
    result = (sub_80069A50() & 63) + 100;
    w_u16(object + 84, result);
    w_u8(object + 68, 0);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_800657F8(uint32 object)
{
    uint32 tick, mark, scratch, previous, speed, models, result;
    FUNCTION_MARKER(0x800657F8, "1.EXE");
    tick = r_u32(0x800A9010);
    if (r_s16(object + 76) >= 4445)
    {
        uint32 count = (sub_80069A50() & 3) + 1;
        for (uint32 i = 0; i < count; ++i)
            sub_80060D20(object, object + 20);
        sub_80062B3C(object + 20, (uint32)r_s16(r_u32(0x800A62EC) + 96), 10485, 24);
        return sub_8002289C(object);
    }
    mark = draft_scratch_mark();
    scratch = draft_scratch_adapter(20);
    previous = scratch + 8;
    w_u32(previous, r_u32(object + 20));
    w_u32(previous + 4, r_u32(object + 24));
    w_u32(previous + 8, r_u32(object + 28));
    speed = r_u16(object + 72) + (uint32)r_s16(object + 74) * tick;
    w_u16(object + 72, speed);
    if ((sint16)speed >= 251)
        w_u16(object + 72, 250);
    result = r_u16(object + 78);
    w_u16(object + 80, r_u16(object + 80) + (tick << 7));
    w_u16(scratch, result);
    w_u16(scratch + 2, r_u16(object + 80));
    sub_80055288(scratch, object + 36);
    w_u16(scratch, 0);
    w_u16(scratch + 2, 0);
    speed = (0 - (uint32)r_s16(object + 72)) * tick;
    w_u16(scratch + 4, speed);
    sub_80031DC8(object + 36, object + 20, scratch);
    result = r_u16(object + 76);
    speed = r_u16(scratch + 4);
    models = r_u32(0x800A62EC);
    w_u16(object + 76, result - speed);
    result = sub_800620A4(object, object + 56, object + 20, previous, (uint32)r_s16(models + 46), 100, (uint32)r_s16(object + 84), 0);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_800659AC(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object, height, flags;
    FUNCTION_MARKER(0x800659AC, "1.EXE");
    object = (uint32)draft_call_adapter(0x800226E4, 56);
    w_u32(object + 20, base_x + (r_u32(record) & 0xFFF));
    w_u32(object + 28, base_z + ((r_u32(record) >> 12) & 0xFFF));
    height = r_u16(record + 4);
    flags = r_u8(object + 14);
    w_u32(object, 0x80065A4C);
    w_u32(object + 8, record);
    w_u8(object + 14, flags | 0x20);
    w_u32(object + 16, 3);
    w_u32(object + 24, 0 - height);
    return object;
}

uint32 sub_80065B84(uint32 object, uint32 tick)
{
    uint32 rotation, x, y, z, angle, old_x, old_y, old_z, result;
    FUNCTION_MARKER(0x80065B84, "1.EXE");
    rotation = tick * r_u32(object + 16);
    x = (uint32)r_s16(object + 40) * tick;
    y = (uint32)r_s16(object + 42) * tick;
    z = (uint32)r_s16(object + 44);
    w_u16(object + 36, r_u16(object + 36) + (tick << 2));
    result = r_u8(object + 13);
    angle = r_u16(object + 38);
    z *= tick;
    w_u8(object + 13, result - tick);
    old_x = r_u32(object + 20);
    w_u16(object + 38, angle + rotation);
    old_y = r_u32(object + 24);
    w_u32(object + 20, old_x - x);
    old_z = r_u32(object + 28);
    w_u32(object + 24, old_y - y);
    result = old_z - z;
    w_u32(object + 28, result);
    return result;
}

uint32 sub_80065C10(uint32 object)
{
    uint32 result;
    FUNCTION_MARKER(0x80065C10, "1.EXE");
    sub_80065B84(object, r_u32(0x800A9010));
    result = (uint32)r_s8(object + 13);
    if ((sint32)result >= 0)
        return result;
    w_u16(object + 32, (uint32)r_s16(r_u32(0x800A62EC) + 90));
    w_u8(object + 13, (sub_80069A50() & 63) + 20);
    return sub_8002289C(object);
}

uint32 sub_80065A4C(uint32 owner)
{
    uint32 result, remaining, object, flags, model, x, y, z, mark, scratch;
    FUNCTION_MARKER(0x80065A4C, "1.EXE");
    if (r_u8(owner + 12) < 4)
        return 1;
    remaining = r_u32(owner + 16);
    result = r_u32(0x800A9010);
    remaining -= result;
    if ((sint32)remaining < 0)
    {
        object = sub_800227C4(48);
        model = r_u32(0x800A62EC);
        flags = r_u8(object + 14);
        model = r_u16(model + 88);
        w_u8(object + 14, flags | 2);
        w_u16(object + 32, model);
        x = r_u32(owner + 20);
        y = r_u32(owner + 24);
        z = r_u32(owner + 28);
        w_u32(object + 20, x);
        w_u32(object + 24, y);
        w_u32(object + 28, z);
        w_u16(object + 36, 75);
        flags = r_u8(object + 14);
        w_u32(object, 0x80065C10);
        w_u8(object + 14, flags | 0x40);
        w_u8(object + 13, (sub_80069A50() & 31) + 32);
        w_u32(object + 16, (sub_80069A50() & 127) - 63);
        w_u8(object + 34, 8);
        mark = draft_scratch_mark();
        scratch = draft_scratch_adapter(32);
        sub_800551CC((r_u32(r_u32(owner + 8) + 4) >> 14) & 0xF80, scratch);
        w_u16(scratch + 24, 0xFFEC);
        w_u16(scratch + 26, 0);
        w_u16(scratch + 28, 0);
        sub_80031C1C(scratch, scratch + 24, scratch + 24);
        result = r_u32(scratch + 24);
        z = r_u32(scratch + 28);
        w_u32(object + 40, result);
        w_u32(object + 44, z);
        remaining = 3;
        draft_scratch_release(mark);
    }
    w_u32(owner + 16, remaining);
    return result;
}

uint32 sub_80065C7C(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object, height, flags;
    FUNCTION_MARKER(0x80065C7C, "1.EXE");
    object = sub_800227C4(40);
    w_u32(object + 20, base_x + (r_u32(record) & 0xFFF));
    w_u32(object + 28, base_z + ((r_u32(record) >> 12) & 0xFFF));
    height = r_u16(record + 4);
    w_u8(object + 34, 11);
    w_u16(object + 36, 288);
    w_u32(object, 0x80060498);
    w_u8(object + 13, 4);
    flags = r_u8(object + 14);
    w_u16(object + 38, 0);
    w_u16(object + 16, 4);
    w_u8(object + 14, flags | 0x20);
    w_u32(object + 24, 0 - height);
    return object;
}

uint32 sub_80060540(uint32 owner, uint32 offset_x, uint32 offset_z, uint32 lifetime)
{
    uint32 object, models, flags, z, result;
    FUNCTION_MARKER(0x80060540, "1.EXE");
    object = sub_800227C4(40);
    w_u8(object + 34, 11);
    models = r_u32(0x800A62EC);
    w_u16(object + 36, 185);
    flags = r_u8(object + 14);
    w_u16(object + 38, 0);
    models = r_u16(models + 62);
    w_u8(object + 14, flags | 2);
    w_u16(object + 32, models);
    w_u32(object + 20, offset_x + r_u32(owner + 20));
    w_u32(object + 24, r_u32(owner + 24) - 92);
    z = r_u32(owner + 28);
    w_u32(object, 0x80060738);
    w_u16(object + 8, 0);
    w_u16(object + 10, lifetime);
    w_u32(object + 28, offset_z + z);
    result = (sub_80069A50() & 127) - 64;
    w_u16(object + 16, result);
    return result;
}

uint32 sub_80060498(uint32 owner)
{
    uint32 result, x, z, lifetime;
    FUNCTION_MARKER(0x80060498, "1.EXE");
    if (r_u8(owner + 12) < 4)
        return 1;
    result = r_u8(owner + 13) - (uint32)r_u8(0x800A9010);
    w_u8(owner + 13, result);
    result <<= 24;
    if ((sint32)result >= 0)
        return result;
    w_u8(owner + 13, r_u8(owner + 16));
    x = (sub_80069A50() & 127) - 63;
    z = (sub_80069A50() & 127) - 63;
    lifetime = (sub_80069A50() & 63) + 175;
    return sub_80060540(owner, x, z, lifetime);
}
