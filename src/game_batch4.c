#include <string.h>
#include "psx.h"

#include "game_scene.h"

















uint32 sub_80054F40(uint32 x, uint32 y, uint32 z, uint32 matrix);













uint32 sub_80057AB0(GameGeometryCallContext *context);



uint32 sub_80041C9C(uint32 destination, uint32 flags, uint32 width, uint32 height,
    GameGeometryCallContext *context);
void sub_80041DB4(uint32 destination, uint32 x, uint32 y, uint32 rotation);
void sub_80058418(GameGeometryCallContext *context);
uint32 sub_8003D0F4(GameGeometryCallContext *context);
uint32 sub_8005982C(GameGeometryCallContext *context);
void nullsub_10(void);
uint32 sub_80057C7C(GameGeometryCallContext *context);
uint32 sub_800551CC(uint32 angle, uint32 matrix);
uint32 sub_8005E790(uint32 object, GameGeometryCallContext *context);
uint32 sub_8005E7C4(uint32 object);
uint32 sub_8005E758(GameGeometryCallContext *context);
void sub_80069A04(uint32 value);
uint32 sub_80069DC4(uint32 entries, uint32 count);
uint32 sub_80069E54(GameGeometryCallContext *context);
uint32 sub_80041DE0(uint32 object, uint32 x, uint32 y);
uint32 sub_80055134(uint32 angles, uint32 matrix, GameGeometryCallContext *context);
uint32 sub_80054F40(uint32 x, uint32 y, uint32 z, uint32 matrix);
uint32 sub_8005E818(void);
uint32 sub_80059610(GameGeometryCallContext *context);
uint32 sub_800215A0(GameGeometryCallContext *context);
uint32 sub_800651AC(uint32 resource, GameGeometryCallContext *context);
uint32 sub_8003C394(GameGeometryCallContext *context);
uint32 sub_80057AB0(GameGeometryCallContext *context);

uint32 sub_800551CC(uint32 angle, uint32 matrix)
{
    uint32 offset = (angle & 0xFFFu) << 1;
    uint32 cosine, sine;
    FUNCTION_MARKER(0x800551CCu, "1.EXE");
    cosine = (uint32)(sint32)(sint16)r_u16(0x80010AE0u + offset);
    w_u16(matrix, cosine);
    w_u16(matrix + 0x10u, cosine);
    sine = (uint32)(sint32)(sint16)r_u16(0x800102E0u + offset);
    w_u16(matrix + 8u, 0x1000u);
    w_u16(matrix + 0xEu, 0u);
    w_u16(matrix + 0xAu, 0u);
    w_u16(matrix + 6u, 0u);
    w_u16(matrix + 2u, 0u);
    w_u16(matrix + 4u, sine);
    w_u16(matrix + 0xCu, 0u - sine);
    return 0x1000u;
}

uint32 sub_8005E790(uint32 object, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    FUNCTION_MARKER(0x8005E790u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    w_u32(object, 0u);
    w_u32(object + 4u, 0u);
    w_u32(object + 8u, 0u);
    result = sub_800551CC(0u, object + 0x10u);
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8005E7C4(uint32 object)
{
    uint32 result;
    FUNCTION_MARKER(0x8005E7C4u, "1.EXE");
    result = (uint32)(sint32)(sint16)r_u16(r_u32(0x800A62ECu) + 0x2Au);
    w_u16(object + 0xCu, result);
    return result;
}

uint32 sub_8005E758(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005E758u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x8005E770u;
    sub_8005E790(0x800A9034u, &child);
    result = sub_8005E7C4(0x800A9034u);
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

void sub_80069A04(uint32 value)
{
    FUNCTION_MARKER(0x80069A04u, "1.EXE");
    w_u32(0x800A63DCu, value);
}

uint32 sub_80069DC4(uint32 entries, uint32 count)
{
    uint32 result = count << 3;
    uint32 end, table, cursor, index, word, pointer;
    FUNCTION_MARKER(0x80069DC4u, "1.EXE");
    if ((sint32)count > 0)
    {
        end = result + entries;
        table = r_u32(0x800A7E2Cu);
        cursor = r_u32(0x800A84FCu);
        do
        {
            word = r_u32(entries + 4u);
            index = 0u;
            w_u32(entries + 4u, word & 0xFFFFFCFFu);
            for (;;)
            {
                result = r_u32(cursor + 4u) & 15u;
                result = (sint32)index < (sint32)result;
                if (result == 0u)
                    break;
                word = r_u32(entries + 4u);
                pointer = table + (((uint32)((sint32)word >> 11) + index) << 2);
                word = r_u32(pointer);
                ++index;
                w_u32(pointer, word | 0xFFFFF000u);
            }
            entries += 8u;
            result = (sint32)entries < (sint32)end;
            cursor += 8u;
        } while (result != 0u);
    }
    return result;
}

uint32 sub_80069E54(GameGeometryCallContext *context)
{
    uint32 resource, frame = context->stack_pointer - 0x18u;
    uint32 entries, count, result;
    FUNCTION_MARKER(0x80069E54u, "1.EXE");
    resource = r_u32(0x800A87E0u);
    w_u32(frame + 0x10u, context->return_address);
    count = r_u32(resource);
    entries = resource + 8u;
    w_u32(0x800A84FCu, entries);
    result = entries + (count << 3);
    w_u32(0x800A63E4u, count);
    w_u32(0x800A7E2Cu, result);
    result = sub_80069DC4(entries, count);
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80041DE0(uint32 object, uint32 x, uint32 y)
{
    FUNCTION_MARKER(0x80041DE0u, "1.EXE");
    w_u16(object + 0x18u, 0x1000u);
    w_u16(object + 0x1Au, 0x1000u);
    w_u16(object + 0x14u, x);
    w_u16(object + 0x16u, y);
    return 0x1000u;
}

uint32 sub_80055134(uint32 angles, uint32 matrix, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 x, y, z, result;
    FUNCTION_MARKER(0x80055134u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    x = (uint32)(sint32)(sint16)r_u16(angles);
    y = (uint32)(sint32)(sint16)r_u16(angles + 2u);
    z = (uint32)(sint32)(sint16)r_u16(angles + 4u);
    result = sub_80054F40(x, y, z, matrix);
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80054F40(uint32 x, uint32 y, uint32 z, uint32 matrix)
{
    uint32 negative_sum = 0u - z - y;
    uint32 difference = y - z;
    uint32 ymx = ((y - x) & 0xFFFu) << 1;
    uint32 ypx = ((y + x) & 0xFFFu) << 1;
    uint32 zpx = ((z + x) & 0xFFFu) << 1;
    uint32 zmx = ((z - x) & 0xFFFu) << 1;
    uint32 nm = ((negative_sum - x) & 0xFFFu) << 1;
    uint32 dm = ((difference - x) & 0xFFFu) << 1;
    uint32 np = ((negative_sum + x) & 0xFFFu) << 1;
    uint32 dp = ((difference + x) & 0xFFFu) << 1;
    sint32 first, second, third, a, b, c, d;
    uint32 result;
    FUNCTION_MARKER(0x80054F40u, "1.EXE");
    first = (sint16)r_u16(0x800102E0u + ((y & 0xFFFu) << 1));
    w_u16(matrix + 4u, (uint32)first);
    first = (sint16)r_u16(0x80010AE0u + ((difference & 0xFFFu) << 1));
    second = (sint16)r_u16(0x80010AE0u + ((negative_sum & 0xFFFu) << 1));
    w_u16(matrix, (uint32)((first + second) >> 1));
    first = (sint16)r_u16(0x800102E0u + ((negative_sum & 0xFFFu) << 1));
    second = (sint16)r_u16(0x800102E0u + ((difference & 0xFFFu) << 1));
    w_u16(matrix + 2u, (uint32)((first + second) >> 1));
    first = (sint16)r_u16(0x800102E0u + ymx);
    second = (sint16)r_u16(0x800102E0u + ypx);
    w_u16(matrix + 0xAu, (uint32)((first - second) >> 1));
    first = (sint16)r_u16(0x80010AE0u + ypx);
    second = (sint16)r_u16(0x80010AE0u + ymx);
    w_u16(matrix + 0x10u, (uint32)((first + second) >> 1));
    first = (sint16)r_u16(0x800102E0u + dm);
    second = (sint16)r_u16(0x80010AE0u + zpx);
    third = (sint16)r_u16(0x800102E0u + nm);
    a = ((first - third) >> 2) + (second >> 1);
    first = (sint16)r_u16(0x80010AE0u + dm);
    second = (sint16)r_u16(0x800102E0u + zpx);
    third = (sint16)r_u16(0x80010AE0u + nm);
    b = ((first - third) >> 2) + (second >> 1);
    first = (sint16)r_u16(0x800102E0u + np);
    second = (sint16)r_u16(0x80010AE0u + zmx);
    third = (sint16)r_u16(0x800102E0u + dp);
    c = ((first - third) >> 2) + (second >> 1);
    first = (sint16)r_u16(0x80010AE0u + np);
    second = (sint16)r_u16(0x800102E0u + zmx);
    third = (sint16)r_u16(0x80010AE0u + dp);
    d = ((first - third) >> 2) + (second >> 1);
    w_u16(matrix + 6u, (uint32)(b + d));
    w_u16(matrix + 8u, (uint32)(c + a));
    w_u16(matrix + 0xCu, (uint32)(c - a));
    result = (uint32)(b - d);
    w_u16(matrix + 0xEu, result);
    return result;
}

uint32 sub_8005E818(void)
{
    uint32 count = 7u, offset = 70u, source = 0x80091074u;
    uint32 resource, index, value;
    FUNCTION_MARKER(0x8005E818u, "1.EXE");
    resource = r_u32(0x800A62ECu);
    do
    {
        index = (uint32)(sint32)(sint16)r_u16(source);
        offset -= 10u;
        value = (uint32)(sint32)(sint16)r_u16(resource + (index << 1));
        --count;
        w_u16(0x800A9890u + offset, value);
        value = r_u8(0x80091078u + count);
        w_u16(0x800A9894u + offset, 202u);
        w_u16(0x800A9892u + offset, value);
        source -= 2u;
    } while ((sint32)count > 0);
    w_u16(0x800A9894u, 0x6D6u);
    return 0x6D6u;
}

uint32 sub_80059610(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x20u;
    uint32 pointer, index, result;
    FUNCTION_MARKER(0x80059610u, "1.EXE");
    w_u16(frame + 0x10u, 0x2B0u);
    w_u16(frame + 0x12u, 0x1E0u);
    w_u16(frame + 0x14u, 32u);
    w_u32(frame + 0x18u, context->return_address);
    w_u16(frame + 0x16u, 1u);
    DrawSync(0);
    StoreImage((PSX_RECT *)psx_addr(frame + 0x10u, sizeof(PSX_RECT)),
        (uint32 *)psx_addr(0x800A71C8u, 1u));
    w_u16(frame + 0x10u, 0x2D0u);
    DrawSync(0);
    StoreImage((PSX_RECT *)psx_addr(frame + 0x10u, sizeof(PSX_RECT)),
        (uint32 *)psx_addr(0x800A7248u, 1u));
    DrawSync(0);
    pointer = 0x800A73C4u;
    for (index = 0u; index < 64u; ++index)
    {
        w_u32(pointer, 0u);
        pointer -= 4u;
    }
    w_u16(frame + 0x12u, 0x1E0u);
    w_u16(frame + 0x10u, 0x2B0u);
    w_u16(frame + 0x14u, 64u);
    DrawSync(0);
    LoadImagePSX((PSX_RECT *)psx_addr(frame + 0x10u, sizeof(PSX_RECT)),
        (uint32 *)psx_addr(0x800A72C8u, 1u));
    result = (uint32)DrawSync(0);
    context->return_address = r_u32(frame + 0x18u);
    return result;
}

uint32 sub_800215A0(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x48u;
    uint32 offset = 0x924u, i, group, words[4], result, half;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x800215A0u, "1.EXE");
    w_u32(frame + 0x40u, context->return_address);
    w_u32(frame + 0x3Cu, context->caller_s1);
    w_u32(frame + 0x38u, context->caller_s0);
    memset(psx_addr(0x800A9D78u, 0x930u), 0, 0x930u);
    for (i = 0u; i < 196u; ++i)
    {
        w_u16(0x800A9D78u + offset, 0u);
        w_u16(0x800A9D7Au + offset, 0xFFFFu);
        w_u32(0x800A9D80u + offset, 0u);
        offset -= 12u;
    }
    words[0] = r_u32(0x800A565Cu);
    words[1] = r_u32(0x800A5660u);
    w_u32(frame + 0x30u, words[0]);
    w_u32(frame + 0x34u, words[1]);
    child.stack_pointer = frame;
    child.caller_s0 = 3u;
    child.caller_s1 = 0x800A9A10u;
    w_u32(0x800A5644u, 0xFFFFFC18u);
    w_u32(0x800A5640u, 0xFFFFFC18u);
    do
    {
        w_u16(frame + 0x32u, child.caller_s0 << 10);
        child.return_address = 0x80021654u;
        sub_80055134(frame + 0x30u, frame + 0x10u, &child);
        for (group = 0u; group < 2u; ++group)
        {
            for (i = 0u; i < 4u; ++i)
                words[i] = r_u32(frame + 0x10u + group * 16u + i * 4u);
            for (i = 0u; i < 4u; ++i)
                w_u32(child.caller_s1 + group * 16u + i * 4u, words[i]);
        }
        --child.caller_s0;
        child.caller_s1 -= 32u;
    } while ((sint32)child.caller_s0 >= 0);
    w_u16(frame + 0x32u, 0u);
    child.return_address = 0x800216B0u;
    sub_80055134(frame + 0x30u, frame + 0x10u, &child);
    for (i = 0u; i < 3u; ++i)
        words[i] = r_u32(frame + 0x10u + i * 4u);
    for (i = 0u; i < 3u; ++i)
        w_u32(0x800A8FBCu + i * 4u, words[i]);
    result = r_u32(frame + 0x1Cu);
    half = r_u16(frame + 0x20u);
    w_u32(0x800A8FC8u, result);
    w_u16(0x800A8FCCu, half);
    context->return_address = r_u32(frame + 0x40u);
    context->caller_s1 = r_u32(frame + 0x3Cu);
    context->caller_s0 = r_u32(frame + 0x38u);
    return result;
}

uint32 sub_800651AC(uint32 resource, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 source = resource, table = 0x800A6398u;
    uint32 index, offset, destination, first, second, result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x800651ACu, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    for (index = 0u; index < 16u; ++index)
    {
        offset = r_u32(source);
        source += 4u;
        destination = r_u32(table);
        w_u32(destination, resource + offset);
        table += 4u;
    }
    first = r_u32(0x800A7494u);
    second = r_u32(0x800A7E08u);
    first = r_u32(first);
    second = r_u32(second);
    w_u32(0x800A7C70u, 0u);
    w_u32(0x800A9A38u, first);
    w_u32(0x800A9A80u, second);
    child.stack_pointer = frame;
    child.return_address = 0x80065210u;
    result = sub_800215A0(&child);
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8003C394(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    GameGeometryCallContext child = *context;
    GameSceneCallContext scene;
    FUNCTION_MARKER(0x8003C394u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    sub_80069A04(0u);
    child.stack_pointer = frame;
    child.return_address = 0x8003C3ACu;
    sub_80069E54(&child);
    child.return_address = 0x8003C3B4u;
    sub_8005E758(&child);
    child.return_address = 0x8003C3BCu;
    sub_80057AB0(&child);
    scene.stack_pointer = frame;
    scene.return_address = 0x8003C3C4u;
    scene.caller_s0 = child.caller_s0;
    result = sub_80064334(1u, &scene);
    context->caller_s0 = scene.caller_s0;
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

uint32 sub_80057AB0(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x48u;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80057AB0u, "1.EXE");
    w_u32(frame + 0x28u, context->caller_s0);
    child.caller_s0 = 1u;
    w_u32(frame + 0x2Cu, context->caller_s1);
    child.caller_s1 = 0x800A7148u;
    w_u32(0x800A73D4u, 0xD48u);
    w_u32(frame + 0x44u, context->return_address);
    w_u32(frame + 0x40u, context->caller_s6);
    w_u32(frame + 0x3Cu, context->caller_s5);
    w_u32(frame + 0x38u, context->caller_s4);
    w_u32(frame + 0x34u, context->caller_s3);
    w_u32(frame + 0x30u, context->caller_s2);
    w_u32(0x800A73CCu, 0u);
    w_u32(0x800A73D0u, 0u);
    w_u16(0x800A73DEu, 0u);
    w_u16(0x800A73DCu, 0u);
    w_u16(0x800A73E0u, 0xC00u);
    child.stack_pointer = frame;
    do
    {
        child.caller_s6 = 5u;
        child.caller_s5 = 192u;
        child.caller_s4 = 20u;
        child.caller_s3 = 368u;
        child.caller_s2 = 480u;
        w_u32(frame + 0x10u, child.caller_s6);
        w_u32(frame + 0x14u, child.caller_s5);
        w_u32(frame + 0x18u, child.caller_s4);
        w_u32(frame + 0x1Cu, child.caller_s3);
        w_u32(frame + 0x20u, child.caller_s2);
        child.return_address = 0x80057B40u;
        sub_80041C9C(child.caller_s1, 0x55000040u, 62u, 6u, &child);
        sub_80041DB4(child.caller_s1, 0xFFFFFF8Du, 72u, 0u);
        ++child.caller_s0;
        child.caller_s1 += 32u;
    } while ((sint32)child.caller_s0 < 3);
    w_u32(frame + 0x10u, 10u);
    w_u32(frame + 0x14u, 32u);
    w_u32(frame + 0x18u, 0u);
    w_u32(frame + 0x1Cu, child.caller_s3);
    w_u32(frame + 0x20u, child.caller_s2);
    child.return_address = 0x80057B9Cu;
    sub_80041C9C(0x800A7188u, 0x55000040u, 32u, 64u, &child);
    sub_80041DB4(0x800A7188u, 0xFFFFFFC0u, 72u, 0u);
    sub_80041DE0(0x800A7188u, 16u, 32u);
    w_u32(frame + 0x10u, child.caller_s6);
    w_u32(frame + 0x14u, child.caller_s5);
    w_u32(frame + 0x18u, child.caller_s4);
    w_u32(frame + 0x1Cu, child.caller_s3);
    w_u32(frame + 0x20u, child.caller_s2);
    child.return_address = 0x80057BF8u;
    sub_80041C9C(0x800A7128u, 0x55000040u, 62u, 6u, &child);
    sub_80041DB4(0x800A7128u, 0xFFFFFF8Du, 72u, 0u);
    child.caller_s0 = 0u;
    child.return_address = 0x80057C18u;
    sub_80058418(&child);
    child.return_address = 0x80057C20u;
    sub_8003D0F4(&child);
    do
    {
        ++child.caller_s0;
        child.return_address = 0x80057C28u;
        sub_8005982C(&child);
        DrawSync(0);
    } while ((sint32)child.caller_s0 < 4);
    nullsub_10();
    w_u32(0x800A73C8u, 0u);
    child.return_address = 0x80057C50u;
    result = sub_80057C7C(&child);
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x44u);
    context->caller_s6 = r_u32(frame + 0x40u);
    context->caller_s5 = r_u32(frame + 0x3Cu);
    context->caller_s4 = r_u32(frame + 0x38u);
    context->caller_s3 = r_u32(frame + 0x34u);
    context->caller_s2 = r_u32(frame + 0x30u);
    context->caller_s1 = r_u32(frame + 0x2Cu);
    context->caller_s0 = r_u32(frame + 0x28u);
    return result;
}

#include "game_scene.h"
uint32 sub_800445E0(void);
uint32 sub_8003AD54(GameGeometryCallContext *context);
uint32 sub_8003CF6C(void);
uint32 sub_800596DC(uint32 mode, GameGeometryCallContext *context);
void sub_80058418(GameGeometryCallContext *context);
uint32 sub_8003D0F4(GameGeometryCallContext *context);
uint32 sub_8005982C(GameGeometryCallContext *context);
uint32 sub_80057C7C(GameGeometryCallContext *context);
void nullsub_10(void);
uint32 sub_8003CF6C(void);
uint32 sub_8003CF8C(void);
uint32 sub_8003CFEC(void);
void sub_8003CFF8(uint32 value);
void sub_8006F150(GameMainCallContext *context);
uint32 sub_8003CF6C(void);
uint32 sub_8003CF8C(void);
uint32 sub_8003CFEC(void);
void sub_8003CFF8(uint32 value);
uint32 sub_800596DC(uint32 flags, GameGeometryCallContext *context);
void sub_8003C374(GameMainCallContext *context);
void sub_800796DC(GameMainCallContext *context);
void sub_80079C20(GameMainCallContext *context);
sint32 StartRCnt(uint32 counter);
void sub_8006F150(GameMainCallContext *context);
void sub_8006F050(GameMainCallContext *context);
void sub_8006F0CC(uint32 target, GameMainCallContext *context);
void sub_8006F050(GameMainCallContext *context);
void sub_8006F0CC(uint32 target, GameMainCallContext *context);
void sub_8006F150(GameMainCallContext *context);

uint32 sub_800445E0(void)
{
    FUNCTION_MARKER(0x800445E0u, "1.EXE");
    w_u32(0x800A9CECu, 0u);
    w_u32(0x800A9CF0u, 0u);
    w_u32(0x800A8928u, 0u);
    w_u32(0x800A892Cu, 0u);
    w_u8(0x800A5F5Cu, 0u);
    w_u8(0x800A5F5Du, 0u);
    w_u32(0x800A5F60u, 0u);
    w_u32(0x800A5F64u, 0u);
    return 0u;
}

uint32 sub_8003AD54(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    FUNCTION_MARKER(0x8003AD54u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    w_u16(0x800A6DDCu, 0u);
    w_u32(0x800A8398u, 0u);
    w_u32(0x800A98F4u, 0u);
    w_u32(0x800A6DFCu, 0u);
    w_u32(0x800A6E00u, 0u);
    w_u32(0x800A6E04u, 0u);
    w_u32(0x800A6DE8u, 0u);
    w_u32(0x800A8B30u, 0u);
    w_u16(0x800A967Cu, 0u);
    w_u32(0x800A8E70u, 1u);
    w_u32(0x800A6E34u, 0u);
    w_u32(0x800A6E08u, 0u);
    w_u32(0x800A973Cu, 0u);
    w_u16(0x800A6DD8u, 0u);
    w_u32(0x800A6E38u, 0u);
    w_u32(0x800A6E3Cu, 0u);
    w_u32(0x800A84D4u, 0u);
    w_u32(0x800A9D74u, 0u);
    w_u32(0x800A9680u, 0u);
    w_u32(0x800A6E40u, 0u);
    w_u32(0x800A6E48u, 0u);
    w_u16(0x800A8B34u, 0u);
    w_u32(0x800A6E30u, 0u);
    w_u16(0x800A9D70u, 0u);
    result = sub_800445E0();
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

void sub_80058418(GameGeometryCallContext *context)
{
    FUNCTION_MARKER(0x80058418u, "1.EXE");
    (void)context;
    w_u32(0x800A71B8u, 0u);
    w_u32(0x800A71BCu, 0u);
    w_u32(0x800A71C0u, 0u);
    w_u32(0x800A71C4u, 0u);
}

uint32 sub_8003D0F4(GameGeometryCallContext *context)
{
    uint32 index = 0u;
    FUNCTION_MARKER(0x8003D0F4u, "1.EXE");
    (void)context;
    do
    {
        w_u16(0x800A5EACu + (uint32)((sint32)(index << 16) >> 15), 0u);
        ++index;
    } while ((sint16)index < 32);
    w_u32(0x800A5EA8u, 11u);
    return 11u;
}

uint32 sub_8005982C(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005982Cu, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x8005983Cu;
    result = sub_8003CF6C() << 16;
    if ((sint32)result <= 0)
    {
        child.return_address = 0x80059850u;
        result = sub_800596DC(2u, &child);
    }
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

uint32 sub_80057C7C(GameGeometryCallContext *context)
{
    uint32 row = 0u;
    uint32 address = 0x800A930Cu;
    uint32 result;
    FUNCTION_MARKER(0x80057C7Cu, "1.EXE");
    (void)context;
    do
    {
        sint32 remaining = 1;
        uint32 cursor = address + 2u;
        do
        {
            w_u16(cursor, 0u);
            --remaining;
            cursor -= 2u;
        } while (remaining >= 0);
        ++row;
        result = (sint32)row < 3;
        address += 8u;
    } while (result != 0u);
    return result;
}

void nullsub_10(void)
{
    FUNCTION_MARKER(0x80057A88u, "1.EXE");
}

uint32 sub_8003CF6C(void)
{
    FUNCTION_MARKER(0x8003CF6Cu, "1.EXE");
    uint32 offset = (uint32)(sint32)(sint16)r_u16(0x800A5EF2u) << 1;
    return (uint32)(sint32)(sint16)r_u16(0x800A5EACu + offset);
}

uint32 sub_8003CF8C(void)
{
    FUNCTION_MARKER(0x8003CF8Cu, "1.EXE");
    uint32 value = r_u16(0x800A5EF2u);
    w_u32(0x800A5C8Cu, 1u);
    value += 1u;
    w_u16(0x800A5EF2u, (uint16)value);
    uint32 result = (sint32)(sint16)(uint16)value < 32 ? 1u : 0u;
    if (result == 0u)
        w_u16(0x800A5EF2u, 0u);
    return result;
}

uint32 sub_8003CFEC(void)
{
    FUNCTION_MARKER(0x8003CFECu, "1.EXE");
    return (uint32)(sint32)(sint16)r_u16(0x800A5EF2u);
}

void sub_8003CFF8(uint32 value)
{
    FUNCTION_MARKER(0x8003CFF8u, "1.EXE");
    w_u16(0x800A5EF2u, (uint16)value);
}

uint32 sub_800596DC(uint32 flags, GameGeometryCallContext *context)
{
    FUNCTION_MARKER(0x800596DCu, "1.EXE");
    uint32 frame = context->stack_pointer - 0x30u;
    uint32 result = flags & 2u;
    w_u32(frame + 0x2Cu, context->return_address);
    w_u32(frame + 0x28u, context->caller_s0);
    if (result == 0u)
        w_u32(0x800A6288u, 0u);
    else
    {
        result = r_u32(0x800A6288u);
        if (result != 0u)
            result = 10u;
        else
        {
            uint32 gate = r_u32(0x800A6274u);
            result = 10u;
            if (gate == 10u)
            {
                uint32 attempts = 0u;
                sub_8003CF8C();
                for (;;)
                {
                    result = sub_8003CF6C();
                    if ((sint32)(result << 16) > 0 || (sint32)attempts >= 32)
                        break;
                    attempts += 1u;
                    sub_8003CF8C();
                }
                w_u32(0x800A73C8u, 30u);
                result = sub_8003CF6C();
                if ((sint32)(result << 16) <= 0)
                {
                    sub_8003CFF8(31u);
                    w_u32(0x800A73C8u, 0u);
                }
                w_u32(0x800A6288u, 1u);
                w_u32(0x800A6274u, 0u);
                uint32 offset = (uint32)(((sint32)(sub_8003CFEC() << 16)) >> 14);
                uint32 first = r_u16(0x80090E24u + offset);
                w_u16(frame + 0x10u, (uint16)first);
                offset = (uint32)(((sint32)(sub_8003CFEC() << 16)) >> 14);
                uint32 second = r_u16(0x80090E26u + offset);
                uint32 index = r_u32(0x800A628Cu);
                w_u16(frame + 0x14u, 8u);
                w_u16(frame + 0x16u, 32u);
                w_u16(frame + 0x12u, (uint16)second);
                uint32 x = r_u16(0x80090EE4u + (index << 2));
                uint32 y = r_u16(0x80090EE6u + (index << 2));
                MoveImage((PSX_RECT *)psx_addr(frame + 0x10u, sizeof(PSX_RECT)), (sint32)x, (sint32)y);
                uint32 next = r_u32(0x800A628Cu) + 1u;
                w_u32(0x800A628Cu, next);
                result = (sint32)next < 4 ? 1u : 0u;
                if (result == 0u)
                    w_u32(0x800A628Cu, 0u);
            }
        }
    }
    context->return_address = r_u32(frame + 0x2Cu);
    context->caller_s0 = r_u32(frame + 0x28u);
    return result;
}

void sub_8003C374(GameMainCallContext *context)
{
    FUNCTION_MARKER(0x8003C374u, "1.EXE");
    uint32 frame = context->stack_pointer - 0x18u;
    w_u32(frame + 0x10u, context->return_address);
    GameMainCallContext child = *context;
    child.stack_pointer = frame;
    child.return_address = 0x8003C384u;
    sub_8006F150(&child);
    child.return_address = r_u32(frame + 0x10u);
    child.stack_pointer = context->stack_pointer;
    *context = child;
}

void sub_8006F050(GameMainCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 handle;
    GameMainCallContext child = *context;
    FUNCTION_MARKER(0x8006F050u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x8006F060u;
    sub_800796DC(&child);
    handle = (uint32)OpenEventPSX(0xF2000003u, 2u, 0x1000u, 0x80078DB8u);
    w_u32(0x800A755Cu, handle);
    EnableEventPSX(handle);
    SetRCnt(0xF2000003u, 1u, 0x1000u);
    StartRCnt(0xF2000003u);
    w_u32(0x800A8550u, 0u);
    child.return_address = 0x8006F0BCu;
    sub_80079C20(&child);
    child.return_address = r_u32(frame + 0x10u);
    child.stack_pointer = context->stack_pointer;
    *context = child;
}

void sub_8006F0CC(uint32 target, GameMainCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 handle;
    GameMainCallContext child = *context;
    FUNCTION_MARKER(0x8006F0CCu, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->return_address);
    child.stack_pointer = frame;
    child.caller_s0 = target;
    child.caller_a0 = target;
    child.return_address = 0x8006F0E0u;
    sub_800796DC(&child);
    handle = (uint32)OpenEventPSX(0xF2000002u, 2u, 0x1000u, 0x80078D70u);
    w_u32(0x800A7560u, handle);
    EnableEventPSX(handle);
    SetRCnt(0xF2000002u, (uint16)child.caller_s0, 0x1000u);
    StartRCnt(0xF2000002u);
    w_u32(0x800A7FACu, 0u);
    child.return_address = 0x8006F13Cu;
    sub_80079C20(&child);
    child.return_address = r_u32(frame + 0x14u);
    child.caller_s0 = r_u32(frame + 0x10u);
    child.stack_pointer = context->stack_pointer;
    *context = child;
}

void sub_8006F150(GameMainCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    GameMainCallContext child = *context;
    FUNCTION_MARKER(0x8006F150u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x8006F160u;
    sub_8006F050(&child);
    child.return_address = 0x8006F168u;
    child.caller_a0 = 0x4394u;
    sub_8006F0CC(0x4394u, &child);
    child.return_address = r_u32(frame + 0x10u);
    child.stack_pointer = context->stack_pointer;
    *context = child;
}

#include "game_scene.h"
void sub_8005A934(void);
uint32 sub_800649D4(uint32 value);
uint32 sub_80064E78(GameGeometryCallContext *context);
uint32 sub_80069E54(GameGeometryCallContext *context);
uint32 sub_80064B04(uint32 size, GameGeometryCallContext *context);
uint32 sub_80029C80(uint32 source, uint32 destination, uint32 scale_x, uint32 unused, uint32 entry_stack);
uint32 sub_800228DC(void);
uint32 sub_800574F4(GameGeometryCallContext *context);
uint32 sub_80029C80(uint32 source, uint32 destination, uint32 scale_x, uint32 unused, uint32 entry_stack);
uint32 sub_80029AF4(GameGeometryCallContext *context);
uint32 sub_80064B04(uint32 size, GameGeometryCallContext *context);
uint32 sub_80089118(void);
void sub_800360BC(GameGeometryCallContext *context);
void sub_8005B668(GameGeometryCallContext *context);
void sub_80038B78(void);
void sub_800360BC(GameGeometryCallContext *context);
void sub_8005B668(GameGeometryCallContext *context);
void sub_8005CA28(uint32 object, GameGeometryCallContext *context);
uint32 sub_80063C3C(uint32 destination, uint32 entry_sp);
uint32 sub_80029AF4(GameGeometryCallContext *context);
uint32 sub_800228DC(void);
uint32 sub_800574F4(GameGeometryCallContext *context);
uint32 sub_800215A0(GameGeometryCallContext *context);
void sub_80038B78(void);
uint32 sub_800510E0(GameGeometryCallContext *context);
uint32 sub_80021550(GameGeometryCallContext *context);
void sub_80069A04(uint32 value);
uint32 sub_80069E54(GameGeometryCallContext *context);
uint32 sub_8005E758(GameGeometryCallContext *context);
void sub_8005CA28(uint32 source, GameGeometryCallContext *context);
void sub_8005A934(void);
uint32 sub_8005A9FC(GameGeometryCallContext *context);
uint32 sub_80078D70(GameCallbackCallContext *context);
uint32 sub_80078DB8(GameCallbackCallContext *context);
uint32 sub_80089118(void);
uint32 sub_800205C8(uint32 value, uint32 color, uint32 mode);
uint32 sub_8003C2B8(uint32 mode, GameGeometryCallContext *context);

uint32 sub_800205C8(uint32 value, uint32 color, uint32 mode)
{
    FUNCTION_MARKER(0x800205C8u, "1.EXE");
    w_u8(0x800A7BDEu, mode);
    w_u8(0x800A7BDDu, color);
    w_u16(0x800A7BDAu, value);
    w_u8(0x800A7BDFu, 0u);
    w_u32(0x800A7BD4u, 0u);
    if ((mode & 1u) != 0u)
        w_u32(0x800A7BD4u, 0xFFFFFFu);
    w_u8(0x800A7BDCu, (sint32)mode < 2 ? 2u : 1u);
    w_u16(0x800A7BD8u, 255u);
    return 255u;
}

uint32 sub_80078D70(GameCallbackCallContext *context)
{
    uint32 frame = context->stack_pointer - 8u;
    FUNCTION_MARKER(0x80078D70u, "1.EXE");
    w_u32(frame, context->caller_fp);
    w_u32(0x800A7FACu, r_u32(0x800A7FACu) + 1u);
    context->caller_fp = r_u32(frame);
    return 0u;
}

uint32 sub_80078DB8(GameCallbackCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 page;
    FUNCTION_MARKER(0x80078DB8u, "1.EXE");
    w_u32(frame + 0x14u, context->return_address);
    w_u32(frame + 0x10u, context->caller_fp);
    w_u32(0x800A8550u, 1u);
    if (r_u32(0x800A5634u) == 1u)
    {
        DrawSync(0);
        w_u32(0x800A562Cu, 1u - r_u32(0x800A562Cu));
        page = r_u32(0x800A562Cu);
        PutDrawEnv((DRAWENV *)psx_addr(0x800A856Cu + ((page << 4u) - page) * 8u, sizeof(DRAWENV)));
        page = r_u32(0x800A562Cu);
        PutDispEnv((DISPENV *)psx_addr(0x800A85C8u + ((page << 4u) - page) * 8u, sizeof(DISPENV)));
        w_u32(0x800A5634u, 0u);
    }
    context->return_address = r_u32(frame + 0x14u);
    context->caller_fp = r_u32(frame + 0x10u);
    return 0u;
}

uint32 sub_8003C2B8(uint32 mode, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    GameGeometryCallContext child = *context;
    GameSceneCallContext scene;
    FUNCTION_MARKER(0x8003C2B8u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->return_address);
    w_u32(0x800A622Cu, 0u);
    w_u32(0x800A5638u, 0u);
    child.stack_pointer = frame;
    child.caller_s0 = mode;
    child.return_address = 0x8003C2DCu;
    sub_80029AF4(&child);
    child.caller_s0 <<= 16u;
    child.return_address = 0x8003C2E4u;
    sub_800228DC();
    child.caller_s0 = (uint32)((sint32)child.caller_s0 >> 16);
    child.return_address = 0x8003C2ECu;
    sub_800574F4(&child);
    if (child.caller_s0 == 0u)
    {
        child.return_address = 0x8003C2FCu;
        sub_800215A0(&child);
        child.return_address = 0x8003C304u;
        sub_80038B78();
    }
    if (child.caller_s0 == 1u)
    {
        child.return_address = 0x8003C318u;
        sub_800510E0(&child);
        child.return_address = 0x8003C320u;
        sub_80021550(&child);
    }
    sub_80069A04(0u);
    child.return_address = 0x8003C330u;
    sub_80069E54(&child);
    child.return_address = 0x8003C338u;
    sub_8005E758(&child);
    child.return_address = 0x8003C348u;
    sub_8005CA28(0x800A7E54u, &child);
    scene.stack_pointer = frame;
    scene.return_address = 0x8003C350u;
    scene.caller_s0 = child.caller_s0;
    sub_80064334(0u, &scene);
    child.caller_s0 = scene.caller_s0;
    child.return_address = 0x8003C358u;
    sub_8005A934();
    child.return_address = 0x8003C360u;
    result = sub_8005A9FC(&child);
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

uint32 sub_80029AF4(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x30u;
    uint32 resource, table, entries, mapping, count, index, value, result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80029AF4u, "1.EXE");
    w_u32(frame + 0x20u, context->caller_s0);
    child.caller_s0 = 0u;
    resource = r_u32(0x800A6300u);
    table = r_u32(0x800A62ECu);
    w_u32(frame + 0x28u, context->return_address);
    w_u32(frame + 0x24u, context->caller_s1);
    entries = resource + 8u;
    w_u32(0x800A90ACu, entries);
    count = r_u32(resource);
    mapping = resource + 8u + count * 40u;
    w_u32(0x800A8548u, mapping);
    do
    {
        value = r_u8(mapping + (uint32)(sint32)(sint16)r_u16(table + 0x1Au));
        index = child.caller_s0 << 3;
        ++child.caller_s0;
        w_u16(entries + value * 40u + index + 2u, 100u);
    } while ((sint32)child.caller_s0 < 4);
    table = r_u32(0x800A62ECu);
    value = (uint32)(sint32)(sint16)r_u16(table + 0x1Au);
    mapping = r_u32(0x800A8548u);
    value = r_u8(mapping + value);
    resource = r_u32(0x800A6300u);
    entries = r_u32(0x800A90ACu);
    w_u16(entries + value * 40u + 0x20u, 220u);
    count = r_u32(resource);
    child.stack_pointer = frame;
    child.return_address = 0x80029BDCu;
    result = sub_80064B04(count * 40u, &child);
    resource = r_u32(0x800A6300u);
    count = r_u32(resource + 4u);
    w_u32(0x800A9750u, result);
    child.caller_s0 = 0u;
    if (count != 0u)
    {
        child.caller_s1 = 255u;
        do
        {
            mapping = r_u32(0x800A8548u);
            value = r_u8(mapping + child.caller_s0);
            ++child.caller_s0;
            if (value != child.caller_s1)
            {
                w_u32(frame + 0x10u, 0xB333u);
                entries = r_u32(0x800A90ACu);
                table = r_u32(0x800A9750u);
                sub_80029C80(entries + value * 40u, table + value * 40u, 0xCCCCu, 0x10000u, frame);
            }
            resource = r_u32(0x800A6300u);
            result = child.caller_s0 < r_u32(resource + 4u);
        } while (result != 0u);
    }
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->return_address = r_u32(frame + 0x28u);
    context->caller_s1 = r_u32(frame + 0x24u);
    context->caller_s0 = r_u32(frame + 0x20u);
    return result;
}

uint32 sub_80064B04(uint32 size, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 current, next, available, block, offset, node, following;
    uint32 first, second, distance, remainder, result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80064B04u, "1.EXE");
    w_u32(frame + 0x20u, context->return_address);
    w_u32(frame + 0x1Cu, context->caller_s3);
    w_u32(frame + 0x18u, context->caller_s2);
    w_u32(frame + 0x14u, context->caller_s1);
    w_u32(frame + 0x10u, context->caller_s0);
    child.stack_pointer = frame;
    child.caller_s2 = sub_800649D4(size);
    current = r_u32(0x800A748Cu);
    child.caller_s1 = child.caller_s2 + 8u;
    offset = current << 3;
    available = r_u32(0x800AC6ACu + offset);
    block = r_u32(0x800AC6A8u + offset);
    if (available >= child.caller_s1)
        goto allocate;
    child.caller_s3 = 1u;
    next = current + 1u;
advance:
    w_u32(0x800A748Cu, next);
    if (next == 256u)
        w_u32(0x800A748Cu, 0u);
    current = r_u32(0x800A748Cu);
    next = r_u32(0x800A7490u);
    child.caller_s0 = current;
    if (current != next)
        goto inspect;
    w_u32(0x800A748Cu, 0xFFFFFFFFu);
collect:
    child.return_address = 0x80064B94u;
    result = sub_80064E78(&child);
    if (result == child.caller_s3)
    {
        result = 0u;
        goto finish;
    }
    next = r_u32(0x800A7490u);
    if (child.caller_s0 == next)
        goto collect;
    w_u32(0x800A748Cu, child.caller_s0);
inspect:
    current = r_u32(0x800A748Cu);
    offset = current << 3;
    available = r_u32(0x800AC6ACu + offset);
    block = r_u32(0x800AC6A8u + offset);
    next = current + 1u;
    if (available < child.caller_s1)
        goto advance;
allocate:
    offset = r_u32(0x800A748Cu) << 3;
    available = r_u32(0x800AC6ACu + offset);
    w_u32(0x800AC6ACu + offset, available - child.caller_s1);
    second = r_u32(block + 4u);
    first = r_u32(block);
    node = block + (second >> 20) + ((first >> 20) << 12) + 8u;
    following = block + (first & 0xFFFFFu);
    second = r_u32(node + 4u);
    first = r_u32(node);
    second = (second & 0xFFFFFu) | (child.caller_s2 << 20);
    first = (first & 0xFFFFFu) | ((child.caller_s2 >> 12) << 20);
    w_u32(node, first);
    distance = (node - block) & 0xFFFFFu;
    w_u32(node + 4u, second);
    second = r_u32(node + 4u);
    remainder = following - node;
    w_u32(node + 4u, (second & 0xFFF00000u) | distance);
    first = r_u32(block);
    w_u32(block, (first & 0xFFF00000u) | distance);
    first = r_u32(node);
    remainder &= 0xFFFFFu;
    w_u32(node, (first & 0xFFF00000u) | remainder);
    result = node + 8u;
    second = r_u32(following + 4u);
    w_u32(following + 4u, (second & 0xFFF00000u) | remainder);
    w_u32(0x800AC6A8u + offset, node);
finish:
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

uint32 sub_80029C80(uint32 source, uint32 destination, uint32 scale_x, uint32 unused, uint32 entry_stack)
{
    uint32 index = 0u;
    uint32 scale_y = r_u32(entry_stack + 0x10u);
    uint32 factor_x = (uint32)((sint32)scale_x >> 8);
    uint32 factor_y = (uint32)((sint32)scale_y >> 8);
    uint32 value, result;
    FUNCTION_MARKER(0x80029C80u, "1.EXE");
    (void)unused;
    do
    {
        uint32 offset = (uint32)((sint32)(index << 16) >> 13);
        uint32 input = source + offset;
        uint32 output = destination + offset;
        value = ((uint32)(sint32)(sint16)r_u16(input) << 8) * factor_x;
        w_u16(output, (uint32)((sint32)value >> 16));
        value = ((uint32)(sint32)(sint16)r_u16(input + 4u) << 8) * factor_y;
        w_u16(output + 4u, (uint32)((sint32)value >> 16));
        ++index;
        value = r_u16(input + 2u);
        w_u16(output + 2u, value);
    } while ((sint16)index < 4);
    w_u16(destination + 0x20u, r_u16(source + 0x20u));
    value = ((uint32)(sint32)(sint16)r_u16(source + 0x22u) << 8) * factor_y;
    w_u16(destination + 0x22u, (uint32)((sint32)value >> 16));
    value = ((uint32)(sint32)(sint16)r_u16(source + 0x24u) << 8) * factor_x;
    result = (uint32)((sint32)value >> 16);
    w_u16(destination + 0x24u, result);
    return result;
}

uint32 sub_800228DC(void)
{
    FUNCTION_MARKER(0x800228DCu, "1.EXE");
    w_u32(0x800A5678u, 0u);
    w_u32(0x800A567Cu, 0u);
    w_u32(0x800A5688u, 0u);
    w_u32(0x800A5684u, 0u);
    w_u32(0x800A5680u, 0u);
    w_u32(0x800A5690u, 0u);
    w_u32(0x800A568Cu, 0x800A6994u);
    return 0x800A6994u;
}

uint32 sub_800574F4(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x800574F4u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    w_u32(0x800A6228u, 0u);
    w_u32(0x800A5F18u, 0u);
    w_u32(0x800A7098u, 0u);
    w_u32(0x800A622Cu, 0u);
    child.stack_pointer = frame;
    child.return_address = 0x80057518u;
    result = sub_80069E54(&child);
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

void sub_80038B78(void)
{
    FUNCTION_MARKER(0x80038B78u, "1.EXE");
    w_u32(0x800A98F4u, 0u);
    w_u32(0x800A9A50u, 0u);
    w_u32(0x800A7C74u, 0u);
    w_u32(0x800A7E4Cu, 0u);
    w_u32(0x800A6D4Cu, 0u);
    w_u32(0x800A5C8Cu, 0u);
}

void sub_8005CA28(uint32 object, GameGeometryCallContext *context)
{
    FUNCTION_MARKER(0x8005CA28u, "1.EXE");
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 pointer = object + 0x40u;
    uint32 angle = 0xFFFFF000u;
    uint32 remaining = 8u;
    w_u32(frame + 0x10u, context->return_address);
    w_u16(object + 0x16u, 0xFF06u);
    w_u16(object + 0xEu, 0xFF06u);
    w_u16(object + 0x1Eu, 0xFF06u);
    w_u16(object + 0x7Cu, 600u);
    w_u16(object + 0x18u, 600u);
    w_u16(object + 0x10u, 600u);
    w_u16(object + 0x20u, 600u);
    w_u16(object + 0x14u, 0u);
    w_u16(object + 0xCu, 0u);
    w_u16(object + 0x1Cu, 0u);
    w_u8(object + 0x2Fu, 1u);
    w_u8(object + 0x32u, 1u);
    w_u8(object + 0x2Cu, 1u);
    w_u16(object + 0x24u, 0u);
    do
    {
        angle += 0x200u;
        uint32 offset = (angle & 0xFFFu) << 1;
        pointer -= 8u;
        uint32 value = (uint32)(sint32)(sint16)r_u16(0x800102E0u + offset);
        uint32 product = (((value << 4) - value) << 2) + value;
        w_u16(pointer + 0x34u, (uint16)((sint32)product >> 11));
        value = (uint32)(sint32)(sint16)r_u16(0x80010AE0u + offset);
        remaining -= 1u;
        w_u16(pointer + 0x36u, 0u);
        product = (((value << 4) - value) << 2) + value;
        w_u16(pointer + 0x38u, (uint16)((sint32)product >> 11));
    } while ((sint32)remaining > 0);
    GameGeometryCallContext child = *context;
    child.stack_pointer = frame;
    child.return_address = 0x8005CAF0u;
    sub_8005B668(&child);
    w_u16(0x800A8530u, 0u);
    child.return_address = r_u32(frame + 0x10u);
    child.stack_pointer = context->stack_pointer;
    *context = child;
}

void sub_8005B668(GameGeometryCallContext *context)
{
    FUNCTION_MARKER(0x8005B668u, "1.EXE");
    uint32 frame = context->stack_pointer - 0x18u;
    w_u32(frame + 0x10u, context->return_address);
    w_u16(0x800A9468u, 0u);
    w_u16(0x800A946Au, 0u);
    GameGeometryCallContext child = *context;
    child.stack_pointer = frame;
    child.return_address = 0x8005B684u;
    sub_800360BC(&child);
    child.return_address = r_u32(frame + 0x10u);
    child.stack_pointer = context->stack_pointer;
    *context = child;
}

void sub_800360BC(GameGeometryCallContext *context)
{
    FUNCTION_MARKER(0x800360BCu, "1.EXE");
    uint32 frame = context->stack_pointer - 0x48u;
    w_u32(frame + 0x40u, context->return_address);
    w_u32(frame + 0x3Cu, context->caller_s1);
    w_u32(frame + 0x38u, context->caller_s0);
    if (sub_80089118() == 1u)
    {
        uint32 voice = 0u;
        do
        {
            w_u8(0x800A7E34u + voice, 0u);
            SpuSetReverbVoice(0, 1u << (voice & 31u));
            voice += 1u;
        } while ((sint32)voice < 24);
        w_u32(0x800A8204u, 31u);
        w_u32(0x800A8210u, 40u);
        w_u32(0x800A8208u, 0u);
        w_u16(0x800A820Cu, 0u);
        w_u16(0x800A820Eu, 0u);
        w_u32(0x800A8214u, 100u);
        SpuSetReverbModeParam((SpuReverbAttr *)psx_addr(0x800A8204u, sizeof(SpuReverbAttr)));
        SpuSetReverbDepth((SpuReverbAttr *)psx_addr(0x800A8204u, sizeof(SpuReverbAttr)));
        SpuSetReverb(0);
        w_u32(frame + 0x10u, 0x100u);
        w_u32(frame + 0x24u, 0u);
        SpuSetCommonAttr((SpuCommonAttr *)psx_addr(frame + 0x10u, sizeof(SpuCommonAttr)));
    }
    context->return_address = r_u32(frame + 0x40u);
    context->caller_s1 = r_u32(frame + 0x3Cu);
    context->caller_s0 = r_u32(frame + 0x38u);
}

uint32 sub_80089118(void)
{
    FUNCTION_MARKER(0x80089118u, "1.EXE");
    return (r_u16(r_u32(0x800A4E14u) + 0x1AAu) & 0x80u) != 0u;
}

void sub_8005A934(void)
{
    FUNCTION_MARKER(0x8005A934u, "1.EXE");
    w_u32(0x800A7450u, 0u);
    w_u32(0x800A7454u, 0u);
}
