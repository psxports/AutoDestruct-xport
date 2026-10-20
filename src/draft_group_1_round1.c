#include "psx.h"
#include "draft_signatures.h"
#include "native_debug_memory.h"
#include <stdlib.h>

// FUNCTION_MARKER sub_80059400
uint32 sub_80059400(void)
{
    uint32 native_stack_mark = draft_scratch_mark();
    return draft_scratch_result(native_stack_mark, (uint64)(sub_80057DD8()));
    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80025874
uint32 sub_80025874(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 value = (uint32)(sint32)(sint16)a1;
    if ((sint16)a3 == 1)
        return draft_scratch_result(native_stack_mark, (uint64)(r_u8(a2 + 8u) == value || r_u8(a2 + 9u) == value || r_u8(a2 + 10u) == value || r_u8(a2 + 11u) == value));
    if (r_u8(a2 + 8u) != value)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    return draft_scratch_result(native_stack_mark, (uint64)(r_u8(a2 + 9u) == value && r_u8(a2 + 10u) == value && r_u8(a2 + 11u) == value));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006F1D0
uint32 sub_8006F1D0(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result;
    // TODO Bind original BIOS and SDK targets
    // Deliver elapsed interrupts before clearing the flag for a new wait
    psx_native_poll_events();
    draft_call_adapter(0x800796DCu);
    w_u32(0x800A8550u, 0u);
    result = (uint32)draft_call_adapter(0x80079C20u);
    if (a1 == 0u)
    {
        // Service native interrupts while waiting for the VBlank callback
        while (r_u32(0x800A8550u) == 0u)
        {
            if (VSync(0) < 0)
                abort();
        }
        result = 0u;
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80064CEC
uint32 sub_80064CEC(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 old = r_u32(0x800A7484u), next = old + 1u, result;
    native_debug_heap_event(2, a1, 0);
    w_u32(0x800AA6A8u + old * 4u, a1);
    w_u32(0x800A7484u, next);
    if (next == 2048u)
        w_u32(0x800A7484u, 0u);
    next = r_u32(0x800A7484u);
    result = next - 1u;
    if (next == r_u32(0x800A7488u))
    {
        w_u32(0x800A7484u, result);
        // TODO Bind original target 0x80064E78
        draft_call_adapter(0x80064E78u);
        result = r_u32(0x800A7484u) + 1u;
        w_u32(0x800A7484u, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80044534
uint32 sub_80044534(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    return draft_scratch_result(native_stack_mark, (uint64)((uint32)sub_800442FC(0u, r_u32(0x800A5F68u), a1, a2, (uint32)(sint32)(sint16)a3, (uint32)(sint32)(sint16)a4, 150u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80045E18
uint32 sub_80045E18(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 mode = (sint16)r_u16(0x800A9734u);
    if (mode == 0)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    if (mode == 1)
    {
        sub_80030F08((uint32)(sint32)(sint16)r_u16(a2 + 4u), (uint32)(sint32)(sint16)r_u16(a1 + 68u), 2u);
        w_u16(a2 + 4u, 0xFFFFu);
    }
    else if (mode == 2)
    {
        sub_80030F08((uint32)(sint32)(sint16)r_u16(a2 + 6u), (uint32)(sint32)(sint16)r_u16(a1 + 68u), 3u);
        w_u16(a2 + 6u, 0xFFFFu);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(0x800A9760u) == 0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8004510C
uint32 sub_8004510C(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = (uint32)(sint32)(sint16)r_u16(0x800A9A78u);
    if ((sint16)r_u16(0x800A9014u) <= 0 && result != 0u)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    result = a2 << 16;
    if ((sint16)a2 < 0)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    result = (sint16)r_u16(0x800A7F3Eu) < (sint16)a2;
    if (result != 0u)
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    {
        uint32 player = r_u32(0x800A7BACu);
        // TODO Bind original target 0x80069BE0
        result = (uint32)draft_call_adapter(0x80069BE0u, r_u32(player + 20u) - r_u32(a1), r_u32(player + 28u) - r_u32(a1 + 8u));
    }
    if ((sint32)result < (sint32)r_u32(0x800A6EE0u))
    {
        w_u32(0x800A6EE0u, result);
        w_u16(0x800A9A78u, a2);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005603C
uint32 sub_8005603C(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 angle = r_u16(a1 + 76u) & 0xFFFu, offset = 500u * r_u32(0x800A6224u), tile = r_u32(0x800A84FCu) + a2 * 8u;
    uint32 cosine = (uint32)(sint32)(sint16)r_u16(0x800102E0u + angle * 2u), sine = (uint32)(sint32)(sint16)r_u16(0x80010AE0u + angle * 2u), result;
    w_u32(a1 + 68u, ((r_u32(tile) & 0x3FFu) << 9) + (uint32)((sint32)((uint32)-900 * cosine + offset * sine) >> 12));
    angle = r_u16(a1 + 76u) & 0xFFFu;
    cosine = (uint32)(sint32)(sint16)r_u16(0x800102E0u + angle * 2u);
    sine = (uint32)(sint32)(sint16)r_u16(0x80010AE0u + angle * 2u);
    result = (((r_u32(tile) >> 10) & 0x3FFu) << 9) + (uint32)((sint32)((uint32)-900 * sine - offset * cosine) >> 12);
    w_u32(a1 + 72u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006F58C
uint32 sub_8006F58C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 masks[10] = {4096u, 0x4000u, 0xFFFF8000u, 0x2000u, 16u, 64u, 128u, 32u, 2048u, 256u}, result = 0u;
    for (uint32 index = 0u; index < 10u; ++index)
    {
        // TODO Bind original target 0x80038970
        result |= (uint32)(sint32)(sint16)(uint32)draft_call_adapter(0x80038970u, masks[index]);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80049814
uint32 sub_80049814(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    // TODO Bind original target 0x80069BE0
    sint32 distance = (sint32)(uint32)draft_call_adapter(0x80069BE0u, r_u32(a1 + 92u) - r_u32(a1 + 20u), r_u32(a1 + 96u) - r_u32(a1 + 28u));
    uint32 limit = ((uint32)draft_call_adapter(0x80069BE0u, r_u32(a1 + 100u), r_u32(a1 + 104u)) * r_u32(0x800A9010u)) >> 4;
    if ((sint32)limit < 256)
        limit = 256u;
    if ((sint32)limit >= 2049)
        limit = 2048u;
    {
        uint32 kind = r_u8(a1 + 198u);
        if (kind == 2u || kind == 13u)
            limit += 1280u;
    }
    return draft_scratch_result(native_stack_mark, (uint64)(distance < (sint32)limit));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800283D4
uint32 sub_800283D4(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 position = draft_scratch_adapter(12u), tag = draft_scratch_adapter(8u), normal = draft_scratch_adapter(8u), height, material;
    uint32 half_height = (uint32)((sint32)(r_u16(r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u)) + 32u) << 16) >> 17);
    w_u32(position, r_u32(a1 + 20u));
    w_u32(position + 8u, r_u32(a1 + 28u));
    w_u32(position + 4u, r_u32(a1 + 24u) - 256u + half_height);
    // TODO Bind original target 0x8002E310
    height = 0u - (uint32)draft_call_adapter(0x8002E310u, position, normal, tag);
    material = (uint32)(sint32)(sint16)r_u16(tag);
    for (uint32 index = 0u; index < 4u; ++index)
        if (r_u16(a3 + 2u * index) != 0u)
            w_u16(a2 + 16u * index + 4u, material == 6u ? height : 0u - r_u16(a3 + index * 2u));
    return draft_scratch_result(native_stack_mark, (uint64)(4u << 16));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8004BAA4
uint32 sub_8004BAA4(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = 0u;
    for (sint32 index = 0; (sint16)index < (sint16)r_u16(0x800A6094u); ++index)
    {
        uint32 entry = 0x800A8930u + (uint32)(sint32)(sint16)index * 4u, object = r_u32(entry);
        if ((sint16)r_u16(a1 + 70u) != (sint16)r_u16(object + 70u) && r_u8(object + 64u) != 0u)
        {
            // TODO Bind original target 0x80069BE0
            sint32 distance = (sint32)(uint32)draft_call_adapter(0x80069BE0u, r_u32(object + 20u) - r_u32(a1 + 20u), r_u32(object + 28u) - r_u32(a1 + 28u));
            if (distance < (sint32)a2 && (sub_8002EAE4(r_u32(entry) + 20u, a1 + 20u, 0u) << 16) != 0u)
            {
                a2 = (uint32)distance;
                result = r_u32(entry);
            }
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80070568
uint32 sub_80070568(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 buttons = sub_8006F58C(), result;
    sub_80070634();
    sub_8006F950(r_u32(0x800A645Cu));
    sub_8006FB78();
    sub_80071DC8(r_u32(0x800A645Cu));
    result = sub_80070788(r_u32(0x800A6464u));
    if (result != 0u)
    {
        sub_800389DC();
        sub_8006F338();
        sub_800707D4(buttons);
        // TODO Bind original targets 0x800703B4 and 0x8006FCB4
        if ((buttons & 16u) != 0u)
            draft_call_adapter(0x800703B4u);
        result = buttons & 64u;
        if ((buttons & 2048u) != 0u && sub_80070788(r_u32(0x800A6464u)) == 0u)
            sub_8007040C();
        if (result != 0u)
            result = (uint32)draft_call_adapter(0x8006FCB4u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80021368
uint32 sub_80021368(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 packet;
    // TODO Bind original SDK targets 0x800836DC and 0x8008358C
    draft_call_adapter(0x800836DCu, (uint32)(sint32)(sint16)r_u16(0x800A821Cu), (uint32)(sint32)(sint16)r_u16(0x800A821Eu));
    draft_call_adapter(0x8008358Cu, (uint32)(sint32)(sint16)r_u16(0x800A821Au));
    packet = sub_800213F4(r_u32(0x800A9A74u), r_u32(0x800A865Cu), (uint32)(sint32)(sint16)r_u16(0x800A8220u), (uint32)(sint32)(sint16)r_u16(0x800A8222u), (uint32)(sint32)(sint16)r_u16(0x800A8224u), (uint32)(sint32)(sint16)r_u16(0x800A8226u));
    w_u32(0x800A865Cu, packet);
    packet = sub_800214C8(r_u32(0x800A9A74u), packet);
    w_u32(0x800A865Cu, packet);
    return draft_scratch_result(native_stack_mark, (uint64)(packet));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80037864
uint32 sub_80037864(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result, location, retry;
    if ((sint32)r_u32(0x800A966Cu) > 0)
    {
        result = r_u32(0x800A966Cu) - r_u32(0x800A9010u);
        w_u32(0x800A966Cu, result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    retry = r_u32(0x800A87F0u);
    location = draft_scratch_adapter(8u);
    // TODO Bind original CD SDK targets 0x8007B368, 0x8007B8B8 and 0x8007B7B4
    if (retry == 0u)
    {
        uint32 status = draft_scratch_adapter(8u);
        result = (uint32)draft_call_adapter(0x8007B368u, 16u, 0u, status);
        w_u32(0x800A7BE0u, result);
        if (result != 1u)
            return draft_scratch_result(native_stack_mark, (uint64)(1u));
        result = (uint32)draft_call_adapter(0x8007B8B8u, status);
        w_u32(0x800A7FA8u, result);
        if ((sint32)result < (sint32)r_u32(0x800A7EE0u))
            return draft_scratch_result(native_stack_mark, (uint64)(1u));
    }
    {
        uint32 start = r_u32(0x800A9058u), duration = (uint32)(sint32)(sint16)r_u16(0x800A5C3Cu + 2u * r_u8(0x800A9A41u));
        w_u32(0x800A9308u, start);
        w_u32(0x800A7FA8u, start);
        w_u32(0x800A7EE0u, start + duration);
        result = (uint32)draft_call_adapter(0x8007B7B4u, start, location);
        w_u32(0x800A7FA8u, result);
    }
    result = (uint32)draft_call_adapter(0x8007B368u, 6u, location, 0u);
    w_u32(0x800A7BE0u, result);
    if (result == 1u)
        w_u32(0x800A87F0u, 0u);
    else if (retry == 0u)
        w_u32(0x800A87F0u, 1u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006A0A0
uint32 sub_8006A0A0(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 count = r_u32(r_u32(0x800A84FCu) + 8u * a1 + 4u) & 15u, first, selected;
    if (count == 0u)
        return draft_scratch_result(native_stack_mark, (uint64)(a2));
    // TODO Bind original target 0x80069A50
    first = sub_80069A50() % count;
    selected = first;
    for (uint32 pass = 0u; pass < 2u; ++pass)
    {
        uint32 index = pass == 0u ? first : 0u, end = pass == 0u ? count : first;
        while (index < end)
        {
            uint32 candidate = sub_80069D8C(a1, index);
            if (candidate != a2)
            {
                uint32 flags = r_u32(r_u32(0x800A84FCu) + candidate * 8u + 4u);
                if ((flags & 0x400u) == 0u)
                {
                    uint32 link = (uint32)((sint32)flags >> 11) + index;
                    uint32 connection = r_u32(r_u32(0x800A7E2Cu) + (link << 2));
                    selected = candidate;
                    if ((connection >> 12) == 0xFFFFFu && (flags & 0x300u) == 0u)
                        return draft_scratch_result(native_stack_mark, (uint64)(candidate));
                }
            }
            ++index;
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(selected));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8004C8F4
uint32 sub_8004C8F4(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 angle = r_u16(a1 + 182u) & 0xFFFu, x = r_u32(a2), z = r_u32(a2 + 8u);
    sint32 dx = (sint32)((x - r_u32(a1 + 100u)) << 8) >> 8, dz = (sint32)((z - r_u32(a1 + 104u)) << 8) >> 8;
    sint32 cosine = (sint16)r_u16(0x800102E0u + 2u * angle) >> 4, sine = (sint16)r_u16(0x80010AE0u + 2u * angle) >> 4;
    uint32 forward = (uint32)((sint32)((uint32)dx * (uint32)cosine + (uint32)dz * (uint32)sine) >> 11), lateral = (uint32)((sint32)((uint32)dx * (uint32)sine - (uint32)dz * (uint32)cosine) >> 10), result;
    // TODO Bind original target 0x80069BE0
    if ((uint32)draft_call_adapter(0x80069BE0u, x, z) >= 4097u)
    {
        forward += (uint32)((sint16)r_u16(0x800102E0u + 2u * (r_u16(a1 + 108u) & 0xFFFu)) >> 9);
        lateral += (uint32)((sint16)r_u16(0x800102E0u + 2u * (r_u16(a1 + 110u) & 0xFFFu)) >> 9);
    }
    w_u16(a1 + 108u, r_u16(a1 + 108u) + ((16128u * (uint32)((sint32)r_u32(0x800A63D8u) >> 8)) >> 16));
    w_u16(a1 + 110u, r_u16(a1 + 110u) + ((19712u * (uint32)((sint32)r_u32(0x800A63D8u) >> 8)) >> 16));
    // TODO Bind original target 0x80055764
    result = (uint32)draft_call_adapter(0x80055764u, (uint32)(sint32)(sint16)r_u16(a1 + 186u), forward, 4u);
    w_u16(a1 + 186u, result);
    result = (uint32)draft_call_adapter(0x80055764u, (uint32)(sint32)(sint16)r_u16(a1 + 184u), lateral, 4u);
    w_u16(a1 + 184u, result);
    {
        sint32 value = (sint16)r_u16(a1 + 186u), absolute = value < 0 ? -value : value;
        result = absolute < 61;
        if (result == 0u)
        {
            result = value < 0 ? (uint32)-60 : 60u;
            w_u16(a1 + 186u, result);
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80040F94
uint32 sub_80040F94(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 first = draft_scratch_adapter(24u), second = first + 12u, i, angle, value;
    sint32 distance;
    for (i = 0; i < 12; i += 4)
    {
        value = r_u32(object + 20u + i);
        w_u32(first + i, value);
        w_u32(second + i, value);
    }
    value = r_u16(object + 446u);
    if (value)
    {
        w_u16(object + 448u, value);
        w_u16(object + 446u, 0);
    }
    angle = r_u16(object + 448u) & 4095u;
    w_u32(second, r_u32(second) + (uint32)((sint16)r_u16(0x800102E0u + angle * 2u) >> 1));
    w_u32(second + 8u, r_u32(second + 8u) + (uint32)((sint16)r_u16(0x80010AE0u + angle * 2u) >> 1));
    if (sub_8002F3FC(first, second) << 16)
    {
        value = sub_80055A9C(r_u32(first), r_u32(first + 8u));
        w_u16(object + 446u, value);
        sub_80069A50();
        value = r_u16(object + 446u);
        w_u16(object + 446u, value - 1024u);
        if ((uint16)(value - 1024u) == 0)
            w_u16(object + 446u, value - 1023u);
    }
    // TODO Bind original target 0x80069BE0
    distance = (sint32)draft_call_adapter(0x80069BE0u, r_u32(second) - r_u32(object + 20u), r_u32(second + 8u) - r_u32(object + 28u));
    w_u16(object + 444u, distance > 32767 ? 32767u : (uint32)distance);
    return draft_scratch_result(native_stack_mark, (uint64)(distance > 32767));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8004E53C
uint32 sub_8004E53C(uint32 object, uint32 a2, uint32 a3, uint32 enabled)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 desired = (a2 + a3) << 10, result;
    sint32 amount, distance, rate, factor;
    if (r_u32(object + 292u) != desired)
    {
        amount = (sint32)(desired - r_u32(object + 280u) + 512u) >> 10;
        w_u32(object + 292u, desired);
        if (amount < 0)
            amount = -amount;
        w_u32(object + 288u, (uint32)amount * (enabled ? 4u : 2u));
    }
    // TODO Bind original target 0x80069BE0
    result = (uint32)draft_call_adapter(0x80069BE0u, r_u32(object + 100u), r_u32(object + 104u));
    distance = (sint32)result;
    rate = (sint32)r_u32(object + 288u);
    if (rate > 0)
    {
        if (distance < 2048 && enabled)
            factor = rate >= 1360 ? 16 : 15 * rate / 1360 + 1;
        else
        {
            result = distance < 10240;
            if (enabled)
                return draft_scratch_result(native_stack_mark, (uint64)(result));
            factor = distance >= 10240 ? 32 : (sint32)((uint32)distance << 4) / 10240 + 16;
        }
        // TODO Bind original target 0x8006B198
        uint32 tick = (uint32)((sint32)(r_u32(0x800A63D8u) + 512u) >> 10);
        uint32 step = tick * (uint32)factor + 32;
        result = (uint32)draft_call_adapter(0x8006B198u, object + 280u, (uint32)((sint32)step >> 6));
        w_u32(object + 24u, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800369E0
uint32 sub_800369E0(uint32 position, uint32 status, uint32 volume, uint32 sample)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 voice = -1, index;
    uint32 record, hardware, mask, value;
    if (r_s16(0x800A7BECu) != 1u || (sint8)r_u8(status) >= 0)
        return draft_scratch_result(native_stack_mark, (uint64)(0xffffffffu));
    // TODO Bind original target 0x80086EE4
    for (index = 14; index < 24; ++index)
    {
        value = (uint32)draft_call_adapter(0x80086EE4u, 1u << index);
        if (value == 0u || value == 3u)
        {
            voice = index;
            break;
        }
    }
    if (voice < 0)
        return draft_scratch_result(native_stack_mark, (uint64)(0xffffffffu));
    record = 0x800A7C78u + (uint32)voice * 16u;
    hardware = 0x800BBEFCu + (uint32)voice * 64u;
    w_u16(record, volume);
    w_u32(record + 8u, position);
    w_u32(record + 12u, status);
    w_u8(status, (uint32)voice);
    w_u32(hardware + 4u, 147u);
    w_u16(hardware + 20u, volume);
    value = r_u32(0x800A7FC0u + (uint32)(sint32)(sint16)sample * 8u);
    w_u32(hardware + 32u, value);
    value = r_u32(0x800A7FC0u + (uint32)(sint32)(sint16)sample * 8u);
    mask = 1u << voice;
    w_u32(hardware, mask);
    w_u16(hardware + 8u, 0);
    w_u16(hardware + 10u, 0);
    w_u32(hardware + 28u, value);
    if ((sint16)sub_80036434(r_u32(record + 8u), (uint32)voice) == -1)
    {
        w_u8(status, 254u);
        w_u32(record + 12u, 0x800A7DFCu);
        return draft_scratch_result(native_stack_mark, (uint64)(0xfffffffeu));
    }
    // TODO Bind original sound SDK targets
    draft_call_adapter(0x80086EBCu, hardware);
    draft_call_adapter(0x800899C0u, 1u, mask);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)(sint32)(sint8)voice));

    draft_scratch_release(native_stack_mark);
}

static sint32 draft11_div(sint32 n, sint32 d);

static uint32 draft11_image(uint32 rect, uint32 x, uint32 width, uint32 source)
{
    w_u16(rect, x);
    w_u16(rect + 4u, width);
    // TODO Bind original DrawSync and LoadImage SDK targets
    draft_call_adapter(0x8007FF6Cu, 0u);
    return (uint32)draft_call_adapter(0x80080230u, rect, source);
}

// FUNCTION_MARKER sub_80057DD8
uint32 sub_80057DD8(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 rect = draft_scratch_adapter(8u), result = 0x210000u;
    sint32 amount, length, numerator, denominator;
    w_u16(rect + 2u, 481);
    w_u16(rect + 6u, 1);
    draft11_image(rect, 320, 64, 0x800A72C8u);
    amount = (sint32)r_u32(0x800A7E10u);
    if (amount > 0)
    {
        numerator = (sint32)((uint32)amount << 24) / 800;
        w_u32(0x800A9CD4u, 100);
        length = numerator >> 16;
        if (length < 4)
            length = 4;
        if (length > 32)
            length = 32;
        draft11_image(rect, 320, (uint32)length, 0x800A71C8u);
        draft11_image(rect, 352, (uint32)length, 0x800A7248u);
    }
    w_u16(rect + 2u, 480);
    draft11_image(rect, 688, 64, 0x800A72C8u);
    amount = (sint32)r_u32(0x800A84ACu);
    if (amount > 0)
    {
        numerator = (sint32)r_u32(0x800A8538u);
        numerator = numerator > 2184479 ? (sint32)(409u * (uint32)(numerator >> 8)) >> 16 : 53;
        denominator = (sint32)(((uint32)numerator << 24) + ((numerator & 128) ? 8191u : 0u)) >> 21;
        amount = r_s32(0x800A84AC);
        length = draft11_div((sint32)((uint32)amount << 24), denominator) >> 16;
        if (length < 4)
            length = 4;
        if (length > 32)
            length = 32;
        draft11_image(rect, 688, (uint32)length, 0x800A71C8u);
        result = draft11_image(rect, 720, (uint32)length, 0x800A7248u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800498D4
uint32 sub_800498D4(uint32 object, uint32 input_angle)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(28u), normal = scratch + 12u, tag = scratch + 20u, index;
    sint32 angle = (sint16)input_angle, x, y, z, cell, delta;
    if (r_u8(object + 197u) - 8u < 2u)
        return draft_scratch_result(native_stack_mark, (uint64)(1));
    if ((sint8)r_u8(object + 87u) < 0)
        angle = (sint16)(angle + 2048);
    angle = (sint16)(angle - 16);
    for (index = 0; index < 2; ++index)
    {
        x = (sint32)r_u32(object + 20u) + (sint16)r_u16(0x800102E0u + ((uint32)angle & 4095u) * 2u) / 3;
        y = (sint32)(r_u32(object + 24u) - 400u);
        z = (sint32)r_u32(object + 28u) + (sint16)r_u16(0x80010AE0u + ((uint32)angle & 4095u) * 2u) / 3;
        w_u32(scratch, (uint32)x);
        w_u32(scratch + 4u, (uint32)y);
        w_u32(scratch + 8u, (uint32)z);
        cell = 80 * (z >> 12) + (x >> 12);
        if ((r_u8(r_u32(0x800A9980u) + (uint32)(cell >> 3)) >> ((uint32)(cell % 8) & 31u)) & 1u)
        {
            // TODO Bind original target 0x8002E310
            draft_call_adapter(0x8002E310u, scratch, normal, tag);
            delta = (sint32)(r_u32(scratch + 4u) - r_u32(object + 24u));
            if (delta < 0)
                delta = -delta;
            if (delta < 512 && r_u16(tag) == 6)
                return draft_scratch_result(native_stack_mark, (uint64)(0));
        }
        angle = (sint16)(angle + 32);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(1));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8001A838
uint32 sub_8001A838(uint32 packet, uint32 vertices, uint32 source, uint32 ot, uint32 a5, uint32 depth_bias, uint32 count, uint32 next)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i, j, address, depth, entry;
    for (i = 0; i < count; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            address = vertices + 8u * r_u16(source + 10u + j * 4u);
            xport_gte_write_data(j * 2u, r_u32(address));
            xport_gte_write_data(j * 2u + 1u, r_u32(address + 4u));
        }
        draft_gte_command_adapter(0x280030u);
        for (j = 0; j < 3; ++j)
        {
            address = vertices + 8u * r_u16(source + 8u + j * 4u);
            xport_gte_write_data(j * 2u, r_u32(address));
            xport_gte_write_data(j * 2u + 1u, r_u32(address + 4u));
        }
        draft_gte_command_adapter(0x1400006u);
        xport_gte_write_data(6u, r_u32(source + 4u));
        if ((sint32)xport_gte_read_data(24u) >= 0)
        {
            draft_gte_command_adapter(0x158002Du);
            depth = xport_gte_read_data(7u);
            if (depth)
            {
                w_u32(packet + 8u, xport_gte_read_data(12u));
                w_u32(packet + 16u, xport_gte_read_data(13u));
                w_u32(packet + 24u, xport_gte_read_data(14u));
                draft_gte_command_adapter(0x118043Fu);
                entry = ot + 4u * (depth_bias + (depth >> 3));
                w_u32(packet, (r_u32(entry) & 0xffffffu) | 0x6000000u);
                w_u32(entry, (r_u32(entry) & 0xff000000u) | (packet & 0xffffffu));
                w_u32(packet + 4u, xport_gte_read_data(20u));
                w_u32(packet + 12u, xport_gte_read_data(21u));
                w_u32(packet + 20u, xport_gte_read_data(22u));
                packet += 28u;
            }
        }
        source += 20u;
    }
    w_u32(next, source);
    return draft_scratch_result(native_stack_mark, (uint64)(packet));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80071B4C
uint32 sub_80071B4C(uint32 list)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 colors[4] = {r_u32(0x800A64D8u), r_u32(0x800A64DCu), r_u32(0x800A64E0u), r_u32(0x800A64E4u)}, x = 0, value, text;
    sint32 kind = (sint16)sub_80037BB8();
    while ((value = r_u8(list++)) != 255u)
    {
        if (kind == -1)
            sub_80043820(r_u32(0x800A8D4Cu), 128, x + 18u, 205, 100, 0);
        else
        {
            if (value >= 4u)
            {
                text = r_u32((kind == 2 ? 0x800920C0u : 0x80092084u) + 4u * value);
                sub_80043820(text, 0x7f7f7fu, x + 78u, 200, 101, 1);
                text = sub_8006F554(r_u32(0x800A8C14u), value);
                x += sub_80043820(text, 0x4f4f4fu, x + 78u, 212, 100, 0) + 14u;
            }
            else
                colors[value] = 0x9f9f9fu;
            sub_800727B0();
        }
    }
    if (kind != -1)
    {
        if (colors[0])
            sub_80044534(colors[0], r_u32(0x80092130u), (uint32)-115, 77);
        if (colors[1])
            sub_80044534(colors[1], r_u32(0x80092134u), (uint32)-115, 93);
        if (colors[2])
            sub_80044534(colors[2], r_u32(0x80092138u), (uint32)-123, 86);
        if (colors[3])
            sub_80044534(colors[3], 0x8009213Cu, (uint32)-107, 86);
        sub_80044534(0x9f9f9fu, 0x800A64E8u, (uint32)-115, 73);
    }
    // TODO Bind original target 0x80020C60
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80020C60u, 199u, r_u32(0x800A9A74u), 0x3f3f3fu, 2u, (uint32)-160, 78u, 320u, 28u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002EAE4
uint32 sub_8002EAE4(uint32 a1, uint32 a2, uint32 update)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(24u), next = scratch + 12u, j;
    sint32 dx = (sint32)(r_u32(a2) - r_u32(a1)), dy = (sint32)(r_u32(a2 + 4u) - r_u32(a1 + 4u)), dz = (sint32)(r_u32(a2 + 8u) - r_u32(a1 + 8u));
    sint32 ax = dx < 0 ? -dx : dx, az = dz < 0 ? -dz : dz, sx, sy, sz, delta;
    uint32 axis;
    if (dx == 0 && dz == 0)
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    for (j = 0; j < 12; j += 4)
        w_u32(scratch + j, r_u32(a1 + j));
    if (az < ax)
    {
        sx = (dx < 0 ? -2048 : 2048);
        sy = (sint32)((uint32)dy << 11) / ax;
        sz = (sint32)((uint32)dz << 11) / ax;
        axis = 0;
    }
    else
    {
        if (dz == 0)
            return draft_scratch_result(native_stack_mark, (uint64)(0));
        sx = (sint32)((uint32)dx << 11) / az;
        sy = (sint32)((uint32)dy << 11) / az;
        sz = dz < 0 ? -2048 : 2048;
        axis = 8;
    }
    for (;;)
    {
        delta = (sint32)(r_u32(scratch + axis) - r_u32(a2 + axis));
        if (delta < 0)
            delta = -delta;
        if (delta < 2049)
        {
            for (j = 0; j < 12; j += 4)
                w_u32(next + j, r_u32(a2 + j));
            if ((sub_8002F3FC(scratch, next) << 16) == 0)
                return draft_scratch_result(native_stack_mark, (uint64)(1));
            break;
        }
        w_u32(next, r_u32(scratch) + (uint32)sx);
        w_u32(next + 4u, r_u32(scratch + 4u) + (uint32)sy);
        w_u32(next + 8u, r_u32(scratch + 8u) + (uint32)sz);
        if (sub_8002F3FC(scratch, next) << 16)
            break;
        for (j = 0; j < 12; j += 4)
            w_u32(scratch + j, r_u32(next + j));
    }
    if (update << 16)
    {
        for (j = 0; j < 12; j += 4)
        {
            w_u32(a1 + j, r_u32(scratch + j));
            w_u32(a2 + j, r_u32(next + j));
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800284E8
uint32 sub_800284E8(uint32 state, uint32 acceleration, uint32 damping, uint32 offset)
{
    uint32 native_stack_mark = draft_scratch_mark();
    sint32 target = (sint16)(r_u16(state + 4) + offset);
    uint32 packed;
    if ((sint32)damping <= 655359)
    {
        packed = r_u32(state + 12);
        uint32 previous = r_u32(state + 8);
        w_u16(state, (uint32)target);
        w_u32(state + 12, packed & 0xf0000000);
        w_u32(state + 8, previous & 0xfff0ffff);
        return draft_scratch_result(native_stack_mark, 0);
    }
    sint32 position = r_s16(state);
    if (position < target)
    {
        packed = r_u32(state + 12);
        sint32 time = r_s32(0x800A63D8) >> 8;
        sint32 velocity = (sint32)(packed << 4) >> 12;
        sint32 displacement = (sint32)((uint32)velocity * (uint32)time) >> 16;
        uint32 increment = (uint32)((sint32)acceleration >> 8) * (uint32)time;
        packed = r_u32(state + 12);
        w_u16(state, (uint32)position + (uint32)displacement);
        packed = (packed & 0xf0000000) | (((uint32)((sint32)(packed << 4) >> 4) + increment) & 0x0fffffff);
        w_u32(state + 12, packed);
        if (((sint32)(packed << 4) >> 4) > 32768000)
            w_u32(state + 12, (packed & 0xf0000000) | 0x01f40000);
        if (target < r_s16(state))
        {
            sint32 velocity = (sint32)(r_u32(state + 12) << 4) >> 4;
            w_u16(state, (uint32)target);
            if ((velocity < (sint32)(acceleration << 4) && (sint32)damping > 0x200000) || (sint32)damping <= 0x7ffff)
                w_u32(state + 12, r_u32(state + 12) & 0xf0000000);
        }
    }
    else
    {
        packed = r_u32(state + 12);
        if (packed & 0x08000000)
        {
            if ((sint32)damping <= 0x1fffff)
            {
                uint32 product = (uint32)((sint32)(packed << 4) >> 12) * (uint32)((sint32)damping >> 13);
                w_u32(state + 12, (packed & 0xf0000000) | (product & 0x0fffffff));
            }
            packed = r_u32(state + 12);
            sint32 time = r_s32(0x800A63D8) >> 8;
            sint32 velocity = (sint32)(packed << 4) >> 12;
            sint32 displacement = (sint32)((uint32)velocity * (uint32)time) >> 16;
            w_u16(state, r_u16(state) + (uint32)displacement);
        }
    }
    if (r_s16(state) >= target)
    {
        sint32 numerator = (sint32)((uint32)(target - r_s16(state + 2)) << 16);
        sint32 divisor = r_s16(0x800A5752);
        if (divisor == 0)
        {
            xport_mips_break(7);
            return draft_scratch_result(native_stack_mark, 0);
        }
        if (divisor == -1 && numerator == (sint32)0x80000000)
        {
            xport_mips_break(6);
            return draft_scratch_result(native_stack_mark, 0);
        }
        uint32 quotient = (uint32)(numerator / divisor);
        packed = r_u32(state + 12);
        w_u16(state, (uint32)target);
        packed = (packed & 0xf0000000) | (quotient & 0x0fffffff);
        w_u32(state + 12, packed);
        if (((sint32)(packed << 4) >> 4) < -1703936)
            w_u32(state + 12, (packed & 0xf0000000) | 0x0fe60000);
        if ((sint32)damping <= 0x1fffff)
        {
            packed = r_u32(state + 12);
            uint32 product = (uint32)((sint32)(packed << 4) >> 12) * (uint32)((sint32)damping >> 13);
            w_u32(state + 12, (packed & 0xf0000000) | (product & 0x0fffffff));
        }
    }
    return draft_scratch_result(native_stack_mark, 0);
}

static sint32 draft11_div(sint32 n, sint32 d)
{
    if (d == 0)
    {
        xport_mips_break(7);
        return 0;
    }
    if (d == -1 && n == (sint32)0x80000000)
    {
        xport_mips_break(6);
        return 0;
    }
    return n / d;
}

static sint32 draft11_segment_div(sint32 numerator, sint32 denominator)
{
    if (denominator == 0)
    {
        xport_mips_break(7);
        return 0;
    }
    if (denominator == -1 && numerator == (sint32)0x80000000)
    {
        xport_mips_break(6);
        return 0;
    }
    return numerator / denominator;
}

// FUNCTION_MARKER sub_8002F7E0
uint32 sub_8002F7E0(uint32 ua, uint32 ub, uint32 point, uint32 uc, uint32 ud, uint32 ue, uint32 uf, uint32 normal, uint32 us, uint32 ut)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 a = (sint32)ua, b = (sint32)ub, c = (sint32)uc, d = (sint32)ud, e = (sint32)ue, f = (sint32)uf, s = (sint32)us, t = (sint32)ut;
    sint32 px = (sint32)r_u32(point), pz = (sint32)r_u32(point + 8u), x, z = b, k, q, m, n, sx = -2, sz = -2, lo, hi, za, zb, length, distance, third;
    uint32 result = 4, angle;
    if (a == px && (c == e || b == pz))
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    if ((b == pz || c == e) && d == f)
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    if (e == c)
    {
        x = e;
        if (b != pz)
            z = (sint32)(ub + (uint32)((sint32)(us * (ua - ue)) >> 10));
    }
    else
    {
        x = a;
        if (f == d)
        {
            z = f;
            if (px != a)
                x = (sint32)(ua + (uint32)((sint32)((uf - ub) * ut) >> 10));
        }
        else if (px == a)
            z = (sint32)(ud + (uint32)draft11_segment_div((sint32)((ud - uf) * (uc - ua)), (sint32)(ue - uc)));
        else if (pz == b)
            x = (sint32)(uc + (uint32)draft11_segment_div((sint32)((ub - ud) * (ue - uc)), (sint32)(uf - ud)));
        else
        {
            k = draft11_segment_div((sint32)((ud - uf) << 10), (sint32)(ue - uc));
            if (s == k)
                return draft_scratch_result(native_stack_mark, (uint64)(0));
            q = draft11_segment_div((sint32)((((ub - ud) << 10) + us * ua - (uint32)k * uc) << 4), (sint32)(us - (uint32)k));
            m = s < 0 ? (sint32)(0 - us) : s;
            n = k < 0 ? (sint32)(0 - (uint32)k) : k;
            z = n >= m ? (sint32)(ub + (uint32)((sint32)(us * ((ua << 4) - (uint32)q)) >> 14)) : (sint32)(ud + (uint32)((sint32)((uint32)k * ((uc << 4) - (uint32)q)) >> 14));
            x = q >> 4;
        }
    }
    if (px < a)
    {
        sx = 2;
        lo = px;
        hi = a;
    }
    else
    {
        lo = a;
        hi = px;
    }
    if (pz < b)
    {
        sz = 2;
        za = pz;
        zb = b;
    }
    else
    {
        za = b;
        zb = pz;
    }
    if (x < lo || x > hi || z < za || z > zb || x < (c < e ? c : e) || x > (c < e ? e : c) || z < (d < f ? d : f) || z > (d < f ? f : d))
        return draft_scratch_result(native_stack_mark, (uint64)(0));
    length = (sint32)((ue - uc) * (ue - uc) + (uf - ud) * (uf - ud));
    third = length / 3;
    distance = (sint32)(((uint32)x - uc) * ((uint32)x - uc) + ((uint32)z - ud) * ((uint32)z - ud));
    if (distance <= third)
        result = 1;
    else if (distance < (sint32)((uint32)third << 1))
        result = 2;
    w_u32(point, (uint32)x + (uint32)sx);
    w_u32(point + 8u, (uint32)z + (uint32)sz);
    if (e == c)
    {
        w_u32(normal, (uint32)(((sint32)(uf - ud) >> 31) | 1) << 16);
        w_u32(normal + 8u, 0);
    }
    else if (f == d)
    {
        w_u32(normal, 0);
        w_u32(normal + 8u, (uint32)(((sint32)(uc - ue) >> 31) | 1) << 16);
    }
    else
    {
        angle = sub_80055A9C(ue - uc, uf - ud) & 4095u;
        w_u32(normal, (uint32)(16 * (sint16)r_u16(0x80010AE0u + angle * 2u)));
        angle = sub_80055A9C(ue - uc, uf - ud) & 4095u;
        w_u32(normal + 8u, (uint32)(-16 * (sint16)r_u16(0x800102E0u + angle * 2u)));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80036584
uint32 sub_80036584(uint32 position, uint32 voice_input)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(20u), vector = scratch + 12u, record, hardware, factor;
    sint32 voice = (sint16)voice_input, left, right, angle, distance, change, level, pan, value;
    sint64 product;
    w_u32(vector, r_u32(0x800A5C58u));
    w_u32(vector + 4u, r_u32(0x800A5C5Cu));
    // TODO Bind original matrix transform and distance targets
    sub_80031B6C(0x800A7EF4u, vector, scratch);
    left = (sint32)draft_call_adapter(0x80069BE0u, r_u32(0x800A7EE4u) + r_u32(scratch) - r_u32(position), r_u32(0x800A7EECu) + r_u32(scratch + 8u) - r_u32(position + 8u));
    w_u16(vector, 136);
    sub_80031B6C(0x800A7EF4u, vector, scratch);
    right = (sint32)draft_call_adapter(0x80069BE0u, r_u32(0x800A7EE4u) + r_u32(scratch) - r_u32(position), r_u32(0x800A7EECu) + r_u32(scratch + 8u) - r_u32(position + 8u));
    angle = (sub_80055A9C(r_u32(0x800A7EE4u) - r_u32(position), r_u32(0x800A7EECu) - r_u32(position + 8u)) - r_u16(0x800A7E7Cu)) & 4095;
    if (angle >= 2049)
        angle -= 4096;
    distance = (sint32)draft_call_adapter(0x80069BE0u, r_u32(0x800A7EE4u) - r_u32(position), r_u32(0x800A7EECu) - r_u32(position + 8u));
    record = 0x800A7C78u + (uint32)voice * 16u;
    hardware = 0x800BBEFCu + (uint32)voice * 64u;
    change = (sint32)((uint32)distance - r_u32(record + 4u)) >> 1;
    if (change >= 128)
        change = 127;
    if (change < -127)
        change = -127;
    level = (sint32)((uint32)right + (uint32)left) >> 7;
    factor = r_u8(0x8008B97C + (uint32)(r_s16(record) >> 8));
    if (level == 0)
        level = 1;
    // TODO Bind original voice status SDK target
    if (draft_call_adapter(0x80086EE4u, 1u << ((uint32)voice & 31)) != 1u || (uint32)level + 126 >= 253u)
        return draft_scratch_result(native_stack_mark, (uint64)(0xffffffffu));
    w_u16(hardware + 20u, r_u16(record) - (uint32)r_s16(0x800A956C + (uint32)change * 2) * factor);
    pan = r_u8(0x800A8234u + (uint32)(uint8)(angle >> 3));
    if (angle > 0)
        pan = -pan;
    pan = (sint16)((uint32)pan << 7);
    level = (right >> 6) + 128;
    if (level < 0)
        level = 0;
    if (level > 255)
        level = 255;
    value = (((sint32)r_u8(0x800A83A0u + (uint32)level) << 7) + pan) >> 1;
    value = (sint32)((uint32)value * (uint32)r_s16(0x800A9D6C));
    product = (sint64)value * (sint32)0x80020009;
    value = ((sint32)((uint32)(sint32)(product >> 32) + (uint32)value) >> 13) - (value >> 31);
    w_u16(hardware + 8, (uint32)value);
    if (value & 0x8000)
        w_u16(hardware + 8, 0);
    pan = r_u8(0x800A8234u + (uint32)(uint8)(angle >> 3));
    if (angle < 0)
        pan = -pan;
    pan = (sint16)((uint32)pan << 7);
    level = (left >> 6) + 128;
    if (level < 0)
        level = 0;
    if (level > 255)
        level = 255;
    value = (((sint32)r_u8(0x800A83A0u + (uint32)level) << 7) + pan) >> 1;
    value = (sint32)((uint32)value * (uint32)r_s16(0x800A9D6C));
    product = (sint64)value * (sint32)0x80020009;
    value = ((sint32)((uint32)(sint32)(product >> 32) + (uint32)value) >> 13) - (value >> 31);
    w_u16(hardware + 10, (uint32)value);
    if (value & 0x8000)
        w_u16(hardware + 10, 0);
    w_u32(record + 4u, (uint32)distance);
    return draft_scratch_result(native_stack_mark, (uint64)(r_u16(hardware + 10u) ? (uint32)voice : 0xffffffffu));

    draft_scratch_release(native_stack_mark);
}

static sint32 draft11_angle(sint32 value)
{
    value &= 4095;
    return value >= 2049 ? value - 4096 : value;
}

static sint32 draft11_abs(sint32 value)
{
    return value < 0 ? (sint32)(0 - (uint32)value) : value;
}

static sint32 draft11_cos(uint32 angle)
{
    return (sint16)r_u16(0x800102E0u + (angle & 4095u) * 2u);
}

static sint32 draft11_sin(uint32 angle)
{
    return (sint16)r_u16(0x80010AE0u + (angle & 4095u) * 2u);
}

// FUNCTION_MARKER sub_80047CF0
uint32 sub_80047CF0(uint32 parameters)
{
    uint32 native_stack_mark = draft_scratch_mark();
    uint32 object = r_u32(parameters), target, velocity, raw, step, increment_x, increment_z, velocity_z;
    sint32 base, desired, turn, other, difference, speed, attenuation, limit, steering, energy, thrust = 0, drag = 0, tick, divisor, heading, x, z, newheading, newdifference, magnitude, loss, result;
    sint64 product;
    if (r_u8(object + 196) == 7 && r_u32(object + 80) == 0xffffffff)
        w_u32(parameters + 12, (uint32)(r_s32(parameters + 12) >> 1));
    object = r_u32(parameters);
    base = r_s32(parameters + 12);
    if (r_s8(object + 87) < 0)
    {
        w_u32(parameters + 12, (uint32)(base >> 3));
        w_u32(parameters + 16, (uint32)(base >> 9));
    }
    target = r_u32(parameters + 4);
    object = r_u32(parameters);
    desired = (sint32)sub_80055A9C(r_u32(target) - r_u32(object + 20), r_u32(target + 8) - r_u32(object + 28));
    object = r_u32(parameters);
    heading = r_u16(object + 182);
    turn = draft11_angle((sint32)((uint32)desired - (uint32)heading));
    other = draft11_angle((sint32)((uint32)desired - r_u16(object + 180)));
    difference = draft11_abs(draft11_angle((sint32)(r_u16(object + 180) - (uint32)heading)));
    if (difference >= 129)
        base = 20000;
    velocity = r_u32(parameters + 8);
    speed = (sint32)draft_call_adapter(0x80069BE0, r_u32(velocity), r_u32(velocity + 8));
    product = (sint64)(sint32)0xb60b60b7 * (difference << 8);
    attenuation = 2048 - ((((sint32)(product >> 32) + (difference << 8)) >> 7) - ((difference << 8) >> 31));
    if (attenuation & 0x8000)
        attenuation = 0;
    limit = (sint32)((uint32)base * (uint32)(sint16)attenuation) >> 11;
    if (limit < 12000)
        limit = 12000;
    object = r_u32(parameters);
    steering = r_u8(object + 198) == 10 ? turn >> 2 : (sint32)((uint32)(speed >> 8) * (uint32)turn) >> 5;
    w_u16(object + 112, r_u16(object + 112) + (uint32)steering);
    steering = r_s16(object + 112);
    object = r_u32(parameters);
    if (draft11_abs(turn) < 1024 && draft11_abs(other) < 1024 && r_u8(object + 195) == 0)
    {
        if ((draft11_abs(steering / 3) >> 6) >= 21)
            w_u16(object + 112, (uint32)(3840 * ((steering >> 15) | 1)));
        energy = (sint32)((uint32)(speed >> 4) * (uint32)(speed >> 4)) >> 8;
    }
    else
    {
        if ((draft11_abs(steering / 3) >> 6) >= 51)
            w_u16(object + 112, (uint32)(9600 * ((steering >> 15) | 1)));
        object = r_u32(parameters);
        w_u8(object + 195, 1);
        if (speed >= 18001)
            w_u32(parameters + 12, 18000);
        energy = (sint32)((uint32)(speed >> 4) * (uint32)(speed >> 4)) >> 10;
        if (draft11_abs(turn) < 128 && draft11_abs(other) < 128)
            w_u8(r_u32(parameters) + 195, 0);
    }
    object = r_u32(parameters);
    steering = r_s16(object + 112);
    if ((draft11_abs(steering) >> 6) >= draft11_abs(turn))
    {
        w_u16(object + 182, r_u16(object + 182) + (uint32)turn);
        w_u16(r_u32(parameters) + 112, 0);
    }
    else
    {
        result = (sint16)(steering / 3) >> 6;
        tick = r_s32(0x800A63D8) >> 8;
        result = (sint32)(((uint32)result << 8) * (uint32)tick) >> 16;
        result = (sint32)(60 * (uint32)result);
        divisor = r_s32(0x800A56C0);
        result = draft11_div(result, divisor);
        w_u16(object + 182, r_u16(object + 182) + (uint32)result);
    }
    if (limit >= speed)
    {
        velocity = r_u32(parameters + 8);
        heading = (sint32)sub_80055A9C(r_u32(velocity), r_u32(velocity + 8));
        result = (sint32)(r_u32(parameters + 12) - (uint32)speed) / 100;
        object = r_u32(parameters);
        thrust = (sint32)((uint32)result * (uint32)draft11_sin((uint32)heading - (uint32)r_s16(object + 182))) >> 12;
        if (thrust >= 128)
        {
            result = r_s32(parameters + 16);
            if (result < thrust)
                thrust = result;
        }
        else
            thrust = 128;
    }
    else
    {
        result = (sint32)((uint32)energy * (uint32)draft11_cos((uint32)turn));
        tick = r_s32(0x800A63D8) >> 8;
        result = draft11_abs(result) / 8000;
        result = (sint32)((uint32)result << 16) >> 8;
        result = (sint32)((uint32)result * (uint32)tick) >> 16;
        divisor = r_s32(0x800A56C0);
        drag = (sint32)(60 * (uint32)draft11_div(result, divisor));
    }
    object = r_u32(parameters);
    if (r_u8(object + 199))
    {
        thrust = 0;
        drag = draft11_abs((sint32)(r_u32(parameters + 16) << 1));
    }
    result = r_s8(object + 87);
    step = r_u32(0x800A9010);
    thrust = (sint32)((uint32)thrust * ((uint32)result * step));
    heading = r_u16(object + 182) & 4095;
    result = draft11_cos((uint32)heading);
    divisor = r_s32(0x800A56C0);
    result = (sint32)((uint32)thrust * (uint32)result) >> 12;
    increment_x = (uint32)draft11_div((sint32)(60 * (uint32)result), divisor);
    result = (sint32)((uint32)thrust * (uint32)draft11_sin((uint32)heading)) >> 12;
    increment_z = (uint32)draft11_div((sint32)(60 * (uint32)result), divisor);
    velocity = r_u32(parameters + 8);
    x = (sint32)(increment_x + r_u32(velocity));
    z = (sint32)(increment_z + r_u32(velocity + 8));
    newheading = (sint32)sub_80055A9C((uint32)x, (uint32)z);
    object = r_u32(parameters);
    heading = r_u16(object + 182);
    newdifference = draft11_abs(draft11_angle((sint32)((uint32)newheading - (uint32)heading)));
    if (newdifference < 32)
        newheading = heading;
    magnitude = (sint32)((uint32)draft_call_adapter(0x80069BE0, (uint32)x, (uint32)z) - (uint32)drag);
    object = r_u32(parameters);
    if (draft11_abs(turn) < 1024 && newdifference < 1024 && r_u16(object + 178) >= 8001)
    {
        result = (sint32)((uint32)energy * (uint32)draft11_cos((uint32)newheading - (uint32)r_s16(object + 182)));
        tick = r_s32(0x800A63D8) >> 8;
        result = draft11_abs(result / 4400);
        result = (sint32)((uint32)result << 16) >> 8;
        result = (sint32)((uint32)result * (uint32)tick) >> 16;
        divisor = r_s32(0x800A56C0);
        loss = (sint32)((uint32)magnitude - 60 * (uint32)draft11_div(result, divisor) - (uint32)(magnitude >> 8));
    }
    else
    {
        result = draft11_cos((uint32)newheading - (uint32)r_s16(object + 182));
        tick = r_s32(0x800A63D8) >> 8;
        result = draft11_abs((sint32)((uint32)energy * (uint32)result) >> 15);
        result = (sint32)((uint32)result << 16) >> 8;
        result = (sint32)((uint32)result * (uint32)tick) >> 16;
        divisor = r_s32(0x800A56C0);
        loss = (sint32)((uint32)magnitude - 60 * (uint32)draft11_div(result, divisor) - (uint32)(magnitude >> 7));
    }
    if (loss < 64)
        loss = 0;
    result = r_s32(parameters + 12);
    if (result < loss)
        loss = result;
    result = (sint32)((uint32)loss * (uint32)draft11_cos((uint32)newheading)) >> 12;
    velocity = r_u32(parameters + 8);
    w_u32(velocity, (uint32)result);
    velocity_z = (uint32)loss * (uint32)draft11_sin((uint32)newheading);
    step = r_u32(0x800A9010);
    divisor = r_s32(0x800A56C0);
    result = (sint32)((uint32)x * step) >> 8;
    increment_x = (uint32)draft11_div((sint32)(60 * (uint32)result), divisor);
    result = (sint32)((uint32)z * step) >> 8;
    increment_z = (uint32)draft11_div((sint32)(60 * (uint32)result), divisor);
    velocity = r_u32(parameters + 8);
    w_u32(velocity + 8, (uint32)((sint32)velocity_z >> 12));
    object = r_u32(parameters);
    raw = r_u32(object + 20);
    w_u32(object + 20, raw + increment_x);
    object = r_u32(parameters);
    raw = r_u32(object + 28);
    w_u32(object + 28, raw + increment_z);
    object = r_u32(parameters);
    w_u8(object + 199, 0);
    return draft_scratch_result(native_stack_mark, object);
}

static uint32 draft11_actor_model(uint32 object)
{
    uint32 index = r_u16(object + 32);
    uint32 map = r_u32(0x800A8548);
    uint32 model = r_u8(map + index);
    uint32 models = r_u32(0x800A90AC);
    return models + model * 40;
}

// FUNCTION_MARKER sub_8004D184
uint32 sub_8004D184(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(76), previous = scratch, motion = scratch + 12, target = scratch + 24, normal = scratch + 40, tag = scratch + 48;
    uint32 i, sum = 0, result, code, x, y_word, z, index, map, models, flags, record, parameter;
    sint32 height, delta;
    uint32 ground, y;
    result = sub_8004D04C(object);
    if (result)
    {
        if ((sint32)result >= 0)
        {
            w_u32(object, 0x80029968u);
            return draft_scratch_result(native_stack_mark, (uint64)(0x80029968u));
        }
        w_u32(object, 0x8004D874u);
    }
    x = r_u32(object + 128);
    y_word = r_u32(object + 132);
    z = r_u32(object + 136);
    w_u32(previous, x);
    w_u32(previous + 4, y_word);
    w_u32(previous + 8, z);
    w_u32(0x800A6EF4u, previous);
    w_u32(0x800A6F9Cu, object);
    w_u16(0x800A6FB4u, 1);
    sub_8004BC94(0x800A6F9Cu);
    w_u32(motion, r_u32(object + 100u));
    w_u32(motion + 8u, r_u32(object + 104u));
    for (i = 0; i < 4; ++i)
        sum += r_u16(object + 210u + i * 16u) & 15u;
    code = r_u8(object + 198);
    if (code == 12 || (r_u8(object + 12u) >= 4u && (sint16)sum == 4))
    {
        // TODO Bind original target 0x80048F9C
        draft_call_adapter(0x80048F9Cu, object + 20u, motion, object + 182u, code);
    }
    else
    {
        w_u32(target, r_u32(object + 92u));
        w_u32(target + 8u, r_u32(object + 96u));
        if (r_u8(object + 89u))
        {
            // TODO Bind original target 0x80048D30
            draft_call_adapter(0x80048D30u, object, object + 20u, target, motion, object + 182u, (uint32)(sint32)(sint8)r_u8(object + 87u), 20u);
        }
        else
        {
            w_u32(0x800A6FC4u, r_u16(object + 178u));
            parameter = r_u16(object + 178);
            w_u32(0x800A6FC0u, motion);
            w_u32(0x800A6FB8u, object);
            w_u32(0x800A6FBCu, target);
            w_u32(0x800A6FC8u, parameter >> 6);
            sub_80047CF0(0x800A6FB8u);
        }
    }
    if (r_u8(object + 12u) < 4u)
    {
        w_u32(object + 320u, 0);
        if (sub_8002F3FC(previous, object + 20u) << 16)
        {
            if (r_u8(object + 88u) == 0)
            {
                x = r_u32(object + 128);
                y_word = r_u32(object + 132);
                z = r_u32(object + 136);
                w_u32(object + 20, x);
                w_u32(object + 24, y_word);
                w_u32(object + 28, z);
                w_u16(object + 114u, 120);
                code = (uint32)r_s8(object + 87);
                parameter = (uint32)r_s16(object + 170);
                w_u8(object + 87, 0 - code);
                if ((sint32)parameter > 0)
                    w_u16(object + 170, parameter - 1);
            }
            w_u32(motion, r_u32(motion) << 8);
            w_u32(motion + 8u, r_u32(motion + 8u) << 8);
            // TODO Bind original target 0x80023918
            draft_call_adapter(0x80023918u, r_u32(previous), r_u32(previous + 8u), motion, motion + 8u);
            w_u32(motion, (uint32)((sint32)r_u32(motion) >> 8));
            w_u32(motion + 8u, (uint32)((sint32)r_u32(motion + 8u) >> 8));
        }
        else
            w_u8(object + 88u, 0);
        height = (sint16)r_u16(draft11_actor_model(object) + 32) >> 1;
        w_u32(object + 24u, r_u32(object + 24u) + (uint32)height);
        // TODO Bind original target 0x8002E310
        result = (uint32)draft_call_adapter(0x8002E310u, object + 20u, normal, tag);
        height = (sint16)r_u16(draft11_actor_model(object) + 32) >> 1;
        y = r_u32(object + 24);
        ground = 0 - result - (uint32)height;
        delta = (sint32)(y - ground);
        if (delta < 0)
            delta = (sint32)(ground - y);
        if (delta >= 512)
        {
            height = (sint16)r_u16(draft11_actor_model(object) + 32) >> 1;
            ground = r_u32(object + 24) - (uint32)height;
        }
        w_u32(object + 24, ground);
        map = r_u32(0x800A8548);
        models = r_u32(0x800A90AC);
        for (i = 0; i < 4; ++i)
        {
            record = object + i * 16;
            w_u16(record + 202, ground);
            w_u16(record + 200, ground);
            index = r_u16(object + 32);
            code = r_u8(map + index);
            flags = r_u32(record + 208);
            height = (sint16)r_u16(models + code * 40 + 32) >> 1;
            w_u32(record + 208, flags & 0xfff0ffff);
            w_u16(record + 204, ground + (uint32)height);
        }
        index = r_u16(object + 32);
        w_u8(object + 266, 0);
        w_u8(object + 267, 0);
        map = r_u32(0x800A8548);
        w_u16(object + 264, ground);
        code = r_u8(map + index);
        models = r_u32(0x800A90AC);
        height = (sint16)r_u16(models + code * 40 + 32) >> 1;
        w_u32(object + 268, ground + (uint32)height);
        sub_80036CFC(object + 194u);
        sub_80036CFC(object + 324u);
    }
    else
    {
        sub_8004C8F4(object, motion);
        if (sub_8004CAD4(object, motion, previous, object + 200u) && (uint32)draft_call_adapter(0x80069BE0u, r_u32(motion), r_u32(motion + 8u)) >= 1281u)
            sub_800369E0(object + 20u, object + 324u, 1000, 56);
        else
            sub_80036CFC(object + 324u);
        height = r_s16(draft11_actor_model(object) + 32);
        sub_80029970(object, (uint32)height, 2, 1, previous);
        code = r_u8(object + 197);
        if (code == 12)
            sub_800369E0(object + 20, object + 194, 1000, 42);
        else
            sub_800369E0(object + 20, object + 194, 3000, 11);
    }
    w_u32(object + 100u, r_u32(motion));
    w_u32(object + 104u, r_u32(motion + 8u));
    x = r_u32(object + 20);
    y_word = r_u32(object + 24);
    z = r_u32(object + 28);
    w_u32(object + 128, x);
    w_u32(object + 132, y_word);
    w_u32(object + 136, z);
    result = (uint32)(sint32)(sint8)r_u8(object + 89u);
    if ((sint32)result <= 0)
        w_u8(object + 89u, 0);
    else
    {
        result -= (uint32)r_s16(0x800A63DA);
        w_u8(object + 89u, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

static void draft11_vertex(uint32 grid, uint32 index, uint32 slot)
{
    xport_gte_write_data(slot * 2u, r_u32(grid + index * 8u));
    xport_gte_write_data(slot * 2u + 1u, r_u32(grid + index * 8u + 4u));
}

static uint32 draft11_quad(uint32 packet, uint32 grid, uint32 uv, uint32 ot, uint32 clut, uint32 page, uint32 bias, uint32 a, uint32 b, uint32 c, uint32 d, uint32 require_depth)
{
    uint32 depth, entry;
    draft11_vertex(grid, a, 0);
    draft11_vertex(grid, b, 1);
    draft11_vertex(grid, c, 2);
    draft_gte_command_adapter(0x280030u);
    draft11_vertex(grid, d, 0);
    w_u32(packet + 8u, xport_gte_read_data(12));
    w_u32(packet + 16u, xport_gte_read_data(13));
    w_u32(packet + 24u, xport_gte_read_data(14));
    draft_gte_command_adapter(0x180001u);
    w_u32(packet + 36u, r_u32(uv + d * 4u));
    draft_gte_command_adapter(0x168002Eu);
    depth = xport_gte_read_data(7);
    if (require_depth && depth == 0)
        return packet;
    w_u32(packet + 32u, xport_gte_read_data(14));
    w_u32(packet + 12u, clut | r_u32(uv + a * 4u));
    w_u32(packet + 20u, page | r_u32(uv + b * 4u));
    w_u32(packet + 28u, r_u32(uv + c * 4u));
    entry = ot + 4u * (bias + (depth >> 3));
    w_u32(packet, (r_u32(entry) & 0xffffffu) | 0x9000000u);
    w_u32(entry, (r_u32(entry) & 0xff000000u) | (packet & 0xffffffu));
    w_u32(packet + 4u, xport_gte_read_data(22));
    return packet + 40u;
}

// FUNCTION_MARKER sub_8001D204
uint32 sub_8001D204(uint32 projected, uint32 packet, uint32 vertices, uint32 source, uint32 ot, uint32 uv, uint32 grid, uint32 clut, uint32 page, uint32 bias)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 bases[4] = {0, 1, 3, 4}, pairs[5][2] = {{0, 1}, {0, 3}, {1, 3}, {1, 4}, {4, 3}}, midpoint_order[5] = {0, 1, 2, 4, 3}, q, i, j, b, flag;
    sint32 area;
    uint32 points[4], allright, allleft, allbottom, alltop;
    for (q = 0; q < 4; ++q)
    {
        b = bases[q];
        draft11_vertex(grid, b, 0);
        draft11_vertex(grid, b + 1u, 1);
        draft11_vertex(grid, b + 3u, 2);
        draft_gte_command_adapter(0x280030u);
        draft11_vertex(grid, b + 4u, 0);
        flag = draft_gte_control_adapter(31);
        draft_gte_command_adapter(0x1400006u);
        area = (sint32)xport_gte_read_data(24);
        uint32 magnitude = area < 0 ? 0 - (uint32)area : (uint32)area;
        if ((sint32)flag >= 0 && (sint32)magnitude < 1024)
        {
            uint32 depth, entry;
            w_u32(packet + 8, xport_gte_read_data(12));
            w_u32(packet + 16, xport_gte_read_data(13));
            w_u32(packet + 24, xport_gte_read_data(14));
            draft_gte_command_adapter(0x180001);
            w_u32(packet + 12, clut | r_u32(uv + 4 * b));
            w_u32(packet + 20, page | r_u32(uv + 4 * (b + 1)));
            w_u32(packet + 28, r_u32(uv + 4 * (b + 3)));
            w_u32(packet + 36, r_u32(uv + 4 * (b + 4)));
            draft_gte_command_adapter(0x168002E);
            w_u32(packet + 32, xport_gte_read_data(14));
            depth = xport_gte_read_data(7);
            entry = ot + 4 * (bias + (depth >> 3));
            w_u32(packet, (r_u32(entry) & 0xFFFFFF) | 0x09000000);
            w_u32(entry, (r_u32(entry) & 0xFF000000) | (packet & 0xFFFFFF));
            w_u32(packet + 4, xport_gte_read_data(22));
            packet += 40;
            continue;
        }
        for (i = 0; i < 3; ++i)
        {
            points[i] = xport_gte_read_data(12 + i);
            w_u32(projected + i * 4, points[i]);
        }
        draft11_vertex(grid, b + 4u, 0);
        draft_gte_command_adapter(0x180001u);
        points[3] = xport_gte_read_data(14);
        w_u32(projected + 12, points[3]);
        allright = allleft = allbottom = alltop = 1;
        for (i = 0; i < 4; ++i)
        {
            sint32 x = (sint16)points[i], y = (sint16)(points[i] >> 16);
            allright &= x >= 320;
            allleft &= x <= 0;
            allbottom &= y >= 240;
            alltop &= y <= 0;
        }
        if (allright || allleft || allbottom || alltop)
            continue;
        for (j = 0; j < 3; ++j)
            for (i = 0; i < 5; ++i)
            {
                uint32 index = midpoint_order[i], a = b + pairs[index][0], c = b + pairs[index][1], dest = 9 + index;
                w_u16(grid + dest * 8u + j * 2u, (uint32)(((sint16)r_u16(grid + a * 8u + j * 2u) + (sint16)r_u16(grid + c * 8u + j * 2u)) >> 1));
            }
        for (j = 0; j < 2; ++j)
            for (i = 0; i < 5; ++i)
            {
                uint32 index = midpoint_order[i], a = b + pairs[index][0], c = b + pairs[index][1], dest = 9 + index;
                w_u8(uv + dest * 4u + j, (r_u8(uv + a * 4u + j) + r_u8(uv + c * 4u + j)) >> 1);
            }
        packet = draft11_quad(packet, grid, uv, ot, clut, page, bias, b, 9, 10, 11, 1);
        packet = draft11_quad(packet, grid, uv, ot, clut, page, bias, 9, b + 1, 11, 12, 1);
        packet = draft11_quad(packet, grid, uv, ot, clut, page, bias, 10, 11, b + 3, 13, 1);
        packet = draft11_quad(packet, grid, uv, ot, clut, page, bias, 11, 12, 13, b + 4, 1);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(packet));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800287B4
uint32 sub_800287B4(uint32 object, uint32 suspension, uint32 damping, uint32 heights)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(28u), normal = scratch + 12u, tag = scratch + 20u, i, state, packed, mask = 0, bit = 1, bounce = 0, value;
    sint32 offset, ground, base, time, acceleration, velocity, target, oscillation, mean, delta, divisor;
    offset = -((sint16)r_u16(r_u32(0x800A90ACu) + 40u * r_u8(r_u32(0x800A8548u) + r_u16(object + 32u)) + 32u) >> 1);
    for (i = 0; i < 12; i += 4)
        w_u32(scratch + i, r_u32(object + 20u + i));
    if (offset >= -109)
        w_u32(scratch + 4u, r_u32(scratch + 4u) - 100u);
    // TODO Bind original ground query target 0x8002E310
    ground = (sint32)(0 - (uint32)draft_call_adapter(0x8002E310u, scratch, normal, tag));
    base = (sint32)r_u32(suspension + 68u);
    if ((sint16)r_u16(suspension + 64u) < (sint32)((uint32)ground - (uint32)offset) && ground)
        base = ground;
    w_u32(suspension + 68u, (uint32)base);
    w_u8(suspension + 66u, (sint32)(r_u32(object + 24u) - (uint32)base) < offset);
    for (i = 0; i < 4; ++i)
    {
        state = suspension + i * 16u;
        time = (sint32)r_u32(0x800A63D8u) >> 8;
        w_u16(state + 2u, r_u16(state));
        if (r_u16(state + 4u) == 0)
            w_u16(state + 4u, (uint32)base);
        if ((sint16)r_u16(state) - (sint16)r_u16(state + 4u) < (sint32)((uint32)offset - (uint32)((sint32)(7680 * (uint32)time) >> 16)))
            w_u32(state + 8u, (r_u32(state + 8u) & 0xfff0ffffu) | 0x10000u);
        if (r_u16(state + 10u) & 15u)
        {
            if (r_u32(suspension + 64u) & 0xffff0000u)
            {
                packed = r_u32(state + 12u);
                time = r_s32(0x800A63D8) >> 8;
                velocity = (sint32)(packed << 4) >> 12;
                sint32 displacement = (sint32)((uint32)velocity * (uint32)time) >> 16;
                acceleration = r_s32(0x800A5740 + i * 4);
                uint32 increment = (uint32)(acceleration >> 8) * (uint32)time;
                packed = r_u32(state + 12u);
                w_u16(state, r_u16(state) + (uint32)displacement);
                value = (packed & 0xf0000000u) | (((uint32)((sint32)(packed << 4) >> 4) + increment) & 0x0fffffffu);
                target = (sint16)(offset + r_u16(state + 4u));
                w_u32(state + 12u, value);
                if ((sint32)(value << 4) >> 4 > 32768000)
                    w_u32(state + 12u, (value & 0xf0000000u) | 0x1f40000u);
                if (target < (sint16)r_u16(state))
                {
                    value = r_u32(state + 12u);
                    w_u16(state + 8u, 0);
                    w_u16(state, (uint32)target);
                    w_u16(state + 6u, (uint32)((sint16)(value >> 12) >> 4));
                    w_u32(state + 8u, r_u32(state + 8u) & 0xfff0ffffu);
                    if ((((sint32)(r_u32(state + 12u) << 4) >> 4) < (sint32)((uint32)acceleration << 4) && (sint32)damping > 0x200000) || (sint32)damping <= 0x7ffff)
                        w_u32(state + 12u, r_u32(state + 12u) & 0xf0000000u);
                    if ((sint32)((uint32)acceleration << 5) < ((sint32)(r_u32(state + 12u) << 4) >> 4))
                        bounce |= 1u;
                }
            }
            else if ((sint16)offset < (sint32)((uint32)base - (uint32)r_s16(state + 4u)))
                w_u16(state, (uint32)(offset + (sint16)r_u16(state + 4u)));
            if (r_u16(state + 10u) & 15u)
                mask |= bit;
            bit = (uint16)(bit * 2u);
        }
        else
        {
            if (r_u8(suspension + 67u))
                bounce |= sub_800284E8(state, r_u32(0x800A5740u + i * 4u), damping, (uint32)(sint16)offset);
            oscillation = 0;
            value = (uint32)(sint32)(sint16)r_u16(state + 8u);
            if ((sint32)value < 8190)
            {
                oscillation = (sint32)((uint32)((sint16)r_u16(state + 6u) * draft11_cos(value)) >> 12);
                w_u16(state + 6u, (uint32)((475 * (sint16)r_u16(state + 6u)) >> 9));
                w_u16(state + 8u, r_u16(state + 8u) + ((sint32)(r_u32(0x800A63D8) << 7) >> 16));
            }
            w_u16(heights + i * 2u, r_u16(heights + i * 2u) + (uint32)oscillation);
            if (r_u16(object + 56u) == 0)
                w_u16(0x800A8688u + 2u * r_u8(0x800A5760u + i), r_u16(heights + i * 2u));
        }
        if (ground < (sint32)r_u32(object + 24u))
            w_u16(state, r_u16(state) + (uint32)ground - r_u16(object + 24u));
        if ((sint32)damping <= 0x1fffff && base < (sint16)r_u16(state) + (sint16)offset)
            w_u16(state, r_u16(state + 2u));
        w_u16(heights + i * 2u, r_u16(heights + i * 2u) + r_u16(state));
    }
    mean = ((sint16)r_u16(heights) + (sint16)r_u16(heights + 2u) + (sint16)r_u16(heights + 4u) + (sint16)r_u16(heights + 6u)) >> 2;
    if (mask)
    {
        if (((sint32)damping <= 0x100000 && mean - offset - 40 >= base) || ((sint32)damping > 0x100000 && offset + mean + 30 >= base))
        {
            w_u32(object + 24u, (uint32)(sint32)(sint16)r_u16(suspension + 64u));
            w_u8(suspension + 67u, 0);
        }
        else
        {
            w_u8(suspension + 67u, 1);
            w_u32(object + 24u, (uint32)mean);
        }
    }
    else
    {
        w_u32(object + 24u, offset + mean + 30 >= base ? (uint32)(sint32)(sint16)r_u16(suspension + 64u) : (uint32)mean);
        w_u8(suspension + 67u, 1);
    }
    delta = (sint32)((uint32)mean - (uint32)ground - ((uint32)r_s16(suspension + 64u) - (uint32)base));
    divisor = (sint32)r_u32(0x800A9010u);
    if (divisor)
    {
        if (divisor == -1 && delta == (sint32)0x80000000)
        {
            xport_mips_break(6);
            return draft_scratch_result(native_stack_mark, 0);
        }
        delta /= divisor;
    }
    if ((bounce << 16) && delta >= 36)
    {
        // TODO Bind original target 0x80035A08
        draft_call_adapter(0x80035A08u, 48u, 1600u, 128u, object + 20u);
    }
    w_u16(suspension + 64u, r_u16(object + 24u));
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)(sint32)(sint16)mask));

    draft_scratch_release(native_stack_mark);
}
