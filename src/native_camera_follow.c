#include "draft_signatures.h"

uint32 sub_8005B32C(uint32 current, uint32 target, uint32 step)
{
    sint32 difference = (sint32)(target - current);
    FUNCTION_MARKER(0x8005B32Cu, "1.EXE");
    if (difference > 0)
        return difference < (sint32)step ? target : current + step;
    return (sint32)(0u - step) < difference ? target : current - step;
}

uint32 sub_8005DBA4(uint32 camera, uint32 angle)
{
    uint32 result;
    FUNCTION_MARKER(0x8005DBA4u, "1.EXE");
    w_u16(0x800A8534u, (sub_80069A50() & 63u) + 127u);
    sub_8005E258(1u);
    w_u16(camera + 38u, 10000u);
    result = sub_8005C560(camera);
    w_u16(0x800A8536u, 0u);
    w_u16(camera + 40u, angle);
    return result;
}

uint32 sub_8005B76C(uint32 camera)
{
    uint32 owner, matrix[8], offset[2], displacement[2];
    uint32 projected[3], relative[3], index, result;
    FUNCTION_MARKER(0x8005B76Cu, "1.EXE");

    offset[0] = r_u32(0x800A6334u);
    offset[1] = r_u32(0x800A6338u);
    owner = r_u32(0x800A9A58u);
    for (index = 0u; index < 5u; ++index)
        matrix[index] = r_u32(owner + 36u + 4u * index);
    for (index = 0u; index < 3u; ++index)
        matrix[5u + index] = r_u32(owner + 20u + 4u * index);
    displacement[0] = r_u32(camera + 12u);
    displacement[1] = r_u32(camera + 16u);
    if (r_u16(0x800A974Cu) != 0u)
    {
        offset[1] = (offset[1] & 0xFFFF0000u) | 550u;
        displacement[1] = (displacement[1] & 0xFFFF0000u) | ((0u - displacement[1]) & 0xFFFFu);
    }

    for (index = 0u; index < 8u; ++index)
        xport_gte_write_control(index, matrix[index]);
    xport_gte_write_data(0u, displacement[0]);
    xport_gte_write_data(1u, displacement[1]);
    draft_gte_command_adapter(0x480012u);
    xport_gte_write_data(2u, offset[0]);
    xport_gte_write_data(3u, offset[1]);
    for (index = 0u; index < 3u; ++index)
        projected[index] = xport_gte_read_data(25u + index);
    for (index = 0u; index < 3u; ++index)
        w_u32(0x800A7EE4u + 4u * index, projected[index]);
    for (index = 0u; index < 3u; ++index)
        w_u32(camera + 4u * index, projected[index]);

    draft_gte_command_adapter(0x488012u);
    w_u32(0x800A84E8u, r_u32(0x800A7EE8u));
    xport_gte_write_data(4u, 200u << 16u);
    xport_gte_write_data(5u, 300u);
    for (index = 0u; index < 3u; ++index)
        relative[index] = xport_gte_read_data(25u + index);
    draft_gte_command_adapter(0x496012u);
    for (index = 0u; index < 3u; ++index)
        relative[index] -= r_u32(0x800A7EE4u + 4u * index);
    for (index = 0u; index < 3u; ++index)
        projected[index] = xport_gte_read_data(25u + index);
    w_u32(0x800A8554u, relative[0] - projected[0]);
    w_u32(0x800A8558u, relative[1] - projected[1]);
    result = relative[2] - projected[2];
    w_u32(0x800A855Cu, result);
    return result;
}
