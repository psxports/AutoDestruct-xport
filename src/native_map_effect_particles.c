#include "native_call_dispatch.h"

uint32 sub_80067CF4(uint32 object)
{
    uint32 tick, displacement, rotation, y, angle, result;
    sint32 speed, limit;
    FUNCTION_MARKER(0x80067CF4, "1.EXE");
    tick = r_u32(0x800A9010);
    displacement = tick * (uint32)r_s16(object + 8);
    rotation = tick * (uint32)r_s16(object + 16);
    displacement = (uint32)((sint32)displacement >> 2);
    w_u16(object + 8, r_u16(object + 8) + (tick << 1));
    y = r_u32(object + 24);
    angle = r_u16(object + 38);
    speed = r_s16(object + 8);
    limit = r_s16(object + 10);
    w_u32(object + 24, y - displacement);
    result = rotation;
    w_u16(object + 38, angle + rotation);
    if (limit < speed)
        result = sub_8002289C(object);
    return result;
}

void sub_80067B0C(uint32 object)
{
    uint32 mark, scratch, owner, phase, offset;
    FUNCTION_MARKER(0x80067B0C, "1.EXE");
    mark = draft_scratch_mark();
    scratch = draft_scratch_adapter(36);
    phase = (uint32)r_s8(object + 13) * r_u32(0x800A9010);
    owner = r_u32(object + 8);
    phase += r_u16(object + 16);
    w_u16(object + 16, phase);
    sub_800551CC((uint32)(sint32)(sint16)phase, scratch);
    sub_80031B20(owner + 36, scratch, object + 36);
    offset = (uint32)r_s16(object + 18);
    w_u32(scratch + 28, 0xFFFFFFB0);
    w_u32(scratch + 32, 0);
    w_u32(scratch + 24, offset);
    sub_80031D50(owner + 36, owner + 20, scratch + 24, object + 20);
    draft_scratch_release(mark);
}

uint32 sub_80067950(uint32 owner, uint32 yaw, uint32 speed, uint32 phase, uint32 offset, uint32 model)
{
    uint32 object, flags, radius;
    FUNCTION_MARKER(0x80067950, "1.EXE");
    object = (uint32)draft_call_adapter(0x80022744, 56, owner);
    w_u8(object + 34, 8);
    flags = r_u8(object + 14);
    w_u32(object, 0x80067B0C);
    w_u16(object + 16, phase);
    w_u16(object + 32, model);
    w_u8(object + 14, flags | 2);
    radius = r_u16(offset);
    w_u8(object + 13, speed);
    w_u16(object + 18, radius);
    sub_80031D50(owner + 36, owner + 20, offset, object + 20);
    return sub_800551CC(yaw, object + 36);
}

uint32 sub_80067A94(uint32 owner, uint32 yaw)
{
    uint32 mark, offset, model, phase, result;
    FUNCTION_MARKER(0x80067A94, "1.EXE");
    model = (uint32)r_s16(r_u32(0x800A62EC) + 362);
    mark = draft_scratch_mark();
    offset = draft_scratch_adapter(12);
    w_u32(offset, 0);
    w_u32(offset + 4, 0xFFFFFFB0);
    w_u32(offset + 8, 0);
    phase = sub_80069A50() & 0xFFF;
    result = sub_80067950(owner, yaw, 32, phase, offset, model);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_80067BB4(uint32 object)
{
    uint32 owner, result, particle, mark, offset, models, model, flags;
    FUNCTION_MARKER(0x80067BB4, "1.EXE");
    result = r_u8(object + 12);
    owner = r_u32(object + 8);
    if (result < 4)
        return 1;
    result = r_u16(object + 16) - (uint32)r_u16(0x800A9010);
    w_u16(object + 16, result);
    result <<= 16;
    if ((sint32)result > 0)
        return result;
    w_u16(object + 16, 3);
    particle = sub_800227C4(40);
    mark = draft_scratch_mark();
    offset = draft_scratch_adapter(12);
    w_u32(offset, 0);
    w_u32(offset + 4, 0xFFFFFFB5);
    w_u32(offset + 8, 0);
    sub_80031D50(owner + 36, owner + 20, offset, object + 20);
    w_u8(particle + 34, 11);
    result = sub_80069A50();
    w_u32(particle + 20, (result & 0x3F) + r_u32(object + 20) - 31);
    w_u32(particle + 24, r_u32(object + 24) - 22);
    result = sub_80069A50();
    result = (result & 0x3F) + r_u32(object + 28) - 31;
    models = r_u32(0x800A62EC);
    w_u32(particle + 28, result);
    flags = r_u8(particle + 14);
    model = r_u16(models + 62);
    w_u8(particle + 14, flags | 2);
    w_u16(particle + 36, 45);
    w_u16(particle + 38, 0);
    w_u32(particle, 0x80067CF4);
    w_u16(particle + 8, 0);
    w_u16(particle + 32, model);
    result = sub_80069A50();
    w_u16(particle + 10, (result & 15) + 32);
    result = (sub_80069A50() & 0x7F) - 63;
    w_u16(particle + 16, result);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_800678D8(uint32 owner)
{
    uint32 object, z;
    FUNCTION_MARKER(0x800678D8, "1.EXE");
    if (r_u8(owner + 12) < 4)
        return 1;
    object = sub_80022820(40, owner);
    w_u32(object + 20, r_u32(owner + 20));
    w_u32(object + 24, r_u32(owner + 24) - 75);
    z = r_u32(owner + 28);
    w_u32(object, 0x80067BB4);
    w_u16(object + 16, 3);
    w_u32(object + 28, z);
    return object;
}
