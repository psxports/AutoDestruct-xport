#include "xport.h"
#include "psx.h"
#include "draft_adapters.h"

static void ad_render_rotation(const sint32 *matrix)
{
    for (uint32 i = 0; i < 5u; ++i)
        xport_gte_write_control(i, (uint32)matrix[i]);
}

static void ad_render_compose(const sint32 *left, uint32 right, uint32 destination)
{
    ad_render_rotation(left);
    for (uint32 column = 0; column < 3u; ++column)
    {
        xport_gte_write_data(9u, r_u16(right + 2u * column));
        xport_gte_write_data(10u, r_u16(right + 6u + 2u * column));
        xport_gte_write_data(11u, r_u16(right + 12u + 2u * column));
        xport_gte_execute(0x49E012u);
        w_u16(destination + 2u * column, xport_gte_read_data(9u));
        w_u16(destination + 6u + 2u * column, xport_gte_read_data(10u));
        w_u16(destination + 12u + 2u * column, xport_gte_read_data(11u));
    }
}

static sint32 ad_render_edge(uint32 a, uint32 b, uint32 c, uint32 d)
{
    return (sint32)(a * b + c * d);
}

static sint32 ad_render_inside(const sint32 *quad, uint32 x, uint32 z, sint32 full_quad)
{
    const uint32 *q = (const uint32 *)quad;
    if (full_quad)
    {
        if (ad_render_edge(q[5] - q[7], x - q[6], q[6] - q[4], z - q[7]) < 0)
            return 0;
        if (ad_render_edge(q[7] - q[1], x - q[0], q[0] - q[6], z - q[1]) < 0)
            return 0;
    }
    else if (ad_render_edge(q[5] - q[1], x - q[0], q[0] - q[4], z - q[1]) < 0)
        return 0;
    if (ad_render_edge(q[3] - q[5], x - q[4], q[4] - q[2], z - q[5]) < 0)
        return 0;
    if (full_quad && ad_render_edge(q[1] - q[3], x - q[2], q[2] - q[0], z - q[3]) < 0)
        return 0;
    return 1;
}

uint32 sub_80014A68(uint32 object_address, uint32 view_address, uint32 clip_address, uint32 render_context, uint32 output_cursor)
{
    const sint32 *object_matrix = (const sint32 *)psx_addr(object_address, 32u);
    const sint32 *view_matrix = (const sint32 *)psx_addr(view_address, 32u);
    const sint32 *clip_quad = (const sint32 *)psx_addr(clip_address, 32u);
    uint32 stack_mark = draft_scratch_mark();
    uint32 temporary = draft_scratch_adapter(80u), rotation = temporary, light = temporary + 32u, next_record = temporary + 56u;
    uint32 vertices = r_u32(r_u32(0x800A7E08u)), ordering_table = r_u32(0x800A9A74u);
    sint32 full_quad = r_u8(0x800A7E80u) >= 3u;
    FUNCTION_MARKER(0x80014A68u, "1.EXE");
    w_u32(0x800A9A6Cu, rotation);
    for (sint32 region = 3; region >= 0; --region)
    {
        uint32 regional_matrix = 0x800A99B0u + (uint32)region * 32u;
        uint32 count, table;
        ad_render_compose(object_matrix, regional_matrix, rotation);
        ad_render_compose(view_matrix, regional_matrix, light);
        for (uint32 i = 0; i < 5u; ++i)
            xport_gte_write_control(8u + i, r_u32(light + 4u * i));
        count = r_u32(0x800A6370u + (uint32)region * 4u);
        table = r_u32(0x800A6380u + (uint32)region * 4u);
        while (count)
        {
            uint32 face = r_u32(table + 4u * --count), asset, total, consumed = 0u;
            uint32 x = r_u32(face + 4u), y = r_u32(face + 8u), z = r_u32(face + 12u);
            if (!ad_render_inside(clip_quad, x, z, full_quad))
                continue;
            for (uint32 i = 0; i < 8u; ++i)
                xport_gte_write_control(i, (uint32)object_matrix[i]);
            xport_gte_write_data(0u, (x & 0xFFFFu) | ((y & 0xFFFFu) << 16));
            xport_gte_write_data(1u, z);
            asset = r_u32(0x800C0E00u + 4u * r_u16(face));
            xport_gte_execute(0x480012u);
            total = r_u32(asset + 4u);
            w_u32(next_record, r_u32(asset));
            for (uint32 i = 0; i < 3u; ++i)
                w_u32(rotation + 20u + i * 4u, xport_gte_read_data(25u + i));
            for (uint32 i = 0; i < 8u; ++i)
                xport_gte_write_control(i, r_u32(rotation + i * 4u));
            while (consumed < total)
            {
                uint32 source = r_u32(next_record), header = r_u32(source), packet_count = header & 0x7FFu;
                uint32 handler = r_u32(0x8008B6C4u + 4u * (header >> 24));
                consumed += packet_count;
                output_cursor = (uint32)draft_call_adapter(handler, output_cursor, vertices, source, ordering_table, render_context, 0x205u, packet_count, next_record);
            }
        }
    }
    draft_scratch_release(stack_mark);
    return output_cursor;
}

uint32 sub_8001F640(uint32 cursor, uint32 vertices, uint32 source, uint32 ordering_table, uint32 render_context, uint32 depth_bias, uint32 count, uint32 next_source)
{
    uint32 header = r_u32(source);
    uint32 bytes;
    FUNCTION_MARKER(0x8001F640u, "1.EXE");
    if (header & 0x800u)
        bytes = ((header >> 10u) & 0x3FFCu) + 4u;
    else
        bytes = ((((header >> 12u) & 0xFFFu) + 1u) * count) << 2u;
    w_u32(next_source, source + bytes);
    return cursor;
}

uint32 sub_8001C4DC(uint32 cursor, uint32 vertices, uint32 source, uint32 ordering_table, uint32 render_context, uint32 depth_bias, uint32 count, uint32 next_source)
{
    uint32 header = r_u32(source);
    uint32 bytes;
    FUNCTION_MARKER(0x8001C4DCu, "1.EXE");
    if (header & 0x800u)
        bytes = ((header >> 10u) & 0x3FFCu) + 4u;
    else
        bytes = ((((header >> 12u) & 0xFFFu) + 1u) * count) << 2u;
    w_u32(next_source, source + bytes);
    return cursor;
}

uint32 sub_80019854(uint32 cursor, uint32 vertices, uint32 source, uint32 ordering_table, uint32 render_context, uint32 depth_bias, uint32 count, uint32 next_source)
{
    uint32 next_record = source;
    uint32 record = source + 12u;
    FUNCTION_MARKER(0x80019854u, "1.EXE");
    while (count)
    {
        uint32 index, depth;
        for (index = 0u; index < 3u; ++index)
        {
            uint32 vertex = vertices + 8u * r_u16(record + 8u + 2u * index);
            xport_gte_write_data(index * 2u, r_u32(vertex));
            xport_gte_write_data(index * 2u + 1u, r_u32(vertex + 4u));
        }
        xport_gte_execute(0x280030u);
        w_u32(cursor + 4u, r_u32(record + 4u));
        xport_gte_execute(0x158002Du);
        --count;
        depth = xport_gte_read_data(7u);
        next_record += 28u;
        if (depth)
        {
            uint32 link;
            w_u32(cursor + 8u, xport_gte_read_data(12u));
            w_u32(cursor + 16u, xport_gte_read_data(13u));
            w_u32(cursor + 24u, xport_gte_read_data(14u));
            link = ordering_table + 4u * depth_bias + 4u * (depth >> 3u);
            w_u32(cursor, (r_u32(link) & 0xFFFFFFu) | 0x07000000u);
            w_u32(link, (r_u32(link) & 0xFF000000u) | (cursor & 0xFFFFFFu));
            w_u32(cursor + 12u, r_u32(record - 8u));
            w_u32(cursor + 20u, r_u32(record - 4u));
            w_u32(cursor + 28u, r_u32(record));
            cursor += 32u;
        }
        record += 28u;
    }
    w_u32(next_source, next_record);
    return cursor;
}
