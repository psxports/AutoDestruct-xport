#include "native_call_dispatch.h"

static uint32 actor_signed_divide(uint32 numerator, sint32 denominator)
{
    if (!denominator)
        xport_mips_break(7);
    if (denominator == -1 && numerator == 0x80000000)
        xport_mips_break(6);
    return (uint32)((sint32)numerator / denominator);
}

static sint32 actor_angle_delta(uint32 value)
{
    value &= 0xFFF;
    if (value >= 0x801)
        value |= 0xF000;
    return (sint16)value;
}

uint32 sub_800487C0(uint32 parameters)
{
    uint32 velocity = r_u32(parameters + 8);
    uint32 length, minimum, heading, owner, target, current, acceleration;
    uint32 brake = 0, force, index, x, z, result, product_z, travel_x, travel_z, tick;
    sint32 first_delta, second_delta, first_abs, second_abs, turn, divisor, speed, penalty;
    FUNCTION_MARKER(0x800487C0, "1.EXE");
    length = sub_80069BE0(r_u32(velocity), r_u32(velocity + 8));
    minimum = (uint32)((sint32)(r_u32(0x800A63D8) << 5) >> 16);
    divisor = r_s32(0x800A56C0);
    minimum = actor_signed_divide(60 * minimum, divisor);
    length >>= 6;
    w_u16(parameters + 20, length);
    if ((sint16)length < (sint32)minimum)
        w_u16(parameters + 20, minimum);
    target = r_u32(parameters + 4);
    owner = r_u32(parameters);
    heading = sub_80055A9C(r_u32(target) - r_u32(owner + 20), r_u32(target + 8) - r_u32(owner + 28));
    owner = r_u32(parameters);
    current = r_u16(owner + 182);
    first_delta = actor_angle_delta(heading - current);
    second_delta = actor_angle_delta(heading - r_u16(owner + 180));
    first_abs = first_delta < 0 ? -first_delta : first_delta;
    second_abs = second_delta < 0 ? -second_delta : second_delta;
    turn = r_s16(parameters + 20);
    if (turn >= first_abs)
        result = current + (uint32)first_delta;
    else
        result = current + (uint32)((first_delta >> 31) | 1) * (uint32)turn;
    w_u16(owner + 182, result);
    owner = r_u32(parameters);
    if (first_abs < 1024 && second_abs < 1024 && !r_u8(owner + 195))
    {
        length = sub_80069BE0(r_u32(owner + 100), r_u32(owner + 104));
        acceleration = (r_u32(parameters + 12) - length) >> 7;
        if ((sint32)acceleration < 8)
            acceleration = 8;
        else if (r_s32(parameters + 16) < (sint32)acceleration)
            acceleration = r_u32(parameters + 16);
    }
    else
    {
        w_u8(owner + 195, 1);
        acceleration = 64;
        if (first_abs < 128 && second_abs < 128)
            w_u8(r_u32(parameters) + 195, 0);
    }
    owner = r_u32(parameters);
    if (r_u8(owner + 199))
    {
        acceleration = 0;
        brake = 12 * r_u32(parameters + 16);
    }
    force = (uint32)r_s8(owner + 87) * r_u32(0x800A9010) * acceleration;
    index = r_u16(owner + 182) & 0xFFF;
    result = (uint32)((sint32)(force * (uint32)r_s16(0x800102E0 + 2 * index)) >> 12);
    divisor = r_s32(0x800A56C0);
    x = actor_signed_divide(60 * result, divisor);
    result = (uint32)((sint32)(force * (uint32)r_s16(0x80010AE0 + 2 * index)) >> 12);
    z = actor_signed_divide(60 * result, divisor);
    velocity = r_u32(parameters + 8);
    x += r_u32(velocity);
    z += r_u32(velocity + 8);
    heading = sub_80055A9C(x, z);
    result = sub_80069BE0(x, z) - brake;
    owner = r_u32(parameters);
    index = ((uint32)(sint32)(sint16)heading - (uint32)r_s16(owner + 182)) & 0xFFF;
    penalty = r_s16(0x800102E0 + 2 * index);
    if (penalty < 0)
        penalty = -penalty;
    speed = (sint32)(result - (uint32)(penalty >> 3));
    if (speed < 64)
        speed = 0;
    if (r_s32(parameters + 12) < speed)
        speed = r_s32(parameters + 12);
    index = heading & 0xFFF;
    result = (uint32)speed * (uint32)r_s16(0x800102E0 + 2 * index);
    velocity = r_u32(parameters + 8);
    w_u32(velocity, (uint32)((sint32)result >> 12));
    product_z = (uint32)speed * (uint32)r_s16(0x80010AE0 + 2 * index);
    tick = r_u32(0x800A9010);
    divisor = r_s32(0x800A56C0);
    result = (uint32)((sint32)(x * tick) >> 8);
    travel_x = actor_signed_divide(60 * result, divisor);
    result = (uint32)((sint32)(z * tick) >> 8);
    travel_z = actor_signed_divide(60 * result, divisor);
    velocity = r_u32(parameters + 8);
    w_u32(velocity + 8, (uint32)((sint32)product_z >> 12));
    owner = r_u32(parameters);
    w_u32(owner + 20, r_u32(owner + 20) + travel_x);
    owner = r_u32(parameters);
    w_u32(owner + 28, r_u32(owner + 28) + travel_z);
    result = r_u32(parameters);
    w_u8(result + 199, 0);
    return result;
}
