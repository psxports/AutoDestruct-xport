#include "draft_signatures.h"

uint32 sub_80040DAC(uint32 object)
{
    uint32 ticks, rotation, dx, dy, dz, result;
    sint32 width;
    FUNCTION_MARKER(0x80040DACu, "1.EXE");
    ticks = r_u32(0x800A9010u);
    rotation = ticks * (uint32)(sint32)(sint16)r_u16(object + 18u);
    dx = ticks * (uint32)(sint32)(sint16)r_u16(object + 8u);
    dy = ticks * (uint32)(sint32)(sint16)r_u16(object + 10u);
    w_u16(object + 38u, r_u16(object + 38u) + rotation);
    dz = ticks * (uint32)(sint32)(sint16)r_u16(object + 16u);
    result = r_u32(object + 28u);
    w_u32(object + 24u, r_u32(object + 24u) + dy);
    w_u16(object + 36u, r_u16(object + 36u) - (ticks << 2u));
    width = (sint16)r_u16(object + 36u);
    w_u32(object + 20u, r_u32(object + 20u) + dx);
    result += dz;
    w_u32(object + 28u, result);
    if (width < 0)
    {
        w_u16(object + 36u, 0u);
        return sub_8002289C(object);
    }
    return result;
}

uint32 sub_80060F6C(uint32 object, uint32 model, uint32 size)
{
    uint32 effect, flags, z, result;
    FUNCTION_MARKER(0x80060F6Cu, "1.EXE");
    effect = sub_800227C4(40u);
    flags = r_u8(effect + 14u);
    w_u8(effect + 34u, 8u);
    w_u16(effect + 36u, size);
    w_u16(effect + 38u, 0u);
    w_u16(effect + 32u, model);
    w_u8(effect + 14u, flags | 2u);
    w_u32(effect + 20u, r_u32(object + 20u));
    w_u32(effect + 24u, r_u32(object + 24u));
    z = r_u32(object + 28u);
    w_u32(effect, 0x80061018u);
    w_u32(effect + 28u, z);
    result = (sub_80069A50() & 127u) - 63u;
    w_u16(effect + 8u, result);
    return result;
}

uint32 sub_80061018(uint32 object)
{
    sint32 width;
    uint32 ticks, rotation, result;
    FUNCTION_MARKER(0x80061018u, "1.EXE");
    width = (sint16)r_u16(object + 36u);
    if (width < 31)
        return sub_8002289C(object);
    ticks = r_u32(0x800A9010u);
    rotation = ticks * (uint32)(sint32)(sint16)r_u16(object + 8u);
    w_u16(object + 36u, (uint32)width - ticks * 10u);
    result = r_u16(object + 38u) + rotation;
    w_u16(object + 38u, result);
    return result;
}
