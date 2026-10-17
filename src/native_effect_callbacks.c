#include "psx.h"
#include "xport.h"
#include "draft_adapters.h"
#include "native_call_dispatch.h"

uint32 sub_80060154(uint32 object, uint32 count, uint32 speed)
{
    uint32 result;
    FUNCTION_MARKER(0x80060154u, "1.EXE");
    while ((sint32)count > 0)
    {
        uint32 particle = sub_800227C4(40u);
        uint32 models, flags, model, random, coordinate;
        w_u32(particle, 0x80060738u);
        w_u8(particle + 34u, 11u);
        models = r_u32(0x800A62ECu);
        w_u16(particle + 36u, 288u);
        flags = r_u8(particle + 14u);
        w_u16(particle + 38u, 0u);
        model = r_u16(models + 62u);
        w_u8(particle + 14u, flags | 2u);
        w_u16(particle + 32u, model);
        random = sub_80069A50();
        coordinate = r_u32(object + 20u);
        w_u32(particle + 20u, coordinate - 255u + (random & 511u));
        w_u32(particle + 24u, r_u32(object + 24u));
        random = sub_80069A50();
        --count;
        coordinate = r_u32(object + 28u);
        w_u16(particle + 8u, 0u);
        w_u16(particle + 10u, speed);
        w_u32(particle + 28u, coordinate - 255u + (random & 511u));
        w_u16(particle + 16u, (sub_80069A50() & 127u) - 64u);
    }
    result = r_u16(object + 16u) - (r_u32(0x800A9010u) << 3);
    w_u16(object + 16u, result);
    result <<= 16;
    if ((sint32)result < 0)
    {
        draft_call_adapter(0x800225D8u, r_u32(object + 8u));
        sub_80036CFC(object + 35u);
        result = sub_8002289C(object);
    }
    return result;
}

uint32 sub_8006027C(uint32 object)
{
    uint32 counter, random;
    sint32 count;
    FUNCTION_MARKER(0x8006027Cu, "1.EXE");
    counter = r_u8(object + 13u) + r_u8(0x800A9010u);
    count = (sint8)counter / 3;
    w_u8(object + 13u, counter);
    if (count)
        w_u8(object + 13u, 0u);
    sub_800369E0(object + 20u, object + 35u, 2048u, 16u);
    random = sub_80069A50();
    return sub_80060154(object, (uint32)count, (uint32)(sint32)(sint16)r_u16(object + 18u) + (random & 127u));
}

uint32 sub_800666E8(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 temporary, step = r_u32(0x800A9010u);
    uint32 pitch_delta, yaw_delta, pitch, yaw, velocity, x, y, z, dz;
    uint32 result = 6u;
    sint32 ground;
    FUNCTION_MARKER(0x800666E8u, "1.EXE");
    pitch_delta = (uint32)(sint32)(sint16)r_u16(object + 70u) * step;
    yaw_delta = (uint32)(sint32)(sint16)r_u16(object + 72u) * step;
    velocity = r_u16(object + 68u);
    pitch = r_u16(object + 60u);
    w_u16(object + 68u, velocity - 3u * step);
    yaw = r_u16(object + 62u);
    w_u16(object + 60u, pitch + pitch_delta);
    w_u16(object + 62u, yaw - yaw_delta);
    sub_80055288(object + 60u, object + 36u);
    x = (uint32)(sint32)(sint16)r_u16(object + 66u);
    x += r_u32(object + 20u);
    z = r_u32(object + 28u);
    velocity = (uint32)(sint32)(sint16)r_u16(object + 68u);
    dz = (uint32)(sint32)(sint16)r_u16(object + 74u);
    w_u32(object + 20u, x);
    y = r_u32(object + 24u) - velocity;
    w_u32(object + 28u, z + dz);
    w_u32(object + 24u, y);
    temporary = draft_scratch_adapter(16u);
    ground = (sint16)(0u - (uint32)draft_call_adapter(0x8002E310u, object + 20u, temporary, temporary + 8u));
    if (ground < (sint32)r_u32(object + 24u))
    {
        if ((sint16)r_u16(temporary + 8u) == 6)
        {
            sub_80054934(object, 3u);
            result = sub_8002289C(object);
        }
        else
        {
            uint32 model;
            x = r_u16(object + 66u);
            z = r_u16(object + 74u);
            w_u32(object + 24u, (uint32)ground);
            w_u16(object + 66u, (uint32)((sint32)(sint16)x >> 1));
            pitch = r_u16(object + 70u);
            w_u16(object + 74u, (uint32)((sint32)(sint16)z >> 1));
            yaw = r_u16(object + 72u);
            w_u16(object + 70u, (uint32)((sint32)(sint16)pitch >> 1));
            velocity = (uint32)(sint32)(sint16)r_u16(object + 68u);
            w_u16(object + 72u, (uint32)((sint32)(sint16)yaw >> 1));
            w_u16(object + 68u, (uint32)((sint32)(0u - velocity) >> 1));
            draft_call_adapter(0x80035A08u, 8u, 2048u, 0u, object + 20u, 0u);
            step = r_u32(0x800A9010u);
            velocity = (uint32)(sint32)(sint16)r_u16(object + 68u);
            model = (uint32)(sint32)(sint16)r_u16(r_u32(0x800A62ECu) + 76u);
            if ((sint32)velocity < (sint32)(step << 1))
            {
                sub_8006268C(object + 20u, 0u, 0u, model, 128u, 0x1C000u, 15u);
                sub_80060B84(object, 0u, 128u, 0x18000u, 9u);
                draft_call_adapter(0x80035A08u, 61u, 2048u, 255u, object + 20u, 1u);
                draft_call_adapter(0x80035A08u, 13u, 2048u, 255u, object + 20u, 1u);
                sub_8005F69C(object);
                result = sub_8002289C(object);
            }
            else
            {
                result = sub_8006268C(object + 20u, 0u, 0u, model, 96u, 0x14CCCu, 3u);
            }
        }
    }
    draft_scratch_release(mark);
    return result;
}
