#include "psx.h"

#include <string.h>
#include "game_scene.h"

uint32 sub_80039224(void);
uint32 sub_8005A59C(uint32 filename, GameGeometryCallContext *context);
uint32 sub_8005A69C(uint32 count, GameGeometryCallContext *context);
uint32 sub_8005A7B8(uint32 index, GameGeometryCallContext *context);
uint32 sub_8005A884(GameGeometryCallContext *context);
uint32 sub_8003C4B8(GameGeometryCallContext *context);
uint32 sub_8005A0D8(uint32 filename, uint32 destination, uint32 size, GameGeometryCallContext *context);
uint32 sub_8005A130(uint32 filename, uint32 destination, GameGeometryCallContext *context);
uint32 sub_8005A1EC(uint32 length, uint32 destination, uint32 mode, uint32 filename, GameGeometryCallContext *context);
uint32 sub_80059990(uint32 progress, GameGeometryCallContext *context);
uint32 sub_8003D7F0(uint32 language, GameGeometryCallContext *context);
uint32 sub_8003C5E4(GameGeometryCallContext *context);
uint32 sub_80035780(GameGeometryCallContext *context);
uint32 sub_80089218(GameGeometryCallContext *context);
uint32 sub_800362B8(uint32 index, GameGeometryCallContext *context);
uint32 sub_80036348(GameGeometryCallContext *context);
uint32 sub_80069AD4(uint32 size, GameSceneCallContext *context);
uint32 sub_8007B8B8(uint32 time_address);
uint32 sub_8005A4D8(uint32 filename, GameSceneCallContext *context);
uint32 sub_80059E4C(uint32 filename, GameGeometryCallContext *context);
uint32 sub_80069B38(uint32 size, GameSceneCallContext *context);
uint32 sub_8005A040(GameGeometryCallContext *context);
void sub_8001F850(void);
uint32 sub_8001FF7C(uint32 mode, GameGeometryCallContext *context);
void sub_80059E20(void);
uint32 sub_800598CC(uint32 resource, GameGeometryCallContext *context);
uint32 sub_800439A4(uint32 color, uint32 number, uint32 subtract, uint32 x, GameGeometryCallContext *context);

uint32 sub_800358DC(GameGeometryCallContext *context);
void sub_80036E9C(uint32 value);
uint32 sub_80036EA8(uint32 value, GameGeometryCallContext *context);
uint32 sub_80059C2C(GameGeometryCallContext *context);
uint32 sub_80059CE4(uint32 value, GameGeometryCallContext *context);
uint32 sub_80089490(uint32 source, uint32 length, GameGeometryCallContext *context);

sint32 CdRead(sint32 count, uint32 *destination, sint32 mode);
sint32 CdReadSync(sint32 mode, uint8 *result);

uint32 sub_80039224(void)
{
    uint32 destination = 0x800A8504u;
    uint32 offset = 6u;
    uint32 row;
    uint32 value;
    FUNCTION_MARKER(0x80039224u, "1.EXE");
    for (row = 1u; row < 5u; ++row)
    {
        w_u32(destination, 0u);
        value = (uint32)r_u8(0x800A976Du + offset) << 24u;
        w_u32(destination, value);
        value |= (uint32)r_u8(0x800A978Bu + offset) << 16u;
        w_u32(destination, value);
        value |= (uint32)r_u8(0x800A97A9u + offset) << 8u;
        w_u32(destination, value);
        value |= r_u8(0x800A97C7u + offset);
        offset += 6u;
        w_u32(destination, value);
        destination += 4u;
    }
    return 0u;
}

uint32 sub_8005A59C(uint32 filename, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005A59Cu, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    child.caller_s0 = filename;
    w_u32(frame + 0x14u, context->return_address);
    child.stack_pointer = frame;
    for (;;)
    {
        result = CdSearchFileGuest(0x800A7438u, child.caller_s0);
        if (result != 0u)
            break;
        child.return_address = 0x8005A5CCu;
        sub_80059E4C(child.caller_s0, &child);
    }
    result = sub_8007B8B8(0x800A7438u);
    context->caller_s1 = child.caller_s1;
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8005A69C(uint32 count, GameGeometryCallContext *context)
{
    uint32 pending = r_u32(0x800A7408u);
    uint32 frame = context->stack_pointer - 0x38u;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005A69Cu, "1.EXE");
    w_u32(frame + 0x28u, context->caller_s4);
    child.caller_s4 = count;
    w_u32(frame + 0x24u, context->caller_s3);
    child.caller_s3 = 0u;
    w_u32(frame + 0x20u, context->caller_s2);
    child.caller_s2 = 0u;
    w_u32(frame + 0x30u, context->caller_s6);
    child.caller_s6 = count + 99u;
    w_u32(frame + 0x34u, context->return_address);
    w_u32(frame + 0x2Cu, context->caller_s5);
    w_u32(frame + 0x1Cu, context->caller_s1);
    w_u32(frame + 0x18u, context->caller_s0);
    child.stack_pointer = frame;
    if (pending == 0u)
        sub_80059E20();
    child.caller_s1 = 0u;
    child.caller_s5 = 0x80090DFCu;
    child.caller_s0 = 0x800BB8B8u;
    do
    {
        child.return_address = 0x8005A700u;
        sub_8005A7B8((uint32)(sint32)(sint16)child.caller_s3, &child);
        child.return_address = 0x8005A708u;
        sub_800598CC(child.caller_s5, &child);
        child.return_address = 0x8005A710u;
        sub_800598CC(child.caller_s5 + 20u, &child);
        w_u32(frame + 0x10u, 2u);
        w_u32(frame + 0x14u, 150u);
        child.return_address = 0x8005A738u;
        sub_800439A4(0x808080u, child.caller_s6, child.caller_s1, 0xFFFFFFC3u, &child);
        result = r_u32(0x800A9D60u) == 1u ? 2u : 0u;
        child.caller_s3 += 1u;
        child.return_address = 0x8005A758u;
        sub_8001FF7C(result, &child);
        child.caller_s1 += 1u;
        sub_8001F850();
        child.caller_s2 += 1u;
        result = sub_8007B8B8(0x800A7438u);
        w_u32(child.caller_s0, result);
        child.caller_s0 += 4u;
    } while (child.caller_s2 != child.caller_s4);
    child.return_address = 0x8005A784u;
    result = sub_8005A884(&child);
    w_u32(0x800A9058u, result);
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x34u);
    context->caller_s6 = r_u32(frame + 0x30u);
    context->caller_s5 = r_u32(frame + 0x2Cu);
    context->caller_s4 = r_u32(frame + 0x28u);
    context->caller_s3 = r_u32(frame + 0x24u);
    context->caller_s2 = r_u32(frame + 0x20u);
    context->caller_s1 = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
    return result;
}

uint32 sub_8005A7B8(uint32 index, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x30u;
    uint32 first;
    uint32 second;
    uint32 third;
    uint32 result;
    sint32 quotient = (sint16)index;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005A7B8u, "1.EXE");
    w_u32(frame + 0x28u, context->return_address);
    first = r_u32(0x800A62C4u);
    second = r_u32(0x800A62C8u);
    third = r_u32(0x800A62CCu);
    w_u32(frame + 0x10u, first);
    w_u32(frame + 0x14u, second);
    w_u32(frame + 0x18u, third);
    first = r_u32(0x800A62D0u);
    second = r_u8(0x800A62D4u);
    third = r_u8(0x800A62D5u);
    w_u32(frame + 0x1Cu, first);
    w_u8(frame + 0x20u, second);
    w_u8(frame + 0x21u, third);
    first = r_u8(0x800A8698u);
    w_u8(frame + 0x15u, first + 48u);
    if (quotient < 0)
        quotient += 15;
    quotient >>= 4;
    first = r_u8(0x800A62B4u + (uint32)quotient);
    w_u8(frame + 0x19u, first);
    w_u8(frame + 0x17u, first);
    first = r_u8(0x800A62B4u + (index & 15u));
    w_u8(frame + 0x1Au, first);
    child.stack_pointer = frame;
    child.return_address = 0x8005A874u;
    result = sub_8005A59C(frame + 0x10u, &child);
    context->caller_s0 = child.caller_s0;
    context->caller_s1 = child.caller_s1;
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x28u);
    return result;
}

uint32 sub_8005A884(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 first;
    uint32 second;
    uint32 third;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005A884u, "1.EXE");
    w_u32(frame + 0x20u, context->return_address);
    first = r_u32(0x800A62D8u);
    second = r_u32(0x800A62DCu);
    third = r_u32(0x800A62E0u);
    w_u32(frame + 0x10u, first);
    w_u32(frame + 0x14u, second);
    w_u32(frame + 0x18u, third);
    first = r_u32(0x800A62E4u);
    w_u32(frame + 0x1Cu, first);
    child.stack_pointer = frame;
    child.return_address = 0x8005A8E0u;
    result = sub_8005A59C(frame + 0x10u, &child);
    context->caller_s0 = child.caller_s0;
    context->caller_s1 = child.caller_s1;
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x20u);
    return result;
}

uint32 sub_8003C4B8(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x38u;
    uint32 first;
    uint32 second;
    uint32 third;
    uint32 destination;
    uint32 result;
    GameSceneCallContext scene;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8003C4B8u, "1.EXE");
    w_u32(frame + 0x30u, context->return_address);
    w_u32(frame + 0x2Cu, context->caller_s1);
    w_u32(frame + 0x28u, context->caller_s0);
    first = r_u32(0x800A5DF8u);
    second = r_u32(0x800A5DFCu);
    third = r_u32(0x800A5E00u);
    w_u32(frame + 0x10u, first);
    w_u32(frame + 0x14u, second);
    w_u32(frame + 0x18u, third);
    first = r_u32(0x800A5E04u);
    second = r_u32(0x800A5E08u);
    third = r_u8(0x800A5E0Cu);
    w_u32(frame + 0x1Cu, first);
    w_u32(frame + 0x20u, second);
    w_u8(frame + 0x24u, third);
    child.stack_pointer = frame;
    child.caller_s1 = frame + 0x10u;
    first = r_u8(0x800A8698u);
    w_u8(frame + 0x15u, first + 48u);
    scene.stack_pointer = frame;
    scene.return_address = 0x8003C540u;
    scene.caller_s0 = child.caller_s0;
    child.caller_s0 = sub_8005A4D8(child.caller_s1, &scene);
    scene.caller_s0 = child.caller_s0;
    scene.return_address = 0x8003C54Cu;
    destination = sub_80069AD4(child.caller_s0, &scene);
    child.caller_s0 = scene.caller_s0;
    w_u32(0x800A7C68u, destination);
    child.return_address = 0x8003C564u;
    sub_8005A0D8(child.caller_s1, destination, child.caller_s0, &child);
    result = child.caller_s0;
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x30u);
    context->caller_s1 = r_u32(frame + 0x2Cu);
    context->caller_s0 = r_u32(frame + 0x28u);
    return result;
}

uint32 sub_8005A0D8(uint32 filename, uint32 destination, uint32 size, GameGeometryCallContext *context)
{
    uint32 pending = r_u32(0x800A7408u);
    uint32 frame = context->stack_pointer - 0x20u;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005A0D8u, "1.EXE");
    (void)size;
    w_u32(frame + 0x10u, context->caller_s0);
    child.caller_s0 = filename;
    w_u32(frame + 0x14u, context->caller_s1);
    child.caller_s1 = destination;
    w_u32(frame + 0x18u, context->return_address);
    child.stack_pointer = frame;
    if (pending == 0u)
        sub_80059E20();
    child.return_address = 0x8005A108u;
    sub_8005A040(&child);
    child.return_address = 0x8005A114u;
    sub_8005A130(child.caller_s0, child.caller_s1, &child);
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x18u);
    context->caller_s1 = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return 1u;
}

uint32 sub_8005A130(uint32 filename, uint32 destination, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x38u;
    uint32 first;
    uint32 second;
    uint32 third;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005A130u, "1.EXE");
    w_u32(frame + 0x28u, context->caller_s0);
    child.caller_s0 = filename;
    w_u32(frame + 0x2Cu, context->caller_s1);
    child.caller_s1 = destination;
    w_u32(frame + 0x30u, context->caller_s2);
    child.caller_s2 = 128u;
    w_u32(frame + 0x34u, context->return_address);
    child.stack_pointer = frame;
    for (;;)
    {
        if (CdSearchFileGuest(frame + 0x10u, child.caller_s0) != 0u)
        {
            CdControl(2, (uint8 *)psx_addr(frame + 0x10u, 1u), NULL);
            VSync(3);
            if ((CdDiskReady(1u) & 2u) != 0u)
            {
                first = r_u32(frame + 0x14u);
                child.return_address = 0x8005A19Cu;
                if (sub_8005A1EC(first, child.caller_s1, child.caller_s2, child.caller_s0, &child) == 0u)
                    break;
            }
        }
        child.return_address = 0x8005A1ACu;
        sub_80059E4C(child.caller_s0, &child);
    }
    first = r_u32(0x800A7408u);
    second = r_u32(0x800A740Cu);
    third = r_u32(0x800A7404u);
    w_u32(0x800A7408u, first + second);
    w_u32(0x800A7404u, third + 1u);
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x34u);
    context->caller_s2 = r_u32(frame + 0x30u);
    context->caller_s1 = r_u32(frame + 0x2Cu);
    context->caller_s0 = r_u32(frame + 0x28u);
    return 0u;
}

uint32 sub_8005A1EC(uint32 length, uint32 destination, uint32 mode, uint32 filename, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 sectors = length + 2047u;
    uint32 result;
    uint32 value;
    uint32 divisor;
    uint32 progress;
    uint32 total;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005A1ECu, "1.EXE");
    (void)filename;
    w_u32(frame + 0x20u, context->return_address);
    w_u32(frame + 0x1Cu, context->caller_s3);
    w_u32(frame + 0x18u, context->caller_s2);
    w_u32(frame + 0x14u, context->caller_s1);
    w_u32(frame + 0x10u, context->caller_s0);
    if ((sint32)sectors < 0)
        sectors = length + 4094u;
    child.caller_s1 = 0xFFFFFFFFu;
    child.stack_pointer = frame;
    result = 0xFFFFFFFFu;
    if (CdRead((sint32)sectors >> 11, (uint32 *)psx_addr(destination, 1u), (sint32)mode) != 1u)
        goto restore;
    child.caller_s2 = CdReadSync(1, NULL);
    if (child.caller_s2 == 0xFFFFFFFFu)
        goto restore;
    child.caller_s0 = 1u;
    if ((sint32)child.caller_s2 >= 5)
    {
        divisor = r_u32(0x800A73FCu);
        if (divisor == 0u) xport_mips_break(7u);
        if (divisor == 0xFFFFFFFFu && child.caller_s2 == 0x80000000u) xport_mips_break(6u);
        child.caller_s0 = (uint32)((sint32)child.caller_s2 / (sint32)divisor) + 1u;
    }
    child.caller_s3 = 100u;
    for (;;)
    {
        child.caller_s1 = CdReadSync(1, NULL);
        value = child.caller_s2 - child.caller_s1;
        if ((sint32)child.caller_s1 <= 0)
            break;
        divisor = child.caller_s0;
        if (divisor == 0u) xport_mips_break(7u);
        if (divisor == 0xFFFFFFFFu && value == 0x80000000u) xport_mips_break(6u);
        progress = (uint32)((sint32)value / (sint32)divisor);
        value = r_u32(0x800A73FCu);
        ++progress;
        w_u32(0x800A740Cu, progress);
        if ((sint32)value < (sint32)progress)
            w_u32(0x800A740Cu, value);
        if (r_u32(0x800A740Cu) >= 100u)
        {
            value = r_u32(0x800A7408u);
            w_u32(0x800A740Cu, child.caller_s3 - value);
        }
        progress = r_u32(0x800A740Cu);
        total = r_u32(0x800A7408u);
        child.return_address = 0x8005A324u;
        sub_80059990(total + progress, &child);
    }
    if (child.caller_s1 == 0xFFFFFFFFu)
        goto restore;
    value = r_u32(0x800A7404u);
    total = r_u32(0x800A7400u);
    if ((sint32)value >= (sint32)total)
    {
        progress = r_u32(0x800A740Cu);
        total = r_u32(0x800A7408u);
        child.return_address = 0x8005A360u;
        sub_80059CE4(total + progress, &child);
        child.return_address = 0x8005A368u;
        sub_80059C2C(&child);
        total = r_u32(0x800A7408u);
        w_u32(0x800A740Cu, 100u - total);
    }
    else
    {
        value = r_u32(0x800A740Cu);
        child.caller_s0 = 0u;
        if (value >= 100u)
            w_u32(0x800A740Cu, 100u - r_u32(0x800A7408u));
        do
        {
            progress = r_u32(0x800A740Cu);
            total = r_u32(0x800A7408u);
            ++child.caller_s0;
            child.return_address = 0x8005A3B8u;
            sub_80059990(total + progress, &child);
        } while ((sint32)child.caller_s0 < 2);
    }
    result = child.caller_s1;
restore:
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x20u);
    context->caller_s3 = r_u32(frame + 0x1Cu);
    context->caller_s2 = r_u32(frame + 0x18u);
    context->caller_s1 = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80059990(uint32 progress, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 result;
    uint32 mode;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80059990u, "1.EXE");
    w_u32(frame + 0x20u, context->caller_s2);
    child.caller_s2 = progress;
    w_u32(frame + 0x1Cu, context->caller_s1);
    child.caller_s1 = 0x80090DFCu;
    w_u32(frame + 0x18u, context->caller_s0);
    child.caller_s0 = 1u;
    w_u32(frame + 0x24u, context->return_address);
    child.stack_pointer = frame;
    do
    {
        child.return_address = 0x800599BCu;
        sub_800598CC(child.caller_s1, &child);
        child.return_address = 0x800599C4u;
        sub_800598CC(child.caller_s1 + 20u, &child);
        w_u32(frame + 0x10u, 2u);
        w_u32(frame + 0x14u, 150u);
        child.return_address = 0x800599ECu;
        sub_800439A4(0x808080u, 100u, child.caller_s2, 0xFFFFFFC3u, &child);
        mode = r_u32(0x800A9D60u) == child.caller_s0 ? 2u : 0u;
        child.return_address = 0x80059A0Cu;
        sub_8001FF7C(mode, &child);
        sub_8001F850();
        result = r_u32(0x800A7410u);
    } while (result != child.caller_s0 && result != 0u);
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x24u);
    context->caller_s2 = r_u32(frame + 0x20u);
    context->caller_s1 = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
    return result;
}

uint32 sub_8003D7F0(uint32 language, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x58u;
    uint32 result;
    uint32 a, b, c, d;
    uint32 source, destination, index, offset;
    GameGeometryCallContext child = *context;
    GameSceneCallContext scene;
    FUNCTION_MARKER(0x8003D7F0u, "1.EXE");
    w_u32(frame + 0x50u, context->return_address);
    w_u32(frame + 0x4Cu, context->caller_s5);
    w_u32(frame + 0x48u, context->caller_s4);
    w_u32(frame + 0x44u, context->caller_s3);
    w_u32(frame + 0x40u, context->caller_s2);
    w_u32(frame + 0x3Cu, context->caller_s1);
    w_u32(frame + 0x38u, context->caller_s0);
    if (language >= 5u) language = 0u;
    child.stack_pointer = frame;
    child.caller_s5 = 0x800A5EFCu;
    w_u8(frame + 0x28u, language + 48u);
    w_u8(frame + 0x29u, 0u);
    a = r_u32(child.caller_s5); b = r_u32(child.caller_s5 + 4u); c = r_u32(child.caller_s5 + 8u);
    w_u32(frame + 0x10u, a); w_u32(frame + 0x14u, b); w_u32(frame + 0x18u, c);
    child.caller_s1 = frame + 0x10u;
    child.caller_s2 = frame + 0x28u;
    strcat((char *)psx_addr(child.caller_s1, 1u), (const char *)psx_addr(child.caller_s2, 1u));
    strcat((char *)psx_addr(child.caller_s1, 1u), (const char *)psx_addr(0x800A5F08u, 1u));
    scene.stack_pointer = frame; scene.return_address = 0x8003D874u; scene.caller_s0 = child.caller_s0;
    child.caller_s0 = sub_8005A4D8(child.caller_s1, &scene);
    scene.caller_s0 = child.caller_s0; scene.return_address = 0x8003D880u;
    result = sub_80069AD4(child.caller_s0, &scene);
    child.caller_s0 = scene.caller_s0;
    child.caller_s4 = 0xFFFFFFFFu; child.caller_s3 = result;
    if (child.caller_s0 == child.caller_s4) goto restore;
    child.return_address = 0x8003D89Cu;
    sub_8005A0D8(child.caller_s1, child.caller_s3, child.caller_s0, &child);
    scene.caller_s0 = child.caller_s0; scene.return_address = 0x8003D8A4u;
    result = sub_80069B38(0x45Cu, &scene);
    child.caller_s0 = scene.caller_s0;
    a = r_u32(child.caller_s5); b = r_u32(child.caller_s5 + 4u); c = r_u32(child.caller_s5 + 8u);
    w_u32(frame + 0x10u, a); w_u32(frame + 0x14u, b); w_u32(frame + 0x18u, c);
    source = child.caller_s2; child.caller_s2 = result;
    strcat((char *)psx_addr(child.caller_s1, 1u), (const char *)psx_addr(source, 1u));
    strcat((char *)psx_addr(child.caller_s1, 1u), (const char *)psx_addr(0x800A5F10u, 1u));
    scene.caller_s0 = child.caller_s0; scene.return_address = 0x8003D8E4u;
    child.caller_s0 = sub_8005A4D8(child.caller_s1, &scene);
    result = child.caller_s0;
    if (child.caller_s0 == child.caller_s4) goto restore;
    child.return_address = 0x8003D8FCu;
    sub_8005A0D8(child.caller_s1, child.caller_s2, child.caller_s0, &child);
    a = r_u32(child.caller_s2); result = 12u;
    if (a != 12u) goto restore;
    source = child.caller_s2 + 0x390u; destination = 0x800A8740u;
    do
    {
        a = r_u32(source); b = r_u32(source + 4u); c = r_u32(source + 8u); d = r_u32(source + 12u);
        w_u32(destination, a); w_u32(destination + 4u, b); w_u32(destination + 8u, c); w_u32(destination + 12u, d);
        source += 16u; destination += 16u;
    } while (source != child.caller_s2 + 0x430u);
    offset = 0xFFFFFFECu;
    for (index = 0u; index < 28u; ++index)
    {
        source = child.caller_s2 + offset;
        w_u16(0x8008FF38u + offset, r_u16(source + 0xB4u));
        w_u16(0x8008FF3Au + offset, r_u16(source + 0xB6u));
        w_u16(0x8008FF3Cu + offset, r_u16(source + 0xB8u));
        w_u16(0x8008FF3Eu + offset, r_u16(source + 0xBAu));
        w_u16(0x8008FF40u + offset, r_u16(source + 0xBCu));
        w_u16(0x8008FF42u + offset, r_u16(source + 0xBEu));
        offset += 20u;
    }
    for (index = 0u; index < 9u; ++index)
    {
        source = child.caller_s2 + index * 16u;
        w_u16(0x80090168u + index * 6u, r_u16(source + 0x2E6u));
        w_u16(0x8009016Au + index * 6u, r_u16(source + 0x2E8u));
        w_u16(0x8009016Cu + index * 6u, r_u16(source + 0x2EAu));
    }
    for (index = 0u; index < 3u; ++index)
        w_u16(0x800901A0u + index * 6u, r_u16(child.caller_s2 + index * 12u + 0x374u));
    result = r_u32(child.caller_s2 + 0x454u);
    if ((sint32)result > 0)
    {
        index = 0u;
        do
        {
            a = r_u32(child.caller_s2 + 0x45Cu + index * 4u);
            ++index;
            w_u32(0x800A8B38u + (index - 1u) * 4u, child.caller_s3 + a);
            result = (sint32)index < (sint32)r_u32(child.caller_s2 + 0x454u);
        } while (result != 0u);
    }
restore:
    context->caller_s6 = child.caller_s6; context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x50u);
    context->caller_s5 = r_u32(frame + 0x4Cu); context->caller_s4 = r_u32(frame + 0x48u);
    context->caller_s3 = r_u32(frame + 0x44u); context->caller_s2 = r_u32(frame + 0x40u);
    context->caller_s1 = r_u32(frame + 0x3Cu); context->caller_s0 = r_u32(frame + 0x38u);
    return result;
}

uint32 sub_8003C5E4(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x38u;
    uint32 a, b, c;
    uint32 index;
    uint32 result;
    GameGeometryCallContext child = *context;
    GameSceneCallContext scene;
    FUNCTION_MARKER(0x8003C5E4u, "1.EXE");
    w_u32(frame + 0x34u, context->return_address);
    w_u32(frame + 0x30u, context->caller_s2);
    w_u32(frame + 0x2Cu, context->caller_s1);
    w_u32(frame + 0x28u, context->caller_s0);
    a = r_u32(0x800A5E10u);
    b = r_u32(0x800A5E14u);
    c = r_u32(0x800A5E18u);
    w_u32(frame + 0x10u, a);
    w_u32(frame + 0x14u, b);
    w_u32(frame + 0x18u, c);
    a = r_u32(0x800A5E1Cu);
    b = r_u32(0x800A5E20u);
    c = r_u8(0x800A5E24u);
    w_u32(frame + 0x1Cu, a);
    w_u32(frame + 0x20u, b);
    w_u8(frame + 0x24u, c);
    child.stack_pointer = frame;
    child.caller_s1 = frame + 0x10u;
    scene.stack_pointer = frame;
    scene.return_address = 0x8003C664u;
    scene.caller_s0 = child.caller_s0;
    child.caller_s0 = sub_8005A4D8(child.caller_s1, &scene);
    scene.return_address = 0x8003C670u;
    scene.caller_s0 = child.caller_s0;
    child.caller_s2 = sub_80069B38(child.caller_s0, &scene);
    child.caller_s0 = scene.caller_s0;
    child.return_address = 0x8003C684u;
    sub_8005A0D8(child.caller_s1, child.caller_s2, child.caller_s0, &child);
    for (index = 0u; index < 72u; ++index)
    {
        w_u32(0x800A9348u + index * 4u, child.caller_s2 + 4u);
        a = r_u32(child.caller_s2);
        child.caller_s2 += a << 2u;
    }
    child.return_address = 0x8003C6BCu;
    result = sub_80035780(&child);
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x34u);
    context->caller_s2 = r_u32(frame + 0x30u);
    context->caller_s1 = r_u32(frame + 0x2Cu);
    context->caller_s0 = r_u32(frame + 0x28u);
    return result;
}

uint32 sub_80035780(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 index;
    uint32 offset;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80035780u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    for (index = 0u; index < 128u; ++index)
    {
        offset = index - 128u;
        w_u8(0x800A8420u + offset, (index * 96u) / 128u);
        w_u8(0x800A84A0u + offset, 96u - (index * 96u) / 128u);
        w_u8(0x800A82B4u + offset, index / 4u);
        w_u8(0x800A8334u + offset, 31u - index / 4u);
        w_u16(0x800A946Cu + index * 2u, offset);
        w_u16(0x800A956Cu + index * 2u, index);
    }
    w_u16(0x800A7DFCu, 0xFFFFu);
    w_u8(0x800A87EDu, 255u);
    w_u8(0x800A87ECu, 0u);
    w_u16(0x800A9A64u, 1u);
    for (index = 0u; index < 24u; ++index)
    {
        w_u16(0x800A7C0Au + index * 4u, 0u);
        w_u16(0x800A7C08u + index * 4u, 0u);
        w_u8(0x800A7E34u + index, 0u);
        w_u32(0x800A7C84u + index * 16u, 0x800A7DFCu);
    }
    w_u32(0x800A9CCCu, 0u);
    child.stack_pointer = frame;
    child.return_address = 0x800358ACu;
    sub_80036348(&child);
    child.return_address = 0x800358B4u;
    sub_800358DC(&child);
    child.return_address = 0x800358C0u;
    sub_80036E9C((uint32)(sint32)(sint16)r_u16(0x800A9D6Cu));
    child.return_address = 0x800358CCu;
    result = sub_80036EA8(r_u32(0x800A9CD0u), &child);
    context->caller_s0 = child.caller_s0;
    context->caller_s1 = child.caller_s1;
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80089218(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    FUNCTION_MARKER(0x80089218u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    result = _SpuInit(0u);
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_800362B8(uint32 index, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 offset = index << 3u;
    uint32 source;
    uint32 length;
    uint32 allocation;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x800362B8u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x18u, context->return_address);
    w_u32(frame + 0x14u, context->caller_s1);
    source = r_u32(0x800A7FC4u + offset);
    length = r_u32(source + 12u);
    allocation = (uint32)SpuMalloc((sint32)length);
    if (allocation == 0u)
        result = 0xFFFFFFFFu;
    else
    {
        allocation = SpuSetTransferStartAddr(allocation);
        source = r_u32(0x800A7FC4u + offset);
        w_u32(0x800A7FC0u + offset, allocation);
        child.stack_pointer = frame;
        child.return_address = 0x80036324u;
        child.caller_s0 = offset;
        child.caller_s1 = length;
        sub_80089490(source + 48u, length, &child);
        SpuIsTransferCompleted(1);
        result = length;
    }
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x18u);
    context->caller_s1 = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80036348(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x48u;
    uint32 value;
    uint32 failed;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80036348u, "1.EXE");
    w_u32(frame + 0x44u, context->return_address);
    w_u32(frame + 0x40u, context->caller_s2);
    w_u32(frame + 0x3Cu, context->caller_s1);
    w_u32(frame + 0x38u, context->caller_s0);
    child.stack_pointer = frame;
    child.return_address = 0x80036360u;
    sub_80089218(&child);
    SpuInitMalloc(72u, 0x800A9A84u);
    w_u32(frame + 0x10u, 0x3C3u);
    w_u16(frame + 0x20u, 0x3FFFu);
    w_u16(frame + 0x22u, 0x3FFFu);
    w_u16(frame + 0x14u, 0x3FFFu);
    w_u16(frame + 0x16u, 0x3FFFu);
    w_u32(frame + 0x28u, 1u);
    w_u32(frame + 0x24u, 1u);
    w_u32(0x800A9CD0u, 0x4000u);
    w_u32(0x800A9684u, 0x4000u);
    w_u32(0x800A975Cu, 0x6000u);
    w_u16(0x800A9D6Cu, 0x1000u);
    SpuSetCommonAttr((SpuCommonAttr *)psx_addr(frame + 0x10u, sizeof(SpuCommonAttr)));
    SpuSetTransferMode(0);
    child.caller_s0 = 0u;
    child.caller_s2 = 0x800A9348u;
    child.caller_s1 = 0u;
    do
    {
        value = r_u32(child.caller_s2);
        w_u32(0x800A7FC4u + child.caller_s1, value);
        child.return_address = 0x800363ECu;
        value = sub_800362B8(child.caller_s0, &child);
        failed = value >> 31u;
        child.caller_s2 += 4u;
        if (failed != 0u)
        {
            value = r_u32(0x800A9CCCu);
            w_u32(0x800A9CCCu, value + failed);
        }
        ++child.caller_s0;
        child.caller_s1 += 8u;
    } while ((sint32)child.caller_s0 < 72);
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x44u);
    context->caller_s2 = r_u32(frame + 0x40u);
    context->caller_s1 = r_u32(frame + 0x3Cu);
    context->caller_s0 = r_u32(frame + 0x38u);
    return 0u;
}

#include "game_scene.h"











uint32 sub_80069B38(uint32 size, GameSceneCallContext *context);
uint32 sub_80069AD4(uint32 size, GameSceneCallContext *context);











uint32 sub_80059990(uint32 progress, GameGeometryCallContext *context);
uint32 sub_80035A08(uint32 channel, uint32 pitch, uint32 volume, uint32 mode,
    GameGeometryCallContext *context);
uint32 sub_800598CC(uint32 resource, GameGeometryCallContext *context);
uint32 sub_800439A4(uint32 color, uint32 number, uint32 subtract, uint32 x,
    GameGeometryCallContext *context);
uint32 sub_8001FF7C(uint32 mode, GameGeometryCallContext *context);
void sub_8001F850(void);
uint32 sub_80059C2C(GameGeometryCallContext *context);



void sub_800643EC(GameRenderCallContext *context);
uint32 sub_80020C60(uint32 index, uint32 table, uint32 color, uint32 mode,
    GameGeometryCallContext *context);



uint32 sub_80035CD0(uint32 mode, GameGeometryCallContext *context);



uint32 sub_8005A4D8(uint32 filename, GameSceneCallContext *context);
uint32 sub_8005A0D8(uint32 filename, uint32 destination, uint32 length,
    GameGeometryCallContext *context);



uint32 sub_8003BF34(uint32 filename, GameGeometryCallContext *context);
uint32 sub_8005A3E4(uint32 filename, uint32 destination, GameGeometryCallContext *context);
void sub_80036E9C(uint32 value);
uint32 sub_80036EA8(uint32 value, GameGeometryCallContext *context);
uint32 sub_800649D4(uint32 value);
uint32 sub_80089490(uint32 source, uint32 length, GameGeometryCallContext *context);
uint32 sub_800358DC(GameGeometryCallContext *context);
uint32 sub_80064A44(uint32 base, uint32 size, GameGeometryCallContext *context);
uint32 sub_800649E4(GameGeometryCallContext *context);
uint32 sub_8005AAE0(void);
uint32 sub_80021200(uint32 resource);
uint32 sub_8005A8F0(GameGeometryCallContext *context);
uint32 sub_80059A88(uint32 radius, uint32 angle);
uint32 sub_80059CE4(uint32 progress, GameGeometryCallContext *context);
uint32 sub_80059C2C(GameGeometryCallContext *context);
uint32 sub_80035A08(uint32 channel, uint32 pitch, uint32 volume, uint32 mode,
    GameGeometryCallContext *context);
uint32 sub_8003C6D8(uint32 language, GameGeometryCallContext *context);
uint32 sub_8003BA80(uint32 mission, uint32 allocation, uint32 loading,
    GameGeometryCallContext *context);

void sub_80036E9C(uint32 value)
{
    FUNCTION_MARKER(0x80036E9Cu, "1.EXE");
    w_u16(0x800A9D6Cu, value);
}

uint32 sub_80036EA8(uint32 value, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x40u;
    FUNCTION_MARKER(0x80036EA8u, "1.EXE");
    w_u32(0x800A9CD0u, value);
    w_u16(frame + 0x20u, value);
    w_u16(frame + 0x22u, value);
    w_u32(frame + 0x38u, context->return_address);
    w_u32(frame + 0x10u, 0xC0u);
    SpuSetCommonAttr((SpuCommonAttr *)psx_addr(frame + 0x10u, sizeof(SpuCommonAttr)));
    context->return_address = r_u32(frame + 0x38u);
    // Original SDK leaves V0 as mask & 0x2000 for mask 0xC0
    return 0u;
}

uint32 sub_800649D4(uint32 value)
{
    FUNCTION_MARKER(0x800649D4u, "1.EXE");
    return (value + 3u) & 0xFFFFFFFCu;
}

uint32 sub_80089490(uint32 source, uint32 length, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 limited = length;
    uint32 mode;
    FUNCTION_MARKER(0x80089490u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->return_address);
    if (limited > 0x7EFF0u)
        limited = 0x7EFF0u;
    _spu_Fw(source, limited);
    mode = r_u32(0x800A4E4Cu);
    if (mode == 0u)
        w_u32(0x800A4E48u, 0u);
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return limited;
}

uint32 sub_800358DC(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    FUNCTION_MARKER(0x800358DCu, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(0x800A8204u, 31u);
    w_u32(0x800A8208u, 4u);
    w_u32(0x800A8210u, 40u);
    w_u32(frame + 0x14u, context->return_address);
    w_u16(0x800A820Cu, 0u);
    w_u16(0x800A820Eu, 0u);
    w_u32(0x800A8214u, 100u);
    SpuSetReverbModeParam((SpuReverbAttr *)psx_addr(0x800A8204u, sizeof(SpuReverbAttr)));
    SpuSetReverbDepth((SpuReverbAttr *)psx_addr(0x800A8204u, sizeof(SpuReverbAttr)));
    result = (uint32)SpuReserveReverbWorkArea(1);
    if (result == 1u)
    {
        result = (uint32)SpuClearReverbWorkArea((sint32)r_u32(0x800A8208u));
        if (result == 0xFFFFFFFFu)
            goto restore;
    }
    result = (uint32)SpuIsReverbWorkAreaReserved(1);
restore:
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80064A44(uint32 base, uint32 size, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 start, end, distance, packed, word;
    FUNCTION_MARKER(0x80064A44u, "1.EXE");
    w_u32(frame + 0x14u, context->return_address);
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(0x800A7480u, size);
    w_u32(0x800A8738u, base);
    start = sub_800649D4(base);
    end = sub_800649D4(r_u32(0x800A8738u) + r_u32(0x800A7480u) - 0x10u);
    word = r_u32(start);
    distance = end - start;
    w_u32(start, word & 0xFFFFFu);
    word = r_u32(start);
    packed = distance & 0xFFFFFu;
    w_u32(start + 4u, 0u);
    w_u32(start, (word & 0xFFF00000u) | packed);
    word = r_u32(end);
    distance -= 8u;
    w_u32(0x800A748Cu, 0u);
    w_u32(0x800A7484u, 0u);
    w_u32(0x800A7488u, 0u);
    w_u32(end + 4u, packed);
    w_u32(end, word & 0xFFFFFu);
    word = r_u32(end);
    w_u32(0x800A7490u, 1u);
    w_u32(end, word & 0xFFF00000u);
    w_u32(0x800AC6A8u, start);
    w_u32(0x800AC6ACu, distance);
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return end;
}

uint32 sub_800649E4(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 base, size, result;
    GameSceneCallContext scene;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x800649E4u, "1.EXE");
    w_u32(frame + 0x14u, context->return_address);
    w_u32(frame + 0x10u, context->caller_s0);
    scene.stack_pointer = frame;
    scene.return_address = 0x800649F8u;
    scene.caller_s0 = context->caller_s0;
    base = sub_80069B38(1u, &scene);
    size = 0x801FFC00u - base;
    w_u32(0x800A8668u, base);
    if (size > 0xF0000u)
        size = 0xF0000u;
    scene.return_address = 0x80064A24u;
    scene.caller_s0 = size;
    base = sub_80069AD4(size, &scene);
    child.stack_pointer = frame;
    child.return_address = 0x80064A30u;
    child.caller_s0 = scene.caller_s0;
    result = sub_80064A44(base, child.caller_s0, &child);
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8005AAE0(void)
{
    uint32 table, header, tag, pointer, index;
    uint32 result = 0x41u;
    FUNCTION_MARKER(0x8005AAE0u, "1.EXE");
    table = r_u32(0x800A62F4u);
    header = r_u32(0x800A62ECu);
    tag = r_u32(table);
    index = (uint32)(sint32)(sint16)r_u16(header + 0x2Cu);
    if (tag == 0x41u)
    {
        pointer = r_u32(table + (index << 3) + 0x14u);
        for (index = 0u; index < 4u; ++index)
        {
            w_u32(pointer + 4u, (uint32)r_u16(pointer + 4u) | 0x78190000u);
            result = index + 1u < 4u;
            pointer += 0x20u;
        }
    }
    return result;
}

uint32 sub_80021200(uint32 resource)
{
    uint32 pointer = 0x800C15CCu;
    uint32 flags, base, entry, count, offset, index, result, word;
    FUNCTION_MARKER(0x80021200u, "1.EXE");
    for (index = 0u; index < 500u; ++index)
    {
        w_u32(pointer, 0u);
        pointer -= 4u;
    }
    flags = r_u32(resource + 4u);
    base = resource + 0xCu;
    entry = resource + 0x14u;
    count = r_u32(resource + 8u);
    if ((flags & 1u) == 0u)
    {
        offset = r_u32(resource + 0xCu);
        w_u32(resource + 4u, flags | 1u);
        w_u32(0x800A7E08u, base);
        w_u32(resource + 0xCu, base + offset);
        w_u32(0x800A9A44u, count);
        pointer = 0x800C0E00u;
        for (index = 0u; index < count; ++index)
        {
            offset = r_u32(entry);
            w_u32(entry, base + offset);
            w_u32(pointer, entry);
            pointer += 4u;
            entry += 8u;
        }
    }
    else
    {
        w_u32(0x800A7E08u, base);
        w_u32(0x800A9A44u, count);
        pointer = 0x800C0E00u;
        for (index = 0u; index < count; ++index)
        {
            w_u32(pointer, entry);
            pointer += 4u;
            entry += 8u;
        }
    }
    result = r_u32(base);
    word = r_u32(base + 4u);
    w_u32(0x800A9A7Cu, result);
    w_u32(0x800A84D8u, word);
    return result;
}

uint32 sub_8005A8F0(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 pixels, result;
    FUNCTION_MARKER(0x8005A8F0u, "1.EXE");
    w_u16(frame + 0x10u, 0x140u);
    w_u16(frame + 0x14u, 0x2C0u);
    pixels = r_u32(0x800A62F0u);
    w_u32(frame + 0x18u, context->return_address);
    w_u16(frame + 0x12u, 0u);
    w_u16(frame + 0x16u, 0x200u);
    result = (uint32)LoadImagePSX((PSX_RECT *)psx_addr(frame + 0x10u, sizeof(PSX_RECT)),
        (uint32 *)psx_addr(pixels, 1u));
    context->return_address = r_u32(frame + 0x18u);
    return result;
}

uint32 sub_80059A88(uint32 radius, uint32 angle)
{
    uint32 color = (sint32)radius < 256 ? radius : 255u;
    uint32 pointer, phase, next, value, table, word, result;
    FUNCTION_MARKER(0x80059A88u, "1.EXE");
    w_u8(r_u32(0x800A7434u) + 3u, 5u);
    w_u8(r_u32(0x800A7434u) + 7u, 0x28u);
    pointer = r_u32(0x800A7434u);
    w_u8(pointer + 7u, r_u8(pointer + 7u) & 0xFDu);
    w_u8(r_u32(0x800A7434u) + 4u, color);
    w_u8(r_u32(0x800A7434u) + 5u, color);
    pointer = r_u32(0x800A7434u);
    angle <<= 7;
    w_u8(pointer + 6u, color);
    phase = (angle & 0xFFFu) << 1;
    value = (uint32)(sint32)(sint16)r_u16(0x800102E0u + phase) * radius;
    pointer = r_u32(0x800A7434u);
    w_u16(pointer + 8u, (uint32)((sint32)value / 4096) + 187u);
    value = (uint32)(sint32)(sint16)r_u16(0x80010AE0u + phase) * radius;
    w_u16(pointer + 10u, (uint32)((sint32)value / 4096) + 120u);
    next = ((angle + 128u) & 0xFFFu) << 1;
    value = (uint32)(sint32)(sint16)r_u16(0x800102E0u + next) * radius;
    w_u16(pointer + 12u, (uint32)((sint32)value / 4096) + 187u);
    value = (uint32)(sint32)(sint16)r_u16(0x80010AE0u + next) * radius;
    value = (uint32)((sint32)value / 4096) + 120u;
    table = r_u32(0x800A9A74u);
    w_u16(pointer + 14u, value);
    w_u16(pointer + 16u, 187u);
    w_u16(pointer + 20u, 187u);
    word = r_u32(pointer);
    w_u16(pointer + 18u, 144u);
    w_u16(pointer + 22u, 144u);
    value = r_u32(table + 0x140u);
    w_u32(pointer, (word & 0xFF000000u) | (value & 0xFFFFFFu));
    value = r_u32(table + 0x140u);
    w_u32(0x800A7434u, pointer + 0x18u);
    result = (value & 0xFF000000u) | (pointer & 0xFFFFFFu);
    w_u32(table + 0x140u, result);
    return result;
}

uint32 sub_80059CE4(uint32 progress, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 result, mode;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80059CE4u, "1.EXE");
    w_u32(frame + 0x18u, context->caller_s0);
    w_u32(frame + 0x24u, context->return_address);
    w_u32(frame + 0x20u, context->caller_s2);
    w_u32(frame + 0x1Cu, context->caller_s1);
    child.stack_pointer = frame;
    child.caller_s0 = progress;
    SetDispMask(1);
    child.caller_s1 = 1u;
    while ((sint32)child.caller_s0 < 102)
    {
        child.return_address = 0x80059D18u;
        sub_80059990(child.caller_s0, &child);
        VSync(2);
        ++child.caller_s0;
        child.caller_s1 = 1u;
    }
    w_u32(frame + 0x10u, 0u);
    child.return_address = 0x80059D48u;
    sub_80035A08(14u, 0x800u, 255u, 0u, &child);
    SetDispMask(1);
    child.caller_s2 = 0x80090DFCu;
    do
    {
        result = r_u32(0x800A865Cu);
        child.caller_s0 = 0u;
        w_u32(0x800A7434u, result);
        do
        {
            sub_80059A88(child.caller_s1, child.caller_s0);
            ++child.caller_s0;
        } while ((sint32)child.caller_s0 < 32);
        w_u32(0x800A865Cu, r_u32(0x800A7434u));
        child.return_address = 0x80059D98u;
        sub_800598CC(child.caller_s2, &child);
        child.return_address = 0x80059DA0u;
        sub_800598CC(child.caller_s2 + 0x14u, &child);
        w_u32(frame + 0x10u, 2u);
        w_u32(frame + 0x14u, 150u);
        child.return_address = 0x80059DC8u;
        sub_800439A4(0x808080u, 100u, 100u, 0xFFFFFFC3u, &child);
        mode = r_u32(0x800A9D60u) == 1u ? 2u : 0u;
        child.caller_s1 += 16u;
        child.return_address = 0x80059DE8u;
        sub_8001FF7C(mode, &child);
        sub_8001F850();
    } while ((sint32)child.caller_s1 < 300);
    child.return_address = 0x80059E04u;
    result = sub_80059C2C(&child);
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x24u);
    context->caller_s2 = r_u32(frame + 0x20u);
    context->caller_s1 = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
    return result;
}

uint32 sub_80059C2C(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 result, mode;
    GameSceneCallContext scene;
    GameGeometryCallContext child = *context;
    GameRenderCallContext render;
    FUNCTION_MARKER(0x80059C2Cu, "1.EXE");
    w_u32(frame + 0x24u, context->return_address);
    w_u32(frame + 0x20u, context->caller_s0);
    scene.stack_pointer = frame;
    scene.return_address = 0x80059C40u;
    scene.caller_s0 = context->caller_s0;
    sub_80064334(1u, &scene);
    SetDispMask(1);
    child.stack_pointer = frame;
    child.caller_s0 = 0u;
    do
    {
        w_u32(frame + 0x10u, 0xFFFFFF60u);
        w_u32(frame + 0x14u, 0xFFFFFF88u);
        w_u32(frame + 0x18u, 320u);
        result = r_u32(0x800A9A74u);
        w_u32(frame + 0x1Cu, 256u);
        child.return_address = 0x80059C8Cu;
        sub_80020C60(0u, result + 0x258u, 0xFFFFFFu, 1u, &child);
        render.stack_pointer = frame;
        render.return_address = 0x80059C94u;
        render.caller_s0 = child.caller_s0;
        render.caller_s1 = child.caller_s1;
        render.caller_s2 = child.caller_s2;
        render.caller_s3 = child.caller_s3;
        render.caller_s4 = child.caller_s4;
        render.caller_s5 = child.caller_s5;
        render.caller_s6 = child.caller_s6;
        render.caller_s7 = child.caller_s7;
        sub_800643EC(&render);
        child.caller_s0 = render.caller_s0;
        child.caller_s1 = render.caller_s1;
        child.caller_s2 = render.caller_s2;
        child.caller_s3 = render.caller_s3;
        child.caller_s4 = render.caller_s4;
        child.caller_s5 = render.caller_s5;
        child.caller_s6 = render.caller_s6;
        child.caller_s7 = render.caller_s7;
        mode = r_u32(0x800A9D60u) == 1u ? 2u : 0u;
        ++child.caller_s0;
        child.return_address = 0x80059CB4u;
        sub_8001FF7C(mode, &child);
        sub_8001F850();
    } while ((sint32)child.caller_s0 < 2);
    scene.return_address = 0x80059CD0u;
    scene.caller_s0 = child.caller_s0;
    result = sub_80064334(0u, &scene);
    context->caller_s1 = child.caller_s1;
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x24u);
    context->caller_s0 = r_u32(frame + 0x20u);
    return result;
}

uint32 sub_80035A08(uint32 channel, uint32 pitch, uint32 volume, uint32 mode,
    GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 index, offset, source, word, scaled, value, result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80035A08u, "1.EXE");
    w_u32(frame + 0x14u, context->return_address);
    w_u32(frame + 0x10u, context->caller_s0);
    for (;;)
    {
        value = (uint32)r_u16(0x800A5C54u) + 1u;
        w_u16(0x800A5C54u, value);
        if ((sint16)value == 14)
            w_u16(0x800A5C54u, 0u);
        word = (uint32)(sint32)(sint16)r_u16(0x800A56AEu);
        index = (uint32)(sint32)(sint16)r_u16(0x800A5C54u);
        if (word == index)
            continue;
        if ((uint32)(sint32)(sint16)r_u16(0x800A5C44u) == index)
            continue;
        if ((uint32)(sint32)(sint16)r_u16(0x800A56ACu) == index)
            continue;
        word = (uint32)(sint32)(sint16)r_u16(0x800A56B4u);
        offset = index << 6;
        if (word != index)
            break;
    }
    source = (uint32)((sint32)(channel << 16) >> 13);
    w_u32(0x800BBF00u + offset, 0x93u);
    w_u16(0x800BBF10u + offset, pitch);
    word = r_u32(0x800A7FC0u + source);
    w_u32(0x800BBF1Cu + offset, word);
    word = r_u32(0x800A7FC0u + source);
    w_u32(0x800BBEFCu + offset, 1u << (index & 31u));
    w_u32(0x800BBF18u + offset, word);
    if (mode != 0u)
    {
        w_u16(0x800BBF04u + offset, 0u);
        w_u16(0x800BBF06u + offset, 0u);
        child.stack_pointer = frame;
        child.return_address = 0x80035B1Cu;
        sub_80035CD0(mode, &child);
        offset = (uint32)(sint32)(sint16)r_u16(0x800A5C54u) << 6;
        value = (uint32)(sint32)(sint16)r_u16(0x800BBF04u + offset);
        w_u16(0x800BBF04u + offset, (sint32)value < 0x4000 ? value * 3u : 0x3FFFu);
        offset = (uint32)(sint32)(sint16)r_u16(0x800A5C54u) << 6;
        value = (uint32)(sint32)(sint16)r_u16(0x800BBF06u + offset);
        w_u16(0x800BBF06u + offset, (sint32)value < 0x4000 ? value * 3u : 0x3FFFu);
    }
    else
    {
        value = (uint32)(sint32)(sint16)r_u16(0x800A9D6Cu);
        scaled = (value << 14) - value;
        scaled = (uint32)((sint32)scaled / 16384) * (volume & 255u);
        scaled = (uint32)((sint32)scaled / 256);
        w_u16(0x800BBF04u + offset, scaled);
        w_u16(0x800BBF06u + offset, scaled);
    }
    index = (uint32)(sint32)(sint16)r_u16(0x800A5C54u);
    offset = index << 6;
    value = r_u16(0x800BBF04u + offset);
    w_u16(0x800A7C08u + (index << 2), value);
    value = r_u16(0x800BBF06u + offset);
    w_u16(0x800A7C0Au + (index << 2), value);
    SpuSetVoiceAttr((SpuVoiceAttr *)psx_addr(0x800BBEFCu + offset, sizeof(SpuVoiceAttr)));
    index = (uint32)(sint32)(sint16)r_u16(0x800A5C54u);
    SpuSetReverbVoice(r_u8(0x800A7E34u + index) != 0u, 1u << (index & 31u));
    index = (uint32)(sint32)(sint16)r_u16(0x800A5C54u);
    child.caller_s0 = 1u;
    SpuSetKey(0, 1u << (index & 31u));
    index = (uint32)(sint32)(sint16)r_u16(0x800A5C54u);
    SpuSetKey(1, child.caller_s0 << (index & 31u));
    result = (uint32)(sint32)(sint16)r_u16(0x800A5C54u);
    context->caller_s1 = child.caller_s1;
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8003C6D8(uint32 language, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x50u;
    uint32 stage, first, second, third, fourth, result, offset, base;
    GameGeometryCallContext child = *context;
    GameSceneCallContext scene;
    FUNCTION_MARKER(0x8003C6D8u, "1.EXE");
    w_u32(frame + 0x48u, context->return_address);
    w_u32(frame + 0x44u, context->caller_s3);
    w_u32(frame + 0x40u, context->caller_s2);
    w_u32(frame + 0x3Cu, context->caller_s1);
    w_u32(frame + 0x38u, context->caller_s0);
    if ((sint16)language < 5)
    {
        w_u8(frame + 0x28u, language + 48u);
        w_u8(frame + 0x29u, 0u);
    }
    child.stack_pointer = frame;
    child.caller_s2 = 0x800A5E28u;
    child.caller_s0 = frame + 0x10u;
    child.caller_s1 = frame + 0x28u;
    for (stage = 0u; stage < 2u; ++stage)
    {
        first = r_u32(child.caller_s2);
        second = r_u16(child.caller_s2 + 4u);
        third = r_u8(child.caller_s2 + 6u);
        w_u32(frame + 0x10u, first);
        w_u16(frame + 0x14u, second);
        w_u8(frame + 0x16u, third);
        strcat((char *)psx_addr(child.caller_s0, 1u),
            (char *)psx_addr(child.caller_s1, 1u));
        strcat((char *)psx_addr(child.caller_s0, 1u),
            (char *)psx_addr(stage == 0u ? 0x800A5E30u : 0x800A5E40u, 1u));
        scene.stack_pointer = frame;
        scene.return_address = stage == 0u ? 0x8003C75Cu : 0x8003C7CCu;
        scene.caller_s0 = child.caller_s0;
        child.caller_s3 = sub_8005A4D8(child.caller_s0, &scene);
        child.caller_s0 = scene.caller_s0;
        scene.return_address = stage == 0u ? 0x8003C768u : 0x8003C7D8u;
        base = stage == 0u ? sub_80069B38(child.caller_s3, &scene)
            : sub_80069AD4(child.caller_s3, &scene);
        child.caller_s0 = scene.caller_s0;
        if (stage == 0u)
            w_u32(0x800A62F0u, base);
        first = child.caller_s0;
        if (stage != 0u)
            child.caller_s0 = base;
        child.return_address = stage == 0u ? 0x8003C780u : 0x8003C7ECu;
        sub_8005A0D8(first, base, child.caller_s3, &child);
        if (stage == 0u)
        {
            child.return_address = 0x8003C788u;
            sub_8005A8F0(&child);
            DrawSync(0);
        }
    }
    base = child.caller_s0;
    offset = (r_u32(base) + 1u) << 2;
    first = r_u32(base + 4u);
    second = r_u32(base + 8u);
    third = r_u32(base + 12u);
    w_u32(0x800A62ECu, base + offset + first);
    w_u32(0x800A62E8u, base + offset + first);
    w_u32(0x800A62F4u, base + offset + first + second);
    result = first + second + third;
    fourth = r_u32(base + 16u);
    w_u32(0x800A62F8u, base + offset + result);
    result += fourth;
    w_u32(0x800A6300u, base + offset + result);
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x48u);
    context->caller_s3 = r_u32(frame + 0x44u);
    context->caller_s2 = r_u32(frame + 0x40u);
    context->caller_s1 = r_u32(frame + 0x3Cu);
    context->caller_s0 = r_u32(frame + 0x38u);
    return result;
}

uint32 sub_8003BA80(uint32 mission, uint32 allocation, uint32 loading,
    GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x40u;
    uint32 words[4], i, phase, source, flag, quotient, remainder, result, destination;
    GameGeometryCallContext child = *context;
    GameSceneCallContext scene;
    FUNCTION_MARKER(0x8003BA80u, "1.EXE");
    w_u32(frame + 0x34u, context->caller_s3);
    w_u32(frame + 0x38u, context->caller_s4);
    w_u32(frame + 0x3Cu, context->return_address);
    w_u32(frame + 0x30u, context->caller_s2);
    w_u32(frame + 0x2Cu, context->caller_s1);
    w_u32(frame + 0x28u, context->caller_s0);
    child.stack_pointer = frame;
    child.caller_s3 = allocation;
    child.caller_s4 = loading;
    for (i = 0u; i < 4u; ++i)
        words[i] = r_u32(0x800A5D58u + i * 4u);
    for (i = 0u; i < 4u; ++i)
        w_u32(frame + 0x10u + i * 4u, words[i]);
    words[0] = r_u32(0x800A5D68u);
    words[1] = r_u32(0x800A5D6Cu);
    w_u32(frame + 0x20u, words[0]);
    w_u32(frame + 0x24u, words[1]);
    flag = r_u32(0x800A9760u);
    child.caller_s2 = 1u;
    child.caller_s1 = frame + 0x10u;
    if (flag == 1u)
    {
        mission = r_u32(0x800A9764u);
        flag = r_u32(0x800A9760u);
    }
    for (phase = 0u; phase < 4u; ++phase)
    {
        source = 0x800A5D58u;
        if (phase == 1u)
        {
            if (flag != child.caller_s2)
                continue;
            source = 0x800A5D70u;
        }
        if (phase == 2u)
        {
            if (r_u32(0x800A8690u) != 2u)
                continue;
        }
        if (phase == 3u)
        {
            if (r_u32(0x800A8690u) != child.caller_s2)
                continue;
            source = 0x800A5D88u;
        }
        if (phase == 0u || phase == 2u)
        {
            for (i = 0u; i < 4u; ++i)
                words[i] = r_u32(source + i * 4u);
            for (i = 0u; i < 4u; ++i)
                w_u32(frame + 0x10u + i * 4u, words[i]);
            words[0] = r_u32(source + 0x10u);
            words[1] = r_u16(source + 0x14u);
            words[2] = r_u8(source + 0x16u);
            w_u32(frame + 0x20u, words[0]);
            w_u16(frame + 0x24u, words[1]);
            w_u8(frame + 0x26u, words[2]);
        }
        else
        {
            for (i = 0u; i < 3u; ++i)
                words[i] = r_u32(source + i * 4u);
            for (i = 0u; i < 3u; ++i)
                w_u32(frame + 0x10u + i * 4u, words[i]);
            words[0] = r_u32(source + 0xCu);
            words[1] = r_u32(source + 0x10u);
            words[2] = r_u16(source + 0x14u);
            w_u32(frame + 0x1Cu, words[0]);
            w_u32(frame + 0x20u, words[1]);
            w_u16(frame + 0x24u, words[2]);
            w_u8(frame + 0x26u, r_u8(source + 0x16u));
        }
        if (phase == 2u)
            mission += 50u;
    }
    quotient = (uint32)((sint32)mission / 10);
    remainder = mission - quotient * 10u;
    w_u8(frame + 0x1Au, (uint32)r_u8(0x800A8FD4u) + 48u);
    child.caller_s0 = quotient;
    w_u8(frame + 0x1Cu, quotient + 48u);
    w_u8(frame + 0x1Eu, quotient + 48u);
    w_u8(frame + 0x1Fu, remainder + 48u);
    scene.stack_pointer = frame;
    scene.return_address = 0x8003BCA4u;
    scene.caller_s0 = child.caller_s0;
    child.caller_s0 = sub_8005A4D8(child.caller_s1, &scene);
    if ((sint32)child.caller_s0 <= 0)
    {
        child.return_address = 0x8003BCB8u;
        sub_8003BF34(child.caller_s1, &child);
    }
    if (child.caller_s3 == child.caller_s2)
    {
        scene.return_address = 0x8003BCC8u;
        scene.caller_s0 = child.caller_s0;
        result = sub_80069AD4(child.caller_s0, &scene);
        child.caller_s0 = scene.caller_s0;
        w_u32(0x800A62FCu, result);
    }
    if (child.caller_s3 == 0u)
    {
        scene.return_address = 0x8003BCE0u;
        scene.caller_s0 = child.caller_s0;
        result = sub_80069B38(child.caller_s0, &scene);
        child.caller_s0 = scene.caller_s0;
        w_u32(0x800A62FCu, result);
    }
    destination = r_u32(0x800A62FCu);
    if (child.caller_s4 == 0u)
    {
        child.return_address = 0x8003BD00u;
        sub_8005A3E4(child.caller_s1, destination, &child);
    }
    else
    {
        child.return_address = 0x8003BD18u;
        sub_8005A0D8(child.caller_s1, destination, child.caller_s0, &child);
    }
    destination = r_u32(0x800A62FCu);
    if ((sint16)r_u16(destination + 2u) != 192 || (sint32)child.caller_s0 <= 0)
    {
        child.return_address = 0x8003BD44u;
        sub_8003BF34(frame + 0x10u, &child);
    }
    result = r_u8(r_u32(0x800A62FCu));
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x3Cu);
    context->caller_s4 = r_u32(frame + 0x38u);
    context->caller_s3 = r_u32(frame + 0x34u);
    context->caller_s2 = r_u32(frame + 0x30u);
    context->caller_s1 = r_u32(frame + 0x2Cu);
    context->caller_s0 = r_u32(frame + 0x28u);
    return result;
}
