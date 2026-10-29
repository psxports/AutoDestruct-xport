#include "native_game_save.h"
#include "game_scene.h"
#include <string.h>
#include "native_call_dispatch.h"

uint32 sub_80073574(GameGeometryCallContext *context);

static uint32 calibration_menu_entry(uint32 menu, uint32 item)
{
    return r_u32(0x80091EE0 + 12 * menu) + 16 * item;
}

uint32 sub_8007288C(uint32 item)
{
    uint32 menu, packed, phase, elapsed, controller = 0, show_hint = 0;
    uint32 text, result, mode;
    sint32 message = -1;
    FUNCTION_MARKER(0x8007288C, "1.EXE");
    menu = r_u32(0x800A645C);
    packed = (uint32)r_s16(calibration_menu_entry(menu, item) + 14);
    elapsed = (packed & 0xFF00) >> 8;
    phase = packed & 255;
    mode = r_u32(0x800A6464);
    if ((mode == 1 || mode == 5) && (uint16)sub_80038970(0x800))
    {
        w_u16(calibration_menu_entry(r_u32(0x800A645C), item) + 14, 0);
        sub_8007040C();
        sub_8006F6BC();
        return sub_8006F690();
    }
    if ((uint16)sub_80038970(16))
    {
        w_u16(calibration_menu_entry(r_u32(0x800A645C), item) + 14, 0);
        sub_8006F6BC();
        return sub_8006F690();
    }
    if ((sint16)sub_80037BB8() == 2)
        controller = 2;
    sub_80037BD0();
    draft_call_adapter(0x80020C60, 199, r_u32(0x800A9A74), 0xFFFFFF, 2, (uint32)-160, (uint32)-28, 320, 42);
    switch (phase)
    {
        case 0:
            phase = 1;
            sub_80037DC8();
            break;
        case 1:
            message = (sint32)controller;
            show_hint = 1;
            if ((uint16)sub_80038970(64))
            {
                phase = 2;
                if (controller)
                    sub_8003800C();
                else
                    sub_80037EE4();
            }
            break;
        case 2:
            message = (sint32)controller + 1;
            show_hint = 1;
            elapsed = 0;
            if (controller)
                sub_80037F2C();
            else
                sub_80037DDC();
            if ((uint16)sub_80038970(64))
            {
                phase = 4;
                result = controller ? sub_80037F7C() : sub_80037E2C();
                if (result)
                    phase = 3;
            }
            break;
        case 3:
        case 4:
            message = phase == 3 ? 5 : 4;
            if ((sint32)elapsed >= 96)
            {
                w_u16(calibration_menu_entry(r_u32(0x800A645C), item) + 14, 0);
                return sub_800703B4();
            }
            elapsed += r_u32(0x800A9010);
            break;
    }
    if (message != -1)
    {
        text = sub_8006F554(r_u32(0x800A8BD0), (uint32)message);
        sub_80043820(text, r_u32(0x80092218 + 4 * (uint32)message), 30, show_hint ? 100 : 107, 100, 0);
        if (show_hint)
        {
            text = sub_8006F554(r_u32(0x800A8BD0), 6);
            result = sub_80043820(text, 0x7F7F7F, 30, 114, 100, 0);
            sub_80043820(controller ? 0x800A64F8 : 0x800A64FC, 0x7F7F7F, result + 44, 114, 100, 0);
        }
    }
    if (menu != r_u32(0x800A645C))
        return 0xFFFF0000;
    packed = ((packed & 0xFFFF00FF) | (elapsed << 8));
    packed = (packed & 0xFFFFFF00) | phase;
    result = calibration_menu_entry(menu, item);
    w_u16(result + 14, packed);
    return result;
}

uint32 sub_8007326C(void)
{
    uint32 data;
    sint16 value;
    FUNCTION_MARKER(0x8007326C, "1.EXE");
    data = r_u32(0x800A62EC);
    w_u32(0x800A6510, 0);
    w_u32(0x800A6514, 0);
    w_u32(0x800A98F8, 0);
    w_u32(0x800A7E0C, 0);
    w_u32(0x800A7794, 0);
    w_u32(0x800A650C, 0);
    w_u32(0x800A6520, 0);
    value = r_s16(data + 0x1BE);
    w_u32(0x800A7DF8, 0xFFFFFFFF);
    w_u32(0x800A7800, 0);
    w_u32(0x800A7804, 0);
    w_u32(0x800A7808, 725);
    w_u16(0x800A7810, 0);
    w_u16(0x800A7812, 0);
    w_u16(0x800A7814, 0);
    w_u16(0x800A77E8, (uint16)value);
    return 725;
}

uint32 sub_800732C4(uint32 data)
{
    uint32 source = data + 4, count = 1, value, sum;
    FUNCTION_MARKER(0x800732C4, "1.EXE");
    w_u32(data, 0);
    do
    {
        value = r_u32(source);
        source += 4;
        sum = r_u32(data) + value;
        ++count;
        w_u32(data, sum);
    } while (count < 101);
    return 0;
}

uint32 sub_80073330(void)
{
    uint32 values[7], source, destination, first, second, third, fourth;
    FUNCTION_MARKER(0x80073330, "1.EXE");
    values[0] = r_u16(0x800A854C);
    values[1] = r_u16(0x800A7C6C);
    values[2] = r_u16(0x800A7E10);
    values[3] = r_u16(0x800A9D6C);
    values[4] = r_u16(0x800A9CD0);
    values[5] = r_u16(0x800A975C);
    values[6] = r_u16(0x800A84A0);
    w_u16(0x800B589C, values[0]);
    w_u16(0x800B589E, values[1]);
    w_u16(0x800B58A0, values[2]);
    w_u16(0x800B58A2, values[3]);
    w_u16(0x800B58A4, values[4]);
    w_u16(0x800B58A6, values[5]);
    w_u16(0x800B58AA, values[6]);
    w_u16(0x800B58A8, sub_8007233C());
    sub_8003CA68(0x800B58AC);
    destination = 0x800B5900;
    source = 0x800A9760;
    do
    {
        first = r_u32(source);
        second = r_u32(source + 4);
        third = r_u32(source + 8);
        fourth = r_u32(source + 12);
        w_u32(destination, first);
        w_u32(destination + 4, second);
        w_u32(destination + 8, third);
        w_u32(destination + 12, fourth);
        source += 16;
        destination += 16;
    } while (source != 0x800A9880);
    first = r_u32(source);
    second = r_u32(source + 4);
    third = r_u32(source + 8);
    w_u32(destination, first);
    w_u32(destination + 4, second);
    w_u32(destination + 8, third);
    return first;
}

// Keep the original packed progress without a card header
static uint8 ad_pending_save[404];
static sint32 ad_load_pending;
static const char *ad_save_message;
static uint32 ad_save_message_menu;

static sint32 ad_save_notify(sint32 result, const char *message)
{
    ad_save_message = message;
    ad_save_message_menu = r_u32(0x800A645Cu);
    return result;
}

const char *ad_save_notice(uint32 menu)
{
    if (menu != ad_save_message_menu)
        ad_save_message = NULL;
    return ad_save_message;
}

static void ad_add_pause_save(uint32 menu, uint32 storage, uint32 entries)
{
    uint32 old = r_u32(0x80091EE0u + menu * 12u);
    memcpy(psx_addr(storage, entries * 16u), psx_addr(old, entries * 16u), entries * 16u);
    xport_guest_fill(storage + entries * 16u, 0u, 32u);
    w_u32(storage + entries * 16u, 1u);
    w_u16(storage + entries * 16u + 12u, 41u);
    w_u32(0x80091EE0u + menu * 12u, storage);
}

void ad_init_save_menu(void)
{
    w_u16(0x800917D4u, 40u);
    w_u16(0x800917D6u, 0u);
    w_u16(0x80091C34u, 41u);
    w_u16(0x80091C36u, 0u);
    // Reuse obsolete card-menu storage while preserving every existing pause action
    ad_add_pause_save(1u, 0x80091C68u, 7u);
    ad_add_pause_save(5u, 0x80091CF8u, 4u);
}

sint32 ad_save_game(void)
{
    sub_80073330();
    sub_800732C4(0x800B5898u);
    sint32 result = xport_save(psx_addr(0x800B5898u, 404u), 404);
    return ad_save_notify(result, result == 1 ? "GAME SAVED" : "SAVE FAILED");
}

static void ad_apply_saved_game(void)
{
    GameGeometryCallContext context = {0};
    memcpy(psx_addr(0x800B5898u, 404u), ad_pending_save, 404u);
    sub_80073574(&context);
    memcpy(psx_addr(0x800A9760u, 300u), psx_addr(0x800B5900u, 300u), 300u);
    if (r_u32(0x800A9760u))
        w_u16(0x800A6DE0u, r_u16(0x800A9764u));
}

sint32 ad_restore_loaded_game(void)
{
    if (!ad_load_pending)
        return 0;
    ad_apply_saved_game();
    ad_load_pending = 0;
    return 1;
}

sint32 ad_load_game(void)
{
    uint8 data[404];
    uint32 sum = 0u;
    sint32 size = xport_load(data, sizeof(data));
    if (size <= 0)
        return ad_save_notify(size, size == 0 ? "NO SAVE DATA" : "LOAD FAILED");
    if (size != sizeof(data))
        return ad_save_notify(-1, "LOAD FAILED");
    for (uint32 offset = 4u; offset < sizeof(data); offset += 4u)
        sum += xport_load_le32(data + offset);
    if (sum != xport_load_le32(data))
        return ad_save_notify(-1, "LOAD FAILED");
    memcpy(ad_pending_save, data, sizeof(data));
    ad_apply_saved_game();
    ad_load_pending = 1;
    return ad_save_notify(1, "GAME LOADED");
}
