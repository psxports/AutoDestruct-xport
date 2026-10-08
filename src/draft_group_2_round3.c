#include "draft_signatures.h"

static uint32 draft_round3_roll_scale(uint32 object)
{
    int32 scale = (int32)r_u32(object + 472u) >> 2;
    if (scale > 65536) scale = 65536; if (scale < 2048) scale = 2048;
    w_u32(0x800A56A8u, 0x8000u); return (uint32)(scale >> 8);
}

/* FUNCTION_MARKER: sub_800245AC */
uint32 sub_800245AC(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 contact = r_u16(a2 + 96u), flags, scale, result = 12u;
    if (contact & 64u) { if ((contact & 12u) == 12u) return draft_scratch_result(native_stack_mark, (uint64)(result)); }
    else {
        if (contact & 16u) { result = 3u; if ((contact & 3u) == 3u) return draft_scratch_result(native_stack_mark, (uint64)(result)); }
        else { if ((contact & 12u) == 12u) return draft_scratch_result(native_stack_mark, (uint64)(result)); result = 3u; if ((contact & 3u) == 3u) return draft_scratch_result(native_stack_mark, (uint64)(result)); }
        scale = draft_round3_roll_scale(a1); flags = r_u16(0x800A8704u);
        if (flags & 1u) w_u32(a1 + 516u, r_u32(a1 + 516u) + (uint32)((int32)a4 >> 9) * scale);
        scale = draft_round3_roll_scale(a1); flags = r_u16(0x800A8704u); result = flags & 2u;
        if (result) { result = r_u32(a1 + 516u) + (uint32)((int32)(0u - a4) >> 9) * scale; w_u32(a1 + 516u, result); }
        if (contact & 16u) return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    scale = draft_round3_roll_scale(a1); flags = r_u16(0x800A8704u);
    if (flags & 4u) w_u32(a1 + 516u, r_u32(a1 + 516u) + (uint32)((int32)a3 >> 9) * scale);
    scale = draft_round3_roll_scale(a1); result = r_u16(0x800A8704u) & 8u;
    if (result) { result = r_u32(a1 + 516u) + (uint32)((int32)(0u - a3) >> 9) * scale; w_u32(a1 + 516u, result); }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

static void draft_round3_approach(uint32 field, uint32 target)
{
    uint32 current = r_u32(field), distance = current - target;
    if ((int32)distance < 0) distance = target - current;
    if ((int32)distance <= 32768) w_u32(field, target);
    else w_u32(field, (int32)target >= (int32)current ? current + 32768u : current - 32768u);
}

/* FUNCTION_MARKER: sub_80024820 */
uint32 sub_80024820(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 row, product, common, x, oppositeX, z, oppositeZ, sums[4], i, result = 0u;
    draft_round3_approach(a1 + 540u, 0u - r_u32(a1 + 536u));
    row = r_u32(0x800A9750u) + r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u)) * 40u;
    product = r_u32(a1 + 540u) * (uint32)((int16)r_u16(row + 32u) >> 1); common = r_u32(a1 + 500u);
    x = ((uint32)((int32)common >> 8) << 7) + (uint32)((int64)(int32)product / (int16)r_u16(row + 34u)); oppositeX = common - x;
    draft_round3_approach(a1 + 544u, r_u32(a1 + 532u));
    row = r_u32(0x800A9750u) + r_u8(r_u32(0x800A8548u) + r_u16(a1 + 32u)) * 40u;
    product = r_u32(a1 + 544u) * (uint32)((int16)r_u16(row + 32u) >> 1); common = r_u32(a1 + 500u);
    z = ((uint32)((int32)common >> 8) << 7) + (uint32)((int64)(int32)product / (int16)r_u16(row + 36u)); oppositeZ = common - z;
    sums[0] = oppositeX + oppositeZ; sums[1] = oppositeX + z; sums[2] = x + z; sums[3] = x + oppositeZ;
    for (i = 0; i < 4u; ++i) { uint32 index = (uint32)((int32)(sums[i] - 65536u) >> 5) & 0x1FFEu; result = (uint32)(((int16)r_u16(0x800102E0u + index) + 4096) * 5 >> 10); w_u16(a2 + i * 2u, (uint16)result); }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80044C78 */
uint32 sub_80044C78(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 value = (int32)a2, digits[5]; uint32 index = a1, result;
    digits[0] = value / 10000; value %= 10000; digits[1] = value / 1000; value %= 1000; digits[2] = value / 100; value %= 100; digits[3] = value / 10; digits[4] = value % 10;
    if (!index) while (index < 4u && !digits[index]) ++index;
    result = (int32)index < 5;
    while ((int32)index < 5) { uint32 digit = (uint8)digits[index++]; draft_call_adapter(0x8004328Cu, 0x800908E8u, 0x54000040u, digit, 8421504u, a3, a4, 0u); a3 += 1u + r_u8(0x800908EAu + digit * 5u); result = (int32)index < 5; }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80043DF4 */
uint32 sub_80043DF4(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = r_u32(0x800A7FB8u), code = 32u, offset = 0u, iteration; int32 x = -160;
    if (!result) return draft_scratch_result(native_stack_mark, (uint64)(result));
    for (iteration = 0; (int32)iteration < (int32)r_u32(0x800A902Cu); ++iteration) {
        uint32 control = 0u, font = r_u32(0x800A5F68u); if (!code) break;
        code = r_u8(0x800BC4FCu + offset);
        if (!code) { w_u32(0x800A9744u, 1u); control = 1u; }
        if (code == 1u) { x = (int32)r_u8(0x800BC4FCu + offset + 1u) - 160; offset += 2u; control = 1u; }
        if (code == 2u) { ++offset; x = -144; control = 1u; }
        if (code == 3u) { x = 144 - (int32)r_u8(0x800BC4FCu + offset + 1u); offset += 2u; control = 1u; }
        if (code == 32u) { ++offset; control = 1u; }
        if (code == 10u) { x = -160; a1 += 13u; ++offset; control = 1u; }
        if (!control) {
            uint32 depth = offset + 100u, type;
            draft_call_adapter(0x8004328Cu, font, 0x54000040u, code, 8421504u, (uint32)x, a1, depth); type = r_u8(font + code * 5u + 4u); ++offset;
            if (type != 1u && type != 6u) draft_call_adapter(0x8004328Cu, font, 0x64000040u, code, 8421504u, (uint32)x + 1u, a1 + 1u, depth);
        }
        x = (int32)((uint32)x + r_u8(font + code * 5u + 2u));
    }
    result = r_u32(0x800A9744u); if (!result) { result = (uint32)((int32)r_u32(0x800A9010u) / 2) + r_u32(0x800A902Cu); w_u32(0x800A902Cu, result); } return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80033200 */
uint32 sub_80033200(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result; int32 y = -104;
    w_u32(0x800A7BE0u, 0);
    if ((int16)r_u16(0x800A6CECu) < 16) {
        w_u32(0x800A902Cu, 1); w_u32(0x800A7FB8u, 1); w_u16(0x800A9744u, 0);
        w_u32(0x800A6C90u, sub_80077AC0(r_u32(0x800A8568u), 1, 1, 287));
        if (!r_u16(0x800A6CECu)) w_u16(0x800A6CECu, 1);
        if ((int32)r_u32(0x800A9A68u) > 0 && r_u32(0x800A975Cu) && r_u16(0x800A6CECu) == 1) w_u32(0x800A7BE0u, sub_80033120());
        if (!r_u32(0x800A7BE0u)) w_u16(0x800A6CECu, r_u16(0x800A6CECu) + 1u);
    } else w_u32(0x800A6C90u, sub_80077AC0(r_u32(0x800A8568u), 1, 1, 287));
    if (r_u32(0x800A8E70u) != 1) y = (int32)(13u * r_u32(0x800A6C90u)) / -2 - 7;
    sub_80043DF4((uint32)y);
    if ((int16)r_u16(0x800A6CF0u) >= 30) {
        sub_80033400(); w_u16(0x800A973Cu, 2); w_u16(0x800A6CECu, 0); w_u16(0x800A6CF0u, 0); return draft_scratch_result(native_stack_mark, (uint64)(2));
    }
    if ((int32)r_u32(0x800A9A68u) > 0 && r_u32(0x800A975Cu)) w_u32(0x800A7BE0u, sub_8003315C());
    result = 1;
    if (r_u16(0x800A9744u) == 1) { result = r_u32(0x800A7BE0u); if (!result) { result = r_u16(0x800A6CF0u) + 1u; w_u16(0x800A6CF0u, result); } }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_8003B3B0 */
uint32 sub_8003B3B0(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 entry, object;
    if (!r_u16(0x800A8B34u) && r_u16(0x800A9A64u) == 1) {
        if ((int32)r_u32(0x800A9A48u) > 0) w_u32(0x800A9A48u, r_u32(0x800A9A48u) - 1u);
        else {
            if (r_u16(0x800A9D70u)) { w_u16(0x800A9D70u, 0); return draft_scratch_result(native_stack_mark, (uint64)(0)); }
            entry = sub_80030E18(0); w_u32(0x800A6D7Cu, entry); if (!entry) return draft_scratch_result(native_stack_mark, (uint64)(0));
            object = r_u32(r_u32(0x800A851Cu) + (uint32)(int32)(int16)r_u16(entry) * 4u); w_u32(0x800A6D78u, entry);
            if (!r_u8(object + 17u)) {
                sub_800331D8();
                w_u32(0x800A8568u, r_u32(0x800A7FB0u) == 1 ? object + 19u : 0x8008FD9Cu);
                w_u32(0x800A9A68u, (uint32)(int32)(int16)r_u16(object + 8u));
                if (r_u16(0x800A5C04u)) sub_800313EC(entry);
                w_u16(0x800A8B34u, 2); w_u32(0x800A9A48u, 10); w_u16(0x800A973Cu, 1);
            } else { w_u16(0x800A8B34u, 1); w_u32(0x800A9A48u, 10); }
        }
    }
    if (r_u16(0x800A8B34u) == 2 && r_u16(0x800A973Cu) == 2) { w_u16(0x800A973Cu, 0); w_u16(0x800A8B34u, 0); }
    return draft_scratch_result(native_stack_mark, (uint64)(r_u16(0x800A8B34u) == 1 ? (uint32)-(r_u8(0x800A7BDFu) != 0) : 0));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_8005FA24 */
uint32 sub_8005FA24(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = sub_80069A50(), point = 0; int32 frames = (int32)r_u32(0x800A9010u);
    while (frames-- > 0) {
        if (r_u8(object + 35u) == 24u) {
            uint32 child = sub_800227C4(40);
            w_u8(child + 34u, 8); w_u16(child + 36u, 288); w_u16(child + 38u, 0);
            w_u8(child + 14u, r_u8(child + 14u) | 2u); w_u32(child, 0x8005FC64u);
            w_u16(child + 32u, r_u16(r_u32(0x800A62ECu) + 62u));
            w_u32(child + 20u, r_u32(object + 20u)); w_u32(child + 24u, r_u32(object + 24u)); w_u32(child + 28u, r_u32(object + 28u));
            w_u8(child + 13u, 16); w_u16(child + 8u, 0); w_u16(child + 10u, (sub_80069A50() & 255u) - 127u); w_u16(child + 16u, r_u16(object + 24u) - 100u);
        }
        w_u8(object + 35u, r_u8(object + 35u) - 1u);
        result = r_u8(object + 13u) - 1u; w_u8(object + 13u, result);
        if ((int8)r_u8(object + 35u) <= 0) return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(object)));
        result <<= 24;
        if ((int32)result < 0) {
            int32 step = 4096 / (int16)r_u16(object + 18u), angle = 4096 - step;
            if (!point) point = draft_scratch_adapter(12);
            for (;;) {
                uint32 index = ((uint32)angle & 4095u) * 2u; int32 radius = (int16)r_u16(object + 16u);
                w_u32(point, r_u32(object + 20u) + (uint32)((radius * (int16)r_u16(0x800102E0u + index)) >> 12));
                w_u32(point + 8u, r_u32(object + 28u) + (uint32)((radius * (int16)r_u16(0x80010AE0u + index)) >> 12));
                w_u32(point + 4u, r_u32(object + 24u) - 100u); sub_8005FDFC(point, 1, sub_80069A50() & 15u);
                { int32 previous = angle; angle -= step; if (previous <= 0) break; }
            }
            w_u8(object + 13u, 1); result = r_u16(object + 16u) + 160u; w_u16(object + 16u, result); w_u16(object + 18u, r_u16(object + 18u) + 3u);
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80066D7C */
uint32 sub_80066D7C(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temp = draft_scratch_adapter(104), old = temp + 8u, mesh = temp + 24u, vx = temp + 88u, vz = temp + 92u, hit = temp + 96u;
    int32 dt = (int32)r_u32(0x800A9010u); uint32 result;
    w_u32(old, r_u32(object + 20u)); w_u32(old + 4u, r_u32(object + 24u)); w_u32(old + 8u, r_u32(object + 28u));
    w_u16(object + 76u, r_u16(object + 76u) + r_u16(object + 66u) * (uint32)dt); w_u16(object + 78u, r_u16(object + 78u) + r_u16(object + 74u) * (uint32)dt);
    w_u16(temp, 0); w_u16(temp + 4u, r_u16(object + 60u) + r_u16(object + 76u)); w_u16(temp + 2u, r_u16(object + 62u) + r_u16(object + 78u));
    /* TODO: Bridge the matrix rotation routine */
    draft_call_adapter(0x80055134u, temp, object + 36u);
    w_u32(object + 20u, r_u32(object + 20u) + (uint32)(int16)r_u16(object + 68u) * (uint32)dt);
    w_u32(object + 24u, r_u32(object + 24u) + (uint32)(int16)r_u16(object + 70u) * (uint32)dt);
    w_u32(object + 28u, r_u32(object + 28u) + (uint32)(int16)r_u16(object + 72u) * (uint32)dt); w_u16(object + 70u, r_u16(object + 70u) + (uint32)dt);
    if (sub_8002F3FC(old, object + 20u) << 16) {
        w_u32(vx, (uint32)(int32)(int16)r_u16(object + 68u) << 16); w_u32(vz, (uint32)(int32)(int16)r_u16(object + 72u) << 16);
        sub_80023918(r_u32(old), r_u32(old + 8u), vx, vz); w_u16(object + 68u, r_u32(vx) >> 16); w_u16(object + 72u, r_u32(vz) >> 16);
        w_u32(old, r_u32(object + 20u)); w_u32(old + 4u, r_u32(object + 24u)); w_u32(old + 8u, r_u32(object + 28u));
    }
    result = (uint32)(int32)(int16)r_u16(object + 70u);
    if ((int32)result >= 0) {
        sub_80029DDC(object, mesh, r_u8(r_u32(0x800A8548u) + r_u16(object + 32u))); sub_8002A300(mesh); result = 6;
        if (sub_80051328(object, mesh, hit) << 16) {
            if (r_u16(hit) == 6) { /* TODO: Bridge the object impact routine */ draft_call_adapter(0x80054934u, object, 3u); return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(object))); }
            sub_8006706C(object + 20u, r_u8(object + 13u), 1);
            { static const uint32 fields[] = {66,74,68,72}; uint32 i; for (i = 0; i < 4; ++i) { int32 speed = (int16)r_u16(object + fields[i]); w_u16(object + fields[i], speed == -1 ? 0 : (uint32)(speed >> 1)); } }
            { int32 speed = -((int16)r_u16(object + 70u) >> 1); result = -((5 * dt) >> 1) < speed; w_u16(object + 70u, (uint32)speed); if (result) return draft_scratch_result(native_stack_mark, (uint64)(sub_8002289C(object))); }
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80038CDC */
uint32 sub_80038CDC(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 mode = sub_80037BB8(), bits, result = 0, masks = r_u16(0x800A5C94u) | r_u16(0x800A5C96u) | r_u16(0x800A5C92u) | 0x900u;
    w_u32(0x800A7C74u, 0); w_u32(0x800A7E4Cu, 0);
    if ((int16)mode != 2) masks |= r_u16(0x800A5C9Cu);
    bits = (uint16)(a1 & ~masks) | (uint32)(int32)(int16)sub_80038970(256);
    bits |= (uint32)(int32)(int16)sub_80038970(2048); bits |= (uint32)(int32)(int16)sub_80038970(r_u16(0x800A5C92u)); bits |= (uint32)(int32)(int16)sub_80038970(r_u16(0x800A5C96u));
    if ((int16)sub_80037BB8() != 2) bits |= (uint32)(int32)(int16)sub_80038970(r_u16(0x800A5C9Cu));
    bits = (uint16)(bits | sub_80038970(r_u16(0x800A5C94u)));
    if (bits & 256u) { if (!r_u16(0x800A9760u) && (!r_u32(0x800A625Cu) || r_u32(0x800A625Cu) == 3)) w_u16(0x800A967Cu, 1); return draft_scratch_result(native_stack_mark, (uint64)(0)); }
    if (bits & 2048u) { if (!r_u16(0x800A901Cu)) w_u16(0x800A8B30u, 1); return draft_scratch_result(native_stack_mark, (uint64)(0)); }
    if (!r_u16(0x800A901Cu)) {
        if ((int16)sub_80037BB8() != 2 || (int16)sub_80037BB8() != 3) { if (bits & 32768u) result = 8; else if (bits & 8192u) result = 16; }
        if (bits & 16384u) result |= 2;
        if (bits & r_u16(0x800A5C96u)) w_u32(0x800A7C74u, 4);
        if (((sub_80037BB8() << 16) == 0 || (int16)sub_80037BB8() == 3) && (bits & r_u16(0x800A5C9Cu))) w_u32(0x800A7C74u, 1);
        w_u16(0x800A974Cu, (int16)sub_80037BB8() == 2 ? (bits & 4096u) != 0 : (bits & 2u) != 0);
        if (bits & r_u16(0x800A5C94u)) sub_8003D6F0();
        if (bits & r_u16(0x800A5C90u)) { if (!r_u32(0x800A5C8Cu)) result |= 64; } else w_u32(0x800A5C8Cu, 0);
        if (bits & r_u16(0x800A5C98u)) result |= 1;
        if (((int16)sub_80037BB8() != 2 || (int16)sub_80037BB8() != 3) && (bits & 4096u)) result |= 1;
        if (bits & r_u16(0x800A5C9Au)) result |= 4;
        if (bits & r_u16(0x800A5C92u)) { w_u32(0x800A7E4Cu, 2); /* TODO: Bridge the audio routine */ draft_call_adapter(0x80035A08u, 7u, 2048u, 255u, 0u, 0u); }
        /* TODO: Bridge the movement mode routine */
        draft_call_adapter(0x800596DCu, r_u32(0x800A7E4Cu));
    }
    if ((uint32)r_u16(0x800A9734u) - 1u < 3u) result |= 4;
    if (r_u16(0x800A901Cu) == 1) result |= 4;
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)(int32)(int16)result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80042598 */
uint32 sub_80042598(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = 0, i;
    sub_80036E10(); sub_80037490(); sub_80036EDC(0); sub_800379BC(); w_u16(0x800A9A64u, 1); w_u16(0x800A8398u, 0); sub_80038964(2112);
    if (r_u16(0x800A9760u)) { /* TODO: Bridge the alternate audio resume routine */ draft_call_adapter(0x80070484u); } else sub_8007044C();
    do {
        sub_800697BC(); w_u16(0x800A98F4u, sub_800389DC() & 0xF6FFu); w_u16(0x800A98F4u, r_u16(0x800A98F4u));
        w_u16(0x800A98F4u, r_u16(0x800A98F4u) | sub_80038970(256)); w_u16(0x800A98F4u, r_u16(0x800A98F4u) | sub_80038970(2048));
        if (r_u16(0x800A98F4u) & 2048u) w_u16(0x800A8B30u, 0);
        sub_8002DC94(); result = r_u32(0x800A7E04u); if (!result) { sub_80022A68(3); result = r_u32(0x800A7E04u); } if (result == 1) sub_80022A68(3);
        sub_80021718(0x800A7EE4u, 0); w_u16(0x800A8566u, 1); sub_8005E31C(); sub_8005E7DC(); sub_80020E30(); sub_8001F690(); sub_8001F968(); sub_80036BE4(); sub_80070568();
        /* TODO: Bridge the render submission routines */
        draft_call_adapter(0x8001FF7Cu, 1u); sub_8005A944(); draft_call_adapter(0x8001F850u); w_u32(0x800A7E04u, 0);
    } while (r_u16(0x800A8B30u));
    sub_800375F0(); w_u16(0x800A9A64u, r_u16(0x800A9670u));
    if (r_u16(0x800A9670u) || r_u32(0x800A5C50u) != 1) {
        uint32 resume = r_u16(0x800A9670u) != 0; sub_800379FC();
        for (i = 0; i < 10; ++i) { /* TODO: Bridge the sound status and frame delay SDK routines */ result = (uint32)draft_call_adapter(0x8007B368u, 6u, 0u, 0u); w_u32(0x800A7BE0u, result); if (result == 1) break; draft_call_adapter(0x8007F8C8u, 3u); }
        result = sub_80036EDC((uint32)(int32)(int16)r_u16(resume ? 0x800A9CD0u : 0x800A975Cu));
    } else {
        sub_8003732C(r_u32(0x800A9A68u), 1); draft_call_adapter(0x8007F8C8u, 3u); sub_8003732C(r_u32(0x800A9A68u), 4); draft_call_adapter(0x8007F8C8u, 3u);
        for (i = 0; i < 10; ++i) { result = (uint32)draft_call_adapter(0x8007B368u, 6u, 0u, 0u); w_u32(0x800A7BE0u, result); if (result == 1) break; draft_call_adapter(0x8007F8C8u, 3u); result = i + 1u < 10u; }
    }
    w_u16(0x800A966Cu, 60); w_u32(0x800A5C50u, 0); return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80046A58 */
uint32 sub_80046A58(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 kind = (int16)r_u16(object + 58u), amount = (int16)r_u16(object + 80u), level = (int16)r_u16(object + 82u); uint32 owner, result;
    sub_800595F0((uint32)kind, (uint32)level);
    /* TODO: Bridge the existing upgrade and equipment routines */
    switch (kind) {
    case 0: if (r_u16(0x800A7F48u)) { uint32 player = r_u32(0x800A9018u); w_u32(player + 8u, r_u32(player + 8u) + (uint32)amount); } break;
    case 3: {
        int32 high = r_u8(0x800A8515u), low = r_u8(0x800A8514u), next = low;
        if (level - 1 < high) { next = amount; if (low >= amount) next = low + 16 * level; }
        else { high = level - 1; if (low < amount) next = amount; }
        if ((int16)next >= 256) next = 255;
        result = ((uint32)high << 8 & 0xFF00u) | ((uint32)next & 255u); w_u32(0x800A8514u, result); draft_call_adapter(0x8003D27Cu, (uint32)(int32)(int16)result); break;
    }
    case 4: draft_call_adapter(0x8003D5DCu, (uint32)level); draft_call_adapter(0x8003D02Cu, (uint32)level, (uint32)amount); break;
    case 7: draft_call_adapter(0x8003D02Cu, (uint32)level, (uint32)amount); break;
    case 6: draft_call_adapter(0x8003D6C4u); break;
    case 12:
        if ((int16)(uint32)draft_call_adapter(0x8003D67Cu) < level - 1) {
            draft_call_adapter(0x8003D694u, (uint32)(int32)(int16)(level - 1)); result = (uint32)(int32)(int16)(uint32)draft_call_adapter(0x8003D654u); result *= 18140u; w_u32(0x800A8538u, result); w_u32(0x800A56C4u, result);
        }
        w_u32(0x800A7C6Cu, r_u32(0x800A7C6Cu) + (uint32)amount); break;
    case 13: if ((int16)sub_8003D688() < level - 1) sub_8003D6A0((uint32)(int32)(int16)(level - 1));
    default: w_u32(0x800A7C6Cu, r_u32(0x800A7C6Cu) + (uint32)amount); break;
    }
    draft_call_adapter(0x80035A08u, r_u8(object + 14u) & 8u ? 40u : 47u, r_u8(object + 14u) & 8u ? 1024u : 2048u, 255u, 0u, 0u);
    if (r_u8(object + 67u) && r_u32(r_u32(0x800A851Cu) + (uint32)(int32)(int16)r_u16(0x800A9730u) * 4u) == object) draft_call_adapter(0x8004525Cu);
    if ((int8)r_u8(object + 67u) > 0 && (int8)r_u8(object + 67u) < 3) { w_u16(0x800A7F4Cu, r_u16(0x800A7F4Cu) - 1u); draft_call_adapter(0x80044F8Cu, 0u); }
    w_u16(object + 56u, 0xFFFFu); w_u8(object + 65u, 0); w_u8(object + 64u, 0); w_u8(object + 14u, r_u8(object + 14u) & 0xFDu);
    if ((int16)r_u16(object + 84u) != -1) { owner = r_u32(r_u32(0x800A851Cu) + (uint32)(int32)(int16)r_u16(object + 84u) * 4u); if (!r_u8(owner + 64u)) w_u8(owner + 66u, r_u8(owner + 66u) - 1u); }
    owner = (uint32)(int32)(int16)r_u16(object + 74u); amount = (int16)r_u16(object + 68u); w_u16(object + 84u, 0xFFFFu); result = sub_80030F08(owner, (uint32)amount, 1); w_u16(object + 74u, 0xFFFFu); w_u8(object + 67u, 0); return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

static uint64 draft_round3_clock(void) { return (uint64)r_u32(0x800A8928u) | (uint64)r_u32(0x800A892Cu) << 32; }
static uint64 draft_round3_deadline(uint32 address) { return (uint64)r_u32(address) | (uint64)r_u32(address + 4u) << 32; }
static void draft_round3_set_deadline(uint32 address, uint64 value) { w_u32(address, (uint32)value); w_u32(address + 4u, (uint32)(value >> 32)); }
static void draft_round3_meter(uint32 packet, int32 value, int32 divisor, uint32 tail)
{
    int32 count = value / divisor; if (count >= 20) count = 19; if (count <= 0) count = 1; if (value <= 0) count = 0;
    w_u8(packet + 5u, (uint32)count); w_u8(packet + 15u, 19u - (uint32)count + tail); w_u8(packet + 14u, 19u - (uint32)count + 29u); sub_80057D14(packet);
}
/* FUNCTION_MARKER: sub_80058600 */
uint32 sub_80058600(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i, code, pointer; int32 value;
    sub_80057FFC(0, 1, r_u32(0x800A86A0u), 512); sub_80057FFC(1, 0, r_u32(0x800A7E10u), 15);
    if (r_u32(0x800A71C0u) == 1) { w_u32(0x800A71C0u, 0); w_u32(0x800A71C4u, 90); }
    value = (int32)r_u32(0x800A9A34u);
    if (value >= 10 && value < 40 && r_u32(0x800A6258u) && r_u16(0x800A8B34u) != 2 && r_u16(0x800A9A64u) == 1) {
        sub_800331D8(); w_u32(0x800A8568u, r_u32(0x800A7FB0u) == 1 ? r_u32(value < 20 ? 0x800A8D88u : 0x800A8D8Cu) : 0x80090DF8u);
        w_u32(0x800A9A68u, value < 20 ? 400 : 401); w_u16(0x800A8B34u, 2); w_u16(0x800A973Cu, 1); w_u32(0x800A6258u, 0);
    }
    if (r_u16(0x800A8B34u) == 2 && !r_u32(0x800A625Cu)) {
        draft_round3_set_deadline(0x800A71A8u, sub_8006984C(0, 0, 3, 0) + draft_round3_clock());
        draft_round3_set_deadline(0x800A71B0u, sub_8006984C(0, 0, 0, 20) + draft_round3_clock()); w_u32(0x800A625Cu, 1);
    }
    if (r_u32(0x800A625Cu) == 3) { sub_80044534(32896, r_u32(0x800A8D6Cu), 0, 55); if (draft_round3_clock() >= draft_round3_deadline(0x800A71A8u)) { w_u32(0x800A625Cu, 2); w_u32(0x800A6270u, 0); } }
    if (r_u32(0x800A625Cu) == 1) {
        sub_80044534(32896, r_u32(0x800A8D6Cu), 0, 55);
        if (draft_round3_clock() >= draft_round3_deadline(0x800A71B0u)) {
            draft_round3_set_deadline(0x800A71B0u, sub_8006984C(0, 0, 0, 20) + draft_round3_clock());
            if ((int32)r_u32(0x800A6270u) >= 3) { w_u32(0x800A625Cu, 3); w_u32(0x800A6270u, 0); }
            else { /* TODO: Bridge the warning sound routine */ draft_call_adapter(0x80035A08u, 0u, 3072u, 255u, 0u, 0u); w_u32(0x800A6270u, r_u32(0x800A6270u) + 1u); }
        }
    }
    if (!r_u16(0x800A8B34u) && r_u32(0x800A625Cu) == 2) { w_u32(0x800A625Cu, 0); w_u32(0x800A6270u, 0); }
    { static const uint32 timers[] = {0x800A73C8u,0x800A71C4u,0x800A9CD8u}; for (i = 0; i < 3; ++i) { value = (int32)(r_u32(timers[i]) - 1u); w_u32(timers[i], value > 0 ? (uint32)value : 0); } }
    if (r_u32(0x800A9CD8u)) { code = r_u16(0x80090DE8u + r_u32(0x800A84A0u) * 2u); sub_80044534(8388736, r_u32(0x800A8B38u + code * 4u), 0, 87); }
    if (r_u32(0x800A73C8u)) { /* TODO: Bridge the current equipment selector */ code = r_u16(0x80090DA8u + (uint32)(int32)(int16)(uint32)draft_call_adapter(0x8003CFECu) * 2u); sub_80044534(128, r_u32(0x800A8B38u + code * 4u), 0, 71); }
    else if (r_u32(0x800A71C4u)) {
        code = r_u16(0x80090D24u + r_u32(0x800A71B8u) * 2u);
        if ((uint16)(code + 16u) < 4u) { static const uint32 tables[] = {0x80090D50u,0x80090D68u,0x80090D40u,0x80090D48u}; code = r_u16(tables[code - 65520u] + r_u32(0x800A71BCu) * 2u); }
        sub_80044534(32896, r_u32(0x800A8B38u + code * 4u), 0, 71);
    }
    if (r_u32(0x800A6260u) == 1 && (int32)r_u32(0x800A7E10u) < (int32)r_u32(0x800A9CD4u)) w_u32(0x800A6260u, 0);
    if (r_u32(0x800A9CD4u) == r_u32(0x800A7E10u) && !r_u32(0x800A6260u)) { draft_call_adapter(0x80035A08u, 40u, 2048u, 255u, 0u, 0u); w_u32(0x800A6260u, 1); }
    if (r_u32(0x800A6264u) == 1 && (int32)r_u32(0x800A86A0u) < (int32)r_u32(0x800A84A4u)) w_u32(0x800A6264u, 0);
    if (r_u32(0x800A84A4u) == r_u32(0x800A86A0u) && !r_u32(0x800A6264u)) { draft_call_adapter(0x80035A08u, 40u, 2048u, 255u, 0u, 0u); w_u32(0x800A6264u, 1); }
    for (pointer = 0x80090BA8u; r_u32(pointer) != 0xFFFFFFFFu; pointer += 20u) sub_80057D14(pointer);
    if (r_u16(0x800A9A38u) != 4 && ((int32)r_u32(0x800A86A0u) < 1025 || (int32)r_u32(0x800A7E10u) < 26)) {
        /* TODO: Bridge the warning texture selector */
        sub_80058508((uint32)draft_call_adapter(0x800582D4u, 17u), 8421504, 0x54000040u, 68, 10, 10, 64, 13, 992, 480, (uint32)-116, 49, 160);
    }
    for (i = 0; i < 2; ++i) if (r_u32(0x800A70A8u + i * 24u) == 1) sub_80058430(r_u32(0x800A70B0u + i * 24u), 0x54000040u, 19, 19, 11, 159, 44, 848, 481, 97u + 21u * i, 29u + 21u * i, 180);
    if ((int32)r_u32(0x800A86A0u) >= 121) {
        w_u32(0x800A84A4u, 2048); draft_round3_meter(0x80090CD4u, (int32)r_u32(0x800A86A0u), 107, 0); w_u32(0x800A84A4u, 255);
        /* TODO: Bridge the packed ammunition getter */
        if ((uint32)draft_call_adapter(0x8003D270u) & 0xFF00u) {
            value = (uint8)(uint32)draft_call_adapter(0x8003D270u) / 13; if (value >= 20) value = 19; if (value <= 0) value = 1; if (!(uint8)(uint32)draft_call_adapter(0x8003D270u)) value = 0;
            w_u8(0x80090D01u, (uint32)value); w_u8(0x80090D0Bu, 19u - (uint32)value + 44u); w_u8(0x80090D0Au, 19u - (uint32)value + 29u); sub_80057D14(0x80090CFCu);
        }
    }
    if ((int16)r_u16(0x800A930Cu) > 0) {
        value = (int16)r_u16(0x800A930Cu) / 19; if (value > 0) draft_round3_meter(0x80090CE8u, (int16)r_u16(0x800A930Eu), value, 0);
        w_u32(0x800A84A4u, 255); if ((int16)r_u16(0x800A9310u) > 0) draft_round3_meter(0x80090D10u, (int16)r_u16(0x800A9310u), 13, 44);
    }
    for (i = 0; i < 3; ++i) if (r_u32(0x800A9688u + i * 8u) || r_u32(0x800A968Cu + i * 8u)) {
        /* TODO: Bridge the selected weapon texture getter */
        sub_80058508((uint32)draft_call_adapter(0x80057CB8u, i), 8421504, 0x54000040u, 68, 10u - r_u8(0x800A6284u + i), 10, 64, r_u8(0x800A6280u + i) + 1u, 992, 480, (uint32)-116, 49, r_u8(0x800A627Cu + i));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}
