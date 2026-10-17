#include "native_call_dispatch.h"

uint32 sub_80032620(void)
{
    FUNCTION_MARKER(0x80032620u, "1.EXE");
    if (!r_u32(0x800A6C4Cu))
    {
        uint32 value = r_u32(0x800A6C48u) + 10u * r_u32(0x800A9010u);
        w_u32(0x800A6C48u, value);
        if ((sint32)value >= 128)
        {
            w_u32(0x800A6C4Cu, 1u);
            w_u32(0x800A6C48u, 128u);
        }
    }
    uint32 direction = r_u32(0x800A6C4Cu);
    if (direction != 1u)
        return 1u;
    uint32 value = r_u32(0x800A6C48u) - 10u * r_u32(0x800A9010u);
    w_u32(0x800A6C48u, value);
    uint32 result = (sint32)value < 2;
    if (result)
    {
        w_u32(0x800A6C4Cu, 0u);
        w_u32(0x800A6C48u, direction);
    }
    return result;
}

uint32 sub_800326BC(void)
{
    FUNCTION_MARKER(0x800326BCu, "1.EXE");
    if (r_u32(0x800A985Cu) == 1u)
        sub_80032620();
    else
        w_u32(0x800A6C48u, 0x808080u);
    if (r_u32(0x800A9760u) != 1u)
        return 1u;
    uint32 index = 6u * r_u32(0x800A9764u) + r_u32(0x800A9768u);
    sub_80032E6C(0x800A5BE8u, r_u32(0x800A6C48u), r_u8(0x800A978Au + index), r_u8(0x800A97A8u + index), r_u8(0x800A97C6u + index), 0u, (uint32)-100);
    return sub_80032E6C(0x800A5BE8u, 0x808000u, r_u32(0x800A6C54u), r_u32(0x800A6C58u), r_u32(0x800A6C5Cu), 230u, (uint32)-100);
}

uint32 sub_8004BC18(uint32 object)
{
    FUNCTION_MARKER(0x8004BC18u, "1.EXE");
    sub_8004D8B4(object);
    sub_80030F08((uint32)r_s16(object + 74u), (uint32)r_s16(object + 68u), 1u);
    if (r_u8(object + 12u) >= 4u)
    {
        sub_8005F920(object);
        draft_call_adapter(0x80035A08u, 63u, 1024u, 255u, object + 20u, 1u);
    }
    w_u32(object, 0x80045510u);
    return 0x80045510u;
}

uint32 sub_8006DFF8(uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x8006DFF8u, "1.EXE");
    uint32 dx = r_u32(second) - r_u32(first);
    if ((sint32)dx < 0)
        dx = 0u - dx;
    uint32 dy = r_u32(second + 4u) - r_u32(first + 4u);
    if ((sint32)dy < 0)
        dy = 0u - dy;
    uint32 dz = r_u32(second + 8u) - r_u32(first + 8u);
    if ((sint32)dz < 0)
        dz = 0u - dz;
    return (sint32)dx < 512 && (sint32)dz < 512 && (sint32)dy < 1024;
}

uint32 sub_8006E2B8(uint32 owner)
{
    FUNCTION_MARKER(0x8006E2B8u, "1.EXE");
    uint32 object = (uint32)draft_call_adapter(0x80022744u, 56u, owner);
    w_u8(object + 34u, 0u);
    w_u32(object + 20u, r_u32(owner + 20u));
    w_u32(object + 24u, r_u32(owner + 24u));
    w_u32(object + 28u, r_u32(owner + 28u));
    uint32 kind = r_u8(owner + 13u) & 127u;
    uint32 index = kind == 11u || kind == 12u || kind == 14u ? 213u : 176u;
    w_u16(object + 32u, r_u16(r_u32(0x800A62ECu) + 2u * index));
    w_u8(owner + 13u, r_u8(owner + 13u) | 128u);
    sub_80055A70(object + 36u);
    w_u8(object + 35u, 1u);
    uint32 result = r_u8(object + 14u) | 0x42u;
    w_u32(object, 0x8006E3A4u);
    w_u8(object + 14u, result);
    return result;
}

uint32 sub_8006E3A4(uint32 object)
{
    FUNCTION_MARKER(0x8006E3A4u, "1.EXE");
    uint32 owner = r_u32(object + 8u);
    w_u32(object + 20u, r_u32(owner + 20u));
    w_u32(object + 24u, r_u32(owner + 24u));
    w_u32(object + 28u, r_u32(owner + 28u));
    uint32 kind = r_u8(owner + 13u) & 127u;
    uint32 active = kind == 11u || kind == 12u || kind == 14u;
    if (kind == 0u || kind == 8u)
        active = r_u16(owner + 58u) != 0u;
    if (!active || (r_u32(owner + 12u) & 0xA0000u) != 0xA0000u)
        sub_8002289C(object);
    if ((r_u8(owner + 14u) & 1u) && (r_u8(object + 14u) & 1u))
        return 1u;
    uint32 result = r_u8(owner + 13u) & 127u;
    w_u8(owner + 13u, result);
    return result;
}
