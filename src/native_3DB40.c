#include "draft_signatures.h"

uint32 sub_8003DB40(uint32 object, uint32 mode)
{
    uint32 mark = draft_scratch_mark();
    uint32 locals = draft_scratch_adapter(20u);
    uint32 orientation = locals, displacement = locals + 8u;
    uint32 target, child, model, flags, result;
    FUNCTION_MARKER(0x8003DB40u, "1.EXE");
    target = r_u32(r_u32(object + 16u) + 20u);
    draft_call_adapter(target, object, orientation);
    child = (uint32)draft_call_adapter(0x800226E4u, 60u);
    draft_call_adapter(0x80054D38u, (uint32)(sint32)(sint16)r_u16(orientation), (uint32)(sint32)(sint16)r_u16(orientation + 2u), (uint32)(sint32)(sint16)r_u16(orientation + 4u), child + 36u);
    w_u8(child + 34u, 8u);
    model = r_u32(0x800A62ECu);
    w_u32(child + 20u, r_u32(object + 20u));
    w_u32(child + 24u, r_u32(object + 24u));
    w_u32(child + 28u, r_u32(object + 28u));
    flags = r_u8(child + 14u);
    model = r_u16(model + 114u);
    w_u16(child + 58u, mode);
    w_u32(child + 16u, object);
    w_u16(child + 10u, 0u);
    w_u16(child + 56u, 0u);
    w_u8(child + 14u, flags | 2u);
    w_u32(child, 0x8003DC50u);
    w_u16(child + 8u, 200u);
    w_u16(child + 32u, model);
    w_u32(displacement, 0u);
    w_u32(displacement + 4u, 0u - 125u);
    w_u32(displacement + 8u, 0u);
    sub_80031E30(child + 36u, child + 20u, displacement);
    result = (uint32)draft_call_adapter(0x80035A08u, 41u, 1024u, 255u, 0u, 0u);
    return (uint32)draft_scratch_result(mark, result);
}

uint32 sub_8003DC50(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    sint32 state = (sint16)r_u16(object + 56u);
    uint32 locals, previous, displacement, movement, result, i;
    FUNCTION_MARKER(0x8003DC50u, "1.EXE");
    if (state != 0)
        return (uint32)draft_scratch_result(mark, sub_8002A5DC(object, (uint32)state));
    locals = draft_scratch_adapter(24u);
    previous = locals;
    displacement = locals + 12u;
    for (i = 0u; i < 3u; ++i)
        w_u32(previous + 4u * i, r_u32(object + 20u + 4u * i));
    movement = (0u - r_u32(0x800A9010u)) * (uint32)(sint32)(sint16)r_u16(object + 8u);
    w_u32(displacement, 0u);
    w_u32(displacement + 4u, 0u);
    w_u32(displacement + 8u, movement);
    sub_80031E30(object + 36u, object + 20u, displacement);
    w_u16(object + 10u, r_u16(object + 10u) - r_u16(displacement + 8u));
    draft_call_adapter(0x80040B54u, previous);
    for (i = 0u; i < 3u; ++i)
        w_u32(displacement + 4u * i, r_u32(previous + 4u * i));
    if ((sint16)r_u16(object + 10u) >= 20000)
        return (uint32)draft_scratch_result(mark, sub_8002289C(object));
    if (sub_8002F3FC(displacement, object + 20u) << 16u)
    {
        if ((sub_80069A50() & 63u) == 0u)
        {
            w_u16(object + 56u, 7u);
            return (uint32)draft_scratch_result(mark, 7u);
        }
        draft_call_adapter(0x80060D20u, object, displacement);
        sub_8002A8F0(object);
    }
    else if (sub_80030678(displacement, object + 20u) << 16u)
    {
        sub_8002A8F0(object);
    }
    result = sub_80029970(object, 136u, 6u, 1u, previous);
    return (uint32)draft_scratch_result(mark, result);
}
