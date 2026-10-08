#include "psx.h"

#include <stdlib.h>
#include "game_scene.h"



void native_input_publish_basic_pad(void);
uint32 sub_80069A70(uint32 destination, uint32 limit);
uint32 sub_80069A98(void);
uint32 sub_80069AD4(uint32 size, GameSceneCallContext *context);
uint32 sub_80069BC0(uint32 index);
uint32 sub_80069B84(uint32 index, GameSceneCallContext *context);
void sub_800861E4(uint32 mode);
void sub_80086214(void);
void sub_80085BFC(uint32 mode, GameMainCallContext *context);
void sub_80085C54(GameMainCallContext *context);
uint32 sub_8007B8B8(uint32 time_address);
uint32 sub_8007B730(uint32 destination, uint32 words, GameSceneCallContext *context);
uint32 sub_80059E2C(GameSceneCallContext *context);
uint32 sub_8005A4D8(uint32 filename, GameSceneCallContext *context);
uint32 sub_8004206C(uint32 destination, uint32 first, uint32 second, uint32 third, uint32 entry_sp);
uint32 sub_8003C87C(GameGeometryCallContext *context);
uint32 sub_80041E24(uint32 filename, uint32 mode, GameGeometryCallContext *context);
uint32 sub_8007F438(uint32 mode);
uint32 sub_80085CC4(void);
uint32 sub_8007D3F0(uint32 destination, uint32 filename);
uint32 sub_8007B368(uint32 command, uint32 argument, uint32 result);
uint32 sub_8007A7AC(uint32 mode);
uint32 sub_80059E4C(uint32 filename, GameGeometryCallContext *context);
uint32 sub_8007CE2C(uint32 destination, uint32 words);
uint32 sub_8007D110(void);
uint32 sub_800420C4(uint32 file, uint32 callback, GameGeometryCallContext *context);
uint32 sub_80042290(uint32 stream, GameGeometryCallContext *context);
uint32 sub_80086530(uint32 buffer, uint32 mode);
uint32 sub_800865AC(uint32 buffer, uint32 length);
uint32 sub_80042424(uint32 stream, uint32 mode);
sint32 sub_8003893C(GameMainCallContext *context);
uint32 sub_80086668(uint32 mode);
void sub_8007D230(GameMainCallContext *context);
uint32 sub_8007B5CC(uint32 command, uint32 argument, uint32 result);
void sub_800796DC(GameMainCallContext *context);
void sub_80079C20(GameMainCallContext *context);

uint32 sub_80069A70(uint32 destination, uint32 limit)
{
    FUNCTION_MARKER(0x80069A70u, "1.EXE");
    while (destination < limit)
    {
        w_u32(destination, 0u);
        destination += 4u;
    }
    return 0u;
}

uint32 sub_80069A98(void)
{
    uint32 value;
    uint32 remainder;
    FUNCTION_MARKER(0x80069A98u, "1.EXE");
    value = r_u32(0x800A63E0u);
    if (value != 0u)
        return value;
    value = r_u32(0x8009242Cu);
    remainder = value & 3u;
    w_u32(0x800A63E0u, value);
    value += 4u;
    if (remainder != 0u)
    {
        value -= remainder;
        w_u32(0x800A63E0u, value);
    }
    return value;
}

uint32 sub_80069AD4(uint32 size, GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 base;
    uint32 limit;
    uint32 remainder;
    uint32 result = 0u;
    FUNCTION_MARKER(0x80069AD4u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->return_address);
    sub_80069A98();
    base = r_u32(0x800A63E0u);
    limit = size + base;
    if (limit <= 0x80200000u)
    {
        remainder = limit & 3u;
        if (remainder != 0u)
            limit = limit + 4u - remainder;
        w_u32(0x800A63E0u, limit);
        sub_80069A70(base, limit);
        result = base;
    }
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80069BC0(uint32 index)
{
    uint32 value;
    FUNCTION_MARKER(0x80069BC0u, "1.EXE");
    value = r_u32(0x800A7498u + (index << 2u));
    w_u32(0x800A63E0u, value);
    return value;
}

uint32 sub_80069B84(uint32 index, GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 value;
    FUNCTION_MARKER(0x80069B84u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->return_address);
    sub_80069A98();
    value = r_u32(0x800A63E0u);
    w_u32(0x800A7498u + (index << 2u), value);
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return value;
}

void sub_800861E4(uint32 mode)
{
    FUNCTION_MARKER(0x800861E4u, "1.EXE");
    (void)mode;
    abort();
}

void sub_80086214(void)
{
    FUNCTION_MARKER(0x80086214u, "1.EXE");
    abort();
}

void sub_80085BFC(uint32 mode, GameMainCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    GameMainCallContext child = *context;
    FUNCTION_MARKER(0x80085BFCu, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->return_address);
    child.stack_pointer = frame;
    child.caller_s0 = mode;
    sub_8007F438(0u);
    child.return_address = 0x80085C1Cu;
    sub_800796DC(&child);
    if (sub_80085CC4() == 0u)
        child.caller_s0 = 0u;
    sub_800861E4(child.caller_s0);
    child.return_address = 0x80085C40u;
    sub_80079C20(&child);
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
}

void sub_80085C54(GameMainCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    GameMainCallContext child = *context;
    FUNCTION_MARKER(0x80085C54u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x80085C64u;
    sub_800796DC(&child);
    sub_80086214();
    sub_8007F438(0u);
    child.return_address = 0x80085C7Cu;
    sub_80079C20(&child);
    context->return_address = r_u32(frame + 0x10u);
}

uint32 sub_8007B8B8(uint32 time_address)
{
    uint32 minute;
    uint32 second;
    uint32 frame;
    FUNCTION_MARKER(0x8007B8B8u, "1.EXE");
    minute = r_u8(time_address);
    second = r_u8(time_address + 1u);
    minute = 10u * (minute >> 4u) + (minute & 15u);
    second = 10u * (second >> 4u) + (second & 15u);
    frame = r_u8(time_address + 2u);
    frame = 10u * (frame >> 4u) + (frame & 15u);
    return 75u * (60u * minute + second) + frame - 150u;
}

uint32 sub_8007B730(uint32 destination, uint32 words, GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    FUNCTION_MARKER(0x8007B730u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    result = sub_8007CE2C(destination, words);
    context->return_address = r_u32(frame + 0x10u);
    return result == 0u;
}

uint32 sub_80059E2C(GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    FUNCTION_MARKER(0x80059E2Cu, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    result = sub_8007D110();
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8005A4D8(uint32 filename, GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x30u;
    uint32 result;
    FUNCTION_MARKER(0x8005A4D8u, "1.EXE");
    w_u32(frame + 0x28u, context->caller_s0);
    w_u32(frame + 0x2Cu, context->return_address);
    for (;;)
    {
        if (sub_8007D3F0(frame + 0x10u, filename) != 0u)
        {
            sub_8007B368(2u, frame + 0x10u, 0u);
            VSync(3);
            if ((sub_8007A7AC(1u) & 2u) != 0u)
                break;
        }
        { GameGeometryCallContext error_context = {0}; error_context.stack_pointer = frame; error_context.caller_s0 = filename; sub_80059E4C(filename, &error_context); }
    }
    result = r_u32(frame + 0x14u);
    context->return_address = r_u32(frame + 0x2Cu);
    context->caller_s0 = r_u32(frame + 0x28u);
    return result;
}

uint32 sub_8004206C(uint32 destination, uint32 first, uint32 second, uint32 third, uint32 entry_sp)
{
    uint32 stack_argument;
    uint32 first_buffer;
    uint32 second_buffer;
    uint32 first_auxiliary;
    uint32 second_auxiliary;
    FUNCTION_MARKER(0x8004206Cu, "1.EXE");
    w_u32(destination + 8u, 0u);
    w_u32(destination + 0x14u, 0u);
    w_u16(destination + 0x18u, first);
    w_u16(destination + 0x1Au, second);
    w_u16(destination + 0x20u, third);
    w_u32(destination + 0x28u, 0u);
    w_u16(destination + 0x2Cu, first);
    w_u16(destination + 0x2Eu, second);
    stack_argument = r_u32(entry_sp + 0x10u);
    first_buffer = r_u32(0x800A6EACu);
    second_buffer = r_u32(0x800A6EB0u);
    first_auxiliary = r_u32(0x800A6EB4u);
    second_auxiliary = r_u32(0x800A6EB8u);
    w_u16(destination + 0x30u, 24u);
    w_u32(destination + 0x34u, 0u);
    w_u32(destination, first_buffer);
    w_u32(destination + 4u, second_buffer);
    w_u32(destination + 0xCu, first_auxiliary);
    w_u32(destination + 0x10u, second_auxiliary);
    w_u16(destination + 0x22u, stack_argument);
    return 24u;
}

uint32 sub_8003C87C(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x40u;
    uint32 first, second, third;
    uint32 result = 0u;
    uint32 offset;
    GameSceneCallContext search;
    GameGeometryCallContext playback = *context;
    FUNCTION_MARKER(0x8003C87Cu, "1.EXE");
    w_u32(frame + 0x38u, context->return_address);
    w_u32(frame + 0x34u, context->caller_s1);
    w_u32(frame + 0x30u, context->caller_s0);
    for (offset = 0u; offset < 24u; offset += 12u)
    {
        first = r_u32(0x800A5E50u + offset);
        second = r_u32(0x800A5E54u + offset);
        third = r_u32(0x800A5E58u + offset);
        w_u32(frame + 0x10u + offset, first);
        w_u32(frame + 0x14u + offset, second);
        w_u32(frame + 0x18u + offset, third);
    }
    w_u8(frame + 0x28u, r_u8(0x800A5E68u));
    w_u8(frame + 0x19u, r_u8(0x800A8698u) + 48u);
    search.stack_pointer = frame;
    search.return_address = 0x8003C91Cu;
    search.caller_s0 = frame + 0x10u;
    if ((sint32)sub_8005A4D8(frame + 0x10u, &search) > 0)
    {
        playback.stack_pointer = frame;
        playback.return_address = 0x8003C92Cu;
        playback.caller_s0 = search.caller_s0;
        playback.caller_s1 = 0u;
        result = sub_80041E24(frame + 0x10u, 1005u, &playback);
        context->caller_s2 = playback.caller_s2;
    }
    w_u32(0x800A6E18u, 8u);
    w_u32(0x800A6E44u, 8u);
    context->return_address = r_u32(frame + 0x38u);
    context->caller_s1 = r_u32(frame + 0x34u);
    context->caller_s0 = r_u32(frame + 0x30u);
    return result;
}

uint32 sub_80041E24(uint32 filename, uint32 mode, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x58u;
    uint32 result = 0u;
    uint32 buffer;
    sint32 product;
    sint32 scaled_width;
    uint32 buttons;
    GameSceneCallContext allocation;
    GameGeometryCallContext decoder = *context;
    GameMainCallContext input = {0};
    uint32 live_s0 = mode;
    uint32 live_s2 = context->caller_s2;
    FUNCTION_MARKER(0x80041E24u, "1.EXE");
    w_u32(frame + 0x4Cu, context->caller_s1);
    w_u32(frame + 0x48u, context->caller_s0);
    w_u32(frame + 0x54u, context->return_address);
    w_u32(frame + 0x50u, context->caller_s2);
    SetDispMask(0);
    w_u32(0x800A6EC0u, mode);
    while (sub_8007D3F0(frame + 0x30u, filename) == 0u) { }
    allocation.stack_pointer = frame;
    allocation.caller_s0 = mode;
    allocation.return_address = 0x80041E6Cu;
    buffer = sub_80069AD4(0x10000u, &allocation);
    w_u32(0x800A6EA8u, buffer);
    allocation.return_address = 0x80041E7Cu;
    buffer = sub_80069AD4(0x28000u, &allocation);
    w_u32(0x800A6EACu, buffer);
    allocation.return_address = 0x80041E8Cu;
    buffer = sub_80069AD4(0x28000u, &allocation);
    w_u32(0x800A6EB0u, buffer);
    allocation.return_address = 0x80041E98u;
    buffer = sub_80069AD4(0x2D00u, &allocation);
    w_u32(0x800A6EB4u, buffer);
    allocation.return_address = 0x80041EA4u;
    buffer = sub_80069AD4(0x2D00u, &allocation);
    w_u32(0x800A6EB8u, buffer);
    w_u32(frame + 0x10u, 0x108u);
    sub_8004206C(0x800A6E70u, 0u, 24u, 0u, frame);
    decoder.stack_pointer = frame;
    decoder.return_address = 0x80041ED8u;
    decoder.caller_s0 = live_s0;
    decoder.caller_s1 = 0u;
    decoder.caller_s2 = live_s2;
    buffer = sub_800420C4(frame + 0x30u, 0x80042130u, &decoder);
    live_s0 = 0xFFFFFFFFu;
    if (buffer != 0xFFFFFFFFu)
    {
        decoder.return_address = 0x80041EF4u;
        decoder.caller_s0 = live_s0;
        buffer = sub_80042290(0x800A6E70u, &decoder);
    }
    if (buffer != 0xFFFFFFFFu)
    {
        w_u32(0x800A6EBCu, 0u);
        live_s0 = 0x800A6E70u;
        live_s2 = 1u;
        for (;;)
        {
            buffer = r_u32(0x800A6E70u + (r_u32(0x800A6E78u) << 2u));
            sub_80086530(buffer, 3u);
            product = (sint32)(sint16)r_u16(0x800A6EA0u);
            product *= (sint32)(sint16)r_u16(0x800A6EA2u);
            buffer = r_u32(0x800A6E7Cu + (r_u32(0x800A6E84u) << 2u));
            sub_800865AC(buffer, (uint32)(product / 2));
            decoder.return_address = 0x80041F6Cu;
            decoder.caller_s0 = live_s0;
            decoder.caller_s1 = result;
            decoder.caller_s2 = live_s2;
            if (sub_80042290(0x800A6E70u, &decoder) == 0xFFFFFFFFu)
                break;
            sub_80042424(0x800A6E70u, frame);
            VSync(0);
            w_u32(frame + 0x10u, 240u);
            SetDefDispEnv((DISPENV *)psx_addr(frame + 0x18u, sizeof(DISPENV)),
                0, r_u32(0x800A6E98u) == 0u ? 240 : 0, 480, (sint32)r_u32(frame + 0x10u));
            scaled_width = (sint32)(sint16)r_u16(frame + 0x1Cu) * 2;
            w_u8(frame + 0x29u, 1u);
            w_u16(frame + 0x1Cu, (uint32)(scaled_width / 3));
            PutDispEnv((DISPENV *)psx_addr(frame + 0x18u, sizeof(DISPENV)));
            SetDispMask(1);
            if (r_u32(0x800A6EBCu) == 1u)
                break;
            input.stack_pointer = frame;
            input.return_address = 0x80042004u;
            input.caller_s0 = live_s0;
            input.caller_s1 = result;
            input.caller_s2 = live_s2;
            buttons = (uint32)sub_8003893C(&input);
            if ((buttons & 0x840u) != 0u)
            {
                result = 1u;
                break;
            }
        }
    }
    SetDispMask(0);
    sub_80086668(0u);
    input.stack_pointer = frame;
    input.return_address = 0x8004203Cu;
    input.caller_s0 = live_s0;
    input.caller_s1 = result;
    input.caller_s2 = live_s2;
    sub_8007D230(&input);
    sub_8007B5CC(9u, 0u, 0u);
    context->return_address = r_u32(frame + 0x54u);
    context->caller_s2 = r_u32(frame + 0x50u);
    context->caller_s1 = r_u32(frame + 0x4Cu);
    context->caller_s0 = r_u32(frame + 0x48u);
    return result;
}

#include "game_scene.h"



uint32 sub_80069B38(uint32 size, GameSceneCallContext *context);
uint32 sub_8005A484(uint32 length, uint32 destination, uint32 mode, GameSceneCallContext *context);
uint32 sub_8005A040(GameGeometryCallContext *context);
uint32 sub_8005A3E4(uint32 filename, uint32 destination, GameGeometryCallContext *context);
uint32 sub_8003BEA8(uint32 filename, GameGeometryCallContext *context);
void sub_8007E9B0(uint32 first, uint32 second, uint32 third);
sint32 sub_8003893C(GameMainCallContext *context);
void sub_8007D230(GameMainCallContext *context);
uint32 sub_80042424(uint32 stream, uint32 entry_sp);
uint32 sub_800424BC(uint32 file, GameGeometryCallContext *context);
uint32 sub_800420C4(uint32 file, uint32 callback, GameGeometryCallContext *context);
uint32 sub_80042318(uint32 stream, GameGeometryCallContext *context);
uint32 sub_80042290(uint32 stream, GameGeometryCallContext *context);
uint32 sub_80042130(GameSceneCallContext *context);
uint32 sub_8003BEFC(GameGeometryCallContext *context);
sint32 sub_800380C8(GameMainCallContext *context);
void native_input_publish_basic_pad(void);
uint32 sub_80069A70(uint32 destination, uint32 limit);
uint32 sub_80069A98(void);
uint32 sub_8005A4D8(uint32 filename, GameSceneCallContext *context);
uint32 sub_8007D3F0(uint32 destination, uint32 filename);
uint32 sub_8007B368(uint32 command, uint32 argument, uint32 result);
uint32 sub_8007A7AC(uint32 mode);
uint32 sub_80059E4C(uint32 filename, GameGeometryCallContext *context);
uint32 sub_800865AC(uint32 buffer, uint32 length);
uint32 sub_80086668(uint32 mode);
uint32 sub_8007B5CC(uint32 command, uint32 argument, uint32 result);
void sub_800796DC(GameMainCallContext *context);
void sub_80079C20(GameMainCallContext *context);
uint32 sub_8007A438(uint32 sectors, uint32 destination, uint32 mode);
uint32 sub_8007A53C(uint32 mode, uint32 result);
uint32 sub_8003BE08(uint32 image, GameGeometryCallContext *context);
uint32 sub_8007ECF4(uint32 mode);
uint32 sub_8007ECE0(uint32 mode);
uint32 sub_8007B770(uint32 mode);
uint32 sub_8007B350(uint32 mode);
uint32 sub_8007D2B4(uint32 mode);
uint32 sub_800863C4(uint32 mode);
uint32 sub_8007E9D0(uint32 buffer, uint32 size);
uint32 sub_8007D368(uint32 first, uint32 second, uint32 third, uint32 fourth, uint32 entry_sp);
uint32 sub_8007EA60(uint32 data, uint32 header);
uint32 sub_80086B58(uint32 data, uint32 buffer);
uint32 sub_8007EC14(uint32 data);
uint32 sub_8007DE14(void);
uint32 sub_80080230(uint32 rectangle, uint32 buffer);

uint32 sub_80069B38(uint32 size, GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 base;
    uint32 limit;
    uint32 result = 0u;
    FUNCTION_MARKER(0x80069B38u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->return_address);
    sub_80069A98();
    base = r_u32(0x800A63E0u);
    limit = size + base;
    if (limit <= 0x80200000u)
    {
        sub_80069A70(base, limit);
        result = r_u32(0x800A63E0u);
    }
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8005A484(uint32 length, uint32 destination, uint32 mode, GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 rounded = length + 0x7FFu;
    uint32 result;
    FUNCTION_MARKER(0x8005A484u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    if ((sint32)rounded < 0)
        rounded = length + 0xFFEu;
    sub_8007A438((uint32)((sint32)rounded >> 11), destination, mode);
    for (;;)
    {
        result = sub_8007A53C(1u, 0u);
        if ((sint32)result <= 0)
            break;
        VSync(0);
    }
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8005A040(GameGeometryCallContext *context)
{
    uint32 value = r_u32(0x800A9D58u);
    uint32 frame = context->stack_pointer - 0x18u;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005A040u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    if (value == 0u)
    {
        w_u32(0x800A9D58u, 2u);
        child.stack_pointer = frame;
        child.return_address = 0x8005A070u;
        sub_8003BEA8(0x800A62A0u, &child);
        context->caller_s0 = child.caller_s0;
        context->caller_s1 = child.caller_s1;
        context->caller_s2 = child.caller_s2;
        value = 1u;
        w_u32(0x800A9D58u, value);
    }
    context->return_address = r_u32(frame + 0x10u);
    return value;
}

uint32 sub_8005A3E4(uint32 filename, uint32 destination, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x38u;
    GameGeometryCallContext font = *context;
    GameSceneCallContext read_context;
    FUNCTION_MARKER(0x8005A3E4u, "1.EXE");
    w_u32(frame + 0x28u, context->caller_s0);
    w_u32(frame + 0x2Cu, context->caller_s1);
    w_u32(frame + 0x30u, context->caller_s2);
    w_u32(frame + 0x34u, context->return_address);
    font.stack_pointer = frame;
    font.return_address = 0x8005A408u;
    font.caller_s0 = filename;
    font.caller_s1 = destination;
    font.caller_s2 = 128u;
    sub_8005A040(&font);
    for (;;)
    {
        if (sub_8007D3F0(frame + 0x10u, font.caller_s0) != 0u)
        {
            sub_8007B368(2u, frame + 0x10u, 0u);
            VSync(3);
            if ((sub_8007A7AC(1u) & 2u) != 0u)
            {
                read_context.stack_pointer = frame;
                read_context.return_address = 0x8005A450u;
                read_context.caller_s0 = font.caller_s0;
                if (sub_8005A484(r_u32(frame + 0x14u), font.caller_s1,
                    font.caller_s2, &read_context) == 0u)
                    break;
            }
        }
        { GameGeometryCallContext error_context = {0}; error_context.stack_pointer = frame; error_context.caller_s0 = font.caller_s0; sub_80059E4C(font.caller_s0, &error_context); }
    }
    context->return_address = r_u32(frame + 0x34u);
    context->caller_s2 = r_u32(frame + 0x30u);
    context->caller_s1 = r_u32(frame + 0x2Cu);
    context->caller_s0 = r_u32(frame + 0x28u);
    return 0u;
}

uint32 sub_8003BEA8(uint32 filename, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 size;
    uint32 destination;
    uint32 result;
    GameSceneCallContext child;
    GameGeometryCallContext load = *context;
    FUNCTION_MARKER(0x8003BEA8u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x8003BEBCu;
    child.caller_s0 = filename;
    size = sub_8005A4D8(filename, &child);
    child.return_address = 0x8003BEC4u;
    destination = sub_80069B38(size, &child);
    w_u32(0x800A62F4u, destination);
    load.stack_pointer = frame;
    load.return_address = 0x8003BED8u;
    load.caller_s0 = child.caller_s0;
    sub_8005A3E4(child.caller_s0, destination, &load);
    context->caller_s1 = load.caller_s1;
    context->caller_s2 = load.caller_s2;
    load.return_address = 0x8003BEE8u;
    result = sub_8003BE08(r_u32(0x800A62F4u), &load);
    context->caller_s1 = load.caller_s1;
    context->caller_s2 = load.caller_s2;
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

void sub_8007E9B0(uint32 first, uint32 second, uint32 third)
{
    FUNCTION_MARKER(0x8007E9B0u, "1.EXE");
    w_u32(0x800C15D8u, first);
    w_u32(0x800B68B0u, second);
    w_u32(0x800C15D4u, third);
}

sint32 sub_8003893C(GameMainCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    GameMainCallContext child = *context;
    FUNCTION_MARKER(0x8003893Cu, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x8003894Cu;
    result = sub_800380C8(&child);
    context->caller_s0 = child.caller_s0;
    context->return_address = r_u32(frame + 0x10u);
    return (sint32)(sint16)(uint16)result;
}

void sub_8007D230(GameMainCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    GameMainCallContext child = *context;
    FUNCTION_MARKER(0x8007D230u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x8007D240u;
    sub_800796DC(&child);
    if (r_u32(0x800925E4u) == 1u)
    {
        sub_8007ECF4(0u);
        sub_8007ECE0(0u);
    }
    else
    {
        sub_8007B770(0u);
        sub_8007B350(0u);
    }
    w_u8(r_u32(0x800928D0u), 0u);
    w_u8(r_u32(0x800928DCu), 0u);
    child.return_address = 0x8007D2A4u;
    sub_80079C20(&child);
    context->return_address = r_u32(frame + 0x10u);
}

uint32 sub_80042424(uint32 stream, uint32 entry_sp)
{
    uint32 frame = entry_sp - 8u;
    uint32 ready;
    uint32 result = 2048u;
    uint32 counter;
    uint32 current;
    uint32 first;
    uint32 second_address;
    FUNCTION_MARKER(0x80042424u, "1.EXE");
    ready = r_u32(stream + 0x34u);
    w_u32(frame, 2048u);
    if (ready == 0u)
    {
        do
        {
            counter = r_u32(frame) - 1u;
            w_u32(frame, counter);
            if (r_u32(frame) == 0u)
            {
                current = r_u32(stream + 0x28u);
                w_u32(stream + 0x34u, 1u);
                current = current == 0u;
                w_u32(stream + 0x28u, current);
                first = r_u16(stream + (current << 3u) + 0x18u);
                second_address = stream + (r_u32(stream + 0x28u) << 3u);
                w_u16(stream + 0x2Cu, first);
                w_u16(stream + 0x2Eu, r_u16(second_address + 0x1Au));
            }
            result = r_u32(stream + 0x34u);
        } while (result == 0u);
    }
    w_u32(stream + 0x34u, 0u);
    return result;
}

uint32 sub_800424BC(uint32 file, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 result = 0xFFFFFFFFu;
    uint32 attempt;
    FUNCTION_MARKER(0x800424BCu, "1.EXE");
    w_u32(frame + 0x1Cu, context->caller_s1);
    w_u32(frame + 0x18u, context->caller_s0);
    w_u32(frame + 0x20u, context->caller_s2);
    w_u32(frame + 0x24u, context->return_address);
    for (attempt = 1u; attempt < 10u; ++attempt)
    {
        if (sub_8007B368(2u, file, 0u) != 0u)
        {
            w_u8(frame + 0x10u, 128u);
            if (sub_8007B5CC(14u, frame + 0x10u, 0u) != 0u)
            {
                VSync(3);
                result = sub_8007D2B4(448u);
                if (result != 0u)
                    break;
            }
        }
        result = 0xFFFFFFFFu;
    }
    context->return_address = r_u32(frame + 0x24u);
    context->caller_s2 = r_u32(frame + 0x20u);
    context->caller_s1 = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
    return result;
}

uint32 sub_800420C4(uint32 file, uint32 callback, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x800420C4u, "1.EXE");
    w_u32(frame + 0x1Cu, context->caller_s1);
    w_u32(frame + 0x18u, context->caller_s0);
    w_u32(frame + 0x20u, context->return_address);
    sub_800863C4(0u);
    sub_80086668(callback);
    sub_8007E9D0(r_u32(0x800A6EA8u), 32u);
    w_u32(frame + 0x10u, 0u);
    sub_8007D368(1u, 1u, 0xFFFFFFFFu, 0u, frame);
    child.stack_pointer = frame;
    child.return_address = 0x80042118u;
    child.caller_s0 = callback;
    child.caller_s1 = file;
    result = sub_800424BC(file, &child);
    context->caller_s2 = child.caller_s2;
    context->return_address = r_u32(frame + 0x20u);
    context->caller_s1 = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
    return result;
}

uint32 sub_80042318(uint32 stream, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x30u;
    uint32 attempts = 2048u;
    uint32 header;
    uint32 width;
    uint32 height;
    uint32 scaled;
    uint32 result = 0u;
    FUNCTION_MARKER(0x80042318u, "1.EXE");
    w_u32(frame + 0x24u, context->caller_s1);
    w_u32(frame + 0x20u, context->caller_s0);
    w_u32(frame + 0x28u, context->return_address);
    for (;;)
    {
        uint32 status = sub_8007EA60(frame + 0x10u, frame + 0x14u);
        --attempts;
        if (status == 0u)
            break;
        if (attempts == 0u)
            goto done;
    }
    header = r_u32(frame + 0x14u);
    if (r_u32(header + 8u) >= r_u32(0x800A6EC0u))
        w_u32(0x800A6EBCu, 1u);
    if (r_u16(header + 0x10u) != r_u32(0x800A5F54u) ||
        r_u16(header + 0x12u) != r_u32(0x800A5F58u))
    {
        w_u16(frame + 0x18u, 0u);
        w_u16(frame + 0x1Au, 0u);
        w_u16(frame + 0x1Cu, 480u);
        w_u16(frame + 0x1Eu, 480u);
        ClearImage((PSX_RECT *)psx_addr(frame + 0x18u, sizeof(PSX_RECT)), 0, 0, 0);
        header = r_u32(frame + 0x14u);
        width = r_u16(header + 0x10u);
        height = r_u16(header + 0x12u);
        w_u32(0x800A5F54u, width);
        w_u32(0x800A5F58u, height);
    }
    width = r_u32(0x800A5F54u);
    result = r_u32(frame + 0x10u);
    scaled = width * 3u;
    scaled = (scaled + (scaled >> 31u)) >> 1u;
    height = r_u16(0x800A5F58u);
    w_u16(stream + 0x24u, scaled);
    w_u16(stream + 0x1Cu, scaled);
    w_u16(stream + 0x26u, height);
    w_u16(stream + 0x1Eu, height);
    w_u16(stream + 0x32u, height);
done:
    context->return_address = r_u32(frame + 0x28u);
    context->caller_s1 = r_u32(frame + 0x24u);
    context->caller_s0 = r_u32(frame + 0x20u);
    return result;
}

uint32 sub_80042290(uint32 stream, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 attempts = 2048u;
    uint32 data;
    uint32 result = 0xFFFFFFFFu;
    uint32 index;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80042290u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x18u, context->caller_s2);
    w_u32(frame + 0x1Cu, context->return_address);
    w_u32(frame + 0x14u, context->caller_s1);
    child.stack_pointer = frame;
    child.caller_s0 = stream;
    do
    {
        child.return_address = 0x800422B4u;
        child.caller_s2 = attempts;
        data = sub_80042318(stream, &child);
        --attempts;
        if (data != 0u)
        {
            index = r_u32(stream + 8u) == 0u;
            w_u32(stream + 8u, index);
            sub_80086B58(data, r_u32(stream + (index << 2u)));
            sub_8007EC14(data);
            result = 0u;
            break;
        }
    } while (attempts != 0u);
    context->return_address = r_u32(frame + 0x1Cu);
    context->caller_s2 = r_u32(frame + 0x18u);
    context->caller_s1 = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80042130(GameSceneCallContext *context)
{
    uint32 pending = r_u32(0x800B5894u);
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 first;
    uint32 second;
    uint32 index;
    uint32 previous_index;
    uint32 width;
    uint32 page;
    uint32 position;
    uint32 result;
    sint32 boundary;
    FUNCTION_MARKER(0x80042130u, "1.EXE");
    w_u32(frame + 0x1Cu, context->return_address);
    w_u32(frame + 0x18u, context->caller_s0);
    if (pending != 0u)
    {
        sub_8007DE14();
        w_u32(0x800B5894u, 0u);
    }
    first = r_u32(0x800A6E9Cu);
    second = r_u32(0x800A6EA0u);
    w_u32(frame + 0x10u, first);
    w_u32(frame + 0x14u, second);
    index = r_u32(0x800A6E84u);
    previous_index = r_u32(0x800A6E84u);
    w_u32(0x800A6E84u, index == 0u);
    position = r_u16(0x800A6E9Cu);
    width = r_u16(0x800A6EA0u);
    page = r_u32(0x800A6E98u);
    position += width;
    w_u16(0x800A6E9Cu, position);
    boundary = (sint16)r_u16(0x800A6E88u + (page << 3u));
    boundary += (sint16)r_u16(0x800A6E8Cu + (page << 3u));
    if ((sint16)position < boundary)
    {
        sint32 height = (sint16)r_u16(0x800A6EA2u);
        sint32 product = (sint16)width * height;
        index = r_u32(0x800A6E84u);
        sub_800865AC(r_u32(0x800A6E7Cu + (index << 2u)), product / 2);
    }
    else
    {
        w_u32(0x800A6EA4u, 1u);
        page = page == 0u;
        w_u32(0x800A6E98u, page);
        position = r_u16(0x800A6E88u + (page << 3u));
        w_u16(0x800A6E9Cu, position);
        position = r_u16(0x800A6E8Au + (page << 3u));
        w_u16(0x800A6E9Eu, position);
    }
    result = sub_80080230(frame + 0x10u,
        r_u32(0x800A6E7Cu + (previous_index << 2u)));
    context->return_address = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
    return result;
}

uint32 sub_8003BEFC(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8003BEFCu, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x8003BF14u;
    sub_8003BEA8(0x800A5DA0u, &child);
    child.return_address = 0x8003BF24u;
    result = sub_8003BEA8(0x800A5DB4u, &child);
    context->caller_s0 = child.caller_s0;
    context->caller_s1 = child.caller_s1;
    context->caller_s2 = child.caller_s2;
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

sint32 sub_800380C8(GameMainCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 offset = 0u;
    uint32 type = 0u;
    uint32 raw;
    uint32 buttons = 0u;
    uint32 high = 0u;
    uint32 copy;
    uint32 a;
    uint32 b;
    uint32 c;
    uint32 d;
    uint32 callback_ra = 0x80038924u;
    sint32 center;
    sint32 tolerance;
    sint32 value;
    sint32 adjusted;
    sint32 result = 0;
    GameMainCallContext child = *context;
    FUNCTION_MARKER(0x800380C8u, "1.EXE");
    native_input_publish_basic_pad();
    w_u16(0x800A5C70u, 0xFFFFu);
    raw = r_u8(0x800A9984u);
    w_u32(frame + 0x14u, context->return_address);
    w_u32(frame + 0x10u, context->caller_s0);
    if (raw != 0u)
        goto copy_default;
    raw = r_u8(0x800A9985u);
    w_u8(0x800A6D48u, raw);
    offset = (raw == 0x80u) << 1u;
    type = r_u8(0x800A9985u + offset);
    if (type == 0x41u)
    {
        w_u8(0x800A6D30u, 0u);
        w_u8(0x800A6D34u, 0u);
        w_u8(0x800A6D38u, 0u);
        w_u16(0x800A5C70u, 0u);
        callback_ra = 0x80038214u;
        goto copy_digital;
    }
    if (type == 0x23u)
    {
        center = (sint32)r_u32(0x800A5C7Cu);
        tolerance = (sint32)r_u32(0x800A5C74u);
        value = r_u8(0x800A9988u + offset);
        if ((sint32)((uint32)center + (uint32)tolerance) >= value &&
            value >= (sint32)((uint32)center - (uint32)tolerance))
            w_u8(0x800A6D30u, r_u8(0x800A5C7Cu));
        else
        {
            adjusted = (sint32)((uint32)value + 128u - (uint32)center);
            if (adjusted < 0) adjusted = 0;
            if (adjusted >= 256) adjusted = 255;
            w_u8(0x800A6D30u, adjusted);
        }
        raw = r_u16(0x800A5C98u);
        if (raw == 64u) w_u8(0x800A6D34u, r_u8(0x800A9989u + offset));
        else if (raw == 128u) w_u8(0x800A6D34u, r_u8(0x800A998Au + offset));
        else if (raw == 4u) w_u8(0x800A6D34u, r_u8(0x800A998Bu + offset));
        raw = r_u16(0x800A5C9Au);
        if (raw == 64u) w_u8(0x800A6D38u, r_u8(0x800A9989u + offset));
        else if (raw == 128u) w_u8(0x800A6D38u, r_u8(0x800A998Au + offset));
        else if (raw == 4u) w_u8(0x800A6D38u, r_u8(0x800A998Bu + offset));
        value = r_u8(0x800A998Bu + offset);
        if ((sint32)r_u32(0x800A5C74u) < value)
            w_u8(0x800A9987u + offset, r_u8(0x800A9987u + offset) ^ 4u);
        value = r_u8(0x800A9989u + offset);
        if ((sint32)r_u32(0x800A5C74u) < value)
            w_u8(0x800A9987u + offset, r_u8(0x800A9987u + offset) ^ 64u);
        value = r_u8(0x800A998Au + offset);
        if ((sint32)r_u32(0x800A5C74u) < value)
            w_u8(0x800A9987u + offset, r_u8(0x800A9987u + offset) ^ 128u);
        w_u16(0x800A5C70u, 2u);
        goto copy_twist;
    }
    if (type != 0x53u && type != 0x73u)
        goto copy_default;
    tolerance = (sint32)r_u32(0x800A5C80u);
    value = r_u8(0x800A998Bu + offset);
    if ((sint32)((uint32)tolerance + 128u) >= value &&
        value >= (sint32)(128u - (uint32)tolerance))
        w_u8(0x800A6D3Cu, 128u);
    else
        w_u8(0x800A6D3Cu, value);
    center = (sint32)r_u32(0x800A5C88u);
    tolerance = (sint32)r_u32(0x800A5C80u);
    value = r_u8(0x800A998Au + offset);
    if ((sint32)((uint32)center + (uint32)tolerance) >= value &&
        value >= (sint32)((uint32)center - (uint32)tolerance))
        w_u8(0x800A6D40u, r_u8(0x800A5C88u));
    else
    {
        w_u8(0x800A6D44u, value);
        adjusted = (sint32)((uint32)value + 128u - (uint32)center);
        if (adjusted < 0) adjusted = 0;
        if (adjusted >= 256) adjusted = 255;
        w_u8(0x800A6D40u, adjusted);
    }
    w_u16(0x800A5C70u, 3u);
    high = r_u8(0x800A9986u + offset) << 8u;
    if (r_u8(0x800A9985u + offset) != 0x53u)
        goto copy_analog;
    raw = r_u8(0x800A9987u + offset);
    if (raw & 1u) buttons |= 1u;
    if (raw & 2u) buttons |= 4u;
    if (raw & 4u) buttons |= 128u;
    if (raw & 8u) buttons |= 16u;
    if (raw & 16u) buttons |= 8u;
    if (raw & 32u) buttons |= 32u;
    if (raw & 64u) buttons |= 64u;
    if (raw & 128u) buttons |= 2u;
    callback_ra = 0x80038774u;
    goto copy_all;
copy_digital:
copy_twist:
copy_analog:
copy_default:
copy_all:
    for (copy = 0u; copy != 32u; copy += 16u)
    {
        a = r_u32(0x800A9984u + copy);
        b = r_u32(0x800A9988u + copy);
        c = r_u32(0x800A998Cu + copy);
        d = r_u32(0x800A9990u + copy);
        w_u32(0x800A7BB0u + copy, a);
        w_u32(0x800A7BB4u + copy, b);
        w_u32(0x800A7BB8u + copy, c);
        w_u32(0x800A7BBCu + copy, d);
    }
    a = r_u8(0x800A99A4u);
    b = r_u8(0x800A99A5u);
    w_u8(0x800A7BD0u, a);
    w_u8(0x800A7BD1u, b);
    if (type == 0x23u)
    {
        w_u8(0x800A6D44u, r_u8(0x800A9988u + offset));
        result = (sint16)(((r_u8(0x800A9986u + offset) << 8u) +
            r_u8(0x800A9987u + offset)) ^ 0xFFFFu);
        goto done;
    }
    if (type == 0x73u)
    {
        result = (sint16)((high + r_u8(0x800A9987u + offset)) ^ 0xFFFFu);
        goto done;
    }
    if (type == 0x41u)
        result = (sint16)(((r_u8(0x800A9986u + offset) << 8u) +
            r_u8(0x800A9987u + offset)) ^ 0xFFFFu);
    else if (type == 0x53u)
        result = (sint16)((high + buttons) ^ 0xFFFFu);
    else
        goto call_default;
    child.caller_s0 = (uint32)(uint16)result;
    goto call_boundary;
call_default:
    result = 0;
call_boundary:
    child.stack_pointer = frame;
    child.return_address = callback_ra;
    sub_80079C20(&child);
done:
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}
