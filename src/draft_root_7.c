#include "draft_signatures.h"
#include <stdlib.h>

uint32 sub_80055288(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 x, y, sum, difference;
    sint32 cs, cd, ss, sd, value;
    FUNCTION_MARKER(0x80055288u, "1.EXE");
    y = (0u - (uint32)r_s16(a0 + 2u)) & 0xFFFu;
    x = (0u - (uint32)r_s16(a0)) & 0xFFFu;
    sum = (x + y) & 0xFFFu;
    difference = (x - y) & 0xFFFu;
    value = r_s16(0x80010AE0u + y * 2u);
    cs = r_s16(0x80010AE0u + sum * 2u);
    cd = r_s16(0x80010AE0u + difference * 2u);
    ss = r_s16(0x800102E0u + sum * 2u);
    sd = r_s16(0x800102E0u + difference * 2u);
    w_u16(a1, (uint16)value);
    value = r_s16(0x800102E0u + y * 2u);
    w_u16(a1 + 2u, (uint16)((cd - cs) >> 1));
    w_u16(a1 + 16u, (uint16)((cd + cs) >> 1));
    w_u16(a1 + 12u, (uint16)value);
    w_u16(a1 + 8u, (uint16)r_s16(0x80010AE0u + x * 2u));
    value = -((sd + ss) >> 1);
    y = (uint32)r_s16(0x800102E0u + x * 2u);
    w_u16(a1 + 14u, (uint16)value);
    w_u16(a1 + 4u, (uint16)((sd - ss) >> 1));
    w_u16(a1 + 6u, 0u);
    w_u16(a1 + 10u, (uint16)y);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80070C48(uint32 a0, uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 packet, table, result;
    FUNCTION_MARKER(0x80070C48u, "1.EXE");
    (void)a3;
    packet = r_u32(0x800A865Cu);
    w_u16(packet + 8u, (uint16)a4); w_u16(packet + 24u, (uint16)a4);
    w_u32(packet + 4u, a1 | 0x38000000u); w_u32(packet + 20u, a1);
    w_u32(packet + 12u, a2); w_u32(packet + 28u, a2);
    table = r_u32(0x800A9A74u) + a0 * 4u;
    w_u16(packet + 16u, (uint16)(a4 + a6)); w_u16(packet + 32u, (uint16)(a4 + a6));
    w_u16(packet + 10u, (uint16)a5); w_u16(packet + 18u, (uint16)a5);
    w_u16(packet + 34u, (uint16)(a5 + a7)); w_u16(packet + 26u, (uint16)(a5 + a7));
    w_u32(packet, (r_u32(table) & 0xFFFFFFu) | 0x08000000u);
    w_u32(0x800A865Cu, packet + 36u);
    result = (r_u32(table) & 0xFF000000u) | (packet & 0xFFFFFFu);
    w_u32(table, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800408C0(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 step, product, value;
    sint32 height, threshold;
    FUNCTION_MARKER(0x800408C0u, "1.EXE");
    step = r_u32(0x800A9010u);
    product = step * (uint32)r_s16(a0 + 10u);
    value = r_u16(a0 + 36u) + step * 5u;
    w_u16(a0 + 36u, (uint16)value);
    height = (sint16)value;
    value = r_u16(a0 + 38u) + product;
    threshold = r_s16(a0 + 8u);
    w_u16(a0 + 38u, (uint16)value);
    threshold = (sint32)((uint32)threshold * 768u) >> 10;
    if (threshold >= height) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    value = r_u32(0x800A62ECu);
    w_u32(a0, 0x8004094Cu);
    value = (uint32)r_s16(value + 0x58u);
    w_u16(a0 + 32u, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

static void draft7_matrix(uint32 source, uint32 count)
{
    uint32 i;
    for (i = 0u; i < count; ++i) xport_gte_write_control(i, r_u32(source + i * 4u));
}

uint32 sub_80064784(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 xy, z, result, m0, m1, m2, saved_xy, saved_z;
    FUNCTION_MARKER(0x80064784u, "1.EXE");
    saved_xy = r_u32(0x800A6364u); saved_z = r_u32(0x800A6368u);
    draft7_matrix(0x800A9324u, 8u);
    xy = r_u16(a0) | ((uint32)r_u16(a0 + 4u) << 16);
    z = r_u32(a0 + 8u);
    xport_gte_write_data(0u, xy); xport_gte_write_data(1u, z);
    xport_gte_mvmva(0x480012u);
    m0 = xport_gte_read_data(25u); m1 = xport_gte_read_data(26u); m2 = xport_gte_read_data(27u);
    // TODO Replace the escaped local-result address with an integration contract
    result = draft_scratch_adapter(12u);
    w_u32(result, m0); w_u32(result + 4u, m1); w_u32(result + 8u, m2);
    draft7_matrix(0x800A8FBCu, 5u);
    xport_gte_write_control(5u, m0); xport_gte_write_control(6u, m1); xport_gte_write_control(7u, m2);
    xport_gte_write_data(0u, saved_xy); xport_gte_write_data(1u, saved_z);
    draft_gte_command_adapter(0x180001u);
    // TODO Unsupported screen/depth GTE outputs retain fail-fast boundaries
    w_u32(a1, xport_gte_read_data(14u));
    w_u32(a1 + 4u, xport_gte_read_data(19u));
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80030E18(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 node, object;
    FUNCTION_MARKER(0x80030E18u, "1.EXE");
    node = r_u32(0x800A60A0u);
    w_u16(0x800A5C04u, 0u);
    if (node == 0u) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    if (a0 == 1u) {
        object = r_u32(r_u32(0x800A851Cu) + (uint32)r_s16(node) * 4u);
        if (r_u8(object + 17u) == 0u) { w_u16(0x800A5C04u, 0u); return draft_scratch_result(native_stack_mark, (uint64)(0u)); }
    }
    object = r_u32(r_u32(0x800A851Cu) + (uint32)r_s16(r_u32(0x800A60A0u)) * 4u);
    w_u16(0x800A5C04u, r_u8(object + 16u) == 0u && node != r_u32(0x800A6098u));
    object = r_u32(0x800A60A0u);
    w_u32(0x800A60A0u, r_u32(object + 4u));
    return draft_scratch_result(native_stack_mark, (uint64)(node));

    draft_scratch_release(native_stack_mark);
}

static uint32 draft7_divide(uint32 value, uint32 divisor)
{
    if (divisor == 0u || (divisor == 0xFFFFFFFFu && value == 0x80000000u)) abort();
    return (uint32)((sint32)value / (sint32)divisor);
}

uint32 sub_80069C78(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scale, smaller, larger, ratio, correction;
    FUNCTION_MARKER(0x80069C78u, "1.EXE");
    if ((sint32)a0 < 0) a0 = 0u - a0;
    if ((sint32)a1 < 0) a1 = 0u - a1;
    if ((sint32)a1 < (sint32)a0) { uint32 swap = a0; a0 = a1; a1 = swap; }
    scale = (uint32)((sint32)a1 >> 15);
    if (a1 == 0u) return draft_scratch_result(native_stack_mark, (uint64)(a0));
    if (scale == 0u) scale = 1u;
    larger = draft7_divide(a1, scale);
    smaller = draft7_divide(a0, scale);
    ratio = draft7_divide(smaller << 9, larger);
    correction = larger * r_u16(0x80091178u + ratio * 2u);
    return draft_scratch_result(native_stack_mark, (uint64)((larger + (uint32)((sint32)correction >> 16)) * scale));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80033764(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 base, value, rate, delta;
    FUNCTION_MARKER(0x80033764u, "1.EXE");
    base = 0x800A6C6Cu + a0 * 12u;
    if (r_u32(base) == 0u) {
        delta = a1 * r_u32(0x800A9010u) * r_u32(base + 8u);
        rate = r_u32(base + 8u) << 7;
        value = delta + r_u32(base + 4u);
        w_u32(base + 4u, value);
        if ((sint32)value >= (sint32)rate) {
            value = r_u32(base + 8u);
            w_u32(base, 1u); w_u32(base + 4u, value << 7);
        }
    }
    if (r_u32(base) != 1u) return draft_scratch_result(native_stack_mark, (uint64)(1u));
    delta = a1 * r_u32(0x800A9010u) * r_u32(base + 8u);
    rate = r_u32(base + 8u);
    value = r_u32(base + 4u) - delta;
    w_u32(base + 4u, value);
    if ((sint32)rate >= (sint32)value) {
        value = r_u32(base + 8u);
        w_u32(base, 0u); w_u32(base + 8u, 0u); w_u32(base + 4u, value);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80078854(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value, threshold;
    FUNCTION_MARKER(0x80078854u, "1.EXE");
    value = r_u32(0x800A7AC8u);
    if (value != 0u) return draft_scratch_result(native_stack_mark, (uint64)(value));
    value = a0 & 0x1000u;
    if (r_u32(0x800A7ACCu) != 0u) return draft_scratch_result(native_stack_mark, (uint64)(value));
    if (value && r_u32(0x800A7AC4u)) w_u32(0x800A7ACCu, 13u);
    value = a0 & 0x4000u;
    if (value == 0u) return draft_scratch_result(native_stack_mark, (uint64)(value));
    threshold = 13u * r_u32(0x800A7BE4u) - 39u;
    if ((sint32)r_u32(0x800A7AC4u) < (sint32)threshold) w_u32(0x800A7AC8u, 13u);
    return draft_scratch_result(native_stack_mark, (uint64)(13u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005E89C(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 dx, dy, value = 0;
    uint32 i, weight, offset = 70u;
    FUNCTION_MARKER(0x8005E89Cu, "1.EXE");
    w_u16(0x800A988Cu, r_u16(a0));
    w_u16(0x800A988Eu, r_u16(a0 + 2u));
    dx = (sint16)(r_u16(a1) - r_u16(a0));
    dy = (sint16)(r_u16(a1 + 2u) - r_u16(a0 + 2u));
    for (i = 0u; i < 6u; ++i) {
        weight = r_u8(0x800A6349u - i);
        offset -= 10u;
        w_u16(0x800A988Cu + offset, (uint16)(r_u16(a0) + ((dx * (sint32)weight) >> 8)));
        weight = r_u8(0x800A6349u - i);
        value = (dy * (sint32)weight) >> 8;
        w_u16(0x800A988Eu + offset, (uint16)(r_u16(a0 + 2u) + value));
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005E95C(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 base, scale, product, positive, negative, texture, index, table;
    uint16 coordinates[8];
    FUNCTION_MARKER(0x8005E95Cu, "1.EXE");
    base = 0x800A988Cu + a1 * 10u;
    scale = (uint32)r_s16(0x800A8218u);
    product = (uint32)r_s16(base + 6u) * scale;
    texture = r_u32(r_u32(0x800C0E00u + (uint32)r_s16(base + 4u) * 4u));
    positive = product >> 12;
    product = (uint32)r_s16(base + 6u) * scale;
    negative = (0u - product) >> 12;
    coordinates[0] = coordinates[1] = coordinates[3] = coordinates[4] = (uint16)positive;
    coordinates[2] = coordinates[5] = coordinates[6] = coordinates[7] = (uint16)negative;
    for (index = 4u; index > 0u; --index) {
        uint32 pair = (index - 1u) * 2u;
        coordinates[pair] = (uint16)(coordinates[pair] + r_u16(base));
        coordinates[pair + 1u] = (uint16)(coordinates[pair + 1u] + r_u16(base + 2u));
        w_u32(a0 + 8u + (index - 1u) * 8u, coordinates[pair] | ((uint32)coordinates[pair + 1u] << 16));
        w_u32(a0 + 12u + (index - 1u) * 8u, r_u32(texture + index * 4u));
    }
    w_u32(a0 + 4u, r_u32(texture + 20u));
    table = r_u32(0x800A9A74u) + (uint32)r_s16(base + 8u) * 4u;
    w_u32(a0, (r_u32(table) & 0xFFFFFFu) | 0x09000000u);
    w_u32(table, (r_u32(table) & 0xFF000000u) | (a0 & 0xFFFFFFu));
    return draft_scratch_result(native_stack_mark, (uint64)(a0 + 40u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80023388(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 axis, amplitude, angle, product, step, result = 0u;
    FUNCTION_MARKER(0x80023388u, "1.EXE");
    for (axis = 0u; axis < 2u; ++axis) {
        uint32 field = a0 + 0x23Cu + axis * 4u;
        angle = (uint32)r_s16(field + 2u);
        result = angle & 0xFFFu;
        if ((sint32)angle >= 0x2000) continue;
        product = (uint32)r_s16(field) * (uint32)r_s16(0x800102E0u + result * 2u);
        amplitude = (uint32)r_s16(field);
        step = r_u32(0x800A63D8u);
        w_u16(field, (uint16)((sint32)(amplitude * 64000u + 0x8000u) >> 16));
        angle = r_u16(field + 2u) + (uint32)((sint32)(step << 7) >> 16);
        amplitude = r_u16(a0 + 0xE0u + axis * 4u);
        w_u16(field + 2u, (uint16)angle);
        result = (uint32)((sint32)product >> 12);
        w_u16(a0 + 0xE0u + axis * 4u, (uint16)(amplitude + result));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80029758(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 divisor, value;
    FUNCTION_MARKER(0x80029758u, "1.EXE");
    divisor = r_u32(0x800A56C0u);
    value = 0u - 136u * r_u32(a0 + 0x1E8u);
    w_u32(a1, draft7_divide(value, divisor));
    value = 0u - 136u * r_u32(a0 + 0x1F0u);
    w_u32(a1 + 8u, draft7_divide(value, divisor));
    value = r_u32(a0 + 0x1ECu);
    w_u32(a1 + 4u, value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}
