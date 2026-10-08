#include "draft_signatures.h"

uint64 sub_8005DAB4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 low, high;
    FUNCTION_MARKER(0x8005DAB4u, "1.EXE");
    w_u8(a0 + 44u, 2u); w_u8(a0 + 47u, 2u); w_u8(a0 + 45u, 2u);
    sub_8005E258(2u); sub_8005C560(a0);
    low = r_u32(a0 + 28u); high = r_u32(a0 + 32u);
    w_u32(a0 + 12u, low); w_u32(a0 + 16u, high);
    return draft_scratch_result(native_stack_mark, (uint64)(low | ((uint64)high << 32)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005D780(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 buffer, value;
    FUNCTION_MARKER(0x8005D780u, "1.EXE");
    // TODO Temporary-vector and existing callee ABI boundaries
    buffer = draft_scratch_adapter(16u);
    draft_call_adapter(0x8005B2ACu, 0x800A7EE4u, r_u32(0x800A9A58u) + 20u, buffer);
    value = (uint32)draft_call_adapter(0x80069BE0u, r_u32(buffer), r_u32(buffer + 8u));
    return draft_scratch_result(native_stack_mark, (uint64)((sint32)value >= 4097));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006F818(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 count = 0u, pointer;
    FUNCTION_MARKER(0x8006F818u, "1.EXE");
    while ((sint32)a0 > 0) {
        --a0;
        pointer = r_u32(0x80091EE0u + r_u32(0x800A645Cu) * 12u);
        if (sub_80070A0C(r_u32(pointer + a0 * 16u))) ++count;
    }
    return draft_scratch_result(native_stack_mark, (uint64)(count));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005DB18(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 choice, value;
    FUNCTION_MARKER(0x8005DB18u, "1.EXE");
    w_u16(0x800A8534u, (uint16)((sub_80069A50() & 63u) + 127u));
    choice = (sub_80069A50() & 3u) + 1u;
    sub_8005E258(choice);
    w_u16(a0 + 38u, choice >= 3u ? 50u : 10000u);
    value = sub_8005C560(a0);
    w_u16(0x800A8536u, 0u); w_u16(a0 + 40u, (uint16)a1);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80066958(uint32 descriptor, uint32 x, uint32 z)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object;
    FUNCTION_MARKER(0x80066958u, "1.EXE");
    /* Preserve incoming arguments across the original wrapper */
    object = (uint32)draft_call_adapter(0x80066984u, descriptor, x, z);
    w_u8(object + 13u, 0u); w_u16(object + 82u, 40u);
    return draft_scratch_result(native_stack_mark, (uint64)(object));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800416CC(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800416CCu, "1.EXE");
    if (r_u8(a0 + 12u) >= 2u) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    w_u32(0x800A5F18u, r_u32(0x800A5F18u) - 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(a0)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003CB54(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 target;
    FUNCTION_MARKER(0x8003CB54u, "1.EXE");
    a1 = (uint32)(sint16)a1;
    target = r_u32(0x800901E0u + a1 * 12u);
    // TODO Indirect guest callback adapter
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(target, a0, a1)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800621A4(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object, value, flags;
    FUNCTION_MARKER(0x800621A4u, "1.EXE");
    object = sub_800227C4(40u);
    w_u8(object + 34u, 11u);
    w_u16(object + 38u, 0u); w_u16(object + 36u, 50u);
    w_u16(object + 8u, (uint16)a0);
    value = (sub_80069A50() & 63u) - 31u;
    flags = r_u8(object + 14u);
    w_u16(object + 10u, (uint16)value);
    w_u16(object + 16u, (uint16)a2);
    w_u32(object, 0x800407C0u);
    w_u16(object + 32u, (uint16)a1);
    w_u8(object + 14u, (uint8)(flags | 0x42u));
    return draft_scratch_result(native_stack_mark, (uint64)(object));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003E868(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object;
    FUNCTION_MARKER(0x8003E868u, "1.EXE");
    // TODO Existing object-constructor and audio ABI boundaries
    object = (uint32)draft_call_adapter(0x8003E690u, a0, (uint32)(sint16)a1, 3u);
    draft_call_adapter(0x80035A08u, 50u, 2048u, 255u, 0u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(sub_800369E0(object + 20u, object + 86u, 2048u, 26u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80040AEC(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 step, product, value;
    sint32 size;
    FUNCTION_MARKER(0x80040AECu, "1.EXE");
    step = r_u32(0x800A9010u);
    product = (uint32)r_s16(a0 + 10u) * step;
    value = r_u16(a0 + 36u) - step * 2u;
    w_u16(a0 + 36u, (uint16)value);
    size = (sint16)value;
    w_u16(a0 + 38u, (uint16)(r_u16(a0 + 38u) + product));
    return draft_scratch_result(native_stack_mark, (uint64)(size < 20 ? sub_8002289C(a0) : 0u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005F568(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005F568u, "1.EXE");
    // TODO Existing constructor ABI boundary
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8005F598u, a0, (uint32)r_s16(r_u32(0x800A62ECu) + 0x2Eu), 100u, 12u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005F4E4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 step, product, value;
    sint32 size;
    FUNCTION_MARKER(0x8005F4E4u, "1.EXE");
    step = r_u32(0x800A9010u);
    product = step * (uint32)r_s16(a0 + 18u);
    w_u32(a0 + 24u, r_u32(a0 + 24u) - step * 12u);
    w_u16(a0 + 36u, (uint16)(r_u16(a0 + 36u) - step * 10u));
    size = r_s16(a0 + 36u);
    value = r_u16(a0 + 38u) + product;
    w_u16(a0 + 38u, (uint16)value);
    if (size >= 30) return draft_scratch_result(native_stack_mark, (uint64)(value));
    w_u16(a0 + 36u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(a0)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003EFDC(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 vector;
    FUNCTION_MARKER(0x8003EFDCu, "1.EXE");
    // TODO Temporary vector storage and existing constructor ABI boundary
    vector = draft_scratch_adapter(6u);
    w_u16(vector + 4u, (uint16)-600);
    w_u16(vector, 0u); w_u16(vector + 2u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8003F1B8u, a0, 16u, (uint32)(sint16)a1, (uint32)-700, vector, 21u, 128u, 1024u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003F2C4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x8003F2C4u, "1.EXE");
    value = (uint32)r_s16(a0 + 8u);
    if ((sint32)value <= 0) return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(a0)));
    value -= r_u16(0x800A9010u);
    w_u16(a0 + 8u, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003CA20(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003CA20u, "1.EXE");
    sub_80036E10();
    // TODO Existing callee ABI boundaries
    draft_call_adapter(0x800375A4u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800360BCu)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80036E10(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index, pointer;
    sint32 voice;
    FUNCTION_MARKER(0x80036E10u, "1.EXE");
    for (index = 0u; index < 10u; ++index) {
        pointer = 0x800A7D64u + index * 16u;
        voice = r_s8(r_u32(pointer));
        if (voice < 0) continue;
        // TODO SDK key adapter
        draft_call_adapter(0x800891B0u, 0u, 1u << ((uint32)voice & 31u));
        w_u32(pointer, 0x800A7DFCu);
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800375A4u)));

    draft_scratch_release(native_stack_mark);
}
