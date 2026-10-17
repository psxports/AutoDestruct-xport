#include "draft_signatures.h"

uint32 sub_80026F98(uint32 object)
{
    uint32 result;
    FUNCTION_MARKER(0x80026F98u, "1.EXE");
    w_u32(object, 0x80029968u);
    w_u16(0x800A9030u, r_u8(0x800A7E83u));
    sub_8005E2BC(2u);
    w_u16(0x800A56A4u, 0u);
    w_u32(object + 552u, 0u);
    sub_80035988((uint32)(sint32)(sint16)r_u16(0x800A56AEu));
    sub_80035988((uint32)(sint32)(sint16)r_u16(0x800A56B4u));
    w_u16(0x800A9734u, 3u);
    w_u32(object + 476u, 0u);
    w_u32(object + 480u, 0u);
    result = sub_80030F08((uint32)(sint32)(sint16)r_u16(object + 74u), (uint32)(sint32)(sint16)r_u16(object + 68u), 1u);
    w_u32(0x800A56C8u, 0u);
    return result;
}

uint32 sub_80028E98(uint32 object)
{
    sint32 timer;
    uint32 reason, model;
    FUNCTION_MARKER(0x80028E98u, "1.EXE");

    timer = (sint16)r_u16(object + 574u);
    if (timer > 0)
    {
        reason = r_u32(0x800A56CCu);
        w_u16(0x800A9734u, reason == 2u ? 2u : 3u);
        sub_80030F08((uint32)(sint32)(sint16)r_u16(object + 72u + 2u * reason), (uint32)(sint32)(sint16)r_u16(object + 68u), (uint32)(sint32)(sint16)r_u16(0x800A56CCu));
    }
    else
    {
        w_u16(object + 574u, (uint32)timer - (uint32)(sint32)(sint16)r_u16(0x800A63DAu));
    }
    model = r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
    sub_80029970(object, (uint32)(sint32)(sint16)r_u16(r_u32(0x800A90ACu) + 40u * model + 32u), 0u, 1u, object + 244u);
    return sub_80026BC4(r_u32(0x800A7BACu));
}

uint32 sub_80028F78(uint32 object, uint32 reason)
{
    uint32 result;
    FUNCTION_MARKER(0x80028F78u, "1.EXE");

    w_u32(object, 0x80028E98u);
    w_u32(0x800A56CCu, reason);
    w_u32(object + 16u, 0x8008B858u);
    w_u16(object + 56u, 0u);
    w_u16(object + 574u, 5u * r_u32(0x800A56C0u));
    sub_80035988((uint32)(sint32)(sint16)r_u16(0x800A56AEu));
    sub_80035988((uint32)(sint32)(sint16)r_u16(0x800A56B4u));
    w_u32(object + 472u, 0u);
    w_u32(object + 476u, 0u);
    w_u32(object + 480u, 0u);

    result = 0u;
    if (r_u8(0x800A6BA0u) == 6u && r_u8(0x800A6BA1u) == 6u && r_u8(0x800A6BA2u) == 6u && r_u8(0x800A6BA3u) == 6u)
    {
        result = r_u8(object + 67u);
        if (result == 0u)
        {
            w_u32(object, 0x80029968u);
            w_u16(0x800A9030u, r_u8(0x800A7E83u));
            sub_8005E2BC(2u);
            w_u16(0x800A56A4u, 0u);
            w_u32(object + 552u, 0u);
            sub_80035988((uint32)(sint32)(sint16)r_u16(0x800A56AEu));
            sub_80035988((uint32)(sint32)(sint16)r_u16(0x800A56B4u));
            w_u16(0x800A9734u, 3u);
            w_u32(object + 476u, 0u);
            w_u32(object + 480u, 0u);
            result = sub_80030F08((uint32)(sint32)(sint16)r_u16(object + 74u), (uint32)(sint32)(sint16)r_u16(object + 68u), 1u);
            w_u32(0x800A56C8u, 0u);
        }
    }
    return result;
}
