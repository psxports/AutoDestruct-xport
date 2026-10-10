#include "draft_signatures.h"

void sub_80033D40(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 p, offset = 0;
    FUNCTION_MARKER(0x80033D40u, "1.EXE");
    // TODO No pseudocode is available; body follows the MIPS listing
    sub_80033724(0, 10);
    sub_80033724(1, 3);
    sub_800338D8(0, r_u32(r_u32(0x800A9020u) + 8), 0xFFFFFF68u, 0xFFFFFFEAu);
    if (!r_u32(0x800A8690u))
    {
        sub_800338D8(1, r_u32(r_u32(0x800A6098u) + 8), 0xFFFFFF68u, 0xFFFFFFEAu);
        if (r_u32(0x800A9688u) || r_u32(0x800A968Cu))
            draft_call_adapter(0x80033B0Cu, 1u, r_u32(0x800A9688u), r_u32(0x800A968Cu), 2u, 0xFFFFFF68u, 0xFFFFFFEAu);
    }
    p = r_u32(0x800A8694u);
    while (r_s16(p + offset) != -1)
    {
        if (r_s16(p + offset) == 18)
            draft_call_adapter(0x80033B0Cu, 1u, 1024u + 8 * r_u16(p + offset + 2), 1024u + 8 * r_u16(p + offset + 4), 16u, 0xFFFFFF68u, 0xFFFFFFEAu);
        offset += 8;
        p = r_u32(0x800A8694u);
    }

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003732C(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 code;
    uint32 base, part, scratch, v;
    FUNCTION_MARKER(0x8003732Cu, "1.EXE");
    w_u32(0x800A966Cu, 60);
    if (a1 != 4)
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    code = r_s16(r_u32(0x800A7C68u) + 2 * a0 - 2);
    part = (uint32)code & 7;
    base = r_u32(0x800BB8B8u + 4 * (uint32)(code / 8));
    w_u32(0x800A9308u, base + part);
    w_u32(0x800A7FA8u, base + part);
    w_u32(0x800A7EE0u, base + (uint32)r_s16(r_u32(0x800A7BF0u) + 2 * (uint32)code) - 37);
    // TODO Bind the SDK addressable position output
    scratch = draft_scratch_adapter(8);
    draft_call_adapter(0x8007B7B4u, base + part, scratch);
    if (!r_u32(0x800A6D2Cu))
    {
        v = (uint32)draft_call_adapter(0x8007B368u, 2u, scratch, 0u);
        w_u32(0x800A7BE0u, v);
        w_u32(0x800A6D2Cu, v == 1);
    }
    sub_80036EDC(r_u32(0x800A975Cu));
    w_u8(0x800A9A41u, part);
    v = r_u32(0x800A6D2Cu);
    w_u8(0x800A9A40u, 1);
    w_u32(0x800A5C48u, 0);
    w_u16(0x800A9A64u, 0);
    if (v == 1)
    {
        v = (uint32)draft_call_adapter(0x8007B4A0u, 13u, 0x800A9A40u);
        w_u32(0x800A7BE0u, v);
        w_u32(0x800A6D2Cu, v == 1 ? 2 : 1);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A6D2Cu) == 2 ? 0 : 0xFFFFFFFF));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80023228(uint32 a0, uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i, scratch, p, mask = 1;
    int32 power = (int32)a4, level = power >> 18;
    FUNCTION_MARKER(0x80023228u, "1.EXE");
    if (level >= 6)
        level = 5;
    for (i = 0; i < 8; i++, mask <<= 1)
        if (r_u16(a1 + 96) & mask)
            break;
    if (i == 8)
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    // TODO Bind the addressable effect position without guest stack recreation
    scratch = draft_scratch_adapter(16);
    p = a2 + 8 * i;
    w_u32(scratch, r_u32(a0));
    w_u32(scratch + 4, r_u32(a0 + 4));
    w_u32(scratch + 8, r_u32(a0 + 8));
    w_u32(scratch, r_u32(scratch) + (uint32)r_s16(p));
    w_u32(scratch + 4, r_u32(scratch + 4) + (uint32)r_s16(p + 2));
    w_u32(scratch + 8, r_u32(scratch + 8) + (uint32)r_s16(p + 4));
    if (power > 1310720)
        power = 1310720;
    if (power <= 524288)
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    draft_call_adapter(0x8006268Cu, scratch, a1 + 12 * i, (uint32)(int16)a3, (uint32)r_s16(r_u32(0x800A62ECu) + 76), 255u, (uint32)(power >> 6), (uint32)(int16)level);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80035A08u, 9u, 2048u, 0u, scratch, 0u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006623C(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 o, v;
    FUNCTION_MARKER(0x8006623Cu, "1.EXE");
    o = (uint32)draft_call_adapter(0x800226E4u, 72u);
    w_u32(o + 20, a1 + (r_u32(a0) & 4095));
    w_u32(o + 28, a2 + ((r_u32(a0) >> 12) & 4095));
    w_u32(o + 24, 0 - r_u16(a0 + 4));
    v = r_u16(r_u32(0x800A8FD8u) + 2 * r_u8(a0 + 11));
    w_u8(o + 14, r_u8(o + 14) | 2);
    w_u8(o + 34, 11);
    w_u32(o, 0x80066380u);
    w_u16(o + 32, v);
    if (r_u32(0x800A9760u) == 1)
    {
        w_u8(o + 13, 0);
        w_u8(o + 14, r_u8(o + 14) | 32);
    }
    else
    {
        w_u8(o + 13, 8);
        w_u8(o + 14, r_u8(o + 14) | 40);
    }
    w_u32(o + 16, 0x800910B4u);
    w_u16(o + 58, 127);
    w_u16(o + 70, 1);
    draft_call_adapter(0x800551CCu, (r_u32(a0 + 4) >> 14) & 0xF80, o + 36);
    w_u32(o + 8, a0);
    w_u16(o + 60, 0);
    w_u16(o + 62, 0);
    w_u16(o + 64, 0);
    w_u16(o + 66, 25);
    w_u16(o + 56, 0);
    return draft_scratch_result(native_stack_mark, (uint64)(25));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800436D4(uint32 a0, uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 c, font, flag, x = (uint32)(int16)a2, y = (uint32)(int16)a3, start = x;
    FUNCTION_MARKER(0x800436D4u, "1.EXE");
    for (;; ++a1)
    {
        c = r_u8(a1);
        if (!c)
            return draft_scratch_result(native_stack_mark, (uint64)(32));
        if (c == 32)
        {
            x += r_u8(r_u32(0x800A5F68u) + 162);
        }
        else if (c == 10)
        {
            x = start;
            y += 13;
        }
        else
        {
            font = r_u32(0x800A5F68u);
            draft_call_adapter(0x8004328Cu, font, 0x54000040u, c, a0, x, y, a4);
            font = r_u32(0x800A5F68u);
            flag = r_u8(font + 5 * c + 4);
            if (flag != 1 && flag != 6)
                draft_call_adapter(0x8004328Cu, font, 0x64000040u, c, a0, x + 1, y + 1, a4);
            x += r_u8(r_u32(0x800A5F68u) + 5 * c + 2);
        }
    }

    draft_scratch_release(native_stack_mark);
}

void sub_8006E8A4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 step = r_u32(0x800A9010u), target = r_u32(a0 + 16), scratch, d;
    FUNCTION_MARKER(0x8006E8A4u, "1.EXE");
    if (r_u8(a0 + 35) & 128)
    {
        sub_8002289C(a0);
        {
            draft_scratch_release(native_stack_mark);
            return;
        }
    }
    w_u8(a0 + 13, r_u8(a0 + 13) - step);
    if (r_s8(a0 + 13) > 0)
    {
        draft_scratch_release(native_stack_mark);
        return;
    }
    w_u8(a0 + 13, 0);
    w_u16(a0 + 54, r_u16(a0 + 54) + 10 * step);
    w_u8(a0 + 14, r_u8(a0 + 14) | 2);
    sub_80055228((uint32)r_s16(a0 + 54), a0 + 36);
    // TODO Bind addressable displacement through project scratch adapter
    scratch = draft_scratch_adapter(16);
    sub_8006E708(a0 + 20, target + 20, scratch);
    d = (uint32)draft_call_adapter(0x80069BE0u, r_u32(scratch), r_u32(scratch + 4));
    d = (uint32)draft_call_adapter(0x80069BE0u, d, r_u32(scratch + 8));
    if (d >= 200 * step)
        sub_80055818(a0 + 20, scratch, 150 * step);
    else
    {
        w_u32(a0 + 20, r_u32(target + 20));
        w_u32(a0 + 24, r_u32(target + 24));
        w_u8(a0 + 35, r_u8(a0 + 35) | 128);
        w_u32(a0 + 28, r_u32(target + 28));
    }

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800379FC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 a = r_u32(0x800A5C6Cu), b = r_u32(0x800A5C64u), c = r_u32(0x800A5C68u), scratch, i, v;
    int32 half;
    FUNCTION_MARKER(0x800379FCu, "1.EXE");
    w_u32(0x800A7EE0u, c);
    w_u32(0x800A9308u, b);
    w_u32(0x800A7FA8u, a);
    if (r_s16(0x800A9A64u) == 1)
    {
        half = r_s16(0x800A5C3Cu + 2 * r_u8(0x800A839Du));
        b = r_u32(0x800A9058u);
        if ((int32)a >= (int32)(b + (uint32)half) && (int32)b >= (int32)a)
        {
            w_u32(0x800A9308u, b);
            w_u32(0x800A7FA8u, b);
            w_u32(0x800A7EE0u, b + (uint32)half);
        }
    }
    // TODO Bind SDK position output through project scratch adapter
    scratch = draft_scratch_adapter(8);
    draft_call_adapter(0x8007B7B4u, r_u32(0x800A7FA8u), scratch);
    draft_call_adapter(0x8007B350u, 0u);
    for (i = 0; i < 10; i++)
    {
        v = (uint32)draft_call_adapter(0x8007B368u, 13u, 0x800A9A40u, 0u);
        w_u32(0x800A7BE0u, v);
        if (v == 1)
            break;
        draft_call_adapter(0x8007F8C8u, 3u);
    }
    for (i = 0; i < 10; i++)
    {
        v = (uint32)draft_call_adapter(0x8007B368u, 2u, scratch, 0u);
        w_u32(0x800A7BE0u, v);
        if (v == 1)
            break;
        draft_call_adapter(0x8007F8C8u, 3u);
    }
    draft_call_adapter(0x8007F8C8u, 3u);
    v = r_u16(0x800A9670u);
    w_u16(0x800A9A64u, v);
    return draft_scratch_result(native_stack_mark, (uint64)(v));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80024B28(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 v;
    int condition;
    FUNCTION_MARKER(0x80024B28u, "1.EXE");
    if ((sub_80037D8C() << 16) && !r_s16(0x800A9734u))
    {
        v = ((uint32)draft_call_adapter(0x80037D44u) & 255) << 10;
        w_u32(a0 + 504, v);
        if (v || ((int32)r_u32(a0 + 484) < 0 && r_s16(0x80010AE0u + 2 * (r_u16(a0 + 564) & 4095)) >= 0 && (int32)r_u32(a0 + 472) > 262144))
        {
            w_u32(a0 + 580, (r_u32(a0 + 580) & 0x0FFFFFFF) | 0x10000000);
            return draft_scratch_result(native_stack_mark, (uint64)(0x10000000));
        }
        v = r_u32(a0 + 580) & 0xFCFFFFFF;
        w_u32(a0 + 580, v);
        return draft_scratch_result(native_stack_mark, (uint64)(v));
    }
    condition = (int32)r_u32(a0 + 484) < 0 && r_s16(0x80010AE0u + 2 * (r_u16(a0 + 564) & 4095)) >= 0 && (int32)r_u32(a0 + 472) > 262144;
    if (!(r_u32(a0 + 580) & 0xF0000000) && !condition)
    {
        w_u32(a0 + 504, 0);
        v = r_u32(a0 + 580) & 0xFCFFFFFF;
        w_u32(a0 + 580, v);
        return draft_scratch_result(native_stack_mark, (uint64)(v));
    }
    v = r_u32(a0 + 504) + 28000;
    w_u32(a0 + 504, v);
    if ((int32)v > 262144)
    {
        w_u32(a0 + 504, 262144);
        return draft_scratch_result(native_stack_mark, (uint64)(1));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80059420(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 v, index = 0, y = 126, count;
    FUNCTION_MARKER(0x80059420u, "1.EXE");
    v = r_u32(0x800A8B30u);
    if (v == 1)
        return draft_scratch_result(native_stack_mark, (uint64)(v));
    if (r_u32(0x800A973Cu) == 1 && !r_s16(0x800A967Cu))
        draft_call_adapter(0x80033200u);
    v = (uint32)r_s16(0x800A9734u);
    if (v && v != 4)
        return draft_scratch_result(native_stack_mark, (uint64)(4));
    if (r_s16(0x800A901Cu) == 1)
        return draft_scratch_result(native_stack_mark, (uint64)(1));
    if (r_u32(0x800A9760u) == 1)
    {
        draft_call_adapter(0x80031770u);
        // TODO Recover SDK argument outputs of the preceding call during integration
        return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80044618u)));
    }
    draft_call_adapter(0x80058600u);
    for (;;)
    {
        v = (uint32)draft_call_adapter(0x8003CFECu);
        count = r_u16(0x80090EA4u + (uint32)(2 * (int32)(int16)v));
        if (index >= count)
            break;
        sub_80058430(0x808080, 0x54000040, 1, 4, 6, 105, 6, 368, 480, y, 85, 180);
        y += 2;
        index++;
    }
    sub_80059274();
    sub_8005AB3C();
    sub_800592D4();
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800433D4u, 0xFFFFFF74u, 88u, 132u, 88u)));

    draft_scratch_release(native_stack_mark);
}
