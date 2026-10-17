#include "native_call_dispatch.h"

// Menu globals use the reviewed runtime GP 0x800A5628
static uint32 menu_settings_entry(uint32 menu, uint32 item)
{
    return r_u32(0x80091EE0 + 12 * menu) + 16 * item;
}

uint32 sub_80072F6C(uint32 item)
{
    uint32 old_value = (uint32)r_s16(menu_settings_entry(r_u32(0x800A645C), item) + 14);
    uint32 buttons = (uint32)(sint32)(sint16)sub_80038970(0xFFFF8000);
    uint32 value, entry;
    buttons |= (uint32)(sint32)(sint16)sub_80038970(0x2000);
    value = old_value;
    if (buttons & 0x8000)
        --value;
    if (buttons & 0x2000)
        ++value;
    value = sub_80071988(value, 1, 25);
    if (value != old_value)
        draft_call_adapter(0x80035A08, 36, 2048, 192, 0, 0);
    entry = menu_settings_entry(r_u32(0x800A645C), item);
    w_u16(entry + 14, value);
    return entry;
}

uint32 sub_80070FF8(void)
{
    uint32 mode = r_u32(0x800A6464);
    uint32 result = 5;
    if (mode == 1 || mode == 5)
    {
        result = r_u32(0x800A75C0);
        if (!result)
        {
            result = sub_80037490();
            w_u32(0x800A75C0, 1);
        }
    }
    return result;
}

void sub_8007104C(uint32 item)
{
    uint32 kind = r_u32(menu_settings_entry(r_u32(0x800A645C), item));
    uint32 buttons, mode;
    sub_80071148(item);
    buttons = (uint32)(sint32)(sint16)sub_800389DC();
    if (!(buttons & 0x5810))
        return;
    mode = r_u32(0x800A6464);
    if (mode == 1 || mode == 5)
    {
        if (kind == 128)
            sub_80036FE4();
        else if (buttons & 0x810)
            w_u16(0x800A9A64, 1);
        sub_80037490();
    }
    else if (kind != 128)
    {
        w_u16(0x800A9A64, 1);
        sub_8003708C();
    }
}

uint32 sub_80072E40(uint32 item)
{
    uint32 row, mark, text, color, x, result;
    sint32 value;
    FUNCTION_MARKER(0x80072E40, "1.EXE");
    row = sub_8006F818(item);
    mark = draft_scratch_mark();
    text = draft_scratch_adapter(3);
    w_u8(text, r_u8(0x800A6500));
    w_u8(text + 1, r_u8(0x800A6501));
    w_u8(text + 2, r_u8(0x800A6502));
    value = r_s16(menu_settings_entry(r_u32(0x800A645C), item) + 14);
    x = r_u32(0x800A75C8);
    w_u8(text, (uint32)(value / 10 + 48));
    w_u8(text + 1, (uint32)(value % 10 + 48));
    color = r_u32(0x800A6460) == item ? 0x7F7F7F : 0x4F4F4F;
    row = 12 * (row + 1);
    sub_80043820(text, color, x + 46, row + 30, 100, 1);
    result = sub_80070D6C(x + 42, row + 28, 28, 15, 100);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_8006F898(uint32 item)
{
    uint32 row, value, text, color;
    FUNCTION_MARKER(0x8006F898, "1.EXE");
    row = sub_8006F818(item);
    value = (uint32)r_s16(menu_settings_entry(r_u32(0x800A645C), item) + 14);
    text = sub_8006F554(r_u32(0x800A8BA0), value != 0);
    color = r_u32(0x800A6460) == item ? 0x7F7F7F : 0x4F4F4F;
    return sub_80043820(text, color, r_u32(0x800A75C8) + 46, 12 * (row + 1) + 30, 100, 0);
}

uint32 sub_80072CAC(uint32 step, uint32 count, uint32 item)
{
    uint32 value, buttons, result;
    FUNCTION_MARKER(0x80072CAC, "1.EXE");
    value = (uint32)r_s16(menu_settings_entry(r_u32(0x800A645C), item) + 14);
    buttons = sub_800389DC();
    if ((sint16)buttons < 0)
        value -= step;
    if (buttons & 0x2000)
        value += step;
    result = sub_80071960(value, count);
    w_u16(menu_settings_entry(r_u32(0x800A645C), item) + 14, result);
    return result;
}

uint32 sub_80072D70(uint32 controller, uint32 value)
{
    FUNCTION_MARKER(0x80072D70, "1.EXE");
    if (controller == 2)
        w_u32(0x800A5C74, value);
    else
        w_u32(0x800A5C80, value);
    return 2;
}

uint32 sub_80072D9C(uint32 item)
{
    uint32 controller;
    sint32 value;
    FUNCTION_MARKER(0x80072D9C, "1.EXE");
    controller = (uint32)(sint32)(sint16)sub_80037BB8();
    value = (sint32)sub_80072CAC(2, 64, item);
    if (controller == 2)
    {
        value /= 3;
        if (value < 3)
            value = 3;
    }
    else
    {
        value /= 2;
        if (value < 11)
            value = 10;
    }
    return sub_80072D70(controller, (uint32)value);
}

uint32 sub_8007135C(uint32 item)
{
    uint32 entry, index, models, model, tick, mark, preview, result;
    FUNCTION_MARKER(0x8007135C, "1.EXE");
    entry = menu_settings_entry(r_u32(0x800A645C), item);
    index = (uint32)r_s16(entry + 14);
    models = r_u32(0x800A62EC);
    index = (uint32)r_s16(0x80091778 + 2 * index);
    model = (uint32)r_s16(models + 2 * index);
    tick = r_u32(0x800A9010);
    mark = draft_scratch_mark();
    preview = draft_scratch_adapter(40);
    w_u32(preview, 0);
    w_u32(preview + 4, 0);
    w_u32(preview + 8, 1000);
    w_u16(0x800A75BC, 0);
    w_u16(preview + 12, model);
    w_u16(0x800A75BA, r_u16(0x800A75BA) + 20 * tick);
    w_u16(0x800A75B8, 200);
    draft_call_adapter(0x80055134, 0x800A75B8, preview + 16);
    result = sub_80020300(preview, r_u32(0x800A9A74), 101, 40, 40);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_80071274(uint32 item)
{
    uint32 old_value, value, buttons, result;
    FUNCTION_MARKER(0x80071274, "1.EXE");
    old_value = (uint32)r_s16(menu_settings_entry(r_u32(0x800A645C), item) + 14);
    value = old_value;
    buttons = sub_8006F58C();
    sub_8007135C(item);
    if (buttons & 0x8000)
        ++value;
    if (buttons & 0x2000)
        --value;
    result = sub_80071960(value, 14);
    w_u16(menu_settings_entry(r_u32(0x800A645C), item) + 14, result);
    if (result != old_value)
        return (uint32)draft_call_adapter(0x80035A08, 36, 2048, 192, 0, 0);
    return result;
}

uint32 sub_8007306C(uint32 item)
{
    uint32 value, row, x, index, selected, text;
    FUNCTION_MARKER(0x8007306C, "1.EXE");
    value = (uint32)r_s16(menu_settings_entry(r_u32(0x800A645C), item) + 14);
    row = sub_8006F818(item);
    x = r_u32(0x800A75C8) + 46;
    index = r_u8(r_u32(0x80092248 + 4 * item) + value);
    selected = r_u32(0x800A6460);
    text = r_u32(0x800A8B38 + 4 * index);
    return sub_80043820(text, selected == item ? 0x7F7F7F : 0x4F4F4F, x, 12 * (row + 1) + 30, 100, 0);
}

void sub_80051124(uint32 item, uint32 value)
{
    uint32 coarse, fine, packed, result;
    FUNCTION_MARKER(0x80051124, "1.EXE");
    if (item == 1)
    {
        if (value < 3)
            sub_8003D6A0((uint32)(sint32)(sint16)value);
    }
    else if (item == 2)
    {
        coarse = r_u8(0x800A8515);
        fine = r_u8(0x800A8514);
        if ((sint32)value < 9 || (sint32)value >= 0)
        {
            coarse = value;
            fine = 255;
        }
        if ((sint16)coarse >= 9)
            coarse = 8;
        if ((sint32)fine >= 256)
            fine = 255;
        packed = ((coarse << 8) & 0xFF00) | fine;
        w_u32(0x800A8514, packed);
        sub_8003D27C((uint32)r_s16(0x800A8514));
    }
    else if (!item && value < 3)
    {
        sub_8003D694((uint32)(sint32)(sint16)value);
        result = 18204 * (uint32)(sint32)(sint16)sub_8003D654();
        w_u32(0x800A8538, result);
        w_u32(0x800A56C4, result);
    }
}

void sub_8007313C(uint32 item)
{
    uint32 old_value, value, buttons, menu, entry;
    FUNCTION_MARKER(0x8007313C, "1.EXE");
    old_value = (uint32)r_s16(menu_settings_entry(r_u32(0x800A645C), item) + 14);
    buttons = (uint32)(sint32)(sint16)sub_80038970(0xFFFF8000);
    buttons |= (uint32)(sint32)(sint16)sub_80038970(0x2000);
    value = old_value;
    if (buttons & 0x8000)
        --value;
    if (buttons & 0x2000)
        ++value;
    value = sub_80071960(value, r_u8(0x80092254 + item));
    if (value != old_value)
        draft_call_adapter(0x80035A08, 36, 2048, 192, 0, 0);
    menu = r_u32(0x800A645C);
    entry = menu_settings_entry(menu, item);
    w_u16(entry + 14, value);
    entry = menu_settings_entry(menu, item);
    sub_80051124(item, (uint32)r_s16(entry + 14));
}

uint32 sub_800719B0(void)
{
    uint32 text, mode, index;
    FUNCTION_MARKER(0x800719B0, "1.EXE");
    sub_80070D6C(95, 70, 186, 50, 101);
    text = sub_8006F554(r_u32(0x800A8D44), 2);
    sub_80043820(text, 0x4F4F4F, 125, 74, 100, 0);
    sub_80043820(0x8009206C, 0x4F4F4F, 125, 87, 100, 1);
    mode = r_u32(0x800A854C);
    index = mode == 17 ? 156 : 155;
    if (mode == 10 || mode == 17)
        return sub_80043820(r_u32(0x800A8B38 + 4 * index), 0x8000, 30, 160, 100, 0);
    return 17;
}

uint32 sub_80042560(uint32 y)
{
    FUNCTION_MARKER(0x80042560, "1.EXE");
    return sub_80044534(0x808080, 0x800903A4, 0, (uint32)(sint32)(sint16)y);
}

uint32 sub_8006F670(void)
{
    FUNCTION_MARKER(0x8006F670, "1.EXE");
    return sub_80042560(68);
}
