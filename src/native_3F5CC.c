#include "native_call_dispatch.h"

void sub_8003F5CC(uint32 position)
{
    uint32 remaining = r_u32(0x800A9010u);
    FUNCTION_MARKER(0x8003F5CCu, "1.EXE");
    while ((sint32)remaining > 0)
    {
        uint32 effect = sub_800227C4(40u);
        w_u8(effect + 34u, 11u);
        w_u32(effect, 0x8003F6D0u);
        w_u8(effect + 14u, r_u8(effect + 14u) | 2u);
        w_u16(effect + 32u, r_u16(r_u32(0x800A62ECu) + 220u));
        w_u32(effect + 20u, r_u32(position));
        --remaining;
        w_u32(effect + 24u, r_u32(position + 4u));
        w_u16(effect + 36u, 100u);
        w_u16(effect + 38u, 0u);
        w_u32(effect + 28u, r_u32(position + 8u));
        w_u16(effect + 8u, ((sub_80069A50() & 31u) - 15u) >> 1);
        w_u16(effect + 10u, 0u - (sub_80069A50() & 7u));
        w_u16(effect + 16u, ((sub_80069A50() & 31u) - 15u) >> 1);
        w_u16(effect + 18u, (sub_80069A50() & 255u) - 127u);
        w_u8(effect + 13u, (sub_80069A50() & 3u) + 2u);
    }
}

uint32 sub_8003F6D0(uint32 object)
{
    uint32 tick = r_u32(0x800A9010u);
    uint32 x = tick * (uint32)(sint32)(sint16)r_u16(object + 8u);
    uint32 y = tick * (uint32)(sint32)(sint16)r_u16(object + 10u);
    uint32 z = tick * (uint32)(sint32)(sint16)r_u16(object + 16u);
    uint32 rotation = tick * (uint32)(sint32)(sint16)r_u16(object + 18u);
    uint32 shrink = tick * (uint32)(sint32)(sint8)r_u8(object + 13u);
    uint32 size, result;
    FUNCTION_MARKER(0x8003F6D0u, "1.EXE");
    w_u32(object + 20u, r_u32(object + 20u) + x);
    w_u32(object + 24u, r_u32(object + 24u) + y);
    w_u16(object + 38u, r_u16(object + 38u) + rotation);
    size = r_u16(object + 36u) - shrink;
    w_u32(object + 28u, r_u32(object + 28u) + z);
    w_u16(object + 36u, size);
    result = (sint16)size < 10;
    if (result != 0u)
        return sub_8002289C(object);
    return result;
}
