#include "native_call_dispatch.h"

uint32 sub_80033418(uint32 selection)
{
    FUNCTION_MARKER(0x80033418u, "1.EXE");
    if (r_u32(0x800A902Cu) != 1u)
        return 1u;
    w_u32(0x800A902Cu, 1u);
    w_u32(0x800A7FB8u, 1u);
    uint32 entry = r_u32(r_u32(0x800A851Cu) + 4u * (uint32)r_s16(selection));
    w_u16(0x800A9744u, 0u);
    uint32 result = sub_80077AC0(entry + 19u, 1u, 1u, 287u);
    w_u32(0x800A6C90u, result);
    return result;
}

uint32 sub_8003D13C(void)
{
    FUNCTION_MARKER(0x8003D13Cu, "1.EXE");
    for (uint32 index = 0u; index < 27u; ++index)
        w_u16(0x800A5EACu + 2u * index, sub_8003CE7C(index));
    w_u16(0x800A5EC4u, 0u);
    w_u16(0x800A5EC6u, 0u);
    w_u32(0x800A5EA8u, 0xFFFFFFu);
    return 0xFFFFFFu;
}

uint32 sub_80053890(uint32 object, uint32 allocation)
{
    FUNCTION_MARKER(0x80053890u, "1.EXE");
    sub_80064D60(allocation);
    w_u32(object + 60u, 0u);
    sub_80054934(object, 2u);
    return sub_80056364(object);
}

uint32 sub_8003AC24(void)
{
    FUNCTION_MARKER(0x8003AC24u, "1.EXE");
    if (!r_u32(0x800A6DE8u))
    {
        sub_80035758();
        w_u32(0x800A6DE8u, 1u);
        w_u32(0x800A6E08u, 1u);
        return 0u;
    }
    if (r_u32(0x800A6E08u) == 1u)
        return 0u - (r_u8(0x800A7BDFu) != 0u);
    return 0u;
}

uint32 sub_8003AC84(void)
{
    FUNCTION_MARKER(0x8003AC84u, "1.EXE");
    if (!r_u32(0x800A6DE8u))
    {
        sub_80035758();
        w_u32(0x800A6DE8u, 1u);
        w_u32(0x800A6E08u, 1u);
        return 0u;
    }
    if (r_u32(0x800A6E08u) == 1u)
        return 0u - (r_u8(0x800A7BDFu) != 0u);
    return 0u;
}

uint32 sub_8006EC70(uint32 object, uint32 position, uint32 nearby)
{
    FUNCTION_MARKER(0x8006EC70u, "1.EXE");
    uint32 owner = r_u32(object + 16u);
    if (!nearby || (sint32)sub_8006E748(position, owner + 20u) >= 12001)
        return sub_8006E790(object);
    uint32 kind = (uint32)r_s8(object + 13u);
    w_u8(object + 34u, 1u);
    w_u16(object + 32u, sub_8006EA04(kind, 0u));
    return (uint32)draft_call_adapter(0x80035A08u, 0u, 2048u, 255u, 0u, 0u);
}

uint32 sub_80070484(void)
{
    FUNCTION_MARKER(0x80070484u, "1.EXE");
    w_u32(0x800A6464u, 5u);
    sub_80070428();
    return sub_8006F7A8();
}

uint32 sub_8006E604(uint32 owner)
{
    FUNCTION_MARKER(0x8006E604u, "1.EXE");
    uint32 object = sub_8006E62C(owner);
    w_u8(object + 35u, 1u);
    return object;
}
