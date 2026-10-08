#include "draft_signatures.h"

/* FUNCTION_MARKER: sub_80061938 */
uint32 sub_80061938(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 previous = r_u8(a2), result = sub_800618D4(a1, a3) | (previous & 1u);
    w_u8(a2, (uint8)result); return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80056364 */
uint32 sub_80056364(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result;
    draft_call_adapter(0x8005792Cu, a1); w_u32(a1 + 80u, 4u);
    result = r_u8(a1 + 14u) & 0xF5u; w_u32(a1, 0x80056288u); w_u8(a1 + 14u, (uint8)result); return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80065EF8 */
uint32 sub_80065EF8(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result;
    sub_80065EB0(a1, r_u32(0x800A9010u)); result = (uint32)(int32)(int8)r_u8(a1 + 13u);
    if ((int32)result < 0) {
        w_u16(a1 + 32u, r_u16(r_u32(0x800A62ECu) + 90u));
        w_u8(a1 + 13u, (uint8)((sub_80069A50() & 31u) + 20u)); result = 0x80065F68u; w_u32(a1, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80036CFC */
uint32 sub_80036CFC(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = (uint32)(int32)(int8)r_u8(a1);
    if ((int32)result >= 0) {
        SpuSetKey(0, 1u << (result & 31u)); draft_call_adapter(0x80035988u, (uint32)(int32)(int8)r_u8(a1));
        w_u32(0x800A7C84u + 16u * (uint32)(int32)(int8)r_u8(a1), 0x800A7DFCu); result = 0xFFFFFFFEu; w_u8(a1, 0xFEu);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80041604 */
uint32 sub_80041604(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 flags, temporary;
    if (r_u8(a1 + 12u) < 5u) flags = r_u8(a1 + 14u) & 0x7Du;
    else { temporary = draft_scratch_adapter(8u); w_u16(temporary, 0u); draft_call_adapter(0x800410E4u, a1, temporary); flags = r_u8(a1 + 14u) | 0x82u; }
    w_u8(a1 + 14u, (uint8)flags);
    if (r_u8(a1 + 12u) < 2u) { w_u32(0x800A5F18u, r_u32(0x800A5F18u) - 1u); return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(a1))); }
    if ((int16)r_u16(a1 + 444u) < 201) return draft_scratch_result(native_stack_mark, (uint64)(sub_80040F94(a1)));
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800214C8 */
uint32 sub_800214C8(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    w_u16(0x800A6722u, (uint16)(r_u16(0x800A6722u) ^ 0x100u)); draft_call_adapter(0x80080D84u, a2, 0x800A6720u);
    w_u32(a2, (r_u32(a2) & 0xFF000000u) | (r_u32(a1 + 800u) & 0xFFFFFFu));
    w_u32(a1 + 800u, (r_u32(a1 + 800u) & 0xFF000000u) | (a2 & 0xFFFFFFu)); return draft_scratch_result(native_stack_mark, (uint64)(a2 + 12u));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80071DC8 */
uint32 sub_80071DC8(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index, text;
    if (r_u32(0x800A6464u) == 1u || r_u32(0x800A6464u) == 5u) {
        index = r_u8(0x80092140u + a1); text = r_u32(0x8009218Cu + 4u * index); if (index == 4u) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    } else { index = r_u8(0x80092160u + a1); text = r_u32(0x80092180u + 4u * index); if (index == 3u) return draft_scratch_result(native_stack_mark, (uint64)(0u)); }
    return draft_scratch_result(native_stack_mark, (uint64)(sub_80071B4C(text)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80070A0C */
uint32 sub_80070A0C(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 address;
    if (a1 == 256u) return draft_scratch_result(native_stack_mark, (uint64)((int16)(uint32)draft_call_adapter(0x80037BB8u) == 2));
    if (a1 == 261u) return draft_scratch_result(native_stack_mark, (uint64)((int16)(uint32)draft_call_adapter(0x80037BB8u) != -1));
    if (a1 == 257u) address = 0x800A905Cu;
    else if (a1 == 258u) address = 0x800A905Eu;
    else if (a1 == 260u) address = 0x800A9068u;
    else if (a1 >= 262u && a1 <= 264u) address = 0x800A906Au + 2u * (a1 - 262u);
    else if (a1 >= 267u && a1 <= 276u) address = 0x800A9070u + 2u * (a1 - 267u);
    else return draft_scratch_result(native_stack_mark, (uint64)(1u));
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)(int32)(int16)r_u16(address)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800727B0 */
uint32 sub_800727B0(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 mode = 0u, count = 7u, table, destination, cursor, result;
    if ((int16)(uint32)draft_call_adapter(0x80037BB8u) == 2) { mode = 1u; count = 6u; }
    if (mode) table = r_u32(0x800921F8u + 4u * (uint32)(int32)(int16)r_u16(0x800A645Au));
    else table = r_u32(0x80092208u + 4u * (uint32)(int32)(int16)r_u16(0x800A6458u));
    destination = r_u32(0x800A5C90u) + 2u * count; cursor = table + count;
    do { --cursor; destination -= 2u; result = r_u16(0x8009219Cu + 2u * r_u8(cursor)); --count; w_u16(destination, (uint16)result); } while (count);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8005EB2C */
uint32 sub_8005EB2C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = (uint32)(int32)(int16)r_u16(0x800A997Cu), temporary, first, second, third;
    if (result) {
        temporary = draft_scratch_adapter(40u); w_u16(temporary + 4u, 4u); w_u16(temporary + 6u, 2u); w_u16(temporary, r_u16(0x800A9974u));
        w_u16(temporary + 2u, (uint16)(r_u16(0x800A9976u) + ((r_u32(0x800A562Cu) != 0u) << 8)));
        draft_call_adapter(0x80080294u, temporary, temporary + 8u);
        first = r_u16(temporary + 10u) & 0x7EFEu; third = r_u32(temporary + 16u) & 0x7EFEu; second = r_u32(temporary + 12u) & 0x7EFEu;
        result = 0x7EFEu;
        if (first == result && second == first) { result = 1u; if (third == second) { w_u16(0x800A997Eu, 1u); return draft_scratch_result(native_stack_mark, (uint64)(result)); } }
        w_u16(0x800A997Eu, 0u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80029D44 */
uint32 sub_80029D44(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index, cursor = a1, result;
    for (index = 0u; index < 3u; ++index) {
        int32 y0 = (int16)r_u16(cursor + 2u), y1 = (int16)r_u16(cursor + 10u);
        w_u16(cursor + 32u, (uint16)(((int16)r_u16(cursor + 8u) + (int16)r_u16(cursor)) >> 1));
        result = (uint32)(int32)(int16)r_u16(cursor + 12u); y1 += y0; y0 = (int16)r_u16(cursor + 4u);
        w_u16(cursor + 34u, (uint16)(y1 >> 1)); w_u16(cursor + 36u, (uint16)(((int32)result + y0) >> 1)); cursor += 8u;
    }
    {
        int32 y1 = (int16)r_u16(a1 + 26u), y0 = (int16)r_u16(a1 + 2u), z0, z1;
        w_u16(a1 + 56u, (uint16)(((int16)r_u16(a1) + (int16)r_u16(a1 + 24u)) >> 1));
        z0 = (int16)r_u16(a1 + 4u); y0 += y1; z1 = (int16)r_u16(a1 + 28u);
        w_u16(a1 + 58u, (uint16)(y0 >> 1)); result = (uint32)((z0 + z1) >> 1); w_u16(a1 + 60u, (uint16)result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80065DD0 */
uint32 sub_80065DD0(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = r_u8(a1 + 12u) < 4u, remaining, particle;
    if (!result) {
        result = r_u32(0x800A9010u); remaining = r_u32(a1 + 8u) - result;
        if ((int32)remaining < 0) {
            particle = (uint32)draft_call_adapter(0x800227C4u, 40u); w_u8(particle + 14u, (uint8)(r_u8(particle + 14u) | 2u));
            w_u16(particle + 32u, r_u16(r_u32(0x800A62ECu) + 88u));
            { uint32 x = r_u32(a1 + 20u), y = r_u32(a1 + 24u), z = r_u32(a1 + 28u); w_u32(particle + 20u, x); w_u32(particle + 24u, y); w_u32(particle + 28u, z); }
            w_u16(particle + 36u, 140u); w_u32(particle, 0x80065EF8u); w_u8(particle + 13u, (uint8)((sub_80069A50() & 31u) + 20u));
            w_u32(particle + 16u, (sub_80069A50() & 127u) - 63u); remaining = 15u; result = 11u; w_u8(particle + 34u, 11u);
        }
        w_u32(a1 + 8u, remaining);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800494F4 */
uint32 sub_800494F4(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 displacement = r_u8(a1 + 197u) == 22u ? 0u : 160u * r_u32(0x800A6224u), record, angle, result, cosine, sine;
    record = sub_800476D8((uint32)(int32)(int16)a2); angle = r_u16(a1 + 180u) & 0xFFFu;
    cosine = (uint32)(int32)(int16)r_u16(0x80010AE0u + 2u * angle); sine = (uint32)(int32)(int16)r_u16(0x800102E0u + 2u * angle);
    w_u32(a1 + 92u, ((r_u32(record) & 0x3FFu) << 9) + (uint32)((int32)(displacement * cosine - 466u * sine) >> 12));
    record = sub_800476D8((uint32)(int32)(int16)a2); angle = r_u16(a1 + 180u) & 0xFFFu; result = 466u * (uint32)(int32)(int16)r_u16(0x80010AE0u + 2u * angle);
    w_u32(a1 + 96u, (((r_u32(record) >> 10) & 0x3FFu) << 9) + (uint32)((int32)((0u - displacement) * (uint32)(int32)(int16)r_u16(0x800102E0u + 2u * angle) - result) >> 12)); return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8004D04C */
uint32 sub_8004D04C(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    if (sub_80045E18(a1, a1 + 72u)) return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    if (sub_80045DD4(a1)) {
        if (r_u8(a1 + 67u) && r_u32(r_u32(0x800A851Cu) + 4u * (uint32)(int32)(int16)r_u16(0x800A9730u)) == a1) draft_call_adapter(0x8004525Cu);
        w_u32(a1 + 140u, 0u); return draft_scratch_result(native_stack_mark, (uint64)(1u));
    }
    if ((int16)r_u16(r_u32(r_u32(0x800A851Cu) + 4u * (uint32)(int32)(int16)r_u16(a1 + 164u)) + 58u) <= 0 || r_u8(a1 + 198u) == 11u) {
        w_u8(a1 + 198u, 8u); if (draft_call_adapter(0x80045EB0u, a1)) { w_u32(a1 + 140u, 0u); return draft_scratch_result(native_stack_mark, (uint64)(1u)); }
    }
    if (r_u8(a1 + 67u) && !r_u32(0x800A9760u)) {
        if (r_u16(a1 + 70u) == 1u) draft_call_adapter(0x800451B4u, a1 + 20u, (uint32)(int32)(int16)r_u16(a1 + 68u));
        else sub_8004510C(a1 + 20u, (uint32)(int32)(int16)r_u16(a1 + 68u));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80029DDC */
uint32 sub_80029DDC(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(12u), component;
    draft_call_adapter(0x80029EECu, a1, r_u32(0x800A90ACu) + 40u * (uint32)(int32)(int16)a3, a2); sub_80029D44(a2);
    for (component = 0u; component < 3u; ++component) xport_gte_write_control(2u * component, (uint32)((int16)r_u16(a2 + 8u + 2u * component) - (int16)r_u16(a2 + 2u * component)));
    xport_gte_write_data(11u, (uint32)((int16)r_u16(a2 + 20u) - (int16)r_u16(a2 + 4u)));
    xport_gte_write_data(9u, (uint32)((int16)r_u16(a2 + 16u) - (int16)r_u16(a2)));
    xport_gte_write_data(10u, (uint32)((int16)r_u16(a2 + 18u) - (int16)r_u16(a2 + 2u)));
    draft_gte_command_adapter(0x170000Cu);
    w_u32(temporary, xport_gte_read_data(25u)); w_u32(temporary + 4u, xport_gte_read_data(26u)); w_u32(temporary + 8u, xport_gte_read_data(27u));
    /* TODO: Original return points to a temporary whose guest stack lifetime ends here */
    return draft_scratch_result(native_stack_mark, (uint64)(temporary));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800576B0 */
uint32 sub_800576B0(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 count = r_u32(0x800A7098u), cursor = r_u32(0x800A70A0u), total = r_u32(0x800A63E4u);
    if (cursor < total) {
        uint32 budget = 0u, output = 0x800A7018u + 2u * count, record = r_u32(0x800A84FCu) + 8u * cursor;
        do {
            uint32 x = r_u32(record) & 0x3FFu, visibility;
            if (x && !(r_u32(record + 4u) & 0x400u)) {
                uint32 grid_x = (x >> 3) - r_u32(0x800A5640u), grid_z = ((((r_u32(record) >> 10) & 0x3FFu) << 9) >> 12) - r_u32(0x800A5644u);
                visibility = grid_x >= 14u || grid_z >= 14u ? 0u : r_u8(0x8008B794u + 14u * grid_z + grid_x) + 1u;
                if (visibility == 1u) { w_u16(output, (uint16)cursor); ++count; output += 2u; if (count == 64u) { w_u32(0x800A70A0u, total); goto finish; } }
            }
            if (budget == 16u) break;
            record += 8u; ++cursor; ++budget;
        } while (cursor < total);
        w_u32(0x800A70A0u, cursor);
    }
finish:
    w_u32(0x800A7098u, count); return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A70A0u) == r_u32(0x800A63E4u)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8006FB78 */
uint32 sub_8006FB78(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 mode = r_u32(0x800A645Cu), result = r_u32(0x80091EDCu + 12u * mode), remaining, offset;
    if (result) result = (uint32)draft_call_adapter(result);
    remaining = r_u32(0x800A75C4u); offset = 4u * remaining;
    while ((int32)remaining > 0) {
        uint32 table, callback;
        offset -= 4u; --remaining; table = r_u32(0x80091EE0u + 12u * r_u32(0x800A645Cu));
        if (sub_80070A0C(r_u32(table + 4u * offset))) { callback = r_u32(r_u32(0x80091EE0u + 12u * r_u32(0x800A645Cu)) + 4u * (offset + 1u)); if (callback) draft_call_adapter(callback, remaining); }
        result = r_u32(0x800A6460u);
        if (remaining == result) { result = r_u32(r_u32(0x80091EE0u + 12u * r_u32(0x800A645Cu)) + 4u * (offset + 2u)); if (result) result = (uint32)draft_call_adapter(result, remaining); }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8006F338 */
uint32 sub_8006F338(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    const uint32 masks[10] = {4096u,0xFFFF8000u,8192u,16384u,4u,1u,8u,2u,32u,128u};
    uint32 bits = 0u, i;
    for (i = 0u; i < 10u; ++i) bits |= (uint32)(int32)(int16)sub_80038970(masks[i]);
    for (i = 0u; i < 20u; ++i) {
        uint32 progress = 0x800A7568u + 2u * i, completed = 0x800A905Cu + 2u * i, sequence = r_u32(0x80091728u + 4u * i);
        if (r_u16(completed) == 1u) continue;
        if (bits & (uint32)(int32)(int16)r_u16(sequence + 2u * (uint32)(int32)(int16)r_u16(progress))) {
            w_u16(progress, (uint16)(r_u16(progress) + 1u)); w_u16(0x800A7590u + 2u * i, 300u);
            if (!r_u16(sequence + 2u * (uint32)(int32)(int16)r_u16(progress))) { w_u16(completed, 1u); draft_call_adapter(0x80035A08u, 47u, 2048u, 255u, 0u); }
        } else if (r_u16(progress) && bits) w_u16(progress, 0u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(80u));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8002DA84 */
uint32 sub_8002DA84(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 count = r_u32(0x800A576Cu), first = r_u32(0x800A5764u), second, outer, inner;
    if ((int32)count < 2 || first == count - 1u) return draft_scratch_result(native_stack_mark, (uint64)(1u));
    second = r_u32(0x800A5768u); outer = 0x800B3480u + 20u * first; inner = 0x800B3480u + 20u * second;
    if (r_u8(outer + 17u) || r_u8(inner + 17u)) {
        uint32 object = r_u32(outer), other = r_u32(inner), dx = r_u32(object + 20u) - r_u32(other + 20u), dz = r_u32(object + 28u) - r_u32(other + 28u);
        if ((int32)dx < 0) dx = 0u - dx; if ((int32)dz < 0) dz = 0u - dz;
        if ((int32)dx < 2048 && (int32)dz < 2048) {
            uint32 offset = 8u * (11u * r_u8(outer + 16u) + r_u8(inner + 16u)), mode = r_u8(0x800A57A8u + offset);
            if (mode == 1u) draft_call_adapter(r_u32(0x800A57ACu + offset), r_u32(inner), r_u32(0x800A5768u), r_u32(outer), r_u32(0x800A5764u));
            else if (mode) draft_call_adapter(r_u32(0x800A57ACu + offset), r_u32(outer), r_u32(0x800A5764u), other, r_u32(0x800A5768u));
        }
    }
    second = r_u32(0x800A5768u) + 1u; w_u32(0x800A5768u, second);
    if (second == r_u32(0x800A576Cu)) { first = r_u32(0x800A5764u); w_u32(0x800A5764u, first + 1u); w_u32(0x800A5768u, first + 2u); }
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A5764u) == r_u32(0x800A576Cu) - 1u));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8006E06C */
uint32 sub_8006E06C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 slot = 0u, point, cell, first, count, index, list, temporary;
    while (slot < 8u && !r_u32(0x800A74F8u + 12u * slot)) ++slot;
    if (slot == 8u) return draft_scratch_result(native_stack_mark, (uint64)(1u));
    point = 0x800A74F8u + 12u * slot; cell = (uint32)((int32)r_u32(point) >> 12) + 80u * (uint32)((int32)r_u32(point + 8u) >> 12);
    first = r_u16(r_u32(0x800A84F8u) + 8u * cell);
    if (first) {
        count = r_u16(r_u32(0x800A7E24u) + 2u * (first - 1u)); list = 2u * first;
        for (index = 0u; index < count; ++index, list += 2u) {
            uint32 record = r_u16(r_u32(0x800A7E24u) + list), type, offset = 0u;
            if (record == 0x7FFFu) continue;
            type = r_u16(r_u32(0x800A7BFCu) + 8u * record);
            while (r_u16(r_u32(0x800A8520u) + offset) != 0xFFFFu) {
                uint32 candidate = r_u16(r_u32(0x800A8520u) + offset); offset += 2u;
                if (candidate == type) {
                    uint32 data = r_u32(0x800A7BFCu) + 8u * record;
                    temporary = draft_scratch_adapter(24u); w_u32(temporary, (r_u32(point) & 0xFFFFF000u) + (r_u16(data + 2u) & 0xFFFu));
                    w_u32(temporary + 8u, (r_u32(point + 8u) & 0xFFFFF000u) + (r_u16(data + 4u) & 0xFFFu)); w_u32(temporary + 4u, 0u - r_u16(data + 6u));
                    if (draft_call_adapter(0x8006DFF8u, point, temporary)) {
                        draft_call_adapter(0x80060078u, temporary, (cell << 16) | index);
                        w_u16(r_u32(0x800A7E24u) + list, (uint16)(r_u16(r_u32(0x800A7E24u) + list) | 0x7FFFu));
                    }
                }
            }
        }
    }
    w_u32(point, 0u); return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80061E1C */
uint32 sub_80061E1C(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(88u), distance, particle, angle, height;
    w_u32(temporary + 48u, r_u32(0x800A635Cu)); w_u32(temporary + 52u, r_u32(0x800A6360u)); w_u16(temporary + 12u, 0u);
    sub_80061D90(a1, a2, temporary);
    distance = (uint32)draft_call_adapter(0x80069BE0u, (uint32)(int32)(int16)r_u16(temporary), (uint32)(int32)(int16)r_u16(temporary + 4u));
    while ((int32)distance >= 201) {
        particle = (uint32)draft_call_adapter(0x80061CE4u, a3, a4, a5); distance -= 200u;
        angle = sub_80055A9C((uint32)(int32)(int16)r_u16(temporary), (uint32)(int32)(int16)r_u16(temporary + 4u)); w_u16(temporary + 10u, (uint16)angle);
        draft_call_adapter(0x800551CCu, (uint32)(int32)(int16)angle, temporary + 16u);
        w_u32(temporary + 56u, r_u32(a1)); w_u32(temporary + 60u, r_u32(a1 + 4u)); w_u32(temporary + 64u, r_u32(a1 + 8u));
        draft_call_adapter(0x80031CE8u, temporary + 16u, temporary + 56u, temporary + 48u, a1);
        height = 0u - (uint32)draft_call_adapter(0x8002E310u, a1, temporary + 72u, temporary + 80u); w_u32(a1 + 4u, height);
        angle = sub_80055A9C(height - r_u32(temporary + 60u), 200u); w_u16(temporary + 8u, (uint16)angle);
        draft_call_adapter(0x80055288u, temporary + 8u, particle + 36u); particle += 20u;
        sub_80061DD0(temporary + 56u, a1, particle); draft_call_adapter(0x80061834u, temporary + 56u, particle, a5);
    }
    return draft_scratch_result(native_stack_mark, (uint64)((int32)distance < 201));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80049AC0 */
uint32 sub_80049AC0(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object = r_u32(a1), temporary, model, pass;
    if (r_u8(object + 197u) == 22u) {
        if (sub_8002EAE4(object + 20u, a1 + 12u, 0u) << 16) return draft_scratch_result(native_stack_mark, (uint64)(2u * (sub_800498D4(r_u32(a1), (uint32)(int32)(int16)a2) == 0u)));
        return draft_scratch_result(native_stack_mark, (uint64)(1u));
    }
    temporary = draft_scratch_adapter(24u);
    for (pass = 0u; pass < 2u; ++pass) {
        uint32 x, y, z;
        model = r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(r_u32(a1) + 32u));
        if (!pass) w_u16(temporary + 16u, (uint16)((int16)(19u * (r_u16(model) + r_u16(model + 24u))) / 40));
        else w_u16(temporary + 16u, (uint16)((int16)(19u * (r_u16(model + 8u) + r_u16(model + 16u))) / 40));
        model = r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(r_u32(a1) + 32u));
        if (!pass) w_u16(temporary + 20u, (uint16)((int16)(19u * (r_u16(model + 4u) + r_u16(model + 28u))) / 40));
        else w_u16(temporary + 20u, (uint16)((int16)(19u * (r_u16(model + 12u) + r_u16(model + 20u))) / 40));
        object = r_u32(a1); x = r_u32(object + 20u); y = r_u32(object + 24u); z = r_u32(object + 28u);
        w_u32(temporary, x); w_u32(temporary + 4u, y); w_u32(temporary + 8u, z); sub_80031DC8(r_u32(a1) + 36u, temporary, temporary + 16u);
        if (!(sub_8002EAE4(temporary, a1 + 12u, 0u) << 16)) return draft_scratch_result(native_stack_mark, (uint64)(1u));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(2u * (sub_800498D4(r_u32(a1), (uint32)(int32)(int16)a2) == 0u)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800442FC */
uint32 sub_800442FC(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = sub_80077AC0(a4, 1u, 1u, 287u), cursor = 0u;
    int32 origin_x = (int16)a5, y = (int16)a6, x = origin_x - 144, line_x = x;
    for (;;) {
        uint32 ch = r_u8(0x800BC4FCu + cursor), glyph = ch;
        if (!ch) { ++cursor; return draft_scratch_result(native_stack_mark, (uint64)(result)); }
        if (ch == 1u) { ++cursor; result = r_u8(0x800BC4FCu + cursor); x = (int32)result + origin_x - 160; line_x = x; }
        else if (ch == 2u) { result = 3u; x = origin_x - 144; line_x = x; }
        else if (ch == 3u) { ++cursor; result = r_u8(0x800BC4FCu + cursor); x = origin_x + 144 - (int32)result; line_x = x; }
        else if (ch == 32u) { result = r_u8(a2 + 162u); x = (int32)((uint32)x + result); }
        else if (ch == 10u) { result = 10u; x = line_x; y += 13; }
        else {
            if (a1 == 1u && ch >= 48u) glyph -= 48u;
            draft_call_adapter(0x8004328Cu, a2, 0x54000040u, glyph, a3, (uint32)x, (uint32)y, a7);
            ch = r_u8(r_u32(0x800A5F68u) + 5u * glyph + 4u);
            if (ch != 1u && ch != 6u) draft_call_adapter(0x8004328Cu, a2, 0x64000040u, glyph, a3, (uint32)x + 1u, (uint32)y + 1u, a7 + 10u);
            result = r_u8(a2 + 5u * glyph + 2u); x = (int32)((uint32)x + result);
        }
        ++cursor;
    }

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_800570DC */
uint32 sub_800570DC(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 source = 8u * a1, destination, next, object, model, angle, lane, record, temporary, value, cosine, sine;
    if (r_u32(r_u32(0x800A84FCu) + source + 4u) & 0x100u) return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    next = sub_80069F84(a1); if ((int32)next < 0) return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    destination = 8u * next;
    record = r_u32(0x800A7E2Cu) + 4u * ((uint32)((int32)r_u32(r_u32(0x800A84FCu) + destination + 4u) >> 11) + sub_80069EFC(a1, next));
    if ((r_u32(record) & 0xFFFFF000u) != 0xFFFFF000u) return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    object = (uint32)draft_call_adapter(0x800226E4u, 96u); w_u8(object + 34u, 8u); model = r_u16(r_u32(0x800A62ECu) + 2u * a2);
    w_u32(object, 0x80056AA8u); w_u8(object + 14u, (uint8)(r_u8(object + 14u) | 2u)); w_u8(object + 13u, 2u); w_u8(object + 9u, 0u); w_u8(object + 14u, (uint8)(r_u8(object + 14u) | 8u));
    w_u32(object + 16u, 0x80090B6Cu); w_u32(object + 84u, 0u); w_u16(object + 10u, 0u); w_u16(object + 32u, (uint16)model);
    record = r_u32(0x800A84FCu);
    angle = sub_80055A9C((r_u32(record + destination) & 0x3FFu) - (r_u32(record + source) & 0x3FFu), ((r_u32(record + destination) >> 10) & 0x3FFu) - ((r_u32(record + source) >> 10) & 0x3FFu)) & 0xFFFu;
    w_u16(object + 76u, (uint16)angle); w_u16(object + 78u, (uint16)angle);
    lane = 608u * r_u32(0x800A6224u); cosine = (uint32)(int32)(int16)r_u16(0x80010AE0u + 2u * angle); sine = (uint32)(int32)(int16)r_u16(0x800102E0u + 2u * angle);
    record = r_u32(0x800A84FCu) + source; w_u32(object + 68u, ((r_u32(record) & 0x3FFu) << 9) + (uint32)((int32)(952u * sine + lane * cosine) >> 12));
    angle = r_u16(object + 76u) & 0xFFFu; cosine = (uint32)(int32)(int16)r_u16(0x80010AE0u + 2u * angle); sine = (uint32)(int32)(int16)r_u16(0x800102E0u + 2u * angle);
    w_u32(object + 72u, (((r_u32(record) >> 10) & 0x3FFu) << 9) + (uint32)((int32)(952u * cosine - lane * sine) >> 12)); value = (r_u32(record) >> 12) & 0xFF00u;
    w_u32(object + 20u, r_u32(object + 68u)); w_u32(object + 24u, 0u - value); w_u32(object + 28u, r_u32(object + 72u));
    temporary = draft_scratch_adapter(16u); value = (uint32)draft_call_adapter(0x8002E310u, object + 20u, temporary, temporary + 8u);
    model = r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(object + 32u));
    w_u32(object + 24u, 0u - value - (uint32)((int32)((uint32)r_u16(model + 32u) << 16) >> 17));
    sub_8005603C(object, next); w_u8(object + 89u, (uint8)sub_80069EFC(a1, next));
    record = r_u32(0x800A7E2Cu) + 4u * ((uint32)((int32)r_u32(r_u32(0x800A84FCu) + destination + 4u) >> 11) + r_u8(object + 89u));
    w_u32(record, (r_u32(record) & 0xFFFu) | ((object - r_u32(0x800A8738u)) << 12)); w_u16(object + 64u, (uint16)next); w_u16(object + 66u, (uint16)sub_8006A0A0(next, a1));
    w_u8(object + 89u, (uint8)sub_80069EFC(r_u16(object + 64u), r_u16(object + 66u))); w_u16(object + 90u, 1u);
    draft_call_adapter(0x80054D38u, 0u, (uint32)(int32)(int16)r_u16(object + 78u) + 2048u, 0u, object + 36u);
    value = (uint32)draft_call_adapter(0x80069BE0u, r_u32(object + 68u) - r_u32(object + 20u), r_u32(object + 72u) - r_u32(object + 28u)); w_u32(object + 80u, value - 1000u);
    w_u16(object + 56u, 1u); w_u8(object + 8u, 255u); w_u16(object + 58u, 256u); w_u32(object + 60u, 0u);
    if (a2 == 6u) { value = 5u * r_u32(0x800A63DCu) + 1u; w_u32(0x800A63DCu, value); if (!(value & 3u)) return draft_scratch_result(native_stack_mark, (uint64)(0u)); w_u8(object + 9u, 1u); }
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80056AA8 */
uint32 sub_80056AA8(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 state = r_u8(a1 + 90u), node, record, other, distance, result, seed;
    w_u8(a1 + 91u, (uint8)(r_u8(a1 + 91u) & 0x80u));
    switch (state) {
    case 3u:
        draft_call_adapter(0x8005612Cu, a1, r_u16(a1 + 64u), r_u16(a1 + 66u));
        w_u32(a1 + 80u, (uint32)draft_call_adapter(0x80069BE0u, r_u32(a1 + 68u) - r_u32(a1 + 20u), r_u32(a1 + 72u) - r_u32(a1 + 28u)));
        record = r_u32(0x800A7E2Cu) + 4u * ((uint32)((int32)r_u32(r_u32(0x800A84FCu) + 8u * r_u16(a1 + 64u) + 4u) >> 11) + r_u8(a1 + 88u));
        if ((r_u32(record) >> 12) + r_u32(0x800A8738u) == a1) w_u32(record, r_u32(record) | 0xFFFFF000u);
        w_u8(a1 + 90u, 2u); break;
    case 4u:
        node = r_u32(r_u32(0x800A84FCu) + 8u * r_u16(a1 + 64u) + 4u);
        if ((node & 0x300u) && (node & 15u) >= 3u) w_u8(a1 + 91u, (uint8)(r_u8(a1 + 91u) | 1u));
        else {
            w_u8(a1 + 88u, r_u8(a1 + 89u)); w_u8(a1 + 89u, (uint8)sub_80069EFC(r_u16(a1 + 64u), r_u16(a1 + 66u)));
            record = r_u32(0x800A7E2Cu) + 4u * ((uint32)((int32)r_u32(r_u32(0x800A84FCu) + 8u * r_u16(a1 + 66u) + 4u) >> 11) + r_u8(a1 + 89u));
            other = r_u32(record) >> 12; w_u32(a1 + 84u, other == 0xFFFFFu || other + r_u32(0x800A8738u) == a1 ? 0u : other + r_u32(0x800A8738u));
            record = r_u32(0x800A7E2Cu) + 4u * ((uint32)((int32)r_u32(r_u32(0x800A84FCu) + 8u * r_u16(a1 + 66u) + 4u) >> 11) + r_u8(a1 + 89u));
            w_u32(record, (r_u32(record) & 0xFFFu) | ((a1 - r_u32(0x800A8738u)) << 12)); node = r_u32(0x800A84FCu) + 8u * r_u16(a1 + 64u); w_u32(node + 4u, r_u32(node + 4u) | 0x100u);
            w_u32(a1 + 80u, (uint32)draft_call_adapter(0x80069BE0u, r_u32(a1 + 68u) - r_u32(a1 + 20u), r_u32(a1 + 72u) - r_u32(a1 + 28u))); w_u16(a1 + 90u, 6u);
        }
        break;
    case 5u:
        sub_8005603C(a1, r_u16(a1 + 66u)); node = r_u32(0x800A84FCu) + 8u * r_u16(a1 + 64u); w_u32(node + 4u, r_u32(node + 4u) & ~0x100u);
        node = r_u16(a1 + 64u); w_u16(a1 + 64u, r_u16(a1 + 66u)); w_u16(a1 + 66u, (uint16)sub_8006A0A0(r_u16(a1 + 64u), node));
        w_u32(a1 + 80u, (uint32)draft_call_adapter(0x80069BE0u, r_u32(a1 + 68u) - r_u32(a1 + 20u), r_u32(a1 + 72u) - r_u32(a1 + 28u)) - 1000u); w_u8(a1 + 90u, 1u); break;
    case 7u: case 8u:
        if (r_u8(a1 + 12u) >= 4u) {
            node = r_u32(0x800A8548u) + r_u16(a1 + 32u); w_u32(a1 + 80u, r_u32(a1 + 80u) - r_u32(0x800A9010u));
            draft_call_adapter(0x80029970u, a1, r_u16(r_u32(0x800A90ACu) + 40u * r_u8(node) + 32u), 1u, 1u, a1 + 20u);
        }
        if (r_u8(a1 + 12u)) { result = r_u32(a1 + 80u); if ((int32)result > 0) return draft_scratch_result(native_stack_mark, (uint64)(result)); }
        return draft_scratch_result(native_stack_mark, (uint64)(sub_80056364(a1)));
    default: break;
    }
    if (!(r_u8(r_u32(a1 + 84u) + 14u) & 2u)) w_u32(a1 + 84u, 0u);
    other = r_u32(a1 + 84u);
    if (other) {
        uint32 dx = r_u32(other + 20u) - r_u32(a1 + 20u), dz = r_u32(other + 28u) - r_u32(a1 + 28u), abs_x = (int32)dx < 0 ? 0u - dx : dx, abs_z = (int32)dz < 0 ? 0u - dz : dz;
        int32 radius = (int16)r_u16(r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(other + 32u)) + 34u);
        radius += (int16)r_u16(r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u)) + 34u); distance = (int32)abs_x < (int32)abs_z ? abs_z : abs_x;
        if ((radius >> 1) + 500 >= (int32)distance) {
            uint32 difference = (r_u16(other + 78u) - r_u16(a1 + 78u)) & 0xFFFu, bearing = (sub_80055A9C(dx, dz) - r_u16(a1 + 78u)) & 0xFFFu;
            int32 signed_difference, signed_bearing;
            if (difference >= 2049u) difference |= 0xF000u; if (bearing >= 2049u) bearing |= 0xF000u;
            signed_difference = (int16)difference; signed_bearing = (int16)bearing; if (signed_difference < 0) signed_difference = -signed_difference; if (signed_bearing < 0) signed_bearing = -signed_bearing;
            if (signed_difference < 1024 && signed_bearing < 1024) w_u8(a1 + 91u, (uint8)(r_u8(a1 + 91u) | 1u));
            seed = 5u * r_u32(0x800A63DCu) + 1u; w_u32(0x800A63DCu, seed); w_u16(a1 + 92u, (uint16)(seed % 80u));
        }
    }
    sub_800563AC(a1);
    if ((int32)r_u32(a1 + 80u) < 49) { state = r_u8(0x8001376Cu + r_u8(a1 + 90u)); w_u8(a1 + 91u, (uint8)(r_u8(a1 + 91u) & ~0x80u)); w_u8(a1 + 90u, (uint8)state); }
    if ((r_u8(a1 + 91u) & 1u) && r_u16(a1 + 92u)) {
        uint32 timer = (uint32)(int32)(int16)r_u16(a1 + 92u) - 1u; w_u16(a1 + 92u, (uint16)timer);
        if (!(timer << 16)) {
            seed = 5u * r_u32(0x800A63DCu) + 1u; w_u32(0x800A63DCu, seed); draft_call_adapter(0x80035A08u, 60u, (seed & 127u) | 1024u, 0u, a1 + 20u);
            seed = 5u * r_u32(0x800A63DCu) + 1u; w_u32(0x800A63DCu, seed); w_u16(a1 + 92u, (uint16)(seed % 80u));
        }
    }
    result = r_u8(a1 + 12u); return draft_scratch_result(native_stack_mark, (uint64)(result ? result : sub_80056364(a1)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8004CAD4 */
uint32 sub_8004CAD4(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(12u), collision, distance, force = 0u, excluded = 0u, i, model;
    int32 tilt, roll;
    sub_80029DDC(a1, 0x800A6EF8u, r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u)));
    { uint32 x = r_u32(a3), y = r_u32(a3 + 4u), z = r_u32(a3 + 8u); w_u32(temporary, x); w_u32(temporary + 4u, y); w_u32(temporary + 8u, z); }
    collision = (uint32)(int32)(int16)sub_80030040(0x800A6F38u, temporary, a1 + 20u, 0x800A6EF8u);
    if (collision) {
        if (!r_u8(a1 + 88u)) {
            uint32 x = r_u32(a1 + 128u), y = r_u32(a1 + 132u), z = r_u32(a1 + 136u);
            w_u32(a1 + 20u, x); w_u32(a1 + 24u, y); w_u32(a1 + 28u, z); draft_call_adapter(0x8004C8A8u, a1);
        }
        distance = (uint32)draft_call_adapter(0x80069BE0u, r_u32(a2), r_u32(a2 + 8u));
        { uint32 x = r_u32(a2) << 8; w_u32(a2 + 8u, r_u32(a2 + 8u) << 8); w_u32(a2, x); }
        distance <<= 8;
        draft_call_adapter(0x80023918u, r_u32(0x800A6F38u + 12u * (collision - 1u)), r_u32(0x800A6F40u + 12u * (collision - 1u)), a2, a2 + 8u);
        if ((int32)distance > 655360) draft_call_adapter(0x80023228u, a1 + 20u, 0x800A6F38u, 0x800A6EF8u, 1u, distance);
        { uint32 z = (uint32)((int32)r_u32(a2 + 8u) >> 8); w_u32(a2, (uint32)((int32)r_u32(a2) >> 8)); w_u32(a2 + 8u, z); }
        w_u8(a1 + 88u, r_u8(0x800A6F98u));
    } else w_u8(a1 + 88u, 0u);
    sub_8002FC90(a1, 0x800A6F38u, 0x800A6EF8u, 0u);
    if ((sub_80025874(6u, 0x800A6F38u, 0u) << 16) && !(r_u32(a1 + 208u) & 0xF0000u) && !(r_u32(a1 + 224u) & 0xF0000u) && !(r_u32(a1 + 240u) & 0xF0000u) && !(r_u32(a1 + 256u) & 0xF0000u)) { draft_call_adapter(0x8004BBBCu, a1, 2u); return draft_scratch_result(native_stack_mark, (uint64)(0u)); }
    sub_800283D4(a1, a4, 0x800A6F38u); w_u16(0x800A6EF8u, 0u); w_u16(0x800A6EFAu, 0u); w_u16(0x800A6EFCu, 0u); w_u16(0x800A6EFEu, 0u);
    distance = 92u * (uint32)draft_call_adapter(0x80069BE0u, r_u32(a2), r_u32(a2 + 8u)); if ((int32)distance > 1560000) distance = 1560000;
    sub_800287B4(a1, a4, distance, 0x800A6EF8u);
    model = r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u));
    tilt = (int32)sub_80055A9C((uint32)(((int16)r_u16(0x800A6EFEu) + (int16)r_u16(0x800A6EFCu) - ((int16)r_u16(0x800A6EF8u) + (int16)r_u16(0x800A6EFAu))) >> 1), (uint32)(int32)(int16)r_u16(model + 34u)) - (int16)r_u16(a1 + 186u);
    model = r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u));
    roll = (int32)sub_80055A9C((uint32)(((int16)r_u16(0x800A6EFCu) + (int16)r_u16(0x800A6EFAu) - ((int16)r_u16(0x800A6EFEu) + (int16)r_u16(0x800A6EF8u))) >> 1), (uint32)(int32)(int16)r_u16(model + 36u));
    draft_call_adapter(0x80054D38u, (uint32)tilt, (uint32)(int32)(int16)r_u16(a1 + 182u) + 2048u, (uint32)(int32)(int16)r_u16(a1 + 184u) + (uint32)roll, a1 + 36u);
    if (r_u8(a1 + 89u)) {
        force = 3u;
        for (i = 0u; i < 2u; ++i) { w_u8(0x800A6EF8u + i, r_u8(a1 + 90u)); excluded |= (r_u16(a1 + 210u + 16u * i) & 15u) << i; }
    } else {
        int32 sine;
        uint32 bearing = sub_80055A9C(r_u32(a1 + 100u), r_u32(a1 + 104u));
        sine = (int16)r_u16(0x800102E0u + 2u * ((r_u16(a1 + 182u) - bearing) & 0xFFFu));
        if (sine < 0) { bearing = sub_80055A9C(r_u32(a1 + 100u), r_u32(a1 + 104u)); sine = -(int16)r_u16(0x800102E0u + 2u * ((r_u16(a1 + 182u) - bearing) & 0xFFFu)); }
        if (sine >= 2101 || r_u8(a1 + 89u) || r_u8(a1 + 199u)) force = 3u;
        for (i = 0u; i < 2u; ++i) { w_u8(0x800A6EF8u + i, r_u8(0x800A6F40u + i)); excluded |= (r_u16(a1 + 210u + 16u * i) & 15u) << i; }
    }
    if (r_u8(a1 + 197u) == 7u) force = 0u;
    else sub_80061A78(a1, a1 + 272u, 0x800A6EF8u, force, excluded, 2u);
    return draft_scratch_result(native_stack_mark, (uint64)(excluded ? 0u : force & 1u));

    draft_scratch_release(native_stack_mark);
}

static uint32 draft_round1_text_line(uint32 output, uint32 length, uint32 alignment, uint32 position, uint32 style, uint32 explicit_newline)
{
    uint32 line = r_u32(0x800A7BE4u), width = r_u32(0x800A9A5Cu), i;
    if (alignment == 1u) {
        int32 centered = (int32)(320u - width) / 2;
        w_u8(output++, 1u); w_u8(output++, (uint8)centered);
        if (style == 287u) w_u16(0x800A7A90u + 2u * line, (uint16)centered);
    }
    if (alignment == 2u) { w_u8(output++, 2u); if (style == 287u) w_u16(0x800A7A90u + 2u * line, (uint16)-104); }
    if (alignment == 3u) {
        w_u8(output++, 3u); w_u8(output++, (uint8)(width + (explicit_newline ? 0u : 1u)));
        if (style == 287u) w_u16(0x800A7A90u + 2u * line, (uint16)(304u - width));
    }
    if (alignment == 4u) { w_u8(output++, 4u); w_u8(output++, (uint8)position); if (style == 287u) w_u16(0x800A7A90u + 2u * line, (uint16)width); }
    if (style == 287u) { w_u16(0x800A7A70u + 2u * line, (uint16)(width + 1u)); if ((int32)r_u32(0x800A8664u) < (int32)width) w_u32(0x800A8664u, width); }
    for (i = 0u; i < length; ++i) w_u8(output++, r_u8(0x800A9CF4u + i));
    return output;
}

/* FUNCTION_MARKER: sub_80077AC0 */
uint32 sub_80077AC0(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 output = 0x800BC4FCu, length = 0u, lines = 0u, position = 0u;
    (void)a2; a3 &= 255u;
    w_u32(0x800A7BE4u, 0u); w_u32(0x800A9A5Cu, 0u); w_u32(0x800A8664u, 0u);
    while (r_u8(a1)) {
        uint32 ch = r_u8(a1), consumed;
        if (ch == 32u || ch == 160u) {
            w_u8(0x800A9CF4u + length++, 32u); w_u32(0x800A9A5Cu, r_u32(0x800A9A5Cu) + r_u8(r_u32(0x800A5F68u) + 162u)); ++a1; continue;
        }
        if (ch == 92u) {
            uint32 command = r_u8(a1 + 1u);
            if (command == 'C' || command == 'c') { a3 = 1u; a1 += 2u; }
            else if (command == 'L' || command == 'l') { a3 = 2u; a1 += 2u; }
            else if (command == 'R' || command == 'r') { a3 = 3u; a1 += 2u; }
            else if (command == 'P' || command == 'p') { a3 = 4u; position = r_u8(a1 + 2u); a1 += 3u; }
            /* Original unsupported escape leaves the input cursor unchanged */
            continue;
        }
        if (ch == 13u) { ++a1; continue; }
        if (ch == 10u) {
            w_u8(0x800A9CF4u + length, 10u); ++lines; output = draft_round1_text_line(output, length + 1u, a3, position, a4, 1u);
            length = 0u; ++a1; w_u32(0x800A9A5Cu, 0u); w_u32(0x800A7BE4u, r_u32(0x800A7BE4u) + 1u); continue;
        }
        consumed = (uint32)(int32)(int16)(uint32)draft_call_adapter(0x80077A20u, a1, a4); a1 += consumed;
        if (consumed) {
            uint32 i; for (i = 0u; (int32)i < (int32)consumed; ++i) w_u8(0x800A9CF4u + length++, r_u8(0x800A8334u + i));
        } else {
            w_u8(0x800A9CF4u + length, 10u); ++lines; output = draft_round1_text_line(output, length + 1u, a3, position, a4, 0u);
            length = 0u; w_u32(0x800A9A5Cu, 0u); w_u32(0x800A7BE4u, r_u32(0x800A7BE4u) + 1u);
        }
    }
    w_u8(0x800A9CF4u + length, 0u); draft_round1_text_line(output, length + 1u, a3, position, a4, 0u); return draft_scratch_result(native_stack_mark, (uint64)(lines));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8004A17C */
uint32 sub_8004A17C(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(24u), object, state, result, next, node, x, z, limit = 3072u, close = 2048u;
    w_u32(temporary, r_u32(a1 + 12u)); w_u32(temporary + 4u, r_u32(a1 + 16u)); w_u32(temporary + 8u, r_u32(a1 + 20u));
    w_u32(temporary + 16u, r_u32(0x800A6140u)); w_u32(temporary + 20u, r_u32(0x800A6144u)); object = r_u32(a1); state = r_u8(object + 198u);
    switch (state) {
    case 0u:
        w_u8(object + 199u, 0u); object = r_u32(a1);
        if (r_u8(object + 197u) == 8u || r_u8(object + 197u) == 9u) { limit = 4096u; close = 3072u; }
        if ((int32)r_u32(a1 + 8u) < (int32)limit) {
            if ((int32)r_u32(a1 + 8u) < (int32)close) w_u8(object + 87u, 255u);
            else { w_u8(object + 199u, 1u); w_u8(r_u32(a1) + 87u, 1u); }
        } else { w_u8(object + 87u, 1u); sub_80031DC8(r_u32(a1 + 4u) + 36u, temporary, temporary + 16u); }
        w_u32(r_u32(a1) + 92u, r_u32(temporary)); w_u32(r_u32(a1) + 96u, r_u32(temporary + 8u)); object = r_u32(a1);
        result = sub_80055A9C(r_u32(temporary) - r_u32(object + 20u), r_u32(temporary + 8u) - r_u32(object + 28u)); w_u16(r_u32(a1) + 180u, (uint16)result);
        if ((int32)r_u32(a1 + 8u) > 16384) { w_u8(r_u32(a1) + 198u, 16u); goto common; }
        { uint32 y = r_u32(temporary + 4u); w_u32(a1 + 12u, r_u32(temporary)); w_u32(a1 + 16u, y); w_u32(a1 + 20u, r_u32(temporary + 8u)); }
        result = sub_80049AC0(a1, (uint32)(int32)(int16)r_u16(r_u32(a1) + 180u));
        if (result) { w_u8(r_u32(a1) + 198u, 16u); return draft_scratch_result(native_stack_mark, (uint64)(16u)); } goto common;
    case 10u:
        w_u8(object + 198u, 10u); w_u8(r_u32(a1) + 87u, 1u); w_u16(r_u32(a1) + 114u, 0u); object = r_u32(a1);
        if ((int32)r_u32(a1 + 8u) > 4096) {
            result = sub_80055A9C(r_u32(object + 116u) - r_u32(object + 20u), r_u32(object + 124u) - r_u32(object + 28u)); w_u16(r_u32(a1) + 180u, (uint16)result);
            w_u32(r_u32(a1) + 92u, r_u32(r_u32(a1) + 116u)); w_u32(r_u32(a1) + 96u, r_u32(r_u32(a1) + 124u));
        } else {
            result = sub_80055A9C(r_u32(a1 + 12u) - r_u32(object + 20u), r_u32(a1 + 20u) - r_u32(object + 28u)); w_u16(r_u32(a1) + 180u, (uint16)result);
            w_u32(r_u32(a1) + 92u, r_u32(a1 + 12u)); w_u32(r_u32(a1) + 96u, r_u32(a1 + 20u));
        }
        w_u8(r_u32(a1) + 199u, (int32)r_u32(a1 + 8u) < 2048 ? 1u : 0u); goto common;
    case 8u: case 16u:
        object = r_u32(a1); w_u8(object + 198u, r_u8(object + 198u) == 8u ? 1u : 17u); goto reset;
    case 9u: w_u8(r_u32(a1) + 198u, 15u);
reset:
        w_u8(r_u32(a1) + 199u, 1u); w_u16(r_u32(a1) + 188u, 0u); w_u32(r_u32(a1) + 80u, 40960u); w_u16(r_u32(a1) + 170u, 0xFFFFu); return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    case 15u:
        result = (uint32)draft_call_adapter(0x80049D98u, a1); if (!result) return draft_scratch_result(native_stack_mark, (uint64)(result)); goto state_eight;
    case 1u: case 17u:
        sub_80049FBC(a1); object = r_u32(a1); result = (uint32)(int32)(int16)r_u16(object + 188u) < r_u32(0x800A63E4u); if (result) return draft_scratch_result(native_stack_mark, (uint64)(result));
        w_u16(object + 152u, (uint16)(r_u16(object + 152u) + 1u)); object = r_u32(a1); result = (uint32)(int32)(int16)r_u16(object + 170u);
        if ((int32)result >= 0) {
            w_u16(object + 172u, (uint16)result); w_u16(r_u32(a1) + 174u, r_u16(r_u32(a1) + 170u)); object = r_u32(a1);
            result = sub_80047788(object, r_u32(r_u32(0x800A851Cu) + 4u * (uint32)(int32)(int16)r_u16(object + 164u)) + 20u); w_u16(r_u32(a1) + 174u, (uint16)result);
            node = sub_800476D8((uint32)(int32)(int16)r_u16(r_u32(a1) + 172u)); x = ((r_u32(node) & 0x3FFu) << 9) - r_u32(r_u32(a1) + 20u);
            node = sub_800476D8((uint32)(int32)(int16)r_u16(r_u32(a1) + 172u)); z = (((r_u32(node) >> 10) & 0x3FFu) << 9) - r_u32(r_u32(a1) + 28u);
            result = sub_80055A9C(x, z) & 0xFFFu; w_u16(r_u32(a1) + 180u, (uint16)result); sub_800494F4(r_u32(a1), (uint32)(int32)(int16)r_u16(r_u32(a1) + 172u));
            w_u8(r_u32(a1) + 199u, 0u); w_u16(r_u32(a1) + 168u, r_u16(r_u32(a1) + 174u)); w_u16(r_u32(a1) + 170u, 5u); w_u8(r_u32(a1) + 87u, 1u); w_u16(r_u32(a1) + 114u, 0u); goto state_thirteen;
        }
        if (r_u32(0x800A8690u) && (r_u32(0x800A9A58u) == object || r_u32(0x800A622Cu) == object)) { w_u16(0x800A9734u, 2u); return draft_scratch_result(native_stack_mark, (uint64)(2u)); }
        object = r_u32(a1);
        if (r_u8(object + 12u) && r_u16(object + 152u) < 11u && r_u16(object + 154u) < 11u) goto state_eight;
        w_u8(r_u32(a1) + 198u, 9u); w_u16(r_u32(a1) + 152u, 0u); w_u16(r_u32(a1) + 154u, 0u); return draft_scratch_result(native_stack_mark, (uint64)(r_u32(a1)));
    case 4u:
        object = r_u32(a1); draft_call_adapter(0x80049648u, object, (uint32)(int32)(int16)r_u16(object + 172u), (uint32)(int32)(int16)r_u16(object + 174u)); w_u8(r_u32(a1) + 198u, 3u); goto common;
    case 6u:
        sub_800494F4(r_u32(a1), (uint32)(int32)(int16)r_u16(r_u32(a1) + 174u)); node = sub_800476D8((uint32)(int32)(int16)r_u16(r_u32(a1) + 172u)); w_u32(node + 4u, r_u32(node + 4u) & ~0x200u);
        object = r_u32(a1); result = sub_80047788(object, r_u32(r_u32(0x800A851Cu) + 4u * (uint32)(int32)(int16)r_u16(object + 164u)) + 20u);
        w_u16(r_u32(a1) + 172u, r_u16(r_u32(a1) + 174u)); w_u16(r_u32(a1) + 174u, (uint16)result); w_u8(r_u32(a1) + 198u, 2u); object = r_u32(a1);
        if ((int8)r_u8(object + 85u) > 0) { w_u8(object + 85u, (uint8)(r_u8(object + 85u) - 1u)); object = r_u32(a1); if (!r_u8(object + 85u)) w_u8(object + 84u, 0u); } goto common;
    case 5u:
        if (r_u16(a1 + 24u)) { node = sub_800476D8((uint32)(int32)(int16)r_u16(r_u32(a1) + 174u)); w_u32(node + 4u, r_u32(node + 4u) | 0x200u); }
        w_u16(r_u32(a1) + 168u, r_u16(r_u32(a1) + 174u)); w_u16(r_u32(a1) + 170u, 5u); w_u8(r_u32(a1) + 199u, 0u); w_u8(r_u32(a1) + 198u, 7u); sub_80044F50(a1); goto common;
    case 14u:
        w_u8(r_u32(a1) + 199u, 0u); w_u8(r_u32(a1) + 87u, 1u); object = r_u32(a1);
        w_u32(a1 + 12u, r_u32(object + 92u)); w_u32(a1 + 16u, r_u32(object + 24u)); w_u32(a1 + 20u, r_u32(r_u32(a1) + 96u));
        if (sub_80049AC0(a1, (uint32)(int32)(int16)r_u16(r_u32(a1) + 182u))) goto state_eight;
state_thirteen:
        w_u8(r_u32(a1) + 198u, 13u); return draft_scratch_result(native_stack_mark, (uint64)(13u));
    default: break;
    }
common:
    object = r_u32(a1); result = sub_800498D4(object, (uint32)(int32)(int16)r_u16(object + 182u));
    if (!result) {
        object = r_u32(a1);
        if (r_u8(object + 198u) == 18u) { w_u8(object + 198u, 8u); w_u8(r_u32(a1) + 85u, 2u); w_u16(r_u32(a1) + 114u, 0u); w_u8(r_u32(a1) + 87u, 1u); return draft_scratch_result(native_stack_mark, (uint64)(1u)); }
        w_u16(object + 152u, (uint16)(r_u16(object + 152u) + 1u)); w_u8(r_u32(a1) + 198u, 18u); w_u8(r_u32(a1) + 87u, 255u); w_u16(r_u32(a1) + 114u, 120u); return draft_scratch_result(native_stack_mark, (uint64)(120u));
    }
    object = r_u32(a1);
    if ((int16)r_u16(object + 170u) <= 0) { w_u16(object + 170u, 5u); next = r_u8(r_u32(a1) + 198u) ? 8u : 16u; w_u8(r_u32(a1) + 198u, (uint8)next); return draft_scratch_result(native_stack_mark, (uint64)(next)); }
    if ((int16)r_u16(object + 114u) > 0) {
        w_u16(object + 114u, (uint16)(r_u16(object + 114u) - r_u16(0x800A9010u)));
        if ((int16)r_u16(r_u32(a1) + 114u) <= 0) { w_u8(r_u32(a1) + 87u, 1u); w_u16(r_u32(a1) + 114u, 0u); w_u8(r_u32(a1) + 198u, 8u); w_u8(r_u32(a1) + 85u, 2u); return draft_scratch_result(native_stack_mark, (uint64)(2u)); }
    }
    result = sub_80049814(r_u32(a1)) << 16;
    if (result) { result = r_u32(a1); w_u8(result + 198u, r_u8(0x80010100u + r_u8(result + 198u))); }
    return draft_scratch_result(native_stack_mark, (uint64)(result));
state_eight:
    w_u8(r_u32(a1) + 198u, 8u); return draft_scratch_result(native_stack_mark, (uint64)(8u));

    draft_scratch_release(native_stack_mark);
}
