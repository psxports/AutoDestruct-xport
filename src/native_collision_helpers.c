#include "native_call_dispatch.h"

uint32 sub_80045510(uint32 object)
{
    sint32 timer = (sint16)r_u16(object + 114u);
    uint32 result = (uint32)timer - 1u;
    FUNCTION_MARKER(0x80045510u, "1.EXE");
    if (timer > 0) w_u16(object + 114u, result);
    else if (timer == 0) {
        w_u16(object + 114u, result);
        /* Original 800510C8 is an empty leaf */
        w_u8(object + 14u, 1u);
        result = 0x80029968u;
        w_u32(object, result);
        w_u32(object + 140u, 0u);
    }
    return result;
}

static uint32 collision_link(uint32 object, uint32 offset)
{
    return r_u32(r_u32(0x800A851Cu) + 4u * (uint32)(sint32)(sint16)r_u16(object + offset));
}

static void collision_detach_chain(uint32 object, uint32 offset)
{
    uint32 current = object;
    if ((sint16)r_u16(current + offset) == -1) return;
    do {
        uint32 previous, next;
        if ((sint16)r_u16(current + 162u) != -1) {
            uint32 owner = collision_link(current, 162u);
            w_u8(owner + 66u, r_u8(owner + 66u) - 1u);
            w_u16(current + 162u, 0xFFFFu);
        }
        w_u8(current + 65u, 0u);
        if (current != object) {
            w_u32(current, 0x80045510u);
            w_u16(current + 114u, 4u);
        }
        previous = current;
        next = collision_link(previous, offset);
        if (r_u16(previous + offset) == r_u16(next + offset))
            w_u16(next + offset, 0xFFFFu);
        current = next;
    } while ((sint16)r_u16(current + offset) != -1);
}

uint32 sub_8004D8B4(uint32 object)
{
    uint32 model, type, index, group;
    FUNCTION_MARKER(0x8004D8B4u, "1.EXE");
    model = sub_800476D8((uint32)(sint32)(sint16)r_u16(object + 172u));
    w_u32(model + 4u, r_u32(model + 4u) & ~0x200u);
    model = sub_800476D8((uint32)(sint32)(sint16)r_u16(object + 174u));
    w_u32(model + 4u, r_u32(model + 4u) & ~0x200u);
    type = r_u8(object + 197u);
    w_u8(object + 13u, 2u);
    if (type < 7u || (type >= 10u && type != 22u)) sub_80036CFC(object + 324u);
    if (type != 22u) sub_80036CFC(object + 194u);
    w_u16(object + 188u, 0u);
    w_u8(object + 65u, 0u);
    w_u8(object + 64u, 0u);
    w_u16(object + 160u, 0xFFFFu);
    if ((sint16)r_u16(object + 162u) != -1) {
        uint32 owner = collision_link(object, 162u);
        if (r_u8(owner + 64u) == 0u) {
            w_u8(owner + 66u, r_u8(owner + 66u) - 1u);
            w_u16(object + 162u, 0xFFFFu);
        }
    }
    if (r_u8(object + 67u) != 0u) {
        uint32 table = r_u32(0x800A851Cu);
        uint32 player = r_u32(table + 4u * (uint32)(sint32)(sint16)r_u16(0x800A9730u));
        if (player == object || r_u32(table + 4u * (uint32)(sint32)(sint16)r_u16(0x800A9A78u)) == object)
            sub_8004525C();
    }
    index = r_u16(object + 70u) == 0u;
    type = r_u8(object + 67u);
    group = type == 1u ? 0u : 1u;
    if (type == 1u || type == 2u) {
        uint32 counter = 0x800A7F5Cu + 4u * group + 2u * index;
        w_u16(counter, r_u16(counter) - 1u);
        sub_80044F8C(index);
    }
    collision_detach_chain(object, 156u);
    collision_detach_chain(object, 158u);
    w_u16(object + 114u, 4u);
    return 4u;
}

uint32 sub_80054934(uint32 object, uint32 mode)
{
    uint32 mark = draft_scratch_mark();
    uint32 scratch = draft_scratch_adapter(24u), effect, index, sound = 1024u, result;
    FUNCTION_MARKER(0x80054934u, "1.EXE");
    w_u32(scratch, r_u32(0x800A61D0u));
    w_u32(scratch + 4u, r_u32(0x800A61D4u));
    if (mode == 0u) draft_call_adapter(0x80035A08u, 51u, 1024u, 255u, 0u, 0u);
    effect = (uint32)draft_call_adapter(0x800226E4u, mode == 1u ? 456u : mode == 0u ? 228u : 84u);
    if (mode == 1u) w_u32(effect, 0x800548B0u);
    w_u8(effect + 34u, 11u);
    if (mode != 0u && mode != 1u) w_u32(effect, 0x80054660u);
    w_u32(effect + 20u, r_u32(object + 20u));
    w_u32(effect + 24u, r_u32(object + 24u));
    w_u32(effect + 28u, r_u32(object + 28u));
    w_u8(effect + 14u, r_u8(effect + 14u) | (mode != 0u && mode != 1u ? 0x42u : 2u));
    if (mode == 0u) w_u32(effect, 0x800547ECu);
    w_u16(effect + 32u, r_u16(object + 32u));
    if (mode == 1u) {
        for (index = 0u; index < 9u; ++index) {
            uint32 entry = effect + 36u * index;
            w_u8(entry + 98u, 0u);
            w_u16(entry + 96u, r_u16(r_u32(0x800A62ECu) + 2u * r_u8(0x800136E9u + index)));
        }
        sub_80022908(effect, effect + 84u, 10u);
        w_u16(effect + 444u, 0u); w_u16(effect + 446u, 0u);
        w_u32(effect + 452u, 0u); w_u16(effect + 450u, 0u); w_u16(effect + 448u, 1u);
    } else if (mode == 0u) {
        w_u8(object + 14u, 1u);
        sound = 0u;
        if ((uint32)r_u16(object + 32u) == (uint32)(sint32)(sint16)r_u16(r_u32(0x800A62ECu) + 26u)) {
            sub_80022908(effect, effect + 84u, 4u);
            for (index = 0u; index < 4u; ++index) {
                w_u8(effect + 36u * index + 98u, 15u);
                w_u16(effect + 36u * index + 96u, r_u16(r_u32(0x800A62ECu) + 28u));
            }
        }
    }
    for (index = 0u; index < 4u; ++index) w_u32(effect + 36u + 4u * index, r_u32(object + 36u + 4u * index));
    w_u16(effect + 52u, r_u16(object + 52u));
    for (index = 0u; index < 4u; ++index) w_u32(effect + 64u + 4u * index, r_u32(object + 36u + 4u * index));
    w_u16(effect + 80u, r_u16(object + 52u));
    w_u32(effect + 16u, 0x80090B54u);
    w_u16(effect + 82u, mode == 4u);
    if (r_u32(0x800A9A58u) == object) {
        uint32 follower = (uint32)draft_call_adapter(0x800226E4u, 56u);
        if (follower != 0u) {
            w_u8(follower + 14u, 1u); w_u32(follower, 0x80029968u); w_u32(follower + 16u, 0x80090B54u);
            w_u32(follower + 20u, r_u32(object + 20u)); w_u32(follower + 24u, r_u32(object + 24u));
            w_u32(0x800A9A58u, follower); w_u32(follower + 28u, r_u32(object + 28u));
        }
    }
    result = 0u - (uint32)draft_call_adapter(0x8002E310u, object + 20u, scratch + 8u, scratch + 16u);
    w_u32(effect + 60u, result);
    if ((sint32)result < 0) result = 0u - result;
    {
        uint32 model = r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
        sint32 size = (sint16)r_u16(model + 32u);
        result -= (uint32)(size / 2);
    }
    w_u16(effect + 56u, result);
    if ((sint16)result >= 1201) w_u16(effect + 56u, 1200u);
    w_u16(effect + 58u, 0u);
    result = (uint32)draft_call_adapter(0x80062B08u, effect);
    if (sound != 0u) result = (uint32)draft_call_adapter(0x80035A08u, 51u, 1024u, 0u, object + 20u, 0u);
    return (uint32)draft_scratch_result(mark, result);
}
