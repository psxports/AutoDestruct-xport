#include "draft_signatures.h"

void sub_8003F7D8(uint32 object, uint32 destination, uint32 distance);
uint32 sub_8003FAD0(uint32 object, uint32 mode, uint32 model, uint32 value);
uint32 sub_80069BE0(uint32 first, uint32 second);

uint32 sub_8003CE7C(uint32 index)
{
    uint32 signed_index = (uint32)(sint32)(sint16)index;
    FUNCTION_MARKER(0x8003CE7Cu, "1.EXE");
    uint32 entry = r_u32(0x800901DCu + signed_index * 12u);
    return (uint32)(sint32)(sint16)r_u16(entry + 4u);
}

uint32 sub_8003D02C(uint32 index, uint32 amount)
{
    uint32 signed_index = (uint32)(sint32)(sint16)index;
    uint32 counter = 0x800A5EACu + signed_index * 2u;
    uint32 result;
    FUNCTION_MARKER(0x8003D02Cu, "1.EXE");
    if ((sint16)r_u16(counter) == -1)
        w_u16(counter, 0u);
    w_u16(counter, r_u16(counter) + amount);
    result = (sint16)sub_8003CE7C(signed_index) < (sint16)r_u16(counter);
    if (result != 0u)
    {
        result = sub_8003CE7C(signed_index);
        w_u16(counter, result);
    }
    return result;
}

uint32 sub_8003F79C(uint32 object, uint32 mode, uint32 value)
{
    uint32 result = r_u8(object + 13u) & 127u;
    FUNCTION_MARKER(0x8003F79Cu, "1.EXE");
    if (result == 1u)
        return sub_8003D02C((uint32)(sint32)(sint16)mode, (uint32)(sint32)(sint16)value);
    return result;
}

uint32 sub_8003FA50(uint32 object, uint32 mode)
{
    FUNCTION_MARKER(0x8003FA50u, "1.EXE");
    uint32 model = (uint32)(sint32)(sint16)r_u16(r_u32(0x800A62ECu) + 204u);
    if (sub_8003FAD0(object, 0u, model, 512u) != 0u)
        return sub_8003F79C(object, (uint32)(sint32)(sint16)mode, 1u);
    return (uint32)draft_call_adapter(0x80035A08u, 37u, 2048u, 255u, 0u, 0u);
}

uint32 sub_8003F974(uint32 object)
{
    uint32 previous_x = r_u32(object + 20u);
    uint32 previous_z = r_u32(object + 28u);
    uint32 owner = r_u32(object + 8u);
    uint32 current_x, current_z, distance;
    sint32 result;
    FUNCTION_MARKER(0x8003F974u, "1.EXE");
    w_u32(object + 20u, r_u32(owner + 20u));
    current_x = r_u32(object + 20u);
    w_u32(object + 24u, r_u32(owner + 24u));
    current_z = r_u32(owner + 28u);
    w_u32(object + 28u, current_z);
    distance = sub_80069BE0(previous_x - current_x, previous_z - current_z);
    w_u16(object + 16u, r_u16(object + 16u) - distance);
    w_u8(object + 13u, r_u8(object + 13u) - r_u8(0x800A9010u));
    if ((sint16)r_u16(object + 16u) < 0)
    {
        owner = r_u32(object + 8u);
        w_u16(object + 16u, r_u16(object + 18u));
        sub_8003FA50(owner, 0u);
    }
    result = (sint8)r_u8(object + 13u);
    if (result < 0)
        return sub_8002289C(object);
    return (uint32)result;
}

uint32 sub_8003F814(uint32 object, uint32 mode)
{
    uint32 mark = draft_scratch_mark();
    uint32 locals = draft_scratch_adapter(32u);
    uint32 position = locals, normal = locals + 16u, tag = locals + 24u;
    uint32 model, height, second, distance, effect, result;
    FUNCTION_MARKER(0x8003F814u, "1.EXE");
    model = r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
    distance = (uint32)(((sint32)(sint16)r_u16(model + 34u) >> 1) - 50);
    sub_8003F7D8(object, position, distance);
    height = (uint32)draft_call_adapter(0x8002E310u, position, normal, tag) + r_u32(object + 24u);
    second = (uint32)draft_call_adapter(0x8002E310u, position, normal, tag) + r_u32(object + 24u);
    distance = (sint32)height < 0 ? 0u - second : second;
    if ((sint32)distance >= 300)
    {
        result = sub_8003F79C(object, (uint32)(sint32)(sint16)mode, 1u);
        return (uint32)draft_scratch_result(mark, result);
    }
    effect = (uint32)draft_call_adapter(0x80022744u, 56u, object);
    w_u32(effect, 0x8003F974u);
    w_u32(effect + 20u, r_u32(object + 20u));
    w_u32(effect + 24u, r_u32(object + 24u));
    result = r_u32(object + 28u);
    w_u8(effect + 13u, 48u);
    w_u16(effect + 16u, 300u);
    w_u16(effect + 18u, 300u);
    w_u32(effect + 28u, result);
    result = (uint32)draft_call_adapter(0x80035A08u, 38u, 2048u, 255u, 0u, 0u);
    return (uint32)draft_scratch_result(mark, result);
}
