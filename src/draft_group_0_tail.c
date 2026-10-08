#include "draft_signatures.h"

/* FUNCTION_MARKER: sub_800327C8 */
uint32 sub_800327C8(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result;
    uint64 value = (uint64)r_u32(0x800A9CECu) | ((uint64)r_u32(0x800A9CF0u) << 32);
    sub_800698C8(0x800A6C50u, value);
    if (r_u32(0x800A9760u) == 1u) {
        if (r_u32(0x800A9864u) == 1u) {
            /* TODO: Bind the original 80032E6C rendering boundary */
            draft_call_adapter(0x80032E6Cu, 0x800A5BE8u, 0x00808000u, 0u, 0u, 0u, 230u, (uint32)-100);
        } else {
            draft_call_adapter(0x80032E6Cu, 0x800A5BE8u, 0x00808000u,
                r_u32(0x800A6C54u), r_u32(0x800A6C58u), r_u32(0x800A6C5Cu), 230u, (uint32)-100);
        }
        uint32 index = 6u * r_u32(0x800A9764u) + r_u32(0x800A9768u);
        draft_call_adapter(0x80032E6Cu, 0x800A5BE8u, 0x00808080u,
            (uint32)r_u8(0x800A978Au + index), (uint32)r_u8(0x800A97A8u + index),
            (uint32)r_u8(0x800A97C6u + index), 0u, (uint32)-100);
    } else {
        sub_80032F44();
    }
    if (r_u32(0x800A9864u) == 1u && r_u32(0x800A7BF4u) == 1u) {
        /* TODO: Bind the original 80043BBC boundary */
        draft_call_adapter(0x80043BBCu, 0x00808080u, 3u - r_u32(0x800A6C58u), 0u, 0u);
        result = r_u32(0x800A6C58u);
        if (result == 3u) {
            w_u32(0x800A9CECu, 0u);
            w_u32(0x800A9CF0u, 0u);
            w_u32(0x800A9864u, 0u);
            w_u32(0x800A9868u, 1u);
        }
    } else {
        result = 1u;
        if (r_u32(0x800A9760u) == 1u && r_u32(0x800A9868u) == 1u) {
            result = r_u32(0x800A7BF4u);
            if (result == 1u)
                return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80043BBCu, 0x00808080u, 0u, 0u, 0u)));
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80033B0C */
uint32 sub_80033B0C(uint32 index, uint32 world_x, uint32 world_z, uint32 kind, uint32 offset_x, uint32 offset_y)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 x = (uint32)((int32)world_x / 2560) - 2u;
    uint32 z = 126u - (uint32)((int32)world_z / 2560);
    if (x >= 129u || z >= 129u)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    kind &= 255u;
    uint32 width = r_u8(0x8008B8ECu + 2u * kind);
    uint32 height = r_u8(0x8008B8EDu + 2u * kind);
    uint32 u = r_u8(0x8008B8BCu + 2u * kind);
    uint32 v = r_u8(0x8008B8BDu + 2u * kind);
    /* TODO: Bind the original primitive construction and submission boundaries */
    draft_call_adapter(0x80041C9Cu, 0x800A6CB4u, 0x64000040u, width, height, 6u, u, v, 352u, 480u);
    draft_call_adapter(0x80041C9Cu, 0x800A6C94u, 0x54000040u, width, height, 6u, u, v, 352u, 480u);
    draft_call_adapter(0x80041DB4u, 0x800A6CB4u, offset_x + x, offset_y + z, 0u);
    draft_call_adapter(0x80041DB4u, 0x800A6C94u, offset_x + x, offset_y + z, 0u);
    draft_call_adapter(0x80041D90u, 0x800A6C94u,
        r_u32(0x800A6C70u + 12u * index) & r_u32(0x8008B91Cu + 4u * kind));
    draft_call_adapter(0x80020AB4u, 0x800A6C94u, r_u32(0x800A9A74u) + 716u, 1u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80020AB4u, 0x800A6CB4u, r_u32(0x800A9A74u) + 720u, 1u, 0u)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800334D4 */
uint32 sub_800334D4(uint32 index, uint32 offset_x, uint32 offset_y)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 slot = r_u32(0x800A851Cu) + 4u * (uint32)(int32)(int16)index;
    uint32 entity = r_u32(slot);
    uint32 x = (uint32)((int32)r_u32(entity + 20u) / 2560) - 2u;
    uint32 z = 126u - (uint32)((int32)r_u32(entity + 28u) / 2560);
    if (x >= 129u || z >= 129u)
        return draft_scratch_result(native_stack_mark, (uint64)(255u));
    uint32 flags = r_u8(entity + 14u);
    if (!(flags & 8u))
        return draft_scratch_result(native_stack_mark, (uint64)(255u));
    if (!(flags & 2u)) {
        uint32 type = r_u8(entity + 13u) & 15u;
        if (type != 5u && type != 13u)
            return draft_scratch_result(native_stack_mark, (uint64)(255u));
    }
    entity = r_u32(r_u32(0x800A851Cu) + 4u * (uint32)(int32)(int16)index);
    uint32 kind = r_u8(entity + 13u) & 15u;
    uint32 width = r_u8(0x8008B8ECu + 2u * kind);
    uint32 height = r_u8(0x8008B8EDu + 2u * kind);
    uint32 u = r_u8(0x8008B8BCu + 2u * kind);
    uint32 v = r_u8(0x8008B8BDu + 2u * kind);
    /* TODO: Bind the original primitive construction and positioning boundaries */
    draft_call_adapter(0x80041C9Cu, 0x800A6CB4u, 0x64000040u, width, height, 6u, u, v, 352u, 480u);
    draft_call_adapter(0x80041C9Cu, 0x800A6C94u, 0x54000040u, width, height, 6u, u, v, 352u, 480u);
    uint32 screen_x = (uint32)(int32)(int16)offset_x + x;
    uint32 screen_y = (uint32)(int32)(int16)offset_y + z;
    draft_call_adapter(0x80041DB4u, 0x800A6CB4u, screen_x, screen_y, 0u);
    draft_call_adapter(0x80041DB4u, 0x800A6C94u, screen_x, screen_y, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(kind));

    draft_scratch_release(native_stack_mark);
}
