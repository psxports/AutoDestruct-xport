#include "draft_signatures.h"
#include "draft_adapters.h"

uint32 sub_80060738(uint32 object)
{
    uint32 tick = r_u32(0x800A9010u);
    sint32 movement = (sint32)(tick * (uint32)(sint32)(sint16)r_u16(object + 8u));
    uint32 rotation = tick * (uint32)(sint32)(sint16)r_u16(object + 16u);
    uint32 result;
    FUNCTION_MARKER(0x80060738u, "1.EXE");
    w_u16(object + 8u, r_u16(object + 8u) + (tick << 1));
    w_u32(object + 24u, r_u32(object + 24u) - (uint32)(movement / 3));
    w_u16(object + 38u, r_u16(object + 38u) + rotation);
    result = ((sint32)(sint16)r_u16(object + 10u) >> 1)
        < (sint32)(sint16)r_u16(object + 8u);
    if (result != 0u) {
        w_u32(object, 0x8006080Cu);
        w_u16(object + 32u, r_u16(r_u32(0x800A62ECu) + 78u));
        result = (sub_80069A50() & 15u) + 32u;
        w_u16(object + 8u, result);
    }
    return result;
}

uint32 sub_8006061C(uint32 object, uint32 count)
{
    sint32 remaining = (sint32)count;
    uint32 effect, result;
    FUNCTION_MARKER(0x8006061Cu, "1.EXE");
    while (remaining >= 0) {
        effect = sub_800227C4(40u);
        w_u32(effect, 0x80060738u);
        w_u8(effect + 34u, 11u);
        w_u16(effect + 36u, 288u);
        w_u16(effect + 38u, 0u);
        w_u8(effect + 14u, r_u8(effect + 14u) | 2u);
        w_u16(effect + 32u, r_u16(r_u32(0x800A62ECu) + 62u));
        w_u32(effect + 20u, r_u32(object + 20u) - 127u + (sub_80069A50() & 255u));
        w_u32(effect + 24u, r_u32(object + 24u));
        result = sub_80069A50() & 255u;
        --remaining;
        w_u16(effect + 8u, 0u);
        w_u32(effect + 28u, r_u32(object + 28u) - 127u + result);
        w_u16(effect + 10u, (sub_80069A50() & 127u) + 192u);
        w_u16(effect + 16u, (sub_80069A50() & 127u) - 64u);
    }
    result = r_u16(object + 8u) - (r_u32(0x800A9010u) << 3);
    w_u16(object + 8u, result);
    result <<= 16;
    if ((sint32)result < 0) {
        sub_80036CFC(object + 18u);
        return sub_8002289C(object);
    }
    return result;
}

uint32 sub_80060404(uint32 object)
{
    sint8 elapsed = (sint8)(r_u8(object + 13u) + r_u8(0x800A9010u));
    sint8 steps = (sint8)(elapsed / 5);
    FUNCTION_MARKER(0x80060404u, "1.EXE");
    w_u8(object + 13u, (uint8)elapsed);
    if (steps != 0) w_u8(object + 13u, 0u);
    sub_800369E0(object + 20u, object + 18u, 2048u, 16u);
    return sub_8006061C(object, (uint32)(sint32)steps);
}
