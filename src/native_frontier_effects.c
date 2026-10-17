#include "psx.h"
#include "xport.h"
#include "draft_adapters.h"
#include "native_call_dispatch.h"

void sub_80060B84(uint32 owner, uint32 transform, uint32 kind, uint32 scale, uint32 count)
{
    uint32 mark = draft_scratch_mark();
    uint32 vector, factor = (uint32)((sint32)scale >> 8);
    FUNCTION_MARKER(0x80060B84u, "1.EXE");
    if ((sint32)count > 0)
    {
        vector = draft_scratch_adapter(8u);
        for (uint32 index = 0u; (sint32)index < (sint32)count; ++index)
        {
            uint32 particle = sub_800227C4(40u);
            uint32 x, y, z, position_z;
            w_u8(particle + 34u, 8u);
            w_u16(particle + 36u, 288u);
            w_u16(particle + 38u, 0u);
            w_u32(particle + 20u, r_u32(owner + 20u));
            w_u32(particle + 24u, r_u32(owner + 24u));
            position_z = r_u32(owner + 28u);
            w_u32(particle, 0x80060E20u);
            w_u32(particle + 28u, position_z);
            x = (sub_80069A50() & 31u) + 0xFFF1u;
            w_u16(vector, x);
            y = (sub_80069A50() & 31u) + 7u;
            w_u16(vector + 2u, y);
            z = (sub_80069A50() & 31u) + 0xFFF1u;
            x = ((uint32)(sint32)(sint16)r_u16(vector) << 8) * factor;
            y = ((uint32)(sint32)(sint16)r_u16(vector + 2u) << 8) * factor;
            z = ((uint32)(sint32)(sint16)z << 8) * factor;
            w_u16(vector, (uint32)((sint32)x >> 16));
            w_u16(vector + 2u, (uint32)((sint32)y >> 16));
            w_u16(vector + 4u, (uint32)((sint32)z >> 16));
            if (transform)
                sub_8005EE38(vector, transform);
            w_u16(particle + 8u, kind);
            w_u16(particle + 10u, r_u16(vector));
            w_u16(particle + 16u, r_u16(vector + 2u));
            w_u16(particle + 18u, r_u16(vector + 4u));
            w_u8(particle + 13u, sub_80069A50() + 129u);
            w_u8(particle + 35u, 1u);
        }
    }
    draft_scratch_release(mark);
}

uint32 sub_80060078(uint32 position, uint32 owner)
{
    uint32 mark = draft_scratch_mark();
    uint32 temporary = draft_scratch_adapter(16u);
    uint32 height, particle, model, flags, position_z, models;
    FUNCTION_MARKER(0x80060078u, "1.EXE");
    height = 0u - (uint32)draft_call_adapter(0x8002E310u, position, temporary, temporary + 8u);
    if (height)
        w_u32(position + 4u, height - 150u);
    particle = sub_800227C4(40u);
    w_u16(particle + 36u, 288u);
    w_u16(particle + 38u, 0u);
    w_u32(particle + 20u, r_u32(position));
    w_u32(particle + 24u, r_u32(position + 4u));
    position_z = r_u32(position + 8u);
    w_u8(particle + 34u, 11u);
    w_u32(particle + 28u, position_z);
    models = r_u32(0x800A62ECu);
    flags = r_u8(particle + 14u);
    model = r_u16(models + 62u);
    w_u8(particle + 14u, flags | 2u);
    flags = r_u8(particle + 14u);
    w_u32(particle, 0x8006027Cu);
    w_u16(particle + 16u, 4096u);
    w_u16(particle + 18u, 192u);
    w_u8(particle + 13u, 0u);
    w_u32(particle + 8u, owner);
    w_u8(particle + 35u, 255u);
    w_u16(particle + 32u, model);
    w_u8(particle + 14u, flags | 64u);
    draft_scratch_release(mark);
    return particle;
}

uint32 sub_80063450(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 model = r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
    uint32 height = (uint32)((sint32)((uint32)r_u16(r_u32(0x800A90ACu) + model * 40u + 34u) << 16) >> 17) + 20u;
    uint32 result;
    FUNCTION_MARKER(0x80063450u, "1.EXE");
    result = sub_8003DB0C(object);
    if (!result)
    {
        uint32 vector = draft_scratch_adapter(8u);
        uint32 distance = 200u, lifetime = 75u, model_offset = 62u;
        for (uint32 index = 0u; index < 8u; ++index)
        {
            uint32 particle, random, models, flags;
            distance -= 25u;
            lifetime -= 5u;
            model_offset -= 2u;
            particle = sub_800227C4(40u);
            w_u8(particle + 34u, 8u);
            w_u16(vector, 0u);
            w_u16(vector + 2u, 0u);
            w_u16(vector + 4u, height + distance);
            sub_80031CE8(object + 36u, object + 20u, vector, particle + 20u);
            w_u32(particle, 0x800613D0u);
            w_u16(particle + 8u, 1u);
            w_u16(particle + 36u, lifetime);
            random = sub_80069A50();
            models = r_u32(0x800A62ECu);
            w_u16(particle + 38u, random);
            flags = r_u8(particle + 14u);
            model = r_u16(models + model_offset);
            result = flags | 2u;
            w_u8(particle + 14u, result);
            w_u16(particle + 32u, model);
        }
    }
    draft_scratch_release(mark);
    return result;
}

uint32 sub_800665E0(uint32 object, uint32 vector)
{
    uint32 particle, result, flags;
    FUNCTION_MARKER(0x800665E0u, "1.EXE");
    particle = (uint32)draft_call_adapter(0x800226E4u, 76u);
    for (uint32 offset = 20u; offset < 52u; offset += 16u)
    {
        uint32 a = r_u32(object + offset);
        uint32 b = r_u32(object + offset + 4u);
        uint32 c = r_u32(object + offset + 8u);
        uint32 d = r_u32(object + offset + 12u);
        w_u32(particle + offset, a);
        w_u32(particle + offset + 4u, b);
        w_u32(particle + offset + 8u, c);
        w_u32(particle + offset + 12u, d);
    }
    w_u32(particle + 52u, r_u32(object + 52u));
    w_u32(particle, 0x800666E8u);
    w_u8(particle + 34u, 11u);
    flags = r_u8(object + 14u);
    w_u32(particle + 8u, 0u);
    w_u8(particle + 14u, flags & 0xF7u);
    w_u16(particle + 60u, r_u16(vector));
    w_u16(particle + 62u, r_u16(vector + 2u));
    w_u16(particle + 64u, r_u16(vector + 4u));
    w_u16(particle + 66u, (sub_80069A50() & 63u) + 0xFFE1u);
    w_u16(particle + 68u, 128u);
    w_u16(particle + 70u, 30u);
    w_u16(particle + 72u, 20u);
    result = (sub_80069A50() & 63u) + 0xFFE1u;
    w_u16(particle + 74u, result);
    return result;
}
