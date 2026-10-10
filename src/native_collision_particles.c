#include "native_call_dispatch.h"

uint32 sub_80022820(uint32 size, uint32 owner)
{
    uint32 object, tail;
    FUNCTION_MARKER(0x80022820u, "1.EXE");
    object = (uint32)draft_call_adapter(0x80064B04u, size);
    w_u32(object + 8u, owner);
    w_u8(owner + 15u, r_u8(owner + 15u) + 1u);
    w_u8(object + 14u, 5u);
    w_u8(object + 15u, 128u);
    tail = r_u32(0x800A567Cu);
    if (tail != 0u)
        w_u32(tail + 4u, object);
    else
        w_u32(0x800A5678u, object);
    w_u32(0x800A567Cu, object);
    w_u32(object + 4u, 0u);
    return object;
}

uint32 sub_80062CA0(uint32 object)
{
    uint32 tick = r_u32(0x800A9010u);
    uint32 x = tick * (uint32)(sint32)(sint16)r_u16(object + 8u);
    uint32 y = tick * (uint32)(sint32)(sint16)r_u16(object + 10u);
    uint32 z = tick * (uint32)(sint32)(sint16)r_u16(object + 16u);
    uint32 rotation = tick * (uint32)(sint32)(sint8)r_u8(object + 13u);
    uint32 size, result;
    FUNCTION_MARKER(0x80062CA0u, "1.EXE");
    w_u16(object + 10u, r_u16(object + 10u) + tick);
    x += r_u32(object + 20u);
    y += r_u32(object + 24u);
    size = r_u16(object + 36u) - (tick << 1);
    w_u32(object + 20u, x);
    w_u32(object + 24u, y);
    w_u16(object + 36u, size);
    w_u32(object + 28u, r_u32(object + 28u) + z);
    w_u16(object + 38u, r_u16(object + 38u) + rotation);
    if ((sint16)size < 0)
        return sub_8002289C(object);
    result = (sint32)(sint16)r_u16(object + 18u) < (sint32)r_u32(object + 24u);
    if (result != 0u)
        return sub_8002289C(object);
    return result;
}

uint32 sub_8005414C(uint32 object)
{
    uint32 step = (uint32)((sint32)r_u32(0x800A63D8u) >> 8);
    uint32 packed = r_u32(object + 16u), speed = r_u8(object + 16u);
    uint32 movement = ((speed << 8) * step) >> 16;
    uint32 radius = (uint32)(sint32)(sint8)r_u8(object + 13u);
    uint32 angle, updated, result;
    sint32 product;
    FUNCTION_MARKER(0x8005414Cu, "1.EXE");
    w_u32(object + 24u, r_u32(object + 24u) - movement);
    product = (sint32)(radius * (uint32)(sint32)(sint16)r_u16(0x800102E0u + ((packed >> 7) & 8190u)));
    w_u32(object + 20u, ((uint32)(sint32)(sint16)r_u16(object + 40u) << 4) + (uint32)(product >> 12));
    product = (sint32)((uint32)(sint32)(sint8)r_u8(object + 35u) * (uint32)(sint32)(sint16)r_u16(0x80010AE0u + 2u * (packed >> 20)));
    w_u32(object + 28u, ((uint32)(sint32)(sint16)r_u16(object + 42u) << 4) + (uint32)(product >> 12));
    angle = (((packed >> 8) & 4095u) + movement) & 4095u;
    updated = (packed & 0xFFF000FFu) | (angle << 8);
    w_u32(object + 16u, updated);
    updated = (updated & 0xFFFFFu) | (((updated >> 20) + (uint32)((sint32)((radius << 8) * step) >> 16)) << 20);
    w_u32(object + 16u, updated);
    if ((sint32)r_u32(object + 24u) < (sint32)r_u32(r_u32(object + 8u) + 60u))
        return sub_8002289C(object);
    result = r_u8(object + 12u) < 5u;
    if (result != 0u)
        return sub_8002289C(object);
    return result;
}
