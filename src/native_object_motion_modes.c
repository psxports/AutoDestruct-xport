#include "native_call_dispatch.h"

uint32 sub_80052C00(uint32 object, uint32 mode)
{
    uint32 mark = draft_scratch_mark();
    uint32 angles = draft_scratch_adapter(8u);
    uint32 state = r_u32(object + 60u);
    FUNCTION_MARKER(0x80052C00u, "1.EXE");
    sub_8005536C(object + 36u, mode, angles);
    w_u16(state + 20u, r_u16(angles + 2u));
    w_u16(state + 22u, r_u16(angles));
    uint32 result = r_u16(angles + 4u);
    w_u16(state + 24u, result);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_80052C58(uint32 object)
{
    FUNCTION_MARKER(0x80052C58u, "1.EXE");
    return sub_80052C00(object, 17u);
}

uint32 sub_80052C78(uint32 object)
{
    FUNCTION_MARKER(0x80052C78u, "1.EXE");
    return sub_80052C00(object, 12u);
}

uint32 sub_80052988(uint32 object)
{
    FUNCTION_MARKER(0x80052988u, "1.EXE");
    uint32 previous = r_u32(object + 60u);
    if (previous)
        sub_80064D60(previous);
    uint32 state = (uint32)draft_call_adapter(0x80064B04u, 28u);
    if (!state)
        return 1u;
    uint32 kind = r_u16(object + 56u);
    w_u32(object + 60u, state);
    if (kind == 1u)
    {
        uint32 model = r_u16(r_u32(0x800A62ECu) + 434u);
        w_u8(object + 14u, r_u8(object + 14u) | 2u);
        w_u16(object + 56u, 13u);
        w_u16(object + 32u, model);
        sub_8005792C(object);
    }
    else if (kind == 0u)
    {
        w_u16(0x800A9030u, r_u8(0x800A7E83u));
        draft_call_adapter(0x8005E2BCu, 2u);
        w_u8(object + 14u, r_u8(object + 14u) | 0x82u);
    }
    else if (kind == 2u)
    {
        draft_call_adapter(0x8004D8B4u, object);
        w_u8(object + 14u, r_u8(object + 14u) & 127u);
    }
    else
        w_u8(object + 90u, 7u);
    w_u32(object + 16u, 0x80090AB8u);
    w_u32(object, 0x80052284u);
    w_u16(state + 16u, 0u);
    w_u16(state + 18u, 0u);
    w_u16(state + 12u, (sub_80069A50() & 127u) - 64u);
    uint32 random = sub_80069A50();
    uint32 time = r_u32(0x800A63D8u);
    w_u16(state + 14u, (random & 127u) - 64u);
    w_u16(state + 26u, 0u);
    w_u32(state + 4u, 0u);
    w_u32(state + 8u, 0u);
    uint32 acceleration = (uint32)((sint32)time >> 8) * 10240u;
    w_u32(state, 0u - ((uint32)((sint32)acceleration >> 16) << 16));
    return sub_80052C58(object);
}

uint32 sub_80052B28(uint32 object, uint32 unused, uint32 angular_y, uint32 angular_z, uint32 angular_extra)
{
    FUNCTION_MARKER(0x80052B28u, "1.EXE");
    sub_8005792C(object);
    uint32 previous = r_u32(object + 60u);
    if (previous)
        sub_80064D60(previous);
    uint32 state = (uint32)draft_call_adapter(0x80064B04u, 28u);
    if (!state)
        return 13u;
    w_u16(object + 56u, 13u);
    w_u32(object + 60u, state);
    w_u16(state + 14u, angular_y);
    w_u16(state + 12u, 0u);
    w_u16(state + 16u, angular_z);
    w_u16(state + 18u, angular_extra);
    w_u32(object, 0x80052284u);
    w_u32(object + 16u, 0x80090AB8u);
    w_u16(state + 26u, 0u);
    w_u32(state, 0u);
    w_u32(state + 4u, 0u);
    w_u32(state + 8u, 0u);
    return 0x80090AB8u;
}
