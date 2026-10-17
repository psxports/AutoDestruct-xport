#include "psx.h"
#include "xport.h"
#include "draft_adapters.h"
#include "native_call_dispatch.h"

extern void sub_80031F3C(uint32 bytes, uint32 cursor, uint32 value, uint32 count);
extern uint32 sub_80031FBC(uint32 bytes, uint32 cursor, uint32 count);
extern uint32 sub_80032024(uint32 bytes, uint32 index);
extern uint32 sub_80032050(uint32 bytes, uint32 value, uint32 index);
extern uint32 sub_80032094(uint32 bytes, uint32 cursor);
extern uint32 sub_80032138(uint32 bytes);

uint32 sub_80068CC8(uint32 object, uint32 model, uint32 lifetime)
{
    uint32 particle = (uint32)draft_call_adapter(0x800226E4u, 84u);
    uint32 z, flags, a, b, result;
    FUNCTION_MARKER(0x80068CC8u, "1.EXE");
    w_u8(particle + 34u, 11u);
    w_u32(particle + 20u, r_u32(object + 20u));
    w_u32(particle + 24u, r_u32(object + 24u));
    z = r_u32(object + 28u);
    flags = r_u8(particle + 14u);
    w_u16(particle + 32u, model);
    w_u8(particle + 14u, flags | 2u);
    w_u32(particle + 28u, z);
    sub_800551CC(r_u32(object + 24u), particle + 36u);
    flags = r_u8(particle + 14u);
    w_u32(particle, 0x80068DD8u);
    w_u8(particle + 14u, flags | 32u);
    a = r_u32(object + 60u);
    b = r_u32(object + 64u);
    w_u32(particle + 60u, a);
    w_u32(particle + 64u, b);
    a = r_u32(object + 68u);
    b = r_u32(object + 72u);
    w_u32(particle + 68u, a);
    w_u32(particle + 72u, b);
    w_u16(particle + 76u, (sub_80069A50() & 127u) - 63u);
    w_u16(particle + 78u, (sub_80069A50() & 15u) - 7u);
    w_u16(particle + 80u, lifetime);
    w_u16(particle + 66u, 0u - ((sub_80069A50() & 31u) + 20u));
    result = sub_80069A50();
    w_u16(particle + 74u, result);
    return result;
}

uint32 sub_80068C74(uint32 object)
{
    uint32 result = 0u;
    FUNCTION_MARKER(0x80068C74u, "1.EXE");
    for (uint32 index = 0u; index < 10u; ++index)
        result = sub_80068CC8(object, (uint32)(sint32)(sint16)r_u16(r_u32(0x800A62ECu) + 348u), 10u);
    return result;
}

uint32 sub_80068BF0(uint32 object)
{
    uint32 result = 0u;
    FUNCTION_MARKER(0x80068BF0u, "1.EXE");
    for (uint32 index = 0u; index < 10u; ++index)
        result = sub_80068CC8(object, (uint32)(sint32)(sint16)r_u16(r_u32(0x800A62ECu) + 360u), 5u);
    return result;
}

uint32 sub_80062DD0(uint32 owner, uint32 slot, uint32 kind, uint32 flag)
{
    uint32 particle = sub_80022820(40u, owner);
    uint32 x = r_u32(owner + 20u), y = r_u32(owner + 24u), z = r_u32(owner + 28u);
    FUNCTION_MARKER(0x80062DD0u, "1.EXE");
    w_u32(particle + 20u, x);
    w_u32(particle + 24u, y);
    w_u32(particle + 28u, z);
    w_u32(particle, 0x80062E70u);
    w_u32(particle + 16u, slot);
    w_u8(particle + 13u, kind);
    w_u8(particle + 35u, (flag << 16) != 0u ? 4u : 0u);
    return particle;
}

uint32 sub_80062D90(uint32 slot, uint32 owner, uint32 flag)
{
    uint32 result;
    FUNCTION_MARKER(0x80062D90u, "1.EXE");
    result = sub_80062DD0(owner, slot, 8u, (uint32)(sint32)(sint16)flag);
    w_u32(slot, result);
    return result;
}

void sub_80067494(uint32 object)
{
}

uint32 sub_8006749C(uint32 object, uint32 model)
{
    uint32 mark = draft_scratch_mark();
    uint32 particle = (uint32)draft_call_adapter(0x800226E4u, 56u);
    uint32 temporary = draft_scratch_adapter(16u);
    uint32 flags, result;
    FUNCTION_MARKER(0x8006749Cu, "1.EXE");
    w_u8(particle + 34u, 8u);
    w_u32(particle + 20u, r_u32(object + 20u));
    w_u32(particle + 24u, r_u32(object + 24u));
    w_u32(particle + 28u, r_u32(object + 28u));
    result = (uint32)draft_call_adapter(0x8002E640u, object + 20u, temporary + 8u, 0u, temporary);
    w_u32(object + 24u, 0u - result);
    flags = r_u8(particle + 14u);
    w_u16(particle + 32u, model);
    w_u8(particle + 14u, flags | 2u);
    sub_80055A70(particle + 36u);
    flags = r_u8(particle + 14u);
    w_u32(particle, 0x80067494u);
    result = flags | 64u;
    w_u8(particle + 14u, result);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_80067604(uint32 object)
{
    uint32 particle = sub_800227C4(40u);
    uint32 flags, z, models;
    FUNCTION_MARKER(0x80067604u, "1.EXE");
    w_u32(particle + 20u, r_u32(object + 20u));
    w_u32(particle + 24u, r_u32(object + 24u) + 100u);
    flags = r_u8(particle + 14u);
    z = r_u32(object + 28u);
    w_u8(particle + 14u, flags | 64u);
    models = r_u32(0x800A62ECu);
    w_u32(particle, 0x80067690u);
    w_u32(particle + 28u, z);
    sub_8006749C(object, (uint32)(sint32)(sint16)r_u16(models + 76u));
    w_u8(particle + 13u, 255u);
    return 255u;
}

void sub_8003E338(uint32 object, uint32 mode)
{
    uint32 mark = draft_scratch_mark();
    uint32 temporary = draft_scratch_adapter(24u);
    uint32 callback = r_u32(r_u32(object + 16u) + 20u);
    sint32 toggle = (sint16)r_u16(object + 54u);
    uint32 particle, models, flags, model, x;
    FUNCTION_MARKER(0x8003E338u, "1.EXE");
    draft_call_adapter(callback, object, temporary);
    particle = (uint32)draft_call_adapter(0x800226E4u, 60u);
    draft_call_adapter(0x80054D38u, (uint32)(sint32)(sint16)r_u16(temporary), (uint32)(sint32)(sint16)r_u16(temporary + 2u), (uint32)(sint32)(sint16)r_u16(temporary + 4u), particle + 36u);
    w_u8(particle + 34u, 8u);
    x = r_u32(object + 20u);
    models = r_u32(0x800A62ECu);
    w_u32(particle + 20u, x);
    w_u32(particle + 24u, r_u32(object + 24u));
    w_u32(particle + 28u, r_u32(object + 28u));
    flags = r_u8(particle + 14u);
    model = r_u16(models + 98u);
    w_u16(particle + 58u, mode);
    w_u32(particle + 16u, object);
    w_u16(particle + 10u, 0u);
    w_u16(particle + 56u, 0u);
    w_u8(particle + 14u, flags | 2u);
    w_u32(particle, 0x8003E454u);
    w_u16(particle + 8u, 200u);
    w_u16(particle + 32u, model);
    w_u32(temporary + 8u, toggle ? 125u : 0u - 125u);
    w_u32(temporary + 12u, 0u - 50u);
    w_u32(temporary + 16u, 0u);
    sub_80031E30(particle + 36u, particle + 20u, temporary + 8u);
    w_u16(object + 54u, ((uint32)toggle + 1u) & 1u);
    draft_scratch_release(mark);
}

uint32 sub_8003E2F0(uint32 object, uint32 mode)
{
    FUNCTION_MARKER(0x8003E2F0u, "1.EXE");
    sub_8003E338(object, (uint32)(sint32)(sint16)mode);
    return (uint32)draft_call_adapter(0x80035A08u, 22u, 1024u, 192u, object + 20u, 0u);
}

uint32 sub_80032388(uint32 password)
{
    uint32 mark = draft_scratch_mark();
    uint32 packed = draft_scratch_adapter(24u), cursor = packed + 8u, shuffled = packed + 16u;
    uint32 result = 0xFFFFFFFFu, checksum, mission, score, secondary, mode, first, lives;
    FUNCTION_MARKER(0x80032388u, "1.EXE");
    for (uint32 i = 0u; i < 6u; ++i)
        w_u8(packed + i, 0u);
    w_u32(cursor, 0u);
    for (uint32 i = 0u; i < 9u; ++i)
    {
        uint32 value = r_u8(password + i), code;
        for (code = 0u; code < 32u; ++code)
            if (value == r_u8(0x800A5B78u + code))
                break;
        sub_80031F3C(packed, cursor, code, 5u);
    }
    sub_80032138(packed);
    for (uint32 i = 0u; i < 45u; ++i)
        sub_80032050(shuffled, sub_80032024(packed, r_u8(0x8008B88Cu + i)), i);
    for (uint32 i = 0u; i < 6u; ++i)
        w_u8(packed + i, r_u8(shuffled + i));
    checksum = sub_80031FBC(packed, cursor, 12u);
    if (checksum == sub_80032094(packed, cursor))
    {
        mission = sub_80031FBC(packed, cursor, 6u);
        score = sub_80031FBC(packed, cursor, 17u);
        secondary = sub_80031FBC(packed, cursor, 2u);
        mode = sub_80031FBC(packed, cursor, 3u);
        first = sub_80031FBC(packed, cursor, 2u);
        lives = sub_80031FBC(packed, cursor, 3u);
        if (mission && mission < 26u && score <= 99999u)
        {
            sub_80072388(mode);
            w_u32(0x800A854Cu, mission);
            sub_8003D6A0((uint32)(sint32)(sint16)first);
            sub_8003D694((uint32)(sint32)(sint16)secondary);
            w_u32(0x800A7C6Cu, score);
            w_u32(0x800A84A0u, lives);
            sub_8003D27C(255u);
            result = 0u;
        }
    }
    draft_scratch_release(mark);
    return result;
}
