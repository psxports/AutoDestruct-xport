#include "psx.h"

uint32 sub_8001ABB0(uint32 cursor, uint32 vertices, uint32 source, uint32 ordering, uint32 unused, uint32 depth_bias, uint32 count, uint32 next_source)
{
    uint32 saved[8], index;
    uint32 matrix = r_u32(0x800A9A6Cu);
    uint32 destination = cursor + 36u;
    FUNCTION_MARKER(0x8001ABB0u, "1.EXE");
    for (index = 0u; index < 8u; ++index)
        saved[index] = r_u32(matrix + index * 4u);
    depth_bias <<= 2u;
    while (count != 0u)
    {
        uint32 center = vertices + 8u * r_u16(source + 18u);
        uint32 x = (uint32)(sint32)(sint16)r_u16(center);
        uint32 y = (uint32)(sint32)(sint16)r_u16(center + 2u);
        uint32 z = (uint32)(sint32)(sint16)r_u16(center + 4u);
        uint32 radius = r_u16(source + 14u);
        uint32 negative = (0u - radius) & 0xFFFFu;
        uint32 translation[3], depth;
        xport_gte_write_data(0u, (x & 0xFFFFu) | (y << 16u));
        xport_gte_write_data(1u, z);
        xport_gte_execute(0x480012u);
        for (index = 0u; index < 3u; ++index)
            translation[index] = xport_gte_read_data(25u + index);
        xport_gte_write_control(0u, 0x1000u);
        xport_gte_write_control(1u, 0u);
        xport_gte_write_control(2u, 0x1000u);
        xport_gte_write_control(3u, 0u);
        xport_gte_write_control(4u, 0x1000u);
        for (index = 0u; index < 3u; ++index)
            xport_gte_write_control(5u + index, translation[index]);
        xport_gte_write_data(0u, negative | (negative << 16u));
        xport_gte_write_data(1u, 0u);
        xport_gte_execute(0x180001u);
        --count;
        // Preserve the original speculative UV write even for a culled quad
        w_u32(destination - 24u, r_u32(source + 4u));
        depth = xport_gte_read_data(19u);
        if (depth != 0u)
        {
            uint32 slot;
            w_u32(cursor + 32u, xport_gte_read_data(14u));
            xport_gte_write_data(0u, radius | (radius << 16u));
            xport_gte_write_data(1u, 0u);
            xport_gte_write_data(2u, negative | (radius << 16u));
            xport_gte_write_data(3u, 0u);
            xport_gte_write_data(4u, radius | (negative << 16u));
            xport_gte_write_data(5u, 0u);
            w_u32(destination - 32u, r_u32(source + 20u));
            xport_gte_execute(0x280030u);
            w_u32(destination - 16u, r_u32(source + 8u));
            w_u32(destination - 8u, r_u32(source + 12u));
            slot = ordering + ((depth >> 5u) << 2u) + depth_bias;
            w_u32(destination, r_u32(source + 16u));
            w_u32(cursor, (r_u32(slot) & 0xFFFFFFu) | 0x09000000u);
            w_u32(slot, (r_u32(slot) & 0xFF000000u) | (cursor & 0xFFFFFFu));
            w_u32(cursor + 8u, xport_gte_read_data(12u));
            w_u32(cursor + 16u, xport_gte_read_data(13u));
            w_u32(cursor + 24u, xport_gte_read_data(14u));
            destination += 40u;
            cursor += 40u;
        }
        for (index = 0u; index < 8u; ++index)
            xport_gte_write_control(index, saved[index]);
        source += 32u;
    }
    w_u32(next_source, source);
    return cursor;
}
