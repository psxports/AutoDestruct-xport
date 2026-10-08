#include "draft_signatures.h"

void sub_800510D0(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800510D0u, "1.EXE");
    w_u32(0x800A6228u, 0u);

    draft_scratch_release(native_stack_mark);
}

void sub_8003D6A0(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003D6A0u, "1.EXE");
    w_u16(0x800A5EF6u, (uint16)a0);

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003D270(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003D270u, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)r_s16(0x800A5EEEu)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003D688(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003D688u, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)r_s16(0x800A5EF6u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003CA68(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003CA68u, "1.EXE");
    uint32 source = 0x800A5EA8u;
    do
    {
        uint32 first = r_u32(source);
        uint32 second = r_u32(source + 4u);
        uint32 third = r_u32(source + 8u);
        uint32 fourth = r_u32(source + 12u);
        w_u32(a0, first);
        w_u32(a0 + 4u, second);
        w_u32(a0 + 8u, third);
        w_u32(a0 + 12u, fourth);
        source += 16u;
        a0 += 16u;
    } while (source != 0x800A5EF8u);
    uint32 result = r_u32(source);
    w_u32(a0, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800356D8(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800356D8u, "1.EXE");
    w_u32(0x800A8398u, 4u);
    w_u16(0x800A6D00u, 0u);
    w_u16(0x800A6D10u, 0u);
    w_u16(0x800A9744u, 0u);
    w_u32(0x800A902Cu, 0u);
    w_u16(0x800A901Cu, 1u);
    w_u16(0x800A866Cu, 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80033E90(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80033E90u, "1.EXE");
    w_u16(0x800A8218u, 0x840u);
    w_u16(0x800A821Cu, 0xE4u);
    w_u16(0x800A821Eu, 0xA1u);
    w_u16(0x800A821Au, 0x42u);
    w_u16(0x800A8220u, 0x92u);
    w_u16(0x800A8222u, 0x61u);
    w_u16(0x800A8224u, 0xA5u);
    w_u16(0x800A8226u, 0x81u);
    return draft_scratch_result(native_stack_mark, (uint64)(0x81u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005CB04(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005CB04u, "1.EXE");
    w_u32(0x800A87FCu, r_u32(a1));
    w_u32(0x800A8800u, r_u32(a1 + 4u));
    uint32 third = r_u32(a1 + 8u);
    w_u16(0x800A8814u, 0u);
    w_u16(0x800A8816u, (uint16)a2);
    w_u32(0x800A8804u, third);
    if ((sint32)a0 <= 0) a0 = 1u;
    uint32 object = r_u32(0x800A7BACu);
    w_u16(0x800A881Au, (uint16)a0);
    uint32 result = 1u;
    if (r_u8(object + 14u) != 1u)
    {
        result = r_u8(object + 14u) | 0x82u;
        w_u8(object + 14u, (uint8)result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005CB7C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005CB7Cu, "1.EXE");
    uint32 second = r_u32(0x800A8800u);
    uint32 result = r_u32(0x800A87FCu);
    uint32 third = r_u32(0x800A8804u);
    w_u32(0x800A880Cu, second);
    second -= 400u;
    w_u32(0x800A8808u, result);
    w_u32(0x800A7EE4u, result);
    w_u32(0x800A8810u, third);
    w_u32(0x800A7EECu, third);
    w_u32(0x800A7EE8u, second);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

void sub_80038964(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80038964u, "1.EXE");
    w_u32(0x800A6D60u, a0);

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80041DF8(uint32 a0, uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80041DF8u, "1.EXE");
    w_u16(a0 + 24u, (uint16)a3);
    w_u16(a0 + 20u, (uint16)a1);
    w_u16(a0 + 22u, (uint16)a2);
    w_u16(a0 + 26u, (uint16)a4);
    return draft_scratch_result(native_stack_mark, (uint64)(a4));

    draft_scratch_release(native_stack_mark);
}

void sub_80041E1C(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80041E1Cu, "1.EXE");
    w_u32(a0 + 28u, a1);

    draft_scratch_release(native_stack_mark);
}

void nullsub_9(void)
{
    FUNCTION_MARKER(0x800334CCu, "1.EXE");
}

void sub_80037320(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80037320u, "1.EXE");
    w_u32(0x800A6D2Cu, 0u);

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80029A1C(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80029A1Cu, "1.EXE");
    uint32 count = r_u32(0x800A5770u);
    uint32 result = (sint32)count < 16;
    if (result != 0u)
    {
        uint32 offset = count << 4u;
        w_u32(0x800A8828u + offset, r_u32(a1));
        w_u32(0x800A882Cu + offset, r_u32(a1 + 4u));
        uint32 third = r_u32(a1 + 8u);
        result = count + 1u;
        w_u32(0x800A5770u, result);
        w_u32(0x800A8834u + offset, a0);
        w_u32(0x800A8830u + offset, third);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005FEC0(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005FEC0u, "1.EXE");
    sint32 remaining = r_s16(a0 + 8u);
    uint32 step = r_u32(0x800A9010u);
    uint32 result;
    if (remaining <= 0)
    {
        uint32 resource = r_u32(0x800A62ECu);
        w_u16(a0 + 8u, 4u);
        w_u32(a0, 0x8005FF38u);
        result = (uint32)r_s16(resource + 0x3Cu);
        w_u16(a0 + 32u, (uint16)result);
    }
    else
    {
        uint32 product = step * (uint32)r_s16(a0 + 10u);
        w_u16(a0 + 8u, (uint16)((uint32)remaining - (step << 1u)));
        result = r_u16(a0 + 38u) + product;
        w_u16(a0 + 38u, (uint16)result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
