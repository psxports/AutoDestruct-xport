#include "native_call_dispatch.h"

static uint32 proximity_within(uint32 first, uint32 second)
{
    uint32 difference = first - second;
    if ((sint32)difference < 0)
        difference = second - first;
    return (sint32)difference < 257;
}

uint32 sub_8002E250(uint32 object, uint32 ignored, uint32 other, uint32 kind)
{
    FUNCTION_MARKER(0x8002E250, "1.EXE");
    if (!proximity_within(r_u32(object + 20), r_u32(other + 20)))
        return 0;
    if (!proximity_within(r_u32(object + 28), r_u32(other + 28)))
        return 0;
    if (!proximity_within(r_u32(object + 24), r_u32(other + 24)))
        return kind << 16;
    return sub_8002AA2C(object, other, r_u8(0x800B3490 + 20 * (uint32)(sint32)(sint16)kind));
}
