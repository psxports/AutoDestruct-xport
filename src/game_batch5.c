#include "psx.h"

#include "game_scene.h"
uint32 sub_8003CF6C(void);
void sub_8003CFF8(uint32 value);
uint32 sub_8003CFEC(void);
uint32 sub_8005A9FC(GameGeometryCallContext *context);
uint32 sub_8002B198(uint32 source, uint32 destination);
uint32 sub_80022908(uint32 object, uint32 entries, uint32 count);
uint32 sub_80064B04(uint32 size, GameGeometryCallContext *context);
uint32 sub_800226E4(uint32 size, GameGeometryCallContext *context);
uint32 sub_8002E310(uint32 position, uint32 normal_output, uint32 tag_output, GameGeometryCallContext *context);
uint32 sub_8004F340(uint32 destination, uint32 source, GameGeometryCallContext *context);
uint32 sub_8004F394(uint32 unused, uint32 destination, uint32 count, uint32 incoming_v0);
uint32 sub_80045280(uint32 object);
uint32 sub_80054D38(uint32 x, uint32 y, uint32 z, uint32 output,
    GameSceneCallContext *context);













void sub_8003D324(uint32 value);
void sub_8003D27C(uint32 value);
void sub_8003D694(uint32 value);
uint32 sub_8002912C(uint32 object, uint32 mode, GameGeometryCallContext *context);
uint32 sub_8006E490(uint32 object, GameGeometryCallContext *context);
uint32 sub_800535DC(uint32 object, uint32 first, uint32 second, uint32 third, GameGeometryCallContext *context);
uint32 sub_8003D67C(void);
uint32 sub_80044E68(void);
uint32 sub_8005BF3C(uint32 object, GameGeometryCallContext *context);
uint32 sub_8004F8E4(void);
uint32 sub_8004F394(uint32 unused, uint32 destination, uint32 count, uint32 incoming_v0);
uint32 sub_80045280(uint32 object);
uint32 sub_800226E4(uint32 size, GameGeometryCallContext *context);
uint32 sub_8004F340(uint32 destination, uint32 source, GameGeometryCallContext *context);
uint32 sub_8002E310(uint32 position, uint32 normal_output, uint32 tag_output, GameGeometryCallContext *context);
uint32 sub_8004F47C(uint32 first_argument, uint32 second_argument, GameGeometryCallContext *context);
uint32 sub_80029C80(uint32 source, uint32 destination, uint32 scale_x, uint32 unused_a3, uint32 entry_stack);
uint32 sub_8002B198(uint32 source, uint32 destination);
uint32 sub_80022908(uint32 object, uint32 entries, uint32 count);
uint32 sub_80063888(uint32 object, GameGeometryCallContext *context);
uint32 sub_8003D654(void);
void sub_8003D324(uint32 value);
void sub_8003D27C(uint32 value);
void sub_8003D694(uint32 value);
uint32 sub_8003D654(void);
uint32 sub_8002912C(uint32 object, uint32 mode, GameGeometryCallContext *context);
uint32 sub_8004F8E4(void);
uint32 sub_8004F394(uint32 source, uint32 destination, uint32 count, uint32 incoming_v0);
uint32 sub_8004F47C(uint32 source, uint32 mode, GameGeometryCallContext *context);
uint32 sub_800226E4(uint32 size, GameGeometryCallContext *context);
uint32 sub_8004F340(uint32 destination, uint32 source, GameGeometryCallContext *context);
uint32 sub_80064B04(uint32 size, GameGeometryCallContext *context);
uint32 sub_80055A70(uint32 matrix, GameGeometryCallContext *context);
uint32 sub_80022908(uint32 object, uint32 entries, uint32 count);
uint32 sub_80055A9C(uint32 x, uint32 z, GameGeometryCallContext *context);
uint32 sub_80055D54(uint32 object, uint32 destination, uint32 rotation, GameGeometryCallContext *context);
uint32 sub_8004ED64(uint32 object, GameGeometryCallContext *context);
uint32 sub_8002E310(uint32 position, uint32 normal, uint32 tag, GameGeometryCallContext *context);
uint32 sub_8004E4F4(uint32 object, uint32 height);
uint32 sub_8004E6A4(uint32 object, uint32 mode, GameGeometryCallContext *context);
uint32 sub_8002B198(uint32 source, uint32 destination);
uint32 sub_80045280(uint32 object);
uint32 sub_800535DC(uint32 object, uint32 mode, uint32 value, uint32 duration, GameGeometryCallContext *context);
uint32 sub_8005BF3C(uint32 object, GameGeometryCallContext *context);
uint32 sub_8004F938(uint32 source, GameGeometryCallContext *context);

uint32 sub_8005A9FC(GameGeometryCallContext *context)
{
    FUNCTION_MARKER(0x8005A9FCu, "1.EXE");
    uint32 frame = context->stack_pointer - 0x30u;
    uint32 count = 0u;
    uint32 x_pointer = 0x80090EE4u;
    uint32 y_pointer = 0x80090EE6u;
    w_u32(frame + 0x2Cu, context->return_address);
    w_u32(frame + 0x28u, context->caller_s4);
    w_u32(frame + 0x24u, context->caller_s3);
    w_u32(frame + 0x20u, context->caller_s2);
    w_u32(frame + 0x1Cu, context->caller_s1);
    w_u32(frame + 0x18u, context->caller_s0);
    if ((sint32)(sub_8003CF6C() << 16u) <= 0)
        sub_8003CFF8(31u);
    do
    {
        count += 2u;
        uint32 index = (uint32)((sint32)(sub_8003CFEC() << 16u) >> 14);
        w_u16(frame + 0x10u, r_u16(0x80090E24u + index));
        index = (uint32)((sint32)(sub_8003CFEC() << 16u) >> 14);
        uint32 y = r_u16(0x80090E26u + index);
        w_u16(frame + 0x14u, 8u);
        w_u16(frame + 0x16u, 32u);
        w_u16(frame + 0x12u, (uint16)y);
        DrawSync(0);
        uint32 destination_y = r_u16(y_pointer);
        y_pointer += 4u;
        uint32 destination_x = r_u16(x_pointer);
        x_pointer += 4u;
        MoveImage((PSX_RECT *)psx_addr(frame + 0x10u, sizeof(PSX_RECT)), (sint32)destination_x, (sint32)destination_y);
    } while ((sint32)count < 8);
    context->return_address = r_u32(frame + 0x2Cu);
    context->caller_s4 = r_u32(frame + 0x28u);
    context->caller_s3 = r_u32(frame + 0x24u);
    context->caller_s2 = r_u32(frame + 0x20u);
    context->caller_s1 = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
    return 0u;
}

uint32 sub_8004F938(uint32 source, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0xC8u;
    uint32 record = frame + 0x28u;
    uint32 object = 0u, index, table, value, value2, value3, result, kind, choice;
    uint32 counter = 0u;
    sint32 signed_value;
    GameGeometryCallContext child = *context;
    GameSceneCallContext scene;
    FUNCTION_MARKER(0x8004F938u, "1.EXE");
    value = r_u32(0x800A62FCu);
    w_u32(frame + 0xB8u, context->caller_s6);
    w_u32(frame + 0xC4u, context->return_address);
    w_u32(frame + 0xC0u, context->caller_fp);
    w_u32(frame + 0xBCu, context->caller_s7);
    w_u32(frame + 0xB4u, context->caller_s5);
    w_u32(frame + 0xB0u, context->caller_s4);
    w_u32(frame + 0xACu, context->caller_s3);
    w_u32(frame + 0xA8u, context->caller_s2);
    w_u32(frame + 0xA4u, context->caller_s1);
    w_u32(frame + 0xA0u, context->caller_s0);
    w_u16(0x800A9734u, 0u);
    w_u32(0x800A6EECu, 0u);
    w_u32(0x800A6EE8u, 0u);
    w_u32(0x800A6EF0u, 0u);
    w_u32(0x800A5FA0u, 0u);
    w_u32(0x800A622Cu, 0u);
    w_u32(0x800A6ED4u, value);
    child.stack_pointer = frame;
    child.caller_s6 = source;
    result = sub_8004F8E4();
    result = sub_8004F394(child.caller_s6, 0x800A7F18u, 144u, result);
    value = (uint32)r_s16(0x800A7F3Eu);
    w_u32(0x800A5768u, 1u);
    w_u32(0x800A6EE4u, 60u);
    value2 = (uint32)r_s16(0x800A7F66u);
    w_u32(0x800A5764u, 0u);
    w_u32(0x800A6224u, value2);
    child.return_address = 0x8004F9E8u;
    result = sub_80064B04((value + 2u) << 2u, &child);
    value = (uint32)r_s16(0x800A7F3Eu);
    w_u32(0x800A851Cu, result);
    child.return_address = 0x8004F9FCu;
    result = sub_80064B04(value + 2u, &child);
    value = (uint32)r_s16(0x800A7F3Eu);
    w_u32(0x800A7F08u, result);
    child.caller_fp = 0u;
    if ((sint32)(value + 2u) > 0)
    {
        do
        {
            index = (uint32)(sint32)(sint16)child.caller_fp;
            ++child.caller_fp;
            w_u8(r_u32(0x800A7F08u) + index, 0u);
        } while ((sint32)(sint16)child.caller_fp < r_s16(0x800A7F3Eu) + 2);
    }
    value = (uint32)r_s16(0x800A7F3Cu);
    w_u32(0x800A9748u, 0u);
    w_u32(0x800A5690u, 0u);
    child.caller_fp = 0u;
    if ((sint32)value <= 0)
        goto finish;
    child.caller_s7 = record;
    child.caller_s5 = 8u;
    child.caller_s4 = 1u;
next_record:
    result = sub_8004F394(child.caller_s6, frame + 0x20u, 4u, result);
    kind = r_u32(frame + 0x20u);
    switch (kind)
    {
    case 1u:
        child.return_address = 0x8004FACCu;
        result = sub_8004F47C(child.caller_s6, 1u, &child);
        goto advance;
    case 2u:
        result = sub_8004F394(child.caller_s6, child.caller_s7, 40u, result);
        child.caller_s1 = child.caller_s7;
        if (r_s16(frame + 0x36u) == 2)
        {
            child.return_address = 0x8004FAFCu;
            result = sub_800226E4(460u, &child);
            object = child.caller_s0 = result;
            index = 0u;
            do { w_u8(object + 56u + (uint32)(sint32)(sint16)index, 0u); ++index; }
            while ((uint16)index < 404u);
            w_u8(object + 34u, child.caller_s5);
            choice = r_s16(record + 38u) == 2 ? 4u : (r_s16(record + 38u) == 1 ? 3u : 1u);
            table = 0x800136E8u + 10u * choice;
            w_u16(object + 32u, r_u16(r_u32(0x800A62ECu) + 2u * r_u8(table)));
            index = 0u;
            do
            {
                value = r_u16(r_u32(0x800A62ECu) + 2u * r_u8(table + (uint32)(sint32)(sint16)index + 1u));
                w_u8(object + 36u * index + 102u, child.caller_s5);
                w_u16(object + 36u * index + 100u, value);
                ++index;
            } while ((sint16)index < 9);
            child.return_address = 0x8004FBF0u;
            sub_80055A70(object + 428u, &child);
            value = r_u16(r_u32(0x800A62ECu) + 0xAAu);
            w_u8(object + 426u, child.caller_s5);
            w_u16(object + 452u, 2u);
            w_u16(object + 424u, value);
            child.return_address = 0x8004FC1Cu;
            sub_80022908(object, object + 88u, 10u);
            w_u32(object, 0x800473C8u);
            scene.stack_pointer = frame; scene.return_address = 0x8004FC3Cu; scene.caller_s0 = child.caller_s0;
            sub_80054D38(0u, 0u, 0u, object + 36u, &scene); child.caller_s0 = scene.caller_s0;
            for (index = 0u; index < 4u; ++index)
                w_u16(object + 72u + index * 2u, r_u16(child.caller_s1 + 28u + index * 2u));
            if (r_u8(child.caller_s1 + 21u)) w_u8(object + 14u, r_u8(object + 14u) | 2u);
            if (r_u8(child.caller_s1 + 20u)) w_u8(object + 14u, r_u8(object + 14u) | 8u);
            child.return_address = 0x8004FCB8u;
            sub_8004F340(object + 20u, child.caller_s1, &child);
            w_u16(object + 58u, r_u16(child.caller_s1 + 14u));
            w_u8(object + 67u, r_u8(child.caller_s1 + 24u));
            w_u16(object + 80u, r_u16(child.caller_s1 + 36u));
            w_u16(object + 82u, r_u16(child.caller_s1 + 38u));
            w_u16(object + 68u, r_u16(child.caller_s1 + 12u));
            w_u16(object + 56u, r_u16(child.caller_s1 + 16u));
            value = r_u16(child.caller_s1 + 18u);
            w_u8(object + 65u, child.caller_s4); w_u8(object + 66u, child.caller_s4);
            w_u16(object + 84u, value);
            if (r_u8(child.caller_s1 + 21u)) w_u8(object + 66u, 0u);
            w_u16(object + 62u, 0xFFFFu);
            w_u8(object + 13u, r_u8(child.caller_s1 + 24u) ? 12u : 4u);
            value = r_u32(0x800A7BACu);
            value2 = r_u32(object + 20u); value3 = r_u32(object + 28u);
            child.return_address = 0x8004FD64u;
            result = sub_80055A9C(r_u32(value + 20u) - value2, r_u32(value + 28u) - value3, &child);
            child.return_address = 0x8004FD7Cu;
            sub_80055D54(object, object + 88u, (uint32)(sint32)(sint16)(0u - result), &child);
            value = (uint32)r_s16(object + 452u); value2 = (uint32)r_s16(object + 458u);
            value = (uint32)r_s16(r_u32(0x8008FCFCu + (value << 2u)) + (value2 << 6u));
            w_u32(object + 24u, r_u32(object + 24u) - value);
            w_u32(r_u32(0x800A851Cu) + ((uint32)r_s16(child.caller_s1 + 12u) << 2u), object);
            goto advance;
        }
        child.return_address = 0x8004FDD0u;
        result = sub_800226E4(124u, &child); object = child.caller_s0 = result;
        w_u8(object + 34u, child.caller_s5);
        index = object + 56u;
        do { w_u8(index, 0u); ++index; } while (index < object + 124u);
        w_u32(object, 0x80047124u);
        scene.stack_pointer = frame; scene.return_address = 0x8004FE10u; scene.caller_s0 = child.caller_s0;
        sub_80054D38(0u, 0u, 0u, object + 36u, &scene); child.caller_s0 = scene.caller_s0;
        for (index = 0u; index < 4u; ++index) w_u16(object + 72u + 2u * index, r_u16(record + 28u + 2u * index));
        value = r_u16(0x800A5FA8u + ((uint32)r_s16(frame + 0x36u) << 1u));
        w_u16(object + 32u, r_u16(r_u32(0x800A62ECu) + 2u * value));
        if (r_u8(frame + 0x3Du)) w_u8(object + 14u, r_u8(object + 14u) | 2u);
        if (r_u8(frame + 0x3Cu)) w_u8(object + 14u, r_u8(object + 14u) | 8u);
        child.return_address = 0x8004FEB4u;
        sub_8004F340(object + 20u, record, &child);
        if (r_s16(frame + 0x36u) == 7) w_u16(record + 14u, 4u);
        w_u16(object + 58u, r_u16(frame + 0x36u));
        w_u8(object + 67u, r_u8(frame + 0x40u));
        w_u16(object + 80u, r_u16(frame + 0x4Cu));
        w_u16(object + 82u, r_u16(frame + 0x4Eu));
        w_u16(object + 68u, r_u16(frame + 0x34u));
        w_u16(object + 56u, r_u16(frame + 0x38u));
        value = r_u16(frame + 0x3Au);
        w_u8(object + 65u, child.caller_s4); w_u8(object + 66u, child.caller_s4); w_u16(object + 84u, value);
        if (r_u8(frame + 0x3Du)) w_u8(object + 66u, 0u);
        w_u16(object + 70u, r_u16(0x800A6EE4u));
        choice = 11u;
        signed_value = r_s16(frame + 0x36u);
        switch (signed_value)
        {
        case 0: case 1: case 5: case 6:
            if (!r_u8(object + 67u)) choice = 3u;
            value = r_u16(0x800A5FC8u + ((uint32)signed_value << 1u)); goto type2_extra;
        case 3: case 4: case 7:
            choice = r_u8(object + 67u) ? 14u : 6u;
            value = r_u16(0x800A5FC8u + ((uint32)signed_value << 1u)); goto type2_extra;
        case 12:
            if (!r_u8(object + 67u)) choice = 3u;
            value = r_u16(0x800A5FE6u + ((uint32)r_s16(object + 82u) << 1u)); goto type2_extra;
        case 13:
            if (!r_u8(object + 67u)) choice = 3u;
            value = r_u16(0x800A5FEEu + ((uint32)r_s16(object + 82u) << 1u));
 type2_extra:
            w_u16(object + 100u, r_u16(r_u32(0x800A62ECu) + (value << 1u)));
            w_u8(object + 13u, choice);
            w_u8(object + 102u, child.caller_s5);
            scene.stack_pointer = frame; scene.return_address = 0x8005006Cu; scene.caller_s0 = child.caller_s0;
            sub_80054D38(0u, 0u, 0u, object + 104u, &scene); child.caller_s0 = scene.caller_s0;
            child.return_address = 0x8005007Cu;
            sub_80022908(object, object + 88u, 1u);
            value = r_u16(object + 32u);
            value = r_u8(r_u32(0x800A8548u) + value);
            value = r_u16(r_u32(0x800A90ACu) + value * 40u + 32u);
            value2 = r_u32(object + 24u); value3 = r_u32(object + 20u);
            w_u32(object + 88u, value3);
            w_u32(object + 24u, value2 - (uint32)((sint32)(value << 16u) >> 17));
            value = r_u32(object + 24u) - 350u; value2 = r_u32(object + 28u);
            w_u32(object + 96u, value2); w_u32(object + 92u, value);
            break;
        default:
            if (!r_u8(object + 67u)) choice = 3u;
            w_u8(object + 13u, choice); break;
        }
        w_u16(object + 62u, 0xFFFFu); w_u16(object + 86u, r_u16(frame + 0x42u));
        if (r_u16(frame + 0x4Eu) - 27u < 2u)
        {
            value = r_u16(r_u32(0x800A62ECu) + 0x1C0u);
            w_u32(object, 0x800469E8u); w_u16(object + 100u, value);
        }
        w_u32(r_u32(0x800A851Cu) + ((uint32)r_s16(frame + 0x34u) << 2u), object);
        w_u8(r_u32(0x800A7F08u) + (uint32)r_s16(frame + 0x34u), 2u);
        goto advance;
    case 3u:
        child.return_address = 0x80050160u;
        result = sub_800226E4(72u, &child); object = child.caller_s0 = result;
        child.caller_s1 = frame + 0x50u;
        w_u8(object + 34u, child.caller_s5);
        result = sub_8004F394(child.caller_s6, child.caller_s1, 48u, result);
        value = (uint32)r_s16(frame + 0x54u) + (uint32)r_s16(frame + 0x60u);
        w_u32(object + 24u, (uint32)((sint32)(value + (value >> 31u)) >> 1));
        value = r_u32(frame + 0x50u) + r_u32(frame + 0x5Cu);
        w_u32(object + 20u, (uint32)((sint32)value >> 1));
        value = r_u32(frame + 0x58u) + r_u32(frame + 0x64u);
        w_u32(object + 28u, (uint32)((sint32)value >> 1));
        value = r_u32(object + 20u); value2 = r_u32(object + 24u); value3 = r_u32(object + 28u);
        w_u32(frame + 0x80u, value); w_u32(frame + 0x84u, value2); w_u32(frame + 0x88u, value3);
        child.return_address = 0x800501ECu;
        sub_8004F340(object + 20u, frame + 0x80u, &child);
        value = r_u32(object + 24u) + 136u;
        w_u32(object + 24u, value); if ((sint32)value > 0) w_u32(object + 24u, 0u);
        w_u32(object + 36u, (uint32)((sint32)(r_u32(frame + 0x5Cu) - r_u32(frame + 0x50u)) >> 1));
        w_u32(object + 40u, (uint32)((sint32)(r_u32(frame + 0x64u) - r_u32(frame + 0x58u)) >> 1));
        w_u32(object + 44u, (uint32)r_s16(frame + 0x54u)); w_u32(object + 48u, (uint32)r_s16(frame + 0x60u));
        value = r_u16(frame + 0x6Au); w_u16(object + 34u, value);
        w_u32(object, (sint16)value < 0 || r_s16(0x800A7F3Eu) < (sint16)value ? 0x8004644Cu : 0x800463F0u);
        w_u8(object + 64u, 0u); w_u16(object + 68u, r_u16(frame + 0x68u));
        for (index = 0u; index < 4u; ++index) w_u16(object + 56u + index * 2u, r_u16(child.caller_s1 + 40u + index * 2u));
        w_u16(object + 32u, r_u16(frame + 0x6Cu));
        value = r_u16(frame + 0x6Eu); w_u8(object + 65u, child.caller_s4); w_u8(object + 66u, child.caller_s4); w_u16(object + 52u, value);
        if (r_u8(frame + 0x71u)) w_u8(object + 66u, 0u);
        if (r_u8(frame + 0x70u)) w_u8(object + 14u, r_u8(object + 14u) | 8u);
        w_u8(object + 8u, r_u8(frame + 0x75u)); w_u16(object + 54u, r_u16(frame + 0x76u)); w_u8(object + 67u, r_u8(frame + 0x74u));
        w_u8(object + 13u, r_u8(object + 67u) ? 13u : 5u);
        w_u32(r_u32(0x800A851Cu) + ((uint32)r_s16(frame + 0x68u) << 2u), object);
        w_u8(r_u32(0x800A7F08u) + (uint32)r_s16(frame + 0x68u), 3u);
        goto advance;
    case 4u:
        table = r_u32(0x800A6ED4u); value = (uint32)r_s16(table + 10u);
        w_u8(table + 18u, 0u); w_u32(0x800A6ED4u, r_u32(0x800A6ED4u) + value);
        w_u32(r_u32(0x800A851Cu) + ((uint32)r_s16(table) << 2u), table);
        goto advance;
    case 5u:
        value = r_u32(0x800A6ED4u); w_u32(frame + 0x98u, value);
        result = sub_8004F394(child.caller_s6, child.caller_s7, 64u, result);
        switch (r_s16(frame + 0x40u))
        {
        case 7:
            child.caller_s1 = record;
            child.return_address = 0x8005041Cu;
            result = sub_800226E4(364u, &child); object = child.caller_s0 = result;
            child.caller_s2 = 0x800A8740u;
            index = 0u; do { w_u8(object + 56u + (uint32)(sint32)(sint16)index, 0u); ++index; } while ((uint16)index < 308u);
            w_u8(object + 34u, child.caller_s5);
            value = r_u16(r_u32(0x800A62ECu) + 8u); w_u32(object, 0x8004F2F8u); w_u16(object + 32u, value);
            child.return_address = 0x80050480u; sub_8004F340(object + 20u, child.caller_s1, &child);
            value = r_u16(object + 32u); value = r_u8(r_u32(0x800A8548u) + value);
            value = r_u16(r_u32(0x800A90ACu) + value * 40u + 32u);
            w_u32(object + 24u, r_u32(object + 24u) - (uint32)((sint32)(value << 16u) >> 17));
            if (r_u16(child.caller_s1 + 26u) >= 4u) w_u16(child.caller_s1 + 26u, child.caller_s4);
            value = ((uint32)r_s16(child.caller_s1 + 24u) << 2u) + (uint32)r_s16(child.caller_s1 + 26u);
            w_u16(object + 178u, r_u16(child.caller_s2 + (value << 1u) - 18u));
            value = r_u16(r_u32(0x800A62ECu) + 0x28u); w_u8(object + 338u, child.caller_s5); w_u16(object + 336u, value);
            child.return_address = 0x80050524u; sub_80022908(object, object + 324u, 1u);
            child.return_address = 0x8005052Cu; sub_8004ED64(object, &child);
            goto type5_bind;
        case 8: case 9:
            child.caller_s1 = record;
            child.return_address = 0x80050540u; result = sub_800226E4(300u, &child); object = child.caller_s0 = result;
            child.caller_s3 = 0x800A8740u;
            index = object + 56u;
            do { w_u8(index, 0u); ++index; child.caller_s2 = object + 20u; } while (index < object + 300u);
            w_u8(object + 34u, child.caller_s5);
            value = r_u16(0x800A5FF8u + ((uint32)r_s16(child.caller_s1 + 24u) << 1u));
            value = r_u16(r_u32(0x800A62ECu) + (value << 1u)); w_u32(object, 0x8004EC84u); w_u16(object + 32u, value);
            child.return_address = 0x800505B0u; sub_8004F340(child.caller_s2, child.caller_s1, &child);
            w_u32(object + 24u, r_u32(object + 24u) - 1200u);
            if (r_u16(child.caller_s1 + 26u) >= 4u) w_u16(child.caller_s1 + 26u, child.caller_s4);
            value = ((uint32)r_s16(child.caller_s1 + 24u) << 2u) + (uint32)r_s16(child.caller_s1 + 26u);
            w_u16(object + 178u, r_u16(child.caller_s3 + (value << 1u) - 18u));
            value = r_u16(r_u32(0x800A62ECu) + 0x24u); w_u8(object + 214u, child.caller_s5); w_u16(object + 212u, value);
            value = r_u16(r_u32(0x800A62ECu) + 0x26u); w_u8(object + 250u, child.caller_s5); w_u16(object + 248u, value);
            child.return_address = 0x8005062Cu; sub_80022908(object, object + 200u, 2u);
            child.return_address = 0x8005063Cu; result = sub_8002E310(child.caller_s2, frame + 0x68u, frame + 0x70u, &child);
            child.return_address = 0x8005064Cu; sub_8004E4F4(object, 0u - result - 1200u);
            child.return_address = 0x80050658u; sub_8004E6A4(object, 0u, &child);
            w_u32(object + 276u, 0u); goto type5_common;
        case 22: case 23: case 24:
            child.caller_s2 = record;
            child.return_address = 0x8005066Cu; result = sub_800226E4(572u, &child); object = child.caller_s0 = result;
            index = 0u; do { w_u8(object + 56u + (uint32)(sint32)(sint16)index, 0u); ++index; } while ((uint16)index < 516u);
            w_u8(object + 34u, child.caller_s5);
            signed_value = r_s16(child.caller_s2 + 24u); choice = 1u;
            if (signed_value == 23) choice = r_s16(child.caller_s2 + 28u) ? 5u : 3u;
            else if (signed_value == 24) choice = r_s16(child.caller_s2 + 28u) ? 6u : 4u;
            else if (signed_value == 22) choice = r_s16(child.caller_s2 + 28u) ? 2u : 1u;
            table = 0x800136E8u + choice * 10u;
            w_u16(object + 32u, r_u16(r_u32(0x800A62ECu) + (r_u8(table) << 1u)));
            index = 0u;
            do
            {
                value = r_u16(r_u32(0x800A62ECu) + (r_u8(table + index + 1u) << 1u));
                w_u8(object + index * 36u + 214u, child.caller_s5); w_u16(object + index * 36u + 212u, value); ++index;
            } while ((sint16)index < 9);
            child.return_address = 0x800507C0u; sub_80055A70(object + 540u, &child);
            value = r_u16(r_u32(0x800A62ECu) + 0xAAu); w_u8(object + 538u, child.caller_s5); w_u32(object, 0x8004E3F0u); w_u16(object + 536u, value);
            child.return_address = 0x800507ECu; sub_8004F340(object + 20u, child.caller_s2, &child);
            child.caller_s1 = object + 200u; w_u16(object + 564u, 6u);
            child.return_address = 0x80050808u; sub_80022908(object, child.caller_s1, 10u);
            if (r_u16(child.caller_s2 + 26u) >= 4u) w_u16(child.caller_s2 + 26u, child.caller_s4);
            value = (uint32)r_s16(object + 564u); value2 = (uint32)r_s16(object + 570u);
            w_u16(object + 178u, r_u16(0x800A61C0u + ((uint32)r_s16(child.caller_s2 + 26u) << 1u)));
            value = (uint32)r_s16(r_u32(0x8008FCFCu + (value << 2u)) + (value2 << 6u));
            w_u32(object + 24u, r_u32(object + 24u) - value);
            child.return_address = 0x80050878u; sub_80055D54(object, child.caller_s1, 0u, &child);
            w_u16(child.caller_s7 + 24u, 22u); goto type5_common;
        default:
            child.caller_s1 = record;
            child.return_address = 0x80050890u; result = sub_800226E4(328u, &child); object = child.caller_s0 = result;
            child.caller_s2 = 0x800A8740u;
            index = 0u; do { w_u8(object + 56u + (uint32)(sint32)(sint16)index, 0u); ++index; } while ((uint16)index < 272u);
            w_u8(object + 34u, child.caller_s5);
            if (r_s16(child.caller_s1 + 24u) == (sint32)child.caller_s4) w_u16(child.caller_s1 + 24u, 2u);
            value = r_u16(0x800A5FF8u + ((uint32)r_s16(child.caller_s1 + 24u) << 1u));
            value = r_u16(r_u32(0x800A62ECu) + (value << 1u)); w_u32(object, 0x8004D874u); w_u16(object + 32u, value);
            child.return_address = 0x80050924u; sub_8004F340(object + 20u, child.caller_s1, &child);
            value = r_u16(object + 32u); value = r_u8(r_u32(0x800A8548u) + value); value = r_u16(r_u32(0x800A90ACu) + value * 40u + 32u);
            w_u32(object + 24u, r_u32(object + 24u) - (uint32)((sint32)(value << 16u) >> 17));
            if (r_u16(child.caller_s1 + 26u) >= 4u) w_u16(child.caller_s1 + 26u, child.caller_s4);
            if (r_u32(0x800A9760u) != 0u && r_u32(0x800A9764u) == 4u) value = 0xFA00u;
            else { value = ((uint32)r_s16(child.caller_s1 + 24u) << 2u) + (uint32)r_s16(child.caller_s1 + 26u); value = r_u16(child.caller_s2 + (value << 1u) - 18u); }
            w_u16(object + 178u, value); w_u8(object + 324u, 255u); w_u32(object + 8u, 0u);
            if (r_u16(0x800A5FF8u + ((uint32)r_s16(child.caller_s1 + 24u) << 1u)) == 6u) w_u32(object + 8u, 255u);
 type5_bind:
            child.return_address = 0x80050A14u; sub_8002B198(object, object + 200u);
            goto type5_common;
        }
 type5_common:
        w_u32(r_u32(0x800A851Cu) + ((uint32)r_s16(frame + 0x34u) << 2u), object);
        w_u8(r_u32(0x800A7F08u) + (uint32)r_s16(frame + 0x34u), 5u);
        w_u8(object + 196u, r_u8(frame + 0x46u)); w_u8(object + 197u, r_u8(frame + 0x40u)); w_u16(object + 156u, r_u16(frame + 0x64u));
        value = r_u16(frame + 0x66u); w_u8(object + 65u, child.caller_s4); w_u8(object + 66u, child.caller_s4); w_u16(object + 158u, value); w_u16(object + 68u, r_u16(frame + 0x34u));
        if (r_s16(frame + 0x66u) == -1)
        {
            if (r_u8(frame + 0x51u)) w_u8(object + 66u, 0u);
            if (r_u8(frame + 0x55u)) w_u8(object + 14u, r_u8(object + 14u) | 2u);
            sub_80045280(object);
        }
        if (r_u8(frame + 0x50u)) w_u8(object + 14u, r_u8(object + 14u) | 8u);
        w_u16(object + 160u, r_u16(frame + 0x4Cu)); w_u16(object + 162u, r_u16(frame + 0x4Eu)); w_u8(object + 67u, r_u8(frame + 0x54u)); w_u16(object + 164u, r_u16(frame + 0x4Au));
        w_u16(object + 176u, (((uint32)r_s16(frame + 0x3Au) - 1u) << 8u) | 255u);
        value = r_u16(frame + 0x44u); w_u16(object + 56u, 2u); w_u16(object + 70u, value);
        w_u16(object + 58u, r_u16(frame + 0x36u)); w_u16(object + 166u, r_u16(frame + 0x36u));
        for (index = 0u; index < 4u; ++index) w_u16(object + 72u + index * 2u, r_u16(child.caller_s7 + 48u + index * 2u));
        w_u16(object + 170u, 5u); w_u8(object + 87u, child.caller_s4); w_u8(object + 198u, child.caller_s5); w_u8(object + 194u, 255u);
        w_u32(object + 148u, r_u32(r_u32(frame + 0x98u) + 20u));
        w_u8(object + 13u, child.caller_s5); w_u16(object + 70u, r_u16(frame + 0x44u));
        if (!r_s16(frame + 0x44u)) { w_u8(object + 13u, 7u); if (!r_u32(0x800A622Cu)) w_u32(0x800A622Cu, object); }
        value = r_u16(frame + 0x48u); w_u32(object + 144u, 0u); w_u16(object + 192u, value);
        if (r_s16(frame + 0x48u)) w_u32(object + 144u, r_u32(frame + 0x98u) + 64u);
        value = (90u - (uint32)r_s16(frame + 0x38u)) << 12u;
        w_u32(object + 16u, 0x80090A84u); w_u16(object + 182u, (uint32)((sint32)value / 360) & 0xFFFu);
        value = r_u32(object + 20u); value2 = r_u32(object + 24u); value3 = r_u32(object + 28u);
        w_u32(object + 116u, value); w_u32(object + 120u, value2); w_u32(object + 124u, value3);
        value = r_u32(object + 20u); value2 = r_u32(object + 24u); value3 = r_u32(object + 28u);
        w_u32(object + 128u, value); w_u32(object + 132u, value2); w_u32(object + 136u, value3);
        scene.stack_pointer = frame; scene.return_address = 0x80050CA8u; scene.caller_s0 = child.caller_s0;
        sub_80054D38(0u, (uint32)r_s16(object + 182u) + 2048u, 0u, object + 36u, &scene); child.caller_s0 = scene.caller_s0;
        if (r_s16(object + 164u) == -1) w_u16(object + 164u, 0u);
        if (r_s16(frame + 0x66u) == -1 && r_s16(frame + 0x40u) == 16)
        {
            w_u32(frame + 0x10u, 450u); w_u32(frame + 0x14u, 400u); value = (uint32)r_s16(object + 68u); w_u32(frame + 0x18u, value);
            child.return_address = 0x80050D04u; sub_800535DC(object, 1u, 167u, 500u, &child);
        }
        value = r_u16(frame + 0x48u); value2 = r_u32(0x800A622Cu);
        value = ((value & 1u) + (uint32)(sint32)(sint16)value) << 1u;
        w_u32(0x800A6ED4u, r_u32(0x800A6ED4u) + value);
        if (value2 == object && r_u32(0x800A8690u))
        {
            w_u32(0x800A9A58u, value2); child.return_address = 0x80050D5Cu; sub_8005BF3C(value2, &child);
        }
        goto advance;
    case 6u:
        table = r_u32(0x800A6ED4u); value = (uint32)r_s16(table); value2 = r_u16(table + 2u);
        w_u32(r_u32(0x800A851Cu) + (value << 2u), table);
        value2 = (uint32)(sint32)(sint16)((((value2 & 1u) + value2) << 1u) + 4u);
        value = (uint32)r_s16(table); value3 = r_u32(0x800A7F08u);
        w_u32(0x800A6ED4u, table + value2); w_u8(value3 + value, 6u); goto advance;
    case 7u:
        child.return_address = 0x80050DC0u; result = sub_800226E4(72u, &child); object = child.caller_s0 = result;
        result = sub_8004F394(child.caller_s6, record, 24u, result);
        w_u8(object + 14u, child.caller_s4); w_u32(object, 0x80047670u);
        value = r_u32(frame + 0x2Cu); value2 = r_u16(0x800A6EE4u); w_u32(object + 8u, value); w_u16(object + 56u, value2);
        w_u8(object + 67u, r_u8(frame + 0x37u)); value = r_u16(frame + 0x28u);
        w_u32(object + 52u, 0u); w_u8(object + 64u, 0u); w_u16(object + 68u, value);
        w_u16(object + 60u, r_u16(frame + 0x30u)); value = r_u16(frame + 0x32u);
        w_u8(object + 65u, child.caller_s4); w_u8(object + 66u, child.caller_s4); w_u16(object + 62u, value);
        if (r_u8(frame + 0x34u)) w_u8(object + 66u, 0u);
        w_u32(r_u32(0x800A851Cu) + ((uint32)r_s16(object + 68u) << 2u), object);
        w_u8(r_u32(0x800A7F08u) + (uint32)r_s16(object + 68u), 7u); goto advance;
    case 8u:
        result = sub_8004F394(child.caller_s6, record, 4u, result);
        value = (uint32)r_s16(frame + 0x28u); table = r_u32(0x800A6ED4u); value2 = table + (value << 3u);
        w_u32(0x800A6EECu, table); w_u32(0x800A6EE8u, value2); w_u32(0x800A6EF0u, value); w_u32(0x800A6ED4u, value2);
        if ((sint32)value > 0)
        {
            index = 0u;
            do
            {
                value2 = table + ((uint32)(sint32)(sint16)index << 3u);
                if ((r_u32(value2) & 0x3FFu) != 0u)
                {
                    value3 = r_u32(value2 + 4u); value2 = r_u32(0x800A6ED4u);
                    w_u32(0x800A6ED4u, value2 + ((value3 & 15u) << 2u));
                }
                ++index;
            } while ((sint32)(sint16)index < (sint32)value);
        }
        goto advance;
    case 9u:
        child.return_address = 0x80050F10u; result = sub_800226E4(72u, &child); object = child.caller_s0 = result;
        result = sub_8004F394(child.caller_s6, record, 8u, result);
        w_u8(object + 14u, child.caller_s4); w_u32(object, 0x80045F94u);
        value = r_u16(frame + 0x28u); w_u8(object + 64u, 0u); w_u16(object + 68u, value);
        value = r_u16(frame + 0x2Cu); w_u8(object + 65u, child.caller_s4); w_u16(object + 62u, value);
        w_u8(object + 66u, r_u8(frame + 0x2Au));
        w_u32(r_u32(0x800A851Cu) + ((uint32)r_s16(object + 68u) << 2u), object);
        w_u8(r_u32(0x800A7F08u) + (uint32)r_s16(object + 68u), 9u); goto advance;
    default:
        goto advance;
    }
advance:
    ++child.caller_fp;
    if ((sint32)(sint16)child.caller_fp < r_s16(0x800A7F3Cu)) goto next_record;
finish:
    value = (uint32)r_s16(0x800A6096u);
    child.caller_s0 = 1u;
    if (value == 0u)
    {
        child.return_address = 0x80050FC4u; result = sub_8004F47C(child.caller_s6, 0u, &child);
    }
    result = (uint32)r_s16(0x800A7F48u);
    w_u16(0x800A6096u, 0u); w_u32(0x800A7E18u, 0u);
    w_u16(0x800A6ED8u, child.caller_s0); w_u16(0x800A6EDAu, child.caller_s0); w_u16(0x800A6EDCu, child.caller_s0); w_u16(0x800A6EDEu, child.caller_s0);
    if (result != 0u)
    {
        child.return_address = 0x80050FF8u; result = sub_800226E4(72u, &child); object = result;
        w_u8(object + 14u, 1u); value = (uint32)r_s16(0x800A7F48u); value2 = r_u16(0x800A6EE4u);
        w_u32(0x800A9018u, object); w_u32(object + 52u, 1u); w_u8(object + 67u, 1u);
        if ((sint32)value < 0) value = 0u - value;
        w_u32(object + 8u, value); w_u16(object + 56u, value2);
        if (r_s16(0x800A7F48u) > 0) w_u16(object + 58u, 0u); else w_u16(object + 58u, child.caller_s0);
        value = r_u16(0x800A7F3Eu);
        w_u16(object + 60u, 0xFFFFu); w_u16(object + 62u, 0xFFFFu); w_u8(object + 65u, 1u);
        result = 0x80047670u; w_u8(object + 64u, 0u); w_u8(object + 66u, 0u); w_u32(object, result); w_u16(object + 68u, value + 1u);
    }
    else w_u32(0x800A9018u, 0u);
    context->return_address = r_u32(frame + 0xC4u);
    context->caller_fp = r_u32(frame + 0xC0u);
    context->caller_s7 = r_u32(frame + 0xBCu); context->caller_s6 = r_u32(frame + 0xB8u);
    context->caller_s5 = r_u32(frame + 0xB4u); context->caller_s4 = r_u32(frame + 0xB0u);
    context->caller_s3 = r_u32(frame + 0xACu); context->caller_s2 = r_u32(frame + 0xA8u);
    context->caller_s1 = r_u32(frame + 0xA4u); context->caller_s0 = r_u32(frame + 0xA0u);
    return result;
}

uint32 sub_8004F8E4(void)
{
    FUNCTION_MARKER(0x8004F8E4u, "1.EXE");
    w_u16(0x800A9D70u, 1u);
    w_u16(0x800A9014u, 1u);
    w_u16(0x800A6096u, 0u);
    w_u32(0x800A6098u, 0u);
    w_u32(0x800A609Cu, 0u);
    w_u32(0x800A60A0u, 0u);
    w_u32(0x800A60A4u, 0u);
    w_u16(0x800A9730u, 0u);
    w_u16(0x800A9A78u, 0u);
    w_u32(0x800A7E18u, 0u);
    w_u16(0x800A60A8u, 0u);
    w_u16(0x800A60ACu, 0u);
    w_u16(0x800A60AAu, 0u);
    w_u16(0x800A6094u, 0u);
    w_u32(0x800A7F14u, 0xA0000u);
    w_u32(0x800A6EE0u, 0xA0000u);
    return 0xA0000u;
}

uint32 sub_8004F394(uint32 unused, uint32 destination, uint32 count, uint32 incoming_v0)
{
    uint32 result = incoming_v0;
    FUNCTION_MARKER(0x8004F394u, "1.EXE");
    (void)unused;
    if ((sint32)count > 0)
    {
        uint32 end = destination + count;
        do
        {
            uint32 source = r_u32(0x800A6ED4u);
            w_u32(0x800A6ED4u, source + 1u);
            w_u8(destination, r_u8(source));
            ++destination;
            result = (sint32)destination < (sint32)end;
        } while (result != 0u);
    }
    return result;
}

uint32 sub_8004F47C(uint32 first_argument, uint32 second_argument, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x98u;
    uint32 object, cursor, end, source, destination, a, b, c, d, type;
    uint32 value, index, table, result, angle, high;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8004F47Cu, "1.EXE");
    w_u32(frame + 0x8Cu, context->caller_s1);
    child.caller_s1 = first_argument;
    w_u32(frame + 0x90u, context->caller_s2);
    child.caller_s2 = second_argument;
    w_u32(frame + 0x94u, context->return_address);
    w_u32(frame + 0x88u, context->caller_s0);
    child.stack_pointer = frame;
    child.return_address = 0x8004F4A0u;
    child.caller_s0 = sub_800226E4(648u, &child);
    object = child.caller_s0;
    cursor = object + 56u;
    end = object + 648u;
    do
    {
        w_u8(cursor, 0u);
        ++cursor;
    } while (cursor < end);
    w_u8(object + 34u, 8u);
    value = r_u16(0x800A6096u);
    w_u32(0x800A9A58u, object);
    w_u32(0x800A7BACu, object);
    destination = frame + 0x20u;
    if (value != 0u)
    {
        source = 0x800A602Cu;
        do
        {
            a = r_u32(source);
            b = r_u32(source + 4u);
            c = r_u32(source + 8u);
            d = r_u32(source + 12u);
            w_u32(destination, a);
            w_u32(destination + 4u, b);
            w_u32(destination + 8u, c);
            w_u32(destination + 12u, d);
            source += 16u;
            destination += 16u;
        } while (source != 0x800A608Cu);
        a = r_u32(source);
        b = r_u32(source + 4u);
        w_u32(destination, a);
        w_u32(destination + 4u, b);
    }
    else
    {
        first_argument = child.caller_s1;
        child.caller_s1 = r_u32(0x800A6ED4u);
        sub_8004F394(first_argument, frame + 0x20u, 104u, 0u);
        if (child.caller_s2 != 0u)
            w_u32(child.caller_s1 + 100u, 0u);
    }
    type = r_u16(frame + 0x74u);
    if ((sint16)type >= 7 && ((sint16)type < 10 || (sint16)type == 22))
        w_u16(frame + 0x74u, r_u16(0x800A6080u));
    if ((sint16)r_u16(frame + 0x74u) == 0)
        w_u16(frame + 0x74u, r_u16(0x800A6080u));
    if ((sint16)r_u16(frame + 0x74u) == 1)
        w_u32(object + 0x244u, (r_u32(object + 0x244u) & 0xF3FFFFFFu) | 0x04000000u);
    type = r_u16(frame + 0x74u);
    if (type - 1u < 24u)
    {
        index = r_u16(0x800A5FF8u + (uint32)((sint32)(type << 16) >> 15));
        table = r_u32(0x800A62ECu);
        a = r_u8(object + 14u);
        b = r_u16(table + (index << 1));
        w_u8(object + 14u, a | 2u);
        w_u16(object + 32u, b);
    }
    else
    {
        table = r_u32(0x800A62ECu);
        a = r_u8(object + 14u);
        b = r_u16(table + 0x1Au);
        w_u8(object + 14u, a | 2u);
        w_u16(object + 32u, b);
    }
    w_u8(object + 34u, 8u);
    value = r_u8(object + 14u);
    w_u8(object + 13u, 1u);
    w_u8(object + 14u, value | 8u);
    child.return_address = 0x8004F658u;
    sub_8004F340(object + 20u, frame + 0x20u, &child);
    object = child.caller_s0;
    index = r_u16(object + 32u);
    table = r_u32(0x800A8548u);
    index = r_u8(table + index);
    table = r_u32(0x800A90ACu);
    value = r_u16(table + index * 40u + 32u);
    a = r_u32(object + 24u);
    b = (uint32)((sint32)(value << 16) >> 17);
    w_u32(object + 24u, a - b);
    angle = (0u - (uint32)(sint32)(sint16)r_u16(frame + 0x30u) - 90u) << 12;
    high = (uint32)(((long long)(sint32)angle * (sint32)0xB60B60B7u) >> 32);
    value = (uint32)((sint32)(high + angle) >> 8) - (uint32)((sint32)angle >> 31);
    value = (value & 0xFFFu) << 16;
    high = (uint32)(((long long)(sint32)value * (sint32)0x0C907DA5u) >> 32);
    result = (uint32)((sint32)high >> 5) - (uint32)((sint32)value >> 31);
    w_u32(object + 0x204u, result);
    cursor = frame + 0x20u;
    destination = object;
    index = 0u;
    do
    {
        value = r_u16(cursor + 0x5Cu);
        cursor += 2u;
        ++index;
        w_u16(destination + 0x48u, value);
        destination += 2u;
    } while ((sint32)index < 4);
    value = r_u16(frame + 0x2Cu);
    w_u8(object + 0x41u, 1u);
    w_u8(object + 0x42u, 0u);
    w_u16(object + 0x44u, value);
    a = (uint32)(sint32)(sint16)r_u16(frame + 0x78u);
    b = r_u32(0x800A7E10u);
    value = a + b;
    w_u32(0x800A7E10u, value);
    if ((sint32)value >= 101)
        w_u32(0x800A7E10u, 100u);
    value = (uint32)(sint32)(sint16)r_u16(frame + 0x32u);
    if (value != 0u && r_u16(0x800A6096u) == 0u)
        value = ((value - 1u) << 8) | 255u;
    else
    {
        value = r_u16(0x800A603Eu);
        w_u16(frame + 0x32u, value);
        value = (uint32)(sint32)(sint16)value;
    }
    w_u32(0x800A8514u, value);
    value = (uint32)(sint32)(sint16)r_u16(0x800A603Au);
    a = r_u16(frame + 0x76u);
    w_u32(0x800A86A0u, value);
    if ((sint16)a == 0)
        w_u16(frame + 0x76u, r_u16(0x800A6082u));
    w_u16(object + 0x46u, 0u);
    a = r_u16(frame + 0x76u);
    b = r_u16(frame + 0x74u);
    w_u16(0x800A6082u, a);
    index = (uint32)(sint32)(sint16)r_u16(frame + 0x2Cu);
    w_u16(0x800A6080u, b);
    table = r_u32(0x800A851Cu);
    w_u32(table + (index << 2), object);
    index = (uint32)(sint32)(sint16)r_u16(frame + 0x2Cu);
    table = r_u32(0x800A7F08u);
    w_u16(0x800A6096u, 1u);
    w_u8(table + index, 1u);
    sub_80045280(object);
    sub_8003D324((uint32)(sint32)(sint16)r_u16(0x800A86A0u));
    sub_8003D27C((uint32)(sint32)(sint16)r_u16(0x800A8514u));
    sub_8003D694((uint32)(sint32)(sint16)(r_u16(frame + 0x76u) - 1u));
    child.return_address = 0x8004F860u;
    sub_8002912C(child.caller_s0, (uint32)(sint32)(sint16)r_u16(frame + 0x76u), &child);
    if (r_u32(0x800A8690u) == 0u)
    {
        child.return_address = 0x8004F87Cu;
        sub_8006E490(child.caller_s0, &child);
    }
    if ((sint16)r_u16(frame + 0x74u) == 16)
    {
        w_u32(frame + 0x10u, 450u);
        w_u32(frame + 0x14u, 400u);
        w_u32(frame + 0x18u, 0u);
        child.return_address = 0x8004F8B0u;
        sub_800535DC(child.caller_s0, 1u, 167u, 500u, &child);
    }
    child.return_address = 0x8004F8B8u;
    result = sub_8003D67C();
    w_u16(frame + 0x76u, result);
    sub_80044E68();
    child.return_address = 0x8004F8C8u;
    result = sub_8005BF3C(child.caller_s0, &child);
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->caller_fp = child.caller_fp;
    context->return_address = r_u32(frame + 0x94u);
    context->caller_s2 = r_u32(frame + 0x90u);
    context->caller_s1 = r_u32(frame + 0x8Cu);
    context->caller_s0 = r_u32(frame + 0x88u);
    return result;
}

uint32 sub_800226E4(uint32 size, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result, tail;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x800226E4u, "1.EXE");
    w_u32(frame + 0x10u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x800226F4u;
    result = sub_80064B04(size, &child);
    w_u8(result + 0xFu, 0u);
    w_u8(result + 0xEu, 1u);
    w_u8(result + 0x23u, 0u);
    tail = r_u32(0x800A567Cu);
    if (tail != 0u)
        w_u32(tail + 4u, result);
    else
        w_u32(0x800A5678u, result);
    w_u32(0x800A567Cu, result);
    w_u32(result + 4u, 0u);
    context->caller_s0 = child.caller_s0;
    context->caller_s1 = child.caller_s1;
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->caller_fp = child.caller_fp;
    context->return_address = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8004F340(uint32 destination, uint32 source, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8004F340u, "1.EXE");
    w_u32(frame + 0x20u, context->caller_s0);
    child.caller_s0 = destination;
    w_u32(frame + 0x24u, context->return_address);
    w_u32(destination, r_u32(source));
    w_u32(destination + 8u, r_u32(source + 8u));
    w_u32(destination + 4u, (uint32)(sint32)(sint16)r_u16(source + 4u));
    child.stack_pointer = frame;
    child.return_address = 0x8004F378u;
    result = 0u - sub_8002E310(destination, frame + 0x10u, frame + 0x18u, &child);
    w_u32(child.caller_s0 + 4u, result);
    context->caller_s1 = child.caller_s1;
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->caller_fp = child.caller_fp;
    context->return_address = r_u32(frame + 0x24u);
    context->caller_s0 = r_u32(frame + 0x20u);
    return result;
}

uint32 sub_8002E310(uint32 position, uint32 normal_output, uint32 tag_output, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 x, z, origin_x, origin_z, start, row, layer, flags;
    uint32 table, candidate, faces, cursor, face_flag, face_offset, face;
    uint32 x0, x1, x2, x3, z0, z1, z2, z3, result = 0u;
    uint32 numerator, value, first_product, second_product;
    sint32 divisor;
    FUNCTION_MARKER(0x8002E310u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s4);
    w_u32(frame + 0x18u, context->caller_s6);
    w_u32(frame + 0x20u, context->caller_fp);
    w_u32(frame, context->caller_s0);
    w_u32(frame + 0x1Cu, context->caller_s7);
    w_u32(frame + 0x14u, context->caller_s5);
    w_u32(frame + 0xCu, context->caller_s3);
    w_u32(frame + 8u, context->caller_s2);
    w_u32(frame + 4u, context->caller_s1);
    x = r_u32(position);
    z = r_u32(position + 8u);
    origin_x = x & 0xFFFFF000u;
    origin_z = z & 0xFFFFF000u;
    value = ((uint32)((sint32)z >> 12) * 80u + (uint32)((sint32)x >> 12)) << 3;
    start = r_u16(r_u32(0x800A84F8u) + value + 4u);
    row = start;
    layer = 0u;
next_layer:
    value = layer * 3u + start;
    numerator = 0u - r_u32(position + 4u);
    table = r_u32(0x800A869Cu);
select_layer:
    flags = r_u16(table + (value << 1));
    if ((sint32)numerator >= (sint32)((flags & 0x7FFFu) << 1) || (flags & 0x8000u) != 0u)
        goto selected;
    value += 3u;
    row += 3u;
    ++layer;
    goto select_layer;
selected:
    table = r_u32(0x800A869Cu);
    candidate = r_u16(table + (row << 1) + 4u);
    if (candidate == 0xFFFFu)
        goto no_face;
    faces = r_u32(0x800A9CE8u);
    x = r_u32(position);
    cursor = r_u32(0x800A9CE4u) + (candidate << 1);
    z = r_u32(position + 8u);
next_face:
    face_flag = r_u16(cursor);
    face_offset = (face_flag & 0x7FFFu) * 28u;
    face = faces + face_offset;
    z0 = (uint32)(sint32)(sint16)r_u16(face + 4u) + origin_z;
    z1 = (uint32)(sint32)(sint16)r_u16(face + 8u) + origin_z;
    x1 = (uint32)(sint32)(sint16)r_u16(face + 6u) + origin_x;
    x0 = (uint32)(sint32)(sint16)r_u16(face) + origin_x;
    value = (z0 - z1) * (x - x1) + (x1 - x0) * (z - z1);
    cursor += 2u;
    if ((sint32)value < 0)
        goto rejected_face;
    z2 = (uint32)(sint32)(sint16)r_u16(face + 0xCu) + origin_z;
    x2 = (uint32)(sint32)(sint16)r_u16(face + 0xAu) + origin_x;
    value = (z1 - z2) * (x - x2) + (x2 - x1) * (z - z2);
    if ((sint32)value < 0)
        goto rejected_face;
    z3 = (uint32)(sint32)(sint16)r_u16(face + 0x10u) + origin_z;
    x3 = (uint32)(sint32)(sint16)r_u16(face + 0xEu) + origin_x;
    value = (z2 - z3) * (x - x3) + (x3 - x2) * (z - z3);
    if ((sint32)value < 0)
        goto rejected_face;
    value = (z3 - z0) * (x - x0) + (x0 - x3) * (z - z0);
    if ((sint32)value >= 0)
        goto found_face;
rejected_face:
    if ((face_flag & 0x8000u) == 0u)
        goto next_face;
no_face:
    if ((flags & 0x8000u) != 0u)
    {
        result = 0u;
        goto finish;
    }
    row += 3u;
    ++layer;
    goto next_layer;
found_face:
    w_u16(tag_output, r_u16(face + 0x18u));
    face = face_offset + r_u32(0x800A9CE8u);
    w_u16(normal_output, r_u16(face + 0x12u));
    w_u16(normal_output + 2u, r_u16(face + 0x14u));
    w_u16(normal_output + 4u, r_u16(face + 0x16u));
    value = r_u32(position);
    x0 = (uint32)(sint32)(sint16)r_u16(face);
    x1 = (uint32)(sint32)(sint16)r_u16(face + 0x12u);
    first_product = x1 * (value - origin_x - x0);
    z1 = (uint32)(sint32)(sint16)r_u16(face + 0x16u);
    value = r_u32(position + 8u);
    z0 = (uint32)(sint32)(sint16)r_u16(face + 4u);
    second_product = z1 * (value - origin_z - z0);
    divisor = (sint16)r_u16(face + 0x14u);
    numerator = 0u - first_product - second_product;
    if (divisor == 0)
        xport_mips_break(7u);
    if (divisor == -1 && numerator == 0x80000000u)
        xport_mips_break(6u);
    result = (uint32)((sint32)numerator / divisor);
    result += (uint32)(sint32)(sint16)r_u16(face + 2u);
finish:
    context->caller_fp = r_u32(frame + 0x20u);
    context->caller_s7 = r_u32(frame + 0x1Cu);
    context->caller_s6 = r_u32(frame + 0x18u);
    context->caller_s5 = r_u32(frame + 0x14u);
    context->caller_s4 = r_u32(frame + 0x10u);
    context->caller_s3 = r_u32(frame + 0xCu);
    context->caller_s2 = r_u32(frame + 0x8u);
    context->caller_s1 = r_u32(frame + 0x4u);
    context->caller_s0 = r_u32(frame + 0x0u);
    return result;
}

uint32 sub_80045280(uint32 object)
{
    sint32 count = (sint16)r_u16(0x800A6094u);
    uint32 result = count < 128;
    FUNCTION_MARKER(0x80045280u, "1.EXE");
    if (result != 0u)
    {
        result = (uint32)count << 2;
        w_u32(0x800A8930u + result, object);
        w_u16(0x800A6094u, (uint32)count + 1u);
    }
    return result;
}

void sub_8003D324(uint32 value)
{
    FUNCTION_MARKER(0x8003D324u, "1.EXE");
    w_u16(0x800A5EF0u, (uint16)value);
}

void sub_8003D27C(uint32 value)
{
    FUNCTION_MARKER(0x8003D27Cu, "1.EXE");
    w_u16(0x800A5EEEu, (uint16)value);
}

void sub_8003D694(uint32 value)
{
    FUNCTION_MARKER(0x8003D694u, "1.EXE");
    w_u16(0x800A5EF4u, (uint16)value);
}

uint32 sub_8002912C(uint32 object, uint32 mode, GameGeometryCallContext *context)
{
    FUNCTION_MARKER(0x8002912Cu, "1.EXE");
    uint32 frame = context->stack_pointer - 0x28u;
    GameGeometryCallContext child = *context;
    w_u32(frame + 0x18u, context->caller_s0);
    child.caller_s0 = object;
    w_u32(0x800A56C0u, 60u);
    w_u32(frame + 0x20u, context->return_address);
    w_u32(frame + 0x1Cu, context->caller_s1);
    w_u32(object, 0x800290B8u);
    w_u32(object + 0x10u, 0x8008B858u);
    uint32 index = r_u16(object + 0x20u);
    uint32 table = r_u32(0x800A8548u);
    child.caller_s1 = mode;
    w_u16(object + 0x38u, 0u);
    uint32 entry = r_u8(table + index);
    uint32 first = r_u32(0x800A90ACu);
    w_u32(frame + 0x10u, 0xB333u);
    uint32 offset = ((entry << 2) + entry) << 3;
    uint32 second = r_u32(0x800A9750u);
    child.stack_pointer = frame;
    child.return_address = 0x800291B4u;
    sub_80029C80(first + offset, second + offset, 0xCCCCu, 0x10000u, frame);
    object = child.caller_s0;
    index = r_u16(object + 0x20u);
    table = r_u32(0x800A8548u);
    uint32 index_again = r_u16(object + 0x20u);
    uint32 selected = r_u8(table + index);
    w_u32(object + 0x224u, 0x10000u);
    entry = r_u8(table + index_again);
    offset = ((entry << 2) + entry) << 3;
    table = r_u32(0x800A9750u);
    uint32 value = r_u16(table + offset + 0x22u);
    value = (uint32)((sint32)(value << 16) >> 24);
    uint32 v3 = (value << 2) + value;
    value = (uint32)((sint32)(v3 << 24) >> 8);
    uint32 product = (uint32)((sint64)(sint32)value * 110);
    w_u32(object + 0x1FCu, v3 << 8);
    v3 = r_u32(object + 0x1FCu);
    value = (uint32)((sint32)product >> 16);
    v3 -= value;
    w_u32(object + 0x20Cu, value);
    w_u32(object + 0x210u, v3);
    offset = ((selected << 2) + selected) << 3;
    table = r_u32(0x800A90ACu);
    value = (uint32)(sint32)(sint16)r_u16(table + offset + 0x24u);
    uint32 square = (uint32)((sint64)(sint32)value * (sint32)value);
    value = r_u32(object + 0x1FCu);
    square += (uint32)((sint64)(sint32)value * (sint32)value);
    sint64 full_product = (sint64)(sint32)square * (sint32)0xA0A0A0A1u;
    value = (uint32)((uint64)full_product >> 32);
    value += square;
    value = (uint32)((sint32)value >> 10) - (uint32)((sint32)square >> 31);
    w_u32(object + 0x200u, value);
    child.return_address = 0x800292A8u;
    sub_8002B198(object, object + 0x58u);
    object = child.caller_s0;
    for (uint32 i = 0u; i < 4u; ++i)
    {
        w_u8(object + i * 0x24u + 0x10Eu, 11u);
        table = r_u32(0x800A62ECu);
        value = r_u16(table + 0x1Cu);
        w_u16(object + i * 0x24u + 0x10Cu, (uint16)value);
    }
    first = r_u32(object + 0x14u);
    second = r_u32(object + 0x18u);
    uint32 third = r_u32(object + 0x1Cu);
    w_u32(object + 0xE8u, first);
    w_u32(object + 0xECu, second);
    w_u32(object + 0xF0u, third);
    first = r_u32(object + 0x14u);
    second = r_u32(object + 0x18u);
    third = r_u32(object + 0x1Cu);
    w_u32(object + 0xF4u, first);
    w_u32(object + 0xF8u, second);
    w_u32(object + 0xFCu, third);
    w_u8(object + 0x244u, 1u);
    w_u32(object + 0x1F4u, 0x10000u);
    w_u8(0x800A7E30u, 0u);
    value = (uint32)(sint32)(sint16)(uint16)sub_8003D654();
    v3 = (value << 3) + value;
    v3 = (v3 << 3) - value;
    v3 = (v3 << 3) + value;
    v3 = (v3 << 3) - value;
    v3 <<= 2;
    w_u32(0x800A8538u, v3);
    for (uint32 i = 0u; i < 2u; ++i)
    {
        w_u8(object + i * 0x24u + 0x19Eu, 8u);
        table = r_u32(0x800A62ECu);
        value = r_u16(table + 0x150u);
        w_u16(object + i * 0x24u + 0x19Cu, (uint16)value);
    }
    child.return_address = 0x800293B8u;
    sub_80022908(object, object + 0x100u, 6u);
    object = child.caller_s0;
    w_u16(object + 0x23Eu, 0x4000u);
    w_u16(object + 0x242u, 0x4000u);
    w_u16(0x800A6C04u, 0u);
    w_u16(0x800A6C06u, 0u);
    w_u16(0x800A8704u, 0u);
    w_u16(0x800A8706u, 0u);
    v3 = r_u32(object + 0x204u);
    w_u16(0x800A56A4u, 0u);
    w_u32(0x800A569Cu, 0u);
    w_u16(0x800A56A0u, 0u);
    w_u16(0x800A56A2u, 0u);
    w_u32(0x800A56A8u, 0u);
    w_u16(0x800A56B4u, 0xFFFFu);
    w_u16(0x800A56B6u, 0u);
    w_u32(0x800A56BCu, 0u);
    value = ((v3 << 2) + v3) << 3;
    value = ((value + v3) << 2) - v3;
    v3 = r_u16(0x800A86A0u);
    value >>= 14;
    w_u16(object + 0x230u, (uint16)value);
    w_u16(0x800A632Cu, (uint16)value);
    w_u16(object + 0x3Au, (uint16)v3);
    first = r_u32(object + 0xF4u);
    second = r_u32(object + 0xF8u);
    third = r_u32(object + 0xFCu);
    w_u32(0x800A6C08u, first);
    w_u32(0x800A6C0Cu, second);
    w_u32(0x800A6C10u, third);
    value = r_u32(object + 0x244u);
    w_u32(0x800A5754u, 0u);
    w_u32(0x800A56C8u, (value & 0x0C000000u) != 0u ? 1u : 0u);
    if (r_u32(0x800A8690u) != 0u)
    {
        w_u8(object + 0xEu, 1u);
        w_u32(object, 0x80029968u);
        w_u32(0x800A56C8u, 0u);
    }
    table = r_u32(0x800A62ECu);
    index = r_u16(object + 0x20u);
    value = (uint32)(sint32)(sint16)r_u16(table + 0x1Au);
    if (index == value)
    {
        child.return_address = 0x800294CCu;
        sub_80063888(object, &child);
    }
    object = child.caller_s0;
    if (r_u32(0x800A9760u) == 1u)
    {
        value = r_u32(0x800A9764u) == 4u ? 0x215520u : 0x378DE0u;
        w_u32(0x800A8538u, value);
        w_u32(object + 0x228u, 0u);
    }
    uint32 result = r_u32(0x800A8538u);
    w_u32(0x800A56C4u, result);
    child.return_address = r_u32(frame + 0x20u);
    child.caller_s1 = r_u32(frame + 0x1Cu);
    child.caller_s0 = r_u32(frame + 0x18u);
    child.stack_pointer = context->stack_pointer;
    *context = child;
    return result;
}

uint32 sub_8002B198(uint32 source, uint32 destination)
{
    FUNCTION_MARKER(0x8002B198u, "1.EXE");
    uint32 index = 4u;
    do
    {
        --index;
        uint32 entry = destination + ((uint32)(sint32)(sint16)index << 4u);
        uint32 value = r_u16(source + 0x18u);
        uint32 flags = r_u32(entry + 0xCu);
        w_u16(entry + 8u, 0x1FFFu);
        w_u16(entry + 6u, 0u);
        w_u16(entry + 2u, (uint16)value);
        w_u16(entry, (uint16)value);
        w_u16(entry + 4u, (uint16)value);
        uint32 packed = r_u32(entry + 8u);
        w_u32(entry + 0xCu, flags & 0xF0000000u);
        w_u32(entry + 8u, packed & 0xFFF0FFFFu);
    } while ((sint16)index > 0);
    w_u8(destination + 0x43u, 1u);
    w_u8(destination + 0x42u, 0u);
    w_u16(destination + 0x40u, r_u16(source + 0x18u));
    uint32 result = r_u32(source + 0x18u);
    w_u32(destination + 0x44u, result);
    return result;
}

uint32 sub_8003D654(void)
{
    FUNCTION_MARKER(0x8003D654u, "1.EXE");
    uint32 index = (uint32)(sint32)(sint16)r_u16(0x800A5EF4u);
    uint32 offset = ((index << 1) + index) << 1;
    return (uint32)(sint32)(sint16)r_u16(0x800901A0u + offset);
}

uint32 sub_80022908(uint32 object, uint32 entries, uint32 count)
{
    FUNCTION_MARKER(0x80022908u, "1.EXE");
    uint32 packed = r_u32(object + 8u) & 0xFFFFF000u;
    packed |= (entries - object) & 0xFFFu;
    packed &= 0xFFFF0FFFu;
    packed |= (count & 0xFu) << 12u;
    uint32 result = r_u8(object + 0xEu);
    packed &= 0x0FFFFFFFu;
    w_u32(object + 8u, packed);
    result |= 0x80u;
    w_u8(object + 0xEu, (uint8)result);
    if ((sint32)count > 0)
    {
        uint32 index = 0u;
        do
        {
            w_u8(entries + 0xFu, 0u);
            ++index;
            result = (sint32)index < (sint32)count ? 1u : 0u;
            entries += 0x24u;
        } while (result != 0u);
    }
    return result;
}

#include "game_scene.h"
uint32 sub_80069BE0(uint32 first, uint32 second);
uint32 sub_80055764(uint32 current, uint32 target, uint32 step);
uint32 sub_80054D38(uint32 x, uint32 y, uint32 z, uint32 matrix, GameSceneCallContext *context);
void sub_80031CE8(uint32 matrix, uint32 translation, uint32 vector, uint32 destination);
uint32 sub_800551CC(uint32 angle, uint32 matrix);
uint32 sub_80031A54(uint32 source, uint32 destination);
void sub_80031CC0(uint32 source, uint32 destination);
uint32 sub_80055168(uint32 angle, uint32 matrix);
uint32 sub_8004E6A4(uint32 object, uint32 angle, GameGeometryCallContext *context);
void sub_80031CC0(uint32 source, uint32 destination);
uint32 sub_80055168(uint32 angle, uint32 matrix);
uint32 sub_80037150(GameGeometryCallContext *context);
uint32 sub_800551CC(uint32 angle, uint32 matrix);
void sub_80031CE8(uint32 matrix, uint32 translation, uint32 vector, uint32 destination);
uint32 sub_8005B2AC(uint32 first, uint32 second, uint32 destination);
uint32 sub_80069BE0(uint32 first, uint32 second);
uint32 sub_8005B70C(uint32 position, GameGeometryCallContext *context);
uint32 sub_8005B2AC(uint32 first, uint32 second, uint32 destination);
uint32 sub_80069BE0(uint32 first, uint32 second);
void sub_80031CE8(uint32 matrix, uint32 translation, uint32 vector, uint32 destination);
uint32 sub_8005BF3C(uint32 object, GameGeometryCallContext *context);
void xport_gte_mvmva(uint32 command);
uint32 sub_8005B70C(uint32 source, uint32 entry_sp);
uint32 sub_8004E4F4(uint32 object, uint32 height);
uint32 sub_80055764(uint32 current, uint32 target, uint32 step);
uint32 sub_80031A54(uint32 source, uint32 destination);
uint32 sub_80064B04(uint32 size, GameGeometryCallContext *context);
uint32 sub_80022744(uint32 size, uint32 owner, GameGeometryCallContext *context);
uint32 sub_80022744(uint32 size, uint32 owner, GameGeometryCallContext *context);
uint32 sub_80063888(uint32 object, GameGeometryCallContext *context);
uint32 sub_8003D67C(void);
uint32 sub_80044E68(void);

uint32 sub_80063888(uint32 object, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result, value;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80063888u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    child.caller_s0 = object;
    w_u32(frame + 0x14u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x800638A4u;
    result = sub_80022744(56u, child.caller_s0, &child);
    w_u8(result + 34u, 9u);
    w_u16(result + 32u, r_u16(r_u32(0x800A62ECu) + 0x1B4u));
    w_u32(result + 20u, r_u32(child.caller_s0 + 20u));
    w_u32(result + 24u, r_u32(child.caller_s0 + 24u));
    value = r_u32(child.caller_s0 + 28u);
    w_u32(result, 0x80063904u);
    w_u32(result + 28u, value);
    context->caller_s1 = child.caller_s1; context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3; context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5; context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7; context->caller_fp = child.caller_fp;
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_80022744(uint32 size, uint32 owner, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x18u;
    uint32 result, previous;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x80022744u, "1.EXE");
    w_u32(frame + 0x10u, context->caller_s0);
    w_u32(frame + 0x14u, context->return_address);
    child.stack_pointer = frame;
    child.return_address = 0x80022758u;
    child.caller_s0 = owner;
    result = sub_80064B04(size, &child);
    w_u32(result + 8u, child.caller_s0);
    w_u8(child.caller_s0 + 15u, r_u8(child.caller_s0 + 15u) + 1u);
    w_u8(result + 14u, 1u);
    w_u8(result + 35u, 0u);
    w_u8(result + 15u, 128u);
    previous = r_u32(0x800A567Cu);
    if (previous != 0u) w_u32(previous + 4u, result);
    else w_u32(0x800A5678u, result);
    w_u32(0x800A567Cu, result);
    w_u32(result + 4u, 0u);
    context->caller_s1 = child.caller_s1; context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3; context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5; context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7; context->caller_fp = child.caller_fp;
    context->return_address = r_u32(frame + 0x14u);
    context->caller_s0 = r_u32(frame + 0x10u);
    return result;
}

uint32 sub_8003D67C(void)
{
    FUNCTION_MARKER(0x8003D67Cu, "1.EXE");
    return (uint32)r_s16(0x800A5EF4u);
}

uint32 sub_80044E68(void)
{
    uint32 source, x, y, z, value, result, first, second, third, fourth;
    uint32 pointer = 0x800A608Eu;
    sint32 counter = 3;
    FUNCTION_MARKER(0x80044E68u, "1.EXE");
    source = r_u32(0x800A7BACu);
    x = r_u32(source + 20u); y = r_u32(source + 24u); z = r_u32(source + 28u);
    w_u32(0x800A602Cu, x); w_u32(0x800A6030u, y); w_u32(0x800A6034u, z);
    source = r_u32(0x800A7BACu);
    w_u16(0x800A6038u, 0u); w_u8(0x800A6086u, 1u);
    value = r_u32(source + 516u) * 652u;
    value = (uint32)((sint32)value >> 16);
    value *= 360u;
    if ((sint32)value < 0) value += 4095u;
    value = (uint32)((sint32)value >> 12) + 90u;
    first = r_u16(0x800A7E10u); second = r_u16(0x800A8514u);
    third = r_u16(0x800A86A0u); fourth = r_u32(0x800A7C6Cu);
    result = 0u - value;
    w_u16(0x800A603Cu, result); w_u16(0x800A6084u, first);
    w_u16(0x800A603Eu, second); w_u16(0x800A603Au, third);
    w_u32(0x800A6090u, fourth);
    do { w_u16(pointer, 0xFFFFu); --counter; pointer -= 2u; } while (counter >= 0);
    return result;
}

uint32 sub_8005BF3C(uint32 object, GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x48u;
    uint32 a, b, c, d, e, f, result, angle;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8005BF3Cu, "1.EXE");
    w_u32(frame + 0x3Cu, context->caller_s1);
    child.caller_s1 = object;
    w_u32(frame + 0x38u, context->caller_s0);
    child.caller_s0 = frame + 0x20u;
    angle = (uint32)(sint32)(sint16)r_u16(0x800A632Cu);
    w_u32(frame + 0x40u, context->return_address);
    sub_800551CC(angle, child.caller_s0);
    a = child.caller_s0;
    child.caller_s1 += 20u;
    child.caller_s0 = 0x800A7E54u;
    sub_80031CE8(a, child.caller_s1, 0x800A7E70u, child.caller_s0);
    a = r_u32(0x800A7E54u);
    b = r_u32(0x800A7E58u);
    c = r_u32(0x800A7E5Cu);
    d = (uint32)(sint32)(sint16)r_u16(0x800A7E60u);
    e = (uint32)(sint32)(sint16)r_u16(0x800A7E62u);
    f = (uint32)(sint32)(sint16)r_u16(0x800A7E64u);
    w_u32(0x800A7EE4u, a);
    w_u32(0x800A7EE8u, b);
    w_u32(0x800A7EECu, c);
    w_u32(0x800A7ED4u, d);
    w_u32(0x800A7ED8u, e);
    w_u32(0x800A7EDCu, f);
    sub_8005B2AC(child.caller_s1, child.caller_s0, frame + 0x10u);
    a = r_u32(frame + 0x10u);
    b = r_u32(frame + 0x18u);
    child.caller_s0 = r_u32(frame + 0x14u);
    result = sub_80069BE0(a, b);
    result = sub_80069BE0(result, child.caller_s0);
    angle = r_u16(0x800A632Cu);
    b = r_u32(0x800A7EE8u);
    w_u16(0x800A7ED0u, result);
    w_u16(0x800A7E7Au, 10000u);
    w_u16(0x800A8564u, 0u);
    w_u16(0x800A8566u, 0u);
    w_u16(0x800A7ECAu, angle);
    w_u16(0x800A7E7Cu, angle);
    w_u32(0x800A84E8u, b);
    child.stack_pointer = frame;
    child.return_address = 0x8005C05Cu;
    result = sub_8005B70C(child.caller_s1, &child);
    context->caller_s2 = child.caller_s2;
    context->caller_s3 = child.caller_s3;
    context->caller_s4 = child.caller_s4;
    context->caller_s5 = child.caller_s5;
    context->caller_s6 = child.caller_s6;
    context->caller_s7 = child.caller_s7;
    context->caller_fp = child.caller_fp;
    context->return_address = r_u32(frame + 0x40u);
    context->caller_s1 = r_u32(frame + 0x3Cu);
    context->caller_s0 = r_u32(frame + 0x38u);
    return result;
}

void sub_80031CE8(uint32 matrix, uint32 translation, uint32 vector, uint32 destination)
{
    uint32 first, second, third;
    FUNCTION_MARKER(0x80031CE8u, "1.EXE");
    first = r_u32(matrix);
    second = r_u32(matrix + 4u);
    xport_gte_write_control(0u, first);
    xport_gte_write_control(1u, second);
    first = r_u32(matrix + 8u);
    second = r_u32(matrix + 12u);
    third = r_u32(matrix + 16u);
    xport_gte_write_control(2u, first);
    xport_gte_write_control(3u, second);
    xport_gte_write_control(4u, third);
    first = r_u32(translation);
    second = r_u32(translation + 4u);
    third = r_u32(translation + 8u);
    xport_gte_write_control(5u, first);
    xport_gte_write_control(6u, second);
    xport_gte_write_control(7u, third);
    xport_gte_write_data(0u, r_u32(vector));
    xport_gte_write_data(1u, r_u32(vector + 4u));
    xport_gte_mvmva(0x480012u);
    w_u32(destination, xport_gte_read_data(25u));
    w_u32(destination + 4u, xport_gte_read_data(26u));
    w_u32(destination + 8u, xport_gte_read_data(27u));
}

uint32 sub_8005B2AC(uint32 first, uint32 second, uint32 destination)
{
    uint32 a, b, result;
    FUNCTION_MARKER(0x8005B2ACu, "1.EXE");
    a = r_u32(first);
    b = r_u32(second);
    w_u32(destination, a - b);
    a = r_u32(first + 4u);
    b = r_u32(second + 4u);
    w_u32(destination + 4u, a - b);
    a = r_u32(first + 8u);
    b = r_u32(second + 8u);
    result = a - b;
    w_u32(destination + 8u, result);
    return result;
}

uint32 sub_80069BE0(uint32 first, uint32 second)
{
    uint32 temporary, numerator, quotient, factor, product;
    FUNCTION_MARKER(0x80069BE0u, "1.EXE");
    if ((sint32)first < 0)
        first = 0u - first;
    if ((sint32)second < 0)
        second = 0u - second;
    temporary = first;
    if ((sint32)second < (sint32)first)
    {
        first = second;
        second = temporary;
    }
    numerator = first << 9;
    if (second == 0u)
        return first;
    if (second == 0xFFFFFFFFu && numerator == 0x80000000u)
        xport_mips_break(6u);
    quotient = (uint32)((sint32)numerator / (sint32)second);
    factor = r_u16(0x80091178u + (quotient << 1));
    product = second * factor;
    return second + (uint32)((sint32)product >> 16);
}

uint32 sub_8005B70C(uint32 source, uint32 entry_sp)
{
    FUNCTION_MARKER(0x8005B70Cu, "1.EXE");
    uint32 first = r_u32(source);
    uint32 baseline = r_u32(0x800A7EE4u);
    uint32 frame = entry_sp - 0x10u;
    first -= baseline;
    w_u32(frame, first);
    uint32 second = r_u32(source + 4u);
    baseline = r_u32(0x800A7EE8u);
    second -= baseline;
    w_u32(frame + 4u, second);
    uint32 result = r_u32(source + 8u);
    baseline = r_u32(0x800A7EECu);
    w_u32(0x800A8554u, first);
    w_u32(0x800A8558u, second);
    result -= baseline;
    w_u32(frame + 8u, result);
    w_u32(0x800A855Cu, result);
    return result;
}

uint32 sub_8004E4F4(uint32 object, uint32 height)
{
    FUNCTION_MARKER(0x8004E4F4u, "1.EXE");
    uint32 value = r_u32(object + 0x18u) << 10;
    w_u32(object + 0x118u, value);
    uint32 result = r_u32(object + 0x118u);
    height <<= 10;
    w_u32(object + 0x11Cu, 0u);
    w_u16(object + 0x128u, 0u);
    w_u32(object + 0x124u, height);
    height = (uint32)((sint32)(height - result + 0x200u) >> 10);
    if ((sint32)height < 0)
        height = 0u - height;
    w_u32(object + 0x120u, height << 2);
    return result;
}

uint32 sub_8004E6A4(uint32 object, uint32 angle, GameGeometryCallContext *context)
{
    FUNCTION_MARKER(0x8004E6A4u, "1.EXE");
    uint32 frame = context->stack_pointer - 0x28u;
    w_u32(frame + 0x20u, context->caller_s2);
    w_u32(frame + 0x24u, context->return_address);
    w_u32(frame + 0x1Cu, context->caller_s1);
    w_u32(frame + 0x18u, context->caller_s0);
    uint32 difference = (r_u16(object + 0xB6u) - angle) & 0xFFFu;
    if (difference >= 0x801u)
        difference |= 0xF000u;
    uint32 first = r_u32(object + 0x64u);
    uint32 second = r_u32(object + 0x68u);
    uint32 distance = sub_80069BE0(first, second);
    uint32 result = sub_80055764((uint32)r_s16(object + 0xBAu), distance >> 6u, 4u);
    uint32 target = 0u - (uint32)(sint32)(sint16)difference;
    target += target << 1u;
    uint32 current = (uint32)r_s16(object + 0xB8u);
    w_u16(object + 0xBAu, (uint16)result);
    result = sub_80055764(current, target, 4u);
    uint32 z = (uint32)(sint32)(sint16)result;
    uint32 x = (uint32)r_s16(object + 0xBAu);
    uint32 y = (uint32)r_s16(object + 0xB6u);
    w_u16(object + 0xB8u, (uint16)result);
    GameSceneCallContext scene;
    scene.stack_pointer = frame;
    scene.return_address = 0x8004E744u;
    scene.caller_s0 = object + 0x24u;
    sub_80054D38(x, y + 0x800u, z, object + 0x24u, &scene);
    uint32 packed_xy = r_u32(0x800A6148u);
    uint32 packed_z = r_u32(0x800A614Cu);
    w_u32(frame + 0x10u, packed_xy);
    w_u32(frame + 0x14u, packed_z);
    sub_80031CE8(object + 0x24u, object + 0x14u, frame + 0x10u, object + 0xC8u);
    uint32 rotated_angle = r_u16(object + 0x110u) - 0x200u;
    w_u16(object + 0x110u, (uint16)rotated_angle);
    sub_800551CC((uint32)(sint32)(sint16)rotated_angle, object + 0xD8u);
    sub_80031A54(object + 0xD8u, object + 0xD8u);
    w_u16(frame + 0x10u, 0x3Cu);
    w_u16(frame + 0x12u, 0xFF9Cu);
    w_u16(frame + 0x14u, 0x30Cu);
    sub_80031CC0(frame + 0x10u, object + 0xECu);
    sub_80055168((uint32)r_s16(object + 0x110u), object + 0xFCu);
    result = sub_80031A54(object + 0xFCu, object + 0xFCu);
    context->return_address = r_u32(frame + 0x24u);
    context->caller_s2 = r_u32(frame + 0x20u);
    context->caller_s1 = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
    return result;
}

uint32 sub_80055764(uint32 current, uint32 target, uint32 step)
{
    FUNCTION_MARKER(0x80055764u, "1.EXE");
    uint32 rate = r_u32(0x800A9010u);
    uint32 limit = (uint32)((sint64)(sint32)step * (sint32)rate);
    uint32 difference = (target - current) & 0xFFFu;
    if ((sint32)difference >= 0x801)
        difference -= 0x1000u;
    uint32 magnitude = difference;
    if ((sint32)difference < 0)
        magnitude = 0u - magnitude;
    if ((sint32)limit < (sint32)magnitude)
        difference = (sint32)difference > 0 ? limit : 0u - limit;
    return current + difference;
}

uint32 sub_80031A54(uint32 source, uint32 destination)
{
    FUNCTION_MARKER(0x80031A54u, "1.EXE");
    for (uint32 column = 0u; column < 3u; ++column)
    {
        uint32 offset = column << 1;
        uint32 x = r_u16(source + offset);
        uint32 y = r_u16(source + offset + 6u);
        uint32 z = r_u16(source + offset + 12u);
        xport_gte_write_data(9u, x);
        xport_gte_write_data(10u, y);
        xport_gte_write_data(11u, z);
        xport_gte_mvmva(0x49E012u);
        uint32 first = xport_gte_read_data(9u);
        uint32 second = xport_gte_read_data(10u);
        uint32 third = xport_gte_read_data(11u);
        w_u16(destination + offset, (uint16)first);
        w_u16(destination + offset + 6u, (uint16)second);
        w_u16(destination + offset + 12u, (uint16)third);
    }
    return destination + 2u;
}

void sub_80031CC0(uint32 source, uint32 destination)
{
    FUNCTION_MARKER(0x80031CC0u, "1.EXE");
    xport_gte_write_data(0u, r_u32(source));
    xport_gte_write_data(1u, r_u32(source + 4u));
    xport_gte_mvmva(0x480012u);
    w_u32(destination, xport_gte_read_data(25u));
    w_u32(destination + 4u, xport_gte_read_data(26u));
    w_u32(destination + 8u, xport_gte_read_data(27u));
}

uint32 sub_80055168(uint32 angle, uint32 matrix)
{
    FUNCTION_MARKER(0x80055168u, "1.EXE");
    uint32 offset = ((0u - angle) & 0xFFFu) << 1u;
    w_u16(matrix, 0x1000u);
    w_u16(matrix + 2u, 0u);
    w_u16(matrix + 4u, 0u);
    w_u16(matrix + 6u, 0u);
    w_u16(matrix + 0xCu, 0u);
    uint32 value = (uint32)r_s16(0x80010AE0u + offset);
    w_u16(matrix + 8u, (uint16)value);
    w_u16(matrix + 0x10u, (uint16)value);
    value = (uint32)r_s16(0x800102E0u + offset);
    w_u16(matrix + 0xAu, (uint16)value);
    value = 0u - value;
    w_u16(matrix + 0xEu, (uint16)value);
    return value;
}

uint32 sub_80037150(GameGeometryCallContext *context)
{
    FUNCTION_MARKER(0x80037150u, "1.EXE");
    uint32 frame = context->stack_pointer - 0x28u;
    uint32 attempts = 0u;
    uint32 result;
    w_u32(frame + 0x18u, context->caller_s0);
    w_u32(frame + 0x1Cu, context->caller_s1);
    w_u8(frame + 0x10u, 0x68u);
    w_u32(frame + 0x20u, context->return_address);
    w_u8(frame + 0x11u, 1u);
    do
    {
        result = (uint32)CdControlB(14u, (uint8 *)psx_addr(frame + 0x10u, 8u), NULL);
        w_u32(0x800A7BE0u, result);
        if (result == 1u)
            break;
        VSync(3);
        ++attempts;
        result = (sint32)attempts < 10 ? 1u : 0u;
    } while (result != 0u);
    context->return_address = r_u32(frame + 0x20u);
    context->caller_s1 = r_u32(frame + 0x1Cu);
    context->caller_s0 = r_u32(frame + 0x18u);
    return result;
}
