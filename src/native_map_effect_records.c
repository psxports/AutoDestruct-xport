#include "native_call_dispatch.h"

uint32 sub_80065308(uint32 tile, uint32 record)
{
    uint32 links, previous, next, entry, result;
    FUNCTION_MARKER(0x80065308, "1.EXE");
    links = r_u32(record + 8);
    previous = links & 0xFFF;
    if (previous)
    {
        entry = r_u32(0x800A9754) + 12 * previous;
        w_u32(entry - 4, (r_u32(entry - 4) & 0xFF000FFF) | (links & 0xFFF000));
    }
    else
        w_u16(r_u32(0x800A84F8) + 8 * tile + 6, (links >> 12) & 0xFFF);
    links = r_u32(record + 8);
    next = (links >> 12) & 0xFFF;
    result = 2 * next;
    if (next)
    {
        result = r_u32(0x800A9754) + 12 * next;
        w_u32(result - 4, (r_u32(result - 4) & 0xFFFFF000) | (links & 0xFFF));
    }
    return result;
}

uint32 sub_800653C4(uint32 tile, uint32 record)
{
    uint32 records, difference, head, links, next, result, index;
    FUNCTION_MARKER(0x800653C4, "1.EXE");
    records = r_u32(0x800A9754);
    difference = record - records;
    head = r_u32(0x800A84F8) + 8 * tile;
    links = r_u32(record + 8) & 0xFF000FFF;
    next = r_u16(head + 6);
    links |= (next & 0xFFF) << 12;
    w_u32(record + 8, links & 0xFFFFF000);
    result = difference / 12;
    index = result + 1;
    w_u16(head + 6, index);
    if (next)
    {
        result = records + 12 * next;
        w_u32(result - 4, (r_u32(result - 4) & 0xFFFFF000) | (index & 0xFFF));
    }
    return result;
}

uint32 sub_80065458(uint32 record, uint32 object, uint32 previous_tile, uint32 angles)
{
    uint32 word, packed, tile;
    FUNCTION_MARKER(0x80065458, "1.EXE");
    word = r_u32(record + 4);
    word = (word & 0xFFE0FFFF) | (((r_u16(angles) >> 7) & 31) << 16);
    w_u32(record + 4, word);
    word = (word & 0xFC1FFFFF) | (((r_u16(angles + 2) >> 7) & 31) << 21);
    w_u32(record + 4, word);
    word = (word & 0x83FFFFFF) | (((r_u16(angles + 4) >> 7) & 31) << 26);
    packed = r_u32(record);
    w_u32(record + 4, word);
    packed = (packed & 0xFFFFF000) | (r_u32(object + 20) & 0xFFF);
    w_u32(record, packed);
    packed = (packed & 0xFF000FFF) | ((r_u32(object + 28) & 0xFFF) << 12);
    w_u32(record, packed);
    w_u16(record + 4, 0 - (uint32)r_u16(object + 24));
    tile = (uint32)(r_s32(object + 20) >> 12) + 80 * (uint32)(r_s32(object + 28) >> 12);
    if (tile != (uint32)(sint32)(sint16)previous_tile)
    {
        sub_80065308((uint32)(sint32)(sint16)previous_tile, record);
        sub_800653C4(tile, record);
    }
    return (uint32)(sint32)(sint16)tile;
}

uint32 sub_80052C98(uint32 object, uint32 motion)
{
    uint32 mark, scratch, contacts, flags, first, second, velocity, selected, value, result;
    FUNCTION_MARKER(0x80052C98, "1.EXE");
    mark = draft_scratch_mark();
    scratch = draft_scratch_adapter(88);
    contacts = scratch + 16;
    flags = scratch + 80;
    w_u32(scratch, r_u32(object + 20));
    w_u32(scratch + 4, r_u32(object + 24));
    w_u32(scratch + 8, r_u32(object + 28));
    first = sub_800514A0(motion + 24, object);
    second = sub_800518C4(motion + 20);
    sub_80051BA4(object, motion);
    sub_80029DDC(object, contacts, r_u8(r_u32(0x800A8548) + r_u16(object + 32)));
    sub_8002A300(contacts);
    velocity = 781 * (uint32)(r_s32(0x800A63D8) >> 8) + r_u32(motion);
    w_u32(motion, velocity);
    w_u32(object + 24, r_u32(object + 24) + (uint32)((sint32)velocity >> 16));
    if ((uint16)sub_80051328(object, contacts, flags))
        w_u32(motion, 0);
    // Original one-based contact indexing can reach the preceding local buffer
    selected = contacts + (((uint32)r_s16(motion + 26) - 1) << 3);
    value = r_u16(motion + 4) - (uint32)r_u16(selected);
    selected = contacts + (((uint32)r_s16(motion + 26) - 1) << 3);
    w_u16(motion + 16, value);
    value = r_u16(motion + 8) - (uint32)r_u16(selected + 4);
    selected = contacts + (((uint32)r_s16(motion + 26) - 1) << 3);
    w_u16(motion + 18, value);
    value = (uint32)r_s16(selected);
    selected = contacts + (((uint32)r_s16(motion + 26) - 1) << 3);
    w_u32(motion + 4, value);
    w_u32(motion + 8, (uint32)r_s16(selected + 4));
    w_u32(object + 20, r_u32(object + 20) + (uint32)r_s16(motion + 16));
    w_u32(object + 28, r_u32(object + 28) + (uint32)r_s16(motion + 18));
    if (!(uint16)second && !(uint16)first)
        w_u16(motion + 26, 0xFFFF);
    sub_80029D44(contacts);
    result = sub_80051A8C(motion, object, contacts, scratch, 0);
    draft_scratch_release(mark);
    return result;
}
