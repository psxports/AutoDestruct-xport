#include "draft_signatures.h"

uint32 sub_80037D8C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x80037D8Cu, "1.EXE");
    if (r_s16(0x800A5C70u) != 2) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    value = r_u16(0x800A5C9Au);
    return draft_scratch_result(native_stack_mark, (uint64)(value == 64u || value == 128u || value == 4u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006E708(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8006E708u, "1.EXE");
    value = r_u32(a0) - r_u32(a1); w_u32(a2, value);
    value = r_u32(a0 + 4u) - r_u32(a1 + 4u); w_u32(a2 + 4u, value);
    value = r_u32(a0 + 8u) - r_u32(a1 + 8u); w_u32(a2 + 8u, value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006E7BC(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8006E7BCu, "1.EXE");
    w_u32(a0 + 0x10u, a1);
    value = r_u8(a1 + 0xFu) + 1u;
    w_u8(a1 + 0xFu, (uint8)value);
    w_u8(a0 + 0xDu, (uint8)a2);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006EA04(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 offset;
    FUNCTION_MARKER(0x8006EA04u, "1.EXE");
    offset = (uint32)r_s16((a1 ? 0x8009158Cu : 0x80091584u) + a0 * 2u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)r_s16(r_u32(0x800A62ECu) + offset * 2u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800595F0(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800595F0u, "1.EXE");
    w_u32(0x800A71B8u, a0);
    w_u32(0x800A71BCu, a1);
    w_u32(0x800A71C0u, 1u);
    w_u32(0x800A6260u, 0u);
    w_u32(0x800A6264u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006E790(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 flags, pointer, value;
    FUNCTION_MARKER(0x8006E790u, "1.EXE");
    flags = r_u8(a0 + 0xEu);
    pointer = r_u32(a0 + 0x10u);
    w_u8(a0 + 0x22u, 0u);
    w_u8(a0 + 0xEu, (uint8)(flags & 0xFDu));
    value = r_u8(pointer + 0xFu) - 1u;
    w_u8(pointer + 0xFu, (uint8)value);
    w_u32(a0 + 0x10u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800537E8(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x800537E8u, "1.EXE");
    value = 0u - r_u32(r_u32(a0 + 0x3Cu) + 0x48u);
    w_u32(a1, value);
    value = r_u32(r_u32(a0 + 0x3Cu) + 0x4Cu);
    w_u32(a1 + 4u, 0u);
    value = 0u - value;
    w_u32(a1 + 8u, value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80047438(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 value;
    FUNCTION_MARKER(0x80047438u, "1.EXE");
    value = r_s16(a0 + 0x38u);
    if (value > 0) {
        w_u16(a0 + 0x38u, (uint16)(value - 1));
        value = r_s16(a0 + 0x38u);
    }
    if (value == 0) {
        w_u16(a0 + 0x38u, 0xFFFFu);
        w_u32(a0, 0x80029968u);
        return draft_scratch_result(native_stack_mark, (uint64)(0x80029968u));
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80065244(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 value;
    FUNCTION_MARKER(0x80065244u, "1.EXE");
    value = r_s16(a1 + 2u);
    w_u16(a0 + 0x46u, 0u);
    w_u16(a0 + 0x44u, (uint16)value);
    value = r_s16(a1 + 0xAu);
    w_u16(a0 + 0x48u, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800652C0(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value, base, count, destination;
    FUNCTION_MARKER(0x800652C0u, "1.EXE");
    value = r_u32(a0);
    base = r_u32(0x800A9A80u);
    count = r_u32(0x800A7C70u);
    w_u32(a0, value | 0x80000000u);
    destination = base + count * 16u;
    w_u16(destination + 6u, (uint16)a0);
    w_u16(destination + 0xEu, (uint16)(a0 >> 16));
    w_u32(0x800A7C70u, count + 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(destination));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8002A300(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 iteration, x, y, z;
    FUNCTION_MARKER(0x8002A300u, "1.EXE");
    for (iteration = 0u; iteration < 2u; ++iteration, a0 += 8u) {
        x = r_u16(a0 + 0x10u);
        y = r_u16(a0 + 0x12u);
        w_u16(a0 + 0x20u, (uint16)(0u - x));
        z = r_u16(a0 + 0x14u);
        w_u16(a0 + 0x22u, (uint16)(0u - y));
        x = r_u16(a0);
        w_u16(a0 + 0x24u, (uint16)(0u - z));
        y = r_u16(a0 + 2u);
        w_u16(a0 + 0x30u, (uint16)(0u - x));
        z = r_u16(a0 + 4u);
        w_u16(a0 + 0x32u, (uint16)(0u - y));
        w_u16(a0 + 0x34u, (uint16)(0u - z));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

static void draft5_copy_block(uint32 source, uint32 destination, uint32 words)
{
    uint32 a = r_u32(source), b = r_u32(source + 4u), c = r_u32(source + 8u);
    uint32 d = words == 4u ? r_u32(source + 12u) : 0u;
    w_u32(destination, a);
    w_u32(destination + 4u, b);
    w_u32(destination + 8u, c);
    if (words == 4u) w_u32(destination + 12u, d);
}

uint32 sub_8005E640(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 offset, value, y, z;
    FUNCTION_MARKER(0x8005E640u, "1.EXE");
    for (offset = 0u; offset < 0x80u; offset += 16u)
        draft5_copy_block(0x800A7E54u + offset, 0x800A96A0u + offset, 4u);
    draft5_copy_block(0x800A7ED4u, 0x800A9720u, 3u);
    value = r_u32(0x800A7EE4u);
    y = r_u32(0x800A7EE8u);
    z = r_u32(0x800A7EECu);
    w_u32(0x800A881Cu, value);
    w_u32(0x800A8820u, y);
    w_u32(0x800A8824u, z);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80033478(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80033478u, "1.EXE");
    w_u32(0x800A8398u, 4u);
    w_u16(0x800A6D00u, 0u);
    w_u16(0x800A6D10u, 0u);
    w_u16(0x800A9744u, 0u);
    w_u32(0x800A902Cu, 0u);
    w_u16(0x800A901Cu, 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800389E8(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index;
    FUNCTION_MARKER(0x800389E8u, "1.EXE");
    for (index = 0u; index < 16u; ++index)
        if (a0 & r_u32(0x8008B9BCu + index * 8u))
            w_u32(0x8008B9C0u + index * 8u, 75u);
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

void sub_800334A8(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800334A8u, "1.EXE");
    w_u32(0x800A98F4u, 0u);
    w_u16(0x800A866Cu, 0u);
    w_u16(0x800A901Cu, 0u);
    w_u32(0x800A8B30u, 0u);

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005E6CC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 offset, value, y, z;
    FUNCTION_MARKER(0x8005E6CCu, "1.EXE");
    for (offset = 0u; offset < 0x80u; offset += 16u)
        draft5_copy_block(0x800A96A0u + offset, 0x800A7E54u + offset, 4u);
    draft5_copy_block(0x800A9720u, 0x800A7ED4u, 3u);
    value = r_u32(0x800A881Cu);
    y = r_u32(0x800A8820u);
    z = r_u32(0x800A8824u);
    w_u32(0x800A7EE4u, value);
    w_u32(0x800A7EE8u, y);
    w_u32(0x800A7EECu, z);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}
