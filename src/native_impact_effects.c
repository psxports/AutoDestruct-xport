#include "native_call_dispatch.h"

uint32 sub_8003FEB4(uint32 matrix, uint32 scales)
{
    uint32 offset = 12u, result, remaining = 3u;
    FUNCTION_MARKER(0x8003FEB4u, "1.EXE");
    do {
        sint32 product = (sint32)((uint32)(sint32)(sint16)r_u16(matrix + offset) * r_u32(scales));
        uint32 second = (uint32)(sint32)(sint16)r_u16(matrix + offset + 4u);
        w_u16(matrix + offset, (uint32)(product >> 12));
        product = (sint32)(second * r_u32(scales + 8u));
        result = (uint32)(product >> 12);
        w_u16(matrix + offset + 4u, result);
        offset -= 6u;
    } while (--remaining != 0u);
    return result;
}

uint32 sub_8003FFB4(uint32 object)
{
    uint32 life = r_u16(object + 8u) - r_u16(0x800A9010u);
    uint32 result = life << 16;
    FUNCTION_MARKER(0x8003FFB4u, "1.EXE");
    w_u16(object + 8u, life);
    if ((sint32)result < 0) {
        result = 0x8003FFECu;
        w_u32(object, result);
    }
    return result;
}

uint32 sub_8003FFEC(uint32 object)
{
    uint32 step = (uint32)((sint32)r_u32(0x800A63D8u) >> 8);
    uint32 size = r_u16(object + 10u) - (uint32)((sint32)(step * 12800u) >> 16);
    uint32 mark, scratch, result;
    FUNCTION_MARKER(0x8003FFECu, "1.EXE");
    w_u16(object + 10u, size);
    if ((sint16)size < 0) return sub_8002289C(object);
    mark = draft_scratch_mark();
    scratch = draft_scratch_adapter(12u);
    w_u32(scratch + 8u, (uint32)(sint32)(sint16)size);
    w_u32(scratch, (uint32)(sint32)(sint16)size);
    draft_call_adapter(0x80054D38u, (uint32)(sint32)(sint16)r_u16(object + 16u),
        0u, (uint32)(sint32)(sint16)r_u16(object + 18u), object + 36u);
    result = sub_8003FEB4(object + 36u, scratch);
    return (uint32)draft_scratch_result(mark, result);
}

uint32 sub_8003FD78(uint32 object)
{
    uint32 owner = r_u32(object + 16u), model, limit, result;
    FUNCTION_MARKER(0x8003FD78u, "1.EXE");
    model = r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(owner + 32u));
    limit = (uint32)((sint32)(sint16)r_u16(model + 34u) >> 1) + 100u;
    result = (uint32)draft_call_adapter(0x80069BE0u,
        r_u32(object + 20u) - r_u32(owner + 20u),
        r_u32(object + 28u) - r_u32(owner + 28u));
    if (limit < result) {
        w_u32(object, 0x8003FE30u);
        result = r_u8(owner + 15u) - 1u;
        w_u8(owner + 15u, result);
    }
    return result;
}

uint32 sub_8003FE30(uint32 object)
{
    uint32 life = r_u16(object + 8u) - r_u16(0x800A9010u);
    FUNCTION_MARKER(0x8003FE30u, "1.EXE");
    w_u16(object + 8u, life);
    if ((sint16)life < 0) return sub_8002289C(object);
    return sub_80029970(object, r_u8(object + 13u) != 0u ? 51u : 50u,
        5u, 1u, object + 20u);
}

uint32 sub_8003FF08(uint32 object)
{
    uint32 step = (uint32)((sint32)r_u32(0x800A63D8u) >> 8);
    uint32 size = r_u16(object + 10u) + (uint32)((sint32)(step * 25600u) >> 16);
    uint32 mark, scratch, result;
    FUNCTION_MARKER(0x8003FF08u, "1.EXE");
    w_u16(object + 10u, size);
    if ((sint16)size >= 6000) {
        w_u16(object + 10u, 6000u);
        w_u32(object, 0x8003FFB4u);
        return 0x8003FFB4u;
    }
    mark = draft_scratch_mark();
    scratch = draft_scratch_adapter(12u);
    w_u32(scratch + 8u, (uint32)(sint32)(sint16)size);
    w_u32(scratch, (uint32)(sint32)(sint16)size);
    draft_call_adapter(0x80054D38u, (uint32)(sint32)(sint16)r_u16(object + 16u),
        0u, (uint32)(sint32)(sint16)r_u16(object + 18u), object + 36u);
    result = sub_8003FEB4(object + 36u, scratch);
    return (uint32)draft_scratch_result(mark, result);
}
