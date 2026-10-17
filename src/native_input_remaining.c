#include "native_call_dispatch.h"

uint32 sub_80038A30(uint32 index, uint32 buttons, uint32 held_mask, uint32 delay_mask)
{
    uint32 entry, mask, held, first, second;
    FUNCTION_MARKER(0x80038A30, "1.EXE");
    entry = 0x8008B9BC + 8 * index;
    mask = r_u32(entry);
    if (buttons & mask)
    {
        held = r_u32(0x800A6D4C);
        if (!(held & mask) || !(held_mask & mask))
        {
            w_u32(0x800A6D50, r_u32(0x800A6D50) | mask);
            first = r_u32(entry);
            second = r_u32(entry);
            w_u32(0x800A6D4C, held | first);
            if (delay_mask & second)
                w_u32(entry + 4, 75);
        }
    }
    else
        w_u32(0x800A6D4C, r_u32(0x800A6D4C) & ~mask);
    return 0;
}

uint32 sub_80038AC4(uint32 buttons, uint32 held_mask, uint32 delay_mask)
{
    uint32 entry, remaining;
    FUNCTION_MARKER(0x80038AC4, "1.EXE");
    w_u32(0x800A6D50, 0);
    entry = 0x8008B9C0;
    for (uint32 i = 0; i < 16; ++i)
    {
        remaining = r_u32(entry);
        if (remaining)
        {
            remaining -= r_u32(0x800A9010);
            w_u32(entry, remaining);
            if ((sint32)remaining < 0)
                w_u32(entry, 0);
        }
        else
            sub_80038A30(i, buttons, held_mask, delay_mask);
        entry += 8;
    }
    return r_u32(0x800A6D50);
}

uint32 sub_80038B98(uint32 buttons)
{
    FUNCTION_MARKER(0x80038B98, "1.EXE");
    return sub_80038AC4(buttons, 0x800, 0);
}

uint32 sub_80038BBC(uint32 buttons)
{
    FUNCTION_MARKER(0x80038BBC, "1.EXE");
    return sub_80038AC4(buttons, 0x840, 0x40);
}

uint32 sub_80038BE0(uint32 buttons)
{
    uint32 result;
    FUNCTION_MARKER(0x80038BE0, "1.EXE");
    result = sub_80038AC4(buttons, 0xA900, 0);
    if (result & 0x100)
        w_u16(0x800A967C, 0);
    if (result & 0x800)
        w_u16(0x800A967C, 0);
    return result;
}

uint32 sub_80038C30(uint32 buttons)
{
    FUNCTION_MARKER(0x80038C30, "1.EXE");
    return sub_80038AC4(buttons, 0x940, 0) & 0x940;
}

uint32 sub_80038C58(uint32 buttons)
{
    uint32 result, mode;
    FUNCTION_MARKER(0x80038C58, "1.EXE");
    result = sub_80038AC4(buttons, 0x900, 0);
    if ((result & 0x100) && !r_u32(0x800A9760))
    {
        mode = r_u32(0x800A625C);
        if (!mode || mode == 3)
            w_u16(0x800A967C, 1);
    }
    if (result & 0x800)
        w_u32(0x800A8B30, 0);
    return result;
}

uint32 sub_80071988(uint32 value, uint32 minimum, uint32 maximum)
{
    FUNCTION_MARKER(0x80071988, "1.EXE");
    if ((sint32)value < (sint32)minimum)
        return minimum;
    if ((sint32)maximum < (sint32)value)
        return maximum;
    return value;
}

uint32 sub_8007035C(uint32 item)
{
    uint32 menu;
    FUNCTION_MARKER(0x8007035C, "1.EXE");
    sub_8006F6E8(r_u32(0x800A645C));
    sub_8006F6E8(r_u32(0x800A6460));
    menu = r_u8(0x80092068 + item);
    w_u32(0x800A6460, 0);
    w_u32(0x800A6468, 1);
    w_u32(0x800A645C, menu);
    return 1;
}

uint32 sub_8006F690(void)
{
    FUNCTION_MARKER(0x8006F690, "1.EXE");
    w_u32(0x800A5C74, 6);
    w_u32(0x800A5C78, 127);
    w_u32(0x800A5C7C, 128);
    return 128;
}

uint32 sub_8006F6BC(void)
{
    FUNCTION_MARKER(0x8006F6BC, "1.EXE");
    w_u32(0x800A5C80, 10);
    w_u32(0x800A5C84, 127);
    w_u32(0x800A5C88, 128);
    return 128;
}
