#include "draft_signatures.h"
#include <stdlib.h>

// FUNCTION_MARKER sub_800376C0
void sub_800376C0(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    w_u32(0x800A87F0u, 0u);
    w_u32(0x800A9A3Cu, 0u);

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800389DC
uint32 sub_800389DC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    return draft_scratch_result(native_stack_mark, (uint64)((uint32)(int32)(int16)r_u16(0x800A6D64u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800577F4
void sub_800577F4(uint32 enabled)
{
    uint32 native_stack_mark = draft_scratch_mark();

    if (!enabled)
    {
        w_u32(0x800A70A0u, 0u);
        w_u32(0x800A7098u, 0u);
    }

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005E7DC
uint32 sub_8005E7DC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 height = r_u32(0x800A84E8u) - 560u;
    w_u32(0x800A9034u, 0u);
    w_u32(0x800A903Cu, 0u);
    w_u32(0x800A9038u, height);
    return draft_scratch_result(native_stack_mark, (uint64)(height));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005E198
uint32 sub_8005E198(uint32 mode)
{
    uint32 native_stack_mark = draft_scratch_mark();

    if (!r_u8(0x800A7E84u))
    {
        w_u8(0x800A7E82u, 1u);
        w_u8(0x800A7E83u, (uint8)mode);
        w_u8(0x800A7E80u, (uint8)mode);
    }
    else if (!r_u8(0x800A7E83u))
    {
        w_u8(0x800A7E82u, 1u);
        w_u8(0x800A7E83u, 1u);
        w_u8(0x800A7E80u, 1u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005E258
uint32 sub_8005E258(uint32 mode)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 current;
    if ((int32)mode < 0)
        mode = 0u;
    if ((int32)mode >= 4)
        mode = 3u;
    current = r_u8(0x800A7E83u);
    if (current == mode)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    if (current < mode)
        return draft_scratch_result(native_stack_mark, (uint64)(sub_8005E198(mode)));
    // TODO Bind the decreasing camera-mode helper
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8005E200u, mode)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002062C
uint32 sub_8002062C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 direction = (r_u8(0x800A7BDEu) & 1u) ? 0xFFFFFFFFu : 1u;
    uint32 result = sub_8002066C(direction);
    w_u8(0x800A7BDFu, (uint8)result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80020E30
uint32 sub_80020E30(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sub_80020E68(0x800A8FE0u, r_u16(0x800A7E7Eu));
    // TODO Bind the terrain visibility helper
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800643ECu)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005BEEC
uint32 sub_8005BEEC(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 y = r_u32(object + 132u);
    // TODO Bind the integer vector-length helper
    uint32 result = (uint32)draft_call_adapter(0x80069BE0u, r_u32(object + 128u), r_u32(object + 136u));
    result = (uint32)draft_call_adapter(0x80069BE0u, result, y);
    w_u16(object + 124u, (uint16)result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005B6B4
uint32 sub_8005B6B4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = (uint32)(int32)(int16)r_u16(0x800A9468u);
    int32 desired = (int16)r_u16(0x800A946Au);
    if ((int32)result != desired)
    {
        // TODO Bind the existing reverb state helpers
        draft_call_adapter(desired ? 0x80035FD8u : 0x800360BCu);
        result = r_u16(0x800A946Au);
        w_u16(0x800A9468u, (uint16)result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800227C4
uint32 sub_800227C4(uint32 size)
{
    uint32 native_stack_mark = draft_scratch_mark();

    // TODO Bind the existing allocator
    uint32 object = (uint32)draft_call_adapter(0x80064B04u, size);
    uint32 tail;
    w_u8(object + 15u, 0u);
    w_u8(object + 14u, 5u);
    tail = r_u32(0x800A567Cu);
    if (tail)
        w_u32(tail + 4u, object);
    else
        w_u32(0x800A5678u, object);
    w_u32(0x800A567Cu, object);
    w_u32(object + 4u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(object));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80021F80
uint32 sub_80021F80(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i;
    for (i = 0; i < 196u; ++i)
    {
        uint32 cell = 0x800A9D78u + 12u * i;
        w_u32(cell + 8u, 0u);
        if (r_u16(cell))
        {
            // TODO Bind the existing deallocator
            draft_call_adapter(0x80064D60u, r_u32(cell + 4u));
            w_u16(cell, 0u);
            w_u16(cell + 2u, 0xFFFFu);
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800698C8
uint32 sub_800698C8(uint32 destination, uint64 value)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 remaining = (int32)(uint32)(value >> 16);
    uint32 i;
    for (i = 0; i < 3u; ++i)
    {
        int32 divisor = (int32)r_u32(0x8009116Cu + 4u * i);
        if (!divisor || (divisor == -1 && remaining == (-2147483647 - 1)))
            abort();
        w_u32(destination + 4u * i, (uint32)(remaining / divisor));
        divisor = (int32)r_u32(0x8009116Cu + 4u * i);
        if (!divisor || (divisor == -1 && remaining == (-2147483647 - 1)))
            abort();
        remaining %= divisor;
    }
    w_u32(destination + 12u, (uint32)remaining);
    return draft_scratch_result(native_stack_mark, (uint64)(destination + 12u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80057528
uint32 sub_80057528(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 count = r_u32(0x800A7098u);
    uint32 result;
    if (count)
    {
        uint32 threshold = (uint32)((int32)(((count << 3) & 0x7FFu) * ((uint32)r_u8(0x80090B83u + r_u32(0x800A854Cu)) << 8)) >> 16);
        if (r_u32(0x800A6228u) < threshold)
        {
            // TODO Bind the existing random-number helper
            uint32 random1 = (uint32)draft_call_adapter(0x80069A50u) & 0xFFFFu;
            uint32 random2 = (uint32)draft_call_adapter(0x80069A50u) & 0x3FFu;
            uint32 divisor;
            count = r_u32(0x800A7098u);
            if (!count)
                abort();
            divisor = 1024u / count;
            if (!divisor)
                abort();
            // TODO Bind the existing spawn helper
            if (!draft_call_adapter(0x800570DCu, r_u16(0x800A7018u + 2u * (random2 / divisor)), r_u16(0x800A6230u + 2u * (random1 % 19u))))
                w_u32(0x800A6228u, r_u32(0x800A6228u) + 1u);
        }
    }
    w_u32(0x800A709Cu, r_u32(0x800A709Cu) + r_u32(0x800A9010u));
    if (r_u32(0x800A5F18u) < 10u && !sub_80041710())
        w_u32(0x800A5F18u, r_u32(0x800A5F18u) + 1u);
    result = r_u32(0x800A6138u);
    w_u32(0x800A6138u, 0u);
    w_u32(0x800A613Cu, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

static int32 draft0_div(int32 numerator, int32 denominator)
{
    if (!denominator || (denominator == -1 && numerator == (-2147483647 - 1)))
        abort();
    return numerator / denominator;
}

// FUNCTION_MARKER sub_80055A9C
uint32 sub_80055A9C(uint32 x, uint32 z)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 a = (int32)x, b = (int32)z, index, value;
    if (b > 0)
    {
        if (a > 0)
        {
            index = a >= b ? 1024 - draft0_div((int32)(z << 9), a) : draft0_div((int32)(x << 9), b);
            return draft_scratch_result(native_stack_mark, (uint64)((uint32)(int32)(int16)r_u16(0x80012AE0u + 2u * (uint32)index)));
        }
        if ((int32)(0u - x) >= b)
        {
            index = draft0_div((int32)(z << 9), a);
            return draft_scratch_result(native_stack_mark, (uint64)(0u - (uint32)(int32)(int16)r_u16(0x800132E0u + 2u * (uint32)index)));
        }
        index = draft0_div((int32)(0u - (x << 9)), b);
        return draft_scratch_result(native_stack_mark, (uint64)(0u - (uint32)(int32)(int16)r_u16(0x80012AE0u + 2u * (uint32)index)));
    }
    if (a > 0)
    {
        if (a >= (int32)(0u - z))
        {
            index = draft0_div((int32)(z << 9), a);
            value = (int16)r_u16(0x800132E0u + 2u * (uint32)index);
        }
        else
        {
            index = draft0_div((int32)(0u - (x << 9)), b);
            value = (int16)r_u16(0x80012AE0u + 2u * (uint32)index);
        }
        return draft_scratch_result(native_stack_mark, (uint64)(2048u - (uint32)value));
    }
    if (!(x | z))
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    index = b < a ? draft0_div((int32)(x << 9), b) : 1024 - draft0_div((int32)(z << 9), a);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)(int32)(int16)r_u16(0x80012AE0u + 2u * (uint32)index) - 2048u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005C194
uint32 sub_8005C194(uint32 position, uint32 target, uint32 distance)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 angle = sub_80055A9C((uint32)((int16)r_u16(target + 2u) - (int16)r_u16(position + 2u)), (uint32)((int16)r_u16(target + 4u) - (int16)r_u16(position + 4u))) & 0xFFFu;
    uint32 scale = (uint32)((int32)r_u32(0x800A63D8u) >> 8);
    uint32 product = distance * (uint32)(int32)(int16)r_u16(0x800102E0u + 2u * angle);
    uint32 delta;
    product = (uint32)((int32)product >> 12) << 16;
    product = (uint32)((int32)product >> 8) * scale;
    delta = (uint32)((int32)product >> 16);
    w_u16(position + 2u, (uint16)(r_u16(position + 2u) + delta));
    product = distance * (uint32)(int32)(int16)r_u16(0x80010AE0u + 2u * angle);
    product = (uint32)((int32)product >> 12) << 16;
    product = (uint32)((int32)product >> 8) * scale;
    delta = (uint32)((int32)product >> 16);
    w_u16(position + 4u, (uint16)(r_u16(position + 4u) + delta));
    return draft_scratch_result(native_stack_mark, (uint64)(delta));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800219E8
uint32 sub_800219E8(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 counts[4], i, column = r_u32(0x800A5648u), row = r_u32(0x800A564Cu);
    uint32 dx = r_u32(0x800A5650u) - r_u32(0x800A6784u);
    uint32 dz = r_u32(0x800A5658u) - r_u32(0x800A678Cu);
    int32 threshold = (int32)r_u32(0x800A5664u), tile;
    for (i = 0; i < 4u; ++i)
        counts[i] = r_u32(0x800A6370u + 4u * i);
    for (tile = 195; tile >= 0; --tile)
    {
        uint32 cell = 0x800A9D78u + 12u * (column + 14u * row);
        int32 count = (int16)r_u16(cell);
        uint32 entries = r_u32(cell + 4u);
        while (--count >= 0)
        {
            uint32 entry = entries + 16u * (uint32)count;
            w_u32(entry + 4u, r_u32(entry + 4u) + dx);
            w_u32(entry + 12u, r_u32(entry + 12u) + dz);
            if ((int8)r_u8(0x8008B794u + (uint32)tile) >= threshold)
            {
                uint32 category = r_u8(entry + 3u);
                // TODO Original category is expected to select one of four lists
                if (category >= 4u)
                    abort();
                w_u32(r_u32(0x800A6380u + 4u * category) + 4u * counts[category], entry);
                ++counts[category];
            }
        }
        if (++column == 14u)
            column = 0u;
        if (column == r_u32(0x800A5648u) && ++row == 14u)
            row = 0u;
    }
    for (i = 0; i < 4u; ++i)
        w_u32(0x800A6370u + 4u * i, counts[i]);
    return draft_scratch_result(native_stack_mark, (uint64)(counts[0]));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800374BC
uint32 sub_800374BC(uint32 index)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 location = r_u32(0x800A9058u), i;
    uint32 position = draft_scratch_adapter(8u);
    w_u8(0x800A9A40u, 1u);
    w_u8(0x800A9A41u, (uint8)index);
    w_u32(0x800A9308u, location);
    w_u32(0x800A7FA8u, location);
    w_u32(0x800A7EE0u, location + (uint32)(int32)(int16)r_u16(0x800A5C3Cu + 2u * index));
    // TODO Bind CD position and control calls
    draft_call_adapter(0x8007B7B4u, location, position);
    for (i = 0; i < 10u; ++i)
    {
        uint32 status = (uint32)draft_call_adapter(0x8007B4A0u, 13u, 0x800A9A40u);
        w_u32(0x800A7BE0u, status);
        if (status == 1u)
            break;
        draft_call_adapter(0x8007F8C8u, 3u);
    }
    for (i = 0; i < 10u; ++i)
    {
        uint32 status = (uint32)draft_call_adapter(0x8007B368u, 6u, position, 0u);
        w_u32(0x800A7BE0u, status);
        if (status == 1u)
            break;
        draft_call_adapter(0x8007F8C8u, 3u);
    }
    w_u32(0x800A5C60u, 0u);
    w_u32(0x800A966Cu, 60u);
    return draft_scratch_result(native_stack_mark, (uint64)(60u));

    draft_scratch_release(native_stack_mark);
}

static uint32 draft0_terrain_flags(uint32 position)
{
    uint32 x = r_u32(position), y = r_u32(position + 4u), z = r_u32(position + 8u);
    uint32 cell = (uint32)((int32)z >> 12) * 80u + (uint32)((int32)x >> 12);
    uint32 layer = r_u16(r_u32(0x800A84F8u) + 8u * cell + 4u);
    uint32 heights = r_u32(0x800A869Cu), list;
    for (;;)
    {
        uint32 height = r_u16(heights + 2u * layer);
        if ((int32)(0u - y) >= (int32)(2u * (height & 0x7FFFu)))
            break;
        if (height & 0x8000u)
            break;
        layer += 3u;
    }
    list = r_u16(heights + 2u * layer + 4u);
    if (list == 0xFFFFu)
        return 0u;
    list = r_u32(0x800A9CE4u) + 2u * list;
    for (;;)
    {
        uint32 tag = r_u16(list), polygon = r_u32(0x800A9CE8u) + 28u * (tag & 0x7FFFu);
        uint32 bx = x & 0xFFFFF000u, bz = z & 0xFFFFF000u;
        uint32 x0 = bx + (uint32)(int32)(int16)r_u16(polygon);
        uint32 z0 = bz + (uint32)(int32)(int16)r_u16(polygon + 4u);
        uint32 x1 = bx + (uint32)(int32)(int16)r_u16(polygon + 6u);
        uint32 z1 = bz + (uint32)(int32)(int16)r_u16(polygon + 8u);
        uint32 x2 = bx + (uint32)(int32)(int16)r_u16(polygon + 10u);
        uint32 z2 = bz + (uint32)(int32)(int16)r_u16(polygon + 12u);
        uint32 x3 = bx + (uint32)(int32)(int16)r_u16(polygon + 14u);
        uint32 z3 = bz + (uint32)(int32)(int16)r_u16(polygon + 16u);
        if ((int32)((z0 - z1) * (x - x1) + (x1 - x0) * (z - z1)) >= 0 && (int32)((z1 - z2) * (x - x2) + (x2 - x1) * (z - z2)) >= 0 && (int32)((z2 - z3) * (x - x3) + (x3 - x2) * (z - z3)) >= 0 && (int32)((z3 - z0) * (x - x0) + (x0 - x3) * (z - z0)) >= 0)
            return r_u16(polygon + 24u);
        if (tag & 0x8000u)
            return 0u;
        list += 2u;
    }
}

// FUNCTION_MARKER sub_80030214
uint32 sub_80030214(uint32 first_position, uint32 second_position)
{
    uint32 native_stack_mark = draft_scratch_mark();

    return draft_scratch_result(native_stack_mark, (uint64)((draft0_terrain_flags(first_position) >> 14) | ((draft0_terrain_flags(second_position) & 0x4000u) >> 13)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005C074
uint32 sub_8005C074(uint32 object, uint32 angle, uint32 position, uint32 mode)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(52u), i;
    uint32 matrix = temporary, target = temporary + 32u, old_position = temporary + 40u;
    for (i = 0; i < 3u; ++i)
        w_u32(old_position + 4u * i, r_u32(0x800A7EE4u + 4u * i));
    // TODO Bind angular interpolation
    w_u16(object + 40u, (uint16)draft_call_adapter(0x80055764u, (uint32)(int32)(int16)r_u16(object + 40u), (uint32)(int32)(int16)angle, 20u));
    w_u32(target, r_u32(object + 12u));
    w_u32(target + 4u, r_u32(object + 16u));
    sub_8005B9A0(matrix, position, target, (uint32)(sint32)(sint16)r_u16(object + 40u), object);
    for (i = 0; i < 3u; ++i)
        w_u32(0x800A7EE4u + 4u * i, r_u32(object + 4u * i));
    w_u32(0x800A7EE8u, sub_8005BA08(r_u32(0x800A7EE8u)));
    w_u32(object + 4u, r_u32(0x800A7EE8u));
    sub_8005BD4C(position, 0x800A7EE4u, old_position, object, matrix, (uint32)(int32)(int16)r_u16(object + 40u), mode);
    w_u32(0x800A84E8u, r_u32(0x800A7EE8u));
    // TODO Bind camera finalization helper
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8005B70Cu, position)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005C5A4
uint32 sub_8005C5A4(uint32 object, uint32 position, uint32 angle)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 state = r_u8(object + 48u), temporary, flags, i;
    switch (state)
    {
        case 0:
            temporary = draft_scratch_adapter(12u);
            for (i = 0; i < 3u; ++i)
                w_u32(temporary + 4u * i, r_u32(0x800A7EE4u + 4u * i));
            w_u32(object + 20u, r_u32(object + 12u));
            w_u32(object + 24u, r_u32(object + 16u));
            if (sub_80030214(position, temporary) & 3u)
                w_u8(object + 48u, 1u);
            break;
        case 1:
            flags = r_u8(object + 47u);
            w_u8(object + 49u, (uint8)flags);
            if (flags >= 2u)
            {
                w_u32(object + 20u, r_u32(object + 12u));
                w_u32(object + 24u, r_u32(object + 16u));
                flags = r_u8(object + 50u);
                w_u8(object + 46u, 1u);
                w_u8(object + 126u, 1u);
                w_u16(object + 38u, 10000u);
                w_u8(object + 44u, (uint8)flags);
                w_u8(object + 45u, (uint8)flags);
                w_u8(object + 47u, (uint8)flags);
                w_u8(object + 47u, (uint8)flags);
            }
            // TODO Bind camera transition helper
            draft_call_adapter(0x8005B694u, 1u);
            w_u8(object + 48u, 2u);
            break;
        case 2:
        case 3:
        case 4:
            temporary = draft_scratch_adapter(44u);
            if (state == 2u)
                w_u8(object + 126u, 0u);
            sub_8005B9A0(temporary + 12u, position, (int16)r_u16(object + 16u) >= (int16)r_u16(object + 24u) ? object + 12u : object + 20u, (uint32)(int32)(int16)angle, temporary);
            w_u32(temporary + 4u, r_u32(position + 4u));
            if (state == 3u && r_u32(0x800A9A38u) == 4u)
                break;
            flags = sub_80030214(position, temporary) & 3u;
            if (state == 2u)
            {
                if (flags == 3u)
                    w_u8(object + 48u, 3u);
                if (!flags && r_u32(0x800A9A38u) != 4u)
                    w_u8(object + 48u, 5u);
            }
            else if (state == 3u)
            {
                if (flags == 2u)
                    w_u8(object + 48u, 4u);
                if (flags == 1u)
                    w_u8(object + 48u, 2u);
                if (!flags)
                    w_u8(object + 48u, 5u);
            }
            else
            {
                if (!flags)
                    w_u8(object + 48u, 5u);
                if (flags == 3u)
                    w_u8(object + 48u, 3u);
            }
            break;
        case 5:
            w_u8(object + 48u, 0u);
            draft_call_adapter(0x8005B694u, 0u);
            flags = r_u8(object + 49u);
            w_u16(object + 38u, 50u);
            if (flags >= 2u)
                sub_8005E258(flags);
            break;
        default:
            break;
    }
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8005B6B4()));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80063904
uint32 sub_80063904(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 owner = r_u32(object + 8u), result = sub_80063824(owner, object);
    uint32 temporary, terrain, angle, matrix, points;
    if (result)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    if (!(r_u8(owner + 14u) & 2u))
    {
        result = r_u8(object + 14u) & 0xFDu;
        w_u8(object + 14u, (uint8)result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    w_u8(object + 14u, (uint8)(r_u8(object + 14u) | 2u));
    if ((int32)r_u32(0x800A86A0u) <= 0)
    {
        // TODO Bind existing object-position update
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8002289Cu, object)));
    }
    temporary = draft_scratch_adapter(112u);
    points = temporary + 24u;
    matrix = temporary + 80u;
    // TODO Bind the owner orientation callback and terrain helpers
    draft_call_adapter(r_u32(r_u32(owner + 16u) + 20u), owner, temporary + 72u);
    terrain = r_u32(0x800A9750u) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(owner + 32u));
    draft_call_adapter(0x80063590u, terrain, temporary);
    angle = (uint32)(int32)(int16)r_u16(temporary + 74u);
    draft_call_adapter(0x800551CCu, angle, matrix);
    draft_call_adapter(0x8008355Cu, matrix);
    draft_call_adapter(0x80031CE8u, matrix, owner + 20u, temporary, points);
    draft_call_adapter(0x80031CC0u, temporary + 8u, points + 12u);
    draft_call_adapter(0x80031CC0u, temporary + 16u, points + 24u);
    w_u32(points + 36u, r_u32(owner + 20u));
    w_u32(points + 40u, r_u32(owner + 24u));
    w_u32(points + 44u, r_u32(owner + 28u));
    draft_call_adapter(0x80063600u, points);
    result = (uint32)draft_call_adapter(0x80063654u, object + 36u, points, angle, terrain);
    w_u32(object + 20u, r_u32(owner + 20u));
    w_u32(object + 28u, r_u32(owner + 28u));
    result = result ? r_u32(points + 40u) : (uint32)((int32)(r_u32(points + 4u) + r_u32(points + 16u) + r_u32(points + 28u)) / 3);
    w_u32(object + 24u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

static uint32 draft0_random(void)
{
    // TODO Bind the existing random-number helper
    return (uint32)draft_call_adapter(0x80069A50u);
}

// FUNCTION_MARKER sub_800418E4
uint32 sub_800418E4(uint32 position)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 rng = r_u32(0x800A63DCu) * 5u + 1u;
    uint32 choice = rng % 28u, x, z, list, count, i, found = 0u, candidates = draft_scratch_adapter(48u);
    uint32 selected, record, old_position = candidates + 32u;
    w_u32(0x800A63DCu, rng);
    x = r_u8(0x800A5F1Cu + 2u * choice) + r_u32(0x800A5640u);
    z = r_u8(0x800A5F1Du + 2u * choice) + r_u32(0x800A5644u);
    if (x >= 80u || z >= 80u)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    list = r_u16(r_u32(0x800A84F8u) + 8u * (80u * z + x));
    if (!list)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    list = r_u32(0x800A7E24u) + 2u * list;
    count = r_u16(list - 2u);
    for (i = 0; i < count; ++i)
    {
        uint32 id = r_u16(list + 2u * i), code = r_u16(r_u32(0x800A7BFCu) + 8u * id);
        uint32 allowed = r_u32(0x800A9740u);
        for (;;)
        {
            uint32 tag = r_u16(allowed);
            if (tag == 0xFFFFu)
                break;
            if ((tag & 0x7FFFu) == code)
            {
                // TODO Preserve the original sixteen-entry candidate limit
                w_u16(candidates + 2u * found, (uint16)(id | (tag & 0x8000u)));
                if (++found == 16u)
                    break;
            }
            allowed += 2u;
        }
    }
    if (!found)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    rng = r_u32(0x800A63DCu) * 5u + 1u;
    selected = r_u16(candidates + 2u * (rng % found));
    record = r_u32(0x800A7BFCu) + 8u * (selected & 0x7FFFu);
    w_u32(position, (x << 12) | (r_u16(record + 2u) & 0xFFFu));
    w_u32(position + 8u, (z << 12) | (r_u16(record + 4u) & 0xFFFu));
    w_u32(position + 4u, 0u - (r_u16(record + 6u) + 64u));
    w_u32(0x800A63DCu, rng);
    if (!(draft0_random() & 3u) || !(selected & 0x8000u))
        return draft_scratch_result(native_stack_mark, (uint64)(2u));
    for (i = 0; i < 3u; ++i)
        w_u32(old_position + 4u * i, r_u32(position + 4u * i));
    if (draft0_random() & 1u)
    {
        w_u32(position, r_u32(position) + ((draft0_random() & 4u) ? 0u - 4000u : 4000u));
        rng = r_u32(0x800A63DCu) * 5u + 1u;
        w_u32(0x800A63DCu, rng);
        w_u32(position + 8u, r_u32(position + 8u) - 512u + (rng & 0x3FFu));
    }
    else
    {
        w_u32(position + 8u, r_u32(position + 8u) + ((draft0_random() & 4u) ? 0u - 4000u : 4000u));
        rng = r_u32(0x800A63DCu) * 5u + 1u;
        w_u32(0x800A63DCu, rng);
        w_u32(position, r_u32(position) - 512u + (rng & 0x3FFu));
    }
    // TODO Bind the existing segment collision helper
    if ((uint32)draft_call_adapter(0x8002EAE4u, old_position, position, 1u) << 16)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    w_u32(position, r_u32(position) + (uint32)(int32)(int16)(r_u32(old_position) >> 8));
    w_u32(position + 8u, r_u32(position + 8u) + (uint32)(int32)(int16)(r_u32(old_position + 8u) >> 8));
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8001F690
uint32 sub_8001F690(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(144u), matrix = temporary, view = temporary + 32u;
    uint32 zeroes = temporary + 56u, quad = temporary + 112u, cursor = r_u32(0x800A865Cu), i;
    for (i = 0; i < 4u; ++i)
    {
        w_u32(quad + 8u * i, r_u32(0x800A8FE0u + 12u * i));
        w_u32(quad + 8u * i + 4u, r_u32(0x800A8FE8u + 12u * i));
    }
    for (i = 0; i < 14u; ++i)
        w_u16(zeroes + 4u * i + 2u, 0u);
    for (i = 0; i < 8u; ++i)
        w_u32(matrix + 4u * i, r_u32(0x800A9324u + 4u * i));
    for (i = 0; i < 8u; ++i)
        w_u32(view + 4u * i, r_u32(0x800A84B4u + 4u * i));
    cursor = (uint32)draft_call_adapter(0x80014A68u, matrix, view, quad, zeroes, cursor);
    cursor = sub_8001AE8C(matrix, view, quad, zeroes, cursor);
    if (r_u8(0x800A7BDCu))
    {
        cursor = sub_8001F868(r_u16(0x800A7BDAu), cursor, r_u32(0x800A9A74u), r_u32(0x800A7BD4u), r_u8(0x800A7BDCu));
        sub_8002062C();
    }
    w_u32(0x800A865Cu, cursor);
    for (i = 0; i < 4u; ++i)
        w_u32(0x800A637Cu - 4u * i, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(0x800A6370u));

    draft_scratch_release(native_stack_mark);
}

static void draft0_rotation(uint32 matrix)
{
    uint32 i;
    for (i = 0; i < 5u; ++i)
        xport_gte_write_control(i, r_u32(matrix + 4u * i));
}

static void draft0_matrix_multiply(uint32 left, uint32 right, uint32 destination)
{
    uint32 column, row;
    draft0_rotation(left);
    for (column = 0; column < 3u; ++column)
    {
        for (row = 0; row < 3u; ++row)
            xport_gte_write_data(9u + row, r_u16(right + 6u * row + 2u * column));
        draft_gte_command_adapter(0x49E012u);
        for (row = 0; row < 3u; ++row)
            w_u16(destination + 6u * row + 2u * column, (uint16)xport_gte_read_data(9u + row));
    }
}

// FUNCTION_MARKER sub_8005E31C
void sub_8005E31C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(104u), pitch, yaw, roll;
    uint32 matrix = temporary + 8u, first = temporary + 32u, second = temporary + 56u, third = temporary + 80u;
    // TODO Bind the existing vector-length helper
    uint32 distance = (uint32)draft_call_adapter(0x80069BE0u, r_u32(0x800A8554u), r_u32(0x800A855Cu));
    pitch = sub_80055A9C(r_u32(0x800A8558u), distance);
    w_u16(0x800A8560u, (uint16)pitch);
    if (!r_u16(0x800A8566u))
        w_u16(0x800A8562u, (uint16)(0u - sub_80055A9C(r_u32(0x800A8554u), r_u32(0x800A855Cu))));
    yaw = r_u16(0x800A8562u);
    roll = r_u16(0x800A8564u);
    if (!r_u16(0x800A974Cu))
        roll = 0u - roll;
    sub_80055228((uint32)(int32)(int16)roll, first);
    // TODO Bind the existing axis rotation constructors
    draft_call_adapter(0x80055168u, (uint32)(int32)(int16)pitch, second);
    draft_call_adapter(0x800551CCu, (uint32)(int32)(int16)yaw, third);
    draft0_matrix_multiply(first, second, matrix);
    draft0_matrix_multiply(matrix, third, 0x800A9324u);
    w_u16(0x800A7E7Eu, (uint16)((2048u - yaw) & 0xFFFu));
    w_u16(temporary, 0u);
    w_u16(temporary + 2u, (uint16)(0u - r_u16(0x800A84E8u)));
    w_u16(temporary + 4u, 0u);
    sub_80031B6C(matrix, temporary, 0x800A9338u);
    w_u16(0x800A8566u, 0u);

    draft_scratch_release(native_stack_mark);
}

static void draft0_transform_corner(uint32 destination, int32 x, int32 z)
{
    xport_gte_write_data(0u, (uint16)x);
    xport_gte_write_data(1u, (uint32)z);
    draft_gte_command_adapter(0x486012u);
    w_u32(destination, xport_gte_read_data(25u));
    w_u32(destination + 4u, xport_gte_read_data(26u));
    w_u32(destination + 8u, xport_gte_read_data(27u));
}

// FUNCTION_MARKER sub_80020E68
uint32 sub_80020E68(uint32 output, uint32 angle)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 far_z = -25000, side = 4660, near_z = 3640, projected, first_x, second_x;
    uint32 mode = r_u8(0x800A7ED2u) ? r_u8(0x800A7ED3u) : r_u8(0x800A7E80u);
    uint32 matrix = draft_scratch_adapter(32u), i;
    if (mode >= 2u)
    {
        near_z = 4000;
        if (mode != 2u)
        {
            far_z = -14000;
            if ((r_u32(0x800A7E80u) & 0xFF00FF00u) == 0x03000300u)
            {
                far_z = -8800;
                near_z = 8400;
                side = -250;
            }
            else
            {
                near_z = 6500;
                side = 0;
            }
        }
    }
    projected = far_z * 160 / 125;
    // TODO Bind the existing Y rotation constructor
    draft_call_adapter(0x800551CCu, angle, matrix);
    draft0_rotation(matrix);
    first_x = (projected - side) >> 1;
    second_x = (side - projected) >> 1;
    draft0_transform_corner(output, first_x, far_z >> 1);
    draft0_transform_corner(output + 12u, second_x, far_z >> 1);
    if (r_u8(0x800A7E80u) == 3u)
    {
        draft0_transform_corner(output + 24u, second_x, near_z >> 1);
        draft0_transform_corner(output + 36u, first_x, near_z >> 1);
    }
    else
    {
        draft0_transform_corner(output + 24u, 0, near_z >> 1);
        for (i = 0; i < 3u; ++i)
            w_u32(output + 36u + 4u * i, xport_gte_read_data(25u + i));
    }
    for (i = 0; i < 4u; ++i)
    {
        w_u32(output + 12u * i, r_u32(output + 12u * i) * 2u);
        w_u32(output + 12u * i + 8u, r_u32(output + 12u * i + 8u) * 2u);
    }
    mode = r_u8(0x800A7E80u);
    w_u8(0x800A7ED3u, (uint8)mode);
    return draft_scratch_result(native_stack_mark, (uint64)(mode));

    draft_scratch_release(native_stack_mark);
}

static void draft0_load_vectors(uint32 first, uint32 second, uint32 third)
{
    xport_gte_write_data(0u, r_u32(first));
    xport_gte_write_data(1u, r_u32(first + 4u));
    xport_gte_write_data(2u, r_u32(second));
    xport_gte_write_data(3u, r_u32(second + 4u));
    xport_gte_write_data(4u, r_u32(third));
    xport_gte_write_data(5u, r_u32(third + 4u));
}

// FUNCTION_MARKER sub_8001C25C
uint32 sub_8001C25C(uint32 cursor, uint32 vertices, uint32 source, uint32 ordering_table, uint32 depth_bias, uint32 count, uint32 next_source)
{
    uint32 native_stack_mark = draft_scratch_mark();

    while (count--)
    {
        uint32 record = source + 4u, depth, link;
        draft0_load_vectors(vertices + 8u * r_u16(record + 6u), vertices + 8u * r_u16(record + 8u), vertices + 8u * r_u16(record + 10u));
        draft_gte_command_adapter(0x280030u);
        w_u32(cursor + 4u, r_u32(record));
        draft_gte_command_adapter(0x158002Du);
        depth = xport_gte_read_data(7u);
        if (depth)
        {
            draft_gte_command_adapter(0x1400006u);
            if ((int32)xport_gte_read_data(24u) >= 0)
            {
                w_u32(cursor + 8u, xport_gte_read_data(12u));
                w_u32(cursor + 12u, xport_gte_read_data(13u));
                w_u32(cursor + 16u, xport_gte_read_data(14u));
                link = ordering_table + 4u * depth_bias + 4u * (uint32)((int32)depth >> 3);
                w_u32(cursor, (r_u32(link) & 0xFFFFFFu) | 0x04000000u);
                w_u32(link, (r_u32(link) & 0xFF000000u) | (cursor & 0xFFFFFFu));
                cursor += 20u;
            }
        }
        source += 16u;
    }
    w_u32(next_source, source);
    return draft_scratch_result(native_stack_mark, (uint64)(cursor));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8001AE8C
uint32 sub_8001AE8C(uint32 object_matrix, uint32 view_matrix, uint32 clip_quad, uint32 render_context, uint32 cursor)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(64u), transformed = temporary + 20u, light = temporary + 32u, next_record = temporary + 52u;
    uint32 camera_x = r_u32(0x800A7EE4u), camera_z = r_u32(0x800A7EECu);
    uint32 vertices = r_u32(r_u32(0x800A7E08u)), ordering_table = r_u32(0x800A9A74u);
    uint32 remaining = r_u32(0x800A636Cu);
    w_u32(0x800A9A6Cu, temporary);
    while (remaining)
    {
        uint32 object = r_u32(0x800BA8B8u + 4u * --remaining);
        uint32 x = r_u32(object) - camera_x, y = r_u32(object + 4u), z = r_u32(object + 8u) - camera_z;
        uint32 asset, source, total, consumed = 0u, depth_bias, i;
        if ((int32)((r_u32(clip_quad + 28u) - r_u32(clip_quad + 4u)) * (x - r_u32(clip_quad)) + (r_u32(clip_quad) - r_u32(clip_quad + 24u)) * (z - r_u32(clip_quad + 4u))) < 0)
            continue;
        if ((int32)((r_u32(clip_quad + 12u) - r_u32(clip_quad + 20u)) * (x - r_u32(clip_quad + 16u)) + (r_u32(clip_quad + 16u) - r_u32(clip_quad + 8u)) * (z - r_u32(clip_quad + 20u))) < 0)
            continue;
        for (i = 0; i < 8u; ++i)
            xport_gte_write_control(i, r_u32(object_matrix + 4u * i));
        xport_gte_write_data(0u, (x & 0xFFFFu) | (y << 16));
        xport_gte_write_data(1u, z);
        draft_gte_command_adapter(0x480012u);
        for (i = 0; i < 3u; ++i)
            w_u32(transformed + 4u * i, xport_gte_read_data(25u + i));
        asset = r_u32(0x800C0E00u + 4u * r_u16(object + 12u));
        source = r_u32(asset);
        total = r_u32(asset + 4u);
        if (r_u8(object + 15u))
        {
            draft0_rotation(object + 16u);
            depth_bias = 200u;
        }
        else
        {
            draft0_matrix_multiply(object_matrix, object + 16u, temporary);
            w_u32(0x800A84B0u, object + 16u);
            draft0_matrix_multiply(view_matrix, object + 16u, light);
            draft0_rotation(temporary);
            for (i = 0; i < 5u; ++i)
                xport_gte_write_control(8u + i, r_u32(light + 4u * i));
            depth_bias = 500u + r_u8(object + 14u);
        }
        for (i = 0; i < 3u; ++i)
            xport_gte_write_control(5u + i, r_u32(transformed + 4u * i));
        while (consumed < total)
        {
            uint32 header = r_u32(source), target = r_u32(0x8008B728u + 4u * (header >> 24));
            uint32 packet_count = header & 0x7FFu;
            consumed += packet_count;
            w_u32(next_record, source);
            cursor = (uint32)draft_call_adapter(target, cursor, vertices, source, ordering_table, render_context, depth_bias, packet_count, next_record);
            source = r_u32(next_record);
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(cursor));

    draft_scratch_release(native_stack_mark);
}

static uint32 draft0_visible(uint32 screen, uint32 count)
{
    uint32 i, left = 0u, right = 0u, top = 0u, bottom = 0u;
    for (i = 0; i < count; ++i)
    {
        int32 x = (int16)r_u16(screen + 4u * i), y = (int16)r_u16(screen + 4u * i + 2u);
        left |= x < 320;
        right |= x > 0;
        top |= y < 240;
        bottom |= y > 0;
    }
    return left && right && top && bottom;
}

static void draft0_screens(uint32 screen, uint32 count)
{
    uint32 i;
    for (i = 0; i < count; ++i)
        w_u32(screen + 4u * i, xport_gte_read_data(12u + i));
}

static void draft0_link(uint32 cursor, uint32 ordering_table, uint32 depth_bias, uint32 depth, uint32 length)
{
    uint32 link = ordering_table + 4u * depth_bias + 4u * (uint32)((int32)depth >> 3);
    w_u32(cursor, (r_u32(link) & 0xFFFFFFu) | (length << 24));
    w_u32(link, (r_u32(link) & 0xFF000000u) | (cursor & 0xFFFFFFu));
}

static void draft0_midpoint(uint32 destination, uint32 first, uint32 second, uint32 channels, uint32 width)
{
    uint32 j;
    for (j = 0; j < channels; ++j)
    {
        if (width == 2u)
            w_u16(destination + 2u * j, (uint16)(((int16)r_u16(first + 2u * j) + (int16)r_u16(second + 2u * j)) >> 1));
        else
            w_u8(destination + j, (uint8)((r_u8(first + j) + r_u8(second + j)) >> 1));
    }
}

static void draft0_quad_grid(uint32 grid, uint32 p0, uint32 p1, uint32 p2, uint32 p3, uint32 channels, uint32 width)
{
    uint32 stride = width == 2u ? 8u : 4u, j;
    uint32 corners[4] = {p0, p1, p2, p3};
    uint32 indices[4] = {0u, 2u, 6u, 8u};
    for (j = 0; j < 4u; ++j)
    {
        uint32 k;
        for (k = 0; k < channels; ++k)
        {
            if (width == 2u)
                w_u16(grid + stride * indices[j] + 2u * k, r_u16(corners[j] + 2u * k));
            else
                w_u8(grid + stride * indices[j] + k, r_u8(corners[j] + k));
        }
    }
    draft0_midpoint(grid + stride, grid, grid + 2u * stride, channels, width);
    draft0_midpoint(grid + 3u * stride, grid, grid + 6u * stride, channels, width);
    draft0_midpoint(grid + 4u * stride, grid + 2u * stride, grid + 6u * stride, channels, width);
    draft0_midpoint(grid + 5u * stride, grid + 2u * stride, grid + 8u * stride, channels, width);
    draft0_midpoint(grid + 7u * stride, grid + 6u * stride, grid + 8u * stride, channels, width);
}

static uint32 draft0_gt4(uint32 cursor, uint32 vertices, uint32 uv, uint32 colors, uint32 i0, uint32 i1, uint32 i2, uint32 i3, uint32 clut, uint32 page, uint32 ordering_table, uint32 depth_bias, uint32 require_depth, uint32 project)
{
    uint32 indices[4] = {i0, i1, i2, i3}, i, depth;
    if (project)
    {
        draft0_load_vectors(vertices + 8u * i0, vertices + 8u * i1, vertices + 8u * i2);
        draft_gte_command_adapter(0x280030u);
        xport_gte_write_data(0u, r_u32(vertices + 8u * i3));
        xport_gte_write_data(1u, r_u32(vertices + 8u * i3 + 4u));
        draft_gte_command_adapter(0x1400006u);
    }
    if (require_depth && (int32)xport_gte_read_data(24u) < 0)
        return cursor;
    for (i = 0; i < 3u; ++i)
        w_u32(cursor + 8u + 12u * i, xport_gte_read_data(12u + i));
    draft_gte_command_adapter(0x180001u);
    w_u32(cursor + 48u, r_u32(uv + 4u * i3));
    draft_gte_command_adapter(0x168002Eu);
    depth = xport_gte_read_data(7u);
    if (require_depth && !depth)
        return cursor;
    for (i = 0; i < 4u; ++i)
    {
        w_u32(cursor + 4u + 12u * i, (r_u32(colors + 4u * indices[i]) & (i ? 0xFFFFFFFFu : 0xFFFFFFu)) | (i ? 0u : 0x3C000000u));
        w_u32(cursor + 12u + 12u * i, r_u32(uv + 4u * indices[i]) | (i == 0u ? clut : i == 1u ? page : 0u));
    }
    w_u32(cursor + 44u, xport_gte_read_data(14u));
    draft0_link(cursor, ordering_table, depth_bias, depth, 12u);
    return cursor + 52u;
}

// FUNCTION_MARKER sub_8001E2C0
uint32 sub_8001E2C0(uint32 screen, uint32 cursor, uint32 ordering_table, uint32 uv, uint32 vertices, uint32 clut, uint32 texture_page, uint32 depth_bias, uint32 colors)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 base;
    for (base = 0u; base < 5u; base += (base == 1u ? 2u : 1u))
    {
        uint32 flag, area, j;
        draft0_load_vectors(vertices + 8u * base, vertices + 8u * (base + 1u), vertices + 8u * (base + 3u));
        draft_gte_command_adapter(0x280030u);
        xport_gte_write_data(0u, r_u32(vertices + 8u * (base + 4u)));
        xport_gte_write_data(1u, r_u32(vertices + 8u * (base + 4u) + 4u));
        flag = draft_gte_control_adapter(31u);
        draft_gte_command_adapter(0x1400006u);
        area = xport_gte_read_data(24u);
        if ((int32)flag < 0 || area >= 1024u)
        {
            draft0_screens(screen, 3u);
            draft_gte_command_adapter(0x180001u);
            w_u32(screen + 12u, xport_gte_read_data(14u));
            if (!draft0_visible(screen, 4u))
                continue;
            for (j = 0u; j < 3u; ++j)
            {
                uint32 buffer = j == 0u ? vertices : j == 1u ? uv : colors;
                uint32 stride = j == 0u ? 8u : 4u, channels = j == 1u ? 2u : 3u, width = j == 0u ? 2u : 1u;
                draft0_midpoint(buffer + 9u * stride, buffer + base * stride, buffer + (base + 1u) * stride, channels, width);
                draft0_midpoint(buffer + 10u * stride, buffer + base * stride, buffer + (base + 3u) * stride, channels, width);
                draft0_midpoint(buffer + 11u * stride, buffer + (base + 1u) * stride, buffer + (base + 3u) * stride, channels, width);
                draft0_midpoint(buffer + 12u * stride, buffer + (base + 1u) * stride, buffer + (base + 4u) * stride, channels, width);
                draft0_midpoint(buffer + 13u * stride, buffer + (base + 3u) * stride, buffer + (base + 4u) * stride, channels, width);
            }
            cursor = draft0_gt4(cursor, vertices, uv, colors, base, 9u, 10u, 11u, clut, texture_page, ordering_table, depth_bias, 1u, 1u);
            cursor = draft0_gt4(cursor, vertices, uv, colors, 9u, base + 1u, 11u, 12u, clut, texture_page, ordering_table, depth_bias, 1u, 1u);
            cursor = draft0_gt4(cursor, vertices, uv, colors, 10u, 11u, base + 3u, 13u, clut, texture_page, ordering_table, depth_bias, 1u, 1u);
            cursor = draft0_gt4(cursor, vertices, uv, colors, 11u, 12u, 13u, base + 4u, clut, texture_page, ordering_table, depth_bias, 1u, 1u);
        }
        else
        {
            // TODO Avoid repeating projection when GTE adapters gain concrete bindings
            cursor = draft0_gt4(cursor, vertices, uv, colors, base, base + 1u, base + 3u, base + 4u, clut, texture_page, ordering_table, depth_bias, 0u, 0u);
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(cursor));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800170D0
uint32 sub_800170D0(uint32 cursor, uint32 vertices, uint32 source, uint32 ordering_table, uint32 uv, uint32 depth_bias, uint32 count, uint32 next_source)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(64u), screen = temporary + 48u;
    xport_gte_write_data(6u, 0x24808080u);
    while (count--)
    {
        uint32 record = source + 12u, p[3], i, flag, area;
        for (i = 0; i < 3u; ++i)
            p[i] = vertices + 8u * r_u16(record + 6u + 2u * i);
        draft0_load_vectors(p[0], p[1], p[2]);
        draft_gte_command_adapter(0x280030u);
        xport_gte_write_data(0u, r_u32(vertices + 8u * r_u16(record + 4u)));
        xport_gte_write_data(1u, r_u32(vertices + 8u * r_u16(record + 4u) + 4u));
        flag = draft_gte_control_adapter(31u);
        draft_gte_command_adapter(0x1400006u);
        area = xport_gte_read_data(24u);
        if ((int32)flag < 0 || (int32)area >= 1024)
        {
            draft0_screens(screen, 3u);
            if (draft0_visible(screen, 3u))
            {
                draft_gte_command_adapter(0xE80413u);
                for (i = 0; i < 3u; ++i)
                {
                    uint32 j;
                    for (j = 0; j < 3u; ++j)
                        w_u16(temporary + 8u * i + 2u * j, r_u16(p[i] + 2u * j));
                }
                draft0_midpoint(temporary + 24u, temporary, temporary + 8u, 3u, 2u);
                draft0_midpoint(temporary + 32u, temporary + 8u, temporary + 16u, 3u, 2u);
                draft0_midpoint(temporary + 40u, temporary, temporary + 16u, 3u, 2u);
                w_u32(uv, r_u16(record - 8u));
                w_u32(uv + 4u, r_u16(record - 4u));
                w_u32(uv + 8u, r_u32(record));
                draft0_midpoint(uv + 12u, uv, uv + 4u, 2u, 1u);
                draft0_midpoint(uv + 16u, uv + 4u, uv + 8u, 2u, 1u);
                draft0_midpoint(uv + 20u, uv, uv + 8u, 2u, 1u);
                cursor = sub_8001EABC(screen, cursor, vertices, source, ordering_table, uv, temporary, r_u32(record - 8u) & 0xFFFF0000u, r_u32(record - 4u) & 0xFFFF0000u, depth_bias);
            }
        }
        else if ((int32)area >= 0)
        {
            uint32 depth;
            draft_gte_command_adapter(0x158002Du);
            w_u32(cursor + 28u, r_u32(record));
            w_u32(cursor + 8u, xport_gte_read_data(12u));
            w_u32(cursor + 16u, xport_gte_read_data(13u));
            w_u32(cursor + 24u, xport_gte_read_data(14u));
            depth = xport_gte_read_data(7u);
            w_u32(cursor + 20u, r_u32(record - 4u));
            draft_gte_command_adapter(0xE80413u);
            draft0_link(cursor, ordering_table, depth_bias, depth, 7u);
            w_u32(cursor + 12u, r_u32(record - 8u));
            w_u32(cursor + 4u, xport_gte_read_data(22u));
            cursor += 32u;
        }
        source += 24u;
    }
    w_u32(next_source, source);
    return draft_scratch_result(native_stack_mark, (uint64)(cursor));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8001998C
uint32 sub_8001998C(uint32 cursor, uint32 vertices, uint32 source, uint32 ordering_table, uint32 uv, uint32 depth_bias, uint32 count, uint32 next_source)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(184u), screen = temporary + 112u, colors = temporary + 128u;
    xport_gte_write_data(6u, 0x3C808080u);
    while (count--)
    {
        uint32 record = source + 16u, p[4], i, flag, area, depth;
        for (i = 0; i < 4u; ++i)
            p[i] = vertices + 8u * r_u16(record + 6u + 4u * i);
        draft0_load_vectors(p[0], p[1], p[2]);
        draft_gte_command_adapter(0x280030u);
        xport_gte_write_data(0u, r_u32(p[3]));
        xport_gte_write_data(1u, r_u32(p[3] + 4u));
        flag = draft_gte_control_adapter(31u);
        draft_gte_command_adapter(0x1400006u);
        area = xport_gte_read_data(24u);
        if ((int32)flag < 0 || (int32)area >= 1024)
        {
            draft0_screens(screen, 3u);
            draft_gte_command_adapter(0x180001u);
            w_u32(screen + 12u, xport_gte_read_data(14u));
            xport_gte_write_data(0u, r_u32(vertices + 8u * r_u16(record + 16u)));
            xport_gte_write_data(1u, r_u32(vertices + 8u * r_u16(record + 16u) + 4u));
            if (draft0_visible(screen, 4u))
            {
                draft_gte_command_adapter(0xE80413u);
                w_u32(colors + 32u, xport_gte_read_data(22u));
                draft0_load_vectors(vertices + 8u * r_u16(record + 4u), vertices + 8u * r_u16(record + 8u), vertices + 8u * r_u16(record + 12u));
                draft_gte_command_adapter(0xF80416u);
                draft0_quad_grid(temporary, p[0], p[1], p[2], p[3], 3u, 2u);
                w_u32(uv, r_u16(record - 12u));
                w_u32(uv + 8u, r_u16(record - 8u));
                w_u32(uv + 24u, r_u32(record - 4u));
                w_u32(uv + 32u, r_u32(record));
                draft0_quad_grid(uv, uv, uv + 8u, uv + 24u, uv + 32u, 2u, 1u);
                w_u32(colors, xport_gte_read_data(20u));
                w_u32(colors + 8u, xport_gte_read_data(21u));
                w_u32(colors + 24u, xport_gte_read_data(22u));
                draft0_quad_grid(colors, colors, colors + 8u, colors + 24u, colors + 32u, 3u, 1u);
                cursor = sub_8001E2C0(screen, cursor, ordering_table, uv, temporary, r_u32(record - 12u) & 0xFFFF0000u, r_u32(record - 8u) & 0xFFFF0000u, depth_bias, colors);
            }
        }
        else if ((int32)area >= 0)
        {
            w_u32(cursor + 8u, xport_gte_read_data(12u));
            w_u32(cursor + 20u, xport_gte_read_data(13u));
            w_u32(cursor + 32u, xport_gte_read_data(14u));
            draft_gte_command_adapter(0x180001u);
            draft0_load_vectors(vertices + 8u * r_u16(record + 4u), vertices + 8u * r_u16(record + 8u), vertices + 8u * r_u16(record + 12u));
            draft_gte_command_adapter(0x168002Eu);
            w_u32(cursor + 44u, xport_gte_read_data(14u));
            depth = xport_gte_read_data(7u);
            draft_gte_command_adapter(0xF80416u);
            w_u32(cursor + 36u, r_u32(record - 4u));
            w_u32(cursor + 48u, r_u32(record));
            w_u32(cursor + 24u, r_u32(record - 8u));
            xport_gte_write_data(0u, r_u32(vertices + 8u * r_u16(record + 16u)));
            xport_gte_write_data(1u, r_u32(vertices + 8u * r_u16(record + 16u) + 4u));
            w_u32(cursor + 4u, xport_gte_read_data(20u));
            w_u32(cursor + 16u, xport_gte_read_data(21u));
            w_u32(cursor + 28u, xport_gte_read_data(22u));
            w_u32(cursor + 12u, r_u32(record - 12u));
            draft_gte_command_adapter(0xE80413u);
            draft0_link(cursor, ordering_table, depth_bias, depth, 12u);
            w_u32(cursor + 40u, xport_gte_read_data(22u));
            cursor += 52u;
        }
        source += 36u;
    }
    w_u32(next_source, source);
    return draft_scratch_result(native_stack_mark, (uint64)(cursor));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8001545C
uint32 sub_8001545C(uint32 cursor, uint32 vertices, uint32 source, uint32 ordering_table, uint32 uv, uint32 depth_bias, uint32 count, uint32 next_source)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(128u), screen = temporary + 112u;
    xport_gte_write_data(6u, 0x2C808080u);
    while (count--)
    {
        uint32 header = source, end = source + ((r_u32(source) >> 10) & 0x3FFCu);
        source += 20u;
        while (source < end)
        {
            uint32 p[4], i, flag, area = 0u;
            for (i = 0; i < 4u; ++i)
                p[i] = vertices + 8u * r_u16(source + 2u + 2u * i);
            draft0_load_vectors(p[0], p[1], p[2]);
            draft_gte_command_adapter(0x280030u);
            xport_gte_write_data(0u, r_u32(p[3]));
            xport_gte_write_data(1u, r_u32(p[3] + 4u));
            flag = draft_gte_control_adapter(31u);
            if ((int32)flag >= 0)
            {
                draft_gte_command_adapter(0x1400006u);
                area = xport_gte_read_data(24u);
            }
            if ((int32)flag < 0 || ((int32)area >= 0 && (int32)area >= 1024))
            {
                draft0_screens(screen, 3u);
                draft_gte_command_adapter(0x180001u);
                xport_gte_write_data(0u, r_u32(vertices + 8u * r_u16(source)));
                xport_gte_write_data(1u, r_u32(vertices + 8u * r_u16(source) + 4u));
                if ((int32)flag >= 0)
                    flag = draft_gte_control_adapter(31u);
                w_u32(screen + 12u, xport_gte_read_data(14u));
                if (draft0_visible(screen, 4u))
                {
                    draft_gte_command_adapter(0xE80413u);
                    draft0_quad_grid(temporary, p[0], p[1], p[2], p[3], 3u, 2u);
                    w_u32(uv, r_u16(header + 4u));
                    w_u32(uv + 8u, r_u16(header + 8u));
                    w_u32(uv + 24u, r_u32(header + 12u));
                    w_u32(uv + 32u, r_u32(header + 16u));
                    draft0_quad_grid(uv, uv, uv + 8u, uv + 24u, uv + 32u, 2u, 1u);
                    if ((int32)flag < 0)
                    {
                        // TODO Bind the clipped quad subdivision helper outside this draft set
                        cursor = (uint32)draft_call_adapter(0x8001CB7Cu, screen, cursor, vertices, source, ordering_table, uv, temporary, r_u32(header + 4u) & 0xFFFF0000u, r_u32(header + 8u) & 0xFFFF0000u, depth_bias);
                    }
                    else
                    {
                        cursor = sub_8001C52C(screen, cursor, vertices, source, ordering_table, uv, temporary, r_u32(header + 4u) & 0xFFFF0000u, r_u32(header + 8u) & 0xFFFF0000u, depth_bias);
                    }
                }
            }
            else if ((int32)area >= 0)
            {
                uint32 depth;
                w_u32(cursor + 8u, xport_gte_read_data(12u));
                w_u32(cursor + 16u, xport_gte_read_data(13u));
                w_u32(cursor + 24u, xport_gte_read_data(14u));
                w_u32(cursor + 12u, r_u32(header + 4u));
                draft_gte_command_adapter(0x180001u);
                xport_gte_write_data(0u, r_u32(vertices + 8u * r_u16(source)));
                xport_gte_write_data(1u, r_u32(vertices + 8u * r_u16(source) + 4u));
                w_u32(cursor + 20u, r_u32(header + 8u));
                draft_gte_command_adapter(0x168002Eu);
                w_u32(cursor + 36u, r_u32(header + 16u));
                w_u32(cursor + 32u, xport_gte_read_data(14u));
                depth = xport_gte_read_data(7u);
                draft_gte_command_adapter(0xE80413u);
                w_u32(cursor + 28u, r_u32(header + 12u));
                draft0_link(cursor, ordering_table, depth_bias, depth, 9u);
                w_u32(cursor + 4u, xport_gte_read_data(22u));
                cursor += 40u;
            }
            source += 12u;
        }
    }
    w_u32(next_source, source);
    return draft_scratch_result(native_stack_mark, (uint64)(cursor));

    draft_scratch_release(native_stack_mark);
}
