#include "psx.h"

#include "game_scene.h"

uint32 sub_8003BE08(uint32 image, GameGeometryCallContext *context);
uint32 sub_8003BD78(uint32 source, uint32 destination);
uint32 sub_8003B864(GameGeometryCallContext *context);
uint32 sub_8003B574(uint32 selected, uint32 mode, GameGeometryCallContext *context);
uint32 sub_80059860(uint32 divisor);
uint32 sub_8003C3D4(GameGeometryCallContext *context);
uint32 sub_80021144(uint32 selection, GameSceneCallContext *context);
uint32 sub_80020C60(uint32 index, uint32 table, uint32 color, uint32 mode,
    GameGeometryCallContext *context);
uint32 sub_8003BFAC(GameGeometryCallContext *context);
uint32 sub_8006499C(GameSceneCallContext *context);
uint32 sub_80064594(uint32 target, uint32 baseline, GameGeometryCallContext *context);
uint32 sub_80054D38(uint32 x, uint32 y, uint32 z, uint32 output,
    GameSceneCallContext *context);
void sub_8001F850(void);
uint32 sub_8001FF7C(uint32 mode, GameGeometryCallContext *context);
void sub_800643EC(GameRenderCallContext *context);
void sub_80031C1C(uint32 matrix, uint32 vector, uint32 destination);
uint32 sub_80069AD4(uint32 size, GameSceneCallContext *context);
uint32 sub_80069BC0(uint32 index);
uint32 sub_80069B84(uint32 index, GameSceneCallContext *context);
uint32 sub_80059E2C(GameSceneCallContext *context);
uint32 sub_8005A4D8(uint32 filename, GameSceneCallContext *context);
uint32 sub_80069B38(uint32 size, GameSceneCallContext *context);
uint32 sub_8005A3E4(uint32 filename, uint32 destination, GameGeometryCallContext *context);
uint32 sub_80080230(uint32 rectangle, uint32 buffer);
uint32 sub_80064334(uint32 force_default, GameSceneCallContext *context);
uint32 sub_80039198(void);
uint32 sub_8003C394(GameGeometryCallContext *context);
uint32 sub_800649E4(GameGeometryCallContext *context);

uint32 sub_800202B0(uint32 page);
uint32 sub_80020D98(uint32 index, uint32 table, uint32 color, uint32 x, uint32 entry_sp);
uint32 sub_80021200(uint32 argument_0);
uint32 sub_80021368(void);
uint32 sub_80032D80(void);
uint32 sub_800376D0(void);
uint32 sub_80037864(void);
sint32 sub_800389A8(GameMainCallContext *context);
uint32 sub_80039224(void);
uint32 sub_8003BA80(uint32 mission, uint32 allocation, uint32 loading,
    GameGeometryCallContext *context);
uint32 sub_8003C4B8(GameGeometryCallContext *context);
uint32 sub_8003C5E4(GameGeometryCallContext *context);
uint32 sub_8003C6D8(uint32 language, GameGeometryCallContext *context);
uint32 sub_8003D7F0(uint32 language, GameGeometryCallContext *context);
uint32 sub_80059400(void);
uint32 sub_80059610(GameGeometryCallContext *context);
void sub_8005A5F8(uint32 value, GameGeometryCallContext *context);
uint32 sub_8005A69C(uint32 count, GameGeometryCallContext *context);
uint32 sub_8005AAE0(void);
uint32 sub_8005E818(void);
uint32 sub_8005EB2C(void);
uint32 sub_80064784(uint32 argument_0, uint32 argument_1);
uint32 sub_800648A4(uint32 argument_0);
uint32 sub_800650CC(void);
uint32 sub_80065124(void);
uint32 sub_800651AC(uint32 resource, GameGeometryCallContext *context);
uint32 sub_80073B78(GameGeometryCallContext *context);
uint32 sub_80080474(uint32 argument_0, uint32 argument_1);
uint32 sub_8008056C(uint32 argument_0);
void sub_80083868(uint32 argument_0);
uint32 sub_80083898(uint32 argument_0, uint32 argument_1);

uint32 sub_8003BE08(uint32 image, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x40u;
    uint32 result;
    uint32 x;
    uint32 y;
    uint32 width;
    uint32 height;
    FUNCTION_MARKER(0x8003BE08u, "1.EXE");
    w_u32(frame + 0x38u, context->return_address);
    sub_8003BD78(image + 4u, frame + 0x18u);
    x = r_u16(frame + 0x1Cu);
    y = r_u16(frame + 0x1Eu);
    width = r_u16(frame + 0x20u);
    height = r_u16(frame + 0x22u);
    w_u16(frame + 0x10u, x);
    w_u16(frame + 0x12u, y);
    w_u16(frame + 0x14u, width);
    w_u16(frame + 0x16u, height);
    DrawSync(0);
    sub_80080230(frame + 0x10u, r_u32(frame + 0x24u));
    result = (r_u32(frame + 0x18u) >> 3u) & 1u;
    if (result != 0u)
    {
        x = r_u16(frame + 0x28u);
        y = r_u16(frame + 0x2Au);
        width = r_u16(frame + 0x2Cu);
        height = r_u16(frame + 0x2Eu);
        w_u16(frame + 0x10u, x);
        w_u16(frame + 0x12u, y);
        w_u16(frame + 0x14u, width);
        w_u16(frame + 0x16u, height);
        DrawSync(0);
        result = sub_80080230(frame + 0x10u, r_u32(frame + 0x30u));
    }
    context->return_address = r_u32(frame + 0x38u);
    return result;
}

uint32 sub_8003BD78(uint32 source, uint32 destination)
{
    uint32 pixels = source + 4u;
    uint32 value;
    uint32 size;
    FUNCTION_MARKER(0x8003BD78u, "1.EXE");
    w_u32(destination, r_u32(source));
    if ((r_u32(source) & 8u) != 0u)
    {
        value = r_u16(source + 8u);
        size = r_u32(source + 4u);
        w_u16(destination + 0x10u, value);
        value = r_u16(source + 0xAu);
        pixels = source + size + 4u;
        w_u16(destination + 0x12u, value);
        value = r_u16(source + 0xCu);
        w_u16(destination + 0x14u, value);
        value = r_u16(source + 0xEu);
        w_u32(destination + 0x18u, source + 0x10u);
        w_u16(destination + 0x16u, value);
    }
    pixels += 4u;
    value = r_u16(pixels);
    w_u16(destination + 4u, value);
    value = r_u16(pixels + 2u);
    pixels += 4u;
    w_u16(destination + 6u, value);
    value = r_u16(pixels);
    w_u16(destination + 8u, value);
    value = r_u16(pixels + 2u);
    pixels += 4u;
    w_u32(destination + 0xCu, pixels);
    w_u16(destination + 0xAu, value);
    return value;
}

uint32 sub_8003B864(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 selected;
    uint32 previous;
    uint32 result;
    GameSceneCallContext child;
    GameGeometryCallContext geometry = *context;
    child.caller_s0 = context->caller_s0;
    FUNCTION_MARKER(0x8003B864u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x8003B874u;
    sub_80059E2C(&child);
    context->caller_s0 = child.caller_s0;
    sub_80069BC0(2u);
    previous = (uint32)(sint32)(sint16)r_u16(0x800A6DE0u);
    selected = r_u32(0x800A6E18u);
    w_u32(0x800A8690u, 1u);
    if (selected != previous)
    {
        geometry.stack_pointer = frame;
        geometry.return_address = 0x8003B8A0u;
        geometry.caller_s0 = context->caller_s0;
        result = sub_8003B574(previous, 1u, &geometry);
        context->caller_s0 = geometry.caller_s0;
        context->caller_s1 = geometry.caller_s1;
        context->caller_s2 = geometry.caller_s2;
        w_u16(0x800A6DE0u, result);
        geometry = *context;
geometry.stack_pointer = frame;
geometry.return_address = 0x8003B8ACu;
result = sub_8003C394(&geometry);
context->caller_s0 = geometry.caller_s0;
context->caller_s1 = geometry.caller_s1;
context->caller_s2 = geometry.caller_s2;
context->caller_s3 = geometry.caller_s3;
context->caller_s4 = geometry.caller_s4;
context->caller_s5 = geometry.caller_s5;
context->caller_s6 = geometry.caller_s6;
context->caller_s7 = geometry.caller_s7;
    }
    else
    {
        geometry = *context;
        geometry.stack_pointer = frame;
        geometry.return_address = 0x8003B8BCu;
        result = sub_8003BA80(selected, 1u, 0u, &geometry);
        context->caller_s0 = geometry.caller_s0;
        context->caller_s1 = geometry.caller_s1;
        context->caller_s2 = geometry.caller_s2;
        context->caller_s3 = geometry.caller_s3;
        context->caller_s4 = geometry.caller_s4;
        context->caller_s5 = geometry.caller_s5;
        context->caller_s6 = geometry.caller_s6;
        context->caller_s7 = geometry.caller_s7;
        w_u16(0x800A6DE0u, result);
        geometry = *context;
geometry.stack_pointer = frame;
geometry.return_address = 0x8003B8C8u;
sub_8003C394(&geometry);
context->caller_s0 = geometry.caller_s0;
context->caller_s1 = geometry.caller_s1;
context->caller_s2 = geometry.caller_s2;
context->caller_s3 = geometry.caller_s3;
context->caller_s4 = geometry.caller_s4;
context->caller_s5 = geometry.caller_s5;
context->caller_s6 = geometry.caller_s6;
context->caller_s7 = geometry.caller_s7;
        child.return_address = 0x8003B8D0u;
        child.caller_s0 = context->caller_s0;
        sub_80069B84(3u, &child);
        context->caller_s0 = child.caller_s0;
        geometry = *context;
        geometry.stack_pointer = frame;
        geometry.return_address = 0x8003B8D8u;
        result = sub_800649E4(&geometry);
        context->caller_s0 = geometry.caller_s0;
        context->caller_s1 = geometry.caller_s1;
        context->caller_s2 = geometry.caller_s2;
        context->caller_s3 = geometry.caller_s3;
        context->caller_s4 = geometry.caller_s4;
        context->caller_s5 = geometry.caller_s5;
        context->caller_s6 = geometry.caller_s6;
        context->caller_s7 = geometry.caller_s7;
    }
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8003B574(uint32 selected, uint32 mode, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 resource = context->caller_s2;
    uint32 counter = context->caller_s0;
    uint32 state;
    uint32 value;
    GameSceneCallContext child;
    GameGeometryCallContext geometry = *context;
    FUNCTION_MARKER(0x8003B574u, "1.EXE");
    (void)mode;
    w_u32(frame + 0x14u, context->caller_s1);
    state = r_u32(0x800A6E1Cu);
    w_u32(frame + 0x1Cu, context->return_address);
    w_u32(frame + 0x18u, context->caller_s2);
    w_u32(frame + 0x10u, context->caller_s0);
    child.stack_pointer = frame;
    geometry.stack_pointer = frame;
    geometry.caller_s1 = selected;
    if (state == 2u)
    {
        sub_80059860(7u);
        counter = 0u;
        geometry.return_address = 0x8003B5A8u;
        geometry.caller_s0 = counter;
        geometry.caller_s2 = resource;
        resource = sub_8003C3D4(&geometry);
        child.return_address = 0x8003B5B4u;
        child.caller_s0 = counter;
        sub_80021144(0u, &child);
        counter = child.caller_s0;
        geometry.return_address = 0x8003B5BCu;
        geometry.caller_s0 = counter;
        geometry.caller_s2 = resource;
        sub_8003BFAC(&geometry);
        counter = geometry.caller_s0;
        SetDispMask(1);
        do
        {
            geometry.return_address = 0x8003B5CCu;
            geometry.caller_s0 = counter;
            geometry.caller_s1 = selected;
            geometry.caller_s2 = resource;
            sub_8005A5F8(resource + 1u, &geometry);
            counter = geometry.caller_s0;
            resource = geometry.caller_s2;
            ++counter;
        } while ((sint32)counter < 2);
        geometry.return_address = 0x8003B5E4u;
        geometry.caller_s0 = counter;
        geometry.caller_s1 = selected;
        geometry.caller_s2 = resource;
        value = sub_80073B78(&geometry);
        counter = geometry.caller_s0;
        resource = geometry.caller_s2;
        if (value == 0xFFFFFFFFu)
        {
            sub_80032D80();
            if (r_u32(0x800A87E4u) != 0u) sub_80039198();
            else sub_80039224();
            w_u8(0x800A9872u, 0u);
            w_u8(0x800A9878u, 0u);
        }
        else
        {
            value = r_u8(0x800A9872u);
            state = r_u8(0x800A9878u);
            w_u16(0x800A906Au, value);
            w_u16(0x800A906Cu, state);
        }
        if ((r_u32(0x800A87E4u) & 8u) != 0u)
        {
            w_u8(0x800A9872u, 1u);
            w_u16(0x800A906Au, 1u);
            w_u8(0x800A9878u, 1u);
            w_u16(0x800A906Cu, 1u);
        }
        w_u32(0x800A9760u, 0u);
        geometry.stack_pointer = frame;
        geometry.return_address = 0x8003B69Cu;
        geometry.caller_s0 = counter;
        geometry.caller_s1 = selected;
        geometry.caller_s2 = resource;
        sub_8005A69C(resource, &geometry);
        counter = geometry.caller_s0;
        selected = geometry.caller_s1;
        resource = geometry.caller_s2;
        geometry.stack_pointer = frame;
        geometry.return_address = 0x8003B6A4u;
        geometry.caller_s0 = counter;
        geometry.caller_s1 = selected;
        geometry.caller_s2 = resource;
        sub_8003C4B8(&geometry);
        counter = geometry.caller_s0;
        selected = geometry.caller_s1;
        resource = geometry.caller_s2;
        geometry.stack_pointer = frame;
        geometry.return_address = 0x8003B6B0u;
        geometry.caller_s0 = counter;
        geometry.caller_s1 = selected;
        geometry.caller_s2 = resource;
        sub_8003D7F0(r_u32(0x800A8FD4u), &geometry);
        counter = geometry.caller_s0;
        selected = geometry.caller_s1;
        resource = geometry.caller_s2;
        child.caller_s0 = counter;
        child.return_address = 0x8003B6B8u;
        sub_80069B84(5u, &child);
        child.return_address = 0x8003B6C0u;
        sub_80069B84(7u, &child);
        sub_80069BC0(7u);
        child.return_address = 0x8003B6D0u;
        sub_80069B84(2u, &child);
        child.return_address = 0x8003B6D8u;
        sub_80069B84(1u, &child);
        counter = child.caller_s0;
    }
    child.return_address = 0x8003B6E0u;
    child.caller_s0 = counter;
    sub_80064334(1u, &child);
    counter = child.caller_s0;
    sub_80069BC0(1u);
    child.caller_s0 = counter;
    child.return_address = 0x8003B6F0u;
    value = sub_80069B38(1u, &child);
    w_u32(0x800A87E8u, value);
    child.return_address = 0x8003B6FCu;
    sub_80021144(selected, &child);
    child.return_address = 0x8003B704u;
    value = sub_80069B38(1u, &child);
    w_u32(0x800A87E8u, value - r_u32(0x800A87E8u));
    SetDispMask(1);
    state = r_u32(0x800A6E1Cu);
    if (state != 0u)
    {
        if (state == 1u) sub_80059860(4u);
        geometry.stack_pointer = frame;
        geometry.return_address = 0x8003B748u;
        geometry.caller_s0 = counter;
        geometry.caller_s1 = selected;
        geometry.caller_s2 = resource;
        sub_8003C5E4(&geometry);
        counter = geometry.caller_s0;
        selected = geometry.caller_s1;
        resource = geometry.caller_s2;
    }
    else sub_80059860(3u);
    {
    geometry.stack_pointer = frame;
    geometry.caller_s0 = counter;
    geometry.caller_s1 = selected;
    geometry.caller_s2 = resource;
    geometry.return_address = 0x8003B764u;
    sub_8003C6D8((uint32)(sint32)(sint16)selected, &geometry);
    counter = geometry.caller_s0;
    selected = geometry.caller_s1;
    resource = geometry.caller_s2;
}
    w_u32(0x800A6E18u, selected);
    w_u32(0x800A6E44u, selected);
    child.return_address = 0x8003B774u;
    sub_80069B84(2u, &child);
    if (r_u32(0x800A9760u) != 0u)
        {
    geometry.stack_pointer = frame;
    geometry.caller_s0 = counter;
    geometry.caller_s1 = selected;
    geometry.caller_s2 = resource;
    geometry.return_address = 0x8003B7DCu;
    value = sub_8003BA80(r_u32(0x800A9768u), 1u, 1u, &geometry);
    counter = geometry.caller_s0;
    selected = geometry.caller_s1;
    resource = geometry.caller_s2;
    selected = value;
}
    else
    {
        state = r_u32(0x800A8690u);
        if (state == 0u || state == 2u)
        {
            {
    geometry.stack_pointer = frame;
    geometry.caller_s0 = counter;
    geometry.caller_s1 = selected;
    geometry.caller_s2 = resource;
    geometry.return_address = 0x8003B7ACu;
    value = sub_8003BA80(r_u32(0x800A854Cu), 1u, 1u, &geometry);
    counter = geometry.caller_s0;
    selected = geometry.caller_s1;
    resource = geometry.caller_s2;
    selected = value;
}
            state = r_u32(0x800A8690u);
        }
        if (state == 1u) {
    geometry.stack_pointer = frame;
    geometry.caller_s0 = counter;
    geometry.caller_s1 = selected;
    geometry.caller_s2 = resource;
    geometry.return_address = 0x8003B7DCu;
    value = sub_8003BA80(selected, 1u, 1u, &geometry);
    counter = geometry.caller_s0;
    selected = geometry.caller_s1;
    resource = geometry.caller_s2;
    selected = value;
}
    }
    child.return_address = 0x8003B7E8u;
    sub_80069B84(3u, &child);
    {
    geometry.stack_pointer = frame;
    geometry.caller_s0 = counter;
    geometry.caller_s1 = selected;
    geometry.caller_s2 = resource;
    geometry.return_address = 0x8003B7F0u;
    sub_800649E4(&geometry);
    counter = geometry.caller_s0;
    selected = geometry.caller_s1;
    resource = geometry.caller_s2;
}
    sub_80021200(r_u32(0x800A62F4u));
    sub_8005AAE0();
    geometry.stack_pointer = frame;
geometry.caller_s0 = counter;
geometry.caller_s1 = selected;
geometry.caller_s2 = resource;
geometry.return_address = 0x8003B818u;
sub_800651AC(r_u32(0x800A62F8u), &geometry);
counter = geometry.caller_s0;
selected = geometry.caller_s1;
resource = geometry.caller_s2;
    sub_8005E818();
    if (r_u32(0x800A6E2Cu) == 0u)
    {
        geometry.stack_pointer = frame;
geometry.caller_s0 = counter;
geometry.caller_s1 = selected;
geometry.caller_s2 = resource;
geometry.return_address = 0x8003B838u;
sub_80059610(&geometry);
counter = geometry.caller_s0;
selected = geometry.caller_s1;
resource = geometry.caller_s2;
        w_u32(0x800A6E2Cu, 1u);
    }
    w_u32(0x800A6E1Cu, 0u);
    context->caller_s3 = geometry.caller_s3;
    context->caller_s4 = geometry.caller_s4;
    context->caller_s5 = geometry.caller_s5;
    context->caller_s6 = geometry.caller_s6;
    context->caller_s7 = geometry.caller_s7;
    context->return_address = r_u32(frame + 0x1Cu);
    context->caller_s2 = r_u32(frame + 0x18u);
    context->caller_s1 = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return selected;
}

uint32 sub_80059860(uint32 divisor)
{
    FUNCTION_MARKER(0x80059860u, "1.EXE");
    if ((sint32)divisor < 2)
    {
        w_u32(0x800A73FCu, 100u);
        w_u32(0x800A7400u, 1u);
    }
    else
    {
        uint32 quotient = (uint32)(100 / (sint32)divisor);
        w_u32(0x800A7400u, divisor);
        w_u32(0x800A73FCu, quotient + 1u);
    }
    w_u32(0x800A7404u, 1u);
    w_u32(0x800A7408u, 0u);
    return 1u;
}

uint32 sub_8003C3D4(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x38u;
    uint32 first;
    uint32 second;
    uint32 third;
    uint32 size;
    uint32 buffer;
    uint32 result;
    GameSceneCallContext allocation;
    GameGeometryCallContext load = *context;
    FUNCTION_MARKER(0x8003C3D4u, "1.EXE");
    w_u32(frame + 0x30u, context->return_address);
    w_u32(frame + 0x2Cu, context->caller_s1);
    w_u32(frame + 0x28u, context->caller_s0);
    first = r_u32(0x800A5DE0u);
    second = r_u32(0x800A5DE4u);
    third = r_u32(0x800A5DE8u);
    w_u32(frame + 0x10u, first);
    w_u32(frame + 0x14u, second);
    w_u32(frame + 0x18u, third);
    first = r_u32(0x800A5DECu);
    second = r_u32(0x800A5DF0u);
    third = r_u8(0x800A5DF4u);
    w_u32(frame + 0x1Cu, first);
    w_u32(frame + 0x20u, second);
    w_u8(frame + 0x24u, third);
    w_u8(frame + 0x15u, r_u8(0x800A8698u) + 48u);
    allocation.stack_pointer = frame;
    allocation.return_address = 0x8003C45Cu;
    allocation.caller_s0 = frame + 0x10u;
    size = sub_8005A4D8(frame + 0x10u, &allocation);
    allocation.return_address = 0x8003C468u;
    buffer = sub_80069AD4(size, &allocation);
    w_u32(0x800A7BF0u, buffer);
    load.stack_pointer = frame;
    load.return_address = 0x8003C47Cu;
    load.caller_s0 = allocation.caller_s0;
    load.caller_s1 = size;
    sub_8005A3E4(frame + 0x10u, buffer, &load);
    size = load.caller_s1;
    result = (uint32)((sint32)size / 16);
    if (size != (result << 4u)) ++result;
    context->caller_s2 = load.caller_s2;
    context->return_address = r_u32(frame + 0x30u);
    context->caller_s1 = r_u32(frame + 0x2Cu);
    context->caller_s0 = r_u32(frame + 0x28u);
    return result;
}

uint32 sub_80021144(uint32 selection, GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    GameSceneCallContext child = *context;
    FUNCTION_MARKER(0x80021144u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->return_address);
    if (selection >= 5u) selection = 5u;
    child.stack_pointer = frame;
    child.caller_s0 = selection;
    if (selection == 0u)
    {
        child.return_address = 0x80021174u;
        result = sub_80069B38(0x19000u, &child) + 0x19000u;
        w_u32(0x800A822Cu, result);
        w_u32(0x800A85E0u, result);
        child.return_address = 0x80021198u;
        result = sub_80069B38(0x19000u, &child) + 0x32000u;
    }
    else
    {
        child.return_address = 0x800211BCu;
        result = sub_80069AD4(r_u8(0x8008B78Cu + child.caller_s0) << 10u, &child);
        w_u32(0x800A822Cu, result);
        w_u32(0x800A85E0u, result);
        child.return_address = 0x800211DCu;
        result = sub_80069AD4(r_u8(0x8008B78Cu + child.caller_s0) << 10u, &child);
    }
    w_u32(0x800A8230u, result);
    w_u32(0x800A8658u, result);
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80020C60(uint32 index, uint32 table, uint32 color, uint32 mode,
    GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 slot = table + (index << 2u);
    uint32 packet;
    uint32 next;
    uint32 x;
    uint32 y;
    uint32 width;
    uint32 height;
    uint32 tag;
    uint32 value;
    uint32 mask;
    FUNCTION_MARKER(0x80020C60u, "1.EXE");
    w_u32(frame + 0x14u, context->caller_s1);
    x = (uint32)(sint32)(sint16)r_u32(frame + 0x30u);
    packet = r_u32(0x800A865Cu);
    w_u32(frame + 0x18u, context->return_address);
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(packet + 4u, color | 0x63000000u);
    y = r_u32(frame + 0x34u);
    next = packet + 16u;
    value = (y << 16u) + 0x007800A0u;
    width = (uint32)(sint32)(sint16)r_u32(frame + 0x38u);
    w_u32(packet + 8u, x + value);
    height = r_u32(frame + 0x3Cu);
    w_u32(packet + 12u, width + (height << 16u));
    tag = r_u32(slot);
    w_u32(packet, (tag & 0xFFFFFFu) | 0x03000000u);
    tag = r_u32(slot);
    w_u32(slot, (tag & 0xFF000000u) | (packet & 0xFFFFFFu));
    w_u8(packet + 19u, 1u);
    tag = r_u32(packet + 16u);
    value = r_u32(slot);
    w_u32(packet + 16u, (tag & 0xFF000000u) | (value & 0xFFFFFFu));
    tag = r_u32(slot);
    w_u32(slot, (tag & 0xFF000000u) | (next & 0xFFFFFFu));
    if (GetGraphType() == 1)
        mask = 0x27FFu;
    else if (GetGraphType() == 2)
        mask = 0x27FFu;
    else
        mask = 0x09FFu;
    w_u32(next + 4u, ((mode << 5u) & mask) | 0xE1000000u);
    value = next + 8u;
    w_u32(0x800A865Cu, value);
    context->return_address = r_u32(frame + 0x18u);
    context->caller_s1 = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return value;
}

uint32 sub_8003BFAC(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x30u;
    uint32 counter = 0u;
    uint32 result;
    GameSceneCallContext scene;
    GameGeometryCallContext child = *context;
    GameRenderCallContext render;
    FUNCTION_MARKER(0x8003BFACu, "1.EXE");
    w_u32(frame + 0x2Cu, context->return_address);
    w_u32(frame + 0x28u, context->caller_s2);
    w_u32(frame + 0x24u, context->caller_s1);
    w_u32(frame + 0x20u, context->caller_s0);
    scene.stack_pointer = frame;
    scene.return_address = 0x8003BFC8u;
    scene.caller_s0 = context->caller_s0;
    sub_80064334(1u, &scene);
    child.stack_pointer = frame;
    child.caller_s1 = 0xFFFFFF88u;
    child.caller_s2 = 0xFFFFFF60u;
    do
    {
        ++counter;
        w_u32(frame + 0x18u, 320u);
        result = r_u32(0x800A9A74u);
        w_u32(frame + 0x10u, child.caller_s2);
        w_u32(frame + 0x14u, child.caller_s1);
        w_u32(frame + 0x1Cu, 256u);
        child.return_address = 0x8003C010u;
        child.caller_s0 = counter;
        sub_80020C60(0u, result + 600u, 0xFFFFFFu, 2u, &child);
        render.stack_pointer = frame;
        render.return_address = 0x8003C018u;
        render.caller_s0 = child.caller_s0;
        render.caller_s1 = child.caller_s1;
        render.caller_s2 = child.caller_s2;
        render.caller_s3 = context->caller_s3;
        render.caller_s4 = context->caller_s4;
        render.caller_s5 = context->caller_s5;
        render.caller_s6 = context->caller_s6;
        render.caller_s7 = context->caller_s7;
        sub_800643EC(&render);
        child.caller_s0 = render.caller_s0;
        child.caller_s1 = render.caller_s1;
        child.caller_s2 = render.caller_s2;
        child.return_address = 0x8003C020u;
        sub_8001F850();
        child.return_address = 0x8003C028u;
        sub_8001FF7C(0u, &child);
        counter = child.caller_s0;
    } while ((sint32)counter < 2);
    scene.return_address = 0x8003C03Cu;
    scene.caller_s0 = counter;
    result = sub_80064334(0u, &scene);
    context->return_address = r_u32(frame + 0x2Cu);
    context->caller_s2 = r_u32(frame + 0x28u);
    context->caller_s1 = r_u32(frame + 0x24u);
    context->caller_s0 = r_u32(frame + 0x20u);
    return result;
}

uint32 sub_8006499C(GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 state = r_u32(0x800A9A38u);
    uint32 result = 4u;
    FUNCTION_MARKER(0x8006499Cu, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    if (state == 4u)
        result = sub_800648A4(0x800A8F18u);
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80064594(uint32 target, uint32 baseline, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 state;
    uint32 result = 2u;
    uint32 value;
    uint32 component;
    sint32 distance;
    sint32 amount;
    FUNCTION_MARKER(0x80064594u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->caller_s1);
    w_u32(frame + 0x18u, context->return_address);
    state = r_u8(target + 0xA0u);
    if (state == 1u)
    {
        sub_80064784(target + 0x88u, target + 0x94u);
        distance = (sint16)r_u16(target + 0x98u);
        if (distance >= 13001) distance = 13000;
        w_u32(target, (uint32)distance);
        w_u16(target + 0x98u, distance);
        amount = (sint8)r_u8(target + 0x9Fu);
        distance = (sint16)distance - amount * 200;
        if (distance < 0) distance = 0;
        amount = r_u8(target + 0x9Fu);
        w_u32(target + 4u, distance);
        component = r_u8(baseline + 0x10u);
        value = component + ((uint32)amount << 2u);
        amount = r_u8(target + 0x9Fu);
        w_u8(target + 0x10u, value);
        component = r_u8(baseline + 0x11u);
        w_u8(target + 0x11u, component + ((uint32)amount << 2u));
        amount = r_u8(target + 0x9Fu);
        component = r_u8(baseline + 0x12u);
        w_u8(target + 0xA0u, 2u);
        w_u8(target + 0x12u, component + ((uint32)amount << 2u));
    }
    else if (state == 2u)
    {
        amount = (sint16)r_u16(0x800A63DAu);
        value = r_u8(target + 0x9Fu) - (uint32)amount;
        w_u8(target + 0x9Fu, value);
        result = value << 24u;
        if ((sint32)result <= 0)
        {
            value = r_u8(target + 0x9Cu);
            w_u8(target + 0xA0u, 0u);
            w_u8(target + 0x9Fu, 0u);
            w_u8(target + 0x9Cu, value & 0xFDu);
            w_u8(target + 0x10u, r_u8(baseline + 0x10u));
            w_u8(target + 0x11u, r_u8(baseline + 0x11u));
            w_u8(target + 0x12u, r_u8(baseline + 0x12u));
            w_u32(target, r_u32(baseline));
            result = r_u32(baseline + 4u);
            w_u32(target + 4u, result);
        }
        else
        {
            value = r_u32(0x800A63D8u);
            component = r_u8(target + 0x10u);
            amount = (sint8)r_u8(target + 0x9Fu);
            w_u8(target + 0x10u, component - (uint32)((sint32)(value << 2u) >> 16));
            value = r_u32(0x800A63D8u);
            component = r_u8(target + 0x11u);
            w_u8(target + 0x11u, component - (uint32)((sint32)(value << 2u) >> 16));
            distance = (sint16)r_u16(target + 0x98u);
            value = r_u32(0x800A63D8u);
            distance -= amount * 200;
            component = r_u8(target + 0x12u);
            result = component - (uint32)((sint32)(value << 2u) >> 16);
            w_u8(target + 0x12u, result);
            if (distance < 0) distance = 0;
            w_u32(target + 4u, distance);
        }
    }
    context->return_address = r_u32(frame + 0x18u);
    context->caller_s1 = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80054D38(uint32 x, uint32 y, uint32 z, uint32 output,
    GameSceneCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 yp = (y + x) & 0xFFFu;
    uint32 ym = (y - x) & 0xFFFu;
    uint32 zp = (z + x) & 0xFFFu;
    uint32 zm = (z - x) & 0xFFFu;
    uint32 neg = 0u - z - y;
    uint32 diff = y - z;
    uint32 np = (neg + x) & 0xFFFu;
    uint32 nm = (neg - x) & 0xFFFu;
    uint32 dp = (diff + x) & 0xFFFu;
    uint32 dm = (diff - x) & 0xFFFu;
    sint32 a;
    sint32 b;
    sint32 c;
    sint32 p;
    sint32 q;
    sint32 r;
    sint32 s;
    uint32 result;
    FUNCTION_MARKER(0x80054D38u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    a = (sint16)r_u16(0x800102E0u + (yp << 1u));
    b = (sint16)r_u16(0x800102E0u + (ym << 1u));
    w_u16(output + 4u, (a + b) >> 1);
    b = (sint16)r_u16(0x80010AE0u + (ym << 1u));
    a = (sint16)r_u16(0x80010AE0u + (yp << 1u));
    w_u16(output + 16u, (a + b) >> 1);
    a = (sint16)r_u16(0x800102E0u + (zp << 1u));
    b = (sint16)r_u16(0x800102E0u + (zm << 1u));
    w_u16(output + 6u, (a + b) >> 1);
    b = (sint16)r_u16(0x80010AE0u + (zp << 1u));
    a = (sint16)r_u16(0x80010AE0u + (zm << 1u));
    w_u16(output + 8u, (a + b) >> 1);
    a = (sint16)r_u16(0x800102E0u + (nm << 1u));
    c = (sint16)r_u16(0x80010AE0u + ((neg & 0xFFFu) << 1u));
    b = (sint16)r_u16(0x800102E0u + (np << 1u));
    p = ((a - b) >> 2) + (c >> 1);
    a = (sint16)r_u16(0x80010AE0u + (np << 1u));
    c = (sint16)r_u16(0x800102E0u + ((neg & 0xFFFu) << 1u));
    b = (sint16)r_u16(0x80010AE0u + (nm << 1u));
    q = ((a - b) >> 2) + (c >> 1);
    a = (sint16)r_u16(0x800102E0u + (((0u - x) & 0xFFFu) << 1u));
    w_u16(output + 10u, a);
    a = (sint16)r_u16(0x800102E0u + (dp << 1u));
    c = (sint16)r_u16(0x80010AE0u + ((diff & 0xFFFu) << 1u));
    b = (sint16)r_u16(0x800102E0u + (dm << 1u));
    r = ((a - b) >> 2) + (c >> 1);
    b = (sint16)r_u16(0x80010AE0u + (dp << 1u));
    c = (sint16)r_u16(0x800102E0u + ((diff & 0xFFFu) << 1u));
    a = (sint16)r_u16(0x80010AE0u + (dm << 1u));
    s = ((a - b) >> 2) + (c >> 1);
    w_u16(output + 12u, q - s);
    w_u16(output + 14u, r - p);
    w_u16(output, p + r);
    result = (uint32)(q + s);
    w_u16(output + 2u, result);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

void sub_8001F850(void)
{
    FUNCTION_MARKER(0x8001F850u, "1.EXE");
    w_u32(0x800A636Cu, 0u);
    w_u32(0x800A6394u, 0u);
}

uint32 sub_8001FF7C(uint32 mode, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x30u;
    uint32 result;
    uint32 page;
    uint32 previous;
    uint32 ordering;
    uint32 primitives;
    uint32 color;
    sint32 selected = (sint16)mode;
    FUNCTION_MARKER(0x8001FF7Cu, "1.EXE");
    w_u32(frame + 0x20u, context->caller_s0);
    w_u32(frame + 0x2Cu, context->return_address);
    w_u32(frame + 0x28u, context->caller_s2);
    w_u32(frame + 0x24u, context->caller_s1);
    w_u32(0x800A5634u, 0u);
    {
        GameMainCallContext input = {0};
        input.stack_pointer = frame;
        input.return_address = 0x8001FF9Cu;
        input.caller_s0 = mode;
        input.caller_s1 = context->caller_s1;
        input.caller_s2 = context->caller_s2;
        input.caller_s3 = context->caller_s3;
        input.caller_s4 = context->caller_s4;
        input.caller_s5 = context->caller_s5;
        input.caller_s6 = context->caller_s6;
        input.caller_s7 = context->caller_s7;
        input.caller_a0 = mode;
        sub_800389A8(&input);
        context->caller_s3 = input.caller_s3;
        context->caller_s4 = input.caller_s4;
        context->caller_s5 = input.caller_s5;
        context->caller_s6 = input.caller_s6;
        context->caller_s7 = input.caller_s7;
    }
    if (selected == 2)
    {
        ordering = r_u32(0x800A9A74u);
        w_u32(frame + 0x10u, 0xFFFFFF88u);
        w_u32(frame + 0x14u, 320u);
        w_u32(frame + 0x18u, 240u);
        page = r_u32(0x800A562Cu);
        w_u32(0x800A84A8u, page);
        sub_80020D98(1998u, ordering, 0u, 0xFFFFFF60u, frame);
        sub_800202B0(r_u32(0x800A562Cu));
        DrawSync(0);
        sub_80021368();
        w_u32(0x800A5634u, 1u);
        VSync(0);
        page = r_u32(0x800A562Cu);
        previous = r_u32(0x800A85DCu + (1u - page) * 120u);
        ordering = r_u32(0x800A85DCu + page * 120u);
        primitives = r_u32(0x800A85E0u + page * 120u);
        w_u32(0x800A9A74u, ordering);
        w_u32(0x800A865Cu, primitives);
        sub_80080474(ordering, 2048u);
        sub_8008056C(previous + 8188u);
    }
    result = mode << 16u;
    if (selected == 1)
    {
        ordering = r_u32(0x800A9A74u);
        color = r_u32(0x800A8F2Cu);
        w_u32(frame + 0x10u, 0xFFFFFF88u);
        w_u32(frame + 0x14u, 320u);
        w_u32(frame + 0x18u, 240u);
        page = r_u32(0x800A562Cu);
        w_u32(0x800A84A8u, page);
        sub_80020D98(1998u, ordering, color & 0xFFFFFFu, 0xFFFFFF60u, frame);
        sub_800202B0(r_u32(0x800A562Cu));
        sub_800650CC();
        sub_80021368();
        sub_80059400();
        sub_8005EB2C();
        w_u32(0x800A5634u, 1u);
        sub_80065124();
        page = r_u32(0x800A562Cu);
        previous = r_u32(0x800A85DCu + (1u - page) * 120u);
        ordering = r_u32(0x800A85DCu + page * 120u);
        primitives = r_u32(0x800A85E0u + page * 120u);
        w_u32(0x800A9A74u, ordering);
        w_u32(0x800A865Cu, primitives);
        sub_80080474(ordering, 2048u);
        sub_8008056C(previous + 8188u);
        if (r_u16(0x800A9A64u) != 0u) sub_80037864();
        else sub_800376D0();
        result = mode << 16u;
    }
    if (result == 0u)
    {
        ordering = r_u32(0x800A9A74u);
        w_u32(frame + 0x10u, 0xFFFFFF88u);
        w_u32(frame + 0x14u, 320u);
        w_u32(frame + 0x18u, 240u);
        page = r_u32(0x800A562Cu);
        w_u32(0x800A84A8u, page);
        sub_80020D98(1998u, ordering, 0u, 0xFFFFFF60u, frame);
        DrawSync(0);
        sub_800202B0(r_u32(0x800A562Cu));
        VSync(0);
        page = 1u - r_u32(0x800A562Cu);
        w_u32(0x800A562Cu, page);
        PutDrawEnv((DRAWENV *)psx_addr(0x800A856Cu + page * 120u, sizeof(DRAWENV)));
        page = r_u32(0x800A562Cu);
        PutDispEnv((DISPENV *)psx_addr(0x800A85C8u + page * 120u, sizeof(DISPENV)));
        page = r_u32(0x800A562Cu);
        previous = r_u32(0x800A85DCu + (1u - page) * 120u);
        ordering = r_u32(0x800A85DCu + page * 120u);
        primitives = r_u32(0x800A85E0u + page * 120u);
        w_u32(0x800A9A74u, ordering);
        w_u32(0x800A865Cu, primitives);
        sub_80080474(ordering, 2048u);
        result = sub_8008056C(previous + 8188u);
    }
    context->return_address = r_u32(frame + 0x2Cu);
    context->caller_s2 = r_u32(frame + 0x28u);
    context->caller_s1 = r_u32(frame + 0x24u);
    context->caller_s0 = r_u32(frame + 0x20u);
    return result;
}

void sub_800643EC(GameRenderCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x78u;
    uint32 source = 0x800A8F30u;
    uint32 destination = 0x800A8F1Eu;
    uint32 matrix_offset = 72u;
    uint32 vector_offset = 60u;
    uint32 light_offset = 12u;
    uint32 count = 3u;
    uint32 red;
    uint32 green;
    uint32 blue;
    uint32 distance;
    GameSceneCallContext scene;
    GameGeometryCallContext geometry;
    FUNCTION_MARKER(0x800643ECu, "1.EXE");
    w_u32(frame + 0x70u, context->return_address);
    w_u32(frame + 0x6Cu, context->caller_s7);
    w_u32(frame + 0x68u, context->caller_s6);
    w_u32(frame + 0x64u, context->caller_s5);
    w_u32(frame + 0x60u, context->caller_s4);
    w_u32(frame + 0x5Cu, context->caller_s3);
    w_u32(frame + 0x58u, context->caller_s2);
    w_u32(frame + 0x54u, context->caller_s1);
    w_u32(frame + 0x50u, context->caller_s0);
    scene.stack_pointer = frame;
    scene.return_address = 0x80064418u;
    scene.caller_s0 = context->caller_s0;
    sub_8006499C(&scene);
    geometry.stack_pointer = frame;
    geometry.return_address = 0x8006442Cu;
    geometry.caller_s0 = scene.caller_s0;
    geometry.caller_s1 = context->caller_s1;
    geometry.caller_s2 = context->caller_s2;
    geometry.caller_s3 = context->caller_s3;
    geometry.caller_s4 = context->caller_s4;
    geometry.caller_s5 = context->caller_s5;
    geometry.caller_s6 = context->caller_s6;
    geometry.caller_s7 = context->caller_s7;
    sub_80064594(0x800A8F18u, 0x800A8E74u, &geometry);
    red = r_u8(0x800A8F24u);
    green = r_u8(0x800A8F25u);
    blue = r_u8(0x800A8F26u);
    SetBackColor(red, green, blue);
    red = r_u8(0x800A8F28u);
    green = r_u8(0x800A8F29u);
    blue = r_u8(0x800A8F2Au);
    SetFarColor(red, green, blue);
    distance = r_u32(0x800A8F18u);
    red = r_u8(0x800A8F2Cu);
    green = r_u8(0x800A8F2Du);
    blue = r_u8(0x800A8F2Eu);
    w_u8(0x800A8585u, red);
    w_u8(0x800A85FDu, red);
    w_u8(0x800A8586u, green);
    w_u8(0x800A85FEu, green);
    w_u8(0x800A8587u, blue);
    w_u8(0x800A85FFu, blue);
    SetFogNear((sint32)distance, 125);
    sub_80083898(r_u32(0x800A8F1Cu), 125u);
    do
    {
        uint32 vector;
        uint32 x;
        uint32 y;
        uint32 z;
        matrix_offset -= 8u;
        source -= 8u;
        destination -= 2u;
        vector_offset -= 20u;
        --count;
        w_u16(destination + 96u, r_u16(source + 24u));
        w_u16(destination + 102u, r_u16(source + 26u));
        w_u16(destination + 108u, r_u16(source + 28u));
        vector = frame + 0x10u + vector_offset;
        x = (uint32)(sint32)(sint16)r_u16(source + 72u);
        y = (uint32)(sint32)(sint16)r_u16(source + 74u);
        z = (uint32)(sint32)(sint16)r_u16(source + 76u);
        scene.return_address = 0x80064538u;
        scene.caller_s0 = vector;
        sub_80054D38(x, y, z, vector, &scene);
        sub_80031C1C(vector, 0x800A8F18u + matrix_offset, 0x800A84B4u + light_offset);
        light_offset -= 6u;
    } while (count != 0u);
    sub_80083868(0x800A8F78u);
    context->return_address = r_u32(frame + 0x70u);
    context->caller_s7 = r_u32(frame + 0x6Cu);
    context->caller_s6 = r_u32(frame + 0x68u);
    context->caller_s5 = r_u32(frame + 0x64u);
    context->caller_s4 = r_u32(frame + 0x60u);
    context->caller_s3 = r_u32(frame + 0x5Cu);
    context->caller_s2 = r_u32(frame + 0x58u);
    context->caller_s1 = r_u32(frame + 0x54u);
    context->caller_s0 = r_u32(frame + 0x50u);
}

void sub_80031C1C(uint32 matrix, uint32 vector, uint32 destination)
{
    uint32 registers[5];
    uint32 xy;
    uint32 z;
    sint32 result[3];
    FUNCTION_MARKER(0x80031C1Cu, "1.EXE");
    registers[0] = r_u32(matrix);
    registers[1] = r_u32(matrix + 4u);
    registers[2] = r_u32(matrix + 8u);
    registers[3] = r_u32(matrix + 12u);
    registers[4] = r_u32(matrix + 16u);
    xy = r_u32(vector);
    z = r_u32(vector + 4u);
    gte_rotate_packed(registers, xy, z, result);
    w_u16(destination, result[0]);
    w_u16(destination + 2u, result[1]);
    w_u16(destination + 4u, result[2]);
}

#include <string.h>
#include "game_scene.h"



sint32 sub_800389A8(GameMainCallContext *context);
uint32 sub_80020D98(uint32 index, uint32 table, uint32 color, uint32 x, uint32 entry_sp);
uint32 sub_800202B0(uint32 page);
void sub_8005A5F8(uint32 value, GameGeometryCallContext *context);
void sub_80059E20(void);
uint32 sub_800598CC(uint32 resource, GameGeometryCallContext *context);
uint32 sub_80041C9C(uint32 destination, uint32 flags, uint32 width, uint32 height,
    GameGeometryCallContext *context);
void sub_80041DB4(uint32 destination, uint32 x, uint32 y, uint32 rotation);
uint32 sub_80041D90(uint32 destination, uint32 color);
uint32 sub_80020AB4(uint32 source, uint32 table, uint32 count);
uint32 sub_800439A4(uint32 color, uint32 number, uint32 subtract, uint32 x, GameGeometryCallContext *context);
uint32 sub_8004328C(uint32 table, uint32 flags, uint32 index, uint32 color, GameGeometryCallContext *context);
uint32 sub_80076ED4(GameGeometryCallContext *context);
uint32 sub_80073B78(GameGeometryCallContext *context);
uint32 sub_80073C48(uint32 filename, GameGeometryCallContext *context);
uint32 sub_80032D80(void);

void sub_8001F850(void);
uint32 sub_8001FF7C(uint32 mode, GameGeometryCallContext *context);
sint32 sub_800380C8(GameMainCallContext *context);
uint32 sub_800732F8(uint32 data, GameGeometryCallContext *context);
uint32 sub_80073574(GameGeometryCallContext *context);
uint32 sub_8007361C(uint32 value, GameGeometryCallContext *context);

sint32 sub_800389A8(GameMainCallContext *context)
{
    uint32 previous = r_u32(0x800A6D64u);
    uint32 frame = context->stack_pointer - 0x18u;
    sint32 result;
    GameMainCallContext child = *context;
    FUNCTION_MARKER(0x800389A8u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    w_u32(0x800A6D60u, previous);
    child.stack_pointer = frame;
    child.return_address = 0x800389C0u;
    result = (sint16)sub_800380C8(&child);
    w_u32(0x800A6D64u, (uint32)result);
    context->caller_s0 = child.caller_s0;
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80020D98(uint32 index, uint32 table, uint32 color, uint32 x, uint32 entry_sp)
{
    uint32 packet;
    uint32 slot;
    uint32 value;
    uint32 width;
    uint32 height;
    FUNCTION_MARKER(0x80020D98u, "1.EXE");
    x = (uint32)(sint32)(sint16)x;
    packet = r_u32(0x800A865Cu);
    w_u32(packet + 4u, color | 0x60000000u);
    value = r_u32(entry_sp + 0x10u);
    slot = table + (index << 2u);
    value = (value << 16u) + 0x007800A0u;
    width = r_u32(entry_sp + 0x14u);
    w_u32(packet + 8u, x + value);
    height = r_u32(entry_sp + 0x18u);
    width = (uint32)(sint32)(sint16)width;
    w_u32(packet + 12u, width + (height << 16u));
    value = r_u32(slot);
    w_u32(packet, (value & 0xFFFFFFu) | 0x03000000u);
    w_u32(0x800A865Cu, packet + 16u);
    value = (r_u32(slot) & 0xFF000000u) | (packet & 0xFFFFFFu);
    w_u32(slot, value);
    return value;
}

uint32 sub_800202B0(uint32 page)
{
    uint32 offset = page * 120u;
    uint32 end;
    uint32 first;
    uint32 maximum;
    uint32 second;
    uint32 result;
    FUNCTION_MARKER(0x800202B0u, "1.EXE");
    end = r_u32(0x800A865Cu);
    first = r_u32(0x800A85E0u + offset);
    maximum = r_u32(0x800A5630u);
    second = r_u32(0x800A85E0u + offset);
    w_u32(0x800A853Cu, end - first);
    result = end - second;
    if (maximum + second < end)
        w_u32(0x800A5630u, result);
    return result;
}

void sub_8005A5F8(uint32 value, GameGeometryCallContext *context)
{
    uint32 pending = r_u32(0x800A7408u);
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 adjusted = value + 99u;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005A5F8u, "1.EXE");
    w_u32(frame + 0x1Cu, context->caller_s1);
    w_u32(frame + 0x20u, context->return_address);
    w_u32(frame + 0x18u, context->caller_s0);
    if (pending == 0u) sub_80059E20();
    child.stack_pointer = frame;
    child.caller_s0 = 0x80090DFCu;
    child.caller_s1 = adjusted;
    child.return_address = 0x8005A62Cu;
    sub_800598CC(0x80090DFCu, &child);
    child.return_address = 0x8005A634u;
    sub_800598CC(child.caller_s0 + 20u, &child);
    w_u32(frame + 0x10u, 2u);
    w_u32(frame + 0x14u, 150u);
    child.return_address = 0x8005A65Cu;
    sub_800439A4(0x808080u, child.caller_s1, 0u, 0xFFFFFFC3u, &child);
    child.return_address = 0x8005A67Cu;
    sub_8001FF7C(r_u32(0x800A9D60u) == 1u ? 2u : 0u, &child);
    sub_8001F850();
    context->caller_s2 = child.caller_s2;
    context->return_address = r_u32(frame + 0x20u);
    context->caller_s1 = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
}

void sub_80059E20(void)
{
    FUNCTION_MARKER(0x80059E20u, "1.EXE");
    w_u32(0x800A7410u, 0u);
}

uint32 sub_800598CC(uint32 resource, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x30u;
    uint32 first;
    uint32 second;
    uint32 parameter;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x800598CCu, "1.EXE");
    w_u32(frame + 0x28u, context->caller_s0);
    w_u32(frame + 0x2Cu, context->return_address);
    parameter = r_u8(resource + 6u);
    first = r_u8(resource + 4u);
    second = r_u8(resource + 5u);
    w_u32(frame + 0x10u, parameter);
    w_u32(frame + 0x14u, r_u8(resource + 7u));
    w_u32(frame + 0x18u, r_u8(resource + 15u));
    w_u32(frame + 0x1Cu, (uint32)(sint32)(sint16)r_u16(resource + 8u));
    w_u32(frame + 0x20u, (uint32)(sint32)(sint16)r_u16(resource + 10u));
    parameter = r_u32(resource);
    child.stack_pointer = frame;
    child.return_address = 0x80059930u;
    child.caller_s0 = resource;
    sub_80041C9C(0x800A7414u, parameter, first, second, &child);
    resource = child.caller_s0;
    first = (uint32)(sint32)(sint16)r_u16(resource + 12u);
    second = (uint32)(sint32)(sint8)r_u8(resource + 14u);
    sub_80041DB4(0x800A7414u, first, second, 0u);
    sub_80041D90(0x800A7414u, r_u32(resource + 16u));
    child.return_address = 0x8005997Cu;
    result = sub_80020AB4(0x800A7414u, r_u32(0x800A9A74u) + 720u, 1u);
    context->caller_s1 = child.caller_s1;
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x2Cu);
    context->caller_s0 = r_u32(frame + 0x28u);
    return result;
}

uint32 sub_80041C9C(uint32 destination, uint32 flags, uint32 width, uint32 height,
    GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x38u;
    uint32 mode;
    uint32 u;
    uint32 v;
    uint32 format;
    sint32 clut_x;
    sint32 clut_y;
    uint32 clut;
    FUNCTION_MARKER(0x80041C9Cu, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    mode = r_u32(frame + 0x48u);
    w_u32(frame + 0x20u, context->caller_s4);
    w_u32(frame + 0x1Cu, context->caller_s3);
    u = r_u16(frame + 0x4Cu);
    clut_x = (sint16)r_u16(frame + 0x54u);
    w_u32(frame + 0x24u, context->caller_s5);
    mode |= (flags >> 17u) & 0x1C0u;
    w_u32(frame + 0x14u, context->caller_s1);
    w_u32(frame + 0x18u, context->caller_s2);
    v = r_u16(frame + 0x50u);
    w_u32(frame + 0x28u, context->caller_s6);
    w_u32(frame + 0x2Cu, context->caller_s7);
    w_u32(frame + 0x30u, context->return_address);
    format = (uint32)((sint32)(flags & 0x30000000u) >> 23);
    clut_y = (sint16)r_u16(frame + 0x58u);
    mode |= format;
    clut = GetClut(clut_x, clut_y);
    w_u16(destination + 16u, width);
    w_u16(destination + 18u, height);
    w_u16(destination + 8u, mode);
    w_u8(destination + 6u, u);
    w_u8(destination + 7u, v);
    w_u16(destination + 4u, clut);
    w_u32(destination, (format & 0x30000000u) != 0u ? 0x2C808080u : 0x2E808080u);
    w_u16(destination + 20u, (sint16)width >> 1);
    w_u16(destination + 22u, (sint16)height >> 1);
    w_u16(destination + 24u, 4096u);
    w_u16(destination + 26u, 4096u);
    w_u32(destination + 28u, 0u);
    w_u16(destination + 10u, 0u);
    context->return_address = r_u32(frame + 0x30u);
    context->caller_s7 = r_u32(frame + 0x2Cu);
    context->caller_s6 = r_u32(frame + 0x28u);
    context->caller_s5 = r_u32(frame + 0x24u);
    context->caller_s4 = r_u32(frame + 0x20u);
    context->caller_s3 = r_u32(frame + 0x1Cu);
    context->caller_s2 = r_u32(frame + 0x18u);
    context->caller_s1 = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return 4096u;
}

void sub_80041DB4(uint32 destination, uint32 x, uint32 y, uint32 rotation)
{
    FUNCTION_MARKER(0x80041DB4u, "1.EXE");
    w_u16(destination + 12u, x);
    w_u16(destination + 14u, y);
    w_u32(destination + 28u, rotation);
}

uint32 sub_80041D90(uint32 destination, uint32 color)
{
    uint32 result;
    FUNCTION_MARKER(0x80041D90u, "1.EXE");
    result = (r_u32(destination) & 0xFF000000u) | (color & 0xFFFFFFu);
    w_u32(destination, result);
    return result;
}

uint32 sub_80020AB4(uint32 source, uint32 table, uint32 count)
{
    uint32 packet = r_u32(0x800A865Cu);
    uint32 value;
    uint32 other;
    uint32 slot;
    FUNCTION_MARKER(0x80020AB4u, "1.EXE");
    while ((count & 0xFFFFu) != 0u)
    {
        w_u16(packet + 8u, r_u16(source + 12u) + 160u);
        w_u16(packet + 10u, r_u16(source + 14u) + 120u);
        value = r_u16(source + 16u);
        other = r_u16(source + 12u);
        w_u16(packet + 16u, other + value + 160u);
        w_u16(packet + 18u, r_u16(source + 14u) + 120u);
        w_u16(packet + 24u, r_u16(source + 12u) + 160u);
        value = r_u16(source + 18u);
        other = r_u16(source + 14u);
        w_u16(packet + 26u, other + value + 120u);
        value = r_u16(source + 16u);
        other = r_u16(source + 12u);
        w_u16(packet + 32u, other + value + 160u);
        value = r_u16(source + 18u);
        other = r_u16(source + 14u);
        w_u16(packet + 34u, other + value + 120u);
        w_u8(packet + 12u, r_u8(source + 6u));
        w_u8(packet + 13u, r_u8(source + 7u));
        value = r_u8(source + 6u);
        other = r_u8(source + 16u);
        w_u8(packet + 20u, value + other);
        w_u8(packet + 21u, r_u8(source + 7u));
        w_u8(packet + 28u, r_u8(source + 6u));
        value = r_u8(source + 7u);
        other = r_u8(source + 18u);
        w_u8(packet + 29u, value + other);
        value = r_u8(source + 6u);
        other = r_u8(source + 16u);
        w_u8(packet + 36u, value + other);
        value = r_u8(source + 7u);
        other = r_u8(source + 18u);
        --count;
        w_u8(packet + 37u, value + other);
        w_u32(packet + 4u, r_u32(source));
        w_u16(packet + 14u, r_u16(source + 4u));
        w_u16(packet + 22u, r_u16(source + 8u));
        slot = table + ((uint32)r_u16(source + 10u) << 2u);
        source += 32u;
        value = r_u32(slot);
        w_u32(packet, (value & 0xFFFFFFu) | 0x09000000u);
        value = r_u32(slot);
        w_u32(slot, (value & 0xFF000000u) | (packet & 0xFFFFFFu));
        packet += 40u;
    }
    w_u32(0x800A865Cu, packet);
    return count & 0xFFFFu;
}

uint32 sub_800439A4(uint32 color, uint32 number, uint32 subtract, uint32 x, GameGeometryCallContext *context)
{
    uint32 remainder = number - subtract;
    sint32 leading = (sint32)remainder / 10000;
    sint32 thousands;
    sint32 hundreds;
    sint32 tens;
    uint32 frame = context->stack_pointer - 0x50u;
    uint32 digit;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x800439A4u, "1.EXE");
    remainder -= (uint32)leading * 10000u;
    thousands = (sint32)remainder / 1000;
    w_u32(frame + 0x48u, context->caller_s4);
    w_u32(frame + 0x38u, context->caller_s0);
    remainder -= (uint32)thousands * 1000u;
    hundreds = (sint32)remainder / 100;
    child.stack_pointer = frame;
    child.caller_s4 = color;
    child.caller_s0 = x;
    w_u32(frame + 0x44u, context->caller_s3);
    child.caller_s3 = 0x80090994u;
    w_u32(frame + 0x3Cu, context->caller_s1);
    child.caller_s1 = r_u32(frame + 0x60u);
    w_u32(frame + 0x40u, context->caller_s2);
    child.caller_s2 = r_u32(frame + 0x64u);
    remainder -= (uint32)hundreds * 100u;
    tens = (sint32)remainder / 10;
    w_u32(frame + 0x24u, (uint32)thousands);
    digit = (r_u8(frame + 0x24u) + 1u) & 0xFFu;
    w_u32(frame + 0x4Cu, context->return_address);
    w_u32(frame + 0x20u, (uint32)leading);
    w_u32(frame + 0x28u, (uint32)hundreds);
    remainder -= (uint32)tens * 10u;
    w_u32(frame + 0x2Cu, (uint32)tens);
    w_u32(frame + 0x30u, remainder);
    w_u32(frame + 0x10u, child.caller_s0);
    w_u32(frame + 0x14u, child.caller_s1);
    w_u32(frame + 0x18u, child.caller_s2);
    child.return_address = 0x80043AECu;
    sub_8004328C(child.caller_s3, 0x54000040u, digit, child.caller_s4, &child);
    child.caller_s0 += 12u;
    digit = (r_u8(frame + 0x28u) + 1u) & 0xFFu;
    w_u32(frame + 0x10u, child.caller_s0);
    child.caller_s0 += 16u;
    w_u32(frame + 0x14u, child.caller_s1);
    w_u32(frame + 0x18u, child.caller_s2);
    child.return_address = 0x80043B20u;
    sub_8004328C(child.caller_s3, 0x54000040u, digit, child.caller_s4, &child);
    digit = (r_u8(frame + 0x2Cu) + 1u) & 0xFFu;
    w_u32(frame + 0x10u, child.caller_s0);
    child.caller_s0 += 12u;
    w_u32(frame + 0x14u, child.caller_s1);
    w_u32(frame + 0x18u, child.caller_s2);
    child.return_address = 0x80043B50u;
    sub_8004328C(child.caller_s3, 0x54000040u, digit, child.caller_s4, &child);
    digit = (r_u8(frame + 0x30u) + 1u) & 0xFFu;
    w_u32(frame + 0x10u, child.caller_s0);
    w_u32(frame + 0x14u, child.caller_s1);
    w_u32(frame + 0x18u, child.caller_s2);
    child.return_address = 0x80043B7Cu;
    result = sub_8004328C(child.caller_s3, 0x54000040u, digit, child.caller_s4, &child);
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x4Cu);
    context->caller_s4 = r_u32(frame + 0x48u);
    context->caller_s3 = r_u32(frame + 0x44u);
    context->caller_s2 = r_u32(frame + 0x40u);
    context->caller_s1 = r_u32(frame + 0x3Cu);
    context->caller_s0 = r_u32(frame + 0x38u);
    return result;
}

uint32 sub_8004328C(uint32 table, uint32 flags, uint32 index, uint32 color, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x40u;
    uint32 entry = table + (index & 0xFFu) * 5u;
    uint32 bank;
    uint32 width;
    uint32 height;
    uint32 value;
    uint32 offset;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8004328Cu, "1.EXE");
    w_u32(frame + 0x34u, context->caller_s3);
    child.caller_s3 = color;
    w_u32(frame + 0x38u, context->return_address);
    w_u32(frame + 0x30u, context->caller_s2);
    w_u32(frame + 0x2Cu, context->caller_s1);
    w_u32(frame + 0x28u, context->caller_s0);
    bank = r_u8(entry + 4u);
    child.caller_s1 = r_u32(frame + 0x50u);
    child.caller_s2 = r_u32(frame + 0x54u);
    child.caller_s0 = r_u32(frame + 0x58u);
    width = r_u8(entry + 2u);
    height = r_u8(entry + 3u);
    w_u32(frame + 0x10u, r_u16(0x800903B4u + bank * 2u));
    bank = r_u8(entry + 4u);
    value = r_u8(entry);
    offset = r_u16(0x800903E4u + bank * 2u);
    w_u32(frame + 0x14u, (uint32)(sint32)(sint16)(value + offset));
    w_u32(frame + 0x18u, r_u8(entry + 1u));
    bank = r_u8(entry + 4u);
    w_u32(frame + 0x1Cu, (uint32)(sint32)(sint16)r_u16(0x800903C4u + bank * 2u));
    bank = r_u8(entry + 4u);
    w_u32(frame + 0x20u, (uint32)(sint32)(sint16)r_u16(0x800903D4u + bank * 2u));
    child.stack_pointer = frame;
    child.return_address = 0x80043368u;
    sub_80041C9C(0x800A98D4u, flags, width, height, &child);
    sub_80041D90(0x800A98D4u, child.caller_s3);
    sub_80041DB4(0x800A98D4u, child.caller_s1, child.caller_s2, 0u);
    value = r_u32(0x800A9A74u);
    child.caller_s0 <<= 2u;
    result = sub_80020AB4(0x800A98D4u, child.caller_s0 + value, 1u);
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x38u);
    context->caller_s3 = r_u32(frame + 0x34u);
    context->caller_s2 = r_u32(frame + 0x30u);
    context->caller_s1 = r_u32(frame + 0x2Cu);
    context->caller_s0 = r_u32(frame + 0x28u);
    return result;
}

uint32 sub_80076ED4(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 status;
    uint32 mask;
    FUNCTION_MARKER(0x80076ED4u, "1.EXE");
    w_u32(frame + 0x1Cu, context->return_address);
    w_u32(frame + 0x18u, context->caller_s0);
    MemCardExist(0u);
    MemCardSync(0u, 0u, frame + 0x10u);
    status = r_u32(frame + 0x10u);
    mask = status == 0u || status == 3u ? 1u : 0u;
    MemCardExist(16u);
    MemCardSync(0u, 0u, frame + 0x10u);
    status = r_u32(frame + 0x10u);
    if (status == 0u || status == 3u)
        mask |= 2u;
    w_u32(0x800A6518u, mask);
    context->return_address = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
    return mask;
}

uint32 sub_80073B78(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 first;
    uint32 second;
    uint32 result = 0u;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80073B78u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    child.caller_s0 = 1u;
    w_u32(frame + 0x1Cu, context->return_address);
    w_u32(frame + 0x18u, context->caller_s2);
    w_u32(frame + 0x14u, context->caller_s1);
    w_u32(0x800A651Cu, child.caller_s0);
    w_u32(0x800A98F8u, 0u);
    child.stack_pointer = frame;
    child.return_address = 0x80073BA0u;
    sub_80076ED4(&child);
    first = r_u32(0x800A6524u);
    second = r_u32(0x800A6528u);
    w_u32(0x800A7798u, first);
    w_u32(0x800A779Cu, second);
    first = r_u32(0x800A652Cu);
    second = r_u8(0x800A6530u);
    w_u32(0x800A77A0u, first);
    w_u8(0x800A77A4u, second);
    child.caller_s2 = 0x800A7798u;
    strcat((char *)psx_addr(child.caller_s2, 1u), (const char *)psx_addr(0x800A6534u, 1u));
    child.return_address = 0x80073C08u;
    child.caller_s1 = sub_80073C48(child.caller_s2, &child);
    if (child.caller_s1 == child.caller_s0)
    {
        w_u32(0x800A98F8u, child.caller_s1);
        child.return_address = 0x80073C20u;
        first = sub_80073C48(child.caller_s2, &child);
        if (first == child.caller_s1)
            result = 0xFFFFFFFFu;
    }
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x1Cu);
    context->caller_s2 = r_u32(frame + 0x18u);
    context->caller_s1 = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80073C48(uint32 filename, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x38u;
    uint32 result;
    uint32 source;
    uint32 destination;
    uint32 first;
    uint32 second;
    uint32 third;
    uint32 fourth;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80073C48u, "1.EXE");
    w_u32(frame + 0x28u, context->caller_s0);
    child.caller_s0 = filename;
    w_u32(frame + 0x2Cu, context->caller_s1);
    child.caller_s1 = 0u;
    first = r_u32(0x800A98F8u);
    w_u32(frame + 0x30u, context->return_address);
    child.stack_pointer = frame;
    result = MemCardOpen(first << 4u, filename, 1u);
    if (result != 0u)
    {
        child.caller_s1 = 1u;
        goto close_file;
    }
    child.caller_s0 = 0x800B5898u;
    first = r_u32(0x800A98F8u);
    w_u32(frame + 0x10u, 0xE00u);
    result = MemCardReadFile(first << 4u, filename, child.caller_s0, 0x200u, r_u32(frame + 0x10u));
    w_u32(frame + 0x20u, result);
    child.return_address = 0x80073CACu;
    sub_8007361C(135u, &child);
    MemCardSync(0u, 0u, frame + 0x20u);
    if (r_u32(frame + 0x20u) != 0u)
        goto close_file;
    if (r_u32(0x800A651Cu) != 1u)
    {
        child.return_address = 0x80073CE4u;
        result = sub_800732F8(child.caller_s0, &child);
        if (result == 0u)
        {
            child.return_address = 0x80073CF4u;
            sub_80073574(&child);
            w_u32(0x800A8FD0u, 0u);
        }
        else
        {
            child.caller_s1 = 1u;
            w_u32(0x800A8FD0u, child.caller_s1);
        }
        goto close_file;
    }
    source = child.caller_s0;
    destination = 0x800A9760u;
    first = source + 0x120u;
    do
    {
        second = r_u32(source);
        third = r_u32(source + 4u);
        fourth = r_u32(source + 8u);
        result = r_u32(source + 12u);
        w_u32(destination, second);
        w_u32(destination + 4u, third);
        w_u32(destination + 8u, fourth);
        w_u32(destination + 12u, result);
        source += 16u;
        destination += 16u;
    } while (source != first);
    first = r_u32(source);
    second = r_u32(source + 4u);
    third = r_u32(source + 8u);
    w_u32(destination, first);
    w_u32(destination + 4u, second);
    w_u32(destination + 8u, third);
    result = 0u;
    goto restore;
close_file:
    MemCardClose();
    result = child.caller_s1;
restore:
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

uint32 sub_80032D80(void)
{
    uint32 row;
    uint32 column;
    uint32 offset = 0u;
    FUNCTION_MARKER(0x80032D80u, "1.EXE");
    for (row = 0u; row < 5u; ++row)
    {
        for (column = 0u; column < 6u; ++column)
        {
            w_u8(0x800A976Cu + offset + column, 0u);
            w_u8(0x800A97E4u + offset + column, 0u);
            w_u8(0x800A978Au + offset + column, 5u);
            w_u8(0x800A9802u + offset + column, 5u);
            w_u8(0x800A97A8u + offset + column, 0u);
            w_u8(0x800A9820u + offset + column, 0u);
            w_u8(0x800A97C6u + offset + column, 0u);
            w_u8(0x800A983Eu + offset + column, 0u);
        }
        offset += 6u;
    }
    w_u32(0x800A985Cu, 0u);
    return 0u;
}
