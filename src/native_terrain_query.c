#include "native_call_dispatch.h"

static uint32 terrain_edge_contains(uint32 x, uint32 z, uint32 ax, uint32 az, uint32 bx, uint32 bz)
{
    uint32 cross = (az - bz) * (x - bx) + (bx - ax) * (z - bz);
    return (sint32)cross >= 0;
}

uint32 sub_8002E640(uint32 position, uint32 normal, uint32 mode, uint32 tag)
{
    uint32 bands = r_u32(0x800A869C);
    uint32 x = r_u32(position);
    uint32 z = r_u32(position + 8);
    uint32 cell = 80 * (uint32)((sint32)z >> 12) + (uint32)((sint32)x >> 12);
    uint32 cells = r_u32(0x800A84F8);
    uint32 height = 0u - r_u32(position + 4);
    uint32 first = r_u16(cells + 8 * cell + 4);
    uint32 band = 0;
    uint32 index, base_x, base_z, list, polygons;
    FUNCTION_MARKER(0x8002E640, "1.EXE");
    for (;;)
    {
        uint32 bound = r_u16(bands + 2 * (first + 3 * band));
        if ((sint32)height >= (sint32)(2 * (bound & 0x7FFF)) || (bound & 0x8000))
            break;
        ++band;
    }
    bands = r_u32(0x800A869C);
    index = r_u16(bands + 2 * (first + 3 * band) + ((uint16)mode ? 2 : 4));
    if (index == 0xFFFF)
        return 0;
    x = r_u32(position);
    z = r_u32(position + 8);
    base_x = x & 0xFFFFF000;
    base_z = z & 0xFFFFF000;
    if ((uint16)mode)
    {
        height = 0u - r_u32(position + 4);
        polygons = r_u32(0x800A9024);
        list = r_u32(0x800A9CDC) + 2 * index;
        for (;;)
        {
            uint32 identifier = r_u16(list);
            uint32 polygon = polygons + 20 * (identifier & 0x7FFF);
            list += 2;
            if ((sint32)height < r_u16(polygon + 2) && r_u16(polygon) < (sint32)height)
            {
                uint32 z0 = base_z + (uint32)r_s16(polygon + 6);
                uint32 z1 = base_z + (uint32)r_s16(polygon + 10);
                uint32 x1, x0, z2, x2, z3, x3;
                x = r_u32(position);
                x1 = base_x + (uint32)r_s16(polygon + 8);
                x0 = base_x + (uint32)r_s16(polygon + 4);
                z = r_u32(position + 8);
                if (terrain_edge_contains(x, z, x0, z0, x1, z1))
                {
                    z2 = base_z + (uint32)r_s16(polygon + 14);
                    x2 = base_x + (uint32)r_s16(polygon + 12);
                    if (terrain_edge_contains(x, z, x1, z1, x2, z2))
                    {
                        z3 = base_z + (uint32)r_s16(polygon + 18);
                        x3 = base_x + (uint32)r_s16(polygon + 16);
                        if (terrain_edge_contains(x, z, x2, z2, x3, z3) && terrain_edge_contains(x, z, x3, z3, x0, z0))
                            return 1;
                    }
                }
            }
            if (identifier & 0x8000)
                return 0;
        }
    }
    list = r_u32(0x800A9CE4) + 2 * index;
    polygons = r_u32(0x800A9CE8);
    for (;;)
    {
        uint32 identifier = r_u16(list);
        uint32 offset = 28 * (identifier & 0x7FFF);
        uint32 polygon = polygons + offset;
        uint32 z0 = base_z + (uint32)r_s16(polygon + 4);
        uint32 z1 = base_z + (uint32)r_s16(polygon + 8);
        uint32 x1 = base_x + (uint32)r_s16(polygon + 6);
        uint32 x0 = base_x + (uint32)r_s16(polygon);
        uint32 z2, x2, z3, x3;
        list += 2;
        if (terrain_edge_contains(x, z, x0, z0, x1, z1))
        {
            z2 = base_z + (uint32)r_s16(polygon + 12);
            x2 = base_x + (uint32)r_s16(polygon + 10);
            if (terrain_edge_contains(x, z, x1, z1, x2, z2))
            {
                z3 = base_z + (uint32)r_s16(polygon + 16);
                x3 = base_x + (uint32)r_s16(polygon + 14);
                if (terrain_edge_contains(x, z, x2, z2, x3, z3) && terrain_edge_contains(x, z, x3, z3, x0, z0))
                {
                    uint32 value, local_x, local_z, nx, nz, numerator;
                    sint32 ny;
                    w_u16(normal, r_u16(polygon + 18));
                    value = r_u16(polygon + 20);
                    w_u16(normal + 2, value);
                    w_u16(tag, value);
                    // Outputs can alias the terrain table or input position
                    polygon = r_u32(0x800A9CE8) + offset;
                    w_u16(normal + 4, r_u16(polygon + 22));
                    local_x = r_u32(position) - base_x - (uint32)r_s16(polygon);
                    nx = (uint32)r_s16(polygon + 18);
                    value = (uint32)r_s16(polygon + 4);
                    local_z = r_u32(position + 8) - base_z - value;
                    nz = (uint32)r_s16(polygon + 22);
                    ny = r_s16(polygon + 20);
                    numerator = 0u - (nx * local_x + nz * local_z);
                    if (!ny)
                        xport_mips_break(7);
                    if (ny == -1 && numerator == 0x80000000)
                        xport_mips_break(6);
                    return (uint32)((sint32)numerator / ny) + (uint32)r_s16(polygon + 2);
                }
            }
        }
        if (identifier & 0x8000)
            return 0;
    }
}
