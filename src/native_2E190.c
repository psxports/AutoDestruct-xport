#include "native_call_dispatch.h"

static uint32 native_2E190_near(uint32 first, uint32 second, sint32 limit)
{
    uint32 difference = first - second;
    if ((sint32)difference < 0)
        difference = second - first;
    return (sint32)difference < limit;
}

uint32 sub_8002E190(uint32 object, uint32 ignored, uint32 other, uint32 index)
{
    uint32 target, parameter;
    FUNCTION_MARKER(0x8002E190u, "1.EXE");
    if (!native_2E190_near(r_u32(other + 20u), r_u32(object + 20u), 301))
        return 0u;
    if (!native_2E190_near(r_u32(other + 28u), r_u32(object + 28u), 301))
        return 0u;
    if (!native_2E190_near(r_u32(other + 24u), r_u32(object + 24u), 257))
        return index << 16;
    parameter = (uint32)(sint32)(sint16)r_u16(0x800B3492u + 20u * (uint32)(sint32)(sint16)index);
    target = r_u32(r_u32(object + 16u) + 28u);
    return (uint32)draft_call_adapter(target, object, parameter, other + 20u);
}
