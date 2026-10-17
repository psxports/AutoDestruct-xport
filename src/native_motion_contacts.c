#include "native_call_dispatch.h"

uint32 sub_8002A364(uint32 object)
{
    sint32 value = (sint16)r_u16(object + 44u);
    FUNCTION_MARKER(0x8002A364u, "1.EXE");
    if (value > 3968)
        return 1u;
    return value < -3968 ? 0xFFFFFFFFu : 0u;
}

uint32 sub_80051BA4(uint32 object, uint32 motion)
{
    uint32 mark = draft_scratch_mark(), scratch = draft_scratch_adapter(48u);
    uint32 angle;
    sint32 normal_y;
    FUNCTION_MARKER(0x80051BA4u, "1.EXE");
    draft_call_adapter(0x80054D38u, (uint32)(sint32)(sint16)r_u16(motion + 20u), (uint32)(sint32)(sint16)r_u16(motion + 22u), (uint32)(sint32)(sint16)r_u16(motion + 24u), object + 36u);
    if (draft_call_adapter(0x8002E310u, object + 20u, scratch + 32u, scratch + 40u))
    {
        angle = 0u - (sub_80055A9C((uint32)(sint32)(sint16)r_u16(scratch + 36u), (uint32)(sint32)(sint16)r_u16(scratch + 34u)) + 2048u);
        draft_call_adapter(0x80054D38u, angle, 0u, sub_80055A9C((uint32)(sint32)(sint16)r_u16(scratch + 32u), (uint32)(sint32)(sint16)r_u16(scratch + 34u)) + 2048u, scratch);
    }
    else
    {
        sub_80055A70(scratch);
    }
    sub_80031B20(scratch, object + 36u, object + 36u);
    normal_y = (sint16)r_u16(scratch + 34u);
    if (normal_y < 0)
        normal_y = -normal_y;
    draft_scratch_release(mark);
    return normal_y < 4000;
}

uint32 sub_80051A8C(uint32 motion, uint32 object, uint32 offsets, uint32 previous, uint32 emit_effect)
{
    uint32 mark = draft_scratch_mark(), scratch = draft_scratch_adapter(112u);
    uint32 contacts, result, speed, last;
    FUNCTION_MARKER(0x80051A8Cu, "1.EXE");
    w_u16(scratch + 96u, 0u);
    w_u16(scratch + 98u, 0u);
    contacts = sub_80030040(scratch, previous, object + 20u, offsets);
    result = contacts << 16u;
    if (result != 0u)
    {
        speed = (uint32)draft_call_adapter(0x80069BE0u, (uint32)(sint32)(sint16)r_u16(motion + 16u), (uint32)(sint32)(sint16)r_u16(motion + 18u));
        if (emit_effect && speed - 6u < 14u)
            sub_80023228(object + 20u, scratch, offsets, 1u, speed << 16u);
        last = scratch + 12u * ((uint32)(sint32)(sint16)contacts - 1u);
        w_u32(scratch + 104u, (uint32)r_u16(motion + 16u) << 16u);
        w_u32(scratch + 108u, (uint32)r_u16(motion + 18u) << 16u);
        sub_80023918(r_u32(last), r_u32(last + 8u), scratch + 104u, scratch + 108u);
        result = (uint32)(sint32)(sint16)r_u16(scratch + 106u);
        // The original stores the same resulting component in both fields
        w_u16(motion + 16u, result);
        w_u16(motion + 18u, result);
    }
    draft_scratch_release(mark);
    return result;
}

uint32 sub_80051C70(uint32 object)
{
    uint32 type;
    FUNCTION_MARKER(0x80051C70u, "1.EXE");
    w_u8(object + 14u, 1u);
    sub_80064D60(r_u32(object + 60u));
    type = r_u16(object + 56u);
    if (type == 2u)
    {
        draft_call_adapter(0x80054934u, object, 2u);
        w_u32(object, 0x80045510u);
        return 0x80045510u;
    }
    if (type == 9u)
    {
        draft_call_adapter(0x80054934u, object, 3u);
        return sub_8002289C(object);
    }
    if (type == 0u)
    {
        w_u32(object + 60u, 200u);
        sub_80026F98(object);
        return (uint32)draft_call_adapter(0x80054934u, object, 0u);
    }
    sub_80056364(object);
    draft_call_adapter(0x80054934u, object, 2u);
    w_u32(object, 0x80029968u);
    return 0x80029968u;
}

uint32 sub_80051D54(uint32 object)
{
    uint32 mark = draft_scratch_mark(), scratch, points, tag, motion, last;
    uint32 first_hit, second_hit, tilted, type, model, mode, result;
    sint32 delta;
    FUNCTION_MARKER(0x80051D54u, "1.EXE");
    type = r_u16(object + 56u);
    if (r_u8(object + 12u) < 2u || (type == 11u && (sint32)r_u32(object + 80u) <= 0 && r_u8(object + 90u) != 7u))
    {
        sub_80064D60(r_u32(object + 60u));
        w_u32(object + 60u, 0u);
        result = sub_80056364(object);
        draft_scratch_release(mark);
        return result;
    }
    if (type == 11u)
        w_u32(object + 80u, r_u32(object + 80u) - r_u32(0x800A9010u));
    scratch = draft_scratch_adapter(88u);
    points = scratch + 16u;
    tag = scratch + 80u;
    for (uint32 index = 0u; index < 3u; ++index)
        w_u32(scratch + 4u * index, r_u32(object + 20u + 4u * index));
    first_hit = sub_800514A0(r_u32(object + 60u) + 24u, object);
    second_hit = sub_800518C4(r_u32(object + 60u) + 20u);
    tilted = sub_80051BA4(object, r_u32(object + 60u));
    model = r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
    sub_80029DDC(object, points, model);
    sub_8002A300(points);
    motion = r_u32(object + 60u);
    w_u32(motion, r_u32(motion) + 781u * (uint32)((sint32)r_u32(0x800A63D8u) >> 8));
    w_u32(object + 24u, r_u32(object + 24u) + (uint32)(sint32)(sint16)r_u16(motion + 2u));
    if ((sub_80051328(object, points, tag) << 16u) != 0u)
        w_u32(r_u32(object + 60u), 0u);
    motion = r_u32(object + 60u);
    last = points + 8u * ((uint32)(sint32)(sint16)r_u16(motion + 26u) - 1u);
    w_u16(motion + 16u, r_u16(motion + 4u) - r_u16(last));
    motion = r_u32(object + 60u);
    last = points + 8u * ((uint32)(sint32)(sint16)r_u16(motion + 26u) - 1u);
    w_u16(motion + 18u, r_u16(motion + 8u) - r_u16(last + 4u));
    motion = r_u32(object + 60u);
    last = points + 8u * ((uint32)(sint32)(sint16)r_u16(motion + 26u) - 1u);
    w_u32(motion + 4u, (uint32)(sint32)(sint16)r_u16(last));
    motion = r_u32(object + 60u);
    last = points + 8u * ((uint32)(sint32)(sint16)r_u16(motion + 26u) - 1u);
    w_u32(motion + 8u, (uint32)(sint32)(sint16)r_u16(last + 4u));
    if (!tilted)
    {
        w_u32(object + 20u, r_u32(object + 20u) + (uint32)(sint32)(sint16)r_u16(r_u32(object + 60u) + 16u));
        w_u32(object + 28u, r_u32(object + 28u) + (uint32)(sint32)(sint16)r_u16(r_u32(object + 60u) + 18u));
    }
    if ((first_hit << 16u) != 0u || (second_hit << 16u) != 0u)
        goto finish_motion;
    delta = (sint32)(r_u32(object + 24u) - r_u32(scratch + 4u));
    if ((delta >= 0 && delta >= 4) || (delta < 0 && (sint32)(0u - (uint32)delta) >= 4))
        goto finish_motion;
    if ((sint16)r_u16(tag) == 6)
    {
        result = sub_80051C70(object);
        draft_scratch_release(mark);
        return result;
    }
    type = r_u16(object + 56u);
    if (type != 11u)
    {
        w_u32(object + 80u, (sub_80069A50() % 30u + 30u) * r_u32(0x800A56C0u));
        type = r_u16(object + 56u);
    }
    if (type == 0u)
    {
        sub_80064D60(r_u32(object + 60u));
        w_u32(object + 60u, 200u);
        result = sub_80028F78(object, 1u);
        draft_scratch_release(mark);
        return result;
    }
    if (type == 2u || type == 9u)
    {
        w_u8(object + 90u, 7u);
        w_u16(object + 78u, r_u16(r_u32(object + 60u) + 22u) - 2048u);
    }
    if (sub_8002A364(object) == 1u)
    {
        sub_80064D60(r_u32(object + 60u));
        sub_8005780C(object, 1u, (uint32)(sint32)(sint16)(r_u16(r_u32(object + 60u) + 22u) - 2048u));
        w_u32(object + 60u, 0u);
        if (type == 2u || type == 9u)
            w_u8(object + 90u, 7u);
    }
    else
    {
        w_u16(object + 56u, 11u);
    }

finish_motion:
    type = r_u16(object + 56u);
    mode = type >= 11u || type == 1u ? 1u : (uint32)(sint32)(sint16)type;
    model = r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
    sub_80029970(object, (uint32)(sint32)(sint16)r_u16(r_u32(0x800A90ACu) + 40u * model + 32u), mode, 1u, scratch);
    sub_80029D44(points);
    sub_80051A8C(r_u32(object + 60u), object, points, scratch, 0u);
    result = r_u16(object + 56u);
    if (result == 0u)
        result = sub_80026BC4(r_u32(0x800A7BACu));
    draft_scratch_release(mark);
    return result;
}
