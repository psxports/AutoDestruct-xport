#include "native_call_dispatch.h"

static uint32 angle_tick_step(uint32 magnitude)
{
    uint32 tick = (uint32)((sint32)r_u32(0x800A63D8u) >> 8);
    return (uint32)((sint32)(magnitude * tick) >> 16);
}

uint32 sub_800514A0(uint32 address, uint32 object)
{
    FUNCTION_MARKER(0x800514A0u, "1.EXE");
    uint32 model = r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
    uint32 physical = r_u32(0x800A90ACu) + 40u * model;
    uint32 angle = r_u16(address) & 4095u;
    sint32 limit = (sint16)sub_80055A9C((uint32)(sint32)(sint16)r_u16(physical + 32u), (uint32)(sint32)(sint16)r_u16(physical + 36u));
    sint32 current = (sint32)angle;
    uint32 next, target;
    switch (angle >> 10)
    {
        case 0u:
            if (current > 1024 - limit)
            {
                next = r_u16(address) + 1u + angle_tick_step(((uint32)(current - 1024 + limit) << 4) & 0xFF00u);
                w_u16(address, next);
                if (((1024u - (uint32)(sint32)(sint16)next) & 4095u) < 2049u)
                    return angle;
                target = 1024u;
            }
            else
            {
                next = r_u16(address) - 1u - angle_tick_step(((uint32)(1024 - current - limit) << 4) & 0xFF00u);
                w_u16(address, next);
                if (((0u - (uint32)(sint32)(sint16)next) & 4095u) >= 2048u)
                    return angle;
                target = 0u;
            }
            break;
        case 1u:
            if (current < limit + 1024)
            {
                next = r_u16(address) - 1u - angle_tick_step(((uint32)(limit - (current - 1024)) << 4) & 0xFF00u);
                w_u16(address, next);
                if (((1024u - (uint32)(sint32)(sint16)next) & 4095u) >= 2048u)
                    return angle;
                target = 1024u;
            }
            else
            {
                next = r_u16(address) + 1u + angle_tick_step(((uint32)(current - 1024 - limit) << 4) & 0xFF00u);
                w_u16(address, next);
                if (((2048u - (uint32)(sint32)(sint16)next) & 4095u) < 2049u)
                    return angle;
                target = 2048u;
            }
            break;
        case 2u:
            if (current > 3072 - limit)
            {
                next = r_u16(address) + 1u + angle_tick_step(((uint32)(current - 3072 + limit) << 4) & 0xFF00u);
                w_u16(address, next);
                if (((3072u - (uint32)(sint32)(sint16)next) & 4095u) < 2049u)
                    return angle;
                target = 3072u;
            }
            else
            {
                next = r_u16(address) - 1u - angle_tick_step(((uint32)(3072 - current - limit) << 4) & 0xFF00u);
                w_u16(address, next);
                if (((2048u - (uint32)(sint32)(sint16)next) & 4095u) >= 2048u)
                    return angle;
                target = 2048u;
            }
            break;
        default:
            if (current > limit + 3072)
            {
                next = r_u16(address) + 1u + angle_tick_step(((uint32)(current - 3072 - limit) << 4) & 0xFF00u);
                w_u16(address, next);
                if (((0u - (uint32)(sint32)(sint16)next) & 4095u) < 2049u)
                    return angle;
                target = 0u;
            }
            else
            {
                next = r_u16(address) - 1u - angle_tick_step(((uint32)(limit - (current - 3072)) << 4) & 0xFF00u);
                w_u16(address, next);
                if (((3072u - (uint32)(sint32)(sint16)next) & 4095u) >= 2048u)
                    return angle;
                target = 3072u;
            }
            break;
    }
    w_u16(address, target);
    return 0u;
}

uint32 sub_800518C4(uint32 address)
{
    FUNCTION_MARKER(0x800518C4u, "1.EXE");
    uint32 original = r_u16(address), angle = original & 4095u;
    uint32 next, target;
    switch (angle >> 10)
    {
        case 0u:
            next = original - 1u - angle_tick_step(((1024u - angle) >> 4) << 8);
            w_u16(address, next);
            if (((0u - (uint32)(sint32)(sint16)next) & 4095u) >= 2048u)
                return angle;
            target = 0u;
            break;
        case 1u:
            next = original + 1u + angle_tick_step(((angle - 1024u) >> 4) << 8);
            w_u16(address, next);
            if (((2048u - (uint32)(sint32)(sint16)next) & 4095u) < 2049u)
                return angle;
            target = 2048u;
            break;
        case 2u:
            next = original - 1u - angle_tick_step(((3072u - angle) >> 4) << 8);
            w_u16(address, next);
            if (((2048u - (uint32)(sint32)(sint16)next) & 4095u) >= 2048u)
                return angle;
            target = 2048u;
            break;
        default:
            next = original + 1u + angle_tick_step(((angle - 3072u) >> 4) << 8);
            w_u16(address, next);
            if (((0u - (uint32)(sint32)(sint16)next) & 4095u) < 2049u)
                return angle;
            target = 0u;
            break;
    }
    w_u16(address, target);
    return 0u;
}
