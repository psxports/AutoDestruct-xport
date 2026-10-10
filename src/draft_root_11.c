#include "draft_signatures.h"
#include <stdlib.h>

uint32 sub_8006E5B4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object;
    FUNCTION_MARKER(0x8006E5B4u, "1.EXE");
    object = sub_8006E62C(a0);
    w_u8(object + 35u, 4u);
    return draft_scratch_result(native_stack_mark, (uint64)(object));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006E62C(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object;
    FUNCTION_MARKER(0x8006E62Cu, "1.EXE");
    // TODO Existing allocator ABI boundary
    object = (uint32)draft_call_adapter(0x80022744u, 56u, r_u32(a0 + 8u));
    w_u32(object + 20u, r_u32(a0 + 20u));
    w_u32(object + 24u, r_u32(a0 + 24u));
    w_u32(object + 28u, r_u32(a0 + 28u));
    sub_80055A70(object + 36u);
    w_u32(object, 0x8006ED00u);
    w_u8(object + 34u, 0u);
    w_u16(object + 54u, 0u);
    w_u32(object + 16u, 0u);
    w_u8(object + 13u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(object));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8004ED64(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 first, second, temporary;
    FUNCTION_MARKER(0x8004ED64u, "1.EXE");
    first = r_u32(0x800A6150u);
    second = r_u32(0x800A6154u);
    // TODO Addressable vector storage and existing GTE callee ABI boundaries
    temporary = draft_scratch_adapter(8u);
    w_u32(temporary, first);
    w_u32(temporary + 4u, second);
    draft_call_adapter(0x80031CE8u, a0 + 36u, a0 + 20u, temporary, a0 + 324u);
    draft_call_adapter(0x800551CCu, (uint32)(r_s16(a0 + 360u) - r_s16(a0 + 182u)), a0 + 340u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80031A54u, a0 + 340u, a0 + 340u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80057A90(uint32 a0, uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80057A90u, "1.EXE");
    // TODO Omitted pseudocode inputs pass through to the unresolved callee contract
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80057AB0u, a0, a1, a2, a3)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003B170(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8003B170u, "1.EXE");
    if (r_s16(0x800A6DDCu))
    {
        w_u32(0x800A8398u, 4u);
        w_u32(0x800A98F4u, 4u);
    }
    else
    {
        value = sub_800389DC();
        // TODO Existing menu selection callee ABI boundary
        value = (uint32)draft_call_adapter(0x80038CDCu, (uint32)(sint16)value);
        w_u32(0x800A8398u, value);
    }
    if ((sint16)sub_80037BB8() != -1)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    w_u32(0x800A8B30u, 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800290B8(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    sint32 index;
    FUNCTION_MARKER(0x800290B8u, "1.EXE");
    value = r_u8(a0 + 64u);
    if (value)
        return draft_scratch_result(native_stack_mark, (uint64)(value));
    if (!r_u8(a0 + 66u))
        w_u32(a0, 0x80027024u);
    index = r_s16(a0 + 72u);
    w_u8(a0 + 64u, 1u);
    if (index == -1)
        index = 0;
    return draft_scratch_result(native_stack_mark, (uint64)(sub_80030F08((uint32)index, (uint32)r_s16(a0 + 68u), 0u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80063600(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary, index, value = 0u;
    FUNCTION_MARKER(0x80063600u, "1.EXE");
    // TODO Reusable addressable output vectors and existing callee ABI boundary
    temporary = draft_scratch_adapter(16u);
    for (index = 4u; index > 0u; --index)
    {
        uint32 point = a0 + (index - 1u) * 12u;
        value = 0u - (uint32)draft_call_adapter(0x8002E310u, point, temporary, temporary + 8u);
        w_u32(point + 4u, value);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006E520(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 kind, value, child;
    FUNCTION_MARKER(0x8006E520u, "1.EXE");
    kind = sub_8003CAFC();
    value = kind;
    if (r_u8(a0 + 13u) == kind)
        return draft_scratch_result(native_stack_mark, (uint64)(value));
    child = r_u32(a0 + 16u);
    if (child)
        sub_8002289C(child);
    value = 2u;
    if (kind == 1u)
    {
        value = sub_8006E5DC(a0);
        w_u32(a0 + 16u, value);
    }
    else if (kind == 2u)
    {
        value = (uint32)draft_call_adapter(0x8006E604u, a0);
        w_u32(a0 + 16u, value);
    }
    else
        w_u32(a0 + 16u, 0u);
    w_u8(a0 + 13u, (uint8)kind);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006E5DC(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object;
    FUNCTION_MARKER(0x8006E5DCu, "1.EXE");
    object = sub_8006E62C(a0);
    w_u8(object + 35u, 2u);
    return draft_scratch_result(native_stack_mark, (uint64)(object));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80047124(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x80047124u, "1.EXE");
    if (!sub_80045E18(a0, a0 + 72u))
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8004557Cu, a0, a0 + 72u, 0x80046E9Cu, 1u, a0 + 56u)));
    value = r_u8(a0 + 14u) | 2u;
    w_u8(a0 + 14u, (uint8)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8004F2F8(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8004F2F8u, "1.EXE");
    if (!sub_80045AD8(a0, 0x8004EDF0u))
        draft_call_adapter(0x8004D730u, a0);
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8004ED64(a0)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800473C8(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x800473C8u, "1.EXE");
    if (!sub_80045E18(a0, a0 + 72u))
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8004557Cu, a0, a0 + 72u, 0x80047194u, 1u, a0 + 56u)));
    value = r_u8(a0 + 14u) | 2u;
    w_u8(a0 + 14u, (uint8)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006E6AC(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8006E6ACu, "1.EXE");
    value = sub_8006BC98(r_u32(0x800A9A58u), a1);
    return draft_scratch_result(native_stack_mark, (uint64)(value ? value : a0));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006BC98(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary, target, y;
    FUNCTION_MARKER(0x8006BC98u, "1.EXE");
    // TODO Indirect callback and addressable vector output boundaries
    temporary = draft_scratch_adapter(8u);
    target = r_u32(r_u32(a0 + 16u) + 20u);
    draft_call_adapter(target, a0, temporary);
    y = r_u16(temporary + 2u) + 2048u;
    w_u16(temporary + 2u, (uint16)y);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8006BD08u, a0 + 20u, (uint32)r_s16(temporary), (uint32)(sint16)y, (uint32)r_u8(a0 + 13u), a1)));

    draft_scratch_release(native_stack_mark);
}

static uint32 draft11_divide(uint32 value, uint32 divisor)
{
    if (divisor == 0u || (divisor == 0xFFFFFFFFu && value == 0x80000000u))
        abort();
    return (uint32)((sint32)value / (sint32)divisor);
}

uint32 sub_800296B0(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 divisor, x, z;
    FUNCTION_MARKER(0x800296B0u, "1.EXE");
    divisor = r_u32(0x800A56C0u);
    x = draft11_divide(r_u32(a0 + 476u) * 136u, divisor);
    z = draft11_divide(r_u32(a0 + 480u) * 136u, divisor);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80069BE0u, (uint32)((sint32)x >> 8), (uint32)((sint32)z >> 8)) << 8));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80066090(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80066090u, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800660D0u, a0, a1, a2, 0u)));

    draft_scratch_release(native_stack_mark);
}
