#include "draft_signatures.h"

static void draft_group2_load_vertex(uint32 vertices, uint32 index, uint32 slot)
{
    xport_gte_write_data(2u * slot, r_u32(vertices + 8u * index));
    xport_gte_write_data(2u * slot + 1u, r_u32(vertices + 8u * index + 4u));
}

static void draft_group2_screens(uint32 destination, uint32 stride)
{
    w_u32(destination, xport_gte_read_data(12u));
    w_u32(destination + stride, xport_gte_read_data(13u));
    w_u32(destination + 2u * stride, xport_gte_read_data(14u));
}

static int draft_group2_visible(uint32 screens, uint32 count)
{
    uint32 i;
    int left = 0, right = 0, top = 0, bottom = 0;
    for (i = 0; i < count; ++i) {
        int32 x = (int16)r_u16(screens + 4u * i), y = (int16)r_u16(screens + 4u * i + 2u);
        left |= x < 320; right |= x > 0; top |= y < 240; bottom |= y > 0;
    }
    return left && right && top && bottom;
}

static void draft_group2_link(uint32 packet, uint32 ordering, uint32 depth, uint32 bias, uint32 tag)
{
    uint32 entry = ordering + 4u * (depth >> 3) + 4u * bias;
    w_u32(packet, (r_u32(entry) & 0xFFFFFFu) | tag);
    w_u32(entry, (r_u32(entry) & 0xFF000000u) | (packet & 0xFFFFFFu));
    w_u32(packet + 4u, xport_gte_read_data(22u));
}

static void draft_group2_midpoints(uint32 vertices, uint32 uv, const uint32 *indices, const uint32 *pairs, uint32 count)
{
    uint32 component, i;
    for (component = 0; component < 3u; ++component) {
        int32 values[4];
        for (i = 0; i < count; ++i) values[i] = (int16)r_u16(vertices + 8u * indices[i] + 2u * component);
        for (i = 0; i < (count == 4u ? 5u : 3u); ++i)
            w_u16(vertices + 8u * (9u + i) + 2u * component, (uint16)((values[pairs[2u * i]] + values[pairs[2u * i + 1u]]) >> 1));
    }
    for (component = 0; component < 2u; ++component) {
        uint32 values[4];
        for (i = 0; i < count; ++i) values[i] = r_u8(uv + 4u * indices[i] + component);
        for (i = 0; i < (count == 4u ? 5u : 3u); ++i)
            w_u8(uv + 4u * (9u + i) + component, (uint8)((values[pairs[2u * i]] + values[pairs[2u * i + 1u]]) >> 1));
    }
}

/* FUNCTION_MARKER: sub_8001EABC */
uint32 sub_8001EABC(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8, uint32 a9, uint32 a10)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 first = 0u, second = 3u, third = 5u, remaining = 4u, depth;
    (void)a3; (void)a4;
    do {
        int32 area;
        draft_group2_load_vertex(a7, first, 0u); draft_group2_load_vertex(a7, second, 1u); draft_group2_load_vertex(a7, third, 2u);
        draft_gte_command_adapter(0x280030u);
        w_u32(a2 + 12u, a8 | r_u32(a6 + 4u * first));
        area = (int32)draft_gte_control_adapter(31u);
        draft_gte_command_adapter(0x1400006u);
        if (area >= 0 && (int32)xport_gte_read_data(24u) < 1024) {
            draft_gte_command_adapter(0x158002Du);
            w_u32(a2 + 20u, a9 | r_u32(a6 + 4u * second)); w_u32(a2 + 28u, r_u32(a6 + 4u * third));
            draft_group2_screens(a2 + 8u, 8u); depth = xport_gte_read_data(7u);
            draft_group2_link(a2, a5, depth, a10, 0x07000000u); a2 += 32u;
        } else {
            draft_group2_screens(a1, 4u);
            if (draft_group2_visible(a1, 3u)) {
                const uint32 indices[3] = { first, second, third }, pairs[6] = { 0u,1u,1u,2u,0u,2u };
                uint32 inner = 4u, i0 = first, i1 = 9u, i2 = 11u;
                draft_group2_midpoints(a7, a6, indices, pairs, 3u);
                do {
                    draft_group2_load_vertex(a7, i0, 0u); draft_group2_load_vertex(a7, i1, 1u); draft_group2_load_vertex(a7, i2, 2u);
                    draft_gte_command_adapter(0x280030u); w_u32(a2 + 12u, a8 | r_u32(a6 + 4u * i0));
                    draft_gte_command_adapter(0x158002Du); depth = xport_gte_read_data(7u);
                    if (depth) {
                        draft_gte_command_adapter(0x1400006u);
                        if ((int32)xport_gte_read_data(24u) >= 0) {
                            draft_group2_screens(a2 + 8u, 8u); draft_group2_link(a2, a5, depth, a10, 0x07000000u);
                            w_u32(a2 + 20u, a9 | r_u32(a6 + 4u * i1)); w_u32(a2 + 28u, r_u32(a6 + 4u * i2)); a2 += 32u;
                        }
                    }
                    --inner;
                    if (inner == 2u) { i1 = second; i2 = 10u; }
                    else { i0 = 11u; if (inner == 3u) { i0 = 9u; i1 = 10u; } else { i1 = 10u; i2 = third; } }
                } while (inner);
            }
        }
        --remaining;
        if (remaining == 2u) { second = 1u; third = 4u; }
        else { first = 5u; if (remaining == 3u) { first = 3u; second = 4u; } else { second = 4u; third = 2u; } }
    } while (remaining);
    return draft_scratch_result(native_stack_mark, (uint64)(a2));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8001C52C */
uint32 sub_8001C52C(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8, uint32 a9, uint32 a10)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index = 0u;
    (void)a3; (void)a4;
    do {
        uint32 depth, indices[4] = { index, index + 1u, index + 3u, index + 4u };
        int32 area;
        draft_group2_load_vertex(a7, indices[0], 0u); draft_group2_load_vertex(a7, indices[1], 1u); draft_group2_load_vertex(a7, indices[2], 2u);
        draft_gte_command_adapter(0x280030u); draft_group2_load_vertex(a7, indices[3], 0u);
        draft_gte_command_adapter(0x1400006u); area = (int32)xport_gte_read_data(24u);
        if (area < 0) area = (int32)(0u - (uint32)area);
        if (area < 1024) {
            draft_group2_screens(a2 + 8u, 8u); draft_gte_command_adapter(0x180001u);
            w_u32(a2 + 12u, a8 | r_u32(a6 + 4u * indices[0])); w_u32(a2 + 20u, a9 | r_u32(a6 + 4u * indices[1]));
            w_u32(a2 + 28u, r_u32(a6 + 4u * indices[2])); w_u32(a2 + 36u, r_u32(a6 + 4u * indices[3]));
            draft_gte_command_adapter(0x168002Eu); w_u32(a2 + 32u, xport_gte_read_data(14u)); depth = xport_gte_read_data(7u);
            draft_group2_link(a2, a5, depth, a10, 0x09000000u); a2 += 40u;
        } else {
            draft_group2_screens(a1, 4u); draft_group2_load_vertex(a7, indices[3], 0u);
            draft_gte_command_adapter(0x180001u); w_u32(a1 + 12u, xport_gte_read_data(14u));
            if (draft_group2_visible(a1, 4u)) {
                const uint32 pairs[10] = { 0u,1u,0u,2u,1u,2u,1u,3u,3u,2u };
                uint32 inner = 4u, i0 = index, i1 = 9u, i2 = 10u, i3 = 11u;
                draft_group2_midpoints(a7, a6, indices, pairs, 4u);
                do {
                    draft_group2_load_vertex(a7, i0, 0u); draft_group2_load_vertex(a7, i1, 1u); draft_group2_load_vertex(a7, i2, 2u);
                    draft_gte_command_adapter(0x280030u); draft_group2_load_vertex(a7, i3, 0u);
                    draft_group2_screens(a2 + 8u, 8u); draft_gte_command_adapter(0x180001u);
                    w_u32(a2 + 36u, r_u32(a6 + 4u * i3)); draft_gte_command_adapter(0x168002Eu); depth = xport_gte_read_data(7u);
                    if (depth) {
                        w_u32(a2 + 32u, xport_gte_read_data(14u)); w_u32(a2 + 12u, a8 | r_u32(a6 + 4u * i0)); w_u32(a2 + 20u, a9 | r_u32(a6 + 4u * i1));
                        w_u32(a2 + 28u, r_u32(a6 + 4u * i2)); draft_group2_link(a2, a5, depth, a10, 0x09000000u); a2 += 40u;
                    }
                    --inner;
                    if (inner == 2u) { i0 = 10u; i1 = 11u; i2 = index + 3u; i3 = 13u; }
                    else { i0 = 11u; if (inner == 3u) { i0 = 9u; i1 = index + 1u; i2 = 11u; i3 = 12u; } else { i1 = 12u; i2 = 13u; i3 = index + 4u; } }
                } while (inner);
            }
        }
        if (index++ == 1u) index = 3u;
    } while (index < 5u);
    return draft_scratch_result(native_stack_mark, (uint64)(a2));

    draft_scratch_release(native_stack_mark);
}

static void draft_group2_quad_scratch(uint32 vertices, uint32 indices_address, uint32 temporary, uint32 uv, uint32 source)
{
    uint32 component, i, addresses[4], positions[4] = { 0u, 2u, 6u, 8u };
    const uint32 midpoint_positions[5] = { 1u, 3u, 4u, 5u, 7u };
    const uint32 pairs[10] = { 0u,1u,0u,2u,1u,2u,1u,3u,2u,3u };
    for (i = 0u; i < 4u; ++i) addresses[i] = vertices + 8u * r_u16(indices_address + 2u * i);
    for (component = 0u; component < 3u; ++component) {
        int32 values[4];
        for (i = 0u; i < 4u; ++i) values[i] = (int16)r_u16(addresses[i] + 2u * component);
        w_u16(temporary + 2u * component, (uint16)values[0]); w_u16(temporary + 16u + 2u * component, (uint16)values[1]); w_u16(temporary + 48u + 2u * component, (uint16)values[2]);
        for (i = 0u; i < 5u; ++i) w_u16(temporary + 8u * midpoint_positions[i] + 2u * component, (uint16)((values[pairs[2u * i]] + values[pairs[2u * i + 1u]]) >> 1));
        w_u16(temporary + 64u + 2u * component, (uint16)values[3]);
    }
    w_u32(uv, r_u32(source + 4u) & 0xFFFFu); w_u32(uv + 8u, r_u16(source + 8u));
    w_u32(uv + 24u, r_u32(source + 12u)); w_u32(uv + 32u, r_u32(source + 16u));
    for (component = 0u; component < 2u; ++component) {
        uint32 values[4];
        for (i = 0u; i < 4u; ++i) values[i] = r_u8(uv + 4u * positions[i] + component);
        for (i = 0u; i < 5u; ++i) w_u8(uv + 4u * midpoint_positions[i] + component, (uint8)((values[pairs[2u * i]] + values[pairs[2u * i + 1u]]) >> 1));
    }
}

/* FUNCTION_MARKER: sub_8001BF94 */
uint32 sub_8001BF94(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    (void)a5;
    while (a7) {
        uint32 depth, entry;
        draft_group2_load_vertex(a2, r_u16(a3 + 24u), 0u); draft_group2_load_vertex(a2, r_u16(a3 + 26u), 1u); draft_group2_load_vertex(a2, r_u16(a3 + 28u), 2u);
        draft_gte_command_adapter(0x280030u); draft_group2_load_vertex(a2, r_u16(a3 + 30u), 0u); draft_gte_command_adapter(0x158002Du);
        --a7; depth = xport_gte_read_data(7u);
        if (depth) {
            draft_gte_command_adapter(0x1400006u);
            if ((int32)xport_gte_read_data(24u) >= 0) {
                draft_group2_screens(a1 + 8u, 8u); w_u32(a1 + 36u, r_u32(a3 + 16u)); draft_gte_command_adapter(0x180001u);
                w_u32(a1 + 4u, r_u32(a3 + 20u)); w_u32(a1 + 12u, r_u32(a3 + 4u)); w_u32(a1 + 20u, r_u32(a3 + 8u)); w_u32(a1 + 28u, r_u32(a3 + 12u)); w_u32(a1 + 32u, xport_gte_read_data(14u));
                entry = a4 + 4u * a6 + 4u * (depth >> 3); w_u32(a1, (r_u32(entry) & 0xFFFFFFu) | 0x09000000u); w_u32(entry, (r_u32(entry) & 0xFF000000u) | (a1 & 0xFFFFFFu)); a1 += 40u;
            }
        }
        a3 += 32u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800176BC */
uint32 sub_800176BC(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = a7 ? draft_scratch_adapter(128u) : 0u;
    while (a7) {
        int32 flag, area = 0;
        uint32 entry, depth;
        draft_group2_load_vertex(a2, r_u16(a3 + 24u), 0u); draft_group2_load_vertex(a2, r_u16(a3 + 26u), 1u); draft_group2_load_vertex(a2, r_u16(a3 + 28u), 2u);
        draft_gte_command_adapter(0x280030u); --a7; draft_group2_load_vertex(a2, r_u16(a3 + 30u), 0u); flag = (int32)draft_gte_control_adapter(31u);
        if (flag >= 0) { draft_gte_command_adapter(0x1400006u); area = (int32)xport_gte_read_data(24u); }
        if (flag < 0 || area >= 1024) {
            draft_group2_screens(temporary + 112u, 4u); draft_gte_command_adapter(0x180001u); xport_gte_write_data(22u, r_u32(a3 + 20u));
            if (flag >= 0) (void)draft_gte_control_adapter(31u);
            w_u32(temporary + 124u, xport_gte_read_data(14u));
            if (draft_group2_visible(temporary + 112u, 4u)) {
                draft_group2_quad_scratch(a2, a3 + 24u, temporary, a5, a3);
                if (flag < 0) a1 = (uint32)draft_call_adapter(0x8001CB7Cu, temporary + 112u, a1, a2, a3, a4, a5, temporary, r_u32(a3 + 4u) & 0xFFFF0000u, r_u32(a3 + 8u) & 0xFFFF0000u, a6);
                else a1 = sub_8001C52C(temporary + 112u, a1, a2, a3, a4, a5, temporary, r_u32(a3 + 4u) & 0xFFFF0000u, r_u32(a3 + 8u) & 0xFFFF0000u, a6);
            }
        } else if (area >= 0) {
            draft_group2_screens(a1 + 8u, 8u); w_u32(a1 + 12u, r_u32(a3 + 4u)); draft_gte_command_adapter(0x180001u);
            w_u32(a1 + 20u, r_u32(a3 + 8u)); w_u32(a1 + 28u, r_u32(a3 + 12u)); w_u32(a1 + 36u, r_u32(a3 + 16u)); draft_gte_command_adapter(0x168002Eu);
            w_u32(a1 + 4u, r_u32(a3 + 20u)); w_u32(a1 + 32u, xport_gte_read_data(14u)); depth = xport_gte_read_data(7u);
            entry = a4 + 4u * a6 + 4u * (depth >> 3); w_u32(a1, (r_u32(entry) & 0xFFFFFFu) | 0x09000000u); w_u32(entry, (r_u32(entry) & 0xFF000000u) | (a1 & 0xFFFFFFu)); a1 += 40u;
        }
        a3 += 32u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80016770 */
uint32 sub_80016770(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = a7 ? draft_scratch_adapter(128u) : 0u;
    xport_gte_write_data(6u, 0x2C808080u);
    while (a7) {
        int32 flag;
        uint32 area = 0u, depth;
        draft_group2_load_vertex(a2, r_u16(a3 + 22u), 0u); draft_group2_load_vertex(a2, r_u16(a3 + 24u), 1u); draft_group2_load_vertex(a2, r_u16(a3 + 26u), 2u);
        draft_gte_command_adapter(0x280030u); draft_group2_load_vertex(a2, r_u16(a3 + 28u), 0u); --a7; flag = (int32)draft_gte_control_adapter(31u);
        if (flag >= 0) { draft_gte_command_adapter(0x1400006u); area = xport_gte_read_data(24u); }
        if (flag < 0 || area + 1023u >= 0x7FFu) {
            draft_group2_screens(temporary + 112u, 4u); draft_gte_command_adapter(0x180001u); draft_group2_load_vertex(a2, r_u16(a3 + 20u), 0u);
            if (flag >= 0) (void)draft_gte_control_adapter(31u);
            w_u32(temporary + 124u, xport_gte_read_data(14u));
            if (draft_group2_visible(temporary + 112u, 4u)) {
                draft_gte_command_adapter(0xE80413u); draft_group2_quad_scratch(a2, a3 + 22u, temporary, a5, a3);
                if (flag < 0) a1 = (uint32)draft_call_adapter(0x8001D204u, temporary + 112u, a1, a2, a3, a4, a5, temporary, r_u32(a3 + 4u) & 0xFFFF0000u, r_u32(a3 + 8u) & 0xFFFF0000u, a6);
                else a1 = sub_8001C52C(temporary + 112u, a1, a2, a3, a4, a5, temporary, r_u32(a3 + 4u) & 0xFFFF0000u, r_u32(a3 + 8u) & 0xFFFF0000u, a6);
            }
        } else {
            draft_group2_screens(a1 + 8u, 8u); w_u32(a1 + 12u, r_u32(a3 + 4u)); draft_gte_command_adapter(0x180001u); draft_group2_load_vertex(a2, r_u16(a3 + 20u), 0u);
            w_u32(a1 + 36u, r_u32(a3 + 16u)); draft_gte_command_adapter(0x168002Eu); w_u32(a1 + 20u, r_u32(a3 + 8u)); w_u32(a1 + 32u, xport_gte_read_data(14u)); depth = xport_gte_read_data(7u);
            draft_gte_command_adapter(0xE80413u); w_u32(a1 + 28u, r_u32(a3 + 12u)); draft_group2_link(a1, a4, depth, a6, 0x09000000u); a1 += 40u;
        }
        a3 += 32u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800188E4 */
uint32 sub_800188E4(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = a7 ? draft_scratch_adapter(128u) : 0u;
    while (a7) {
        uint32 i, component, vertex[3], entry, depth;
        int32 flag, area;
        for (i = 0u; i < 3u; ++i) { vertex[i] = r_u16(a3 + 20u + 2u * i); draft_group2_load_vertex(a2, vertex[i], i); }
        draft_gte_command_adapter(0x280030u); --a7; xport_gte_write_data(22u, r_u32(a3 + 16u)); flag = (int32)draft_gte_control_adapter(31u);
        draft_gte_command_adapter(0x1400006u); area = (int32)xport_gte_read_data(24u);
        if (flag < 0 || area >= 1024) {
            draft_group2_screens(temporary + 112u, 4u);
            if (draft_group2_visible(temporary + 112u, 3u)) {
                for (component = 0u; component < 3u; ++component) {
                    int32 v0 = (int16)r_u16(a2 + 8u * vertex[0] + 2u * component), v1 = (int16)r_u16(a2 + 8u * vertex[1] + 2u * component), v2 = (int16)r_u16(a2 + 8u * vertex[2] + 2u * component);
                    w_u16(temporary + 2u * component, (uint16)v0); w_u16(temporary + 8u + 2u * component, (uint16)v1);
                    w_u16(temporary + 24u + 2u * component, (uint16)((v0 + v1) >> 1)); w_u16(temporary + 32u + 2u * component, (uint16)((v1 + v2) >> 1));
                    w_u16(temporary + 16u + 2u * component, (uint16)v2); w_u16(temporary + 40u + 2u * component, (uint16)((v0 + v2) >> 1));
                }
                w_u32(a5, r_u32(a3 + 4u) & 0xFFFFu); w_u32(a5 + 4u, r_u16(a3 + 8u)); w_u32(a5 + 8u, r_u32(a3 + 12u));
                for (component = 0u; component < 2u; ++component) {
                    uint32 v0 = r_u8(a5 + component), v1 = r_u8(a5 + 4u + component), v2 = r_u8(a5 + 8u + component);
                    w_u8(a5 + 12u + component, (uint8)((v0 + v1) >> 1)); w_u8(a5 + 16u + component, (uint8)((v1 + v2) >> 1)); w_u8(a5 + 20u + component, (uint8)((v0 + v2) >> 1));
                }
                a1 = sub_8001EABC(temporary + 112u, a1, a2, a3, a4, a5, temporary, r_u32(a3 + 4u) & 0xFFFF0000u, r_u32(a3 + 8u) & 0xFFFF0000u, a6);
            }
        } else if (area >= 0) {
            draft_group2_screens(a1 + 8u, 8u); w_u32(a1 + 12u, r_u32(a3 + 4u)); draft_gte_command_adapter(0x158002Du);
            w_u32(a1 + 20u, r_u32(a3 + 8u)); w_u32(a1 + 28u, r_u32(a3 + 12u)); w_u32(a1 + 4u, r_u32(a3 + 16u)); depth = xport_gte_read_data(7u);
            entry = a4 + 4u * a6 + 4u * (depth >> 3); w_u32(a1, (r_u32(entry) & 0xFFFFFFu) | 0x07000000u); w_u32(entry, (r_u32(entry) & 0xFF000000u) | (a1 & 0xFFFFFFu)); a1 += 32u;
        }
        a3 += 28u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}
