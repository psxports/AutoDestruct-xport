#include "draft_signatures.h"

uint32 sub_80034820(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80034820u, "1.EXE");
    // TODO Inputs retain the original arguments passed through to the camera callee
    if (r_u32(0x800A7E50u)) return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8005CBC8u, a0, a1)));
    sub_8005CBE8(a0, a1);
    w_u32(0x800A7E50u, 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005CBE8(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005CBE8u, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8005CB04(a0, a1, 0xFFFFFFFFu)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005E114(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8005E114u, "1.EXE");
    if ((sint32)a0 <= 0) a0 = 1u;
    if ((sint32)a0 >= 4) a0 = 3u;
    sub_8005E258(a0);
    value = r_u16(0x800A7E7Cu);
    w_u16(0x800A7ECCu, 0u); w_u16(0x800A7E7Au, (uint16)a1); w_u16(0x800A7ECAu, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005D5A8(uint32 a0, uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8005D5A8u, "1.EXE");
    w_u16(a0 + 118u, (uint16)(r_u16(a0 + 118u) + r_u32(0x800A9010u) * 3u));
    value = sub_8005D5E8(a0, a1, a2, a3);
    w_u16(0x800A8566u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80068F70(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object, flags, height;
    FUNCTION_MARKER(0x80068F70u, "1.EXE");
    object = sub_800227C4(40u);
    w_u32(object + 20u, a1 + (r_u32(a0) & 0xFFFu));
    a2 += (r_u32(a0) >> 12) & 0xFFFu;
    flags = r_u8(object + 14u);
    w_u32(object + 28u, a2);
    height = r_u16(a0 + 4u);
    w_u32(object + 8u, 0u); w_u8(object + 14u, (uint8)(flags | 0x20u));
    w_u32(object, 0x80069018u); w_u8(object + 13u, 255u);
    w_u32(object + 16u, 69u); w_u32(object + 24u, 0u - height);
    return draft_scratch_result(native_stack_mark, (uint64)(object));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80033724(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80033724u, "1.EXE");
    w_u32(0x800A6C74u + a0 * 12u, 0x10101u);
    return draft_scratch_result(native_stack_mark, (uint64)(sub_80033764(a0, a1)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8002133C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8002133Cu, "1.EXE");
    // TODO SDK projection adapters
    draft_call_adapter(0x800836DCu, 160u, 120u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8008358Cu, 125u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80033120(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80033120u, "1.EXE");
    w_u32(0x800A5C08u, 0u); w_u32(0x800A5C0Cu, 0u);
    while (sub_80036FE4()) {}
    sub_80037320();
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80036FE4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 first, second, third, fourth, attributes, value, flags;
    FUNCTION_MARKER(0x80036FE4u, "1.EXE");
    if (r_u32(0x800A5C60u)) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    first = r_u32(0x800A9308u); second = r_u32(0x800A7EE0u);
    third = r_u32(0x800A7FA8u); fourth = r_u32(0x800A9CD0u);
    w_u32(0x800A5C30u, first); w_u32(0x800A5C34u, second);
    w_u32(0x800A5C38u, third); w_u32(0x800A9684u, fourth);
    sub_80036EDC(0u);
    // TODO Addressable SDK attributes preserve the unspecified fields
    attributes = draft_scratch_adapter(40u);
    w_u32(attributes, 256u); w_u32(attributes + 20u, 0u);
    draft_call_adapter(0x8008757Cu, attributes);
    flags = r_u8(0x800A9A40u); value = r_u8(0x800A9A41u);
    w_u8(0x800A9678u, (uint8)flags); w_u8(0x800A9679u, (uint8)value);
    value = (uint32)draft_call_adapter(0x8007B4A0u, 9u, 0u);
    if (value != 1u) return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    w_u32(0x800A5C60u, 1u); w_u32(0x800A966Cu, 60u);
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003315C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8003315Cu, "1.EXE");
    value = r_u32(0x800A8B30u);
    w_u32(0x800A7BE0u, 0u);
    if (!value && (sint32)r_u32(0x800A5C08u) < 5 && !r_u32(0x800A5C0Cu)) {
        value = (uint32)draft_call_adapter(0x8003732Cu);
        w_u32(0x800A7BE0u, value);
        if (value != 0xFFFFFFFFu) w_u32(0x800A5C08u, r_u32(0x800A5C08u) + 1u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A7BE0u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80069018(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80069018u, "1.EXE");
    if (!(r_u8(a0 + 14u) & 1u)) return draft_scratch_result(native_stack_mark, (uint64)(sub_80036CFC(a0 + 13u)));
    if (r_u8(a0 + 12u) < 5u && r_u32(a0 + 8u) == 0u) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    sub_800369E0(a0 + 20u, a0 + 13u, 1024u, (uint32)r_s16(a0 + 16u));
    w_u32(a0 + 8u, 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800442AC(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800442ACu, "1.EXE");
    // TODO Full MIPS supplies the three real stack arguments missing from pseudocode
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8004328Cu, r_u32(0x800A5F68u), 0x54000040u, a0 & 255u, 0x808080u, (uint32)-148, a1 + 16u, 150u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005FF38(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8005FF38u, "1.EXE");
    value = (uint32)r_s16(a0 + 8u);
    if ((sint32)value <= 0) return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(a0)));
    value -= r_u16(0x800A9010u);
    w_u16(a0 + 8u, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80034C88(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80034C88u, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)(sub_80033400()));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800390E4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800390E4u, "1.EXE");
    w_u16(0x800A8218u, 4096u); w_u16(0x800A821Cu, 160u); w_u16(0x800A821Eu, 120u);
    w_u16(0x800A821Au, 125u); w_u16(0x800A8224u, 320u);
    w_u16(0x800A8220u, 0u); w_u16(0x800A8222u, 0u); w_u16(0x800A8226u, 240u);
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8002133C()));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006E490(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object, value;
    FUNCTION_MARKER(0x8006E490u, "1.EXE");
    // TODO Existing allocator and setup ABI boundaries
    object = (uint32)draft_call_adapter(0x80022744u, 56u, a0);
    w_u8(object + 34u, 0u);
    w_u32(object + 20u, r_u32(a0 + 20u)); w_u32(object + 24u, r_u32(a0 + 24u));
    w_u32(object + 28u, r_u32(a0 + 28u));
    sub_80055A70(object + 36u);
    w_u8(object + 35u, 1u); w_u32(object, 0x8006E520u);
    w_u8(object + 13u, 0u); w_u32(object + 16u, 0u);
    value = (uint32)draft_call_adapter(0x8006E5B4u, object);
    w_u32(0x800A7558u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}
