#include "draft_signatures.h"

uint32 sub_80057D14(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 b6, b4, b5, b7, b15, h8, h10, pointer;
    FUNCTION_MARKER(0x80057D14u, "1.EXE");
    b6 = r_u8(a0 + 6u);
    b4 = r_u8(a0 + 4u);
    b5 = r_u8(a0 + 5u);
    b7 = r_u8(a0 + 7u);
    b15 = r_u8(a0 + 15u);
    h8 = (uint32)r_s16(a0 + 8u);
    h10 = (uint32)r_s16(a0 + 10u);
    pointer = r_u32(a0);
    // TODO Existing sprite callee ABI boundaries
    draft_call_adapter(0x80041C9Cu, 0x800A7108u, pointer, b4, b5, b6, b7, b15, h8, h10);
    draft_call_adapter(0x80041DB4u, 0x800A7108u, (uint32)r_s16(a0 + 12u), (uint32)r_s8(a0 + 14u), 0u);
    draft_call_adapter(0x80041D90u, 0x800A7108u, r_u32(a0 + 16u));
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80020AB4u, 0x800A7108u, r_u32(0x800A9A74u) + 0x2F8u, 1u, 0u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80059274(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x80059274u, "1.EXE");
    value = (uint32)draft_call_adapter(0x8003CF6Cu);
    if (value & 0x8000u)
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80044C78u, 1u, 0u, 74u, 107u)));
    value = (uint32)draft_call_adapter(0x8003CF6Cu);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80044C78u, 1u, (uint32)(sint16)value, 84u, 96u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005AB3C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8005AB3Cu, "1.EXE");
    value = r_u32(0x800A7E14u);
    if ((sint32)value < 0)
        value += 1023u;
    w_u32(0x800A7458u, (uint32)((sint32)value >> 10) - 14u);
    value = r_u32(0x800A7E20u);
    if ((sint32)value < 0)
        value += 511u;
    w_u32(0x800A745Cu, 611u - (uint32)((sint32)value >> 9));
    draft_call_adapter(0x8005ABD8u);
    if (!r_u32(0x800A8B30u))
        draft_call_adapter(0x80044618u);
    value = r_u32(0x800A8540u) & 1u;
    return draft_scratch_result(native_stack_mark, (uint64)(value ? (uint32)draft_call_adapter(0x800446D8u) : value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80036188(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index;
    FUNCTION_MARKER(0x80036188u, "1.EXE");
    index = (uint32)(sint16)a0;
    if (draft_call_adapter(0x80086EE4u, 1u << (index & 31u)) != 1u)
        return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    w_u16(0x800BBF10u + index * 64u, (uint16)a1);
    draft_call_adapter(0x80086EBCu, 0x800BBEFCu + index * 64u);
    return draft_scratch_result(native_stack_mark, (uint64)(index));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800361FC(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index, product;
    sint32 value;
    FUNCTION_MARKER(0x800361FCu, "1.EXE");
    index = (uint32)(sint16)a0;
    if (draft_call_adapter(0x80086EE4u, 1u << (index & 31u)) != 1u)
        return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    product = (uint32)r_s16(0x800A9D6Cu) * 16383u;
    value = (sint32)product / 16384;
    product = (uint32)value * (uint32)(sint16)a1;
    value = (sint32)product / 256;
    w_u16(0x800BBF06u + index * 64u, (uint16)value);
    w_u16(0x800BBF04u + index * 64u, (uint16)value);
    draft_call_adapter(0x80086EBCu, 0x800BBEFCu + index * 64u);
    return draft_scratch_result(native_stack_mark, (uint64)(index));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800661CC(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 angle, shift, step, value;
    FUNCTION_MARKER(0x800661CCu, "1.EXE");
    angle = r_u32(a0 + 16u);
    shift = r_u8(a0 + 13u);
    value = (uint32)r_s16(0x800102E0u + (angle & 0xFFFu) * 2u);
    step = r_u32(0x800A9010u);
    value = (uint32)draft_call_adapter(0x800551CCu, (uint32)((sint32)value >> (shift & 31u)), a0 + 36u);
    w_u32(a0 + 16u, angle + step * 4u);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006E748(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary, x, y, z;
    FUNCTION_MARKER(0x8006E748u, "1.EXE");
    temporary = draft_scratch_adapter(16u);
    sub_8006E708(a0, a1, temporary);
    x = r_u32(temporary);
    y = r_u32(temporary + 4u);
    z = r_u32(temporary + 8u);
    x = (uint32)draft_call_adapter(0x80069BE0u, x, y);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80069BE0u, x, z)));

    draft_scratch_release(native_stack_mark);
}

void sub_80055818(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 storage, x, y, z, magnitude, pitch, yaw;
    FUNCTION_MARKER(0x80055818u, "1.EXE");
    x = r_u32(a1);
    y = r_u32(a1 + 4u);
    z = r_u32(a1 + 8u);
    magnitude = (uint32)draft_call_adapter(0x80069BE0u, x, z);
    pitch = sub_80055A9C(y, magnitude);
    yaw = sub_80055A9C(x, z) + 2048u;
    // TODO Addressable scalar helper buffers
    storage = draft_scratch_adapter(48u);
    w_u16(storage, (uint16)pitch);
    w_u16(storage + 2u, (uint16)yaw);
    sub_80055288(storage, storage + 24u);
    w_u32(storage + 8u, 0u);
    w_u32(storage + 12u, 0u);
    w_u32(storage + 16u, a2);
    sub_80031E30(storage + 24u, a0, storage + 8u);

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005EAD8(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 packet, index;
    FUNCTION_MARKER(0x8005EAD8u, "1.EXE");
    packet = r_u32(0x800A865Cu);
    for (index = 6u; index > 0u; --index)
        packet = sub_8005E95C(packet, index);
    w_u32(0x800A865Cu, packet);
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

void sub_800331D8(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800331D8u, "1.EXE");
    w_u16(0x800A6CECu, 0u);
    w_u16(0x800A6CF0u, 0u);
    // TODO Original return carrier is unchanged by the void callee
    sub_80037320();

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80046E18(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value, flags;
    sint32 amount;
    FUNCTION_MARKER(0x80046E18u, "1.EXE");
    if ((sint32)r_u32(0x800A7C6Cu) >= 500)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    if ((sint32)r_u32(0x800A613Cu) >= 500)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    value = sub_80069A50() & 255u;
    if (value)
        return draft_scratch_result(native_stack_mark, (uint64)(value));
    flags = r_u8(a0 + 14u);
    amount = r_s16(a0 + 80u);
    w_u8(a0 + 14u, (uint8)(flags | 2u));
    value = r_u32(0x800A613Cu);
    w_u32(a0, 0x80046E9Cu);
    w_u32(0x800A613Cu, value + (uint32)amount);
    return draft_scratch_result(native_stack_mark, (uint64)(0x80046E9Cu));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005EE38(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 angle, other, value, x;
    FUNCTION_MARKER(0x8005EE38u, "1.EXE");
    angle = sub_80055A9C(r_u32(a1 + 8u), r_u32(a1));
    other = sub_80055A9C((uint32)r_s16(a0 + 4u), (uint32)r_s16(a0));
    value = (uint32)r_s16(0x80010AE0u + ((angle - other) & 0xFFFu) * 2u);
    if ((sint32)value < 0)
    {
        value = 0u - r_u16(a0 + 4u);
        x = 0u - r_u16(a0);
        w_u16(a0 + 4u, (uint16)value);
        w_u16(a0, (uint16)x);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800298A8(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scale, x, z, value;
    FUNCTION_MARKER(0x800298A8u, "1.EXE");
    x = r_u32(a1);
    scale = r_u32(0x800A56C0u);
    w_u32(a0 + 476u, (uint32)((sint32)x / -136) * scale);
    z = r_u32(a1 + 8u);
    w_u32(a0 + 480u, (uint32)((sint32)z / -136) * scale);
    x = r_u32(a1);
    z = r_u32(a1 + 8u);
    value = (uint32)draft_call_adapter(0x80069BE0u, (uint32)((sint32)x >> 8), (uint32)((sint32)z >> 8)) << 8;
    w_u32(a0 + 472u, value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800451B4(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value, pointer, x, z, px, pz;
    sint32 index;
    FUNCTION_MARKER(0x800451B4u, "1.EXE");
    if (r_s16(0x800A9014u) <= 0)
    {
        value = (uint32)r_s16(0x800A9730u);
        if (value)
            return draft_scratch_result(native_stack_mark, (uint64)(value));
    }
    index = (sint16)a1;
    if (index < 0)
        return draft_scratch_result(native_stack_mark, (uint64)(a1 << 16));
    if (r_s16(0x800A7F3Eu) < index)
        return draft_scratch_result(native_stack_mark, (uint64)(1u));
    pointer = r_u32(0x800A7BACu);
    x = r_u32(a0);
    z = r_u32(a0 + 8u);
    px = r_u32(pointer + 20u);
    pz = r_u32(pointer + 28u);
    value = (uint32)draft_call_adapter(0x80069BE0u, px - x, pz - z);
    if ((sint32)value < (sint32)r_u32(0x800A7F14u))
    {
        w_u32(0x800A7F14u, value);
        w_u16(0x800A9730u, (uint16)a1);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800313EC(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 previous, child;
    FUNCTION_MARKER(0x800313ECu, "1.EXE");
    previous = r_u32(0x800A6098u);
    child = r_u32(a0 + 8u);
    while (r_u32(previous + 4u) != a0)
        previous = r_u32(previous + 4u);
    while (child)
    {
        sub_80064D60(child);
        child = r_u32(child + 4u);
    }
    if (a0 == r_u32(0x800A609Cu))
    {
        w_u32(0x800A609Cu, previous);
        w_u32(previous + 4u, 0u);
    }
    else
        w_u32(previous + 4u, r_u32(a0 + 4u));
    return draft_scratch_result(native_stack_mark, (uint64)(sub_80064D60(a0)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80057CB8(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 x, z, value;
    FUNCTION_MARKER(0x80057CB8u, "1.EXE");
    x = r_u32(0x800A9688u + a0 * 8u) - r_u32(0x800A7E14u);
    z = r_u32(0x800A968Cu + a0 * 8u) - r_u32(0x800A7E20u);
    value = sub_80055A9C(x, z);
    return draft_scratch_result(native_stack_mark, (uint64)((value - (r_u32(0x800A8518u) + 1024u)) & 0xFFFu));

    draft_scratch_release(native_stack_mark);
}
