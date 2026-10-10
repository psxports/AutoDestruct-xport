#include "draft_signatures.h"

uint32 sub_80065EB0(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80065EB0u, "1.EXE");
    uint32 product = a1 * r_u32(a0 + 16u);
    uint32 start = r_u16(a0 + 36u);
    uint32 count = r_u8(a0 + 13u);
    w_u16(a0 + 36u, (uint16)(start + a1));
    uint32 cursor = r_u32(a0 + 24u);
    w_u8(a0 + 13u, (uint8)(count - a1));
    w_u32(a0 + 24u, cursor - (a1 << 2u));
    uint32 result = r_u16(a0 + 38u) + product;
    w_u16(a0 + 38u, (uint16)result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80064D80(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80064D80u, "1.EXE");
    uint32 index = r_u32(0x800A748Cu);
    uint32 end = r_u32(0x800A7490u);
    uint32 offset = index << 3u;
    do
    {
        if (r_u32(0x800AC6A8u + offset) == a0)
            return draft_scratch_result(native_stack_mark, (uint64)(index));
        ++index;
        offset += 8u;
        if (index == 256u)
        {
            offset = 0u;
            index = 0u;
        }
    } while (index != end);
    return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80064DF4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80064DF4u, "1.EXE");
    uint32 end = r_u32(0x800A7490u);
    uint32 result = r_u32(0x800A748Cu);
    if (end != result)
    {
        uint32 first = r_u32(a0);
        uint32 second = r_u32(a0 + 4u);
        uint32 remaining = (first & 0xFFFFFu) - ((second >> 20u) + ((first >> 20u) << 12u)) - 8u;
        result = end << 3u;
        if ((sint32)remaining >= 128)
        {
            w_u32(0x800AC6A8u + result, a0);
            w_u32(0x800AC6ACu + result, remaining);
            result = 256u;
            w_u32(0x800A7490u, end + 1u);
            if (end + 1u == 256u)
                w_u32(0x800A7490u, 0u);
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80047718(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80047718u, "1.EXE");
    uint32 packed;
    uint32 table;
    if ((sint32)a0 >= 0)
    {
        packed = r_u32(r_u32(0x800A84FCu) + (a0 << 3u) + 4u);
        table = r_u32(0x800A7E2Cu);
    }
    else
    {
        packed = r_u32(r_u32(0x800A6EECu) + ((0u - a0) << 3u) + 4u);
        table = r_u32(0x800A6EE8u);
    }
    uint32 index = (uint32)((sint32)packed >> 11) + a1;
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)((sint32)(r_u32(table + (index << 2u)) << 20u) >> 20)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80044F50(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80044F50u, "1.EXE");
    uint32 object = r_u32(a0);
    if (r_u16(object + 0x98u) != 0u)
        w_u16(object + 0x9Au, (uint16)(r_u16(object + 0x9Au) + 1u));
    else
        w_u16(object + 0x9Au, 0u);
    uint32 result = r_u32(a0);
    w_u16(result + 0x98u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80061DD0(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80061DD0u, "1.EXE");
    uint32 result = (uint32)((sint32)(r_u32(a0) + r_u32(a1)) >> 1);
    w_u32(a2, result);
    result = (uint32)((sint32)(r_u32(a0 + 4u) + r_u32(a1 + 4u)) >> 1);
    w_u32(a2 + 4u, result);
    result = (uint32)((sint32)(r_u32(a0 + 8u) + r_u32(a1 + 8u)) >> 1);
    w_u32(a2 + 8u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006F6E8(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8006F6E8u, "1.EXE");
    uint32 count = r_u32(0x800A646Cu);
    w_u32(0x800A75CCu + (count << 2u), a0);
    w_u32(0x800A646Cu, count + 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(count + 1u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80070CF4(uint32 a0, uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80070CF4u, "1.EXE");
    uint32 packet = r_u32(0x800A865Cu);
    w_u32(packet + 4u, a3 | 0x40000000u);
    w_u32(packet + 8u, r_u32(a0));
    w_u32(packet + 12u, r_u32(a1));
    uint32 order = r_u32(0x800A9A74u) + (a2 << 2u);
    w_u32(packet, (r_u32(order) & 0xFFFFFFu) | 0x03000000u);
    w_u32(0x800A865Cu, packet + 16u);
    uint32 result = (r_u32(order) & 0xFF000000u) | (packet & 0xFFFFFFu);
    w_u32(order, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80071960(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80071960u, "1.EXE");
    if ((sint32)a0 < 0)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    return draft_scratch_result(native_stack_mark, (uint64)((sint32)a1 >= (sint32)a0 ? a0 : a1));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80064DCC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80064DCCu, "1.EXE");
    uint32 previous = r_u32(0x800A7490u);
    uint32 current = previous - 1u;
    w_u32(0x800A7490u, current);
    if (current == 0xFFFFFFFFu)
        w_u32(0x800A7490u, previous + 255u);
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A7490u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005B694(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005B694u, "1.EXE");
    uint32 result = r_u16(0x800A946Au);
    w_u16(0x800A946Au, a0 != 0u);
    w_u16(0x800A9468u, (uint16)result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005D7C8(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005D7C8u, "1.EXE");
    uint32 index = r_u32(0x800A9A38u) << 1u;
    uint32 first = r_u16(0x80091058u + index);
    w_u16(a0 + 2u, 0u);
    w_u16(a0, (uint16)first);
    uint32 result = r_u16(0x80091060u + index);
    w_u16(a0 + 4u, (uint16)result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006F710(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8006F710u, "1.EXE");
    uint32 count = r_u32(0x800A646Cu) - 1u;
    w_u32(0x800A646Cu, count);
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A75CCu + (count << 2u))));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800452E8(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800452E8u, "1.EXE");
    w_u32(a1, r_u32(a0 + 100u) << 8u);
    uint32 second = r_u32(a0 + 104u);
    w_u32(a1 + 4u, 0u);
    uint32 result = second << 8u;
    w_u32(a1 + 8u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80055FA4(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80055FA4u, "1.EXE");
    uint32 index = (r_u16(a0 + 78u) & 0xFFFu) << 1u;
    sint32 magnitude = r_s16(a0 + 10u);
    sint32 sine = r_s16(0x800102E0u + index);
    if (magnitude < 0)
        magnitude = -magnitude;
    uint32 product = (uint32)magnitude * (uint32)sine;
    w_u32(a1, (uint32)((sint32)product >> 4));
    sint32 cosine = r_s16(0x80010AE0u + index);
    product = (uint32)magnitude * (uint32)cosine;
    w_u32(a1 + 4u, 0u);
    uint32 result = (uint32)((sint32)product >> 4);
    w_u32(a1 + 8u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8004549C(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8004549Cu, "1.EXE");
    w_u32(a0 + 100u, (uint32)((sint32)r_u32(a1) >> 8));
    uint32 result = (uint32)((sint32)r_u32(a1 + 8u) >> 8);
    w_u32(a0 + 104u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
