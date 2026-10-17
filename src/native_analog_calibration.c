#include "native_call_dispatch.h"

uint32 sub_80037DC8(void)
{
    FUNCTION_MARKER(0x80037DC8, "1.EXE");
    w_u16(0x800A6D54, 0);
    w_u16(0x800A6D58, 255);
    return 255;
}

static uint32 analog_calibration_track(void)
{
    sint32 maximum = r_s16(0x800A6D54);
    uint32 sample = r_u8(0x800A6D44);
    uint32 result;
    w_u8(0x800A6D48, 128);
    if (maximum < (sint32)sample)
        w_u16(0x800A6D54, r_u8(0x800A6D44));
    result = (sint32)sample < r_s16(0x800A6D58);
    if (result)
    {
        result = r_u8(0x800A6D44);
        w_u16(0x800A6D58, result);
    }
    return result;
}

uint32 sub_80037DDC(void)
{
    FUNCTION_MARKER(0x80037DDC, "1.EXE");
    return analog_calibration_track();
}

uint32 sub_80037F2C(void)
{
    FUNCTION_MARKER(0x80037F2C, "1.EXE");
    return analog_calibration_track();
}

uint32 sub_80037E2C(void)
{
    sint32 maximum, minimum, high_extent, low_extent, extent, center_offset;
    uint32 center;
    FUNCTION_MARKER(0x80037E2C, "1.EXE");
    maximum = r_s16(0x800A6D54);
    minimum = r_s16(0x800A6D58);
    high_extent = maximum - 128;
    if (high_extent < 0)
        high_extent = -high_extent;
    low_extent = minimum - 128;
    if (low_extent < 0)
        low_extent = -low_extent;
    if (minimum < maximum && high_extent >= 64 && low_extent >= 64)
    {
        center = r_u32(0x800A5C88);
        if (center - 96 < 65)
        {
            extent = (high_extent + low_extent) / 2;
            center_offset = (sint32)(center - 128);
            if (center_offset < 0)
                center_offset = -center_offset;
            if (128 - center_offset < extent)
                extent = 128 - center_offset;
            w_u32(0x800A5C84, (uint32)extent);
            return 0;
        }
    }
    w_u32(0x800A5C88, 128);
    w_u32(0x800A5C84, 128);
    return 0xFFFFFFFF;
}

uint32 sub_80037F7C(void)
{
    sint32 maximum, minimum, high_extent, low_extent;
    uint32 center;
    FUNCTION_MARKER(0x80037F7C, "1.EXE");
    maximum = r_s16(0x800A6D54);
    minimum = r_s16(0x800A6D58);
    high_extent = maximum - 128;
    if (high_extent < 0)
        high_extent = -high_extent;
    low_extent = minimum - 128;
    if (low_extent < 0)
        low_extent = -low_extent;
    if (minimum < maximum && high_extent >= 64 && low_extent >= 64)
    {
        center = r_u32(0x800A5C7C);
        if (center - 96 < 65)
        {
            w_u32(0x800A5C78, (uint32)((high_extent + low_extent) / 2));
            return 0;
        }
    }
    w_u32(0x800A5C7C, 128);
    w_u32(0x800A5C78, 128);
    return 0xFFFFFFFF;
}

static uint32 analog_calibration_center(uint32 destination)
{
    uint32 deadzone = r_u32(0x800A5C80);
    uint32 sample = r_u8(0x800A6D44);
    uint32 result;
    w_u8(0x800A6D48, 128);
    result = (sint32)(deadzone + 128) < (sint32)sample;
    if (!result)
        result = (sint32)sample < (sint32)(128 - deadzone);
    w_u32(destination, result ? sample : 128);
    return result;
}

uint32 sub_80037EE4(void)
{
    FUNCTION_MARKER(0x80037EE4, "1.EXE");
    return analog_calibration_center(0x800A5C88);
}

uint32 sub_8003800C(void)
{
    FUNCTION_MARKER(0x8003800C, "1.EXE");
    return analog_calibration_center(0x800A5C7C);
}

void sub_800510C8(void)
{
    // Original empty entry contains JR RA and its NOP delay slot
}
