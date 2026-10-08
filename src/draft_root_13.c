#include "draft_signatures.h"

uint32 sub_80035758(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80035758u, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800205C8u, 1u, 32u, 0u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006F738(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value, flags;
    FUNCTION_MARKER(0x8006F738u, "1.EXE");
    w_u16(0x80091906u, r_u16(0x800A854Cu));
    w_u16(0x80091E26u, (uint16)draft_call_adapter(0x8003D67Cu));
    value = sub_8003D688(); flags = r_u8(0x800A8515u);
    w_u16(0x80091E36u, (uint16)value); w_u16(0x80091E46u, (uint16)flags);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80067160(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 angle, value;
    FUNCTION_MARKER(0x80067160u, "1.EXE");
    if (r_u32(0x800A9A38u) != 4u) {
        if (r_u8(a0 + 14u) & 1u) sub_800369E0(a0 + 20u, a0 + 8u, 1024u, 46u);
        else sub_80036CFC(a0 + 8u);
    }
    angle = (uint32)r_s8(a0 + 13u) * r_u32(0x800A9010u) + r_u32(a0 + 16u);
    value = (uint32)draft_call_adapter(0x800551CCu, angle, a0 + 36u);
    w_u32(a0 + 16u, angle);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006E7D8(uint32 a0, uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object, index, value;
    FUNCTION_MARKER(0x8006E7D8u, "1.EXE");
    object = (uint32)draft_call_adapter(0x80022744u, 56u, a1);
    w_u32(object + 20u, r_u32(a0 + 20u)); w_u32(object + 24u, r_u32(a0 + 24u));
    w_u32(object + 28u, r_u32(a0 + 28u)); sub_80055A70(object + 36u);
    w_u8(object + 35u, 1u); w_u32(object, 0x8006E8A4u);
    w_u32(object + 16u, a1); w_u8(object + 13u, (uint8)a2); w_u16(object + 54u, 0u);
    index = r_u16(0x8009157Cu + a3 * 2u);
    value = (uint32)r_s16(r_u32(0x800A62ECu) + index * 2u);
    w_u16(object + 32u, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

void sub_8005FD2C(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 iterations, size, temporary, x, y, z;
    FUNCTION_MARKER(0x8005FD2Cu, "1.EXE");
    iterations = r_u32(0x800A9010u);
    while ((sint32)iterations > 0) {
        w_u8(a0 + 13u, (uint8)(r_u8(a0 + 13u) - 1u));
        size = r_u16(a0 + 8u) - 1u;
        w_u16(a0 + 8u, (uint16)size);
        if (r_s8(a0 + 13u) <= 0) { sub_8002289C(a0); { draft_scratch_release(native_stack_mark); return; } }
        // TODO Original loop increments this counter rather than decrementing it
        ++iterations;
        if ((sint16)size < 0) {
            x = sub_80069A50(); x = r_u32(a0 + 20u) - 383u + (x & 0x2FFu);
            z = sub_80069A50(); z = r_u32(a0 + 28u) - 383u + (z & 0x2FFu);
            y = r_u32(a0 + 24u);
            temporary = draft_scratch_adapter(16u);
            w_u32(temporary, x); w_u32(temporary + 8u, z); w_u32(temporary + 4u, y);
            draft_call_adapter(0x8005FF80u, temporary, 8u);
            w_u16(a0 + 8u, 3u);
        }
    }

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80035FD8(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value, index, attributes;
    FUNCTION_MARKER(0x80035FD8u, "1.EXE");
    value = (uint32)draft_call_adapter(0x80089118u);
    if (value) return draft_scratch_result(native_stack_mark, (uint64)(value));
    for (index = 0u; index < 24u; ++index) {
        w_u8(0x800A7E34u + index, 1u);
        draft_call_adapter(0x800891B0u, 1u, 1u << index);
    }
    value = r_u16(0x800A5C4Cu);
    w_u32(0x800A8204u, 31u); w_u32(0x800A8208u, 4u);
    w_u32(0x800A8210u, 40u); w_u32(0x800A8214u, 100u);
    w_u16(0x800A820Cu, (uint16)value); w_u16(0x800A820Eu, (uint16)value);
    draft_call_adapter(0x80086F78u, 0x800A8204u);
    draft_call_adapter(0x80089138u, 0x800A8204u);
    draft_call_adapter(0x80089238u, 1u);
    attributes = draft_scratch_adapter(40u);
    w_u32(attributes, 256u);
    w_u32(attributes + 20u, r_s16(0x800A9A64u) != 0);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8008757Cu, attributes)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80037490(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x80037490u, "1.EXE");
    value = (uint32)draft_call_adapter(0x8007B368u, 9u, 0u, 0u);
    w_u32(0x800A7BE0u, value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8007044C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8007044Cu, "1.EXE");
    w_u32(0x800A6464u, 1u);
    sub_80070428(); sub_8006F738();
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8006F7A8()));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80036D6C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index, pointer;
    sint32 voice;
    FUNCTION_MARKER(0x80036D6Cu, "1.EXE");
    for (index = 0u; index < 10u; ++index) {
        pointer = 0x800A7D64u + index * 16u;
        voice = r_s8(r_u32(pointer));
        if (voice < 0) continue;
        draft_call_adapter(0x800891B0u, 0u, 1u << ((uint32)voice & 31u));
        w_u8(r_u32(pointer), 255u); w_u32(pointer, 0x800A7DFCu);
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800375A4u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800375F0(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value;
    FUNCTION_MARKER(0x800375F0u, "1.EXE");
    w_u16(0x800A5C54u, 3u);
    draft_call_adapter(0x80035A08u, 10u, 2048u, 0u, 0u, 0u);
    if (r_s16(0x800A56ACu) != -1) {
        w_u16(0x800A56ACu, 0xFFFFu);
        value = (uint32)draft_call_adapter(0x80035A08u, 58u, 2048u, 192u, 0u, 0u);
        w_u16(0x800A56ACu, (uint16)value);
    }
    w_u16(0x800A56B4u, 0xFFFFu); w_u16(0x800A5C44u, 0xFFFFu);
    value = (uint32)draft_call_adapter(0x80035A08u, 43u, 2048u, 128u, 0u, 0u);
    w_u16(0x800A5C44u, (uint16)value); w_u16(0x800A56AEu, 0xFFFFu);
    value = (uint32)draft_call_adapter(0x80035A08u, 12u, 2048u, 128u, 0u, 0u);
    w_u16(0x800A56AEu, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800632D0(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object, value;
    FUNCTION_MARKER(0x800632D0u, "1.EXE");
    value = sub_80069A50() & 2u;
    if (value) return draft_scratch_result(native_stack_mark, (uint64)(value));
    object = sub_800227C4(40u);
    w_u8(object + 34u, 11u);
    value = r_u16(r_u32(0x800A62ECu) + 0x152u);
    w_u8(object + 14u, (uint8)(r_u8(object + 14u) | 2u)); w_u16(object + 32u, (uint16)value);
    w_u32(object + 20u, r_u32(a0)); w_u32(object + 24u, r_u32(a0 + 4u));
    value = r_u32(a0 + 8u); w_u16(object + 36u, 300u); w_u32(object + 28u, value);
    w_u16(object + 38u, (uint16)sub_80069A50());
    value = r_u8(object + 14u); w_u32(object, 0x800633A0u); w_u8(object + 14u, (uint8)(value | 0x40u));
    value = (sub_80069A50() & 63u) - 31u;
    w_u16(object + 8u, (uint16)value); w_u32(object + 24u, r_u32(object + 24u) - 50u);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80058430(uint32 a0, uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8, uint32 a9, uint32 a10, uint32 a11)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80058430u, "1.EXE");
    draft_call_adapter(0x80041C9Cu, 0x800A7108u, a1, (uint32)(sint16)a2, (uint32)(sint16)a3,
        (uint32)(uint16)a4, (uint32)(sint16)a5, (uint32)(sint16)a6, (uint32)(sint16)a7, (uint32)(sint16)a8);
    draft_call_adapter(0x80041DB4u, 0x800A7108u, a9, a10, 0u);
    draft_call_adapter(0x80041D90u, 0x800A7108u, a0);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80020AB4u, 0x800A7108u, r_u32(0x800A9A74u) + a11 * 4u, 1u, 0u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80067140(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80067140u, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80067390u, a0, a1, a2, 20u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003ACE4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003ACE4u, "1.EXE");
    if (!r_u32(0x800A6DE8u)) {
        sub_80035758(); w_u32(0x800A6DE8u, 1u); w_u32(0x800A6E04u, 1u);
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    }
    if (r_u32(0x800A6E04u) != 1u || !r_u8(0x800A7BDFu)) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    w_u32(0x800A6E48u, 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800633A0(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 step, product, value;
    FUNCTION_MARKER(0x800633A0u, "1.EXE");
    value = (uint32)r_s16(a0 + 36u); step = r_u32(0x800A9010u);
    if ((sint32)value < 30) { w_u16(a0 + 36u, 0u); return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(a0))); }
    product = (uint32)r_s16(a0 + 8u) * step;
    w_u32(a0 + 24u, r_u32(a0 + 24u) + step);
    w_u16(a0 + 36u, (uint16)(r_u16(a0 + 36u) - step * 2u));
    value = r_u16(a0 + 38u) + product; w_u16(a0 + 38u, (uint16)value);
    return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

void sub_8005FDFC(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object, value;
    FUNCTION_MARKER(0x8005FDFCu, "1.EXE");
    while ((sint32)a1 > 0) {
        object = sub_800227C4(40u); w_u8(object + 34u, 8u);
        value = r_u16(r_u32(0x800A62ECu) + 0x3Eu);
        w_u8(object + 14u, (uint8)(r_u8(object + 14u) | 2u)); w_u16(object + 32u, (uint16)value);
        w_u32(object + 20u, r_u32(a0)); w_u32(object + 24u, r_u32(a0 + 4u)); --a1;
        value = r_u32(a0 + 8u); w_u16(object + 36u, 288u); w_u16(object + 38u, 0u);
        w_u32(object, 0x8005FEC0u); w_u16(object + 8u, (uint16)a2); w_u32(object + 28u, value);
        w_u16(object + 10u, (uint16)(sub_80069A50() & 255u));
    }

    draft_scratch_release(native_stack_mark);
}

void sub_8005FC64(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 step, index, temporary, x, z;
    sint32 height;
    FUNCTION_MARKER(0x8005FC64u, "1.EXE");
    // TODO Original return carrier is unspecified when the step is nonpositive
    step = r_u32(0x800A9010u);
    for (index = 0u; (sint32)index < (sint32)step; ++index) {
        x = r_u32(a0 + 20u); w_u8(a0 + 13u, (uint8)(r_u8(a0 + 13u) - 1u));
        z = r_u32(a0 + 28u); height = r_s16(a0 + 16u);
        temporary = draft_scratch_adapter(24u);
        w_u32(temporary, x); w_u32(temporary + 8u, z); w_u32(temporary + 4u, (uint32)height);
        w_u16(a0 + 16u, (uint16)(r_u16(a0 + 16u) - 96u));
        sub_8005FDFC(temporary, 1u, 40u);
        if (r_s8(a0 + 13u) < 0) {
            height = r_s16(a0 + 16u); w_u8(a0 + 13u, 16u); w_u16(a0 + 8u, 0u);
            w_u32(a0, 0x8005FD2Cu); w_u32(a0 + 24u, (uint32)height - 31u);
            { draft_scratch_release(native_stack_mark); return; }
        }
    }

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006706C(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8006706Cu, "1.EXE");
    (void)a2;
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80035A08u, a1 <= 3u ? 8u : 53u, 2048u, 0u, a0, 0u)));

    draft_scratch_release(native_stack_mark);
}
