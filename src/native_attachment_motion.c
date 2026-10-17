#include "native_call_dispatch.h"

static sint32 attachment_angle_delta(uint32 value)
{
    value &= 0xFFF;
    if (value >= 0x801)
        value |= 0xF000;
    return (sint16)value;
}

static uint32 attachment_damp_motion(uint32 value)
{
    uint32 shifted = (uint32)((sint32)(value << 16) >> 8);
    return (uint32)((sint32)(117 * shifted) >> 16);
}

uint32 sub_80052FB0(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 owner = r_u32(r_u32(0x800A851C) + 4 * (uint32)r_s16(object + 58));
    uint32 scratch = draft_scratch_adapter(224);
    // Contact selection can address the adjacent vector work area
    uint32 contacts = scratch;
    uint32 angles = scratch + 104;
    uint32 rotated = scratch + 112;
    uint32 attachment = scratch + 128;
    uint32 previous = scratch + 144;
    uint32 sweep = scratch + 160;
    uint32 tags = scratch + 192;
    uint32 heights = scratch + 208;
    uint32 response = scratch + 216;
    uint32 flags, result, dx, dz, heading, desired, model, physical;
    uint32 pitch, roll, old_x, old_z, value, motion_x, motion_z, selected;
    sint32 delta, magnitude;
    FUNCTION_MARKER(0x80052FB0, "1.EXE");
    w_u32(sweep, r_u32(object + 20));
    w_u32(sweep + 4, r_u32(object + 24));
    w_u32(sweep + 8, r_u32(object + 28));
    flags = r_u8(object + 14) & 0xF9;
    w_u8(object + 14, flags);
    result = r_u8(owner + 14) & 0xA;
    flags |= result;
    w_u8(object + 14, flags);
    if (!(flags & 2))
    {
        draft_scratch_release(mark);
        return result;
    }
    w_u16(angles, 0);
    value = r_u16(object + 144);
    w_u16(angles + 2, 0);
    w_u16(angles + 4, value);
    sub_80031B6C(owner + 36, angles, attachment);
    dx = r_u32(owner + 20) + r_u32(attachment) - ((uint32)r_s16(object + 140) + r_u32(object + 20));
    dz = r_u32(owner + 28) + r_u32(attachment + 8) - ((uint32)r_s16(object + 142) + r_u32(object + 28));
    heading = sub_80055A9C(0u - r_u32(attachment), 0u - r_u32(attachment + 8));
    w_u16(angles, 0);
    value = r_u16(object + 144);
    w_u16(angles + 2, 0);
    w_u16(angles + 4, value);
    sub_80031B6C(owner + 36, angles, attachment);
    w_u16(angles, 0);
    w_u16(angles + 4, 0u - r_u16(object + 138));
    desired = sub_80055A9C(dx, dz) + 2048;
    w_u16(angles + 2, desired);
    delta = attachment_angle_delta(heading - desired);
    magnitude = delta < 0 ? -delta : delta;
    if (magnitude < 1024)
        w_u16(angles + 2, delta > 0 ? heading - 1024 : heading + 1024);
    desired = r_u16(angles + 2);
    delta = attachment_angle_delta(desired - r_u16(object + 136));
    value = (uint32)r_s16(object + 138) - (uint32)delta;
    model = r_u16(object + 32);
    w_u16(object + 136, desired);
    model = r_u32(0x800A8548) + model;
    w_u16(object + 138, (uint32)((sint32)value >> 1));
    sub_80029DDC(object, 0x800A6FD8, r_u8(model));
    sub_8002FC90(object, tags, 0x800A6FD8, 0);
    sub_800283D4(object, object + 64, tags);
    w_u32(heights, r_u32(0x800A61C8));
    w_u32(heights + 4, r_u32(0x800A61CC));
    value = sub_80069BE0((uint32)r_s16(object + 140), (uint32)r_s16(object + 142));
    sub_800287B4(object, object + 64, value << 8, heights);
    model = r_u8(r_u32(0x800A8548) + r_u16(object + 32));
    physical = r_u32(0x800A90AC) + 40 * model;
    value = (uint32)((r_s16(heights) + r_s16(heights + 2)) >> 1);
    pitch = sub_80055A9C(r_u32(owner + 24) - r_u32(attachment + 4) - value, (uint32)r_s16(physical + 34));
    model = r_u8(r_u32(0x800A8548) + r_u16(object + 32));
    physical = r_u32(0x800A90AC) + 40 * model;
    roll = sub_80055A9C((uint32)r_s16(heights + 2) - (uint32)r_s16(heights), (uint32)r_s16(physical + 36));
    draft_call_adapter(0x80054D38, pitch, (uint32)r_s16(angles + 2), roll, object + 36);
    w_u16(heights, 0);
    value = r_u16(object + 146);
    w_u16(heights + 2, 0);
    w_u16(heights + 4, 0u - value);
    sub_80031B6C(object + 36, heights, rotated);
    old_x = r_u32(object + 20);
    old_z = r_u32(object + 28);
    w_u32(previous, old_x);
    w_u32(previous + 4, r_u32(object + 24));
    w_u32(previous + 8, r_u32(object + 28));
    w_u32(object + 20, r_u32(owner + 20) + r_u32(attachment) - r_u32(rotated));
    value = (uint32)((sint32)(r_u32(object + 20) - old_x) >> 1);
    w_u32(object + 28, r_u32(owner + 28) + r_u32(attachment + 8) - r_u32(rotated + 8));
    motion_x = attachment_damp_motion((uint32)r_s16(object + 140) + value);
    value = r_u32(owner + 24) + r_u32(attachment + 4) - r_u32(rotated + 4);
    w_u16(object + 140, motion_x);
    dz = r_u32(object + 28) - old_z;
    w_u32(object + 24, value);
    motion_z = attachment_damp_motion((uint32)r_s16(object + 142) + (uint32)((sint32)dz >> 1));
    delta = r_s16(object + 140);
    if (delta < 0)
        delta = -delta;
    w_u16(object + 142, motion_z);
    magnitude = (sint32)motion_z;
    if (magnitude < 0)
        magnitude = -magnitude;
    if (delta < 6 && magnitude < 6)
    {
        w_u16(object + 140, 0);
        w_u16(object + 142, 0);
    }
    w_u32(sweep + 16, r_u32(object + 20));
    w_u32(sweep + 20, r_u32(object + 24));
    value = r_u32(object + 28);
    w_u16(contacts + 96, 0);
    w_u16(contacts + 98, 0);
    w_u32(sweep + 24, value);
    result = sub_80030040(contacts, previous, object + 20, 0x800A6FD8);
    if (r_s16(contacts + 96))
    {
        // This branch and both owner callbacks are absent from the pseudocode
        selected = contacts + 12 * (uint32)(sint32)(sint16)result;
        motion_x = (0u - (uint32)r_s16(object + 140)) << 16;
        motion_z = (0u - (uint32)r_s16(object + 142)) << 16;
        w_u32(response, motion_x);
        w_u32(response + 4, motion_z);
        sub_80023918(r_u32(selected), r_u32(selected + 8), response, response + 4);
        motion_x = 0u - r_u32(response);
        motion_z = 0u - r_u32(response + 4);
        w_u16(object + 140, (uint32)((sint32)motion_x >> 16));
        w_u16(object + 142, (uint32)((sint32)motion_z >> 16));
        w_u32(owner + 20, r_u32(object + 20) - r_u32(sweep + 16) + r_u32(owner + 20));
        dz = r_u32(object + 28) - r_u32(sweep + 24);
        value = r_u32(owner + 16);
        w_u32(owner + 28, dz + r_u32(owner + 28));
        draft_call_adapter(r_u32(value + 4), owner, sweep + 16);
        sub_80023918(r_u32(selected), r_u32(selected + 8), sweep + 16, sweep + 24);
        draft_call_adapter(r_u32(r_u32(owner + 16) + 24), owner, sweep + 16);
    }
    model = r_u8(r_u32(0x800A8548) + r_u16(object + 32));
    physical = r_u32(0x800A90AC) + 40 * model;
    sub_80029970(object, (uint32)r_s16(physical + 32), 9, 1, sweep);
    result = (uint32)r_s16(owner + 58);
    if (!result)
    {
        w_u16(object + 56, 9);
        w_u16(object + 58, 0);
        w_u8(object + 13, 2);
        sub_80052988(object);
        result = sub_800608F8(object);
    }
    draft_scratch_release(mark);
    return result;
}
