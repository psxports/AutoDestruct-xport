#include "draft_signatures.h"

uint32 sub_80029968(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80029968u, "1.EXE");
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80055A70(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80055A70u, "1.EXE");
    w_u16(a1 + 16u, 4096u);
    w_u16(a1 + 8u, 4096u);
    w_u16(a1, 4096u);
    w_u16(a1 + 14u, 0u);
    w_u16(a1 + 12u, 0u);
    w_u16(a1 + 10u, 0u);
    w_u16(a1 + 6u, 0u);
    w_u16(a1 + 4u, 0u);
    w_u16(a1 + 2u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(4096u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80055228(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80055228u, "1.EXE");
    uint32 offset = ((0u - a1) & 4095u) << 1;
    uint32 cosine = r_u16(0x80010AE0u + offset);
    w_u16(a2, (uint16)cosine);
    w_u16(a2 + 8u, (uint16)cosine);
    uint32 sine = (uint32)(sint32)(sint16)r_u16(0x800102E0u + offset);
    w_u16(a2 + 16u, 4096u);
    w_u16(a2 + 14u, 0u);
    w_u16(a2 + 12u, 0u);
    w_u16(a2 + 10u, 0u);
    w_u16(a2 + 4u, 0u);
    w_u16(a2 + 2u, (uint16)sine);
    w_u16(a2 + 6u, (uint16)(0u - sine));
    return draft_scratch_result(native_stack_mark, (uint64)(4096u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800452B8(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800452B8u, "1.EXE");
    // TODO Bind the original length helper
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80069BE0u, r_u32(a1 + 100u), r_u32(a1 + 104u)) << 8));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8004530C(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8004530Cu, "1.EXE");
    // TODO Bind the original angle helper
    uint32 result = (uint32)draft_call_adapter(0x80055A9Cu, r_u32(a1 + 100u), r_u32(a1 + 104u));
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)(sint32)(sint16)(uint16)result));

    draft_scratch_release(native_stack_mark);
}

uint64 sub_8006984C(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8006984Cu, "1.EXE");
    uint32 term = ((a3 << 1) + a3) << 3;
    a4 += (term + a3) << 2;
    term = ((a2 << 1) + a2) << 4;
    term = ((term - a2) << 3) - a2;
    a4 += term << 4;
    term = ((a1 << 1) + a1) << 2;
    term = ((term - a1) << 6) - a1;
    term = ((term << 3) + a1) << 6;
    a4 += term;
    uint32 high = ((uint32)((sint32)a4 >> 31) << 16) | (a4 >> 16);
    return draft_scratch_result(native_stack_mark, (uint64)(((uint64)high << 32) | (uint32)(a4 << 16)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005B614(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005B614u, "1.EXE");
    // TODO Bind the original height helper
    uint32 result = (uint32)draft_call_adapter(0x8005B47Cu, a1) - a3;
    if ((sint32)result < (sint32)a2)
        w_u32(a1 + 4u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

void sub_8005B9A0(uint32 matrix, uint32 translation, uint32 vector, uint32 angle, uint32 destination)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005B9A0u, "1.EXE");
    // TODO Bind the existing matrix and vector helpers
    draft_call_adapter(0x800551CCu, angle, matrix);
    draft_call_adapter(0x80031CE8u, matrix, translation, vector, destination);

    draft_scratch_release(native_stack_mark);
}

void sub_80031B6C(uint32 matrix, uint32 vector, uint32 destination)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80031B6Cu, "1.EXE");
    uint32 words[5];
    words[0] = r_u32(matrix);
    words[1] = r_u32(matrix + 4u);
    words[2] = r_u32(matrix + 8u);
    words[3] = r_u32(matrix + 12u);
    words[4] = r_u32(matrix + 16u);
    uint32 xy = r_u32(vector);
    uint32 z = r_u32(vector + 4u);
    sint32 output[3];
    gte_rotate_packed(words, xy, z, output);
    sint16 coefficients[9];
    for (uint32 i = 0u; i < 9u; ++i)
        coefficients[i] = (sint16)(words[i >> 1] >> ((i & 1u) << 4));
    sint32 components[3] = {(sint16)xy, (sint16)(xy >> 16), (sint16)z};
    for (uint32 row = 0u; row < 3u; ++row)
    {
        sint64 value = (sint64)coefficients[row * 3u] * components[0] + (sint64)coefficients[row * 3u + 1u] * components[1] + (sint64)coefficients[row * 3u + 2u] * components[2];
        w_u32(destination + row * 4u, (uint32)(value >> 12));
    }

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006F23C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8006F23Cu, "1.EXE");
    // TODO Bind the interrupt BIOS boundaries
    draft_call_adapter(0x800796DCu);
    uint32 result = r_u32(0x800A7FACu);
    w_u32(0x800A7FACu, 0u);
    draft_call_adapter(0x80079C20u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005C8A4(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005C8A4u, "1.EXE");
    uint32 temporary = draft_scratch_adapter(16u);
    w_u32(temporary, r_u32(a2));
    w_u32(temporary + 4u, r_u32(a2 + 4u));
    w_u32(temporary + 8u, r_u32(a2 + 8u));
    // TODO Bind the original position helper
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8005C5A4u, a1, temporary, a3)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80065D34(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80065D34u, "1.EXE");
    // TODO Bind the object allocator
    uint32 result = (uint32)draft_call_adapter(0x800227C4u, 40u);
    w_u32(result + 20u, a2 + (r_u32(a1) & 4095u));
    w_u32(result + 28u, a3 + ((r_u32(a1) >> 12) & 4095u));
    uint32 height = r_u16(a1 + 4u);
    uint32 flags = r_u8(result + 14u);
    w_u32(result, 0x80065DD0u);
    w_u8(result + 14u, (uint8)(flags | 32u));
    w_u32(result + 8u, 15u);
    w_u32(result + 24u, 0u - height);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005D5E8(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005D5E8u, "1.EXE");
    if (a3 != 0u)
        sub_8005C8A4(a1, a2, (uint32)(sint32)(sint16)r_u16(a1 + 40u));
    if (r_u8(a1 + 46u) != 0u)
    {
        w_u8(a1 + 46u, 0u);
        draft_call_adapter(0x8005C560u, a1);
    }
    uint32 settled = (uint32)draft_call_adapter(0x8005C270u, a1 + 12u, a1 + 28u, (uint32)(sint32)(sint16)r_u16(a1 + 38u));
    if (settled != 0u && r_u32(a1) == r_u32(0x800A7EE4u) && r_u32(a1 + 4u) == r_u32(0x800A7EE8u) && r_u32(a1 + 8u) == r_u32(0x800A7EECu))
    {
        uint32 flag = r_u8(a1 + 47u);
        w_u8(a1 + 44u, (uint8)flag);
        w_u8(a1 + 45u, (uint8)flag);
    }
    // TODO Bind the original camera update helpers
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8005C074u, a1, (uint32)(sint32)(sint16)r_u16(a1 + 118u), a2, a4)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80045340(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80045340u, "1.EXE");
    uint32 kind = r_u8(a1 + 197u);
    if (kind >= 8u && kind < 10u)
    {
        w_u16(a2, r_u16(a1 + 186u));
        w_u16(a2 + 4u, r_u16(a1 + 186u));
    }
    else if (kind == 22u)
    {
        w_u16(a2, 0u);
        w_u16(a2 + 4u, 0u);
    }
    else
    {
        sint32 value = (sint16)r_u16(a1 + 252u) + (sint16)r_u16(a1 + 236u) - ((sint16)r_u16(a1 + 204u) + (sint16)r_u16(a1 + 220u));
        uint32 entry = r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u));
        uint32 scale = (uint32)(sint32)(sint16)r_u16(r_u32(0x800A90ACu) + entry * 40u + 34u);
        w_u16(a2, (uint16)draft_call_adapter(0x80055A9Cu, (uint32)(value >> 1), scale));
        value = (sint16)r_u16(a1 + 236u) + (sint16)r_u16(a1 + 220u) - ((sint16)r_u16(a1 + 252u) + (sint16)r_u16(a1 + 204u));
        entry = r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u));
        scale = (uint32)(sint32)(sint16)r_u16(r_u32(0x800A90ACu) + entry * 40u + 36u);
        w_u16(a2 + 4u, (uint16)draft_call_adapter(0x80055A9Cu, (uint32)(value >> 1), scale));
    }
    uint32 result = r_u16(a1 + (r_u8(a1 + 197u) == 7u ? 360u : 182u)) + 2048u;
    w_u16(a2 + 2u, (uint16)result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80021E94(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80021E94u, "1.EXE");
    w_u32(0x800A564Cu, 0u);
    w_u32(0x800A5648u, 0u);
    draft_call_adapter(0x80021F80u);
    uint32 row = 0u;
    do
    {
        if (row + r_u32(0x800A5644u) < 80u)
        {
            for (uint32 column = 0u; column < 14u; ++column)
            {
                uint32 source = row * 14u + column;
                if (column + r_u32(0x800A5640u) < 80u && r_u8(0x8008B794u + source) != 0u)
                    sub_80021BB0(source, (row + r_u32(0x800A5644u)) * 80u + r_u32(0x800A5640u) + column);
            }
        }
        row += 1u;
    } while ((sint32)row < 14);
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8004EC84(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8004EC84u, "1.EXE");
    uint32 result = (uint32)draft_call_adapter(0x80045AD8u, a1, 0x8004E954u);
    if (result != 0u)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    if ((r_u8(a1 + 14u) & 2u) != 0u && r_u8(a1 + 12u) >= 4u)
    {
        draft_call_adapter(0x8004E6A4u, a1, (uint32)(sint32)(sint16)r_u16(a1 + 182u));
        uint32 entry = r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u));
        uint32 model = (uint32)(sint32)(sint16)r_u16(r_u32(0x800A90ACu) + entry * 40u + 32u);
        draft_call_adapter(0x80029970u, a1, model, 2u, 1u, a1 + 20u);
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800369E0u, a1 + 20u, a1 + 194u, 1024u, 18u)));
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80036CFCu, a1 + 194u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8004D730(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8004D730u, "1.EXE");
    uint32 result = r_u8(a1 + 14u) & 2u;
    if (result == 0u)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    result = r_u8(a1 + 12u) < 4u;
    if (result != 0u)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    uint32 entry = r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u));
    uint32 model = (uint32)(sint32)(sint16)r_u16(r_u32(0x800A90ACu) + entry * 40u + 32u);
    draft_call_adapter(0x80029970u, a1, model, 2u, 1u, a1 + 20u);
    result = (uint32)draft_call_adapter(0x80069BE0u, r_u32(a1 + 100u), r_u32(a1 + 104u)) < 17u;
    if (result != 0u)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    uint32 vectors = draft_scratch_adapter(32u);
    uint32 first = r_u32(a1 + 128u);
    uint32 second = r_u32(a1 + 132u);
    uint32 third = r_u32(a1 + 136u);
    w_u32(vectors + 16u, first);
    w_u32(vectors + 20u, second);
    w_u32(vectors + 24u, third);
    w_u32(vectors, r_u32(a1 + 100u));
    w_u32(vectors + 8u, r_u32(a1 + 104u));
    draft_call_adapter(0x80048F9Cu, a1 + 20u, vectors, a1 + 182u, 12u);
    draft_call_adapter(0x8004CAD4u, a1, vectors, vectors + 16u, a1 + 200u);
    w_u32(a1 + 100u, r_u32(vectors));
    w_u32(a1 + 104u, r_u32(vectors + 8u));
    result = r_u32(a1 + 20u);
    second = r_u32(a1 + 24u);
    third = r_u32(a1 + 28u);
    w_u32(a1 + 128u, result);
    w_u32(a1 + 132u, second);
    w_u32(a1 + 136u, third);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8002F3FC */
uint32 sub_8002F3FC(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(24u);
    uint32 average = (uint32)((int32)(r_u32(a1 + 4u) + r_u32(a2 + 4u)) >> 1);
    uint32 cells[4], xs[4], zs[4];
    uint32 index, layer, offset, value, entry;
    xs[0] = xs[2] = r_u32(a1);
    xs[1] = xs[3] = r_u32(a2);
    zs[0] = zs[3] = r_u32(a1 + 8u);
    zs[1] = zs[2] = r_u32(a2 + 8u);
    w_u32(temporary, a1);
    w_u32(temporary + 4u, a2);
    w_u32(temporary + 8u, average);
    for (index = 0; index < 4u; ++index)
    {
        cells[index] = (uint32)((int32)xs[index] >> 12) + 80u * (uint32)((int32)zs[index] >> 12);
        entry = r_u16(r_u32(0x800A84F8u) + 8u * cells[index] + 4u);
        layer = 0u;
        offset = entry;
        for (;;)
        {
            value = r_u16(r_u32(0x800A869Cu) + 2u * offset);
            if ((int32)(0u - average) >= (int32)(2u * (value & 0x7FFFu)))
                break;
            offset += 3u;
            if (value & 0x8000u)
                break;
            ++layer;
        }
        value = r_u16(r_u32(0x800A869Cu) + 2u * (3u * layer + entry) + 2u);
        w_u32(temporary + 12u, value);
        if (index == 1u && (value == 0xFFFFu || cells[1] == cells[0]))
            return draft_scratch_result(native_stack_mark, (uint64)(0u));
        if (index == 2u && (value == 0xFFFFu || cells[2] == cells[0] || cells[2] == cells[1]))
            return draft_scratch_result(native_stack_mark, (uint64)(0u));
        if (index == 3u && value == 0xFFFFu)
            return draft_scratch_result(native_stack_mark, (uint64)(0u));
        if (value == 0xFFFFu)
            continue;
        w_u32(temporary + 16u, xs[index] & 0xFFFFF000u);
        w_u32(temporary + 20u, zs[index] & 0xFFFFF000u);
        if (((uint32)draft_call_adapter(0x8002EDDCu, temporary) << 16) != 0u)
            return draft_scratch_result(native_stack_mark, (uint64)(1u));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8003095C */
uint32 sub_8003095C(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 x = r_u32(a1), z = r_u32(a1 + 8u), layer = 0u;
    uint32 base_x = x & 0xFFFFF000u, base_z = z & 0xFFFFF000u;
    uint32 entry = r_u16(r_u32(0x800A84F8u) + 8u * ((uint32)((int32)x >> 12) + 80u * (uint32)((int32)z >> 12)) + 4u);
    uint32 offset = entry, value, cursor, polygon, height;
    for (;;)
    {
        value = r_u16(r_u32(0x800A869Cu) + 2u * offset);
        if ((int32)(0u - r_u32(a1 + 4u)) >= (int32)(2u * (value & 0x7FFFu)))
            break;
        offset += 3u;
        if (value & 0x8000u)
            break;
        ++layer;
    }
    value = r_u16(r_u32(0x800A869Cu) + 2u * (3u * layer + entry) + 2u);
    if (value == 0xFFFFu)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    height = 0u - r_u32(a1 + 4u);
    cursor = r_u32(0x800A9CDCu) + 2u * value;
    do
    {
        uint32 px[4], pz[4], i;
        int inside = 1;
        value = r_u16(cursor);
        cursor += 2u;
        polygon = r_u32(0x800A9024u) + 20u * (value & 0x7FFFu);
        if ((int32)height < (int32)r_u16(polygon + 2u) && (int32)r_u16(polygon) < (int32)height)
        {
            for (i = 0u; i < 4u; ++i)
            {
                px[i] = base_x + (uint32)(int32)(int16)r_u16(polygon + 4u + 4u * i);
                pz[i] = base_z + (uint32)(int32)(int16)r_u16(polygon + 6u + 4u * i);
            }
            x = r_u32(a1);
            z = r_u32(a1 + 8u);
            for (i = 0u; i < 4u; ++i)
            {
                uint32 next = (i + 1u) & 3u;
                if ((int32)((pz[i] - pz[next]) * (x - px[next]) + (px[next] - px[i]) * (z - pz[next])) < 0)
                {
                    inside = 0;
                    break;
                }
            }
            if (inside)
                return draft_scratch_result(native_stack_mark, (uint64)(1u));
        }
    } while (!(value & 0x8000u));
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80030F08 */
uint32 sub_80030F08(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 node = r_u32(0x800A6098u), result, tail, previous, allocated;
    int32 key = (int16)a1;
    if (key == -1)
        return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    w_u16(0x800A9D70u, 1u);
    w_u32(0x800A5FA4u, 2u);
    if (r_u32(0x800A6C18u) || !r_u16(0x800A9734u))
        w_u32(0x800A6C18u, 0u);
    else
    {
        w_u32(0x800A6C18u, 1u);
        w_u32(0x800A60A0u, 0u);
        w_u32(0x800A60A4u, r_u32(0x800A609Cu));
    }
    if (r_u32(0x800A609Cu))
    {
        while (node)
        {
            if ((int16)r_u16(node) == key && r_u8(node + 3u) == r_u32(0x800A5FA0u))
            {
                tail = r_u32(node + 8u);
                while (r_u32(tail + 4u))
                    tail = r_u32(tail + 4u);
                result = (uint32)draft_call_adapter(0x80064B04u, 8u);
                w_u32(tail + 4u, result);
                w_u16(result, (uint16)a2);
                w_u32(result + 4u, 0u);
                return draft_scratch_result(native_stack_mark, (uint64)(result));
            }
            node = r_u32(node + 4u);
        }
        if (!r_u32(0x800A60A0u) || r_u8(r_u32(0x800A60A4u) + 3u) != r_u32(0x800A5FA0u))
            w_u32(0x800A60A4u, r_u32(0x800A609Cu));
        if (key && r_u8(r_u32(r_u32(0x800A851Cu) + 4u * (uint32)key) + 17u))
        {
            node = r_u32(0x800A60A4u);
            previous = r_u32(node + 4u);
            allocated = (uint32)draft_call_adapter(0x80064B04u, 12u);
            node = r_u32(0x800A60A4u);
            w_u32(node + 4u, allocated);
            if (node == r_u32(0x800A609Cu))
                w_u32(0x800A609Cu, allocated);
            node = r_u32(node + 4u);
            w_u32(0x800A60A4u, node);
            w_u32(node + 4u, previous);
            if (!r_u32(0x800A60A0u))
                w_u32(0x800A60A0u, node);
            w_u8(node + 2u, (uint8)a3);
            w_u16(node, (uint16)a1);
            w_u8(node + 3u, (uint8)r_u32(0x800A5FA0u));
            if (node == r_u32(0x800A609Cu))
                w_u32(node + 4u, 0u);
            allocated = (uint32)draft_call_adapter(0x80064B04u, 8u);
            node = r_u32(0x800A60A4u);
            w_u32(node + 8u, allocated);
            w_u16(allocated, (uint16)a2);
            result = r_u32(node + 8u);
            w_u32(result + 4u, 0u);
            return draft_scratch_result(native_stack_mark, (uint64)(result));
        }
        allocated = (uint32)draft_call_adapter(0x80064B04u, 12u);
        previous = r_u32(0x800A609Cu);
        w_u32(0x800A609Cu, allocated);
        w_u32(previous + 4u, allocated);
        if (!r_u32(0x800A60A0u))
            w_u32(0x800A60A0u, allocated);
    }
    else
    {
        allocated = (uint32)draft_call_adapter(0x80064B04u, 12u);
        w_u32(0x800A609Cu, allocated);
        w_u32(0x800A6098u, allocated);
        w_u32(0x800A60A4u, allocated);
        w_u32(0x800A60A0u, allocated);
    }
    node = r_u32(0x800A609Cu);
    w_u8(node + 2u, (uint8)a3);
    w_u16(node, (uint16)a1);
    w_u8(node + 3u, (uint8)r_u32(0x800A5FA0u));
    w_u32(r_u32(0x800A609Cu) + 4u, 0u);
    allocated = (uint32)draft_call_adapter(0x80064B04u, 8u);
    node = r_u32(0x800A609Cu);
    w_u32(node + 8u, allocated);
    w_u16(allocated, (uint16)a2);
    w_u32(r_u32(node + 8u) + 4u, 0u);
    result = a1 << 16;
    if (!result)
        w_u32(0x800A60A0u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8005BD4C */
void sub_8005BD4C(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(144u), hit = 0u, distance, vertical, horizontal;
    if (!(r_u8(a4 + 126u) & 1u) && !a7)
    {
        hit = (uint32)(sint32)(sint16)draft_call_adapter(0x80030BACu, temporary + 40u, a1, a2, a3, a4 + 52u);
        sub_8005B614(a2, r_u32(a4 + 4u), 175u);
    }
    if (!hit && !(r_u8(a4 + 126u) & 1u))
    {
        w_u16(0x800A8562u, (uint16)(0u - (uint32)(int32)(int16)(a6 + 2048u)));
        w_u16(0x800A8566u, 1u);
    }
    draft_call_adapter(0x8005B2ACu, a2, a1, temporary + 8u);
    vertical = r_u32(temporary + 12u);
    horizontal = (uint32)draft_call_adapter(0x80069BE0u, r_u32(temporary + 8u), r_u32(temporary + 16u));
    distance = (uint32)draft_call_adapter(0x80069BE0u, horizontal, vertical);
    w_u32(temporary + 24u, 0u);
    w_u32(temporary + 28u, r_u32(temporary + 12u));
    w_u32(temporary + 32u, (uint32)draft_call_adapter(0x80069BE0u, r_u32(temporary + 8u), r_u32(temporary + 16u)));
    if ((int32)(50u * r_u32(0x800A9010u)) >= (int32)(distance - (uint32)(int32)(int16)r_u16(a4 + 124u)) || a7)
    {
        vertical = r_u32(temporary + 28u);
        horizontal = r_u32(temporary + 32u);
        w_u32(a4 + 128u, 0u);
        w_u32(a4 + 132u, vertical);
        w_u32(a4 + 136u, horizontal);
    }
    else
    {
        draft_call_adapter(0x800557C0u, a4 + 128u, temporary + 24u, 50u * r_u32(0x800A9010u));
        draft_call_adapter(0x80031D50u, a5, a1, a4 + 128u, a2);
    }

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80021BB0 */
uint32 sub_80021BB0(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 row = (int32)a2 / 80;
    uint32 x = (a2 - 80u * (uint32)row) << 12, z = (uint32)row << 12;
    uint32 local_x = x - r_u32(0x800A6784u), local_z = z - r_u32(0x800A678Cu);
    uint32 node = r_u16(r_u32(0x800A84F8u) + 8u * a2 + 6u), offset, record, count, buffer, end;
    w_u32(0x800A9D80u + 12u * a1, node);
    while (node)
    {
        offset = 12u * node;
        record = r_u32(r_u32(0x800A9754u) + offset - 12u);
        if (!(record & 0x80000000u))
            draft_call_adapter(r_u32(0x800910E8u + ((record >> 22) & 0x1FCu)), r_u32(0x800A9754u) + offset - 12u, x, z);
        node = (r_u32(r_u32(0x800A9754u) + offset - 4u) >> 12) & 0xFFFu;
    }
    node = r_u16(r_u32(0x800A84F8u) + 8u * a2 + 2u * r_u32(0x800A5638u));
    if (node)
    {
        count = r_u16(r_u32(0x800A7E24u) + 2u * (node - 1u));
        buffer = (uint32)draft_call_adapter(0x80064B04u, 16u * count);
        w_u32(0x800A9D7Cu + 12u * a1, buffer);
        end = buffer + 16u * count;
        while (buffer < end)
        {
            record = r_u16(r_u32(0x800A7E24u) + 2u * node);
            if ((record & 0x7FFFu) != 0x7FFFu)
            {
                offset = r_u32(0x800A7BFCu) + 8u * record;
                w_u8(buffer + 3u, (uint8)(r_u16(offset + 2u) >> 14));
                w_u32(buffer + 4u, local_x + (r_u16(offset + 2u) & 0xFFFu));
                w_u8(buffer + 3u, (uint8)(r_u16(offset + 2u) >> 14));
                w_u32(buffer + 8u, 0u - r_u16(offset + 6u));
                record = r_u16(offset + 4u);
                w_u8(buffer + 2u, 0u);
                w_u32(buffer + 12u, local_z + (record & 0xFFFu));
                w_u16(buffer, r_u16(offset));
            }
            else
                w_u8(buffer + 3u, 4u);
            buffer += 16u;
            ++node;
        }
        w_u16(0x800A9D78u + 12u * a1, (uint16)count);
    }
    w_u16(0x800A9D7Au + 12u * a1, (uint16)a2);
    return draft_scratch_result(native_stack_mark, (uint64)(12u * a1));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8002DC94 */
uint32 sub_8002DC94(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 first = r_u32(0x800A5764u), second = r_u32(0x800A5768u), i;
    while ((int32)first < (int32)(r_u32(0x800A576Cu) - 1u))
    {
        uint32 outer = 0x800B3480u + 20u * first, object = r_u32(outer);
        while ((int32)second < (int32)r_u32(0x800A576Cu))
        {
            uint32 inner = 0x800B3480u + 20u * second, other = r_u32(inner);
            if (r_u8(outer + 17u) || r_u8(inner + 17u))
            {
                uint32 dx = r_u32(object + 20u) - r_u32(other + 20u), dz = r_u32(object + 28u) - r_u32(other + 28u);
                uint32 abs_x = (int32)dx < 0 ? 0u - dx : dx, abs_z = (int32)dz < 0 ? 0u - dz : dz;
                if ((int32)abs_x < 2048 && (int32)abs_z < 2048)
                {
                    uint32 offset = 8u * (11u * r_u8(outer + 16u) + r_u8(inner + 16u)), mode = r_u8(0x800A57A8u + offset);
                    if (mode == 1u)
                        draft_call_adapter(r_u32(0x800A57ACu + offset), r_u32(inner), (uint32)(int32)(int16)second, object, (uint32)(int32)(int16)first);
                    else if (mode)
                        draft_call_adapter(r_u32(0x800A57ACu + offset), object, (uint32)(int32)(int16)first, r_u32(inner), (uint32)(int32)(int16)second);
                }
            }
            ++second;
        }
        ++first;
        second = first + 1u;
    }
    for (i = 0u; (int32)i < (int32)r_u32(0x800A5770u); ++i)
    {
        uint32 index;
        for (index = 0u; (int32)index < (int32)r_u32(0x800A576Cu); ++index)
        {
            uint32 object = r_u32(0x800B3480u + 20u * index), event = 0x800A8828u + 16u * i;
            uint32 distance = (uint32)draft_call_adapter(0x80069BE0u, r_u32(event) - r_u32(object + 20u), r_u32(event + 8u) - r_u32(object + 28u));
            uint32 radius = r_u32(event + 12u), dy;
            if ((int32)radius < (int32)distance)
                continue;
            dy = r_u32(event + 4u) - r_u32(object + 24u);
            if ((int32)dy < 0)
                dy = 0u - dy;
            if ((int32)radius >= (int32)dy && (r_u8(0x800B3490u + 20u * index) < 4u || r_u8(0x800B3490u + 20u * index) == 10u))
                draft_call_adapter(0x8002D7D4u, object, (uint32)(int32)(int16)index, (uint32)(int32)(int16)i, distance);
        }
    }
    w_u32(0x800A5770u, 0u);
    w_u32(0x800A576Cu, 0u);
    w_u32(0x800A5764u, 0u);
    w_u32(0x800A5768u, 1u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800314A8u)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8005EBE4 */
uint32 sub_8005EBE4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 mode = r_u32(0x800A9A38u), translation[3], result = 3u, i, screen, temporary;
    uint32 xy, z;
    translation[0] = r_u32(0x800A634Cu);
    translation[1] = r_u32(0x800A6350u);
    translation[2] = r_u32(0x800A6354u);
    if (mode == 1u)
    {
        xy = 4096u | ((uint32)(uint16)-1500 << 16);
        z = 0u;
    }
    else if (mode == 3u)
    {
        xy = r_u16(0x800110E0u) | ((uint32)(uint16)-3175 << 16);
        z = (uint32)(int32)(int16)r_u16(0x800118E0u);
    }
    else
    {
        w_u16(0x800A997Cu, 0u);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    for (i = 0u; i < 5u; ++i)
        xport_gte_write_control(i, r_u32(0x800A9324u + 4u * i));
    for (i = 0u; i < 3u; ++i)
        xport_gte_write_control(i + 5u, translation[i]);
    xport_gte_write_data(0u, xy);
    xport_gte_write_data(1u, z);
    draft_gte_command_adapter(0x180001u);
    screen = xport_gte_read_data(14u);
    result = ((screen & 0xFFFFu) - 2u) < 0x13Du;
    if (!result)
    {
        w_u16(0x800A997Cu, 0u);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    result = 1u;
    if ((screen >> 16) - 1u >= 0xEFu)
    {
        w_u16(0x800A997Cu, 0u);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    temporary = draft_scratch_adapter(16u);
    w_u32(temporary, screen);
    w_u16(0x800A997Cu, 1u);
    w_u32(0x800A9974u, r_u32(0x800A9978u));
    w_u16(temporary + 8u, (uint16)(320u - (screen & 0xFFFFu)));
    w_u16(temporary + 10u, (uint16)(240u - (screen >> 16)));
    w_u32(0x800A9978u, screen);
    draft_call_adapter(0x8005E89Cu, temporary, temporary + 8u);
    if (r_u16(0x800A997Eu))
    {
        int32 x;
        uint32 color;
        draft_call_adapter(0x8005EAD8u, temporary, temporary + 8u);
        x = (int16)r_u16(temporary);
        if (x >= 161)
            x = 320 - x;
        color = (uint32)((int32)((uint32)x * 17u) >> 6);
        draft_call_adapter(0x80020C60u, 201u, r_u32(0x800A9A74u), color | (color << 8) | (color << 16), 1u, (uint32)-160, (uint32)-120, 320u, 240u);
    }
    /* TODO: 5E95C trailing volatile and stack values are unspecified at the original boundary */
    result = (uint32)draft_call_adapter(0x8005E95Cu, r_u32(0x800A865Cu), 0u);
    w_u32(0x800A865Cu, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8005DC0C */
uint32 sub_8005DC0C(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary = draft_scratch_adapter(40u), object, direction, delta, state;
    int32 angle, orientation;
    object = r_u32(0x800A9A58u);
    angle = (int16)(uint32)draft_call_adapter(r_u32(r_u32(object + 16u) + 12u), object);
    object = r_u32(0x800A9A58u);
    draft_call_adapter(r_u32(r_u32(object + 16u) + 20u), object, temporary);
    angle += 2048;
    object = r_u32(0x800A9A58u);
    if ((int32)(uint32)draft_call_adapter(r_u32(r_u32(object + 16u)), object) <= 0x3FFFF)
        angle = (int16)r_u16(temporary + 2u);
    orientation = (int16)r_u16(temporary + 2u);
    delta = ((uint32)angle - (uint32)orientation) & 0xFFFu;
    if ((int32)(delta - 2048u) < 0)
    {
        if (2048u - delta < 1024u)
            angle += 2048;
    }
    else if (delta - 2048u < 1024u)
        angle += 2048;
    state = (uint32)(int32)(int16)r_u16(0x800A8530u);
    if (state == 0u)
    {
        w_u8(a1 + 49u, 1u);
        draft_call_adapter(0x8005D76Cu, 2u, r_u32(0x800A9A58u) + 20u, 0u);
        draft_call_adapter(0x8005E258u, 2u);
        w_u16(a1 + 38u, 50u);
        w_u16(a1 + 118u, (uint16)angle);
        w_u16(a1 + 40u, (uint16)angle);
        w_u16(0x800A8534u, 256u);
        w_u16(0x800A8530u, (uint16)(r_u16(0x800A8530u) + 1u));
        draft_call_adapter(0x8005C560u, a1);
        sub_8005D5E8(a1, r_u32(0x800A9A58u) + 20u, 1u, 0u);
    }
    else if (state == 1u)
    {
        object = r_u32(0x800A9A58u);
        w_u16(a1 + 118u, (uint16)((uint32)angle + r_u16(0x800A8536u)));
        w_u16(0x800A8534u, (uint16)(r_u16(0x800A8534u) - r_u16(0x800A9010u)));
        sub_8005D5E8(a1, object + 20u, 1u, 0u);
        if ((int16)r_u16(0x800A8534u) < 0)
        {
            w_u16(0x800A8534u, 0xFFFFu);
            direction = (uint32)draft_call_adapter(0x80030214u, r_u32(0x800A9A58u) + 20u, 0x800A7EE4u) & 3u;
            draft_call_adapter(0x8005B694u, direction);
            if (!draft_call_adapter(0x8005D8D4u, (uint32)orientation, direction))
                w_u16(0x800A8530u, 1u);
            else
            {
                w_u16(0x800A8530u, direction ? 3u : 2u);
                draft_call_adapter(0x8005B70Cu, r_u32(0x800A9A58u) + 20u);
                w_u16(0x800A8534u, 512u);
                draft_call_adapter(0x8005DAB4u, a1);
            }
        }
    }
    else if (state == 2u || state == 3u)
    {
        object = r_u32(0x800A9A58u);
        w_u32(temporary + 8u, r_u32(object + 20u));
        w_u32(temporary + 12u, r_u32(object + 24u));
        w_u32(temporary + 16u, r_u32(object + 28u));
        draft_call_adapter(0x8005D6CCu, temporary + 8u, 0x800A7EE4u);
        direction = (uint32)draft_call_adapter(0x80030214u, r_u32(0x800A9A58u) + 20u, 0x800A7EE4u) & 3u;
        draft_call_adapter(0x8005B694u, direction);
        if (state == 2u)
        {
            if (direction)
            {
                w_u16(0x800A8534u, 512u);
                w_u16(0x800A8530u, 3u);
                draft_call_adapter(0x80035FD8u);
                if (draft_call_adapter(0x8005D800u, direction))
                    goto countdown;
            }
            else
            {
                if (!draft_call_adapter(0x8005D780u))
                    goto countdown;
                if (draft_call_adapter(0x8005D8D4u, (uint32)orientation, 0u))
                {
                    w_u16(0x800A8530u, 2u);
                    draft_call_adapter(0x8005B70Cu, r_u32(0x800A9A58u) + 20u);
                    w_u16(0x800A8534u, 512u);
                    draft_call_adapter(0x8005DAB4u, a1);
                    goto countdown;
                }
            }
            draft_call_adapter(0x8005DB18u, a1, (uint32)angle);
            w_u16(0x800A8530u, 1u);
        countdown:
            w_u16(0x800A8534u, (uint16)(r_u16(0x800A8534u) - r_u16(0x800A9010u)));
            if (r_u16(0x800A8534u) & 0x8000u)
            {
                draft_call_adapter(0x8005DB18u, a1, (uint32)angle);
                w_u16(0x800A8530u, 1u);
            }
            draft_call_adapter(0x8005B70Cu, r_u32(0x800A9A58u) + 20u);
        }
        else
        {
            if (draft_call_adapter(0x8005D780u))
            {
                if (draft_call_adapter(0x8005D8D4u, (uint32)orientation, direction))
                {
                    w_u16(0x800A8530u, direction ? 3u : 2u);
                    draft_call_adapter(0x8005B70Cu, r_u32(0x800A9A58u) + 20u);
                    w_u16(0x800A8534u, 512u);
                    draft_call_adapter(0x8005DAB4u, a1);
                }
                else
                {
                    draft_call_adapter(0x8005DBA4u, a1, (uint32)angle);
                    w_u16(0x800A8530u, 1u);
                }
            }
            draft_call_adapter(0x8005B70Cu, r_u32(0x800A9A58u) + 20u);
            delta = r_u16(0x800A8534u) - r_u16(0x800A9010u);
            w_u16(0x800A8534u, (uint16)delta);
            object = r_u32(r_u32(0x800A9A58u) + 24u);
            if ((int32)object < (int32)r_u32(0x800A7EE8u) || (int32)(r_u32(0x800A7EE8u) - object) < -405 || (delta & 0x8000u))
            {
                draft_call_adapter(0x8005DBA4u, a1, (uint32)angle);
                w_u16(0x800A8530u, 1u);
            }
        }
    }
    w_u32(0x800A84E8u, r_u32(0x800A7EE8u));
    draft_call_adapter(0x8005B6B4u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8005BEECu, a1)));

    draft_scratch_release(native_stack_mark);
}
