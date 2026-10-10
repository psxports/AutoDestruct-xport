#include "native_call_dispatch.h"

uint32 sub_80062B08(uint32 object)
{
    uint32 material;
    FUNCTION_MARKER(0x80062B08u, "1.EXE");
    material = (uint32)(sint32)(sint16)r_u16(r_u32(0x800A62ECu) + 350u);
    return (uint32)draft_call_adapter(0x80062B3Cu, object + 20u, material, 5242u, 24u);
}

uint32 sub_800548B0(uint32 object)
{
    uint32 result;
    FUNCTION_MARKER(0x800548B0u, "1.EXE");
    result = (uint32)draft_call_adapter(0x80054594u, object);
    if (result != 0u)
    {
        result = (uint32)(sint32)(sint16)r_u16(object + 82u);
        if (result == 0u)
            return sub_8002289C(object);
        return result;
    }
    if ((sint32)r_u32(object + 60u) < (sint32)r_u32(object + 24u))
        draft_call_adapter(0x800542C0u, object, 0u, 1u);
    return (uint32)draft_call_adapter(0x80055D54u, object, object + 84u, 0u);
}

uint32 sub_800547EC(uint32 object)
{
    uint32 result;
    FUNCTION_MARKER(0x800547ECu, "1.EXE");
    result = (uint32)draft_call_adapter(0x80054594u, object);
    if (result != 0u)
        return result;
    if ((sint32)r_u32(object + 60u) < (sint32)r_u32(object + 24u))
    {
        draft_call_adapter(0x800542C0u, object, 0u, 4u);
        result = sub_80069A50();
        if (result % 7u == 0u)
            draft_call_adapter(0x80035A08u, 3u, 2048u, 128u, 0u, 0u);
    }
    result = (uint32)(sint32)(sint16)r_u16(r_u32(0x800A62ECu) + 26u);
    if ((uint32)r_u16(object + 32u) == result)
        return (uint32)draft_call_adapter(0x800546D4u, object);
    return result;
}

uint32 sub_80054660(uint32 object)
{
    uint32 result;
    FUNCTION_MARKER(0x80054660u, "1.EXE");
    result = (uint32)draft_call_adapter(0x80054594u, object);
    if (result != 0u)
    {
        result = (uint32)(sint32)(sint16)r_u16(object + 82u);
        if (result == 0u)
            return sub_8002289C(object);
        return result;
    }
    result = (sint32)r_u32(object + 60u) < (sint32)r_u32(object + 24u);
    if (result != 0u)
        return (uint32)draft_call_adapter(0x800542C0u, object, 0u, 1u);
    return result;
}
