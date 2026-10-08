#include "psx.h"
#include "draft_signatures.h"

// FUNCTION_MARKER sub_80037BB8
uint32 sub_80037BB8(void) {
    uint32 native_stack_mark = draft_scratch_mark();
 return draft_scratch_result(native_stack_mark, (uint64)((uint32)(sint32)(sint16)r_u16(0x800A5C70u))); 
    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005D76C
void sub_8005D76C(uint32 a1, uint32 a2, uint32 a3) {
    uint32 native_stack_mark = draft_scratch_mark();
 (void)a2; w_u16(0x800A8530u, a3); w_u16(0x800A8532u, a1); 
    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80070428
uint32 sub_80070428(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 saved = r_u32(0x800A6464u);
    w_u32(0x800A6460u, 0u); w_u32(0x800A646Cu, 0u); w_u32(0x800A6454u, 0u);
    w_u32(0x800A6468u, 1u); w_u32(0x800A645Cu, saved); return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006F7A8
uint32 sub_8006F7A8(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 x = (sint32)r_u32(0x800A9CD0u) / 512;
    sint32 y = (sint32)(sint16)r_u16(0x800A9D6Cu) / 256;
    sint32 z = (sint32)r_u32(0x800A975Cu) / 512;
    w_u16(0x80091A36u, (uint32)x); w_u16(0x80091A46u, (uint32)y);
    w_u16(0x80091A56u, (uint32)z); w_u32(0x800A75C0u, 0u); return draft_scratch_result(native_stack_mark, (uint64)((uint32)z));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800704B4
uint32 sub_800704B4(void) {
    uint32 native_stack_mark = draft_scratch_mark();
 w_u32(0x800A6464u, 0u); sub_80070428(); w_u32(0x800A8B30u, 0u); return draft_scratch_result(native_stack_mark, (uint64)(sub_8006F7A8())); 
    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005C560
uint32 sub_8005C560(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index = r_u8(a1 + 47u), value;
    w_u32(a1 + 28u, 0u); w_u16(a1 + 30u, r_u16(0x80091044u + index * 2u));
    value = r_u16(0x8009104Cu + index * 2u); w_u16(a1 + 32u, value);
    if (index != 0u) w_u16(0x800A8564u, 0u); return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005B2EC
uint32 sub_8005B2EC(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 difference = r_u16(a1) - r_u16(a2); w_u16(a3, difference);
    difference = r_u16(a1 + 2u) - r_u16(a2 + 2u); w_u16(a3 + 2u, difference);
    difference = r_u16(a1 + 4u) - r_u16(a2 + 4u); w_u16(a3 + 4u, difference); return draft_scratch_result(native_stack_mark, (uint64)(difference));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005BA08
uint32 sub_8005BA08(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 mode = r_u32(0x800A9A38u);
    sint32 minimum = mode == 2u ? -17000 : mode == 4u ? -15000 : mode == 1u ? -9000 : -7800;
    return draft_scratch_result(native_stack_mark, (uint64)((sint32)a1 >= minimum ? a1 : (uint32)minimum));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80063824
uint32 sub_80063824(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 table = r_u32(0x800A62ECu), type = r_u16(a1 + 32u);
    if (type == (uint32)(sint32)(sint16)r_u16(table + 0x1Au)) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    if (type == (uint32)(sint32)(sint16)r_u16(table + 0x1Eu) || type == (uint32)(sint32)(sint16)r_u16(table + 0x148u)) {
        w_u8(a2 + 14u, r_u8(a2 + 14u) & 0xFDu); return draft_scratch_result(native_stack_mark, (uint64)(1u));
    }
    w_u16(a2 + 32u, r_u16(table + 0x1C2u)); return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80069974
uint64 sub_80069974(uint64 value)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 increment = (uint32)((sint32)r_u32(0x800A63D8u) >> 8) * 426u;
    return draft_scratch_result(native_stack_mark, (uint64)(value + (uint64)(sint64)(sint32)increment));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800697BC
uint32 sub_800697BC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    // TODO Bind original target 0x8006F23C
    sint32 duration = (sint32)(uint32)draft_call_adapter(0x8006F23Cu);
    uint32 quarter;
    if (duration / 4 == 0) duration = 4;
    if (duration / 4 >= 6) duration = 20;
    if (duration < 0) duration = 4;
    quarter = (uint32)(duration / 4);
    w_u32(0x800A9010u, quarter); w_u32(0x800A7E28u, quarter);
    w_u32(0x800A63D8u, quarter << 16); return draft_scratch_result(native_stack_mark, (uint64)(quarter << 16));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8004D874
uint32 sub_8004D874(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = sub_80045AD8(a1, 0x8004D184u);
    if (result == 0u) sub_8004D730(a1); return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005C270
uint32 sub_8005C270(uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    // TODO Bind addressable local vector
    uint32 difference = draft_scratch_adapter(8u), distance;
    sub_8005B2EC(a1, a2, difference);
    // TODO Bind original target 0x80069BE0
    distance = (uint32)draft_call_adapter(0x80069BE0u, (uint32)(sint32)(sint16)r_u16(difference + 4u), (uint32)(sint32)(sint16)r_u16(difference + 2u));
    if ((sint32)distance < (sint32)(a3 * r_u32(0x800A9010u))) {
        w_u16(a1, r_u16(a2)); w_u16(a1 + 2u, r_u16(a2 + 2u)); w_u16(a1 + 4u, r_u16(a2 + 4u)); return draft_scratch_result(native_stack_mark, (uint64)(1u));
    }
    sub_8005C194(a1, a2, a3); return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005B47C
uint32 sub_8005B47C(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 samples[3], height, reference;
    uint32 sum = 0u, count = 0u;
    uint32 normal = draft_scratch_adapter(8u), tag = draft_scratch_adapter(4u);
    w_u32(a1 + 4u, r_u32(a1 + 4u) + 150u);
    // TODO Bind original target 0x8002E310
    height = (sint32)(0u - (uint32)draft_call_adapter(0x8002E310u, a1, normal, tag));
    w_u32(a1 + 4u, r_u32(a1 + 4u) - 150u);
    if (height != 0) { w_u16(0x800A7ECEu, (uint32)height); return draft_scratch_result(native_stack_mark, (uint64)((uint32)height)); }
    reference = (sint32)(sint16)r_u16(0x800A7ECEu);
    samples[0] = (sint32)draft_call_adapter(0x8005B434u, a1, 128u, 128u);
    samples[1] = (sint32)draft_call_adapter(0x8005B434u, a1, 47u, (uint32)-175);
    samples[2] = (sint32)draft_call_adapter(0x8005B434u, a1, (uint32)-175, 47u);
    for (sint32 index = 2; index >= 0; --index) {
        uint32 delta = (uint32)samples[index] - (uint32)reference;
        sint32 absolute = (sint32)delta < 0 ? (sint32)(0u - delta) : (sint32)delta;
        if (samples[index] != 0 && absolute < 128) { ++count; sum += (uint32)samples[index]; }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(count != 0u ? (uint32)((sint32)sum / (sint32)count) : (uint32)reference));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80044618
uint64 sub_80044618(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint64 value; uint32 output; (void)a1; (void)a2;
    if (r_u32(0x800A7BF4u) == 0u && r_u32(0x800A9864u) == 1u && r_u32(0x800A9760u) == 1u) return draft_scratch_result(native_stack_mark, (uint64)(0x100000001ull));
    output = draft_scratch_adapter(16u);
    sub_800698C8(output, (uint64)r_u32(0x800A8928u) | ((uint64)r_u32(0x800A892Cu) << 32));
    w_u8(0x800A5F5Cu, r_u8(output)); w_u8(0x800A5F5Du, r_u8(output + 4u));
    w_u32(0x800A5F60u, r_u32(output + 8u)); w_u32(0x800A5F64u, r_u32(output + 12u));
    value = sub_80069974((uint64)r_u32(0x800A8928u) | ((uint64)r_u32(0x800A892Cu) << 32));
    w_u32(0x800A8928u, (uint32)value); w_u32(0x800A892Cu, (uint32)(value >> 32));
    value = sub_80069974((uint64)r_u32(0x800A9CECu) | ((uint64)r_u32(0x800A9CF0u) << 32));
    w_u32(0x800A9CECu, (uint32)value); w_u32(0x800A9CF0u, (uint32)(value >> 32)); return draft_scratch_result(native_stack_mark, (uint64)(value));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002066C
uint32 sub_8002066C(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 delta = r_u8(0x800A7BDDu) * r_u32(0x800A9010u);
    uint32 remaining = r_u16(0x800A7BD8u) - delta;
    w_u16(0x800A7BD8u, remaining);
    if ((remaining & 0x8000u) != 0u) {
        w_u32(0x800A7BD4u, a1 == 0xFFFFFFFFu ? 0u : 0xFFFFFFu);
        if ((sint32)(sint16)r_u16(0x800A7BD8u) >= (sint32)(0u - (delta << 1))) return draft_scratch_result(native_stack_mark, (uint64)(0u));
        { uint32 mode = r_u8(0x800A7BDEu); w_u16(0x800A7BD8u, 0u);
          if (mode == 1u || mode == 3u) w_u8(0x800A7BDCu, 0u); }
        return draft_scratch_result(native_stack_mark, (uint64)(1u));
    }
    { uint32 color = r_u32(0x800A7BD4u), amount = delta * a1;
      w_u32(0x800A7BD4u, ((color & 0xFFu) + amount) | ((color & 0xFF00u) + (amount << 8)) | ((color & 0xFF0000u) + (amount << 16))); }
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8001F868
uint32 sub_8001F868(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 ot = a3 + 4u * a1, mode, graph;
    w_u16(a2 + 12u, 320u); w_u32(a2 + 4u, a4 | 0x63000000u);
    w_u32(a2 + 8u, 0u); w_u16(a2 + 14u, 240u);
    w_u32(a2, (r_u32(ot) & 0xFFFFFFu) | 0x03000000u);
    w_u32(ot, (r_u32(ot) & 0xFF000000u) | (a2 & 0xFFFFFFu));
    w_u8(a2 + 19u, 1u);
    w_u32(a2 + 16u, (r_u32(a2 + 16u) & 0xFF000000u) | (r_u32(ot) & 0xFFFFFFu));
    w_u32(ot, (r_u32(ot) & 0xFF000000u) | ((a2 + 16u) & 0xFFFFFFu));
    graph = GetGraphType();
    mode = (uint32)(sint32)(sint16)(a5 * 32u);
    if (graph == 1u || GetGraphType() == 2u) mode &= 0x27FFu; else mode &= 0x9FFu;
    w_u32(a2 + 20u, mode | 0xE1000000u); return draft_scratch_result(native_stack_mark, (uint64)(a2 + 24u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800314A8
uint32 sub_800314A8(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 chosen[2] = { r_u32(0x800A5B70u), r_u32(0x800A5B74u) };
    sint32 nearest[2] = {655360, 655360}; uint32 result;
    if ((sint32)r_u32(0x800A9014u) >= 0 || r_u32(0x800A9730u) == 0u || r_u32(0x800A9A78u) == 0u) {
        uint32 target = r_u32(0x800A9730u); if (target == 0u) target = r_u32(0x800A9A78u);
        if (target == 0u) { w_u32(0x800A9688u, 0u); w_u32(0x800A968Cu, 0u); }
        else { w_u32(0x800A9688u, r_u32(r_u32(r_u32(0x800A851Cu) + 4u * target) + 20u));
               w_u32(0x800A968Cu, r_u32(r_u32(r_u32(0x800A851Cu) + 4u * target) + 28u)); }
        if ((sint32)r_u32(0x800A9014u) > 0) w_u32(0x800A9014u, r_u32(0x800A9014u) - 1u);
    }
    for (sint32 index = 1; index < (sint32)(sint16)r_u16(0x800A6094u); ++index) {
        uint32 object = r_u32(0x800A8934u + 4u * (uint32)(index - 1));
        if (r_u8(object + 64u) != 0u && (r_u8(object + 14u) & 1u) != 0u) {
            uint32 player = r_u32(0x800A7BACu);
            // TODO Bind original target 0x80069BE0
            sint32 distance = (sint32)(uint32)draft_call_adapter(0x80069BE0u, r_u32(player + 20u) - r_u32(object + 20u), r_u32(player + 28u) - r_u32(object + 28u));
            if ((r_u8(object + 14u) & 8u) != 0u) {
                uint32 group = r_u16(object + 70u) == 1u ? 0u : 1u;
                if (distance < nearest[group]) { chosen[group] = object; nearest[group] = distance; }
            }
        }
    }
    for (uint32 index = 0u; index < 2u; ++index) {
        w_u32(0x800A9690u + 8u * index, chosen[index] != 0u ? r_u32(chosen[index] + 20u) : 0u);
        w_u32(0x800A9694u + 8u * index, chosen[index] != 0u ? r_u32(chosen[index] + 28u) : 0u);
    }
    if ((sint32)r_u32(0x800A5FA4u) > 0) w_u32(0x800A5FA4u, r_u32(0x800A5FA4u) - 1u);
    result = r_u32(0x800A5FA4u);
    if (result == 0u) { w_u32(0x800A5FA4u, 0xFFFFFFFFu); result = r_u32(0x800A5FA0u) + 1u; w_u32(0x800A5FA0u, result); }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80041710
uint32 sub_80041710(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 position = draft_scratch_adapter(16u), object, random, kind, table;
    // TODO Bind original targets 0x800418E4 and 0x800226E4
    if ((uint32)draft_call_adapter(0x800418E4u, position) == 0u) return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    object = (uint32)draft_call_adapter(0x800226E4u, 452u); if (object == 0u) return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    for (uint32 offset = 56u; offset < 452u; ++offset) w_u8(object + offset, 0u);
    random = r_u32(0x800A63DCu) * 5u + 1u; kind = random % 6u;
    w_u32(object, 0x80041604u); w_u32(0x800A63DCu, random);
    w_u32(object + 20u, r_u32(position)); w_u32(object + 24u, r_u32(position + 4u)); w_u32(object + 28u, r_u32(position + 8u));
    table = r_u32(0x800A62ECu); w_u16(object + 32u, r_u16(table + 2u * r_u8(0x80013730u + kind * 10u)));
    w_u8(object + 14u, r_u8(object + 14u) | 2u); w_u8(object + 34u, 8u);
    // TODO Bind original target 0x80055A70
    sub_80055A70( object + 36u);
    for (uint32 index = 0u; index < 9u; ++index) {
        w_u16(object + 72u + 36u * index, r_u16(r_u32(0x800A62ECu) + 2u * r_u8(0x80013731u + kind * 10u + index)));
        w_u16(object + 74u + 36u * index, 8u);
    }
    sub_80055A70( object + 400u);
    w_u8(object + 398u, 8u); w_u16(object + 58u, 0xFFFFu); w_u32(object + 16u, 0x8009037Cu); w_u16(object + 424u, 7u);
    w_u16(object + 396u, r_u16(r_u32(0x800A62ECu) + 0xAAu));
    random = r_u32(0x800A63DCu) * 5u + 1u; w_u32(0x800A63DCu, random); w_u16(object + 448u, random & 0xFFFu);
    // TODO Bind original target 0x80022908
    draft_call_adapter(0x80022908u, object, object + 60u, 10u); return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80045AD8
uint32 sub_80045AD8(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 current = a1, found = 0u;
    sint32 link = (sint32)(sint16)r_u16(a1 + 160u);
    if ((link != -1 && r_u8(r_u32(r_u32(0x800A851Cu) + (uint32)link * 4u) + 65u) == 0u) || (sint8)r_u8(a1 + 66u) <= 0) {
        if ((sint8)r_u8(a1 + 66u) < -119) {
            w_u8(a1 + 66u, 127u); w_u16(a1 + 160u, 0xFFFFu); w_u8(a1 + 14u, 1u);
            w_u8(a1 + 64u, 0u); w_u8(a1 + 65u, 1u); w_u32(a1, 0x80029968u); return draft_scratch_result(native_stack_mark, (uint64)(0u));
        }
        w_u32(a1, a2); link = (sint32)(sint16)r_u16(a1 + 158u);
        if (link == -1) {
            uint32 index = (uint32)(sint32)(sint16)r_u16(a1 + 72u), type = r_u16(a1 + 68u), flags = r_u8(a1 + 14u);
            w_u8(a1 + 64u, 1u); w_u16(a1 + 160u, 0xFFFFu); w_u8(a1 + 66u, 1u); w_u8(a1 + 65u, 1u); w_u8(a1 + 14u, flags | 2u);
            sub_80030F08(index, type, 0u); return draft_scratch_result(native_stack_mark, (uint64)(1u));
        }
        do {
            uint32 object = r_u32(r_u32(0x800A851Cu) + (uint32)link * 4u);
            if (r_u8(object + 64u) != 0u) found = (uint32)link;
            link = (sint32)(sint16)r_u16(r_u32(r_u32(0x800A851Cu) + (uint32)link * 4u) + 158u);
        } while (link != -1 && found == 0u);
        link = (sint32)(sint16)r_u16(a1 + 156u);
        if (link != -1 && found == 0u) do {
            uint32 object = r_u32(r_u32(0x800A851Cu) + (uint32)link * 4u);
            if (r_u8(object + 64u) != 0u) found = (uint32)link;
            link = (sint32)(sint16)r_u16(r_u32(r_u32(0x800A851Cu) + (uint32)link * 4u) + 156u);
        } while (link != -1 && found == 0u);
        if (found != 0u) {
            uint32 replacement = r_u32(r_u32(0x800A851Cu) + (uint32)(sint32)(sint16)found * 4u);
            // TODO Bind original target 0x8004561C
            draft_call_adapter(0x8004561Cu, a1, replacement);
            w_u16(current + 160u, 0xFFFFu); w_u8(current + 66u, 1u); w_u8(current + 65u, 1u); current = replacement;
        }
        link = (sint32)(sint16)r_u16(current + 162u);
        w_u8(current + 14u, 1u); w_u8(current + 66u, 1u); w_u8(current + 65u, 1u); w_u8(current + 64u, 0u);
        if (link != -1 && found != 0u) {
            uint32 object = r_u32(r_u32(0x800A851Cu) + (uint32)link * 4u);
            if (r_u8(object + 64u) == 0u) { w_u8(object + 66u, r_u8(object + 66u) - 1u); w_u16(current + 162u, 0xFFFFu); }
        }
        w_u16(current + 114u, 4u); w_u32(current, 0x80045510u); return draft_scratch_result(native_stack_mark, (uint64)(1u));
    }
    if ((sint16)r_u16(a1 + 158u) == -1 && r_u32(0x800A9734u) != 0u) {
        w_u8(a1 + 14u, r_u8(a1 + 14u) | 2u);
        if (r_u32(0x800A9734u) == 1u) { sub_80030F08((uint32)(sint32)(sint16)r_u16(a1 + 76u), r_u16(a1 + 68u), 2u); w_u16(current + 76u, 0xFFFFu); }
        else if (r_u32(0x800A9734u) == 2u) { sub_80030F08((uint32)(sint32)(sint16)r_u16(a1 + 78u), r_u16(a1 + 68u), 3u); w_u16(current + 78u, 0xFFFFu); }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80030BAC
uint32 sub_80030BAC(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 first = draft_scratch_adapter(12u), second = draft_scratch_adapter(12u), original = draft_scratch_adapter(12u), collided;
    w_u16(a1 + 96u, 0u); w_u16(a1 + 98u, 0u);
    w_u32(first, r_u32(a4)); w_u32(first + 8u, r_u32(a4 + 8u)); w_u32(first + 4u, r_u32(a4 + 4u));
    w_u32(original, r_u32(a3)); w_u32(original + 8u, r_u32(a3 + 8u)); w_u32(original + 4u, r_u32(a3 + 4u));
    collided = (sub_8002F3FC(first, original) << 16) != 0u;
    w_u32(second, r_u32(a3)); w_u32(first, r_u32(second)); w_u32(second + 8u, r_u32(a3 + 8u)); w_u32(first + 8u, r_u32(second + 8u));
    w_u32(second + 4u, r_u32(a3 + 4u) - 200u); w_u32(first + 4u, r_u32(a3 + 4u) + 200u);
    if (sub_8003095C(second) != 0u || sub_8003095C(first) != 0u) { collided = 1u; w_u32(a3 + 4u, r_u32(a4 + 4u)); }
    w_u32(first, r_u32(a2)); w_u32(first + 8u, r_u32(a2 + 8u)); w_u32(first + 4u, r_u32(a3 + 4u));
    if (sub_8003095C(first) != 0u) { w_u32(a3, r_u32(original)); collided = 1u; w_u32(a3 + 8u, r_u32(original + 8u)); }
    else { w_u32(second + 4u, r_u32(a3 + 4u));
           if ((sub_8002F3FC(first, second) << 16) != 0u) { uint32 y = r_u32(second + 4u), z = r_u32(second + 8u); w_u32(a3, r_u32(second)); w_u32(a3 + 4u, y); w_u32(a3 + 8u, z); collided = 1u; } }
    { uint32 y = r_u32(a3 + 4u), z = r_u32(a3 + 8u); w_u32(first, r_u32(a3)); w_u32(first + 4u, y); w_u32(first + 8u, z); }
    w_u32(second + 4u, r_u32(a3 + 4u));
    for (uint32 index = 0u; (sint16)index < 8; ++index) {
        uint32 vertex = a5 + index * 8u;
        w_u32(second, (uint32)(sint32)(sint16)r_u16(vertex) + r_u32(a3));
        w_u32(second + 8u, (uint32)(sint32)(sint16)r_u16(vertex + 4u) + r_u32(a3 + 8u));
        if ((sub_8002F3FC(first, second) << 16) != 0u) {
            collided = 1u;
            if (r_u32(first) != 0u) w_u32(a3, r_u32(second) - (uint32)(sint32)(sint16)r_u16(vertex));
            if (r_u32(first + 8u) != 0u) w_u32(a3 + 8u, r_u32(second + 8u) - (uint32)(sint32)(sint16)r_u16(vertex + 4u));
            w_u32(first, r_u32(a3)); w_u32(first + 8u, r_u32(a3 + 8u));
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(collided));

    draft_scratch_release(native_stack_mark);
}

static void draft1_vertex(uint32 address, uint32 index)
{
    xport_gte_write_data(index * 2u, r_u32(address)); xport_gte_write_data(index * 2u + 1u, r_u32(address + 4u));
}
static void draft1_link(uint32 packet, uint32 ot, uint32 length)
{
    w_u32(packet, (r_u32(ot) & 0xFFFFFFu) | (length << 24)); w_u32(ot, (r_u32(ot) & 0xFF000000u) | (packet & 0xFFFFFFu));
}

// FUNCTION_MARKER sub_80017550
uint32 sub_80017550(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 source = a3 + 12u; (void)a5;
    xport_gte_write_data(6u, 0x24808080u);
    while (a7 != 0u) {
        draft1_vertex(a2 + 8u * r_u16(source + 6u), 0u); draft1_vertex(a2 + 8u * r_u16(source + 8u), 1u); draft1_vertex(a2 + 8u * r_u16(source + 10u), 2u);
        draft_gte_command_adapter(0x280030u); draft1_vertex(a2 + 8u * r_u16(source + 4u), 0u);
        --a7; draft_gte_command_adapter(0x158002Du);
        { uint32 depth = xport_gte_read_data(7u);
          if (depth != 0u) {
            w_u32(a1 + 8u, xport_gte_read_data(12u)); w_u32(a1 + 16u, xport_gte_read_data(13u)); w_u32(a1 + 24u, xport_gte_read_data(14u));
            w_u32(a1 + 12u, r_u32(source - 8u)); draft_gte_command_adapter(0xE80413u);
            draft1_link(a1, a4 + 4u * a6 + 4u * (depth >> 3), 7u);
            w_u32(a1 + 20u, r_u32(source - 4u)); w_u32(a1 + 28u, r_u32(source)); w_u32(a1 + 4u, xport_gte_read_data(22u)); a1 += 32u;
          } }
        source += 24u; a3 += 24u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8001C384
uint32 sub_8001C384(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 source = a3 + 4u; (void)a5;
    while (a7 != 0u) {
        draft1_vertex(a2 + 8u * r_u16(source + 6u), 0u); draft1_vertex(a2 + 8u * r_u16(source + 8u), 1u); draft1_vertex(a2 + 8u * r_u16(source + 10u), 2u);
        draft_gte_command_adapter(0x280030u); draft1_vertex(a2 + 8u * r_u16(source + 12u), 0u); draft_gte_command_adapter(0x158002Du);
        --a7; a3 += 20u;
        { uint32 depth = xport_gte_read_data(7u);
          if (depth != 0u) {
            draft_gte_command_adapter(0x1400006u);
            if ((sint32)xport_gte_read_data(24u) >= 0) {
                w_u32(a1 + 8u, xport_gte_read_data(12u)); w_u32(a1 + 12u, xport_gte_read_data(13u)); w_u32(a1 + 16u, xport_gte_read_data(14u));
                draft_gte_command_adapter(0x180001u); w_u32(a1 + 4u, r_u32(source)); w_u32(a1 + 20u, xport_gte_read_data(14u));
                draft1_link(a1, a4 + 4u * a6 + ((uint32)((sint32)depth >> 3) << 2), 5u); a1 += 24u;
            }
          } }
        source += 20u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8001A9B4
uint32 sub_8001A9B4(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 vertex = a2 + 8u * r_u16(a3 + 18u), radius = r_u16(a3 + 14u), negative = (0u - radius) & 0xFFFFu, translation[3], depth;
    (void)a5; (void)a7;
    xport_gte_write_data(0u, r_u16(vertex) | (r_u16(vertex + 2u) << 16)); xport_gte_write_data(1u, (uint32)(sint32)(sint16)r_u16(vertex + 4u));
    xport_gte_mvmva(0x480012u);
    for (uint32 index = 0u; index < 3u; ++index) translation[index] = xport_gte_read_data(25u + index);
    xport_gte_write_control(0u, 4096u); xport_gte_write_control(1u, 0u); xport_gte_write_control(2u, 4096u); xport_gte_write_control(3u, 0u); xport_gte_write_control(4u, 4096u);
    for (uint32 index = 0u; index < 3u; ++index) xport_gte_write_control(5u + index, translation[index]);
    xport_gte_write_data(0u, negative | (negative << 16));
    xport_gte_write_data(1u, 0u); draft_gte_command_adapter(0x180001u);
    w_u32(a1 + 28u, r_u32(a3 + 12u)); depth = xport_gte_read_data(19u);
    if (depth != 0u) {
        w_u32(a1 + 32u, xport_gte_read_data(14u));
        xport_gte_write_data(0u, radius | (radius << 16)); xport_gte_write_data(1u, 0u);
        xport_gte_write_data(2u, negative | (radius << 16)); xport_gte_write_data(3u, 0u);
        xport_gte_write_data(4u, radius | (negative << 16)); xport_gte_write_data(5u, 0u);
        w_u32(a1 + 20u, r_u32(a3 + 8u)); draft_gte_command_adapter(0x280030u);
        w_u32(a1 + 36u, r_u32(a3 + 16u)); w_u32(a1 + 4u, r_u32(a3 + 20u)); w_u32(a1 + 12u, r_u32(a3 + 4u));
        draft1_link(a1, a4 + 4u * a6 + 4u * (depth >> 5), 9u);
        w_u32(a1 + 8u, xport_gte_read_data(12u)); w_u32(a1 + 16u, xport_gte_read_data(13u)); w_u32(a1 + 24u, xport_gte_read_data(14u)); a1 += 40u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}

static void draft1_camera_copy(void)
{
    uint32 x = r_u32(0x800A6784u), y = r_u32(0x800A6788u);
    w_u32(0x800A5650u, x); w_u32(0x800A5654u, y); w_u32(0x800A5658u, r_u32(0x800A678Cu));
}

// FUNCTION_MARKER sub_80021718
uint32 sub_80021718(uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sint32 x, z, delta; uint32 reload = 0u, result;
    if (a2 != 0u) { w_u32(0x800A5664u, 3u); w_u32(0x800A5674u, a2); }
    else if (r_u32(0x800A5674u) != 0u) { w_u32(0x800A5664u, 3u); w_u32(0x800A5674u, 0u); }
    else {
        uint32 level = r_u8(0x80010000u + 4u * r_u32(0x800A7E28u) + r_u32(0x800A5664u) - 1u);
        if (level == r_u32(0x800A5668u)) { w_u32(0x800A566Cu, 0u); w_u32(0x800A5664u, level); }
        else { w_u32(0x800A5668u, level); w_u32(0x800A566Cu, 0u); }
    }
    w_u32(0x800A5670u, r_u32(0x800A5670u) + 1u);
    w_u32(0x800A677Cu, r_u32(0x800A5640u)); w_u32(0x800A6780u, r_u32(0x800A5644u));
    { uint32 y = r_u32(a1 + 4u), zz = r_u32(a1 + 8u); w_u32(0x800A6784u, r_u32(a1)); w_u32(0x800A6788u, y); w_u32(0x800A678Cu, zz); }
    w_u32(0x800A84ECu, 0u); w_u32(0x800A84E4u, 0u);
    x = ((sint32)(r_u32(0x800A6784u) + 2048u) >> 12) - 7;
    w_u32(0x800A84E8u, r_u32(0x800A6788u)); z = ((sint32)(r_u32(0x800A678Cu) + 2048u) >> 12) - 7;
    delta = (sint32)(r_u32(0x800A5640u) - (uint32)x); if (delta < 0) delta = (sint32)(0u - (uint32)delta);
    if (delta >= 14) reload = 1u;
    delta = (sint32)(r_u32(0x800A6780u) - (uint32)z); if (delta < 0) delta = (sint32)(0u - (uint32)delta);
    if (delta >= 14) reload = 1u;
    if (reload == 0u && r_u32(0x800A5638u) == r_u32(0x800A563Cu)) sub_800219E8();
    if (r_u32(0x800A677Cu) != (uint32)x || r_u32(0x800A6780u) != (uint32)z) {
        w_u32(0x800A5640u, (uint32)x); w_u32(0x800A5644u, (uint32)z);
        if (reload != 0u) { sub_80021E94(); if (r_u32(0x800A5638u) == r_u32(0x800A563Cu)) { draft1_camera_copy(); sub_800219E8(); } }
        else {
            // TODO Bind original target 0x8002201C
            draft_call_adapter(0x8002201Cu, r_u32(0x800A677Cu) - (uint32)x, r_u32(0x800A6780u) - (uint32)z);
        }
        w_u32(0x800A5670u, 0u);
    }
    if (r_u32(0x800A5638u) != r_u32(0x800A563Cu)) {
        w_u32(0x800A5638u, r_u32(0x800A563Cu));
        // TODO Bind original target 0x80022528
        draft_call_adapter(0x80022528u); draft1_camera_copy(); sub_800219E8();
    }
    { uint32 enabled = r_u32(0x800A5670u); draft1_camera_copy(); result = r_u32(0x800A678Cu); sub_800577F4(enabled); }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

static uint32 draft1_visibility(uint32 object)
{
    uint32 x = (uint32)((sint32)r_u32(object + 20u) >> 12) - r_u32(0x800A5640u);
    uint32 z = (uint32)((sint32)r_u32(object + 28u) >> 12) - r_u32(0x800A5644u);
    return x >= 14u || z >= 14u ? 0u : (r_u8(0x8008B794u + z * 14u + x) + 1u) & 0xFFu;
}

// FUNCTION_MARKER sub_80022A68
uint32 sub_80022A68(uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object, slot = r_u32(0x800A5688u), result;
    w_u32(0x800A5680u + 4u * slot, 0u);
    if (r_u32(0x800A9760u) == 0u && (a1 & 3u) == 0u) sub_80057528();
    object = r_u32(0x800A5678u); w_u32(0x800A6790u, 0u);
    while (object != 0u) {
        if ((r_u8(object + 14u) & 1u) != 0u) {
            w_u8(object + 12u, draft1_visibility(object));
            if (r_u8(object + 12u) >= ((r_u8(object + 14u) & 0x70u) >> 4) && ((r_u8(object + 15u) & 0x80u) == 0u || (r_u8(r_u32(object + 8u) + 14u) & 1u) != 0u)) {
                if ((a1 & 3u) != 0u) w_u8(object + 12u, (a1 & 1u) != 0u ? draft1_visibility(object) : 5u);
                // TODO Bind original indirect object callback
                if ((a1 & 1u) == 0u) draft_call_adapter(r_u32(object), object);
                if ((r_u8(object + 14u) & 2u) != 0u && r_u8(object + 12u) >= 4u) {
                    uint32 counter = (r_u8(object + 14u) & 4u) != 0u ? 0x800A6394u : 0x800A636Cu;
                    uint32 queue = counter == 0x800A6394u ? 0x800BE518u : 0x800BA8B8u;
                    uint32 count = r_u32(counter); w_u32(queue + 4u * count, object + 20u); w_u32(counter, count + 1u);
                    if ((r_u8(object + 14u) & 8u) != 0u) {
                        uint32 current = r_u32(0x800A5688u), pointer = 0x800A5680u + 4u * current, old = r_u32(pointer);
                        w_u32(pointer, old + 1u); w_u32(0x800A6794u + 512u * current + 4u * old, object);
                    }
                    if ((r_u8(object + 14u) & 0x80u) != 0u) {
                        uint32 packed = r_u32(object + 8u);
                        if ((packed & 0xF000u) != 0u) {
                            uint32 entry = object + (packed & 0xFFFu), index = 0u;
                            while (index < ((packed & 0xFFFFu) >> 12)) {
                                uint32 count2 = r_u32(0x800A636Cu); ++index;
                                w_u32(0x800BA8B8u + 4u * count2, entry); packed = r_u32(object + 8u); w_u32(0x800A636Cu, count2 + 1u); entry += 36u;
                            }
                            packed = r_u32(object + 8u);
                        }
                        if ((packed & 0xF0000000u) != 0u) {
                            uint32 entry = object + ((packed >> 16) & 0xFFFu), index = 0u;
                            while (index < (packed >> 28)) {
                                uint32 count2 = r_u32(0x800A6394u); ++index;
                                w_u32(0x800BE518u + 4u * count2, entry); packed = r_u32(object + 8u); w_u32(0x800A6394u, count2 + 1u); entry += 20u;
                            }
                        }
                    }
                }
                if ((r_u8(object + 14u) & 1u) != 0u) goto retain_object;
            }
            else {
                if ((r_u8(object + 15u) & 0x80u) != 0u) { uint32 owner = r_u32(object + 8u); w_u8(object + 15u, r_u8(object + 15u) & 0x7Fu); w_u8(owner + 15u, r_u8(owner + 15u) - 1u); }
                { uint32 callback = r_u32(object); w_u8(object + 14u, r_u8(object + 14u) & 0xFCu); draft_call_adapter(callback, object); }
            }
        }
        if ((r_u8(object + 15u) & 0x7Fu) == 0u) {
            uint32 previous = r_u32(0x800A6790u);
            if (previous != 0u) w_u32(previous + 4u, r_u32(object + 4u)); else w_u32(0x800A5678u, r_u32(object + 4u));
            if (r_u32(0x800A567Cu) == object) w_u32(0x800A567Cu, r_u32(0x800A6790u));
            // TODO Bind original target 0x80064D60
            draft_call_adapter(0x80064D60u, object); object = r_u32(object + 4u); continue;
        }
retain_object:
        w_u32(0x800A6790u, object); object = r_u32(object + 4u);
    }
    slot = r_u32(0x800A5688u); w_u32(0x800A568Cu, 0x800A6794u + 512u * slot);
    { uint32 count = r_u32(0x800A5680u + 4u * slot); result = 1u - slot; w_u32(0x800A5688u, result); w_u32(0x800A5690u, count); }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

static void draft1_reset_deadline(void)
{
    uint64 duration = sub_8006984C(0u, 0u, 30u, 0u);
    uint64 current = (uint64)r_u32(0x800A8928u) | ((uint64)r_u32(0x800A892Cu) << 32);
    duration += current; w_u32(0x800A6ECCu, (uint32)duration); w_u32(0x800A6ED0u, (uint32)(duration >> 32));
}

// FUNCTION_MARKER sub_800428B0
uint32 sub_800428B0(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    // TODO Bind original targets outside the scalar draft registry
    draft_call_adapter(0x800445E0u); draft1_reset_deadline();
    if (r_u32(0x800A9758u) != 2u || r_u32(0x800A7FBCu) == 1u) { sub_800704B4(); w_u32(0x800A6EC8u, 0u); w_u32(0x800A7FBCu, 0u); }
    w_u32(0x800A8398u, 0u); draft_call_adapter(0x800205C8u, 1u, 12u, 3u);
    w_u32(0x800A7F0Cu, 0u); w_u32(0x800A6EC4u, 0u); w_u32(0x800A98F4u, 0u); w_u32(0x800A9758u, 1u);
    draft_call_adapter(0x8007FED0u, 1u); w_u32(0x800A87F4u, 0u); w_u32(0x800A9A30u, r_u32(0x800A9A30u) + 1u);
    for (;;) {
        uint32 mode = 0u, state;
        sub_800697BC();
        if (r_u32(0x800A6EC4u) == 0u && r_u32(0x800A87F4u) == 0u) {
            sub_80044618(0u, 0u);
            if ((sub_800389DC() << 16) != 0u) {
                if (r_u32(0x800A6EC8u) == 1u) draft_call_adapter(0x80038964u, 0xFFFFu);
                w_u32(0x800A6EC8u, 0u); draft1_reset_deadline();
            }
            else {
                sint64 current = (sint64)((uint64)r_u32(0x800A8928u) | ((uint64)r_u32(0x800A892Cu) << 32));
                sint64 deadline = (sint64)((uint64)r_u32(0x800A6ECCu) | ((uint64)r_u32(0x800A6ED0u) << 32));
                if (current >= deadline) w_u32(0x800A6EC8u, 1u);
            }
            if ((sint16)sub_80037BB8() == -1) {
                if (r_u32(0x800A6EC8u) == 1u) draft_call_adapter(0x80038964u, 0xFFFFu);
                w_u32(0x800A6EC8u, 0u); draft1_reset_deadline();
            }
        }
        sub_8002DC94();
        if (r_u32(0x800A87F4u) != 0u) { draft_call_adapter(0x80036E10u); draft_call_adapter(0x800375A4u); draft_call_adapter(0x800360BCu); mode = 3u; }
        sub_80022A68(mode);
        if (r_u32(0x800A622Cu) != 0u) { w_u32(0x800A9A58u, r_u32(0x800A622Cu)); if (r_u32(0x800A87F4u) == 0u) sub_8005DC0C(0x800A7E54u); }
        sub_80021718(0x800A7EE4u, 0u); sub_8005E31C(); sub_8005E7DC(); sub_80020E30(); sub_8001F690(); sub_8001F968(); draft_call_adapter(0x80036BE4u);
        if (r_u32(0x800A6EC8u) != 0u) {
            if ((r_u32(0x800A5F64u) - 51u) < 49u) draft_call_adapter(0x80044534u, 0x808080u, r_u32(0x800A8C34u), 0u, 83u);
        }
        else draft_call_adapter(0x80070568u);
        draft_call_adapter(0x8001FF7Cu, 1u); draft_call_adapter(0x8005A944u); draft_call_adapter(0x8001F850u);
        if (r_u32(0x800A7F0Cu) != 0u && r_u32(0x800A6EC4u) == 0u) { w_u32(0x800A9758u, 0u); w_u32(0x800A6EC4u, 1u); }
        if (((sint16)r_u16(0x800A9734u) != 0 || r_u8(0x800A5F5Du) >= 3u) && r_u32(0x800A9758u) == 1u && r_u32(0x800A87F4u) == 0u && r_u32(0x800A6EC8u) == 1u) {
            w_u32(0x800A9758u, 2u); w_u32(0x800A6EC4u, 1u); w_u16(0x800A9734u, 4u);
        }
        state = r_u32(0x800A6EC4u);
        if (state == 1u) { draft_call_adapter(0x800205C8u, 1u, 12u, 0u); w_u32(0x800A6EC4u, 2u); state = 2u; }
        if (state == 2u && r_u8(0x800A7BDFu) != 0u) {
            if ((r_u32(0x800A9758u) - 2u) >= 2u) w_u32(0x800A9758u, 0u);
            if (r_u32(0x800A562Cu) == 0u) return draft_scratch_result(native_stack_mark, (uint64)(0u));
        }
    }

    draft_scratch_release(native_stack_mark);
}

static uint32 draft1_visible_points(const uint32 *points, uint32 count)
{
    uint32 left = 0u, right = 0u, top = 0u, bottom = 0u;
    for (uint32 index = 0u; index < count; ++index) {
        sint32 x = (sint16)points[index], y = (sint16)(points[index] >> 16);
        left |= x < 320; right |= x > 0; top |= y < 240; bottom |= y > 0;
    }
    return left && right && top && bottom;
}
static void draft1_triangle_grid(uint32 destination, const uint32 *vertices)
{
    for (uint32 axis = 0u; axis < 3u; ++axis) {
        sint32 a = (sint16)r_u16(vertices[0] + axis * 2u), b = (sint16)r_u16(vertices[1] + axis * 2u), c = (sint16)r_u16(vertices[2] + axis * 2u);
        w_u16(destination + axis * 2u, (uint32)a); w_u16(destination + 8u + axis * 2u, (uint32)b); w_u16(destination + 16u + axis * 2u, (uint32)c);
        w_u16(destination + 24u + axis * 2u, (uint32)((a + b) >> 1)); w_u16(destination + 32u + axis * 2u, (uint32)((b + c) >> 1)); w_u16(destination + 40u + axis * 2u, (uint32)((a + c) >> 1));
    }
}
static void draft1_quad_grid(uint32 destination, const uint32 *vertices)
{
    for (uint32 axis = 0u; axis < 3u; ++axis) {
        sint32 a = (sint16)r_u16(vertices[0] + axis * 2u), b = (sint16)r_u16(vertices[1] + axis * 2u), c = (sint16)r_u16(vertices[2] + axis * 2u), d = (sint16)r_u16(vertices[3] + axis * 2u);
        sint32 values[9] = {a, (a + b) >> 1, b, (a + c) >> 1, (c + b) >> 1, (b + d) >> 1, c, (c + d) >> 1, d};
        for (uint32 index = 0u; index < 9u; ++index) w_u16(destination + index * 8u + axis * 2u, (uint32)values[index]);
    }
}

// FUNCTION_MARKER sub_8001A110
uint32 sub_8001A110(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 source = a3 + 12u, grid = 0u, colors = 0u, projected = 0u;
    xport_gte_write_data(6u, 0x34808080u);
    while (a7 != 0u) {
        uint32 vertices[3], points[3], flags; sint32 area;
        for (uint32 index = 0u; index < 3u; ++index) { vertices[index] = a2 + 8u * r_u16(source + 6u + 4u * index); draft1_vertex(vertices[index], index); }
        draft_gte_command_adapter(0x280030u);
        for (uint32 index = 0u; index < 3u; ++index) draft1_vertex(a2 + 8u * r_u16(source + 4u + 4u * index), index);
        flags = draft_gte_control_adapter(31u); draft_gte_command_adapter(0x1400006u); --a7; area = (sint32)xport_gte_read_data(24u);
        if ((sint32)flags < 0 || area >= 1024) {
            for (uint32 index = 0u; index < 3u; ++index) points[index] = xport_gte_read_data(12u + index);
            if (draft1_visible_points(points, 3u)) {
                uint32 first_uv = r_u32(source - 8u), second_uv = r_u32(source - 4u), rgb[3];
                draft_gte_command_adapter(0xF80416u);
                if (grid == 0u) { grid = draft_scratch_adapter(48u); colors = draft_scratch_adapter(24u); projected = draft_scratch_adapter(12u); }
                draft1_triangle_grid(grid, vertices);
                w_u32(a5, first_uv & 0xFFFFu); w_u32(a5 + 4u, second_uv & 0xFFFFu); w_u32(a5 + 8u, r_u32(source));
                for (uint32 component = 0u; component < 2u; ++component) {
                    uint32 a = r_u8(a5 + component), b = r_u8(a5 + 4u + component), c = r_u8(a5 + 8u + component);
                    w_u8(a5 + 12u + component, (a + b) >> 1); w_u8(a5 + 16u + component, (b + c) >> 1); w_u8(a5 + 20u + component, (a + c) >> 1);
                }
                for (uint32 index = 0u; index < 3u; ++index) { rgb[index] = xport_gte_read_data(20u + index); w_u32(colors + index * 4u, rgb[index]); w_u32(projected + index * 4u, points[index]); }
                for (uint32 component = 0u; component < 3u; ++component) {
                    uint32 a = (rgb[0] >> (component * 8u)) & 0xFFu, b = (rgb[1] >> (component * 8u)) & 0xFFu, c = (rgb[2] >> (component * 8u)) & 0xFFu;
                    w_u8(colors + 12u + component, (a + b) >> 1); w_u8(colors + 16u + component, (b + c) >> 1); w_u8(colors + 20u + component, (a + c) >> 1);
                }
                // TODO Bind original target 0x8001F008 with its explicit scratch and texture arguments
                a1 = (uint32)draft_call_adapter(0x8001F008u, projected, a1, a2, a3, a4, a5, grid, first_uv & 0xFFFF0000u, second_uv & 0xFFFF0000u, grid, colors);
            }
        }
        else if (area >= 0) {
            uint32 depth;
            draft_gte_command_adapter(0x158002Du);
            w_u32(a1 + 8u, xport_gte_read_data(12u)); w_u32(a1 + 20u, xport_gte_read_data(13u)); w_u32(a1 + 32u, xport_gte_read_data(14u)); depth = xport_gte_read_data(7u);
            w_u32(a1 + 12u, r_u32(source - 8u)); draft_gte_command_adapter(0xF80416u);
            w_u32(a1 + 24u, r_u32(source - 4u)); w_u32(a1 + 36u, r_u32(source));
            draft1_link(a1, a4 + 4u * a6 + ((uint32)((sint32)depth >> 3) << 2), 9u);
            w_u32(a1 + 4u, xport_gte_read_data(20u)); w_u32(a1 + 16u, xport_gte_read_data(21u)); w_u32(a1 + 28u, xport_gte_read_data(22u)); a1 += 40u;
        }
        source += 28u; a3 += 28u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80018D44
uint32 sub_80018D44(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 source = a3 + 16u, grid = 0u, projected = 0u; (void)a5;
    while (a7 != 0u) {
        uint32 vertices[4], flags; sint32 area;
        for (uint32 index = 0u; index < 4u; ++index) vertices[index] = a2 + 8u * r_u16(source - 6u + 2u * index);
        for (uint32 index = 0u; index < 3u; ++index) draft1_vertex(vertices[index], index);
        draft_gte_command_adapter(0x280030u); draft1_vertex(vertices[3], 0u); flags = draft_gte_control_adapter(31u);
        draft_gte_command_adapter(0x1400006u); --a7; area = (sint32)xport_gte_read_data(24u);
        if ((sint32)flags < 0 || area >= 1024) {
            uint32 points[4];
            for (uint32 index = 0u; index < 3u; ++index) points[index] = xport_gte_read_data(12u + index);
            draft_gte_command_adapter(0x180001u); draft1_vertex(a2 + 8u * r_u16(source - 8u), 0u); points[3] = xport_gte_read_data(14u);
            if (draft1_visible_points(points, 4u)) {
                xport_gte_write_data(6u, r_u32(source - 12u)); draft_gte_command_adapter(0x108041Bu);
                if (grid == 0u) { grid = draft_scratch_adapter(72u); projected = draft_scratch_adapter(16u); }
                draft1_quad_grid(grid, vertices);
                for (uint32 index = 0u; index < 4u; ++index) w_u32(projected + index * 4u, points[index]);
                // TODO Bind original target 0x8001D870 with its explicit subdivision grid
                a1 = (uint32)draft_call_adapter(0x8001D870u, projected, a1, a2, a3, a4, grid, 4u * a6);
            }
        }
        else if (area >= 0) {
            uint32 depth;
            w_u32(a1 + 8u, xport_gte_read_data(12u)); w_u32(a1 + 12u, xport_gte_read_data(13u)); w_u32(a1 + 16u, xport_gte_read_data(14u));
            draft_gte_command_adapter(0x180001u); draft1_vertex(a2 + 8u * r_u16(source - 8u), 0u); w_u32(a1 + 20u, xport_gte_read_data(14u)); draft_gte_command_adapter(0x168002Eu);
            xport_gte_write_data(6u, r_u32(source - 12u)); depth = xport_gte_read_data(7u); draft_gte_command_adapter(0x108041Bu);
            draft1_link(a1, a4 + 4u * a6 + ((uint32)((sint32)depth >> 3) << 2), 5u); w_u32(a1 + 4u, xport_gte_read_data(22u)); a1 += 24u;
        }
        source += 20u; a3 += 20u;
    }
    w_u32(a8, a3); return draft_scratch_result(native_stack_mark, (uint64)(a1));

    draft_scratch_release(native_stack_mark);
}

static void draft1_load_matrix(uint32 matrix)
{
    for (uint32 index = 0u; index < 8u; ++index) xport_gte_write_control(index, r_u32(matrix + index * 4u));
}

// FUNCTION_MARKER sub_8001F968
uint32 sub_8001F968(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 camera_x = r_u32(0x800A7EE4u), camera_z = r_u32(0x800A7EECu), ot = r_u32(0x800A9A74u), cursor;
    uint32 camera = draft_scratch_adapter(32u), matrix = draft_scratch_adapter(32u), next = draft_scratch_adapter(4u), result;
    sint32 old_radius = 0; uint32 corners = draft_scratch_adapter(32u);
    for (uint32 index = 0u; index < 8u; ++index) w_u32(camera + index * 4u, r_u32(0x800A9324u + index * 4u));
    for (uint32 index = 0u; index < 4u; ++index) w_u16(corners + index * 8u + 4u, 0u);
    // TODO Bind original target 0x8005EBE4
    draft_call_adapter(0x8005EBE4u); cursor = r_u32(0x800A865Cu);
    if (r_u32(0x800A5638u) == 0u && r_u32(0x800A9A38u) != 4u) {
        uint32 vertices, source, extent, emitted = 0u;
        draft1_load_matrix(camera);
        xport_gte_write_data(0u, r_u16(0x800A9034u) | (r_u16(0x800A9038u) << 16)); xport_gte_write_data(1u, r_u32(0x800A903Cu)); xport_gte_mvmva(0x480012u);
        vertices = r_u32(r_u32(0x800A7E08u));
        for (uint32 axis = 0u; axis < 3u; ++axis) w_u32(matrix + 20u + 4u * axis, xport_gte_read_data(25u + axis));
        for (uint32 column = 0u; column < 3u; ++column) {
            for (uint32 row = 0u; row < 3u; ++row) xport_gte_write_data(9u + row, r_u16(0x800A9044u + row * 6u + column * 2u));
            xport_gte_mvmva(0x49E012u);
            for (uint32 row = 0u; row < 3u; ++row) w_u16(matrix + row * 6u + column * 2u, xport_gte_read_data(9u + row));
        }
        draft1_load_matrix(matrix);
        source = r_u32(0x800C0E00u + 4u * r_u16(0x800A9040u)); w_u32(next, r_u32(source)); extent = r_u32(source + 4u);
        while (emitted < extent) {
            uint32 object = r_u32(next), header = r_u32(object), count = header & 0x7FFu;
            emitted += count;
            // TODO Bind original indirect renderer dispatch and its eight scalar arguments
            cursor = (uint32)draft_call_adapter(r_u32(0x8008B728u + 4u * (header >> 24)), cursor, vertices, object, ot, 0u, 1750u, count, next);
        }
    }
    result = sub_80055A70(matrix);
    for (sint32 index = (sint32)r_u32(0x800A6394u) - 1; index >= 0; --index) {
        uint32 object = r_u32(0x800BE518u + 4u * (uint32)index), translation[3], texture, angle, depth, area;
        draft1_load_matrix(camera);
        xport_gte_write_data(0u, ((r_u32(object) - camera_x) & 0xFFFFu) | ((r_u32(object + 4u) & 0xFFFFu) << 16));
        xport_gte_write_data(1u, r_u32(object + 8u) - camera_z); xport_gte_mvmva(0x480012u);
        angle = r_u16(object + 18u) & 0xFFFu;
        w_u16(matrix, r_u16(0x80010AE0u + 2u * angle)); w_u16(matrix + 8u, r_u16(matrix));
        w_u16(matrix + 2u, r_u16(0x800102E0u + 2u * angle)); w_u16(matrix + 6u, 0u - r_u16(matrix + 2u));
        texture = r_u32(r_u32(0x800C0E00u + 4u * r_u16(object + 12u)));
        for (uint32 axis = 0u; axis < 3u; ++axis) { translation[axis] = xport_gte_read_data(25u + axis); w_u32(matrix + 20u + 4u * axis, translation[axis]); }
        draft1_load_matrix(matrix);
        { sint32 radius = (sint16)r_u16(object + 16u);
          if (radius != old_radius) {
            old_radius = radius;
            w_u16(corners, (uint32)radius); w_u16(corners + 2u, (uint32)radius); w_u16(corners + 8u, (uint32)-radius); w_u16(corners + 10u, (uint32)radius);
            w_u16(corners + 16u, (uint32)radius); w_u16(corners + 18u, (uint32)-radius); w_u16(corners + 24u, (uint32)-radius); w_u16(corners + 26u, (uint32)-radius);
          } }
        draft1_vertex(corners + 24u, 0u); draft_gte_command_adapter(0x180001u); depth = xport_gte_read_data(19u); result = cursor + 32u;
        if ((sint32)depth > 0) {
            w_u32(cursor + 32u, xport_gte_read_data(14u));
            for (uint32 vertex = 0u; vertex < 3u; ++vertex) draft1_vertex(corners + 8u * vertex, vertex);
            draft_gte_command_adapter(0x280030u); w_u32(cursor + 12u, r_u32(texture + 4u));
            draft_gte_command_adapter(0x1400006u); area = xport_gte_read_data(24u); result = (sint32)area < 16000;
            if ((sint32)area < 16000) {
                uint32 bucket = ot + 4u * (r_u8(object + 14u) + 500u) + ((uint32)((sint32)depth >> 5) << 2);
                w_u32(cursor + 8u, xport_gte_read_data(12u)); w_u32(cursor + 16u, xport_gte_read_data(13u)); w_u32(cursor + 24u, xport_gte_read_data(14u));
                w_u32(cursor + 20u, r_u32(texture + 8u)); w_u32(cursor + 28u, r_u32(texture + 12u)); w_u32(cursor + 36u, r_u32(texture + 16u)); w_u32(cursor + 4u, r_u32(texture + 20u));
                draft1_link(cursor, bucket, 9u); cursor += 40u; result = r_u32(bucket);
            }
        }
    }
    w_u32(0x800A865Cu, cursor); return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

static void draft1_quad_uv(uint32 uv, uint32 source)
{
    w_u32(uv, r_u32(source - 12u) & 0xFFFFu); w_u32(uv + 8u, r_u16(source - 8u));
    w_u32(uv + 24u, r_u32(source - 4u)); w_u32(uv + 32u, r_u32(source));
    for (uint32 component = 0u; component < 2u; ++component) {
        uint32 a = r_u8(uv + component), b = r_u8(uv + 8u + component), c = r_u8(uv + 24u + component), d = r_u8(uv + 32u + component);
        w_u8(uv + 4u + component, (a + b) >> 1); w_u8(uv + 12u + component, (a + c) >> 1); w_u8(uv + 16u + component, (c + b) >> 1);
        w_u8(uv + 20u + component, (b + d) >> 1); w_u8(uv + 28u + component, (c + d) >> 1);
    }
}

static uint32 draft1_textured_quads(uint32 cursor, uint32 vertices, uint32 source, uint32 ot, uint32 uv, uint32 bias, uint32 count, uint32 next_source, uint32 unlit)
{
    uint32 record = source + 16u, grid = 0u, projected = 0u;
    if (unlit == 0u) xport_gte_write_data(6u, 0x2C808080u);
    while (count != 0u) {
        uint32 positions[4], first_flags, flags, subdivide = 0u, clipping = 0u; sint32 area = 0;
        uint32 start = unlit != 0u ? 8u : 6u;
        for (uint32 index = 0u; index < 4u; ++index) positions[index] = vertices + 8u * r_u16(record + start + index * 2u);
        for (uint32 index = 0u; index < 3u; ++index) draft1_vertex(positions[index], index);
        draft_gte_command_adapter(0x280030u); draft1_vertex(positions[3], 0u); --count; first_flags = draft_gte_control_adapter(31u); flags = first_flags;
        if ((sint32)first_flags < 0) { subdivide = 1u; clipping = 1u; }
        else {
            draft_gte_command_adapter(0x1400006u); area = (sint32)xport_gte_read_data(24u);
            if (unlit != 0u) subdivide = ((uint32)area + 1023u) >= 2047u;
            else if (area >= 0) subdivide = area >= 1024;
        }
        if (subdivide != 0u) {
            uint32 points[4];
            for (uint32 index = 0u; index < 3u; ++index) points[index] = xport_gte_read_data(12u + index);
            draft_gte_command_adapter(0x180001u);
            if (unlit != 0u) xport_gte_write_data(22u, r_u32(record + 4u));
            else draft1_vertex(vertices + 8u * r_u16(record + 4u), 0u);
            if (clipping == 0u) flags = draft_gte_control_adapter(31u);
            points[3] = xport_gte_read_data(14u);
            if (draft1_visible_points(points, 4u)) {
                uint32 clut = r_u32(record - 12u) & 0xFFFF0000u, tpage = r_u32(record - 8u) & 0xFFFF0000u;
                if (unlit == 0u) draft_gte_command_adapter(0xE80413u);
                if (grid == 0u) { grid = draft_scratch_adapter(72u); projected = draft_scratch_adapter(16u); }
                draft1_quad_grid(grid, positions); draft1_quad_uv(uv, record);
                for (uint32 index = 0u; index < 4u; ++index) w_u32(projected + index * 4u, points[index]);
                if (clipping == 0u) cursor = sub_8001C52C(projected, cursor, vertices, source, ot, uv, grid, clut, tpage, bias);
                else {
                    // TODO Bind original clipping helpers 0x8001CB7C and 0x8001D204
                    cursor = (uint32)draft_call_adapter(unlit != 0u ? 0x8001D204u : 0x8001CB7Cu, projected, cursor, vertices, source, ot, uv, grid, clut, tpage, bias, flags);
                }
            }
        }
        else if (unlit != 0u || area >= 0) {
            uint32 depth;
            w_u32(cursor + 8u, xport_gte_read_data(12u)); w_u32(cursor + 16u, xport_gte_read_data(13u)); w_u32(cursor + 24u, xport_gte_read_data(14u));
            if (unlit != 0u) {
                w_u32(cursor + 12u, r_u32(record - 12u)); draft_gte_command_adapter(0x180001u);
                w_u32(cursor + 20u, r_u32(record - 8u)); w_u32(cursor + 28u, r_u32(record - 4u)); w_u32(cursor + 36u, r_u32(record)); w_u32(cursor + 4u, r_u32(record + 4u));
                draft_gte_command_adapter(0x168002Eu); w_u32(cursor + 32u, xport_gte_read_data(14u)); depth = xport_gte_read_data(7u);
            }
            else {
                w_u32(cursor + 36u, r_u32(record)); draft_gte_command_adapter(0x180001u); draft1_vertex(vertices + 8u * r_u16(record + 4u), 0u);
                w_u32(cursor + 12u, r_u32(record - 12u)); draft_gte_command_adapter(0x168002Eu); w_u32(cursor + 28u, r_u32(record - 4u));
                w_u32(cursor + 32u, xport_gte_read_data(14u)); depth = xport_gte_read_data(7u); draft_gte_command_adapter(0xE80413u);
            }
            draft1_link(cursor, ot + 4u * bias + ((uint32)((sint32)depth >> 3) << 2), 9u);
            if (unlit == 0u) { w_u32(cursor + 20u, r_u32(record - 8u)); w_u32(cursor + 4u, xport_gte_read_data(22u)); }
            cursor += 40u;
        }
        record += 32u; source += 32u;
    }
    w_u32(next_source, source); return cursor;
}

// FUNCTION_MARKER sub_80015E0C
uint32 sub_80015E0C(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    return draft_scratch_result(native_stack_mark, (uint64)(draft1_textured_quads(a1, a2, a3, a4, a5, a6, a7, a8, 0u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80017FD0
uint32 sub_80017FD0(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    uint32 native_stack_mark = draft_scratch_mark();

    return draft_scratch_result(native_stack_mark, (uint64)(draft1_textured_quads(a1, a2, a3, a4, a5, a6, a7, a8, 1u)));

    draft_scratch_release(native_stack_mark);
}
