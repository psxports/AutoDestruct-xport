#include "draft_signatures.h"

static void draft_round2_gt3_vertices(uint32 vertices, const uint32 indices[3])
{
    uint32 i;
    for (i = 0; i < 3u; ++i)
    {
        xport_gte_write_data(i * 2u, r_u32(vertices + indices[i] * 8u));
        xport_gte_write_data(i * 2u + 1u, r_u32(vertices + indices[i] * 8u + 4u));
    }
}

static void draft_round2_gt3_emit(uint32 packet, uint32 ot, uint32 uv, uint32 clut, uint32 page, uint32 bias, uint32 colors, const uint32 indices[3], uint32 depth)
{
    uint32 i, entry = ot + (bias + (depth >> 3)) * 4u;
    for (i = 0; i < 3u; ++i)
    {
        w_u32(packet + 8u + i * 12u, xport_gte_read_data(12u + i));
        w_u32(packet + 12u + i * 12u, r_u32(uv + indices[i] * 4u) | (i == 0u ? clut : i == 1u ? page : 0u));
        w_u32(packet + 4u + i * 12u, i == 0u ? (r_u32(colors + indices[i] * 4u) & 0xFFFFFFu) | 0x34000000u : r_u32(colors + indices[i] * 4u));
    }
    w_u32(packet, (r_u32(entry) & 0xFFFFFFu) | 0x09000000u);
    w_u32(entry, (r_u32(entry) & 0xFF000000u) | (packet & 0xFFFFFFu));
}

/* FUNCTION_MARKER: sub_8001F008 */
uint32 sub_8001F008(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8, uint32 a9, uint32 a10, uint32 a11)
{
    uint32 native_stack_mark = draft_scratch_mark();

    static const uint32 triangles[4][3] = {{0u, 3u, 5u}, {3u, 4u, 5u}, {3u, 1u, 4u}, {5u, 4u, 2u}};
    uint32 outer;
    for (outer = 0; outer < 4u; ++outer)
    {
        const uint32 *indices = triangles[outer];
        uint32 i, j, depth, flag, area;
        int left = 0, right = 0, top = 0, bottom = 0;
        draft_round2_gt3_vertices(a7, indices);
        draft_gte_command_adapter(0x280030u);
        w_u32(a2 + 12u, a8 | r_u32(a6 + indices[0] * 4u));
        flag = draft_gte_control_adapter(31u);
        draft_gte_command_adapter(0x1400006u);
        area = xport_gte_read_data(24u);
        if ((int32)flag >= 0 && area < 1024u)
        {
            draft_gte_command_adapter(0x158002Du);
            depth = xport_gte_read_data(7u);
            draft_round2_gt3_emit(a2, a5, a6, a8, a9, a10, a11, indices, depth);
            a2 += 40u;
            continue;
        }
        for (i = 0; i < 3u; ++i)
        {
            uint32 screen = xport_gte_read_data(12u + i);
            int32 x = (int16)screen, y = (int16)(screen >> 16);
            w_u32(a1 + i * 4u, screen);
            left |= x < 320;
            right |= x > 0;
            top |= y < 240;
            bottom |= y > 0;
        }
        if (!(left && right && top && bottom))
            continue;
        for (i = 0; i < 3u; ++i)
        {
            static const uint32 pairs[3][2] = {{0u, 1u}, {1u, 2u}, {0u, 2u}};
            uint32 first = indices[pairs[i][0]], second = indices[pairs[i][1]], middle = 9u + i;
            for (j = 0; j < 3u; ++j)
                w_u16(a7 + middle * 8u + j * 2u, (uint16)(((int16)r_u16(a7 + first * 8u + j * 2u) + (int16)r_u16(a7 + second * 8u + j * 2u)) >> 1));
            for (j = 0; j < 2u; ++j)
                w_u8(a6 + middle * 4u + j, (uint8)((r_u8(a6 + first * 4u + j) + r_u8(a6 + second * 4u + j)) >> 1));
            for (j = 0; j < 3u; ++j)
                w_u8(a11 + middle * 4u + j, (uint8)((r_u8(a11 + first * 4u + j) + r_u8(a11 + second * 4u + j)) >> 1));
        }
        for (i = 0; i < 4u; ++i)
        {
            uint32 inner[3];
            if (i == 0u)
            {
                inner[0] = indices[0];
                inner[1] = 9u;
                inner[2] = 11u;
            }
            else if (i == 1u)
            {
                inner[0] = 9u;
                inner[1] = 10u;
                inner[2] = 11u;
            }
            else if (i == 2u)
            {
                inner[0] = 11u;
                inner[1] = indices[1];
                inner[2] = 10u;
            }
            else
            {
                inner[0] = 11u;
                inner[1] = 10u;
                inner[2] = indices[2];
            }
            draft_round2_gt3_vertices(a7, inner);
            draft_gte_command_adapter(0x280030u);
            w_u32(a2 + 12u, a8 | r_u32(a6 + inner[0] * 4u));
            draft_gte_command_adapter(0x1400006u);
            if ((int32)xport_gte_read_data(24u) < 0)
                continue;
            draft_gte_command_adapter(0x158002Du);
            depth = xport_gte_read_data(7u);
            if (!depth)
                continue;
            draft_round2_gt3_emit(a2, a5, a6, a8, a9, a10, a11, inner, depth);
            a2 += 40u;
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(a2));

    draft_scratch_release(native_stack_mark);
}
