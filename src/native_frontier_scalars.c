#include "draft_signatures.h"

uint32 sub_80065588(uint32 vector, uint32 magnitude)
{
    FUNCTION_MARKER(0x80065588u, "1.EXE");
    uint32 angle = sub_80055A9C((uint32)r_s16(vector), (uint32)r_s16(vector + 4u)) & 4095u;
    uint32 product = magnitude * (uint32)r_s16(0x800102E0u + 2u * angle);
    w_u16(vector, (uint32)((sint32)product >> 12));
    product = magnitude * (uint32)r_s16(0x80010AE0u + 2u * angle);
    uint32 result = (uint32)((sint32)product >> 12);
    w_u16(vector + 4u, result);
    return result;
}

uint32 sub_8003D5DC(uint32 weapon)
{
    FUNCTION_MARKER(0x8003D5DCu, "1.EXE");
    uint32 index = (uint32)(sint32)(sint16)weapon;
    uint32 descriptor = r_u32(0x800901DCu + 12u * index);
    uint32 result = r_u32(0x800A5EA8u) | r_u32(descriptor + 16u);
    w_u32(0x800A5EA8u, result);
    return result;
}

uint32 sub_8003D6C4(void)
{
    FUNCTION_MARKER(0x8003D6C4u, "1.EXE");
    sint32 count = r_s16(0x800A5EF8u);
    if (count >= 5)
        return 0u;
    uint32 result = (uint32)count + 1u;
    w_u16(0x800A5EF8u, result);
    return result;
}

uint32 sub_80043BA0(void)
{
    FUNCTION_MARKER(0x80043BA0u, "1.EXE");
    w_u32(0x800A5F78u, 4u);
    w_u32(0x800A5F70u, 28672u);
    w_u32(0x800A5F74u, 28672u);
    return 28672u;
}
