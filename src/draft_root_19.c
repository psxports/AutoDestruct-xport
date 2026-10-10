#include "draft_signatures.h"

#define D19_O r_u32(wrapper)
#define D19_H(offset) ((uint32)(int32)r_s16(D19_O + (offset)))

static uint32 draft19_angle(uint32 wrapper)
{
    uint32 point = sub_800476D8(D19_H(0xAC));
    uint32 x = ((r_u32(point) & 1023u) << 9) - r_u32(D19_O + 0x14);
    point = sub_800476D8(D19_H(0xAC));
    return sub_80055A9C(x, (((r_u32(point) >> 10) & 1023u) << 9) - r_u32(D19_O + 0x1C)) & 4095u;
}

static void draft19_route(uint32 wrapper, int rewind)
{
    int32 index = r_s16(D19_O + 0xBC);
    uint32 next;
    if (index < 0)
        index = -index;
    w_u16(D19_O + 0xAC, r_u16(r_u32(D19_O + 0x90) + (uint32)index * 2));
    w_u16(D19_O + 0xBC, r_u16(D19_O + 0xBC) + 1);
    if (r_s16(D19_O + 0xBC) >= r_s16(D19_O + 0xC0))
        w_u16(D19_O + 0xBC, 0);
    next = sub_8004AA30(D19_O);
    w_u16(D19_O + 0xAE, next);
    if (rewind)
        w_u16(D19_O + 0xBC, r_u16(D19_O + 0xBC) - 1);
    next = draft19_angle(wrapper);
    w_u16(D19_O + 0xB4, next);
    sub_800494F4(D19_O, D19_H(0xAC));
    w_u16(D19_O + 0xA8, r_u16(D19_O + 0xAE));
    w_u32(wrapper + 12, r_u32(D19_O + 0x5C));
    w_u32(wrapper + 16, r_u32(D19_O + 0x18));
    w_u32(wrapper + 20, r_u32(D19_O + 0x60));
}

static uint32 draft19_position(uint32 wrapper)
{
    uint32 point = sub_800476D8(D19_H(0xBE));
    uint32 packed = r_u32(point), position = draft_scratch_adapter(16);
    /* TODO Supply project local-vector adapter */
    w_u32(position, (packed & 1023u) << 9);
    w_u32(position + 4, 0u - (((packed >> 20) & 255u) << 8));
    w_u32(position + 8, ((packed >> 10) & 1023u) << 9);
    return position;
}

uint32 sub_8004AB4C(uint32 wrapper)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object = D19_O, point, value, state, destination, position;
    int32 i, start, trial, index;
    uint32 old;
    if (r_u16(object + 0x98) >= 11 || r_u16(object + 0x9A) >= 11)
    {
        if (r_u8(object + 0xC6) < 19)
        {
            point = sub_800476D8((uint32)(int32)r_s16(r_u32(object + 0x90) + D19_H(0xBE) * 2));
        }
        else
        {
            point = sub_800476D8(D19_H(0xBE));
            for (i = 0; i < r_s16(D19_O + 0xC0); ++i)
            {
                if (r_s16(r_u32(D19_O + 0x90) + (uint32)i * 2) == r_s16(D19_O + 0xBE))
                {
                    w_u16(D19_O + 0xBE, i);
                    w_u16(D19_O + 0xBC, i);
                    w_u16(D19_O + 0x70, 0);
                }
            }
        }
        value = (r_u32(point) & 1023u) << 9;
        object = D19_O;
        w_u32(object + 0x14, value);
        w_u32(object + 0x80, value);
        value = ((r_u32(point) >> 10) & 1023u) << 9;
        object = D19_O;
        w_u32(object + 0x1C, value);
        w_u32(object + 0x88, value);
        w_u32(D19_O + 0x18, (uint32)-30000);
        position = draft_scratch_adapter(16);
        /* TODO Supply absent terrain-height ABI adapter */
        value = 0u - (uint32)draft_call_adapter(0x8002E310u, D19_O + 0x14, position, position + 8);
        object = D19_O;
        w_u32(object + 0x18, value);
        w_u32(object + 0x84, value);
        point = r_u32(0x800A6EF4u);
        if (point)
        {
            w_u32(point, r_u32(D19_O + 0x80));
            w_u32(point + 4, r_u32(D19_O + 0x88));
            w_u32(point + 8, r_u32(D19_O + 0x84));
        }
        w_u8(D19_O + 0xC6, 8);
        object = D19_O;
        w_u16(object + 0x98, 0);
        w_u16(object + 0x9A, 0);
    }
    state = r_u8(D19_O + 0xC6);
    destination = state - 1 < 28 ? r_u32(0x800101A8u + (state - 1) * 4) : 0x8004B824u;
    /* TODO Resolve original jump-table destinations to semantic state names */
    switch (destination)
    {
        case 0x8004AD50u:
            w_u8(D19_O + 0xC7, 1);
            w_u16(D19_O + 0xAA, 5);
            w_u8(D19_O + 0xC6, 1);
            /* Fall through */
        case 0x8004AD74u:
            old = r_u16(D19_O + 0xBE);
            start = (int32)old - 1;
            w_u16(D19_O + 0xBC, start);
            if (r_s16(D19_O + 0xBC) < 0)
                w_u16(D19_O + 0xBC, 0);
            draft19_route(wrapper, 0);
            if (!sub_80049AC0(wrapper, draft19_angle(wrapper)))
            {
                if (r_u8(D19_O + 0xC6) != 11)
                    w_u8(D19_O + 0xC6, 13);
                w_u8(D19_O + 0xC7, 0);
                w_u8(D19_O + 0x57, 1);
                w_u16(D19_O + 0xAA, 5);
                w_u16(D19_O + 0x72, 0);
                /* TODO Name incidental address return left by original stores */
                return draft_scratch_result(native_stack_mark, (uint64)(D19_O));
            }
            w_u16(D19_O + 0xBE, old);
            if ((int16)start < 0)
                start = 0;
            w_u16(D19_O + 0x70, 0);
            w_u8(D19_O + 0xC7, 1);
            w_u16(D19_O + 0xBC, start);
            for (trial = (int16)start; trial < (int16)start + 4 && trial < r_s16(D19_O + 0xC0); ++trial)
            {
                draft19_route(wrapper, 1);
                if (!sub_80049AC0(wrapper, draft19_angle(wrapper)))
                {
                    w_u16(D19_O + 0xBE, r_u16(D19_O + 0xBC));
                    w_u16(D19_O + 0xBC, r_u16(D19_O + 0xBC) + 1);
                    if (r_u8(D19_O + 0xC6) != 11)
                        w_u8(D19_O + 0xC6, 13);
                    w_u8(D19_O + 0xC7, 0);
                    w_u16(D19_O + 0xAA, 5);
                    goto clear_timer;
                }
            }
            w_u8(D19_O + 0xC6, 19);
            index = (int16)old;
            if (index < 0)
                index = -index;
            w_u16(D19_O + 0xBE, r_u16(r_u32(D19_O + 0x90) + (uint32)index * 2));
            w_u16(D19_O + 0xBC, 0);
            w_u32(D19_O + 0x50, 40960);
            w_u16(D19_O + 0xAA, 65535);
            return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
        case 0x8004B28Cu:
            sub_80049648(D19_O, D19_H(0xAC), D19_H(0xAE));
            w_u8(D19_O + 0xC6, 3);
            goto normal;
        case 0x8004B2B4u:
            sub_800494F4(D19_O, D19_H(0xAE));
            point = sub_800476D8(D19_H(0xAC));
            w_u32(point + 4, r_u32(point + 4) & ~512u);
            w_u16(D19_O + 0xAC, r_u16(D19_O + 0xAE));
            value = sub_8004AA30(D19_O);
            if (r_s16(D19_O + 0xBC) <= r_s16(D19_O + 0xC0))
                w_u16(D19_O + 0xAE, value);
            if (r_u8(D19_O + 0xC6) != 11)
                w_u8(D19_O + 0xC6, 2);
            goto normal;
        case 0x8004B350u:
            state = 7;
            goto activate;
        case 0x8004B3C8u:
            /* TODO Supply absent wrapper-route ABI adapter */
            if (draft_call_adapter(0x80049D98u, wrapper))
                goto reset_route;
            goto normal;
        case 0x8004B3E0u:
            sub_80049FBC(wrapper);
            if (D19_H(0xBC) < r_u32(0x800A63E4u))
                goto normal;
            w_u16(D19_O + 0x98, r_u16(D19_O + 0x98) + 1);
            if (r_s16(D19_O + 0xAA) < 0)
            {
                w_u16(D19_O + 0x72, 120);
                w_u8(D19_O + 0x57, r_u8(D19_O + 0x57));
                w_u8(D19_O + 0xC7, 0);
                if (!r_u8(D19_O + 12))
                {
                    w_u16(D19_O + 0x98, 0);
                    w_u16(D19_O + 0x9A, 0);
                    w_u8(D19_O + 0xC6, 26);
                    goto normal;
                }
                goto reset_route;
            }
            position = draft19_position(wrapper);
            value = r_u16(D19_O + 0xAA);
            w_u16(D19_O + 0xAC, value);
            w_u16(D19_O + 0xAE, value);
            value = sub_80047788(D19_O, position);
            w_u16(D19_O + 0xAE, value);
            value = draft19_angle(wrapper);
            w_u16(D19_O + 0xB4, value);
            sub_800494F4(D19_O, D19_H(0xAC));
            w_u8(D19_O + 0xC7, 0);
            w_u16(D19_O + 0xA8, r_u16(D19_O + 0xAE));
            w_u16(D19_O + 0xAA, 5);
            w_u8(D19_O + 0x57, 1);
            w_u16(D19_O + 0x72, 0);
            w_u8(D19_O + 0xC6, 20);
            goto normal;
        case 0x8004B600u:
            sub_80049648(D19_O, D19_H(0xAC), D19_H(0xAE));
            w_u8(D19_O + 0xC6, 21);
            goto normal;
        case 0x8004B624u:
            position = draft19_position(wrapper);
            sub_800494F4(D19_O, D19_H(0xAE));
            point = sub_800476D8(D19_H(0xAC));
            w_u32(point + 4, r_u32(point + 4) & ~512u);
            value = sub_80047788(D19_O, position);
            w_u16(D19_O + 0xAC, r_u16(D19_O + 0xAE));
            w_u16(D19_O + 0xAE, value);
            if (r_s16(D19_O + 0xAC) != r_s16(D19_O + 0xBE))
            {
                w_u8(D19_O + 0xC6, 20);
                goto normal;
            }
            w_u8(D19_O + 0xC6, 1);
            for (i = 0; i < r_s16(D19_O + 0xC0); ++i)
            {
                if (r_s16(r_u32(D19_O + 0x90) + (uint32)i * 2) == r_s16(D19_O + 0xBE))
                {
                    w_u16(D19_O + 0xBE, i);
                    w_u16(D19_O + 0xBC, i);
                    w_u16(D19_O + 0x70, 0);
                    return draft_scratch_result(native_stack_mark, (uint64)(D19_O));
                }
            }
            goto normal;
        case 0x8004B77Cu:
            state = 25;
            goto activate;
        case 0x8004B7F4u:
            w_u16(D19_O + 0xBC, 0);
            w_u32(D19_O + 0x50, 40960);
            w_u16(D19_O + 0xAA, 65535);
            w_u8(D19_O + 0xC6, 28);
            goto normal;
        default:
            goto normal;
    }
activate:
    if (r_s16(wrapper + 24))
    {
        point = sub_800476D8(D19_H(0xAE));
        w_u32(point + 4, r_u32(point + 4) | 512u);
    }
    w_u16(D19_O + 0xA8, r_u16(D19_O + 0xAE));
    w_u16(D19_O + 0xAA, 5);
    w_u8(D19_O + 0xC7, 0);
    w_u8(D19_O + 0xC6, state);
    sub_80044F50(wrapper);
normal:
    state = r_u8(D19_O + 0xC6);
    value = sub_800498D4(D19_O, D19_H(0xB6));
    if (!value)
    {
        if (state < 19 && r_u8(D19_O + 0xC6) == 18)
        {
            w_u16(D19_O + 0xBC, r_u16(D19_O + 0xBE));
            w_u8(D19_O + 0xC6, 9);
            goto clear_timer;
        }
        if (state >= 19 && r_u8(D19_O + 0xC6) == 29)
        {
            w_u8(D19_O + 0x55, 2);
            w_u16(D19_O + 0x72, 0);
            w_u8(D19_O + 0x57, 1);
            goto reset_route;
        }
        w_u16(D19_O + 0x98, r_u16(D19_O + 0x98) + 1);
        w_u8(D19_O + 0xC6, state < 19 ? 18 : 29);
        w_u8(D19_O + 0x57, 255);
        w_u16(D19_O + 0x72, 120);
        return draft_scratch_result(native_stack_mark, (uint64)(120));
    }
    if (r_s16(D19_O + 0x72) > 0)
    {
        w_u16(D19_O + 0x72, r_u16(D19_O + 0x72) - r_u16(0x800A9010u));
        if (r_s16(D19_O + 0x72) <= 0)
        {
            w_u8(D19_O + 0x57, 1);
            w_u16(D19_O + 0x72, 0);
            if (state >= 19)
                goto reset_route;
            w_u8(D19_O + 0xC6, 9);
            return draft_scratch_result(native_stack_mark, (uint64)(9));
        }
    }
    value = sub_80049814(D19_O) << 16;
    if (value)
    {
        value = D19_O;
        w_u8(value + 0xC6, r_u8(0x80010100u + r_u8(value + 0xC6)));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(value));
clear_timer:
    w_u16(D19_O + 0x72, 0);
    w_u8(D19_O + 0x57, 1);
    return draft_scratch_result(native_stack_mark, (uint64)(1));
reset_route:
    w_u16(D19_O + 0xBC, 0);
    w_u32(D19_O + 0x50, 40960);
    w_u16(D19_O + 0xAA, 65535);
    w_u8(D19_O + 0xC6, 19);
    return draft_scratch_result(native_stack_mark, (uint64)(19));

    draft_scratch_release(native_stack_mark);
}

#undef D19_O
#undef D19_H
