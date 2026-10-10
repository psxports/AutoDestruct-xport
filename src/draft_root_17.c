#include "draft_signatures.h"

uint32 sub_80034CA8(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 v, target, kind, i;
    uint64 pair;
    static const uint32 masks[8] = {0xFFFF8000u, 8192, 4096, 16384, 16, 64, 2048, 256};
    FUNCTION_MARKER(0x80034CA8u, "1.EXE");
    if (!r_u32(0x800A84D4u))
        w_u32(0x800A9A68u, 0);
    draft_call_adapter(0x80078830u);
    if (r_s16(0x800A6D10u) == 2)
        return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A6D04u) == 3 ? 0xFFFFFFFE : 0xFFFFFFFF));
    sub_80034868(object);
    w_u32(0x800A6CF8u, 0);
    w_u32(0x800A6D04u, 0);
    w_u32(0x800A6D08u, 0xFFFFFFFF);
    w_u32(0x800A6CFCu, 0);
    w_u32(0x800A6CF4u, 0);
    w_u32(0x800A6C60u, 0);
    w_u32(0x800A6D28u, 0);
    w_u16(0x800A6D10u, 0);
    w_u32(0x800A6D0Cu, 0);
    w_u32(0x800A6D24u, 0);
    sub_80038964(0xFFFF);
    w_u32(0x800A902Cu, 1);
    w_u32(0x800A6C60u, 1);
    w_u32(0x800A6D1Cu, 0);
    w_u32(0x800A6D20u, 0);
    pair = sub_8006984C(0, 0, r_s16(0x800A9734u) == 3 ? 3 : 20, 0);
    w_u32(0x800A6CE4u, (uint32)pair);
    w_u32(0x800A6CE8u, (uint32)(pair >> 32));
    for (;;)
    {
        w_u32(0x800A98F4u, 0);
        sub_800697BC();
        if (r_u32(0x800A9760u) == 1)
        {
            if (r_u32(0x800A8E70u))
                goto after_initial_display;
            draft_call_adapter(0x800330E0u);
            draft_call_adapter(0x800326BCu);
            draft_call_adapter(0x80033100u);
            w_u16(0x800A6D10u, 2);
        }
        if (!r_u32(0x800A8E70u))
        {
            target = r_u32(r_u32(0x800A851Cu) + 4 * (uint32)r_s16(object));
            v = (uint32)draft_call_adapter(0x80077AC0u, target + 19, 1u, 1u, 287u);
            w_u32(0x800A6C90u, v);
        }
    after_initial_display:
        if ((int32)r_u32(0x800A9A34u) >= 40 && !r_u32(0x800A8E70u))
        {
            v = (uint32)draft_call_adapter(0x80077AC0u, r_u32(0x800A8D90u), 1u, 1u, 287u);
            w_u32(0x800A6C90u, v);
            w_u16(0x800A6D10u, 2);
        }
        v = r_u32(0x800A8690u) == 2 ? 1 : (uint32)draft_call_adapter(0x8005CC60u, 0x800A7E54u);
        w_u32(0x800A6D18u, v);
        draft_call_adapter(0x800345B0u, object);
        if (r_u32(0x800A8690u) == 2)
        {
            sub_8002DC94();
            sub_80022A68(0);
            v = r_u32(0x800A622Cu);
            if (v)
            {
                target = r_u32(r_u32(0x800A851Cu) + 4 * (uint32)r_s16(r_u32(object + 8)));
                w_u32(0x800A9A58u, v);
                kind = r_u8(target + 13);
                if (kind && (kind >= 9 || kind < 7))
                    draft_call_adapter(0x8005CC60u, 0x800A7E54u);
                else
                    draft_call_adapter(0x8005DC0Cu, 0x800A7E54u);
            }
        }
        else
        {
            sub_8002DC94();
            v = r_u32(0x800A7E04u);
            if (!v)
            {
                sub_80022A68(3);
                v = r_u32(0x800A7E04u);
            }
            if (v == 1)
                sub_80022A68(3);
            if (r_u32(0x800A7E04u) == 2)
                sub_80022A68(0);
        }
        draft_call_adapter(0x80021718u, 0x800A7EE4u, 1u);
        sub_8005E31C();
        sub_8005E7DC();
        draft_call_adapter(0x80020E30u);
        draft_call_adapter(0x8001F690u);
        draft_call_adapter(0x8001F968u);
        sub_80036BE4();
        for (i = 0; i < 8; i++)
        {
            v = (uint32)(int16)sub_80038970(masks[i]);
            w_u32(0x800A6D14u, i ? r_u32(0x800A6D14u) + v : v);
        }
        draft_call_adapter(0x8003438Cu, object);
        draft_call_adapter(0x8001FF7Cu, 1u);
        draft_call_adapter(0x8001F850u);
        sub_8005A944();
        v = r_u32(0x800A6C60u);
        if (v)
            w_u32(0x800A6C60u, v - 1);
        else
            draft_call_adapter(0x8007FED0u, 1u);
        pair = ((uint64)r_u32(0x800A6D20u) << 32) | r_u32(0x800A6D1Cu);
        pair = sub_80069974(pair);
        w_u32(0x800A6D1Cu, (uint32)pair);
        w_u32(0x800A6D20u, (uint32)(pair >> 32));
        if (!r_u32(0x800A6D24u))
        {
            v = r_u32(0x800A6D20u);
            target = r_u32(0x800A6CE8u);
            if (((int32)v > (int32)target || (v == target && r_u32(0x800A6D1Cu) >= r_u32(0x800A6CE4u))) && r_s16(0x800A9734u) && r_s16(0x800A9A64u) == 1)
                w_u32(0x800A6D0Cu, 1);
            else if (sub_80034264() == 0xFFFFFFFF)
            {
                if ((int32)r_u32(0x800A9A34u) < 40 && (r_u32(0x800A9760u) != 1 || r_u32(0x800A8E70u) || r_u32(0x800A84D4u)))
                {
                    w_u32(0x800A6D0Cu, 0);
                    break;
                }
                w_u32(0x800A6D0Cu, 1);
            }
            if (r_u32(0x800A6D0Cu) == 1)
                w_u32(0x800A6D24u, 1);
        }
        if (r_u32(0x800A6D24u) == 1)
        {
            draft_call_adapter(0x800205C8u, 0u, 6u, 0u);
            w_u32(0x800A6D24u, 2);
        }
        if (r_u32(0x800A6D24u) == 2 && r_u8(0x800A7BDFu) && !r_u32(0x800A562Cu))
        {
            w_u16(0x800A6D10u, 2);
            break;
        }
    }
    sub_80034C88();
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

static int32 draft17_mul12(int32 a, int32 b)
{
    return (int32)((uint32)a * (uint32)b) >> 12;
}

uint32 sub_8005ABD8(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 angle, font, glyph, i, j, o, type, uv, offset, result;
    int32 sine, cosine, x, y, rx, ry;
    FUNCTION_MARKER(0x8005ABD8u, "1.EXE");
    // TODO Bind polygon SDK boundaries using real MIPS argument counts
    angle = (0 - (r_u32(0x800A8518u) + 2048)) & 4095;
    draft_call_adapter(0x80041C9Cu, 0x800A7460u, 0x54000040u, 3u, 3u, 6u, 68u, 31u, 352u, 480u);
    draft_call_adapter(0x80041DB4u, 0x800A7460u, 0xFFFFFF8Cu, 49u, 0u);
    draft_call_adapter(0x80041D90u, 0x800A7460u, 32768u);
    draft_call_adapter(0x80020AB4u, 0x800A7460u, r_u32(0x800A9A74u) + 600, 1u, 0u);
    sine = r_s16(0x800102E0u + 2 * angle);
    cosine = r_s16(0x80010AE0u + 2 * angle);
    for (i = 0; i < 4; i++)
    {
        x = r_s8(0x80091039u + 3 * i);
        y = r_s8(0x8009103Au + 3 * i);
        glyph = 5 * r_u8(r_u32(0x800A8D74u) + r_u8(0x80091038u + 3 * i));
        rx = (int32)((uint32)draft17_mul12(x, cosine) - (uint32)draft17_mul12(y, sine));
        ry = (int32)((uint32)draft17_mul12(x, sine) + (uint32)draft17_mul12(y, cosine));
        font = r_u32(0x800A5F68u) + glyph;
        draft_call_adapter(0x80041C9Cu, 0x800A7460u, 0x54000040u, (uint32)r_u8(font + 2), (uint32)r_u8(font + 3), 13u, (uint32)r_u8(font), (uint32)r_u8(font + 1), (uint32)r_s16(0x800903C4u + 2 * r_u8(font + 4)), 481u);
        draft_call_adapter(0x80041D90u, 0x800A7460u, 28784u);
        draft_call_adapter(0x80041DB4u, 0x800A7460u, (uint32)rx - 120, (uint32)ry + 44, 0u);
        draft_call_adapter(0x80020AB4u, 0x800A7460u, r_u32(0x800A9A74u) + 760, 1u, 0u);
        font = r_u32(0x800A5F68u) + glyph;
        draft_call_adapter(0x80041C9Cu, 0x800A7460u, 0x64000040u, (uint32)r_u8(font + 2), (uint32)r_u8(font + 3), 13u, (uint32)r_u8(font), (uint32)r_u8(font + 1), (uint32)r_s16(0x800903C4u + 2 * r_u8(font + 4)), 481u);
        draft_call_adapter(0x80041D90u, 0x800A7460u, 0x808080u);
        draft_call_adapter(0x80041DB4u, 0x800A7460u, (uint32)rx - 119, (uint32)ry + 45, 0u);
        draft_call_adapter(0x80020AB4u, 0x800A7460u, r_u32(0x800A9A74u) + 760, 1u, 0u);
    }
    w_u32(0x800A7458u, (uint32)((int32)r_u32(0x800A7E14u) / 512) - 28);
    result = (uint32)((int32)r_u32(0x800A7E20u) / 512);
    w_u32(0x800A745Cu, 611 - result);
    if (!r_u32(0x800A5690u))
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    for (i = 0, offset = 0;; offset += 4)
    {
        o = r_u32(r_u32(0x800A568Cu) + offset);
        type = r_u8(o + 13);
        if (r_u8(o + 12) >= 4 && !(type & 128) && (type & 15) >= 8)
            draft_call_adapter(0x8006E2B8u, o);
        o = r_u32(r_u32(0x800A568Cu) + offset);
        x = (int32)((uint32)((int32)r_u32(o + 20) / 512) - r_u32(0x800A7458u));
        y = (int32)(639 - r_u32(0x800A745Cu) - (uint32)((int32)r_u32(o + 28) / 512));
        ++i;
        if (x < 56 && y < 56 && x >= 0 && y >= 0)
        {
            x -= 28;
            y -= 28;
            rx = (int32)((uint32)draft17_mul12(x, cosine) - (uint32)draft17_mul12(y, sine));
            ry = (int32)((uint32)draft17_mul12(x, sine) + (uint32)draft17_mul12(y, cosine));
            for (j = 0; j < 2; j++)
            {
                o = r_u32(r_u32(0x800A568Cu) + offset);
                uv = r_u8(0x80090F90u + (r_u8(o + 13) & 15));
                draft_call_adapter(0x80041C9Cu, 0x800A7460u, j ? 0x64000040u : 0x54000040u, 4u, 4u, 6u, (uint32)r_u8(0x80091008u + 2 * uv), (uint32)r_u8(0x80091009u + 2 * uv), 352u, 480u);
                draft_call_adapter(0x80041DB4u, 0x800A7460u, (uint32)rx - 116, (uint32)ry + 49, 0u);
                if (!j)
                {
                    o = r_u32(r_u32(0x800A568Cu) + offset);
                    draft_call_adapter(0x80041D90u, 0x800A7460u, r_u32(0x80090FA8u + 4 * (r_u8(o + 13) & 15)));
                }
                draft_call_adapter(0x80020AB4u, 0x800A7460u, r_u32(0x800A9A74u) + 600, 1u, 0u);
            }
        }
        result = i < r_u32(0x800A5690u);
        if (!result)
            break;
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005CC60(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch, flags, transition = 0, done = 0, v, step;
    int32 state, rate, angle;
    uint32 movement;
    FUNCTION_MARKER(0x8005CC60u, "1.EXE");
    // TODO Bind local vectors and matrix through project scratch adapter
    scratch = draft_scratch_adapter(80);
    draft_call_adapter(0x8005B2ACu, 0x800A8808u, 0x800A87FCu, scratch);
    angle = (int32)draft_call_adapter(0x80055A9Cu, r_u32(scratch), r_u32(scratch + 8));
    rate = (int32)sub_8005B364(scratch);
    step = r_u32(0x800A9010u);
    w_u16(scratch + 16, 0);
    w_u16(scratch + 18, 0);
    w_u16(scratch + 20, (0 - step) * (uint32)r_s16(0x800A8814u));
    draft_call_adapter(0x800551CCu, (uint32)angle, scratch + 24);
    draft_call_adapter(0x80031B6Cu, scratch + 24, scratch + 16, scratch + 48);
    w_u16(scratch + 72, r_u16(0x800A563Cu) << 15);
    draft_call_adapter(0x8002E310u, 0x800A8808u, scratch + 64, scratch + 72);
    w_u32(0x800A563Cu, r_u16(scratch + 72) >> 15);
    flags = (uint32)draft_call_adapter(0x80030214u, 0x800A8808u, 0x800A87FCu) & 3;
    w_u16(scratch + 72, 0);
    draft_call_adapter(0x8002E310u, 0x800A7EE4u, scratch + 64, scratch + 72);
    flags |= (r_u16(scratch + 72) >> 14) != 0;
    state = r_s16(0x800A8816u);
    switch (state)
    {
        case -1:
            w_u8(object + 48, 0);
            w_u16(object + 40, r_u16(object + 118));
            sub_8005E114(flags & 1 ? 1 : 2, 10000);
            w_u16(0x800A8816u, 665);
            transition = 1;
            break;
        case 0:
            w_u8(object + 48, 0);
            w_u16(object + 40, r_u16(object + 118));
            if (r_u32(0x800A8808u) == r_u32(0x800A87FCu) && r_u32(0x800A880Cu) == r_u32(0x800A8800u) && r_u32(0x800A8810u) == r_u32(0x800A8804u))
            {
                sub_8005E114(flags & 1 ? 1 : 2, 50);
                w_u16(0x800A8816u, 665);
            }
            else
                w_u16(0x800A8816u, r_u8(0x80091054u + flags));
            break;
        case 1:
            sub_8005E114(3, 50);
            if (rate == -1 || r_u32(0x800A9A38u) == 1)
                w_u16(0x800A8816u, 10);
            else
            {
                w_u16(0x800A8816u, 2);
                w_u8(object + 45, 255);
            }
            break;
        case 2:
            if (draft_call_adapter(0x8005CC34u, object))
                w_u16(0x800A8816u, 3);
            break;
        case 3:
            v = (uint32)draft_call_adapter(0x8005B32Cu, (uint32)r_s16(0x800A8814u), (uint32)rate, 10u);
            w_u16(0x800A8814u, v);
            movement = (uint32)((int32)(12800u * (uint32)((int32)r_u32(0x800A63D8u) >> 8)) >> 16);
            v = (uint32)draft_call_adapter(0x8005B32Cu, r_u32(0x800A880Cu), r_u32(0x800A8800u), movement);
            w_u32(0x800A880Cu, v);
            if (!rate)
                w_u16(0x800A8816u, 4);
            break;
        case 4:
            sub_8005E114((uint32)r_s16(0x800A881Au), 50);
            w_u16(0x800A8816u, 5);
            break;
        case 5:
            if (draft_call_adapter(0x8005CC34u, object))
                w_u16(0x800A8816u, 665);
            break;
        case 10:
        case 21:
        case 41:
        case 61:
            if (!r_u8(0x800A7BDCu))
            {
                draft_call_adapter(0x800205C8u, 210u, 6u, 2u);
                w_u16(0x800A8816u, state + 1);
                w_u16(0x800A8818u, 64);
            }
            else if (r_u8(0x800A7BDFu) == 1)
            {
                w_u16(0x800A8816u, state + 2);
                w_u16(0x800A8818u, 0);
            }
            break;
        case 11:
        case 22:
        case 42:
        case 62:
            v = r_u16(0x800A8818u) - r_u16(0x800A9010u);
            w_u16(0x800A8818u, v);
            if ((int16)v < 0)
                w_u16(0x800A8816u, state + 1);
            break;
        case 12:
            draft_call_adapter(0x800205C8u, 210u, 6u, 3u);
            sub_8005CB7C();
            w_u16(0x800A8816u, 4);
            break;
        case 20:
            w_u16(0x800A8816u, 21);
            break;
        case 23:
            sub_8005CB7C();
            w_u16(0x800A8816u, 233);
            break;
        case 24:
            sub_8005E114((uint32)r_s16(0x800A881Au), 50);
            w_u16(0x800A8816u, 25);
            break;
        case 25:
        case 44:
            draft_call_adapter(0x800205C8u, 210u, 6u, 3u);
            w_u16(0x800A8816u, 665);
            break;
        case 40:
            sub_8005E114(3, 50);
            w_u16(0x800A8816u, 41);
            break;
        case 43:
            sub_8005CB7C();
            w_u16(0x800A8816u, 433);
            break;
        case 60:
            w_u16(0x800A8816u, 61);
            break;
        case 63:
            w_u16(0x800A8816u, 43);
            break;
        case 233:
            sub_8005E114(3, 10000);
            w_u16(0x800A8816u, 24);
            transition = 1;
            break;
        case 433:
            sub_8005E114(1, 10000);
            transition = 1;
            w_u16(0x800A8816u, 44);
            break;
        case 665:
            if (r_u8(0x800A7BDFu))
                w_u16(0x800A8816u, r_u8(0x800A7BDCu) ? 44 : 666);
            break;
        case 666:
            done = 1;
            break;
        default:
            break;
    }
    w_u32(0x800A8808u, r_u32(0x800A8808u) + r_u32(scratch + 48));
    w_u32(0x800A8810u, r_u32(0x800A8810u) + r_u32(scratch + 56));
    if ((!flags || r_u32(0x800A9A38u) == 4) && r_u32(object + 28) == 0xFF060000u && r_s16(object + 32) == 600)
    {
        w_u16(object + 30, (uint16)-400);
        w_u16(object + 28, 0);
        w_u16(object + 32, 600);
    }
    sub_8005D5A8(object, 0x800A8808u, 0, transition);
    sub_8005BEEC(object);
    return draft_scratch_result(native_stack_mark, (uint64)(done));

    draft_scratch_release(native_stack_mark);
}
