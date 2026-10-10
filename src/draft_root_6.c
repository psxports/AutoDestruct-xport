#include "draft_signatures.h"

uint32 sub_800379BC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 first, second, third, fourth, fifth, sixth;
    FUNCTION_MARKER(0x800379BCu, "1.EXE");
    first = r_u32(0x800A9308u);
    second = r_u32(0x800A7EE0u);
    third = r_u32(0x800A7FA8u);
    fourth = (uint32)r_s16(0x800A9A64u);
    fifth = r_u8(0x800A9A40u);
    sixth = r_u8(0x800A9A41u);
    w_u32(0x800A5C64u, first);
    w_u32(0x800A5C68u, second);
    w_u32(0x800A5C6Cu, third);
    w_u32(0x800A9670u, fourth);
    w_u8(0x800A839Cu, (uint8)fifth);
    w_u8(0x800A839Du, (uint8)sixth);
    return draft_scratch_result(native_stack_mark, (uint64)(first));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003CAB4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 offset, first, second, third, fourth;
    FUNCTION_MARKER(0x8003CAB4u, "1.EXE");
    for (offset = 0u; offset < 0x50u; offset += 16u)
    {
        first = r_u32(a0 + offset);
        second = r_u32(a0 + offset + 4u);
        third = r_u32(a0 + offset + 8u);
        fourth = r_u32(a0 + offset + 12u);
        w_u32(0x800A5EA8u + offset, first);
        w_u32(0x800A5EACu + offset, second);
        w_u32(0x800A5EB0u + offset, third);
        w_u32(0x800A5EB4u + offset, fourth);
    }
    first = r_u32(a0 + 0x50u);
    w_u32(0x800A5EF8u, first);
    return draft_scratch_result(native_stack_mark, (uint64)(first));

    draft_scratch_release(native_stack_mark);
}
