#include "native_call_dispatch.h"

uint32 sub_80040478(uint32 object, uint32 ignored)
{
    uint32 effect;
    FUNCTION_MARKER(0x80040478u, "1.EXE");
    (void)ignored;
    effect = sub_80022820(40u, object);
    w_u8(effect + 34u, 11u);
    w_u16(effect + 36u, 50u);
    w_u16(effect + 38u, 0u);
    w_u8(effect + 14u, r_u8(effect + 14u) | 2u);
    w_u32(effect, 0x80040500u);
    w_u16(effect + 16u, 64u);
    w_u16(effect + 18u, 1u);
    w_u16(effect + 32u, r_u16(r_u32(0x800A62ECu) + 106u));
    return (uint32)draft_call_adapter(0x80035A08u, 57u, 1024u, 128u, 0u, 0u);
}

uint32 sub_80040500(uint32 object)
{
    uint32 tick = r_u32(0x800A9010u), result, mark, scratch, owner;
    FUNCTION_MARKER(0x80040500u, "1.EXE");
    if ((sint16)r_u16(object + 16u) <= 0) return sub_8002289C(object);
    mark = draft_scratch_mark();
    scratch = draft_scratch_adapter(12u);
    owner = r_u32(object + 8u);
    w_u32(scratch, 0u); w_u32(scratch + 4u, 0u); w_u32(scratch + 8u, 300u);
    sub_80031D50(owner + 36u, owner + 20u, scratch, object + 20u);
    result = r_u16(object + 16u) - tick;
    w_u16(object + 16u, result);
    while ((sint32)tick > 0) {
        --tick;
        if ((sint16)r_u16(object + 18u) < 0) {
            uint32 effect = sub_800227C4(40u);
            w_u8(effect + 34u, 11u); w_u16(effect + 36u, 50u); w_u16(effect + 38u, 0u);
            w_u32(effect + 20u, r_u32(object + 20u));
            w_u32(effect + 24u, r_u32(object + 24u));
            w_u32(effect + 28u, r_u32(object + 28u));
            w_u8(effect + 14u, r_u8(effect + 14u) | 2u);
            w_u32(effect, 0x80040674u);
            w_u16(effect + 8u, 1024u);
            w_u16(effect + 32u, r_u16(r_u32(0x800A62ECu) + 106u));
            w_u16(effect + 10u, (sub_80069A50() & 31u) + 0xFFF1u);
            w_u16(effect + 16u, 0xFFF7u);
            w_u16(effect + 18u, (sub_80069A50() & 31u) + 0xFFF1u);
            w_u8(effect + 13u, (sub_80069A50() & 31u) + 241u);
            w_u16(object + 18u, 1u);
        }
        result = r_u16(object + 18u) - 1u;
        w_u16(object + 18u, result);
    }
    return (uint32)draft_scratch_result(mark, result);
}

uint32 sub_80040674(uint32 object)
{
    uint32 tick = r_u32(0x800A9010u), size, result;
    FUNCTION_MARKER(0x80040674u, "1.EXE");
    w_u16(object + 38u, r_u16(object + 38u) + tick * (uint32)(sint32)(sint8)r_u8(object + 13u));
    size = (uint32)(sint32)(sint16)r_u16(object + 36u);
    if ((sint32)size < 500) {
        uint32 x = tick * (uint32)(sint32)(sint16)r_u16(object + 10u);
        uint32 y = tick * (uint32)(sint32)(sint16)r_u16(object + 16u);
        uint32 z = tick * (uint32)(sint32)(sint16)r_u16(object + 18u);
        w_u16(object + 36u, size + 10u * tick);
        w_u32(object + 20u, r_u32(object + 20u) + x);
        w_u32(object + 24u, r_u32(object + 24u) + y);
        w_u32(object + 28u, r_u32(object + 28u) + z);
    }
    result = r_u16(object + 8u) - tick;
    w_u16(object + 8u, result);
    result <<= 16;
    if ((sint32)result < 0) {
        result = 0x80040754u;
        w_u32(object, result);
    }
    return result;
}

uint32 sub_80040754(uint32 object)
{
    uint32 tick = r_u32(0x800A9010u);
    uint32 rotation = tick * (uint32)(sint32)(sint8)r_u8(object + 13u);
    uint32 size = r_u16(object + 36u) - 10u * tick, result;
    FUNCTION_MARKER(0x80040754u, "1.EXE");
    w_u16(object + 36u, size);
    result = r_u16(object + 38u) + rotation;
    w_u16(object + 38u, result);
    if ((sint16)size < 0) {
        w_u16(object + 36u, 0u);
        return sub_8002289C(object);
    }
    return result;
}
