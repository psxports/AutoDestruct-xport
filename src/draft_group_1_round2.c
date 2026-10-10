#include "psx.h"
#include "draft_signatures.h"
#include "draft_adapters.h"

static sint32 draft12_abs(sint32 v)
{
    return v < 0 ? -v : v;
}

static sint32 draft12_angle(sint32 v)
{
    v &= 4095;
    return v >= 2049 ? v - 4096 : v;
}

static sint32 draft12_cos(uint32 a)
{
    return (sint16)r_u16(0x800102E0u + (a & 4095u) * 2u);
}

static sint32 draft12_sin(uint32 a)
{
    return (sint16)r_u16(0x80010AE0u + (a & 4095u) * 2u);
}

static sint32 draft12_div(sint32 n, sint32 d, uint32 owner)
{
    // TODO Preserve original division break exception
    if (!d || (d == -1 && n == (sint32)0x80000000u))
        return (sint32)draft_call_adapter(owner, (uint32)n, (uint32)d);
    return n / d;
}

// FUNCTION_MARKER sub_8005A54C
uint32 sub_8005A54C(uint32 file)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 buffer = draft_scratch_adapter(24u);
    // TODO Bind original file and CD SDK targets
    while (!draft_call_adapter(0x8007D3F0u, buffer, file))
        draft_call_adapter(0x80059E4Cu, file);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8007B8B8u, buffer)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80035664
uint32 sub_80035664(uint32 count)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result;
    if ((sint32)count <= 0)
    {
        w_u32(0x800A6C64u, 0);
        // TODO Resolve undefined incoming V0 for the empty loop
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80035664u, count)));
    }
    w_u32(0x800A6C64u, 0);
    do
    {
        sub_800697BC();
        sub_8002DC94();
        sub_80022A68(2);
        // TODO Bind original frame and VSync boundaries
        draft_call_adapter(0x8001F850u);
        draft_call_adapter(0x8007F8C8u, 0u);
        w_u32(0x800A6C64u, r_u32(0x800A6C64u) + 1u);
        result = (sint32)r_u32(0x800A6C64u) < (sint32)count;
    } while (result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005F2D8
uint32 sub_8005F2D8(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 tick = r_u32(0x800A9010u), result;
    w_u32(object + 20u, r_u32(object + 20u) + (sint16)r_u16(object + 8u) * tick);
    w_u8(object + 13u, r_u8(object + 13u) - tick);
    w_u32(object + 24u, r_u32(object + 24u) + (sint16)r_u16(object + 10u) * tick);
    w_u32(object + 28u, r_u32(object + 28u) + (sint16)r_u16(object + 16u) * tick);
    result = r_u16(object + 38u) + (sint16)r_u16(object + 18u) * tick;
    w_u16(object + 38u, result);
    if ((sint8)r_u8(object + 13u) < 0)
    {
        w_u16(object + 8u, 2);
        w_u8(object + 13u, sub_80069A50() & 15u);
        w_u16(object + 32u, r_u16(r_u32(0x800A62ECu) + 60u));
        w_u32(object, 0x8005F3B8u);
        result = 0x8005F3B8u;
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005F3B8
uint32 sub_8005F3B8(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 tick = r_u32(0x800A9010u), result, movement = tick * (sint16)r_u16(object + 8u);
    w_u8(object + 13u, r_u8(object + 13u) - tick);
    w_u16(object + 8u, r_u16(object + 8u) + 2u * (sint16)tick);
    w_u32(object + 24u, r_u32(object + 24u) - movement);
    result = r_u16(object + 38u) + tick * (sint16)r_u16(object + 18u);
    w_u16(object + 38u, result);
    if ((sint8)r_u8(object + 13u) < 0)
    {
        w_u8(object + 13u, sub_80069A50() & 31u);
        w_u16(object + 18u, (uint32)((sint16)r_u16(object + 18u) >> 1));
        w_u16(object + 32u, r_u16(r_u32(0x800A62ECu) + 78u));
        w_u32(object, 0x8005F478u);
        result = 0x8005F478u;
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8003E5C4
uint32 sub_8003E5C4(uint32 position, uint32 velocity, uint32 bounce, uint32 offset)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(16u);
    sint32 v = (sint16)r_u16(velocity), ground, y, tick = (sint32)r_u32(0x800A9010u);
    // TODO Bind original ground query target 0x8002E310
    ground = -(sint32)draft_call_adapter(0x8002E310u, position, scratch, scratch + 8u) - (sint16)offset;
    y = (sint32)r_u32(position + 4u);
    if (y != ground)
    {
        v += 5 * tick;
        y += v;
        w_u32(position + 4u, (uint32)y);
        if (ground < y)
        {
            if (ground - y < -128 * tick)
                return draft_scratch_result(native_stack_mark, (uint64)(1));
            w_u32(position + 4u, (uint32)ground);
            v = (sint16)((sint16)bounce + ground - y);
        }
    }
    w_u16(velocity, (uint32)v);
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80062588
uint32 sub_80062588(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 tick = r_u32(0x800A9010u), scratch = draft_scratch_adapter(8u), result;
    if ((sint16)r_u16(object + 54u) < (sint32)r_u32(object + 24u))
        return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(object)));
    w_u16(scratch, r_u16(object + 8u));
    w_u16(scratch + 2u, r_u16(object + 10u));
    sub_80055288(scratch, object + 36u);
    {
        uint32 dx = tick * (sint16)r_u16(object + 18u), dy = tick * (sint16)r_u16(object + 56u), dz = tick * (sint16)r_u16(object + 58u);
        w_u16(object + 56u, r_u16(object + 56u) - tick);
        w_u16(object + 8u, r_u16(object + 8u) + tick * (sint8)r_u8(object + 13u));
        w_u16(object + 10u, r_u16(object + 10u) + tick * r_u16(object + 16u));
        w_u32(object + 20u, r_u32(object + 20u) + dx);
        w_u32(object + 24u, r_u32(object + 24u) - dy);
        result = r_u32(object + 28u) + dz;
        w_u32(object + 28u, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006AF08
uint32 sub_8006AF08(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(12u), i, target, current;
    for (i = 0; i < 12; i += 4)
        w_u32(scratch + i, r_u32(0x800A63F4u + i));
    sub_80031EA8(object + 36u, object + 20u, scratch);
    current = r_u32(object + 24u) << 10;
    target = r_u32(scratch + 4u) << 10;
    w_u32(object + 116u, 200);
    w_u32(object + 108u, current);
    w_u32(object + 120u, target);
    w_u32(object + 112u, (uint32)((sint32)(target - current) / 200));
    w_u16(object + 128u, r_u16(object + 116u));
    if ((sint32)target < (sint32)current)
    {
        w_u16(object + 124u, 1);
        return draft_scratch_result(native_stack_mark, (uint64)(1));
    }
    w_u16(object + 124u, target == current ? 0u : 0xffffu);
    return draft_scratch_result(native_stack_mark, (uint64)(0xffffffffu));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8003708C
uint32 sub_8003708C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch;
    if (r_u32(0x800A5C60u) == 1u)
    {
        scratch = draft_scratch_adapter(8u);
        w_u32(0x800A9A64u, 1);
        w_u32(0x800A9308u, r_u32(0x800A5C30u));
        w_u32(0x800A7EE0u, r_u32(0x800A5C34u));
        w_u32(0x800A7FA8u, r_u32(0x800A5C38u));
        w_u32(0x800A9A40u, r_u32(0x800A9678u));
        w_u8(0x800A9A41u, r_u8(0x800A9679u));
        // TODO Bind original CD SDK targets
        w_u32(0x800A7BE0u, (uint32)draft_call_adapter(0x8007B4A0u, 13u, 0x800A9A40u));
        if ((sint32)r_u32(0x800A7FA8u) < (sint32)r_u32(0x800A9308u))
            w_u32(0x800A7FA8u, r_u32(0x800A9308u));
        draft_call_adapter(0x8007B7B4u, r_u32(0x800A7FA8u), scratch);
        w_u32(0x800A7BE0u, (uint32)draft_call_adapter(0x8007B368u, 6u, scratch, 0u));
        w_u32(0x800A5C60u, 0);
        sub_80036EDC(r_u32(0x800A9CD0u));
        w_u32(0x800A966Cu, 60);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800734C0
uint32 sub_800734C0(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value, result;
    w_u32(0x800A7E10u, 100);
    w_u32(0x800A86A0u, 2048);
    // TODO Bind original parameter setter targets
    draft_call_adapter(0x8003D324u, 2048u);
    value = (uint32)(sint32)(sint16)sub_8003D270();
    draft_call_adapter(0x8003D27Cu, value | 255u);
    w_u32(0x800A7A18u, r_u32(0x800A7C6Cu));
    w_u32(0x800A7A1Cu, (uint32)(sint32)(sint16)sub_8003D270());
    w_u32(0x800A7A20u, r_u32(0x800A854Cu));
    w_u32(0x800A7A24u, (uint32)(sint32)(sint16)sub_8003D688());
    result = (uint32)(sint32)(sint16)draft_call_adapter(0x8003D67Cu);
    w_u32(0x800A7A28u, result);
    w_u32(0x800A7A2Cu, r_u32(0x800A84A0u));
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80048F9C
uint32 sub_80048F9C(uint32 position, uint32 velocity, uint32 direction, uint32 kind)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 tick = r_u32(0x800A9010u), heading, result;
    sint32 speed, extra = 0, angle, current;
    w_u32(position, r_u32(position) + (uint32)((sint32)(tick * r_u32(velocity)) >> 8));
    w_u32(position + 8u, r_u32(position + 8u) + (uint32)((sint32)(tick * r_u32(velocity + 8u)) >> 8));
    heading = (sint16)sub_80055A9C(r_u32(velocity), r_u32(velocity + 8u));
    // TODO Bind original distance target
    speed = (sint32)draft_call_adapter(0x80069BE0u, r_u32(velocity), r_u32(velocity + 8u));
    if ((sint16)kind == 12 && speed >= 257)
    {
        current = r_u16(direction);
        angle = draft12_angle((sint32)heading - current);
        if (draft12_abs(angle) < 21)
            w_u16(direction, (uint32)(angle + current));
        else
            w_u16(direction, (uint32)(current + ((angle >> 31) | 1) * ((1280 * ((sint32)r_u32(0x800A63D8u) >> 8)) >> 16)));
        extra = speed >> 4;
    }
    speed -= (speed >> 5) + extra;
    if (speed < 64)
        speed = 0;
    w_u32(velocity, (uint32)((speed * draft12_cos(heading)) >> 12));
    result = (uint32)((speed * draft12_sin(heading)) >> 12);
    w_u32(velocity + 8u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006BA1C
uint32 sub_8006BA1C(uint32 object, uint32 maximum, uint32 force)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 age = (sint16)r_u16(object + 82u), wiggle = 0, angle, xforce, zforce, tick = ((sint32)r_u32(0x800A63D8u) + 512) >> 10, x, z, length, factor, dx, dz, movement;
    uint32 result;
    if (age >= 11)
        wiggle = ((draft12_cos((uint32)(80 * age - 800)) << 7) + 2048) >> 12;
    angle = (wiggle + r_u16(object + 72u)) & 4095;
    xforce = ((sint32)force * draft12_cos((uint32)angle) + 2048) >> 12;
    zforce = ((sint32)force * draft12_sin((uint32)angle) + 2048) >> 12;
    x = ((tick * xforce + 32) >> 6) + (sint32)r_u32(object + 60u);
    z = ((tick * zforce + 32) >> 6) + (sint32)r_u32(object + 68u);
    // TODO Bind original distance target
    length = (sint32)draft_call_adapter(0x80069BE0u, (uint32)x, (uint32)z);
    if ((sint32)maximum < length && (sint32)maximum > 0)
    {
        factor = draft12_div((sint32)(maximum << 10), length, 0x8006BA1Cu);
        x = (factor * x + 512) >> 10;
        z = (factor * z + 512) >> 10;
    }
    dx = (((tick * (x + (sint32)r_u32(object + 60u) + xforce) + 32) >> 6) + 1024) >> 11;
    dz = (((tick * (z + (sint32)r_u32(object + 68u) + zforce) + 32) >> 6) + 1024) >> 11;
    w_u32(object + 20u, r_u32(object + 20u) + (uint32)dx);
    w_u32(object + 28u, r_u32(object + 28u) + (uint32)dz);
    movement = (sint32)draft_call_adapter(0x80069BE0u, (uint32)dx, (uint32)dz);
    if (movement < 30)
        movement = 30;
    sub_8006A948(object, (uint32)movement);
    w_u32(object + 24u, sub_8006B198(object + 108u, (uint32)movement));
    w_u32(object + 64u, 0);
    result = sub_80055A9C(r_u32(object + 112u), 1024u);
    w_u32(object + 76u, result);
    w_u32(object + 60u, (uint32)x);
    w_u32(object + 68u, (uint32)z);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8003D338
uint32 sub_8003D338(uint32 state, uint32 kind)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 stage = (sint16)r_u16(state) >> 8, value = r_u8(state), x, y, z, scale, next;
    uint32 descriptor = r_u32(0x800901DCu + 12u * (uint32)(sint32)(sint16)kind), table;
    if (stage)
    {
        --stage;
        if (stage < 0)
            stage = 0;
        if (stage > 9)
            stage = 9;
        table = 0x80090168u + (uint32)stage * 6u;
        x = draft12_div((sint32)((r_u16(descriptor + 6u) + 1u) << 16), r_u16(table), 0x8003D338u);
        y = draft12_div((sint32)((r_u16(descriptor + 8u) + 1u) << 16), r_u16(table + 2u), 0x8003D338u);
        z = draft12_div((sint32)((r_u16(descriptor + 10u) + 1u) << 16), r_u16(table + 4u), 0x8003D338u);
        scale = (value ^ 255) >> 2;
    }
    else
    {
        x = (sint32)(r_u16(descriptor + 6u) << 16);
        if (x < 0)
            x += 3;
        x >>= 2;
        y = (sint32)(r_u16(descriptor + 8u) << 16);
        if (y < 0)
            y += 3;
        y >>= 2;
        z = (sint32)(r_u16(descriptor + 10u) << 16);
        if (z < 0)
            z += 3;
        z >>= 2;
        value = 0;
        scale = 15;
    }
    scale = scale ? scale << 8 : 256;
    next = value - ((value ^ 255) >> 3) - 1;
    if (next < 0)
        next = 0;
    w_u16(state, (uint32)(((stage + 1) << 8) + next));
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)(sint32)(sint16)((((x / 256 * scale) >> 16) + ((y / 256 * scale) >> 16) + ((z / 256 * scale) >> 16)) / 3)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80019220
uint32 sub_80019220(uint32 packet, uint32 vertices, uint32 source, uint32 ot, uint32 ignored, uint32 bias, uint32 count, uint32 next)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i, j, address, depth, entry;
    for (i = 0; i < count; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            address = vertices + 8u * r_u16(source + 10u + j * 2u);
            xport_gte_write_data(j * 2u, r_u32(address));
            xport_gte_write_data(j * 2u + 1u, r_u32(address + 4u));
        }
        draft_gte_command_adapter(0x280030u);
        address = vertices + 8u * r_u16(source + 8u);
        xport_gte_write_data(0, r_u32(address));
        xport_gte_write_data(1, r_u32(address + 4u));
        draft_gte_command_adapter(0x1400006u);
        if ((sint32)xport_gte_read_data(24) >= 0)
        {
            draft_gte_command_adapter(0x158002Du);
            depth = xport_gte_read_data(7);
            if (depth)
            {
                w_u32(packet + 8u, xport_gte_read_data(12));
                w_u32(packet + 12u, xport_gte_read_data(13));
                w_u32(packet + 16u, xport_gte_read_data(14));
                xport_gte_write_data(6, r_u32(source + 4u));
                draft_gte_command_adapter(0x108041Bu);
                entry = ot + 4u * (bias + (depth >> 3));
                w_u32(packet, (r_u32(entry) & 0xffffffu) | 0x4000000u);
                w_u32(entry, (r_u32(entry) & 0xff000000u) | (packet & 0xffffffu));
                w_u32(packet + 4u, xport_gte_read_data(22));
                packet += 20u;
            }
        }
        source += 16u;
    }
    w_u32(next, source);
    return draft_scratch_result(native_stack_mark, (uint64)(packet));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002BC6C
uint32 sub_8002BC6C(uint32 object, uint32 target, uint32 output)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(20u), vector = scratch + 8u, i, angle, result;
    sint32 velocity, magnitude;
    w_u32(scratch, r_u32(0x800A5794u));
    w_u16(scratch + 6u, r_u16(0x800A579Au));
    for (i = 0; i < 12; i += 4)
        w_u32(vector + i, r_u32(0x800A579Cu + i));
    // TODO Bind original indirect orientation and speed callbacks
    draft_call_adapter(r_u32(r_u32(object + 16u) + 20u), object, scratch);
    angle = (sub_80055A9C(r_u32(target + 20u) - r_u32(object + 20u), r_u32(target + 28u) - r_u32(object + 28u)) - 2048u - r_u16(scratch + 2u)) & 4095u;
    velocity = (sint32)draft_call_adapter(r_u32(r_u32(object + 16u)), object);
    velocity = angle < 2049u ? -(sint32)velocity >> 16 : velocity >> 16;
    if ((sint16)r_u16(object + 44u) < 0)
        velocity = -(sint16)velocity;
    velocity = (sint16)velocity;
    magnitude = draft12_abs(velocity);
    result = magnitude < 3;
    if (magnitude >= 3)
    {
        velocity = (magnitude >= 10 ? 15 : 10) * ((velocity >> 31) | 1);
        w_u16(scratch, (uint32)velocity);
        sub_80031DC8(object + 36u, vector, scratch);
        w_u32(output, r_u32(output) + (r_u32(vector) << 16));
        result = r_u32(output + 8u) + (r_u32(vector + 8u) << 16);
        w_u32(output + 8u, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002B7FC
uint32 sub_8002B7FC(uint32 position, uint32 mask, uint32 offsets, uint32 strength)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i, scratch, result;
    sint32 count = (sint32)strength >> 18;
    if (count >= 6)
        count = 5;
    for (i = 0; i < 8; ++i)
        if ((mask & (1u << i)) << 16)
            break;
    if (i == 8)
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    scratch = draft_scratch_adapter(12u);
    w_u32(scratch, r_u32(position) + (sint16)r_u16(offsets + i * 8u));
    w_u32(scratch + 4u, r_u32(position + 4u) + (sint16)r_u16(offsets + i * 8u + 2u));
    w_u32(scratch + 8u, r_u32(position + 8u) + (sint16)r_u16(offsets + i * 8u + 4u));
    if ((sint32)strength > 1310720)
        strength = 1310720;
    result = (sint32)strength > 0x80000;
    if (result)
    {
        sub_800623F8(scratch, r_u16(r_u32(0x800A62ECu) + 76u), (uint32)((sint32)strength >> 6), (uint32)(sint32)(sint16)count);
        // TODO Bind original sound target
        draft_call_adapter(0x80035A08u, 9u, 2048u, 0u, scratch);
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80035A08u, 15u, 2048u, 0u, scratch)));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800623F8
uint32 sub_800623F8(uint32 position, uint32 resource, uint32 force, uint32 count)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(16u), object, i, result = count << 16;
    sint32 ground, scale = (sint32)force >> 8, x, y, z;
    // TODO Bind original ground and allocation targets
    ground = -(sint32)draft_call_adapter(0x8002E310u, position, scratch, scratch + 8u);
    if (ground == 0)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    for (i = 0; (sint32)i < (sint16)count; ++i)
    {
        object = (uint32)draft_call_adapter(0x800226E4u, 60u);
        w_u32(object + 20u, r_u32(position));
        w_u32(object + 24u, r_u32(position + 4u));
        w_u32(object + 28u, r_u32(position + 8u));
        w_u16(object + 32u, resource);
        w_u16(object + 54u, (uint32)ground);
        w_u8(object + 14u, r_u8(object + 14u) | 2u);
        w_u8(object + 34u, 11);
        w_u32(object, 0x80062588u);
        w_u16(object + 8u, sub_80069A50());
        w_u16(object + 10u, sub_80069A50());
        w_u8(object + 13u, sub_80069A50() - 127u);
        w_u16(object + 16u, (sub_80069A50() & 255u) - 127u);
        x = (sub_80069A50() & 31u) - 15;
        y = (sub_80069A50() & 31u) + 7;
        z = (sub_80069A50() & 31u) - 15;
        w_u16(object + 18u, (uint32)((x << 8) * scale) >> 16);
        w_u16(object + 56u, (uint32)((y << 8) * scale) >> 16);
        result = (uint32)(((z << 8) * scale) >> 16);
        w_u16(object + 58u, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80062240
uint32 sub_80062240(uint32 start, uint32 end, uint32 ignored, uint32 effect, uint32 spacing, uint32 allocation, uint32 auxiliary)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(64u), delta = scratch, angles = scratch + 8u, vector = scratch + 16u, position = scratch + 24u, matrix = scratch + 40u, object, i;
    sint32 horizontal, distance;
    for (i = 0; i < 8; ++i)
        w_u8(vector + i, 0);
    w_u16(vector + 4u, 0u - (sint16)spacing);
    sub_80061D90(start, end, delta);
    // TODO Bind original distance target
    horizontal = (sint32)draft_call_adapter(0x80069BE0u, (uint32)(sint32)(sint16)r_u16(delta), (uint32)(sint32)(sint16)r_u16(delta + 4u));
    distance = (sint32)draft_call_adapter(0x80069BE0u, (uint32)horizontal, (uint32)(sint32)(sint16)r_u16(delta + 2u));
    w_u16(angles + 2u, sub_80055A9C((uint32)(sint32)(sint16)r_u16(delta), (uint32)(sint32)(sint16)r_u16(delta + 4u)));
    w_u16(angles, 0u - sub_80055A9C((uint32)(sint32)(sint16)r_u16(delta + 2u), (uint32)horizontal));
    w_u16(angles + 4u, 0);
    while ((sint32)spacing < distance)
    {
        object = sub_800621A4((uint32)(sint32)(sint16)allocation, effect, (uint32)(sint32)(sint16)auxiliary);
        for (i = 0; i < 12; i += 4)
            w_u32(position + i, r_u32(start + i));
        sub_80055288(angles, matrix);
        // TODO Bind original transform target 0x80031CE8
        draft_call_adapter(0x80031CE8u, matrix, position, vector, start);
        sub_80061DD0(position, start, object + 20u);
        distance -= (sint32)spacing;
    }
    return draft_scratch_result(native_stack_mark, (uint64)((sint32)spacing < distance));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800620A4
uint32 sub_800620A4(uint32 object, uint32 trail, uint32 resource, uint32 ignored, uint32 effect, uint32 spacing, uint32 allocation, uint32 auxiliary)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(20u), vector = scratch + 12u, i, result;
    for (i = 0; i < 8; ++i)
        w_u8(vector + i, 0);
    w_u16(vector + 4u, spacing);
    // TODO Bind original transform target 0x80031CE8
    draft_call_adapter(0x80031CE8u, object + 36u, object + 20u, vector, scratch);
    if (r_u8(trail + 12u) & 1u)
        return draft_scratch_result(native_stack_mark, (uint64)(sub_80062240(trail, scratch, r_u32(resource + 4u), effect, spacing, allocation, auxiliary)));
    w_u8(trail + 12u, 1);
    w_u32(trail, r_u32(scratch));
    w_u32(trail + 4u, r_u32(scratch + 4u));
    result = r_u32(scratch + 8u);
    w_u32(trail + 8u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80035CD0
uint32 sub_80035CD0(uint32 position, uint32 voice)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(20u), vector = scratch + 12u, hardware = 0x800BBEFCu + (uint32)(sint32)(sint16)voice * 64u;
    sint32 left, right, angle, level, pan, value, result;
    sint64 product;
    w_u32(vector, r_u32(0x800A5C58u));
    w_u32(vector + 4u, r_u32(0x800A5C5Cu));
    sub_80031B6C(0x800A7EF4u, vector, scratch);
    // TODO Bind original distance target
    left = (sint32)draft_call_adapter(0x80069BE0u, r_u32(0x800A7EE4u) + r_u32(scratch) - r_u32(position), r_u32(0x800A7EECu) + r_u32(scratch + 8u) - r_u32(position + 8u));
    w_u16(vector, 136);
    sub_80031B6C(0x800A7EF4u, vector, scratch);
    right = (sint32)draft_call_adapter(0x80069BE0u, r_u32(0x800A7EE4u) + r_u32(scratch) - r_u32(position), r_u32(0x800A7EECu) + r_u32(scratch + 8u) - r_u32(position + 8u));
    angle = draft12_angle(sub_80055A9C(r_u32(0x800A7EE4u) - r_u32(position), r_u32(0x800A7EECu) - r_u32(position + 8u)) - r_u16(0x800A7E7Cu));
    level = (right + left) >> 7;
    result = angle >> 3;
    if ((uint32)(level ? level + 126 : 127) < 253u)
    {
        pan = r_u8(0x800A8234u + (uint8)(angle >> 3));
        if (angle > 0)
            pan = -pan;
        pan = (sint16)(pan << 7);
        level = (right >> 6) + 128;
        if (level < 0)
            level = 0;
        if (level > 255)
            level = 255;
        value = ((((sint32)r_u8(0x800A83A0u + (uint32)level) << 7) + pan) >> 1) * (sint16)r_u16(0x800A9D6Cu);
        product = (sint64)value * (sint32)0x80020008u;
        value = (((sint32)(product >> 32) + value) >> 13) - (value >> 31);
        w_u16(hardware + 8u, (value & 0x8000) ? 0u : (uint32)value);
        pan = r_u8(0x800A8234u + (uint8)(angle >> 3));
        if (angle < 0)
            pan = -pan;
        pan = (sint16)(pan << 7);
        level = (left >> 6) + 128;
        if (level < 0)
            level = 0;
        if (level > 255)
            level = 255;
        value = ((((sint32)r_u8(0x800A83A0u + (uint32)level) << 7) + pan) >> 1) * (sint16)r_u16(0x800A9D6Cu);
        product = (sint64)value * (sint32)0x80020008u;
        value = (((sint32)(product >> 32) + value) >> 13) - (value >> 31);
        w_u16(hardware + 10u, (value & 0x8000) ? 0u : (uint32)value);
        result = (sint32)((uint32)value << 16);
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006BD08
uint32 sub_8006BD08(uint32 position, uint32 pitch, uint32 yaw, uint32 faction, uint32 category)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i, object, kind, best = 0, secondary = 0;
    sint32 best_cost = 27200, secondary_cost = 27200, dx, dz, angle, distance, vertical, cost, v, w;
    faction &= 127u;
    for (i = 0; i < r_u32(0x800A5690u); ++i)
    {
        object = r_u32(r_u32(0x800A568Cu) + i * 4u);
        if (r_u32(object + 20u) == r_u32(position) && r_u32(object + 28u) == r_u32(position + 8u))
            continue;
        kind = r_u8(object + 13u) & 127u;
        if (kind == 0 || kind == 8)
        {
            if (!r_u16(object + 58u) || (faction != 1 && faction != 7))
                continue;
        }
        else if (kind == 1)
        {
            if (faction != 8 && faction != 0)
                continue;
        }
        else if (kind == 2)
        {
            if (!r_u16(object + 58u))
                continue;
        }
        else if (kind == 7)
        {
            if (!r_u16(object + 58u) || (faction != 8 && faction != 0))
                continue;
        }
        else
            continue;
        dx = (sint32)(r_u32(object + 20u) - r_u32(position));
        dz = (sint32)(r_u32(object + 28u) - r_u32(position + 8u));
        angle = draft12_angle(sub_80055A9C((uint32)dx, (uint32)dz) - (sint16)yaw);
        if (draft12_abs(angle) >= 1024)
            continue;
        // TODO Bind original distance target
        distance = (sint32)draft_call_adapter(0x80069BE0u, (uint32)dx, (uint32)dz);
        vertical = draft12_angle(sub_80055A9C(r_u32(object + 24u) - r_u32(position + 4u), (uint32)distance) - (sint16)pitch);
        if (distance >= 10001 || (uint16)(vertical + 1023) >= 1423u)
            continue;
        v = angle / 32;
        w = vertical / 16;
        cost = draft12_abs(v * v * v) + draft12_abs(w * w * w) + distance;
        if (kind == 2)
        {
            if (cost < secondary_cost && (sub_8002EAE4(position, object + 20u, 0) << 16))
            {
                secondary = object;
                secondary_cost = cost;
            }
        }
        else if (cost < best_cost && (sub_8002EAE4(position, object + 20u, 0) << 16))
        {
            best = object;
            best_cost = cost;
        }
    }
    w_u16(category, best ? 1u : 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(best ? best : secondary));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8004915C
uint32 sub_8004915C(uint32 parameters)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object = r_u32(parameters), target, limit = 5, begin, end, index, frequency;
    sint32 angle;
    if (!r_u16(object + 70u) && r_u32(0x800A8690u))
        limit = 10;
    // TODO Bind original distance target
    if ((uint32)draft_call_adapter(0x80069BE0u, r_u32(object + 100u), r_u32(object + 104u)) < 4096u && ((sint32)limit < (sint8)r_u8(object + 84u) || (r_u8(object + 86u) && limit < 10)))
    {
        if ((sint8)r_u8(object + 85u) <= 0)
        {
            w_u8(object + 198u, r_u8(object + 198u) ? 8u : 16u);
            w_u8(object + 85u, sub_80069A50() % 6u + 1u);
        }
        if ((sint16)r_u16(object + 166u) / 2 < (sint16)r_u16(object + 58u))
            w_u8(object + 86u, 0);
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    }
    w_u8(object + 86u, 0);
    target = r_u32(parameters + 4u);
    if ((sub_8002EAE4(object + 20u, target + 20u, 0) << 16) == 0)
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    angle = draft12_abs((sint16)r_u16(parameters + 26u));
    if (angle < 1949 || r_u8(object + 197u) == 22u || r_u8(object + 197u) - 8u < 2u)
    {
        if (angle >= 100)
            return draft_scratch_result(native_stack_mark, (uint64)(0));
        begin = 0x800A60C8u + 20u * (uint32)(angle / 25);
        end = begin + 20u;
    }
    else
    {
        begin = 0x800A60B0u + 6u * (uint32)((2048 - angle) / 25);
        end = begin + 6u;
    }
    for (; begin < end; ++begin)
    {
        index = r_u8(begin);
        if ((1u << (index & 31u)) & r_u32(object + 148u))
        {
            frequency = r_u8(0x800A6118u + index);
            if (!frequency)
            {
                // TODO Preserve original modulus break boundary
                return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8004915Cu, parameters)));
            }
            if (sub_80069A50() % frequency == 0)
            {
                w_u8(object + 84u, r_u8(object + 84u) + 1u);
                return draft_scratch_result(native_stack_mark, (uint64)(index + 1u));
            }
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80066AEC
uint32 sub_80066AEC(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 speed, x, z, amount;
    uint32 remaining, kind;
    if (r_u8(object + 12u) < 4u)
        return draft_scratch_result(native_stack_mark, (uint64)(1));
    if (!r_u16(object + 56u))
        goto render;
    // TODO Bind original speed and velocity normalization targets
    speed = (sint32)draft_call_adapter(0x80069BE0u, (uint32)(sint32)(sint16)r_u16(object + 68u), (uint32)(sint32)(sint16)r_u16(object + 72u));
    remaining = r_u16(object + 80u) - 1u;
    w_u16(object + 80u, remaining);
    if ((sint16)r_u16(object + 82u) >= speed && (remaining << 16))
    {
        w_u16(object + 56u, 0);
        goto render;
    }
    if (speed >= 101)
        draft_call_adapter(0x80065588u, object + 68u, 100u);
    x = (sint16)r_u16(object + 68u) >> 2;
    z = (sint16)r_u16(object + 72u) >> 2;
    w_u16(object + 68u, (uint32)x);
    w_u16(object + 72u, (uint32)z);
    amount = sub_80069A50() & 15u;
    w_u16(object + 68u, (uint32)(x + (x <= 0 ? -amount : amount)));
    amount = sub_80069A50() & 15u;
    w_u16(object + 72u, (uint32)(z + (z <= 0 ? -amount : amount)));
    amount = speed >> 1;
    if (amount < 5)
        amount = 5;
    if (amount > 30)
        amount = 30;
    w_u32(object, 0x80066D7Cu);
    w_u8(object + 34u, 8);
    w_u16(object + 70u, r_u16(object + 70u) - (uint32)amount - (sub_80069A50() & 7u));
    w_u16(object + 66u, (sub_80069A50() & 127u) - 63u);
    w_u16(object + 74u, (sub_80069A50() & 127u) - 63u);
    kind = r_u8(object + 13u);
    sub_8006706C(object + 20u, kind, 0);
    sub_800652C0(r_u32(object + 8u));
    // TODO Bind original subtype initialization targets
    if (kind == 2)
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80068C74u, object)));
    if (kind == 3)
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80068BF0u, object)));
    if (kind == 1)
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80067604u, object)));
    return draft_scratch_result(native_stack_mark, (uint64)(kind >= 3 ? 3u : 1u));
render:
    return draft_scratch_result(native_stack_mark, (uint64)(sub_80029970(object, 0, r_u32(0x800A9A38u) == 4u || r_u8(object + 13u) == 4u ? 10u : 7u, 0, object + 20u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80055D54
uint32 sub_80055D54(uint32 object, uint32 animation, uint32 angle)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(8u), base = r_u32(0x8008FD3Cu + 12u * (uint32)(sint32)(sint16)r_u16(animation + 364u)), frame = base + ((uint32)(sint32)(sint16)r_u16(animation + 370u) << 6), i, data, matrix, result;
    sint32 bone;
    w_u16(scratch, 2048);
    w_u16(scratch + 2u, angle + 2048u);
    sub_80055288(scratch, object + 36u);
    for (i = 0; i < 5; ++i)
        xport_gte_write_control(i, r_u32(object + 36u + i * 4u));
    for (i = 0; i < 3; ++i)
        xport_gte_write_control(i + 5u, r_u32(object + 20u + i * 4u));
    for (bone = 8; bone >= 0; --bone)
    {
        data = frame + (uint32)bone;
        matrix = animation + 36u * (uint32)bone;
        for (i = 0; i < 3; ++i)
            w_u16(scratch + i * 2u, (uint32)(2 * (sint8)r_u8(data + 10u + i * 9u)) + r_u16(0x800A61E8u + 6u * (uint32)(bone + 1) + i * 2u));
        // TODO Bind original vector and matrix targets
        draft_call_adapter(0x80031CC0u, scratch, matrix);
        draft_call_adapter(0x80054F40u, 16u * r_u8(data + 37u), 16u * r_u8(data + 46u) + 2048u, 0u - 16u * r_u8(data + 55u), matrix + 16u);
        draft_call_adapter(0x80031A54u, matrix + 16u, matrix + 16u);
    }
    draft_call_adapter(0x80054F40u, 16u * r_u8(frame + 6u), 16u * r_u8(frame + 7u) + 2048u, 0u - 16u * r_u8(frame + 8u), object + 36u);
    draft_call_adapter(0x80031A54u, object + 36u, object + 36u);
    w_u32(animation + 324u, r_u32(object + 20u));
    w_u32(animation + 332u, r_u32(object + 28u));
    result = (uint32)(sint32)(sint16)r_u16(frame) + r_u32(object + 24u);
    w_u32(animation + 328u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8003CCE0
uint32 sub_8003CCE0(uint32 position, uint32 type)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 target, seed, first, second, kind = 13, volume = 2048;
    type = (uint32)(sint32)(sint16)type;
    if (type >= 32u)
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    target = r_u32(0x80010080u + type * 4u);
    if (target == 0x8003CD18u)
        kind = 13;
    else if (target == 0x8003CD20u)
    {
        kind = 13;
        volume = 1800;
    }
    else if (target == 0x8003CD2Cu)
    {
        seed = r_u32(0x800A63DCu) * 5u + 1u;
        w_u32(0x800A63DCu, seed);
        first = (seed & 65535u) % 255u;
        seed = seed * 5u + 1u;
        w_u32(0x800A63DCu, seed);
        second = (seed & 65535u) % 255u;
        w_u32(0x800A6E6Cu, first);
        if (second >= 201u)
            kind = 33;
        else if (first - 101u < 49u)
            kind = 4;
        else if (first - 1u < 49u)
            kind = 5;
        else
        {
            // TODO Resolve original caller-carried T1 on the remaining RNG branch
            return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8003CCE0u, position, type)));
        }
    }
    else if (target == 0x8003CDDCu)
        kind = 15;
    else if (target == 0x8003CDE4u)
        kind = 22;
    else if (target == 0x8003CE0Cu)
        return draft_scratch_result(native_stack_mark, (uint64)(target));
    else
    {
        // TODO Resolve additional jump-table destinations
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(target, position, type)));
    }
    // TODO Bind original sound target
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80035A08u, kind, volume, 0u, position)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800461DC
uint32 sub_800461DC(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result, target, playerlist = r_u32(0x800A851Cu);
    sint32 difference, y;
    if (sub_80045E18(object, object + 56u) || sub_80045DD4(object))
    {
        if (r_u8(object + 67u) && r_u32(playerlist + 4u * r_u32(0x800A9730u)) == object)
        {
            // TODO Bind original selection cleanup target
            draft_call_adapter(0x8004525Cu);
        }
        w_u32(object, 0x80029968u);
        return draft_scratch_result(native_stack_mark, (uint64)(0x80029968u));
    }
    target = r_u32(playerlist + 4u * (uint32)(sint32)(sint16)r_u16(object + 34u));
    result = r_u8(target + 64u);
    if (!result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    if (r_u8(object + 67u) && !r_u16(object + 34u))
        sub_800451B4(object + 20u, (uint32)(sint32)(sint16)r_u16(object + 68u));
    target = r_u32(playerlist + 4u * (uint32)(sint32)(sint16)r_u16(object + 34u));
    difference = draft12_abs((sint32)(r_u32(target + 20u) - r_u32(object + 20u)));
    result = (sint32)r_u32(object + 36u) < difference;
    if (result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    difference = draft12_abs((sint32)(r_u32(target + 28u) - r_u32(object + 28u)));
    result = (sint32)r_u32(object + 40u) < difference;
    if (result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    y = (sint32)r_u32(target + 24u);
    result = (sint32)r_u32(object + 44u) < y;
    if (result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    result = y < (sint32)r_u32(object + 48u);
    if (result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    if (r_u8(object + 8u))
    {
        // TODO Bind original indirect object speed callback
        result = (sint32)draft_call_adapter(r_u32(r_u32(target + 16u))) < 8193;
        if (!result)
            return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    // TODO Bind original activation target
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80046004u, object, r_u16(target + 70u) == 1u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800725D0
uint32 sub_800725D0(uint32 row)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(16u), selection = scratch + 8u, x = r_u32(0x800A75C8u) + 46u, y = 12u * (sub_8006F818(row) + 1u) + 30u, kind = (sint16)sub_80037BB8() == 2, which = 0x800A6458u + kind * 2u, keys, result;
    sint32 index, next;
    w_u32(scratch, 0x34333231u);
    w_u8(scratch + 4u, 0);
    w_u16(selection, r_u16(0x800A64F4u));
    sub_80070D6C(x - 7u, y - 2u, 60, 15, 101);
    sub_80043820(scratch, 0x4f4f4fu, x, y, 98, 1);
    // TODO Bind original pad target
    keys = (uint32)(sint32)(sint16)draft_call_adapter(0x80038970u, 0xffff8000u);
    keys |= (uint32)(sint32)(sint16)draft_call_adapter(0x80038970u, 8192u);
    index = (sint16)r_u16(which);
    w_u8(selection, r_u8(scratch + (uint32)index));
    sub_80043820(selection, 0x7f7f7fu, x + 15u * (uint32)index, y, 98, 1);
    result = keys & 0x8000u;
    if (r_u32(0x800A6460u) == row)
    {
        if (result)
            --index;
        next = (keys & 8192u) ? index + 1 : index;
        result = sub_80071960((uint32)next, 3);
        index = (sint16)result;
        if (index != (sint16)r_u16(which))
        {
            // TODO Bind original sound target
            result = (uint32)draft_call_adapter(0x80035A08u, 29u, 2048u, 255u, 0u);
        }
        w_u16(which, (uint32)index);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002A5DC
uint32 sub_8002A5DC(uint32 object, uint32 type)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 sound = 0, volume = 0, size = 0, index, address, result;
    type &= 255u;
    // TODO Bind original effect initialization and sound targets
    if (type == 1)
    {
        size = 512;
        draft_call_adapter(0x8005F080u, object);
        sub_8002289C(object);
        sound = 15;
        volume = 2048;
    }
    else if (type == 2)
    {
        size = 1024;
        sound = 15;
        volume = 1536;
        draft_call_adapter(0x80061418u, object, (uint32)(sint32)(sint16)r_u16(r_u32(0x800A62ECu) + 60u));
        sub_8002289C(object);
    }
    if (type != 10)
        draft_call_adapter(0x8006DF90u, object + 20u);
    draft_call_adapter(0x80035A08u, sound, volume, 128u, object + 20u);
    if (sound == 0)
    {
        if (type == 8)
            sub_800623F8(object + 20u, r_u16(r_u32(0x800A62ECu) + 76u), 32768, 10);
        else if (type == 9)
        {
            size = 512;
            draft_call_adapter(0x8005F568u, object);
        }
        else if (type == 10)
            draft_call_adapter(0x8005EEC0u, object);
        else if (type == 7)
            draft_call_adapter(0x80060320u, object);
        if (type >= 7 && type <= 10)
            sub_8002289C(object);
        sub_8003CCE0(object + 20u, (uint32)(sint32)(sint16)r_u16(object + 58u));
    }
    index = r_u32(0x800A5770u);
    result = (sint32)index < 16;
    if (result)
    {
        address = 0x800A8828u + 16u * index;
        w_u32(address, r_u32(object + 20u));
        w_u32(address + 4u, r_u32(object + 24u));
        w_u32(address + 8u, r_u32(object + 28u));
        w_u32(address + 12u, size);
        result = index + 1u;
        w_u32(0x800A5770u, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002201C
uint32 sub_8002201C(uint32 dx, uint32 dz)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 x = (sint32)(r_u32(0x800A5648u) - dx), z = (sint32)(r_u32(0x800A564Cu) - dz), i, j, xx, zz, cell, old, world, row;
    uint32 localx, localz, previous, current, address;
    if (z < 0)
        z += 14;
    else if (z >= 14)
        z -= 14;
    w_u32(0x800A564Cu, (uint32)z);
    if (x < 0)
        x += 14;
    else if (x >= 14)
        x -= 14;
    w_u32(0x800A5648u, (uint32)x);
    zz = z;
    for (j = 0; j < 14; ++j)
    {
        if ((uint32)(j + (sint32)r_u32(0x800A5644u)) < 80u)
        {
            xx = x;
            for (i = 0; i < 14; ++i)
            {
                if ((uint32)(i + (sint32)r_u32(0x800A5640u)) < 80u)
                {
                    cell = 14 * zz + xx;
                    address = 0x800A9D78u + (uint32)cell * 12u;
                    old = (sint16)r_u16(address + 2u);
                    world = 80 * (j + (sint32)r_u32(0x800A5644u)) + (sint32)r_u32(0x800A5640u) + i;
                    row = old / 80;
                    localx = (uint32)(old - 80 * row) - r_u32(0x800A5640u);
                    localz = (uint32)row - r_u32(0x800A5644u);
                    previous = old == -1 || localx >= 14u || localz >= 14u ? 0u : r_u8(0x8008B794u + 14u * localz + localx);
                    row = world / 80;
                    localx = (uint32)(world % 80) - r_u32(0x800A5640u);
                    localz = (uint32)row - r_u32(0x800A5644u);
                    current = localx < 14u && localz < 14u ? r_u8(0x8008B794u + 14u * localz + localx) : 0u;
                    if (!previous && old != -1)
                    {
                        w_u32(address + 8u, 0);
                        if ((sint16)r_u16(address))
                        {
                            sub_80064D60(r_u32(address + 4u));
                            w_u16(address, 0);
                        }
                        w_u16(address + 2u, 0xffffu);
                    }
                    if (old != world && current)
                        sub_80021BB0((uint32)cell, (uint32)world);
                }
                if (++xx == 14)
                    xx = 0;
            }
        }
        if (++zz == 14)
            zz = 0;
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006C3D4
uint32 sub_8006C3D4(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(28u), category = scratch + 12u, previous = scratch + 16u, target, i, force = 819, result;
    sint32 age, dy, tick = (sint32)r_u32(0x800A9010u);
    if (!r_u8(object + 12u) || r_u16(object + 56u))
    {
        target = r_u32(object + 88u);
        if (target)
            w_u8(target + 15u, r_u8(target + 15u) - 1u);
        sub_80036CFC(object + 130u);
        return draft_scratch_result(native_stack_mark, (uint64)(r_u8(object + 12u) ? sub_8002A5DC(object, r_u16(object + 56u)) : sub_8002289C(object)));
    }
    if ((sint16)r_u16(object + 82u) >= 10)
    {
        force = 4096;
        if ((sint8)r_u8(object + 130u) == -1)
            sub_800369E0(object + 20u, object + 130u, 2048, 19);
    }
    for (i = 0; i < 12; i += 4)
        w_u32(scratch + i, r_u32(object + 20u + i));
    if ((sint8)r_u8(object + 84u) >= 0)
    {
        w_u8(object + 84u, r_u8(object + 84u) - (uint32)tick);
        if ((sint8)r_u8(object + 84u) < 0)
        {
            target = r_u32(object + 88u);
            if (target)
                w_u8(target + 15u, r_u8(target + 15u) - 1u);
            target = sub_8006BD08(object + 20u, r_u16(object + 76u), r_u16(object + 72u), r_u8(r_u32(object + 16u) + 13u), category);
            w_u32(object + 88u, target);
            if (target)
                w_u8(target + 15u, r_u8(target + 15u) + 1u);
            else
                w_u8(object + 84u, (sub_80069A50() & 31u) + 10u);
        }
    }
    target = r_u32(object + 88u);
    if (target)
        sub_8006B410(object, target + 20u, 122880, force);
    else
        sub_8006BA1C(object, 122880, force);
    dy = draft12_abs((sint32)(r_u32(scratch + 4u) - r_u32(object + 24u)));
    age = dy > (tick << 7) ? 1200 : (sint16)(r_u16(object + 82u) + (uint32)tick);
    w_u16(object + 82u, (uint32)age);
    for (i = 0; i < 12; i += 4)
        w_u32(previous + i, r_u32(scratch + i));
    if ((sub_8002F3FC(previous, object + 20u) << 16) || (sub_80030678(previous, object + 20u) << 16) || (sint16)r_u16(object + 82u) >= 1200)
        sub_8002A8F0(object);
    // TODO Bind original angle matrix target
    draft_call_adapter(0x80054D38u, r_u32(object + 76u), r_u16(object + 72u) + 2048u, 0u, object + 36u);
    sub_80029970(object, 136, 6, 1, scratch);
    result = sub_800620A4(object, object + 92u, object + 20u, scratch, r_u16(r_u32(0x800A62ECu) + 66u), 150, 100, r_u8(object + 13u));
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002B224
uint32 sub_8002B224(uint32 object, uint32 ignored, uint32 flags, uint32 motion, uint32 parameter, uint32 callback)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 kind = r_u16(object + 56u), state, angles = draft_scratch_adapter(20u), i, result;
    sint32 tilt, sign = 0, speed = 40;
    if (kind == 13)
    {
        for (i = 0; i < 12; i += 4)
            w_u32(angles + 8u + i, r_u32(motion + i));
        // TODO Bind original indirect object motion callback
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(r_u32(r_u32(object + 16u) + 24u), object, angles + 8u)));
    }
    if (kind == 11)
    {
        tilt = (sint16)r_u16(object + 44u);
        sign = tilt >= 3969 ? 1 : (tilt < -3968 ? -1 : 0);
        if (!sign)
        {
            if (flags & 0x410u)
            {
                // TODO Bind original distance target
                speed = (sint32)draft_call_adapter(0x80069BE0u, (uint32)((sint32)r_u32(motion) >> 15), (uint32)((sint32)r_u32(motion + 8u) >> 15));
                if (flags & 16u)
                    speed = -speed;
            }
            // TODO Bind original motion and response targets
            draft_call_adapter(0x80052B28u, object, 0u, (uint32)(sint32)(sint16)speed, (uint32)(sint32)(sint16)r_u16(motion + 2u), (uint32)(sint32)(sint16)r_u16(motion + 10u));
            return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80052C58u, object)));
        }
    }
    else if (kind != 12)
    {
        speed = (sint32)draft_call_adapter(0x80069BE0u, (uint32)((sint32)r_u32(motion) >> 15), (uint32)((sint32)r_u32(motion + 8u) >> 15));
        if (flags & 0x410u)
        {
            if (flags & 16u)
                speed = -speed;
            draft_call_adapter(0x80052B28u, object, 0u, (uint32)(sint32)(sint16)speed, (uint32)(sint32)(sint16)r_u16(motion + 2u), (uint32)(sint32)(sint16)r_u16(motion + 10u));
            return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80052C78u, object)));
        }
        if (kind == 14)
            goto existing;
    }
    if (kind != 12 && kind != 14)
    {
        state = r_u32(object + 60u);
        if (state)
            sub_80064D60(state);
        // TODO Bind original allocation target
        state = (uint32)draft_call_adapter(0x80064B04u, 92u);
        w_u32(object + 60u, state);
        sub_800540E0(object, kind == 11 ? 12u : 14u);
        for (i = 0; i < 4; ++i)
        {
            uint32 s = state + i * 16u;
            w_u16(s + 8u, 8191);
            w_u16(s + 6u, 0);
            w_u16(s, r_u16(object + 24u));
            w_u16(s + 2u, r_u16(object + 24u));
            w_u16(s + 4u, r_u16(object + 24u));
            w_u32(s + 12u, r_u32(s + 12u) & 0xf0000000u);
            w_u32(s + 8u, r_u32(s + 8u) & 0xfff0ffffu);
        }
        w_u8(state + 67u, 1);
        w_u8(state + 66u, 0);
        w_u16(state + 64u, r_u16(object + 24u));
        w_u32(state + 68u, r_u32(object + 24u));
        sub_8005536C(object + 36u, kind == 11 && sign != 1 ? 17u : 12u, angles);
        w_u16(state + 84u, r_u16(angles));
        w_u16(state + 82u, (r_u16(angles + 2u) & 4095u) - 1025u < 2047u ? 2048u : 0u);
        w_u16(state + 86u, (r_u16(angles + 4u) & 4095u) - 1025u < 2047u ? 2048u : 0u);
        goto apply;
    }
existing:
    state = r_u32(object + 60u);
apply:
    w_u32(state + 72u, r_u32(motion));
    w_u32(state + 76u, r_u32(motion + 8u));
    w_u16(state + 80u, 0);
    // TODO Bind original indirect response callback
    result = (uint32)draft_call_adapter(callback, state, (uint32)(sint32)(sint16)flags, parameter);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006FCB4
uint32 sub_8006FCB4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 menu = r_u32(0x80091EE0u + 12u * r_u32(0x800A645Cu)), entry = menu + 16u * r_u32(0x800A6460u), value = entry + 14u, type = r_u16(entry + 12u), toggle = 0, address = 0, result, old;
    sint32 setting = (sint16)r_u16(value);
    switch (type)
    {
        case 1:
            return draft_scratch_result(native_stack_mark, (uint64)(sub_800702D4()));
        case 2:
            return draft_scratch_result(native_stack_mark, (uint64)(sub_800703B4()));
        case 3:
            sub_8007040C();
            break;
        case 4:
            sub_8007040C();
            w_u16(0x800A967Cu, 1);
            break;
        case 5:
            sub_8007040C();
            w_u32(0x800A9D74u, 1);
            break;
        case 6:
            sub_8007040C();
            w_u32(0x800A84DCu, 1);
            break;
        case 7:
            address = 0x800A5628u;
            toggle = 1;
            break;
        case 8:
            address = 0x800A8540u;
            toggle = 1;
            break;
        case 9:
            address = 0x800A6450u;
            toggle = 1;
            break;
        // TODO Bind original menu action boundaries
        case 10:
            draft_call_adapter(0x8003D13Cu);
            break;
        case 11:
            sub_8003D6B8(5);
            break;
        case 12:
            w_u32(0x800A7C6Cu, 99999);
            break;
        case 13:
            w_u8(0x800A9872u, 1);
            w_u8(0x800A9878u, 1);
            w_u16(0x800A906Au, 1);
            w_u16(0x800A906Cu, 1);
            break;
        case 14:
            if (r_u32(0x800A7E18u))
                w_u16(0x800A60ACu, 60);
            if (r_u16(0x800A60A8u))
                w_u16(0x800A60AAu, 60);
            break;
        case 15:
            w_u32(0x800A644Cu, 1u - (uint32)setting);
            w_u16(value, r_u16(value) ^ 1u);
            w_u8(0x800A7E84u, 0);
            w_u16(0x800A8530u, 0);
            break;
        case 16:
            address = 0x800A5694u;
            toggle = 1;
            break;
        case 17:
            address = 0x800A6358u;
            toggle = 1;
            break;
        case 18:
            w_u32(0x800A9680u, 1);
            draft_call_adapter(0x80035A08u, 50u, 2048u, 192u, 0u);
            menu = r_u32(0x80091EE0u + 12u * r_u32(0x800A645Cu));
            w_u32(0x800A854Cu, (uint32)(sint32)(sint16)r_u16(menu + 16u * r_u32(0x800A6460u) + 14u));
            sub_8007040C();
            // TODO Preserve original undefined V0 from void menu setter
            return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8007040Cu)));
        case 19:
            return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80035A08u, 2u, 2048u, 255u, 0u)));
        case 20:
            w_u32(0x800A5C50u, 1);
            if (r_u32(0x800A6464u) == 1u || r_u32(0x800A6464u) == 5u)
            {
                old = r_u16(0x800A9D6Cu);
                w_u16(0x800A9D6Cu, (uint32)((sint32)r_u32(0x800A975Cu) >> 2));
                draft_call_adapter(0x80035A08u, (uint32)(sint32)(sint16)(r_u16(0x800A6470u) + 64u), 2048u, 255u, 0u);
                w_u16(0x800A9D6Cu, old);
                result = 1u - r_u16(0x800A6470u);
                w_u16(0x800A6470u, result);
                return draft_scratch_result(native_stack_mark, (uint64)(result));
            }
            sub_80036FE4();
            draft_call_adapter(0x800371C4u, 496u);
            break;
        case 21:
            w_u32(0x800A5C50u, 1);
            if (r_u32(0x800A6464u) == 1u || r_u32(0x800A6464u) == 5u)
                draft_call_adapter(0x80037B3Cu);
            break;
        case 22:
            w_u32(0x800A9CD0u, 16384);
            w_u16(menu + 14u, 32);
            menu = r_u32(0x80091EE0u + 12u * r_u32(0x800A645Cu));
            w_u16(menu + 30u, 16);
            menu = r_u32(0x80091EE0u + 12u * r_u32(0x800A645Cu));
            w_u16(menu + 46u, 48);
            sub_80036EDC(16384);
            w_u16(0x800A9D6Cu, 4096);
            draft_call_adapter(0x80036E9Cu, 4096u);
            w_u32(0x800A975Cu, 24576);
            break;
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 33:
        {
            uint32 modes[5] = {5, 3, 2, 1, 4};
            sub_8007040C();
            w_u32(0x800A7F0Cu, type == 33 ? 7u : modes[type - 23u]);
            break;
        }
        case 28:
            draft_call_adapter(0x80029538u, (uint32)(sint32)(sint16)r_u16(0x80091778u + (uint32)setting * 2u));
            return draft_scratch_result(native_stack_mark, (uint64)(sub_800703B4()));
        case 29:
            w_u32(0x800A7BF8u, 1);
            sub_8007040C();
            return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8007040Cu)));
        case 30:
            draft_call_adapter(0x80076FF4u, (uint32)setting);
            return draft_scratch_result(native_stack_mark, (uint64)(sub_800703B4()));
        case 31:
            draft_call_adapter(0x80076FE8u, (uint32)setting);
            return draft_scratch_result(native_stack_mark, (uint64)(sub_800703B4()));
        case 32:
            draft_call_adapter(0x80077000u, (uint32)setting);
            return draft_scratch_result(native_stack_mark, (uint64)(sub_800703B4()));
        case 34:
            address = 0x800A8660u;
            toggle = 1;
            break;
        case 35:
            sub_8007040C();
            w_u32(0x800A9344u, 1);
            break;
        case 37:
            address = 0x800A7FB0u;
            toggle = 1;
            break;
        case 38:
            w_u16(0x800A6458u, 0);
            w_u16(0x800A645Au, 0);
            break;
        case 39:
            result = sub_800389DC();
            menu = r_u32(0x80091F64u);
            w_u16(menu + 14u, (sint16)result == 2 ? 18u : 20u);
            draft_call_adapter((sint16)result == 2 ? 0x8006F690u : 0x8006F6BCu);
            break;
        default:
            // TODO Preserve original jump-table V0 on unhandled menu actions
            return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8006FCB4u, type)));
    }
    if (toggle)
    {
        w_u32(address, 1u - (uint32)setting);
        w_u16(value, r_u16(value) ^ 1u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80035A08u, 39u, 2048u, 255u, 0u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800538EC
uint32 sub_800538EC(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(236u), previous = scratch, original = scratch + 12u, heights = scratch + 24u, offsets = scratch + 32u, tags = scratch + 96u, intersections = scratch + 112u, matrix = scratch + 208u, state, model, height_address, i, count, stable = 0, result;
    sint32 speed, pitch, roll, yaw, coefficient;
    if (r_u8(object + 12u) < 2u || (r_u16(object + 56u) == 11u && (sint32)r_u32(object + 80u) <= 0 && r_u8(object + 90u) != 7u))
    {
        sub_80064D60(r_u32(object + 60u));
        w_u32(object + 60u, 0);
        return draft_scratch_result(native_stack_mark, (uint64)(sub_80056364(object)));
    }
    model = r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
    height_address = r_u32(0x800A90ACu) + 40u * model + 32u;
    if (r_u16(object + 56u) == 11u)
    {
        sub_80029970(object, r_u16(height_address), 1, 1, object + 20u);
        result = r_u32(object + 80u) - r_u32(0x800A9010u);
        w_u32(object + 80u, result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    for (i = 0; i < 12; i += 4)
    {
        w_u32(original + i, r_u32(object + 20u + i));
        w_u32(previous + i, r_u32(object + 20u + i));
    }
    state = r_u32(object + 60u);
    coefficient = (sint32)r_u32(0x800A63D8u) >> 8;
    w_u32(object + 20u, r_u32(object + 20u) + (uint32)((((sint16)r_u16(state + 74u) << 8) * coefficient) >> 16));
    w_u32(object + 28u, r_u32(object + 28u) + (uint32)((((sint16)r_u16(state + 78u) << 8) * coefficient) >> 16));
    // TODO Bind original speed target
    speed = (sint32)((uint32)draft_call_adapter(0x80069BE0u, (uint32)((sint32)r_u32(state + 72u) >> 8), (uint32)((sint32)r_u32(state + 76u) >> 8)) << 8);
    sub_80029DDC(object, offsets, model);
    count = (uint32)(sint32)(sint16)sub_80030040(intersections, previous, object + 20u, offsets);
    if (count)
    {
        if (speed > 655360)
        {
            // TODO Bind original collision correction target
            draft_call_adapter(0x80023228u, object + 20u, intersections, offsets, 1u, (uint32)speed);
        }
        state = r_u32(object + 60u);
        draft_call_adapter(0x80023918u, r_u32(intersections + 12u * count - 12u), r_u32(intersections + 12u * count - 4u), state + 72u, state + 76u);
    }
    state = r_u32(object + 60u);
    w_u16(state + 80u, (uint32)(3625 * (sint16)r_u16(state + 80u)) >> 12);
    sub_8002FC90(object, tags, offsets, 0);
    sub_800283D4(object, r_u32(object + 60u), tags);
    sub_800287B4(object, r_u32(object + 60u), (uint32)speed, heights);
    if (sub_80025874(6, tags, 0) << 16)
    {
        // TODO Bind original suspension correction target
        draft_call_adapter(0x80053890u, object, r_u32(object + 60u));
    }
    pitch = (sint16)sub_80055A9C(0, (uint32)(sint32)(sint16)r_u16(height_address + 2u));
    roll = (sint16)sub_80055A9C(0, (uint32)(sint32)(sint16)r_u16(height_address + 4u));
    state = r_u32(object + 60u);
    if ((sint16)r_u16(object + 44u) >= 0)
    {
        w_u32(state + 72u, (uint32)(226 * ((sint32)r_u32(state + 72u) >> 8)));
        w_u32(state + 76u, (uint32)(226 * ((sint32)r_u32(state + 76u) >> 8)));
        w_u16(state + 80u, (uint32)(3625 * (sint16)r_u16(state + 80u)) >> 12);
        w_u16(state + 84u, r_u16(state + 84u) + r_u16(state + 80u));
    }
    else
    {
        w_u32(state + 72u, (uint32)(242 * ((sint32)r_u32(state + 72u) >> 8)));
        w_u32(state + 76u, (uint32)(242 * ((sint32)r_u32(state + 76u) >> 8)));
        w_u16(state + 80u, (uint32)(125 * (sint16)r_u16(state + 80u)) >> 7);
        w_u16(state + 84u, r_u16(state + 84u) - r_u16(state + 80u));
        pitch = (sint16)-pitch;
    }
    // TODO Bind original angle matrix target
    draft_call_adapter(0x80054D38u, (uint32)pitch, 0u, (uint32)roll, object + 36u);
    state = r_u32(object + 60u);
    pitch = (sint16)r_u16(state + 82u);
    roll = (sint16)r_u16(state + 86u);
    yaw = (sint16)r_u16(state + 84u);
    draft_call_adapter(0x80054D38u, (uint32)pitch, (uint32)yaw, (uint32)roll, matrix);
    sub_80031B20(matrix, object + 36u, object + 36u);
    if (speed < 16384)
    {
        state = r_u32(object + 60u);
        w_u32(state + 72u, 0);
        w_u32(state + 76u, 0);
        w_u16(state + 80u, 0);
    }
    sub_80029970(object, r_u16(height_address), 1, 1, original);
    for (i = 0; i < 4; ++i)
    {
        state = r_u32(object + 60u) + 16u * i;
        if (r_u16(state) == r_u16(state + 2u) && (r_u16(state + 10u) & 15u) == 0)
            ++stable;
    }
    result = stable << 16;
    if (speed < 16384)
    {
        result = (uint32)(sint32)(sint16)stable;
        if (stable == 4)
        {
            state = r_u32(object + 60u);
            count = r_u32(state + 88u);
            result = count - 1u;
            if (count)
                w_u32(state + 88u, result);
            else if (r_u16(object + 56u) == 12u)
            {
                result = (sub_80069A50() % 30u + 30u) * r_u32(0x800A56C0u);
                w_u16(object + 56u, 11);
                w_u32(object + 16u, 0x80090B38u);
                w_u32(object + 80u, result);
            }
            else
            {
                sub_80064D60(state);
                w_u32(object + 60u, 0);
                return draft_scratch_result(native_stack_mark, (uint64)(sub_8005780C(object, 0, (uint32)(sint32)(sint16)(yaw - 2048))));
            }
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
