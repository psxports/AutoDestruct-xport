#include "draft_signatures.h"
#include "game_scene.h"

uint32 sub_800329EC(void);
uint32 sub_80032B4C(void);
uint32 sub_80044E68(void);
uint32 sub_8003FAD0(uint32 object, uint32 mode, uint32 model, uint32 value);
uint32 sub_80072388(uint32 mode);
uint32 sub_80064B04(uint32 size, GameGeometryCallContext *context);
uint32 sub_8004F8E4(void);
uint32 sub_8004F47C(uint32 source, uint32 mode, GameGeometryCallContext *context);
void sub_8003D27C(uint32 value);
void sub_8003D694(uint32 value);
void sub_8003D324(uint32 value);
void sub_800796DC(GameMainCallContext *context);
void sub_80079C20(GameMainCallContext *context);

/* FUNCTION_MARKER: sub_800648A4 */
uint32 sub_800648A4(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 dt = r_u32(0x800A9010u), result;
    w_u16(object + 72u, r_u16(object + 72u) + 5u * dt); w_u16(object + 74u, r_u16(object + 74u) + (uint16)(10u * dt)); w_u16(object + 76u, r_u16(object + 76u));
    w_u16(object + 80u, r_u16(object + 80u)); w_u16(object + 82u, r_u16(object + 82u) + (uint16)(0u - 5u * dt)); w_u16(object + 84u, r_u16(object + 84u));
    w_u16(object + 88u, r_u16(object + 88u)); w_u16(object + 90u, r_u16(object + 90u) + (uint16)(15u * dt)); result = r_u16(object + 92u) + (uint16)(0u - 8u * dt); w_u16(object + 92u, result); return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_800732F8 */
uint32 sub_800732F8(uint32 data, GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i, sum = 0; (void)context; for (i = 1; i <= 100; ++i) sum += r_u32(data + i * 4u); return draft_scratch_result(native_stack_mark, (uint64)(sum != r_u32(data)));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_80073574 */
uint32 sub_80073574(GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    (void)context; w_u32(0x800A854Cu, (uint32)(int32)(int16)r_u16(0x800B589Cu)); w_u32(0x800A7E10u, (uint32)(int32)(int16)r_u16(0x800B58A0u)); w_u32(0x800A7C6Cu, (uint32)(int32)(int16)r_u16(0x800B589Eu));
    w_u16(0x800A9D6Cu, r_u16(0x800B58A2u)); w_u32(0x800A9CD0u, (uint32)(int32)(int16)r_u16(0x800B58A4u)); w_u32(0x800A975Cu, (uint32)(int32)(int16)r_u16(0x800B58A6u)); w_u32(0x800A84A0u, (uint32)(int32)(int16)r_u16(0x800B58AAu));
    sub_80072388((uint32)(int32)(int16)r_u16(0x800B58A8u)); return draft_scratch_result(native_stack_mark, (uint64)(sub_8003CAB4(0x800B58ACu)));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_8007361C */
uint32 sub_8007361C(uint32 count, GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = 0; (void)context; while (count--) result = (uint32)VSync(0); return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_80021550 */
uint32 sub_80021550(GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i; (void)context; for (i = 0; i < 196; ++i) { uint32 entry = 0x800A9D78u + (195u - i) * 12u; w_u16(entry, 0); w_u16(entry + 2u, 0xFFFFu); w_u32(entry + 8u, 0); }
    w_u32(0x800A5644u, (uint32)-1000); w_u32(0x800A5640u, (uint32)-1000); return draft_scratch_result(native_stack_mark, (uint64)((uint32)-1000));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_8004525C */
uint32 sub_8004525C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    w_u16(0x800A9014u, 2); w_u32(0x800A7F14u, 655360); w_u32(0x800A6EE0u, 655360); w_u16(0x800A9730u, 0); w_u16(0x800A9A78u, 0); return draft_scratch_result(native_stack_mark, (uint64)(655360));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_80044F8C */
uint32 sub_80044F8C(uint32 index)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 offset = (uint32)(int32)(int16)index * 2u; int32 result = (int16)r_u16(0x800A9734u);
    if (result) return draft_scratch_result(native_stack_mark, (uint64)((uint32)result));
    if ((int16)r_u16(0x800A6ED8u + offset) > 0) {
        static const uint32 fields[] = {0x800A7F82u,0x800A7F7Eu,0x800A7F50u,0x800A7F4Cu,0x800A7F60u,0x800A7F5Cu,0x800A7F58u,0x800A7F54u}; uint32 i;
        for (i = 0; i < 8; ++i) { result = (int16)r_u16(fields[i] + offset); if (result > 0) return draft_scratch_result(native_stack_mark, (uint64)((uint32)result)); }
    }
    if ((int16)index) { w_u16(0x800A9734u, 2); return draft_scratch_result(native_stack_mark, (uint64)(2)); }
    w_u16(0x800A9734u, 1); if (r_u32(0x800A9760u)) { sub_800329EC(); sub_80032B4C(); if (!r_u32(0x800A985Cu)) w_u16(0x800A9734u, 2); }
    w_u32(0x800A7C6Cu, r_u32(0x800A7C6Cu) + (uint32)(int32)(int16)r_u16(0x800A7F4Au)); return draft_scratch_result(native_stack_mark, (uint64)(sub_80044E68()));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_80063418 */
uint32 sub_80063418(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = r_u32(0x800A6358u); return draft_scratch_result(native_stack_mark, (uint64)(result ? sub_8003FAD0(object, 1, (uint32)(int32)(int16)r_u16(r_u32(0x800A62ECu) + 118u), 1024) : result));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_80040EF4 */
uint32 sub_80040EF4(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result = r_u32(0x800A6358u); if (!result) return draft_scratch_result(native_stack_mark, (uint64)(result)); result = sub_800227C4(40);
    w_u16(result + 36u, 128); w_u32(result, 0x80040E94u); w_u16(result + 38u, 0); w_u8(result + 34u, 8); w_u32(result + 20u, r_u32(object + 20u)); w_u32(result + 24u, r_u32(object + 24u) - 256u); w_u32(result + 28u, r_u32(object + 28u)); w_u8(result + 14u, r_u8(result + 14u) | 2u); w_u32(result + 8u, 4000); w_u16(result + 32u, r_u16(r_u32(0x800A62ECu) + 418u)); return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_800510E0 */
uint32 sub_800510E0(GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result; w_u32(0x800A851Cu, sub_80064B04(4, context)); sub_8004F8E4(); w_u16(0x800A6096u, 1); result = sub_8004F47C(0, 0, context); w_u16(0x800A6096u, 0); return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_8006F2F4 */
uint32 sub_8006F2F4(uint32 mask)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i; for (i = 0; i < 20; ++i) w_u16(0x800A905Cu + i * 2u, (mask & (1u << i)) != 0); return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_80073438 */
uint32 sub_80073438(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    w_u32(0x800A7C6Cu, r_u32(0x800A7A18u)); sub_8003D27C((uint32)(int32)(int16)(r_u16(0x800A7A1Cu) | 255u)); w_u32(0x800A854Cu, r_u32(0x800A7A20u)); sub_8003D6A0((uint32)(int32)(int16)r_u16(0x800A7A24u)); sub_8003D694((uint32)(int32)(int16)r_u16(0x800A7A28u)); w_u32(0x800A7E10u, 100); sub_8003D324(2048); w_u32(0x800A86A0u, 2048); w_u32(0x800A84A0u, r_u32(0x800A7A2Cu)); return draft_scratch_result(native_stack_mark, (uint64)(2048));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_8006F178 */
void sub_8006F178(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sub_800796DC(NULL); DisableEventPSX(r_u32(0x800A755Cu)); CloseEventPSX(r_u32(0x800A755Cu)); DisableEventPSX(r_u32(0x800A7560u)); CloseEventPSX(r_u32(0x800A7560u)); sub_80079C20(NULL);

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_8006F27C */
void sub_8006F27C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sub_800796DC(NULL); w_u32(0x800A7FACu, 8); sub_80079C20(NULL);

    draft_scratch_release(native_stack_mark);
}

void sub_800643EC(GameRenderCallContext *context);
uint32 sub_8001FF7C(uint32 mode, GameGeometryCallContext *context);
void sub_8001F850(void);
uint32 sub_800205C8(uint32 value, uint32 color, uint32 mode);
uint32 sub_80070518(void);
uint32 sub_80070540(void);
uint32 sub_800704E8(void);
uint32 sub_800226E4(uint32 size, GameGeometryCallContext *context);
uint32 sub_80059E2C(GameSceneCallContext *context);
uint32 sub_8007A7AC(uint32 mode);
uint32 sub_8007D3F0(uint32 destination, uint32 filename);

static void native_missing_frame(uint32 mode, uint32 audio, GameGeometryCallContext *context)
{
    sub_800697BC(); sub_8002DC94(); sub_80022A68(mode); sub_80021718(0x800A7EE4u, 0); sub_8005E31C(); sub_8005E7DC(); sub_80020E30(); sub_8001F690(); sub_8001F968(); sub_80036BE4(); if (audio) sub_80070568(); sub_8001FF7C(1, context); sub_8005A944(); sub_8001F850();
}
/* FUNCTION_MARKER: sub_80042D64 */
uint32 sub_80042D64(uint32 count, GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    do { do { --count; native_missing_frame(0, 0, context); } while ((int32)count > 0); } while (r_u32(0x800A562Cu)); return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_80042E14 */
uint32 sub_80042E14(GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    sub_800205C8(1, 12, 0); do { native_missing_frame(0, 0, context); } while (!r_u8(0x800A7BDFu) || r_u32(0x800A562Cu)); return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_80042ED4 */
uint32 sub_80042ED4(GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    w_u16(0x800A9A64u, 1); sub_8003708C(); w_u32(0x800A7BF8u, 0); w_u32(0x800A6EC4u, 0); sub_80038964(65535); w_u32(0x800A7F0Cu, 0); w_u32(0x800A84DCu, 0); sub_800205C8(1, 12, 3);
    if (r_u32(0x800A9760u) == 1) sub_80070518(); else sub_80070540();
    for (;;) {
        native_missing_frame(3, 1, context);
        if ((r_u32(0x800A7F0Cu) || r_u32(0x800A84DCu) == 1) && !r_u32(0x800A6EC4u)) { w_u32(0x800A9758u, 0); w_u32(0x800A6EC4u, 1); }
        if (r_u32(0x800A6EC4u) == 1) { sub_800205C8(1, 12, 0); w_u32(0x800A6EC4u, 2); }
        if (r_u32(0x800A6EC4u) == 2 && r_u8(0x800A7BDFu) && !r_u32(0x800A562Cu)) return draft_scratch_result(native_stack_mark, (uint64)(0));
    }

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_8004307C */
uint32 sub_8004307C(GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result; w_u16(0x800A9A64u, 1); sub_8003708C(); w_u32(0x800A7BF8u, 0); w_u32(0x800A6EC4u, 0); sub_800205C8(1, 12, 3); result = r_u32(0x800A9760u); if (result) return draft_scratch_result(native_stack_mark, (uint64)(result)); sub_800704E8();
    for (;;) {
        native_missing_frame(3, 1, context);
        if (r_u32(0x800A7BF8u) && !r_u32(0x800A6EC4u)) { w_u32(0x800A9758u, 0); w_u32(0x800A6EC4u, 1); }
        if (r_u32(0x800A6EC4u) == 1) { sub_800205C8(1, 12, 0); w_u32(0x800A6EC4u, 2); }
        if (r_u32(0x800A6EC4u) == 2 && r_u8(0x800A7BDFu) && !r_u32(0x800A562Cu)) return draft_scratch_result(native_stack_mark, (uint64)(0));
    }

    draft_scratch_release(native_stack_mark);
}
static void native_missing_render(GameGeometryCallContext *context)
{
    GameRenderCallContext render = {context->stack_pointer, context->return_address,context->caller_s0,context->caller_s1,context->caller_s2,context->caller_s3,context->caller_s4,context->caller_s5,context->caller_s6,context->caller_s7}; sub_800643EC(&render);
}
/* FUNCTION_MARKER: sub_8003BF34 */
uint32 sub_8003BF34(uint32 filename, GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    for (;;) { sub_80044534(8421504, 0x800A5DC8u, 0, (uint32)-6); sub_80044534(8421504, filename, 0, 20); native_missing_render(context); sub_8001F850(); sub_8001FF7C(0, context); }

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_80059E4C */
uint32 sub_80059E4C(uint32 filename, GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 found = 0; GameSceneCallContext scene = {context->stack_pointer,context->return_address,context->caller_s0};
    if (r_u32(0x800A9D58u) != 1) return draft_scratch_result(native_stack_mark, (uint64)(1));
    for (;;) {
        uint32 status = sub_8007A7AC(1);
        if (status & 16u) { sub_80044534(8421504, r_u32(0x800A8BFCu), 0, (uint32)-12); sub_80044534(8421504, r_u32(0x800A8BECu), 0, 1); }
        else if (status & 5u) sub_80044534(8421504, r_u32(0x800A8BE8u), 0, (uint32)-6);
        else if ((status & 2u) && !found) {
            if (!sub_8007D3F0(0x800A8670u, 0x800A6290u)) { sub_80044534(8421504, r_u32(0x800A8C00u), 0, (uint32)-24); sub_80044534(8421504, r_u32(0x800A8BCCu), 0, 1); sub_80044534(8421504, r_u32(0x800A8BFCu), 0, 14); sub_80059E2C(&scene); }
            else if (sub_8007D3F0(0x800A8670u, filename)) { sub_80044534(8421504, r_u32(0x800A8C3Cu), 0, (uint32)-6); found = 1; }
            else { sub_80044534(8421504, r_u32(0x800A8BCCu), 0, (uint32)-12); sub_80044534(8421504, r_u32(0x800A8BFCu), 0, 1); }
        }
        native_missing_render(context); sub_8001F850(); sub_8001FF7C(r_u32(0x800A9D60u) == 1 ? 2 : 0, context); if (found) return draft_scratch_result(native_stack_mark, (uint64)(1));
    }

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_800535DC */
uint32 sub_800535DC(uint32 object, uint32 mode, uint32 model, uint32 distance, GameGeometryCallContext *context)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 frame = context->stack_pointer - 72u, second = r_u16(context->stack_pointer + 16u), duration = r_u32(context->stack_pointer + 24u), child, i; (void)mode;
    child = sub_800226E4(148, context); for (i = 56; i < 148; ++i) w_u8(child + i, 0);
    w_u8(child + 34u, 8); w_u32(child + 8u, object); w_u8(child + 14u, (r_u8(child + 14u) | 2u) & 0xF5u); w_u32(child, 0x80052FB0u); w_u16(child + 32u, r_u16(r_u32(0x800A62ECu) + (uint32)(int32)(int16)model * 2u));
    if (r_u8(object + 14u) & 2u) w_u8(child + 14u, r_u8(child + 14u) | 2u); if (r_u8(object + 14u) & 8u) w_u8(child + 14u, r_u8(child + 14u) | 8u);
    w_u32(child + 16u, 0x80090AE8u); w_u16(child + 56u, 9); w_u8(child + 13u, r_u8(object + 13u)); for (i = 36; i <= 52; i += 4) w_u32(child + i, r_u32(object + i));
    w_u16(frame + 16u, 0); w_u16(frame + 18u, 0); w_u16(frame + 20u, distance + second); sub_80031B6C(object + 36u, frame + 16u, frame + 24u);
    w_u32(child + 20u, r_u32(object + 20u) + r_u32(frame + 24u)); w_u32(child + 28u, r_u32(object + 28u) + r_u32(frame + 32u)); w_u32(child + 24u, r_u32(object + 24u)); w_u16(child + 58u, duration);
    w_u16(child + 136u, sub_80055A9C(0u - r_u32(frame + 24u), 0u - r_u32(frame + 32u))); w_u16(child + 138u, 2048); w_u16(child + 144u, distance); w_u16(child + 146u, second); return draft_scratch_result(native_stack_mark, (uint64)(sub_8002B198(child, child + 64u)));

    draft_scratch_release(native_stack_mark);
}

/* FUNCTION_MARKER: sub_80072388 */
uint32 sub_80072388(uint32 mode)
{
    uint32 native_stack_mark = draft_scratch_mark();

    if (mode & 4u) w_u16(0x800A645Au, mode - 4u); else w_u16(0x800A6458u, mode); return draft_scratch_result(native_stack_mark, (uint64)(sub_800727B0()));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_800329EC */
uint32 sub_800329EC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i, result = 1; if (r_u32(0x800A9760u) != 1) return draft_scratch_result(native_stack_mark, (uint64)(result));
    for (i = 0; i < 4; ++i) { result = 0x800A97E4u + i * 30u + 6u * r_u32(0x800A9764u) + r_u32(0x800A9768u); w_u8(result, r_u8(0x800A6C50u + i * 4u)); } return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_80032AD8 */
uint32 sub_80032AD8(uint32 hours, uint32 minutes, uint32 seconds, uint32 fraction)
{
    uint32 native_stack_mark = draft_scratch_mark();

    return draft_scratch_result(native_stack_mark, (uint64)((fraction & 255u) + 100u * (seconds & 255u) + 6000u * (minutes & 255u) + 360000u * (hours & 255u)));

    draft_scratch_release(native_stack_mark);
}
static uint32 native_missing_timer(uint32 base)
{
    uint32 offset = 6u * r_u32(0x800A9764u) + r_u32(0x800A9768u); return sub_80032AD8(r_u8(base + offset), r_u8(base + 30u + offset), r_u8(base + 60u + offset), r_u8(base + 90u + offset));
}
/* FUNCTION_MARKER: sub_80032B4C */
uint32 sub_80032B4C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 previous = native_missing_timer(0x800A976Cu), result = (int32)native_missing_timer(0x800A97E4u) < (int32)previous, i;
    if (result) {
        for (i = 0; i < 4; ++i) { uint32 offset = i * 30u + 6u * r_u32(0x800A9764u) + r_u32(0x800A9768u); w_u8(0x800A976Cu + offset, r_u8(0x800A97E4u + offset)); }
        w_u32(0x800A985Cu, 1); w_u32(0x800A6C4Cu, 0);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8002E310(uint32 position, uint32 normal, uint32 tag, GameGeometryCallContext *context);
uint32 sub_80054D38(uint32 x, uint32 y, uint32 z, uint32 matrix, GameSceneCallContext *context);
/* FUNCTION_MARKER: sub_8003F7D8 */
void sub_8003F7D8(uint32 object, uint32 destination, uint32 distance)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 vector = draft_scratch_adapter(12); w_u32(vector, 0); w_u32(vector + 4u, 0); w_u32(vector + 8u, distance); sub_80031D50(object + 36u, object + 20u, vector, destination);

    draft_scratch_release(native_stack_mark);
}
/* FUNCTION_MARKER: sub_8003FAD0 */
uint32 sub_8003FAD0(uint32 object, uint32 mode, uint32 model, uint32 value)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch = draft_scratch_adapter(1024), position = scratch, normal = scratch + 16u, tag = scratch + 24u, dust_normal = scratch + 32u, child, i, angle; int32 delta;
    GameGeometryCallContext context = {0}; GameSceneCallContext scene = {0}; context.stack_pointer = scratch + 1024u; scene.stack_pointer = context.stack_pointer;
    if (mode) { for (i = 0; i < 3; ++i) w_u32(position + i * 4u, r_u32(object + 20u + i * 4u)); }
    else { uint32 type = r_u8(r_u32(0x800A8548u) + r_u16(object + 32u)); sub_8003F7D8(object, position, (uint32)(((int16)r_u16(r_u32(0x800A90ACu) + 40u * type + 34u) >> 1) - 50)); }
    delta = (int32)(sub_8002E310(position, normal, tag, &context) + r_u32(object + 24u));
    { uint32 magnitude = sub_8002E310(position, normal, tag, &context) + r_u32(object + 24u); if (delta < 0) magnitude = 0u - magnitude; if ((int32)magnitude >= 300) return draft_scratch_result(native_stack_mark, (uint64)(1)); }
    child = sub_800226E4(60, &context); w_u32(child, mode ? 0x8003FE30u : 0x8003FD78u); w_u32(position + 4u, r_u32(position + 4u) - 100u); w_u32(child + 20u, r_u32(position)); w_u32(child + 28u, r_u32(position + 8u)); w_u32(child + 24u, 0u - sub_8002E310(position, normal, tag, &context));
    w_u16(child + 8u, value + 160u); w_u8(child + 13u, mode); w_u32(child + 16u, object); w_u16(child + 56u, 0); w_u8(object + 15u, r_u8(object + 15u) + 1u);
    for (i = 0; i < 5; ++i) {
        child = sub_800226E4(56, &context); w_u8(child + 34u, 10); w_u32(child, 0x8003FF08u);
        w_u32(child + 20u, (sub_80069A50() & 255u) + r_u32(position) - 127u); w_u32(child + 24u, r_u32(position + 4u)); w_u32(child + 28u, (sub_80069A50() & 255u) + r_u32(position + 8u) - 127u);
        w_u32(child + 24u, 0u - sub_8002E310(child + 20u, dust_normal, normal, &context)); w_u16(child + 8u, value + (sub_80069A50() & 127u)); w_u16(child + 10u, 1024);
        angle = 0u - (sub_80055A9C((uint32)(int32)(int16)r_u16(dust_normal + 4u), (uint32)(int32)(int16)r_u16(dust_normal + 2u)) + 2048u); w_u16(child + 16u, angle);
        angle = sub_80055A9C((uint32)(int32)(int16)r_u16(dust_normal), (uint32)(int32)(int16)r_u16(dust_normal + 2u)) + 2048u; w_u16(child + 18u, angle);
        sub_80054D38((uint32)(int32)(int16)r_u16(child + 16u), 0, (uint32)(int32)(int16)angle, child + 36u, &scene); w_u16(child + 32u, model); w_u8(child + 14u, r_u8(child + 14u) | 2u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80071434(void);
/* FUNCTION_MARKER: sub_80070518 */
uint32 sub_80070518(void) { w_u32(0x800A6464u, 27); return sub_80070428(); }
/* FUNCTION_MARKER: sub_80070540 */
uint32 sub_80070540(void) { w_u32(0x800A6464u, 26); return sub_80070428(); }
/* FUNCTION_MARKER: sub_800704E8 */
uint32 sub_800704E8(void) { w_u32(0x800A6464u, 17); sub_80070428(); return sub_80071434(); }

uint32 sub_8003D67C(void);
/* FUNCTION_MARKER: sub_8007233C */
uint32 sub_8007233C(void) { return (int16)sub_80037BB8() == 2 ? (uint32)(int32)(int16)r_u16(0x800A645Au) + 4u : (uint32)(int32)(int16)r_u16(0x800A6458u); }
/* FUNCTION_MARKER: sub_80031F3C */
void sub_80031F3C(uint32 bytes, uint32 cursor, uint32 value, uint32 count)
{
    uint32 i; for (i = 0; (int32)i < (int32)count; ++i) {
        int32 bit = (int32)r_u32(cursor), byte = bit / 8; if ((value >> (i & 31u)) & 1u) { uint32 address = bytes + (uint32)byte; w_u8(address, r_u8(address) | (1u << ((uint32)(bit - byte * 8) & 31u))); } w_u32(cursor, (uint32)bit + 1u);
    }
}
/* FUNCTION_MARKER: sub_80031FBC */
uint32 sub_80031FBC(uint32 bytes, uint32 cursor, uint32 count)
{
    uint32 result = 0; int32 i = (int32)(count - 1u); for (; i >= 0; --i) { int32 bit = (int32)(r_u32(cursor) - 1u), byte = bit / 8; w_u32(cursor, (uint32)bit); if ((r_u8(bytes + (uint32)byte) >> ((uint32)(bit - byte * 8) & 31u)) & 1u) result |= 1u << ((uint32)i & 31u); } return result;
}
/* FUNCTION_MARKER: sub_80032024 */
uint32 sub_80032024(uint32 bytes, uint32 index)
{
    int32 bit = (int32)index, byte = bit / 8; return (r_u8(bytes + (uint32)byte) >> ((uint32)(bit - byte * 8) & 31u)) & 1u;
}
/* FUNCTION_MARKER: sub_80032050 */
uint32 sub_80032050(uint32 bytes, uint32 value, uint32 index)
{
    int32 bit = (int32)index, byte = bit / 8; uint32 shift = (uint32)(bit - byte * 8) & 31u, result = value << shift, address = bytes + (uint32)byte; w_u8(address, (r_u8(address) & ~(1u << shift)) | result); return result;
}
/* FUNCTION_MARKER: sub_80032094 */
uint32 sub_80032094(uint32 bytes, uint32 cursor)
{
    uint32 mark = draft_scratch_mark(), temp = draft_scratch_adapter(12), remaining = r_u32(cursor), result = 1, i = 0, n; for (n = 0; n < 6; ++n) w_u8(temp + n, r_u8(bytes + n)); w_u32(temp + 8u, remaining);
    while (remaining) { uint32 bits = sub_80031FBC(temp, temp + 8u, 3); remaining -= 3u; result += 1u + 5u * (result + 2u * i + bits); ++i; } return (uint32)draft_scratch_result(mark, result & 4095u);
}
/* FUNCTION_MARKER: sub_80032138 */
uint32 sub_80032138(uint32 bytes)
{
    static const uint32 mask[] = {180,147,86,169,101,150}; uint32 i, result = 0; for (i = 0; i < 6; ++i) { uint32 value = r_u8(bytes + i) ^ mask[i]; w_u8(bytes + i, value); if (i == 4) result = value; } return result;
}
/* FUNCTION_MARKER: sub_80071AAC */
uint32 sub_80071AAC(uint32 value, uint32 alphabet)
{
    uint32 i; for (i = 0; i < 32; ++i) if (r_u8(alphabet + i) == (value & 255u)) return i; return 0;
}
/* FUNCTION_MARKER: sub_80071AE0 */
uint32 sub_80071AE0(uint32 source, uint32 destination, uint32 alphabet)
{
    uint32 i = 9, result; do { --i; result = 2u * sub_80071AAC(r_u8(source + i), alphabet); w_u8(destination + i, result); } while (i); return result;
}
/* FUNCTION_MARKER: sub_80032184 */
uint32 sub_80032184(void)
{
    uint32 mark = draft_scratch_mark(), temp = draft_scratch_adapter(48), packed = temp, cursor = temp + 8u, shuffled = temp + 16u, encoded = temp + 24u, extraction = temp + 32u, i, result;
    uint32 mode = sub_8007233C(), selected = r_u32(0x800A84A0u), total = r_u32(0x800A854Cu), first = (uint32)(int32)(int16)sub_8003D688(), second = (uint32)(int32)(int16)sub_8003D67C(), score = r_u32(0x800A7C6Cu);
    for (i = 0; i < 6; ++i) w_u8(packed + i, 0); w_u32(cursor, 0);
    sub_80031F3C(packed, cursor, selected, 3); sub_80031F3C(packed, cursor, first, 2); sub_80031F3C(packed, cursor, mode, 3); sub_80031F3C(packed, cursor, second, 2); sub_80031F3C(packed, cursor, score, 17); sub_80031F3C(packed, cursor, total, 6);
    result = sub_80032094(packed, cursor); sub_80031F3C(packed, cursor, result, 12);
    for (i = 0; i < 45; ++i) sub_80032050(shuffled, sub_80032024(packed, i), r_u8(0x8008B88Cu + i)); sub_80032138(shuffled);
    for (i = 0; i < 6; ++i) { uint32 byte = r_u8(shuffled + i); w_u8(packed + i, byte); w_u8(encoded + i, byte); } w_u32(extraction, r_u32(cursor));
    for (i = 0; i < 9; ++i) { result = r_u8(0x800A5B78u + sub_80031FBC(encoded, extraction, 5)); w_u8(0x800A852Cu - i, result); } w_u8(0x800A852Du, 0); return (uint32)draft_scratch_result(mark, result);
}
/* FUNCTION_MARKER: sub_80071434 */
uint32 sub_80071434(void)
{
    sub_80032184(); w_u32(0x8009206Cu, r_u32(0x800A8524u)); w_u32(0x80092070u, r_u32(0x800A8528u)); w_u8(0x80092074u, r_u8(0x800A852Cu)); return sub_80071AE0(0x8009206Cu, 0x80092078u, 0x800A5B78u);
}

void sub_800557C0(uint32 destination, uint32 source, uint32 step)
{
    uint32 mark = draft_scratch_mark();
    uint32 delta = draft_scratch_adapter(12u);
    FUNCTION_MARKER(0x800557C0u, "1.EXE");
    w_u32(delta, r_u32(destination) - r_u32(source));
    w_u32(delta + 4u, r_u32(destination + 4u) - r_u32(source + 4u));
    w_u32(delta + 8u, r_u32(destination + 8u) - r_u32(source + 8u));
    sub_80055818(destination, delta, step);
    draft_scratch_release(mark);
}

uint32 sub_8005E200(uint32 mode)
{
    FUNCTION_MARKER(0x8005E200u, "1.EXE");
    if (r_u8(0x800A7E84u) == 0u)
    {
        w_u8(0x800A7E82u, 1u);
        w_u8(0x800A7E83u, mode);
    }
    else if (r_u8(0x800A7E83u) != 0u)
    {
        w_u8(0x800A7E82u, 1u);
        w_u8(0x800A7E83u, 1u);
    }
    return 1u;
}

uint32 sub_80049D98(uint32 wrapper)
{
    uint32 object, entry, packed, distance, dx, mirror;
    FUNCTION_MARKER(0x80049D98u, "1.EXE");
    w_u32(0x800A6FD0u, 0u);
    w_u16(r_u32(wrapper) + 112u, 0u);
    w_u8(r_u32(wrapper) + 199u, 1u);
    object = r_u32(wrapper);
    while ((uint32)(sint32)(sint16)r_u16(object + 188u) < r_u32(0x800A63E4u))
    {
        if ((sint32)r_u32(0x800A6FD0u) >= 10)
            break;
        entry = (uint32)draft_call_adapter(0x800476D8u, (uint32)(sint32)(sint16)r_u16(object + 188u));
        dx = r_u32(r_u32(wrapper) + 20u) - ((r_u32(entry) & 0x3FFu) << 9u);
        entry = (uint32)draft_call_adapter(0x800476D8u, (uint32)(sint32)(sint16)r_u16(r_u32(wrapper) + 188u));
        distance = (uint32)draft_call_adapter(0x80069BE0u, dx,
            r_u32(r_u32(wrapper) + 28u) - (((r_u32(entry) >> 10u) & 0x3FFu) << 9u));
        object = r_u32(wrapper);
        if ((sint32)distance < (sint32)r_u32(object + 80u))
        {
            w_u32(object + 80u, distance);
            object = r_u32(wrapper);
            w_u16(object + 170u, r_u16(object + 188u));
        }
        object = r_u32(wrapper);
        w_u16(object + 188u, r_u16(object + 188u) + 1u);
        object = r_u32(wrapper);
        w_u32(0x800A6FD0u, r_u32(0x800A6FD0u) + 1u);
    }
    if ((uint32)(sint32)(sint16)r_u16(r_u32(wrapper) + 188u) < r_u32(0x800A63E4u))
        return 0u;
    entry = (uint32)draft_call_adapter(0x800476D8u,
        (uint32)(sint32)(sint16)r_u16(r_u32(wrapper) + 170u));
    packed = r_u32(entry);
    object = r_u32(wrapper);
    w_u32(object + 20u, (packed & 0x3FFu) << 9u);
    w_u32(object + 128u, (packed & 0x3FFu) << 9u);
    packed = r_u32(entry);
    object = r_u32(wrapper);
    w_u32(object + 28u, ((packed >> 10u) & 0x3FFu) << 9u);
    w_u32(object + 136u, ((packed >> 10u) & 0x3FFu) << 9u);
    packed = r_u32(entry);
    object = r_u32(wrapper);
    w_u32(object + 24u, 0u - ((packed >> 12u) & 0xFF00u));
    w_u32(object + 132u, 0u - ((packed >> 12u) & 0xFF00u));
    mirror = r_u32(0x800A6EF4u);
    if (mirror != 0u)
    {
        w_u32(mirror, r_u32(r_u32(wrapper) + 128u));
        w_u32(mirror + 4u, r_u32(r_u32(wrapper) + 136u));
        w_u32(mirror + 8u, r_u32(r_u32(wrapper) + 132u));
    }
    w_u8(r_u32(wrapper) + 199u, 0u);
    w_u8(r_u32(wrapper) + 87u, 1u);
    w_u16(r_u32(wrapper) + 152u, 0u);
    return 1u;
}

uint32 sub_8005B434(uint32 position, uint32 offset_x, uint32 offset_z)
{
    uint32 mark = draft_scratch_mark();
    uint32 temporary = draft_scratch_adapter(32u);
    uint32 height;
    FUNCTION_MARKER(0x8005B434u, "1.EXE");
    // TODO Resolve the original uninitialized local Y word
    w_u32(temporary, r_u32(position) + offset_x);
    w_u32(temporary + 8u, r_u32(position + 8u) + offset_z);
    height = (uint32)draft_call_adapter(0x8002E310u, temporary, temporary + 16u, temporary + 24u);
    return draft_scratch_result(mark, (uint64)(0u - height));
}

uint32 sub_80048D30(uint32 object, uint32 position, uint32 target,
    uint32 velocity, uint32 direction, uint32 drive, uint32 turn_step)
{
    uint32 bearing, angle, magnitude, acceleration, vx, vz, result;
    sint32 difference, absolute, step = (sint16)turn_step;
    FUNCTION_MARKER(0x80048D30u, "1.EXE");
    sub_80055A9C(r_u32(target) - r_u32(position), r_u32(target + 8u) - r_u32(position + 8u));
    bearing = sub_80055A9C(r_u32(target) - r_u32(position), r_u32(target + 8u) - r_u32(position + 8u));
    draft_call_adapter(0x80069BE0u, r_u32(target) - r_u32(position), r_u32(target + 8u) - r_u32(position + 8u));
    angle = (bearing - r_u16(direction)) & 0xFFFu;
    difference = angle >= 2049u ? (sint16)(angle | 0xF000u) : (sint32)angle;
    absolute = difference < 0 ? -difference : difference;
    if (step >= absolute) {
        w_u16(direction, r_u16(direction) + (uint32)difference);
        w_u16(object + 112u, 0u);
    } else {
        w_u16(direction, r_u16(direction) + turn_step * (uint32)((difference >> 31) | 1));
    }
    angle = r_u16(direction) & 0xFFFu;
    acceleration = (uint32)(((sint32)drive >> 31) | 1) * (r_u32(0x800A9010u) << 4u);
    vx = r_u32(velocity) + (uint32)((sint32)(acceleration * (uint32)(sint32)(sint16)r_u16(0x800102E0u + angle * 2u)) >> 12);
    vz = r_u32(velocity + 8u) + (uint32)((sint32)(acceleration * (uint32)(sint32)(sint16)r_u16(0x80010AE0u + angle * 2u)) >> 12);
    bearing = sub_80055A9C(vx, vz);
    magnitude = (uint32)draft_call_adapter(0x80069BE0u, vx, vz);
    magnitude -= (uint32)((sint32)magnitude >> 7);
    if ((sint32)magnitude < 64) magnitude = 0u;
    angle = bearing & 0xFFFu;
    w_u32(velocity, (uint32)((sint32)(magnitude * (uint32)(sint32)(sint16)r_u16(0x800102E0u + angle * 2u)) >> 12));
    w_u32(velocity + 8u, (uint32)((sint32)(magnitude * (uint32)(sint32)(sint16)r_u16(0x80010AE0u + angle * 2u)) >> 12));
    acceleration = (uint32)(sint32)(sint16)r_u16(0x800A63DAu);
    w_u32(position, r_u32(position) + (uint32)((sint32)(acceleration * vx) >> 8));
    result = r_u32(position + 8u) + (uint32)((sint32)(acceleration * vz) >> 8);
    w_u32(position + 8u, result);
    w_u8(object + 199u, 0u);
    return result;
}

uint32 sub_8002CBD8(uint32 object, uint32 first_index, uint32 target, uint32 second_index)
{
    uint32 mark = draft_scratch_mark();
    uint32 first = 0x800B3484u + 20u * (uint32)(sint32)(sint16)first_index;
    uint32 second = 0x800B3484u + 20u * (uint32)(sint32)(sint16)second_index;
    uint32 radius = r_u16(first + 14u) + r_u16(second + 14u);
    uint32 dy = r_u32(object + 24u) - r_u32(target + 24u);
    uint32 result, scratch, x, z, angle, damage, remaining;
    static const sint16 square[8] = {100,-100,100,100,-100,100,-100,-100};
    FUNCTION_MARKER(0x8002CBD8u, "1.EXE");
    if ((sint32)dy < 0) dy = r_u32(target + 24u) - r_u32(object + 24u);
    result = (sint32)radius < (sint32)dy;
    if (result) return draft_scratch_result(mark, result);
    result = r_u32(object + 16u);
    if (target == result) return draft_scratch_result(mark, result);
    result = (uint32)(sint32)(sint16)r_u16(target + 58u);
    if (!result) return draft_scratch_result(mark, result);
    scratch = draft_scratch_adapter(88u);
    x = r_u32(target + 20u); z = r_u32(target + 28u);
    w_u32(scratch + 32u, r_u32(first) - x);
    w_u32(scratch + 40u, r_u32(first + 8u) - z);
    w_u32(scratch + 48u, r_u32(object + 20u) - x);
    w_u32(scratch + 56u, r_u32(object + 28u) - z);
    for (uint32 index = 0u; index < 8u; ++index)
        w_u16(scratch + 4u * index, (uint16)square[index]);
    result = (uint32)draft_call_adapter(0x8002A38Cu, scratch + 48u, scratch + 32u, scratch);
    if ((result << 16u) == 0u) return draft_scratch_result(mark, 255u);
    w_u16(target + 56u, 255u);
    angle = sub_80055A9C(r_u32(object + 20u) - r_u32(first),
        r_u32(object + 28u) - r_u32(first + 8u)) & 0xFFFu;
    w_u32(scratch + 64u, (uint32)(sint32)(sint16)r_u16(0x800102E0u + 2u * angle) << 8u);
    w_u32(scratch + 72u, (uint32)(sint32)(sint16)r_u16(0x80010AE0u + 2u * angle) << 8u);
    draft_call_adapter(r_u32(r_u32(target + 16u) + 24u), target, scratch + 64u);
    w_u32(object + 20u, x + r_u32(scratch + 32u));
    w_u32(object + 28u, z + r_u32(scratch + 40u));
    w_u16(object + 56u, r_u8(0x800A5774u + (uint32)(sint32)(sint16)r_u16(object + 58u)));
    result = (uint32)(sint32)(sint16)r_u16(target + 58u);
    if ((sint32)result < 0) return draft_scratch_result(mark, result);
    damage = (uint32)draft_call_adapter(0x8003D338u, target + 176u,
        (uint32)(sint32)(sint16)r_u16(object + 58u));
    remaining = r_u16(target + 58u) - damage;
    w_u16(target + 58u, remaining);
    result = 1u;
    if ((sint16)remaining <= 0)
    {
        if ((sint16)remaining < 0)
        {
            w_u16(target + 58u, 0u);
            w_u16(0x800A9310u, 0u);
            w_u16(0x800A930Eu, 0u);
        }
    }
    else if ((sint16)r_u16(target + 70u) == 1)
    {
        w_u16(0x800A930Eu, remaining);
        w_u16(0x800A930Cu, r_u16(target + 166u));
        result = r_u8(target + 176u);
        w_u16(0x800A9310u, result);
    }
    return draft_scratch_result(mark, result);
}

uint32 sub_80061418(uint32 object, uint32 parameter)
{
    uint32 child;
    FUNCTION_MARKER(0x80061418u, "1.EXE");
    w_u8(0x800A8FB8u, 1u);
    w_u8(0x800A8FB7u, 20u);
    w_u8(0x800A8FB4u, r_u8(0x800A8FB4u) | 2u);
    w_u32(0x800A8FA0u, r_u32(object + 20u) - r_u32(0x800A7EE4u));
    w_u32(0x800A8FA4u, r_u32(object + 24u));
    w_u32(0x800A8FA8u, r_u32(object + 28u) - r_u32(0x800A7EECu));
    child = sub_800227C4(40u);
    w_u8(child + 34u, 8u);
    w_u32(child, 0x80061500u);
    w_u32(child + 20u, r_u32(object + 20u));
    w_u32(child + 24u, r_u32(object + 24u));
    w_u16(child + 8u, 24u);
    w_u16(child + 10u, parameter);
    w_u32(child + 28u, r_u32(object + 28u));
    return child;
}

uint32 sub_80061500(uint32 object)
{
    uint32 result = (uint32)(sint32)(sint16)r_u16(object + 8u);
    sint32 count;
    uint32 child;
    FUNCTION_MARKER(0x80061500u, "1.EXE");
    if ((sint32)result <= 0)
        return sub_8002289C(object);
    count = (sint32)r_u32(0x800A9010u);
    while (count > 0)
    {
        child = sub_800227C4(40u);
        w_u8(child + 34u, 8u);
        w_u16(child + 32u, r_u16(object + 10u));
        w_u8(child + 14u, r_u8(child + 14u) | 2u);
        w_u32(child + 20u, r_u32(object + 20u));
        w_u32(child + 24u, r_u32(object + 24u));
        w_u16(child + 36u, 288u);
        w_u32(child, 0x80061628u);
        w_u16(child + 38u, 0u);
        w_u8(child + 13u, 18u);
        w_u32(child + 28u, r_u32(object + 28u));
        w_u16(child + 8u, (sub_80069A50() & 31u) - 16u);
        w_u16(child + 10u, 0u - (sub_80069A50() & 15u));
        w_u16(child + 16u, (sub_80069A50() & 31u) - 16u);
        w_u16(child + 18u, sub_80069A50() & 255u);
        result = r_u16(object + 8u) - 1u;
        w_u16(object + 8u, result);
        --count;
    }
    return result;
}

uint32 sub_8006108C(uint32 object)
{
    uint32 child;
    FUNCTION_MARKER(0x8006108Cu, "1.EXE");
    w_u8(0x800A8FB8u, 1u);
    w_u8(0x800A8FB7u, 20u);
    w_u8(0x800A8FB4u, r_u8(0x800A8FB4u) | 2u);
    w_u32(0x800A8FA0u, r_u32(object + 20u) - r_u32(0x800A7EE4u));
    w_u32(0x800A8FA4u, r_u32(object + 24u));
    w_u32(0x800A8FA8u, r_u32(object + 28u) - r_u32(0x800A7EECu));
    child = sub_800227C4(40u);
    w_u32(child + 20u, r_u32(object + 20u));
    w_u32(child + 24u, r_u32(object + 24u));
    w_u32(child, 0x80061174u);
    w_u32(child + 28u, r_u32(object + 28u));
    w_u16(child + 10u, 160u);
    w_u16(child + 16u, 2u);
    w_u16(child + 18u, 288u);
    w_u16(child + 8u, r_u16(object + 24u));
    return child;
}

uint32 sub_80061628(uint32 object)
{
    uint32 step = r_u32(0x800A9010u), result;
    FUNCTION_MARKER(0x80061628u, "1.EXE");
    if ((sint8)r_u8(object + 13u) <= 0)
    {
        if ((sub_80069A50() & 3u) >= 2u)
            return sub_8002289C(object);
        w_u16(object + 18u, (uint32)((sint16)r_u16(object + 18u) >> 1));
        w_u16(object + 32u, r_u16(r_u32(0x800A62ECu) + 78u));
        w_u8(object + 13u, sub_80069A50() & 31u);
        w_u32(object, 0x80061738u);
        return 0x80061738u;
    }
    w_u8(object + 13u, r_u8(object + 13u) - step);
    w_u32(object + 20u, r_u32(object + 20u) + step * (uint32)(sint32)(sint16)r_u16(object + 8u));
    w_u32(object + 28u, r_u32(object + 28u) + step * (uint32)(sint32)(sint16)r_u16(object + 16u));
    w_u32(object + 24u, r_u32(object + 24u) + step * (uint32)(sint32)(sint16)r_u16(object + 10u));
    result = r_u16(object + 38u) + step * (uint32)(sint32)(sint16)r_u16(object + 18u);
    w_u16(object + 38u, result);
    return result;
}

uint32 sub_80061174(uint32 object)
{
    uint32 mark = draft_scratch_mark();
    uint32 step = r_u32(0x800A9010u), scratch, material, angle, old_angle, result;
    sint32 divisor = (sint16)r_u16(object + 16u), increment;
    FUNCTION_MARKER(0x80061174u, "1.EXE");
    material = r_u16(r_u32(0x800A62ECu) + 60u);
    if ((sint16)r_u16(object + 18u) < 36)
        return draft_scratch_result(mark, sub_8002289C(object));
    if (divisor == 0) abort();
    increment = 4096 / divisor;
    angle = 4096u - (uint32)increment;
    scratch = draft_scratch_adapter(16u);
    for (;;)
    {
        uint32 index = (angle & 4095u) * 2u;
        uint32 radius = (uint32)(sint32)(sint16)r_u16(object + 10u);
        sint32 product_x = (sint32)(radius * (uint32)(sint32)(sint16)r_u16(0x800102E0u + index));
        sint32 product_z = (sint32)(radius * (uint32)(sint32)(sint16)r_u16(0x80010AE0u + index));
        w_u32(scratch, r_u32(object + 20u) + (uint32)(product_x >> 12));
        w_u32(scratch + 8u, r_u32(object + 28u) + (uint32)(product_z >> 12));
        w_u32(scratch + 4u, r_u32(object + 24u) - 75u);
        draft_call_adapter(0x80061308u, scratch, 1u, 1u,
            (uint32)(sint32)(sint16)r_u16(object + 18u), material);
        old_angle = angle;
        angle -= (uint32)increment;
        if ((sint32)old_angle <= 0) break;
    }
    w_u16(object + 10u, r_u16(object + 10u) + 50u * step);
    w_u16(object + 16u, r_u16(object + 16u) + 2u * step);
    result = 5u * step;
    w_u16(object + 18u, r_u16(object + 18u) - result);
    return draft_scratch_result(mark, result);
}

void sub_80061308(uint32 position, uint32 count, uint32 parameter, uint32 size, uint32 material)
{
    FUNCTION_MARKER(0x80061308u, "1.EXE");
    while ((sint32)count > 0)
    {
        uint32 child = sub_800227C4(40u);
        w_u8(child + 34u, 8u);
        w_u16(child + 38u, 0u);
        w_u16(child + 36u, size);
        w_u32(child + 20u, r_u32(position));
        w_u32(child + 24u, r_u32(position + 4u));
        w_u16(child + 32u, material);
        w_u32(child, 0x800613D0u);
        w_u16(child + 8u, parameter);
        w_u8(child + 14u, r_u8(child + 14u) | 2u);
        w_u32(child + 28u, r_u32(position + 8u));
        --count;
    }
}

uint32 sub_80061738(uint32 object)
{
    uint32 step = r_u32(0x800A9010u), result;
    FUNCTION_MARKER(0x80061738u, "1.EXE");
    if ((sint8)r_u8(object + 13u) <= 0)
    {
        w_u32(object, 0x800617A8u);
        return 0x800617A8u;
    }
    w_u8(object + 13u, r_u8(object + 13u) - step);
    w_u32(object + 24u, r_u32(object + 24u) - 12u * step);
    result = r_u16(object + 38u) + step * (uint32)(sint32)(sint16)r_u16(object + 18u);
    w_u16(object + 38u, result);
    return result;
}

uint32 sub_800613D0(uint32 object)
{
    sint32 life = (sint16)r_u16(object + 8u);
    uint32 result;
    FUNCTION_MARKER(0x800613D0u, "1.EXE");
    if (life <= 0)
        return sub_8002289C(object);
    result = (uint32)life - r_u32(0x800A9010u);
    w_u16(object + 8u, result);
    return result;
}

uint32 sub_800617A8(uint32 object)
{
    uint32 step, result;
    FUNCTION_MARKER(0x800617A8u, "1.EXE");
    if ((sint16)r_u16(object + 36u) < 30)
        return sub_8002289C(object);
    step = r_u32(0x800A9010u);
    result = r_u16(object + 38u) + step * (uint32)(sint32)(sint16)r_u16(object + 18u);
    w_u32(object + 24u, r_u32(object + 24u) - 12u * step);
    w_u16(object + 36u, r_u16(object + 36u) - 10u * step);
    w_u16(object + 38u, result);
    return result;
}
