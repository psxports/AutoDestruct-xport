#include "native_call_dispatch.h"

static uint32 object_table_near(uint32 first, uint32 second)
{
    uint32 difference = first - second;
    if ((sint32)difference < 0)
        difference = second - first;
    return (sint32)difference < 300;
}

uint32 sub_800297FC(uint32 object)
{
    uint32 x = 0u - (uint32)(r_s32(object + 488) >> 8);
    uint32 z = 0u - (uint32)(r_s32(object + 496) >> 8);
    FUNCTION_MARKER(0x800297FC, "1.EXE");
    return (uint32)(sint32)(sint16)sub_80055A9C(x, z);
}

uint32 sub_80029838(uint32 object)
{
    uint32 length;
    FUNCTION_MARKER(0x80029838, "1.EXE");
    length = sub_80069BE0((uint32)(r_s32(object + 488) >> 8), (uint32)(r_s32(object + 496) >> 8));
    return (uint32)(sint32)(sint16)sub_80055A9C(r_u32(object + 492), length << 8);
}

uint32 sub_80022F20(uint32 object, uint32 event, uint32 position)
{
    uint32 duration;
    FUNCTION_MARKER(0x80022F20, "1.EXE");
    duration = (sint16)event == 51 ? r_u16(0x800A56C0) : r_u32(0x800A56C0) << 1;
    w_u16(object + 594, duration);
    w_u8(object + 582, event);
    for (uint32 index = 0; index < 4; ++index)
    {
        uint32 x = (uint32)r_s16(object + 160 + 8 * index) + r_u32(object + 20);
        if (object_table_near(r_u32(position), x))
        {
            uint32 z = (uint32)r_s16(object + 164 + 8 * index) + r_u32(object + 28);
            if (object_table_near(r_u32(position + 8), z))
                w_u8(object + 584 + index, 1);
        }
    }
    return 0;
}

void sub_80029948(uint32 object, uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x80029948, "1.EXE");
    w_u16(object + 572, first);
    w_u16(object + 574, second);
}

void sub_80029954(uint32 object, uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x80029954, "1.EXE");
    w_u16(object + 576, first);
    w_u16(object + 578, second);
}

// Original empty entries contain only JR RA and its NOP delay slot
void sub_80029960(void)
{
}

void sub_8002E308(void)
{
}

void sub_800464A8(void)
{
}

uint32 sub_80052E88(uint32 object)
{
    uint32 owner = r_u32(r_u32(0x800A851C) + 4 * (uint32)r_s16(object + 58));
    uint32 target = r_u32(r_u32(owner + 16));
    FUNCTION_MARKER(0x80052E88, "1.EXE");
    return (uint32)draft_call_adapter(target, owner);
}

uint32 sub_80052ED4(uint32 object, uint32 output)
{
    uint32 owner = r_u32(r_u32(0x800A851C) + 4 * (uint32)r_s16(object + 58));
    uint32 target = r_u32(r_u32(owner + 16) + 4);
    FUNCTION_MARKER(0x80052ED4, "1.EXE");
    return (uint32)draft_call_adapter(target, owner, output);
}

uint32 sub_80052F20(uint32 object)
{
    FUNCTION_MARKER(0x80052F20, "1.EXE");
    return (uint32)(sint32)(sint16)sub_80055A9C((uint32)r_s16(object + 140), (uint32)r_s16(object + 142));
}

uint32 sub_80052F54(uint32 object)
{
    FUNCTION_MARKER(0x80052F54, "1.EXE");
    return (uint32)(sint32)(sint16)sub_80055A9C((uint32)r_s16(object + 140), (uint32)r_s16(object + 142));
}

void sub_80052F88(uint32 object, uint32 output)
{
    FUNCTION_MARKER(0x80052F88, "1.EXE");
    w_u16(output, 0);
    w_u16(output + 4, 0);
    w_u16(output + 2, 0);
}

uint32 sub_80052F98(uint32 object, uint32 input)
{
    uint32 result = (uint32)r_s16(input + 2);
    FUNCTION_MARKER(0x80052F98, "1.EXE");
    w_u16(object + 140, result);
    result = (uint32)r_s16(input + 10);
    w_u16(object + 142, result);
    return result;
}

uint32 sub_80051258(uint32 object)
{
    uint32 motion = r_u32(object + 60);
    FUNCTION_MARKER(0x80051258, "1.EXE");
    return sub_80069BE0((uint32)r_s16(motion + 16), (uint32)r_s16(motion + 18)) << 16;
}

uint32 sub_8005128C(uint32 object, uint32 output)
{
    uint32 result;
    FUNCTION_MARKER(0x8005128C, "1.EXE");
    result = (0u - (uint32)r_s16(r_u32(object + 60) + 16)) << 16;
    w_u32(output, result);
    result = (uint32)r_s16(r_u32(object + 60) + 18);
    w_u32(output + 4, 0);
    result = (0u - result) << 16;
    w_u32(output + 8, result);
    return result;
}

uint32 sub_800512C8(uint32 object)
{
    FUNCTION_MARKER(0x800512C8, "1.EXE");
    return (uint32)r_s16(r_u32(object + 60) + 22);
}

uint32 sub_800512DC(uint32 object, uint32 output)
{
    uint32 result;
    FUNCTION_MARKER(0x800512DC, "1.EXE");
    w_u16(output, 0);
    result = r_u16(r_u32(object + 60) + 22);
    w_u16(output + 4, 0);
    w_u16(output + 2, result);
    return result;
}

uint32 sub_800512F8(uint32 object, uint32 input)
{
    uint32 motion = r_u32(object + 60);
    uint32 value = (uint32)r_s16(input + 2);
    FUNCTION_MARKER(0x800512F8, "1.EXE");
    w_u16(motion + 16, value);
    motion = r_u32(object + 60);
    value = (uint32)r_s16(input + 10);
    w_u16(motion + 18, value);
    w_u32(object, 0x80052284);
    return 0x80052284;
}

uint32 sub_800454C0(uint32 object, uint32 event)
{
    uint32 result = 0xFFFFFF80;
    FUNCTION_MARKER(0x800454C0, "1.EXE");
    if ((sint16)event == 51)
    {
        result = r_u8(0x800A6EE4);
        w_u16(object + 90, event);
        w_u8(object + 89, result);
    }
    else
    {
        w_u8(object + 89, result);
        w_u16(object + 90, event);
    }
    return result;
}

uint32 sub_800454F8(uint32 object)
{
    uint32 result = (uint32)r_s8(object + 87);
    FUNCTION_MARKER(0x800454F8, "1.EXE");
    w_u16(object + 114, 120);
    result = 0u - result;
    w_u8(object + 87, result);
    return result;
}

uint32 sub_80040E64(uint32 object, uint32 output)
{
    uint32 result;
    FUNCTION_MARKER(0x80040E64, "1.EXE");
    w_u16(output, 0);
    result = r_u16(object + 448);
    w_u16(output + 4, 0);
    w_u16(output + 2, result);
    return result;
}

uint32 sub_800537B0(uint32 object)
{
    uint32 motion = r_u32(object + 60);
    FUNCTION_MARKER(0x800537B0, "1.EXE");
    return sub_80069BE0((uint32)(r_s32(motion + 72) >> 8), (uint32)(r_s32(motion + 76) >> 8)) << 8;
}

uint32 sub_8005381C(uint32 object)
{
    FUNCTION_MARKER(0x8005381C, "1.EXE");
    return (uint32)r_s16(r_u32(object + 60) + 84);
}

uint32 sub_80053830(uint32 object, uint32 output)
{
    uint32 result = r_u16(r_u32(object + 60) + 84);
    FUNCTION_MARKER(0x80053830, "1.EXE");
    w_u16(output, 0);
    w_u16(output + 4, 0);
    w_u16(output + 2, result);
    return result;
}

uint32 sub_8005384C(uint32 object, uint32 input)
{
    uint32 motion = r_u32(object + 60);
    uint32 result = (uint32)r_s16(input + 2);
    FUNCTION_MARKER(0x8005384C, "1.EXE");
    w_u32(motion + 72, result);
    motion = r_u32(object + 60);
    result = (uint32)r_s16(input + 10);
    w_u32(motion + 76, result);
    return result;
}

void sub_8005386C(uint32 object, uint32 output)
{
    FUNCTION_MARKER(0x8005386C, "1.EXE");
    w_u32(output, 0);
    w_u32(output + 8, 0);
    w_u32(output + 4, 0);
}

uint32 sub_8005387C(uint32 object)
{
    FUNCTION_MARKER(0x8005387C, "1.EXE");
    return (uint32)r_s16(r_u32(object + 60) + 84);
}

void sub_8005413C(uint32 object, uint32 output)
{
    FUNCTION_MARKER(0x8005413C, "1.EXE");
    w_u16(output, 0);
    w_u16(output + 2, 0);
    w_u16(output + 4, 0);
}

uint32 sub_80055F98(uint32 object)
{
    FUNCTION_MARKER(0x80055F98, "1.EXE");
    return (uint32)r_s16(object + 10) << 8;
}

uint32 sub_80056010(uint32 object)
{
    FUNCTION_MARKER(0x80056010, "1.EXE");
    return (uint32)(sint32)(sint16)(r_u16(object + 78) + 2048);
}
