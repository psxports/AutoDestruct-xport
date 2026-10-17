#include "native_call_dispatch.h"

static uint32 projectile_mul_shift(uint32 first, uint32 second, uint32 rounding, uint32 shift)
{
    return (uint32)((sint32)(first * second + rounding) >> shift);
}

static uint32 projectile_divide(uint32 numerator, sint32 denominator)
{
    if (!denominator)
        xport_mips_break(7);
    if (denominator == -1 && numerator == 0x80000000)
        xport_mips_break(6);
    return (uint32)((sint32)numerator / denominator);
}

static uint32 projectile_displacement(uint32 tick, uint32 sum)
{
    uint32 value = projectile_mul_shift(tick, sum, 32, 6) + 1024;
    return (uint32)((sint32)value >> 11);
}

uint32 sub_8006A474(uint32 vector, uint32 yaw, uint32 pitch)
{
    uint32 x = r_u32(vector), z = r_u32(vector + 8);
    uint32 length, first, second, result;
    FUNCTION_MARKER(0x8006A474, "1.EXE");
    length = sub_80069BE0(x, z);
    yaw &= 0xFFF;
    first = projectile_mul_shift(x, (uint32)r_s16(0x80010AE0 + 2 * yaw), 2048, 12);
    second = projectile_mul_shift(z, (uint32)r_s16(0x800102E0 + 2 * yaw), 2048, 12);
    w_u32(vector, first - second);
    first = projectile_mul_shift(z, (uint32)r_s16(0x80010AE0 + 2 * yaw), 2048, 12);
    second = projectile_mul_shift(x, (uint32)r_s16(0x800102E0 + 2 * yaw), 2048, 12);
    pitch &= 0xFFF;
    w_u32(vector + 8, first + second);
    first = (uint32)r_s16(0x80010AE0 + 2 * pitch);
    first = projectile_mul_shift(first, r_u32(vector + 4), 2048, 12);
    result = projectile_mul_shift(length, (uint32)r_s16(0x800102E0 + 2 * pitch), 2048, 12);
    w_u32(vector + 4, first - result);
    return result;
}

uint32 sub_8006C94C(uint32 object, uint32 limit, uint32 acceleration)
{
    uint32 pitch = r_u32(object + 76) & 0xFFF;
    uint32 horizontal, ax, ay, az, old_x, old_y, old_z, tick, length, scale, x, y, z, result;
    FUNCTION_MARKER(0x8006C94C, "1.EXE");
    horizontal = projectile_mul_shift(acceleration, (uint32)r_s16(0x80010AE0 + 2 * pitch), 2048, 12);
    ay = projectile_mul_shift(acceleration, (uint32)r_s16(0x800102E0 + 2 * pitch), 2048, 12);
    ax = projectile_mul_shift(horizontal, (uint32)r_s16(0x800102E0 + 2 * (r_u32(object + 72) & 0xFFF)), 2048, 12);
    az = projectile_mul_shift(horizontal, (uint32)r_s16(0x80010AE0 + 2 * (r_u32(object + 72) & 0xFFF)), 2048, 12);
    tick = (uint32)((sint32)(r_u32(0x800A63D8) + 512) >> 10);
    old_x = r_u32(object + 60);
    old_y = r_u32(object + 64);
    old_z = r_u32(object + 68);
    w_u32(object + 60, old_x + projectile_mul_shift(tick, ax, 32, 6));
    w_u32(object + 64, old_y + projectile_mul_shift(tick, ay, 32, 6));
    w_u32(object + 68, old_z + projectile_mul_shift(tick, az, 32, 6));
    length = sub_80069BE0(r_u32(object + 60), r_u32(object + 64));
    length = sub_80069BE0(length, r_u32(object + 68));
    if ((sint32)limit < 0)
        limit = 0 - limit;
    if ((sint32)limit < (sint32)length)
    {
        scale = projectile_divide(limit << 10, (sint32)length);
        x = scale * r_u32(object + 60);
        y = scale * r_u32(object + 64);
        z = scale * r_u32(object + 68);
        w_u32(object + 60, (uint32)((sint32)(x + 512) >> 10));
        w_u32(object + 64, (uint32)((sint32)(y + 512) >> 10));
        w_u32(object + 68, (uint32)((sint32)(z + 512) >> 10));
    }
    tick = (uint32)((sint32)(r_u32(0x800A63D8) + 512) >> 10);
    w_u32(object + 20, r_u32(object + 20) + projectile_displacement(tick, r_u32(object + 60) + old_x + ax));
    w_u32(object + 24, r_u32(object + 24) + projectile_displacement(tick, r_u32(object + 64) + old_y + ay));
    result = r_u32(object + 28) + projectile_displacement(tick, r_u32(object + 68) + old_z + az);
    w_u32(object + 28, result);
    return result;
}

uint32 sub_8006CC30(uint32 normal, uint32 velocity)
{
    uint32 first, second, angle_x, angle_z, length_x, length_z, value, tick, result;
    FUNCTION_MARKER(0x8006CC30, "1.EXE");
    first = sub_80055A9C((uint32)r_s16(normal + 2), 0 - (uint32)r_s16(normal));
    second = sub_80055A9C(r_u32(velocity + 4), r_u32(velocity));
    angle_x = 2 * first - second + 2048;
    first = sub_80055A9C((uint32)r_s16(normal + 2), 0 - (uint32)r_s16(normal + 4));
    second = sub_80055A9C(r_u32(velocity + 4), r_u32(velocity + 8));
    angle_z = 2 * first - second + 2048;
    length_x = sub_80069BE0(r_u32(velocity + 4), r_u32(velocity));
    length_z = sub_80069BE0(r_u32(velocity + 4), r_u32(velocity + 8));
    value = r_u32(velocity + 4);
    if ((sint32)value < 0)
        value = 0 - value;
    tick = (uint32)((sint32)(r_u32(0x800A63D8) + 512) >> 10) << 3;
    if ((sint32)tick < (sint32)value)
    {
        value = projectile_mul_shift(length_x, (uint32)r_s16(0x800102E0 + 2 * (angle_x & 0xFFF)), 2048, 12);
        value = projectile_mul_shift(768, value, 512, 10);
        w_u32(velocity + 4, value);
    }
    else
        w_u32(velocity + 4, 0);
    value = projectile_mul_shift(length_x, (uint32)r_s16(0x80010AE0 + 2 * (angle_x & 0xFFF)), 2048, 12);
    w_u32(velocity, projectile_mul_shift(819, value, 512, 10));
    value = projectile_mul_shift(length_z, (uint32)r_s16(0x80010AE0 + 2 * (angle_z & 0xFFF)), 2048, 12);
    result = projectile_mul_shift(819, value, 512, 10);
    w_u32(velocity + 8, result);
    return result;
}

uint32 sub_8006A5AC(uint32 object, uint32 ignored, uint32 normal, uint32 tag)
{
    uint32 mark = draft_scratch_mark();
    uint32 scratch = draft_scratch_adapter(8);
    uint32 result, length, pitch, yaw, pitch_turn, saved_pitch, saved_yaw, magnitude;
    uint32 x_force, z_force, slope, horizontal, angle, tick, x, y, z, inverse_yaw, inverse_pitch;
    sint32 divisor;
    FUNCTION_MARKER(0x8006A5AC, "1.EXE");
    result = sub_8002E640(object + 20, normal, 0, scratch);
    if (!result)
    {
        w_u32(object + 24, 0);
        draft_scratch_release(mark);
        return 0;
    }
    length = sub_80069BE0((uint32)r_s16(normal + 4), (uint32)r_s16(normal));
    pitch = sub_80055A9C((uint32)r_s16(normal + 2), length);
    yaw = sub_80055A9C(0 - (uint32)r_s16(normal + 4), 0 - (uint32)r_s16(normal));
    pitch_turn = pitch + 1024;
    saved_yaw = (uint16)(0 - yaw);
    sub_8006A474(object + 60, (uint32)(sint32)(sint16)saved_yaw, (uint32)(sint32)(sint16)pitch_turn);
    length = sub_80069BE0(r_u32(object + 60), r_u32(object + 68));
    divisor = (sint32)(length + 32772) >> 3;
    magnitude = projectile_divide(253952, divisor) + 81;
    slope = 0 - projectile_mul_shift(512, (uint32)r_s16(0x800102E0 + 2 * (pitch & 0xFFF)), 2048, 12);
    w_u32(0x800A74D4, length);
    horizontal = projectile_mul_shift(512, (uint32)r_s16(0x80010AE0 + 2 * (pitch & 0xFFF)), 2048, 12);
    w_u32(0x800A74D0, magnitude);
    saved_pitch = (uint16)pitch;
    slope = projectile_mul_shift(slope, magnitude, 512, 10);
    if ((sint32)length < 512)
    {
        if ((sint32)horizontal < (sint32)slope)
        {
            result = sub_8006A474(object + 60, (uint32)(sint32)(sint16)yaw, (uint32)(sint32)(sint16)(0 - pitch_turn));
            draft_scratch_release(mark);
            return result;
        }
        x_force = horizontal - slope;
        z_force = 0;
    }
    else
    {
        angle = (sub_80055A9C(r_u32(object + 68), r_u32(object + 60)) + 2048) & 0xFFF;
        x_force = horizontal + projectile_mul_shift(slope, (uint32)r_s16(0x80010AE0 + 2 * angle), 2048, 12);
        z_force = projectile_mul_shift(slope, (uint32)r_s16(0x800102E0 + 2 * angle), 2048, 12);
    }
    tick = (uint32)((sint32)(r_u32(0x800A63D8) + 512) >> 10);
    x = r_u32(object + 60);
    y = r_u32(object + 64);
    z = r_u32(object + 68);
    w_u32(0x800A74B8, x);
    w_u32(0x800A74BC, y);
    w_u32(0x800A74C0, z);
    x = r_u32(object + 60) + projectile_mul_shift(tick, x_force, 32, 6);
    z = r_u32(object + 68) + projectile_mul_shift(tick, z_force, 32, 6);
    w_u32(object + 64, 0);
    w_u32(object + 60, x);
    w_u32(object + 68, z);
    x = r_u32(object + 60) + r_u32(0x800A74B8) + x_force;
    w_u32(0x800A74C8, 0);
    w_u32(0x800A74C4, projectile_displacement(tick, x));
    z = r_u32(object + 68) + r_u32(0x800A74C0) + z_force;
    inverse_yaw = (uint32)(sint32)(sint16)(0 - saved_yaw);
    inverse_pitch = (uint32)(sint32)(sint16)(0 - (saved_pitch + 1024));
    w_u32(0x800A74CC, projectile_displacement(tick, z));
    sub_8006A474(object + 60, inverse_yaw, inverse_pitch);
    sub_8006A474(0x800A74C4, inverse_yaw, inverse_pitch);
    w_u32(object + 20, r_u32(object + 20) + r_u32(0x800A74C4));
    w_u32(object + 28, r_u32(object + 28) + r_u32(0x800A74CC));
    result = 0 - (uint32)draft_call_adapter(0x8002E310, object + 20, normal, tag);
    if (result)
        w_u32(object + 24, result);
    draft_scratch_release(mark);
    return result;
}
