#include "draft_signatures.h"

uint32 sub_8005F7F0(uint32 object)
{
    uint32 x, y, z, random, effect, result, count = 9u;
    FUNCTION_MARKER(0x8005F7F0u, "1.EXE");
    random = sub_80069A50();
    x = r_u32(object + 20u) - 255u + (random & 511u);
    random = sub_80069A50();
    y = r_u32(object + 24u) - (random & 511u);
    random = sub_80069A50();
    z = r_u32(object + 28u) - 255u + (random & 511u);
    do
    {
        effect = sub_800227C4(40u);
        w_u8(effect + 34u, 8u);
        w_u16(effect + 36u, 288u);
        w_u16(effect + 38u, 0u);
        w_u8(effect + 14u, r_u8(effect + 14u) | 2u);
        w_u32(effect, 0x8005F1E0u);
        w_u16(effect + 32u, r_u16(r_u32(0x800A62ECu) + 62u));
        w_u32(effect + 20u, x);
        w_u32(effect + 24u, y);
        w_u32(effect + 28u, z);
        w_u8(effect + 13u, 32u);
        w_u16(effect + 8u, (sub_80069A50() & 31u) + 0xFFF0u);
        w_u16(effect + 10u, 0u - (sub_80069A50() & 15u));
        w_u16(effect + 16u, (sub_80069A50() & 31u) + 0xFFF0u);
        result = sub_80069A50() & 255u;
        w_u16(effect + 18u, result);
    } while (--count != 0u);
    return result;
}

uint32 sub_8005EFBC(uint32 object)
{
    uint32 tick = r_u32(0x800A9010u);
    uint32 vx, vy, vz, size, rotation;
    FUNCTION_MARKER(0x8005EFBCu, "1.EXE");
    vx = (uint32)(sint32)(sint16)r_u16(object + 8u) * tick;
    vy = (uint32)(sint32)(sint16)r_u16(object + 10u) * tick;
    vz = (uint32)(sint32)(sint16)r_u16(object + 16u) * tick;
    rotation = tick * (uint32)(sint32)(sint16)r_u16(object + 18u);
    w_u8(object + 13u, r_u8(object + 13u) - tick);
    size = r_u16(object + 36u) - (tick << 1u);
    w_u16(object + 36u, size);
    w_u16(object + 38u, r_u16(object + 38u) + rotation);
    w_u32(object + 20u, r_u32(object + 20u) + vx);
    w_u32(object + 24u, r_u32(object + 24u) + vy);
    w_u32(object + 28u, r_u32(object + 28u) + vz);
    if ((sint8)r_u8(object + 13u) < 0 || (sint32)(size << 16u) < 0)
    {
        w_u16(object + 36u, 0u);
        return sub_8002289C(object);
    }
    return size << 16u;
}

uint32 sub_8005F774(uint32 object)
{
    uint32 tick = r_u32(0x800A9010u), result;
    FUNCTION_MARKER(0x8005F774u, "1.EXE");
    w_u16(object + 10u, r_u16(object + 10u) - tick);
    w_u16(object + 8u, r_u16(object + 8u) - tick);
    if ((sint16)r_u16(object + 10u) < 0)
    {
        draft_call_adapter(0x8005F7F0u, object);
        w_u16(object + 10u, sub_80069A50() & 15u);
    }
    result = (uint32)(sint32)(sint16)r_u16(object + 8u);
    return (sint32)result < 0 ? sub_8002289C(object) : result;
}

uint32 sub_8005F69C(uint32 object)
{
    uint32 effect;
    FUNCTION_MARKER(0x8005F69Cu, "1.EXE");
    w_u8(0x800A8FB8u, 1u);
    w_u8(0x800A8FB7u, 20u);
    w_u8(0x800A8FB4u, r_u8(0x800A8FB4u) | 2u);
    w_u32(0x800A8FA0u, r_u32(object + 20u) - r_u32(0x800A7EE4u));
    w_u32(0x800A8FA4u, r_u32(object + 24u));
    w_u32(0x800A8FA8u, r_u32(object + 28u) - r_u32(0x800A7EECu));
    effect = sub_800227C4(40u);
    w_u32(effect + 20u, r_u32(object + 20u));
    w_u32(effect + 24u, r_u32(object + 24u));
    w_u32(effect + 28u, r_u32(object + 28u));
    w_u32(effect, 0x8005F774u);
    w_u16(effect + 8u, 48u);
    w_u16(effect + 10u, 0xFFFFu);
    return effect;
}

uint32 sub_8005EEC0(uint32 object)
{
    uint32 count = 15u, effect, result;
    FUNCTION_MARKER(0x8005EEC0u, "1.EXE");
    do
    {
        effect = sub_800227C4(40u);
        w_u8(effect + 34u, 8u);
        w_u16(effect + 36u, 50u);
        w_u16(effect + 38u, 0u);
        w_u8(effect + 14u, r_u8(effect + 14u) | 2u);
        w_u16(effect + 32u, r_u16(r_u32(0x800A62ECu) + 88u));
        w_u32(effect + 20u, r_u32(object + 20u));
        w_u32(effect + 24u, r_u32(object + 24u));
        w_u32(effect + 28u, r_u32(object + 28u));
        w_u32(effect, 0x8005EFBCu);
        w_u8(effect + 13u, (sub_80069A50() & 63u) + 6u);
        w_u16(effect + 8u, (sub_80069A50() & 15u) + 0xFFF9u);
        w_u16(effect + 10u, (sub_80069A50() & 15u) + 0xFFF9u);
        w_u16(effect + 16u, (sub_80069A50() & 15u) + 0xFFF9u);
        result = sub_80069A50() & 255u;
        w_u16(effect + 18u, result);
    } while (--count != 0u);
    return result;
}

uint32 sub_80060320(uint32 object)
{
    uint32 mark = draft_scratch_mark(), temporary = draft_scratch_adapter(16u);
    uint32 result, ground, effect;
    FUNCTION_MARKER(0x80060320u, "1.EXE");
    result = (uint32)draft_call_adapter(0x8002E310u, object + 20u, temporary, temporary + 8u);
    ground = 0u - result;
    if (ground != 0u)
    {
        result = ground - 300u;
        if ((sint32)ground >= (sint32)r_u32(object + 24u))
        {
            result = (sint32)result < (sint32)r_u32(object + 24u);
            if (result != 0u)
            {
                effect = sub_800227C4(40u);
                result = effect;
                w_u16(effect + 36u, 288u);
                w_u16(effect + 38u, 0u);
                w_u32(effect + 24u, ground - 288u);
                w_u32(effect + 20u, r_u32(object + 20u));
                w_u32(effect + 28u, r_u32(object + 28u));
                w_u8(effect + 34u, 11u);
                w_u8(effect + 14u, r_u8(effect + 14u) | 2u);
                w_u32(effect, 0x80060404u);
                w_u16(effect + 8u, 0x2000u);
                w_u8(effect + 13u, 0u);
                w_u16(effect + 18u, 0xFFFFu);
                w_u16(effect + 32u, r_u16(r_u32(0x800A62ECu) + 62u));
                w_u8(effect + 14u, r_u8(effect + 14u) | 0x40u);
            }
        }
    }
    return draft_scratch_result(mark, result);
}
