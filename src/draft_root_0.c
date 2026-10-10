#include "draft_signatures.h"

uint32 sub_80038970(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80038970u, "1.EXE");
    uint32 value = (uint32)(sint32)(sint16)a0;
    if ((value & r_u32(0x800A6D64u)) == 0u)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    return draft_scratch_result(native_stack_mark, (uint64)((value & r_u32(0x800A6D60u)) == 0u ? value : 0u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006F554(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8006F554u, "1.EXE");
    while (a1 != 0u)
    {
        uint32 byte = r_u8(a0);
        if (byte == 10u || byte == 0u)
            --a1;
        ++a0;
    }
    return draft_scratch_result(native_stack_mark, (uint64)(a0));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80070788(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80070788u, "1.EXE");
    if (a0 == 17u || a0 == 0u || ((sint32)a0 >= 26 && (sint32)a0 < 28))
        return draft_scratch_result(native_stack_mark, (uint64)(1u));
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A6468u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006F22C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8006F22Cu, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A8550u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800650C4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800650C4u, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80069A50(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80069A50u, "1.EXE");
    uint32 value = r_u32(0x800A63DCu);
    value = value * 5u + 1u;
    w_u32(0x800A63DCu, value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80069D8C(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80069D8Cu, "1.EXE");
    uint32 entry = r_u32(0x800A84FCu) + (a0 << 3u);
    uint32 index = (uint32)((sint32)r_u32(entry + 4u) >> 11);
    uint32 table = r_u32(0x800A7E2Cu);
    uint32 packed = r_u32(table + ((index + a1) << 2u));
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)((sint32)(packed << 20u) >> 20)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80045DD4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80045DD4u, "1.EXE");
    if ((sint8)r_u8(a0 + 0x42u) > 0)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    sint32 value = (sint8)r_u8(a0 + 0x42u);
    w_u8(a0 + 0xEu, 1u);
    w_u8(a0 + 0x40u, 0u);
    w_u8(a0 + 0x41u, 0u);
    if (value < -119)
        w_u8(a0 + 0x41u, 1u);
    w_u8(a0 + 0x42u, 127u);
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800618D4(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800618D4u, "1.EXE");
    if (a0 == 8u)
        return draft_scratch_result(native_stack_mark, (uint64)(16u));
    if (a0 == 9u)
        return draft_scratch_result(native_stack_mark, (uint64)(8u));
    if (a0 == 51u)
        return draft_scratch_result(native_stack_mark, (uint64)(32u));
    if (a0 == 1u)
        return draft_scratch_result(native_stack_mark, (uint64)(a1 == 0u ? 64u : 4u));
    return draft_scratch_result(native_stack_mark, (uint64)(2u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800619FC(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800619FCu, "1.EXE");
    uint32 kind = a0 & 0xFEu;
    uint32 index = 101u;
    if (kind == 8u || kind == 64u)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    if (kind == 4u)
        index = 172u;
    if (kind == 16u)
        index = 173u;
    if (kind == 32u)
        index = 171u;
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)r_s16(r_u32(0x800A62ECu) + (index << 1u))));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80029970(uint32 a0, uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80029970u, "1.EXE");
    uint32 count = r_u32(0x800A576Cu);
    uint32 result = count << 2u;
    if ((sint32)count < 256)
    {
        result = count * 20u;
        w_u8(0x800B3490u + result, (uint8)a2);
        count = r_u32(0x800A576Cu);
        w_u32(0x800B3480u + result, a0);
        result = count * 20u;
        w_u8(0x800B3491u + result, (uint8)a3);
        count = r_u32(0x800A576Cu);
        w_u16(0x800B3492u + result, (uint16)a1);
        uint32 value = r_u32(a4);
        result = count * 20u;
        w_u32(0x800B3484u + result, value);
        w_u32(0x800B3488u + result, r_u32(a4 + 4u));
        value = r_u32(a4 + 8u);
        w_u32(0x800A576Cu, count + 1u);
        w_u32(0x800B348Cu + result, value);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800476D8(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800476D8u, "1.EXE");
    sint32 value = (sint16)a0;
    if (value >= 0)
        return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A84FCu) + ((uint32)value << 3u)));
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A6EECu) + ((0u - (uint32)value) << 3u) - 8u));

    draft_scratch_release(native_stack_mark);
}

void sub_80031DC8(uint32 matrix, uint32 translation, uint32 vector)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80031DC8u, "1.EXE");
    uint32 first = r_u32(matrix);
    uint32 second = r_u32(matrix + 4u);
    xport_gte_write_control(0u, first);
    xport_gte_write_control(1u, second);
    first = r_u32(matrix + 8u);
    second = r_u32(matrix + 12u);
    uint32 third = r_u32(matrix + 16u);
    xport_gte_write_control(2u, first);
    xport_gte_write_control(3u, second);
    xport_gte_write_control(4u, third);
    first = r_u32(translation);
    second = r_u32(translation + 4u);
    third = r_u32(translation + 8u);
    xport_gte_write_control(5u, first);
    xport_gte_write_control(6u, second);
    xport_gte_write_control(7u, third);
    xport_gte_write_data(0u, r_u32(vector));
    xport_gte_write_data(1u, r_u32(vector + 4u));
    xport_gte_mvmva(0x480012u);
    w_u32(translation, xport_gte_read_data(25u));
    w_u32(translation + 4u, xport_gte_read_data(26u));
    w_u32(translation + 8u, xport_gte_read_data(27u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80061D90(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80061D90u, "1.EXE");
    w_u16(a2, (uint16)(r_u16(a0) - r_u16(a1)));
    w_u16(a2 + 2u, (uint16)(r_u16(a0 + 4u) - r_u16(a1 + 4u)));
    uint32 result = (uint32)r_u16(a0 + 8u) - (uint32)r_u16(a1 + 8u);
    w_u16(a2 + 4u, (uint16)result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80069E94(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80069E94u, "1.EXE");
    uint32 table = r_u32(0x800A7E2Cu);
    uint32 entry = r_u32(0x800A84FCu) + (a0 << 3u);
    uint32 packed = r_u32(entry + 4u);
    uint32 base = r_u32(0x800A8738u);
    uint32 count = packed & 15u;
    uint32 index = (uint32)((sint32)packed >> 11);
    for (uint32 i = 0u; i < count; ++i)
        if ((r_u32(table + ((index + i) << 2u)) >> 12u) + base == a1)
            return draft_scratch_result(native_stack_mark, (uint64)(i));
    return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8002289C(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8002289Cu, "1.EXE");
    uint32 flags = r_u8(a0 + 15u);
    if ((flags & 0x80u) != 0u)
    {
        uint32 owner = r_u32(a0 + 8u);
        w_u8(a0 + 15u, (uint8)(flags & 0x7Fu));
        w_u8(owner + 15u, (uint8)(r_u8(owner + 15u) - 1u));
    }
    uint32 result = r_u8(a0 + 14u) & 0xFCu;
    w_u8(a0 + 14u, (uint8)result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
