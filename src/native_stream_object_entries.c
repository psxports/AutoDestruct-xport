#include "native_call_dispatch.h"

uint32 sub_8001BED0(uint32 packet, uint32 ordering_table, uint32 parameter, uint32 stream, uint32 detail)
{
    uint32 mark, iterator, cursor, count, consumed, command, words, target;
    FUNCTION_MARKER(0x8001BED0, "1.EXE");
    mark = draft_scratch_mark();
    iterator = draft_scratch_adapter(4);
    cursor = r_u32(stream);
    count = r_u32(stream + 4);
    consumed = 0;
    w_u32(iterator, cursor);
    while (consumed < count)
    {
        cursor = r_u32(iterator);
        command = r_u32(cursor);
        words = command & 0x7FF;
        consumed += words;
        target = r_u32(0x8008B728 + 4 * (command >> 24));
        packet = (uint32)draft_call_adapter(target, packet, ordering_table, cursor, parameter, 0, (uint32)(sint32)(sint16)detail, words, iterator);
    }
    draft_scratch_release(mark);
    return packet;
}

uint32 sub_8002298C(uint32 object, uint32 attachment, uint32 kind)
{
    uint32 result, flags;
    FUNCTION_MARKER(0x8002298C, "1.EXE");
    result = r_u16(object + 8);
    flags = r_u8(object + 14);
    result = (result | (((attachment - object) & 0xFFF) << 16) | (kind << 28)) & 0xFFFF0FFF;
    w_u32(object + 8, result);
    w_u8(object + 14, flags | 0x80);
    return result;
}

uint32 sub_800229D4(uint32 object, uint32 children, uint32 count, uint32 attachment, uint32 kind)
{
    uint32 packed, flags, result, offset;
    FUNCTION_MARKER(0x800229D4, "1.EXE");
    packed = r_u32(object + 8);
    packed = (packed & 0xFFFFF000) | ((children - object) & 0xFFF);
    packed = (packed & 0xFFFF0FFF) | ((count & 15) << 12);
    packed = (packed & 0xFFFF) | (((attachment - object) & 0xFFF) << 16);
    result = kind << 28;
    flags = r_u8(object + 14);
    w_u32(object + 8, packed | result);
    w_u8(object + 14, flags | 0x80);
    offset = children;
    for (uint32 i = 0; (sint32)i < (sint32)count; ++i)
    {
        w_u8(offset + 15, 0);
        result = (sint32)(i + 1) < (sint32)count;
        offset += 36;
    }
    return result;
}

uint32 sub_80040A38(uint32 object)
{
    uint32 tick, rotation, remaining, result, index, models;
    sint32 model;
    FUNCTION_MARKER(0x80040A38, "1.EXE");
    tick = r_u32(0x800A9010);
    rotation = (uint32)r_s16(object + 10) * tick;
    remaining = r_u16(object + 16) - tick;
    w_u16(object + 16, remaining);
    result = r_u16(object + 38) + rotation;
    w_u16(object + 38, result);
    if ((sint16)remaining < 0)
    {
        index = (uint32)r_s16(object + 18);
        w_u16(object + 16, 5);
        model = r_s16(0x80090374 + 2 * index);
        if (model < 0)
            return sub_8002289C(object);
        models = r_u32(0x800A62EC);
        index = r_u16(object + 18);
        result = (uint32)r_s16(models + 2 * (uint32)model);
        w_u16(object + 18, index + 1);
        w_u16(object + 32, result);
    }
    return result;
}

uint32 sub_80067A1C(uint32 owner, uint32 yaw)
{
    uint32 model, mark, offset, phase, result;
    FUNCTION_MARKER(0x80067A1C, "1.EXE");
    model = (uint32)r_s16(r_u32(0x800A62EC) + 364);
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
