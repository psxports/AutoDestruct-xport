#include "draft_signatures.h"

uint32 sub_800330D4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800330D4u, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A6D24u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80033400(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80033400u, "1.EXE");
    w_u32(0x800A902Cu, 1u);
    w_u32(0x800A7FB8u, 0u);
    w_u16(0x800A9744u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

void sub_8003570C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003570Cu, "1.EXE");
    w_u32(0x800A98F4u, 0u);
    w_u16(0x800A866Cu, 0u);
    w_u16(0x800A901Cu, 0u);
    w_u32(0x800A8B30u, 0u);

    draft_scratch_release(native_stack_mark);
}

void sub_8003D6B8(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003D6B8u, "1.EXE");
    w_u16(0x800A5EF8u, (uint16)a0);

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800595B8(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800595B8u, "1.EXE");
    if (r_u32(0x800A625Cu) == 1u) {
        w_u32(0x800A625Cu, 2u);
        w_u32(0x800A6270u, 0u);
    }
    if (a0 == 1u) {
        w_u32(0x800A625Cu, 0u);
        w_u32(0x800A6268u, 0u);
        w_u32(0x800A626Cu, 0u);
        w_u32(0x800A6270u, 0u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(2u));

    draft_scratch_release(native_stack_mark);
}

void sub_8003ADE0(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003ADE0u, "1.EXE");
    w_u16(0x800A9734u, 0u);
    w_u32(0x800A6E4Cu, 0u);

    draft_scratch_release(native_stack_mark);
}

void sub_8006F790(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8006F790u, "1.EXE");
    w_u16(0x80091966u, 0u);
    w_u16(0x80091976u, 0u);

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80029884(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x80029884u, "1.EXE");
    value = r_u16(a0 + 0x50u); w_u16(a1, (uint16)value);
    value = r_u16(a0 + 0x52u); w_u16(a1 + 2u, (uint16)value);
    value = r_u16(a0 + 0x54u); w_u16(a1 + 4u, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80063590(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 value;
    FUNCTION_MARKER(0x80063590u, "1.EXE");
    w_u16(a1 + 0x12u, 0u);
    w_u16(a1 + 0xAu, 0u);
    w_u16(a1 + 2u, 0u);
    w_u16(a1, r_u16(a0));
    w_u16(a1 + 4u, r_u16(a0 + 4u));
    w_u16(a1 + 8u, r_u16(a0 + 8u));
    w_u16(a1 + 0xCu, r_u16(a0 + 0xCu));
    value = (r_s16(a0 + 0x10u) + r_s16(a0 + 0x18u)) >> 1;
    w_u16(a1 + 0x10u, (uint16)value);
    value = (r_s16(a0 + 0x14u) + r_s16(a0 + 0x1Cu)) >> 1;
    w_u16(a1 + 0x14u, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003CAFC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003CAFCu, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)(r_u8(0x800A5E88u + (uint32)r_s16(0x800A5EF2u))));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80047670(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 index;
    FUNCTION_MARKER(0x80047670u, "1.EXE");
    index = r_s16(a0 + 0x3Cu);
    if ((index != -1 && r_u8(r_u32(r_u32(0x800A851Cu) + (uint32)index * 4u) + 0x41u) == 0u)
        || r_s8(a0 + 0x42u) <= 0) {
        w_u8(a0 + 0x40u, 1u);
        w_u8(a0 + 0x42u, 1u);
        w_u16(a0 + 0x3Cu, 0xFFFFu);
        w_u32(a0, 0x80047480u);
        return draft_scratch_result(native_stack_mark, (uint64)(0x80047480u));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003CB14(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8003CB14u, "1.EXE");
    value = (uint32)r_s16(0x800A5EECu);
    if ((sint32)value > 0) {
        value -= r_u16(0x800A9010u);
        w_u16(0x800A5EECu, (uint16)value);
        value <<= 16;
        if ((sint32)value < 0) w_u16(0x800A5EECu, 0u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003D6AC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003D6ACu, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)r_s16(0x800A5EF8u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003ABE4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 value;
    FUNCTION_MARKER(0x8003ABE4u, "1.EXE");
    value = r_s16(0x800A9734u);
    return draft_scratch_result(native_stack_mark, (uint64)(value >= 1 && value <= 3 ? (uint32)value : 0u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80037D50(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x80037D50u, "1.EXE");
    if (r_s16(0x800A5C70u) != 2) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    value = r_u16(0x800A5C98u);
    return draft_scratch_result(native_stack_mark, (uint64)(value == 64u || value == 128u || value == 4u));

    draft_scratch_release(native_stack_mark);
}

void nullsub_11(void)
{
    FUNCTION_MARKER(0x8003D330u, "1.EXE");
}
