#include "draft_signatures.h"

static void draft_round1_load_vertex(uint32 vertices, uint32 index, uint32 slot)
{
    xport_gte_write_data(2u * slot, r_u32(vertices + 8u * index));
    xport_gte_write_data(2u * slot + 1u, r_u32(vertices + 8u * index + 4u));
}

static void draft_round1_screens(uint32 destination, uint32 stride)
{
    w_u32(destination, xport_gte_read_data(12u));
    w_u32(destination + stride, xport_gte_read_data(13u));
    w_u32(destination + 2u * stride, xport_gte_read_data(14u));
}

static int draft_round1_visible(uint32 screens, uint32 count)
{
    uint32 i;
    int left = 0, right = 0, top = 0, bottom = 0;
    for (i = 0; i < count; ++i) {
        int32 x = (int16)r_u16(screens + 4u * i), y = (int16)r_u16(screens + 4u * i + 2u);
        left |= x < 320; right |= x > 0; top |= y < 240; bottom |= y > 0;
    }
    return left && right && top && bottom;
}

static void draft_round1_link(uint32 packet, uint32 ordering, uint32 depth, uint32 bias, uint32 tag)
{
    uint32 entry = ordering + 4u * (depth >> 3) + 4u * bias;
    w_u32(packet, (r_u32(entry) & 0xFFFFFFu) | tag);
    w_u32(entry, (r_u32(entry) & 0xFF000000u) | (packet & 0xFFFFFFu));
    w_u32(packet + 4u, xport_gte_read_data(22u));
}

static void draft_round1_midpoints(uint32 vertices, uint32 uv, const uint32 *indices, const uint32 *pairs, uint32 count)
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


static void draft_round1_tag(uint32 packet, uint32 ordering, uint32 depth, uint32 bias, uint32 tag)
{
    uint32 entry = ordering + 4u * bias + 4u * (depth >> 3);
    w_u32(packet, (r_u32(entry) & 0xFFFFFFu) | tag); w_u32(entry, (r_u32(entry) & 0xFF000000u) | (packet & 0xFFFFFFu));
}

/* FUNCTION_MARKER: sub_8001B3B4 */
uint32 sub_8001B3B4(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    (void)a5; xport_gte_write_data(6u, 0x34808080u);
    while (a7) {
        uint32 i, depth;
        for (i = 0u; i < 3u; ++i) draft_round1_load_vertex(a2, r_u16(a3 + 18u + 4u * i), i);
        draft_gte_command_adapter(0x280030u);
        for (i = 0u; i < 3u; ++i) draft_round1_load_vertex(a2, r_u16(a3 + 16u + 4u * i), i);
        draft_gte_command_adapter(0x158002Du); --a7; depth = xport_gte_read_data(7u);
        if (depth) {
            draft_gte_command_adapter(0x1400006u);
            if ((int32)xport_gte_read_data(24u) >= 0) {
                draft_round1_screens(a1 + 8u, 12u); w_u32(a1 + 36u, r_u32(a3 + 12u)); draft_gte_command_adapter(0xF80416u);
                draft_round1_tag(a1, a4, depth, a6, 0x09000000u); w_u32(a1 + 12u, r_u32(a3 + 4u)); w_u32(a1 + 24u, r_u32(a3 + 8u));
                w_u32(a1 + 4u, xport_gte_read_data(20u)); w_u32(a1 + 16u, xport_gte_read_data(21u)); w_u32(a1 + 28u, xport_gte_read_data(22u)); a1 += 40u;
            }
        }
        a3 += 28u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8001B560 */
uint32 sub_8001B560(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    (void)a5; xport_gte_write_data(6u, 0x3C808080u);
    while (a7) {
        uint32 i, depth;
        for (i = 0u; i < 3u; ++i) draft_round1_load_vertex(a2, r_u16(a3 + 22u + 4u * i), i);
        draft_gte_command_adapter(0x280030u); draft_round1_load_vertex(a2, r_u16(a3 + 34u), 0u); draft_gte_command_adapter(0x158002Du); --a7; depth = xport_gte_read_data(7u);
        if (depth) {
            draft_gte_command_adapter(0x1400006u);
            if ((int32)xport_gte_read_data(24u) >= 0) {
                draft_round1_screens(a1 + 8u, 12u); draft_gte_command_adapter(0x180001u);
                for (i = 0u; i < 3u; ++i) draft_round1_load_vertex(a2, r_u16(a3 + 20u + 4u * i), i);
                w_u32(a1 + 44u, xport_gte_read_data(14u)); w_u32(a1 + 48u, r_u32(a3 + 16u)); draft_gte_command_adapter(0xF80416u);
                w_u32(a1 + 12u, r_u32(a3 + 4u)); w_u32(a1 + 24u, r_u32(a3 + 8u)); w_u32(a1 + 36u, r_u32(a3 + 12u));
                w_u32(a1 + 4u, xport_gte_read_data(20u)); w_u32(a1 + 16u, xport_gte_read_data(21u)); w_u32(a1 + 28u, xport_gte_read_data(22u));
                draft_round1_load_vertex(a2, r_u16(a3 + 32u), 0u); draft_gte_command_adapter(0xE80413u); draft_round1_tag(a1, a4, depth, a6, 0x0C000000u); w_u32(a1 + 40u, xport_gte_read_data(22u)); a1 += 52u;
            }
        }
        a3 += 36u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8001BB70 */
uint32 sub_8001BB70(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 saved[8], i;
    xport_gte_write_data(6u, 0x34808080u);
    for (i = 0u; i < 8u; ++i) saved[i] = draft_gte_control_adapter(i);
    while (a7) {
        uint32 depth, matrix, first_ir, second_ir, third_ir;
        for (i = 0u; i < 3u; ++i) draft_round1_load_vertex(a2, r_u16(a3 + 18u + 4u * i), i);
        draft_gte_command_adapter(0x280030u);
        for (i = 0u; i < 3u; ++i) draft_round1_load_vertex(a2, r_u16(a3 + 16u + 4u * i), i);
        --a7; draft_gte_command_adapter(0x158002Du); depth = xport_gte_read_data(7u);
        if (depth) {
            draft_gte_command_adapter(0x1400006u);
            if ((int32)xport_gte_read_data(24u) >= 0) {
                draft_round1_screens(a1 + 8u, 12u); matrix = r_u32(0x800A84B0u);
                for (i = 0u; i < 5u; ++i) xport_gte_write_control(i, r_u32(matrix + 4u * i));
                draft_gte_command_adapter(0x486012u); w_u32(a5, r_u16(a3 + 4u)); w_u32(a5 + 4u, r_u16(a3 + 8u)); first_ir = xport_gte_read_data(9u); (void)xport_gte_read_data(10u); (void)xport_gte_read_data(11u);
                draft_gte_command_adapter(0x48E012u); w_u8(a5, (uint8)(((int16)first_ir >> 6) + 64)); w_u32(a5 + 8u, r_u32(a3 + 12u));
                second_ir = xport_gte_read_data(9u); (void)xport_gte_read_data(10u); (void)xport_gte_read_data(11u); draft_gte_command_adapter(0x496012u); w_u8(a5 + 4u, (uint8)(((int16)second_ir >> 6) + 64));
                third_ir = xport_gte_read_data(9u); (void)xport_gte_read_data(10u); (void)xport_gte_read_data(11u);
                for (i = 0u; i < 5u; ++i) xport_gte_write_control(i, saved[i]); w_u8(a5 + 8u, (uint8)(((int16)third_ir >> 6) + 64));
                draft_gte_command_adapter(0xF80416u); w_u32(a1 + 12u, (r_u32(a3 + 4u) & 0xFFFF0000u) | r_u32(a5)); w_u32(a1 + 24u, (r_u32(a3 + 8u) & 0xFFFF0000u) | r_u32(a5 + 4u));
                w_u32(a1 + 36u, r_u32(a5 + 8u)); draft_round1_tag(a1, a4, depth, a6, 0x09000000u);
                w_u32(a1 + 4u, xport_gte_read_data(20u)); w_u32(a1 + 16u, xport_gte_read_data(21u)); w_u32(a1 + 28u, xport_gte_read_data(22u)); a1 += 40u;
            }
        }
        a3 += 28u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8001CB7C */
uint32 sub_8001CB7C(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8, uint32 a9, uint32 a10)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index = 0u;
    (void)a3; (void)a4;
    do {
        uint32 depth, indices[4] = {index,index + 1u,index + 3u,index + 4u};
        int32 flag, area;
        draft_round1_load_vertex(a7, indices[0], 0u); draft_round1_load_vertex(a7, indices[1], 1u); draft_round1_load_vertex(a7, indices[2], 2u); draft_gte_command_adapter(0x280030u); draft_round1_load_vertex(a7, indices[3], 0u);
        flag = (int32)draft_gte_control_adapter(31u); draft_gte_command_adapter(0x1400006u); area = (int32)xport_gte_read_data(24u);
        if (flag >= 0 && area < 1024) {
            draft_round1_screens(a2 + 8u, 8u); draft_gte_command_adapter(0x180001u);
            w_u32(a2 + 12u, a8 | r_u32(a6 + 4u * indices[0])); w_u32(a2 + 20u, a9 | r_u32(a6 + 4u * indices[1])); w_u32(a2 + 28u, r_u32(a6 + 4u * indices[2])); draft_gte_command_adapter(0x168002Eu); w_u32(a2 + 36u, r_u32(a6 + 4u * indices[3]));
            w_u32(a2 + 32u, xport_gte_read_data(14u)); depth = xport_gte_read_data(7u); draft_round1_link(a2, a5, depth, a10, 0x09000000u); a2 += 40u;
        } else {
            draft_round1_screens(a1, 4u); draft_round1_load_vertex(a7, indices[3], 0u); draft_gte_command_adapter(0x180001u); w_u32(a1 + 12u, xport_gte_read_data(14u));
            if (draft_round1_visible(a1, 4u)) {
                const uint32 pairs[10] = {0u,1u,0u,2u,1u,2u,1u,3u,3u,2u};
                uint32 inner = 4u, i0 = index, i1 = 9u, i2 = 10u, i3 = 11u;
                draft_round1_midpoints(a7, a6, indices, pairs, 4u);
                do {
                    draft_round1_load_vertex(a7, i0, 0u); draft_round1_load_vertex(a7, i1, 1u); draft_round1_load_vertex(a7, i2, 2u); draft_gte_command_adapter(0x280030u); draft_round1_load_vertex(a7, i3, 0u); draft_gte_command_adapter(0x1400006u);
                    if ((int32)xport_gte_read_data(24u) >= 0) {
                        draft_round1_screens(a2 + 8u, 8u); draft_gte_command_adapter(0x180001u); w_u32(a2 + 36u, r_u32(a6 + 4u * i3)); draft_gte_command_adapter(0x168002Eu); depth = xport_gte_read_data(7u);
                        if (depth) {
                            w_u32(a2 + 12u, a8 | r_u32(a6 + 4u * i0)); w_u32(a2 + 20u, a9 | r_u32(a6 + 4u * i1)); w_u32(a2 + 28u, r_u32(a6 + 4u * i2)); w_u32(a2 + 32u, xport_gte_read_data(14u)); draft_round1_link(a2, a5, depth, a10, 0x09000000u); a2 += 40u;
                        }
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
