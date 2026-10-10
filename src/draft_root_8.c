#include "draft_signatures.h"

uint32 sub_80065FD8(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 value;
    FUNCTION_MARKER(0x80065FD8u, "1.EXE");
    sub_80065EB0(a0, r_u32(0x800A9010u));
    value = r_s8(a0 + 13u);
    if (value >= 0)
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)value));
    w_u16(a0 + 32u, (uint16)r_s16(r_u32(0x800A62ECu) + 0x5Eu));
    w_u8(a0 + 13u, (uint8)((sub_80069A50() & 31u) + 20u));
    w_u32(a0, 0x80066048u);
    return draft_scratch_result(native_stack_mark, (uint64)(0x80066048u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80061CE4(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object;
    FUNCTION_MARKER(0x80061CE4u, "1.EXE");
    // TODO Allocator ABI adapter for the existing translation
    object = (uint32)draft_call_adapter(0x800226E4u, 56u);
    w_u8(object + 34u, 10u);
    w_u16(object + 8u, (uint16)a0);
    if (a1)
    {
        uint32 flags = r_u8(object + 14u);
        w_u16(object + 32u, (uint16)a1);
        w_u8(object + 14u, (uint8)(flags | 2u));
    }
    w_u8(object + 14u, (uint8)(r_u8(object + 14u) | 0x40u));
    if ((a2 & 0xFEu) == 16u)
    {
        w_u32(object, 0x80061FF8u);
        w_u16(object + 10u, 4096u);
    }
    else
        w_u32(object, 0x80061FACu);
    return draft_scratch_result(native_stack_mark, (uint64)(object));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80061834(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80061834u, "1.EXE");
    a2 &= 0xFEu;
    if (a2 == 8u)
    {
        // TODO Callee boundary remains outside this draft packet
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800632D0u, a0, a1, a2)));
    }
    if (a2 == 2u || a2 == 16u)
    {
        // TODO First call retains the input pointer; second uses the second pointer
        draft_call_adapter(0x800630DCu, a0, a1, a2);
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800630DCu, a1)));
    }
    if (a2 == 4u || a2 == 64u)
        return draft_scratch_result(native_stack_mark, (uint64)(sub_800631A4(a0)));
    return draft_scratch_result(native_stack_mark, (uint64)(a2 < 9u ? 4u : 64u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80061FAC(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x80061FACu, "1.EXE");
    value = (uint32)r_s16(a0 + 8u);
    if ((sint32)value < 0)
        return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(a0)));
    value -= r_u16(0x800A9010u);
    w_u16(a0 + 8u, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800702D4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 selection, item, pointer;
    FUNCTION_MARKER(0x800702D4u, "1.EXE");
    sub_8006F6E8(r_u32(0x800A645Cu));
    sub_8006F6E8(r_u32(0x800A6460u));
    selection = r_u32(0x800A645Cu);
    item = r_u32(0x800A6460u);
    w_u32(0x800A6460u, 0u);
    pointer = r_u32(0x80091EE0u + selection * 12u);
    item = (uint32)r_s16(pointer + item * 16u + 14u);
    w_u32(0x800A6468u, 1u);
    w_u32(0x800A645Cu, item);
    // TODO Existing audio-call ABI adapter
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80035A08u, 30u, 2048u, 255u, 0u, 0u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80066048(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 value;
    FUNCTION_MARKER(0x80066048u, "1.EXE");
    sub_80065EB0(a0, r_u32(0x800A9010u));
    value = r_s8(a0 + 13u);
    return draft_scratch_result(native_stack_mark, (uint64)(value < 0 ? sub_8002289C(a0) : (uint32)value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800631A4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object, value;
    FUNCTION_MARKER(0x800631A4u, "1.EXE");
    object = sub_800227C4(40u);
    w_u8(object + 34u, 11u);
    value = r_u16(r_u32(0x800A62ECu) + 0x154u);
    w_u8(object + 14u, (uint8)(r_u8(object + 14u) | 2u));
    w_u16(object + 32u, (uint16)value);
    w_u32(object + 20u, r_u32(a0));
    w_u32(object + 24u, r_u32(a0 + 4u));
    value = r_u32(a0 + 8u);
    w_u16(object + 36u, 50u);
    w_u32(object + 28u, value);
    w_u16(object + 38u, (uint16)sub_80069A50());
    value = r_u8(object + 14u);
    w_u32(object, 0x80063258u);
    w_u8(object + 14u, (uint8)(value | 0x40u));
    value = (sub_80069A50() & 63u) - 31u;
    w_u16(object + 8u, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80063258(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 step, product, delta, value, y;
    FUNCTION_MARKER(0x80063258u, "1.EXE");
    value = (uint32)r_s16(a0 + 36u);
    step = r_u32(0x800A9010u);
    if ((sint32)value >= 201)
        return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(a0)));
    product = (uint32)r_s16(a0 + 8u) * step;
    delta = step * 2u;
    value = r_u16(a0 + 36u);
    y = r_u32(a0 + 24u);
    w_u16(a0 + 36u, (uint16)(value + delta));
    value = r_u16(a0 + 38u);
    w_u32(a0 + 24u, y - delta);
    value += product;
    w_u16(a0 + 38u, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80035988(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index, value;
    FUNCTION_MARKER(0x80035988u, "1.EXE");
    index = (uint32)(sint16)a0;
    // TODO SDK call adapters remain fail-fast for this project
    draft_call_adapter(0x800899C0u, 0u, 1u << (index & 31u));
    w_u16(0x800BBF04u + index * 64u, 0u);
    w_u16(0x800BBF06u + index * 64u, 0u);
    value = (uint32)draft_call_adapter(0x80086EBCu, 0x800BBEFCu + index * 64u);
    w_u16(0x800A7C08u + index * 4u, 0u);
    w_u16(0x800A7C0Au + index * 4u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80070FFC(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x80070FFCu, "1.EXE");
    // TODO Logical input represents the original incoming V1 carrier
    if (a0 != 1u && a0 != 5u)
        return draft_scratch_result(native_stack_mark, (uint64)(5u));
    value = r_u32(0x800A75C0u);
    if (value)
        return draft_scratch_result(native_stack_mark, (uint64)(value));
    value = (uint32)draft_call_adapter(0x80037490u);
    w_u32(0x800A75C0u, 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80036EDC(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 attributes;
    FUNCTION_MARKER(0x80036EDCu, "1.EXE");
    // TODO Preserve unspecified SDK structure fields at the adapter boundary
    attributes = draft_scratch_adapter(40u);
    w_u16(attributes + 16u, (uint16)a0);
    w_u16(attributes + 18u, (uint16)a0);
    w_u32(attributes, 192u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8008757Cu, attributes)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005D6CC(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary, x, y, z;
    sint32 dx, dz;
    FUNCTION_MARKER(0x8005D6CCu, "1.EXE");
    x = r_u32(a0);
    y = r_u32(a0 + 4u);
    z = r_u32(a0 + 8u);
    // TODO Addressable temporary vector storage for the selected scalar callee
    temporary = draft_scratch_adapter(12u);
    w_u32(temporary, x);
    w_u32(temporary + 4u, y);
    w_u32(temporary + 8u, z);
    if ((sub_8002EAE4(temporary, a1, 1u) << 16) != 0u)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    dx = (sint16)((uint32)((sint32)r_u32(temporary) >> 8) * 2u);
    dz = (sint16)((uint32)((sint32)r_u32(temporary + 8u) >> 8) * 2u);
    x = r_u32(a1);
    z = r_u32(a1 + 8u);
    w_u32(a1, x + (uint32)dx);
    w_u32(a1 + 8u, z + (uint32)dz);
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800703B4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x800703B4u, "1.EXE");
    value = r_u32(0x800A646Cu);
    if (value == 0u)
        return draft_scratch_result(native_stack_mark, (uint64)(value));
    w_u32(0x800A6460u, sub_8006F710());
    w_u32(0x800A645Cu, sub_8006F710());
    w_u32(0x800A6468u, 1u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80035A08u, 30u, 2048u, 255u, 0u, 0u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800540E0(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 pointer, value;
    FUNCTION_MARKER(0x800540E0u, "1.EXE");
    pointer = r_u32(a0 + 60u);
    w_u32(a0, 0x800538ECu);
    value = 0x80090B1Cu;
    w_u32(a0 + 16u, value);
    w_u16(a0 + 56u, (uint16)a1);
    if (pointer)
    {
        value = sub_80069A50() & 31u;
        pointer = r_u32(a0 + 60u);
        w_u32(pointer + 88u, value);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80031B20(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 first, second, third;
    FUNCTION_MARKER(0x80031B20u, "1.EXE");
    first = r_u32(a0);
    second = r_u32(a0 + 4u);
    xport_gte_write_control(0u, first);
    xport_gte_write_control(1u, second);
    first = r_u32(a0 + 8u);
    second = r_u32(a0 + 12u);
    third = r_u32(a0 + 16u);
    xport_gte_write_control(2u, first);
    xport_gte_write_control(3u, second);
    xport_gte_write_control(4u, third);
    // TODO Existing callee ABI boundary
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80031A54u, a1, a2)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005B5D8(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8005B5D8u, "1.EXE");
    value = sub_8005B47C(a0) - a1;
    w_u32(a0 + 4u, value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}
