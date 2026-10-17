#include "native_call_dispatch.h"

static sint32 motion_abs_half(uint32 address)
{
    sint32 value = (sint16)r_u16(address);
    return value < 0 ? -value : value;
}

static uint32 motion_step(uint32 angular, uint32 tick)
{
    uint32 product = ((uint32)(sint32)(sint16)angular << 8) * tick;
    return (uint32)((sint32)product >> 16);
}

uint32 sub_80052284(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 local = draft_scratch_adapter(104u), corners = local + 16u, contact_out = local + 80u;
    FUNCTION_MARKER(0x80052284u, "1.EXE");
    w_u16(contact_out, 0u);
    for (uint32 i = 0; i < 3u; ++i)
        w_u32(local + 4u * i, r_u32(object + 20u + 4u * i));
    uint32 state = r_u32(object + 60u);
    uint32 tick = (uint32)((sint32)r_u32(0x800A63D8u) >> 8);
    w_u16(state + 20u, r_u16(state + 20u) + motion_step(r_u16(state + 12u), tick));
    state = r_u32(object + 60u);
    w_u16(state + 24u, r_u16(state + 24u) + motion_step(r_u16(state + 14u), tick));
    state = r_u32(object + 60u);
    if (r_u16(state + 26u))
    {
        if (motion_abs_half(state + 14u) < 8)
            draft_call_adapter(0x800514A0u, state + 24u, object);
        state = r_u32(object + 60u);
        if (motion_abs_half(state + 12u) < 8)
            draft_call_adapter(0x800518C4u, state + 20u);
    }
    draft_call_adapter(0x80051BA4u, object, r_u32(object + 60u));
    uint32 model = r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
    sub_80029DDC(object, corners, model);
    sub_8002A300(corners);
    tick = (uint32)((sint32)r_u32(0x800A63D8u) >> 8);
    state = r_u32(object + 60u);
    w_u32(state, r_u32(state) + 781u * tick);
    state = r_u32(object + 60u);
    w_u32(object + 24u, r_u32(object + 24u) + (uint32)(sint32)(sint16)r_u16(state + 2u));
    uint32 contact = sub_80051328(object, corners, contact_out);
    if ((sint16)contact != 0)
    {
        if ((sint16)contact < 0)
        {
            contact = (uint32) - (sint32)(sint16)contact;
            tick = (uint32)((sint32)r_u32(0x800A63D8u) >> 8);
            w_u32(r_u32(object + 60u), 390u * tick);
        }
        state = r_u32(object + 60u);
        if ((sint32)r_u32(state) > 800000)
        {
            uint32 corner = corners + (uint32)((sint32)(sint16)contact * 8 - 8);
            for (uint32 i = 0; i < 3u; ++i)
                w_u32(local + 88u + 4u * i, r_u32(object + 20u + 4u * i));
            for (uint32 i = 0; i < 3u; ++i)
                w_u32(local + 88u + 4u * i, r_u32(local + 88u + 4u * i) + (uint32)(sint32)(sint16)r_u16(corner + 2u * i));
        }
        w_u32(r_u32(object + 60u), 0u);
        if (!r_u16(r_u32(object + 60u) + 26u))
            draft_call_adapter(0x80035A08u, 8u, 500u, 128u, 0u, 0u);
        state = r_u32(object + 60u);
        if ((sint16)contact != (sint16)r_u16(state + 26u))
        {
            if (motion_abs_half(state + 12u) >= 9 && motion_abs_half(state + 14u) >= 9)
                draft_call_adapter(0x80035A08u, 8u, 1024u, 128u, 0u, 0u);
            uint32 corner = local + 8u + (uint32)((sint32)(sint16)contact * 8);
            w_u32(r_u32(object + 60u) + 4u, (uint32)(sint32)(sint16)r_u16(corner));
            w_u32(r_u32(object + 60u) + 8u, (uint32)(sint32)(sint16)r_u16(corner + 4u));
        }
        w_u16(r_u32(object + 60u) + 26u, contact);
    }
    tick = (uint32)((sint32)r_u32(0x800A63D8u) >> 8);
    state = r_u32(object + 60u);
    uint32 x_step = motion_step(r_u16(state + 16u), tick);
    uint32 z_speed = r_u16(state + 18u);
    w_u32(object + 20u, r_u32(object + 20u) + x_step);
    w_u32(object + 28u, r_u32(object + 28u) + motion_step(z_speed, tick));
    state = r_u32(object + 60u);
    if (r_u16(state + 26u))
    {
        for (uint32 offset = 12u; offset <= 18u; offset += 2u)
        {
            state = r_u32(object + 60u);
            sint32 speed = (sint16)r_u16(state + offset);
            w_u16(state + offset, (uint32)((3600 * speed + 2048) >> 12));
        }
        state = r_u32(object + 60u);
        uint32 corner = corners + (uint32)(((sint32)(sint16)r_u16(state + 26u) - 1) * 8);
        w_u32(object + 20u, r_u32(object + 20u) + r_u32(state + 4u) - (uint32)(sint32)(sint16)r_u16(corner));
        state = r_u32(object + 60u);
        corner = corners + (uint32)(((sint32)(sint16)r_u16(state + 26u) - 1) * 8);
        w_u32(object + 28u, r_u32(object + 28u) + r_u32(state + 8u) - (uint32)(sint32)(sint16)r_u16(corner + 4u));
        state = r_u32(object + 60u);
        corner = corners + (uint32)(((sint32)(sint16)r_u16(state + 26u) - 1) * 8);
        w_u32(state + 4u, (uint32)(sint32)(sint16)r_u16(corner));
        state = r_u32(object + 60u);
        corner = corners + (uint32)(((sint32)(sint16)r_u16(state + 26u) - 1) * 8);
        w_u32(state + 8u, (uint32)(sint32)(sint16)r_u16(corner + 4u));
    }
    uint32 kind = r_u16(object + 56u);
    uint32 category = kind >= 11u || kind == 1u ? 1u : (uint32)(sint32)(sint16)kind;
    model = r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
    sub_80029970(object, (uint32)(sint32)(sint16)r_u16(r_u32(0x800A90ACu) + 40u * model + 32u), category, 1u, local);
    sub_80029D44(corners);
    draft_call_adapter(0x80051A8Cu, r_u32(object + 60u), object, corners, local, 1u);
    state = r_u32(object + 60u);
    if (motion_abs_half(state + 12u) < 5 && motion_abs_half(state + 14u) < 5 && motion_abs_half(state + 16u) < 5 && motion_abs_half(state + 18u) < 5 && (sint16)r_u16(state + 26u) > 0)
    {
        w_u32(object, 0x80051D54u);
        w_u16(state + 16u, 0u);
        w_u16(r_u32(object + 60u) + 18u, 0u);
        w_u16(r_u32(object + 60u) + 12u, 0u);
        w_u16(r_u32(object + 60u) + 14u, 0u);
        if (r_u16(object + 56u) == 2u)
        {
            sub_80030F08((uint32)(sint32)(sint16)r_u16(object + 74u), (uint32)(sint32)(sint16)r_u16(object + 68u), 1u);
            w_u8(object + 90u, 7u);
        }
    }
    uint32 result = r_u16(object + 56u);
    if (!result)
        result = sub_80026BC4(r_u32(0x800A7BACu));
    draft_scratch_release(mark);
    return result;
}
