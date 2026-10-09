#include "xport.h"
#include "psx.h"
#include "game_scene.h"
#include "draft_signatures.h"
#include <stdio.h>
#include <string.h>
uint32 sub_8007FAAC(uint32 mode);

uint32 sub_80078830(void);

uint32 sub_80031290(void)
{
    uint32 result = r_u32(0x800A6098), previous = result, node = r_u32(result + 4);
    FUNCTION_MARKER(0x80031290, "1.EXE");
    while (node) {
        uint32 element, previous_element;
        result = r_u32(0x800A60A0); if (node == result) break;
        element = previous_element = r_u32(node + 8);
        while (element) {
            if (r_u8(r_u32(r_u32(0x800A851C) + 4 * (sint16)r_u16(element)) + 64)) previous_element = element;
            else {
                if (element == r_u32(node + 8)) w_u32(node + 8, r_u32(element + 4));
                else w_u32(previous_element + 4, r_u32(element + 4));
                sub_80064D60(element);
            }
            element = r_u32(element + 4);
        }
        result = r_u32(node + 8);
        if (result) { previous = node; node = r_u32(node + 4); }
        else {
            if (node == r_u32(0x800A609C)) { w_u32(0x800A609C, previous); w_u32(previous + 4, 0); return sub_80064D60(node); }
            w_u32(previous + 4, r_u32(r_u32(previous + 4) + 4)); result = sub_80064D60(node); node = r_u32(previous + 4);
        }
    }
    return result;
}

void sub_80031754(void)
{
    FUNCTION_MARKER(0x80031754, "1.EXE");
    w_u32(0x800A6C34, 0); w_u32(0x800A6C38, 0); w_u16(0x800A6C2E, 0); w_u32(0x800A6C3C, 0); w_u32(0x800A6C40, 0);
}

uint32 sub_800330E0(void)
{
    uint32 result = (sint16)r_u16(0x800A9744);
    FUNCTION_MARKER(0x800330E0, "1.EXE");
    w_u32(0x800A6CD4, result); w_u32(0x800A6CD8, r_u32(0x800A902C)); w_u32(0x800A6CDC, r_u32(0x800A7FB8)); return result;
}

uint32 sub_80033100(void)
{
    uint32 result = r_u16(0x800A6CD4);
    FUNCTION_MARKER(0x80033100, "1.EXE");
    w_u16(0x800A9744, result); w_u32(0x800A902C, r_u32(0x800A6CD8)); w_u32(0x800A7FB8, r_u32(0x800A6CDC)); return result;
}

uint32 sub_800333C4(void)
{
    FUNCTION_MARKER(0x800333C4, "1.EXE");
    w_u16(0x800A6C68, 0); sub_80078830(); w_u32(0x800A9020, r_u32(0x800A6098)); return sub_80033400();
}

uint32 sub_800339D0(uint32 buttons)
{
    uint32 cursor = r_u32(0x800A9020), original;
    FUNCTION_MARKER(0x800339D0, "1.EXE");
    if (!cursor) { cursor = r_u32(0x800A6098); if (!cursor) return -1; w_u32(0x800A9020, cursor); }
    original = cursor;
    if (buttons & 0x2000) {
        uint32 head = r_u32(0x800A6098);
        if (cursor == head) { while (r_u32(cursor + 4)) { cursor = r_u32(cursor + 4); w_u32(0x800A9020, cursor); } }
        else { while (r_u32(head + 4) != cursor) head = r_u32(head + 4); cursor = head; w_u32(0x800A9020, cursor); }
        sub_80078830(); if (original == r_u32(0x800A9020)) return -1;
    }
    if (buttons & 0x8000) {
        cursor = r_u32(r_u32(0x800A9020) + 4); if (!cursor) cursor = r_u32(0x800A6098); w_u32(0x800A9020, cursor);
        sub_80078830(); if (original == r_u32(0x800A9020)) return -1;
    }
    return 0;
}

uint32 sub_80039198(void)
{
    FUNCTION_MARKER(0x80039198, "1.EXE");
    for (uint32 i = 1; i < 5; ++i) {
        uint32 word = r_u32(0x800A8500 + i * 4), offset = i * 6;
        w_u8(0x800A976D + offset, word >> 24); w_u8(0x800A978B + offset, word >> 16);
        w_u8(0x800A97A9 + offset, word >> 8); w_u8(0x800A97C7 + offset, word);
    }
    return 0;
}

uint32 sub_8003AB60(uint32 mode)
{
    PSX_RECT rectangle;
    FUNCTION_MARKER(0x8003AB60, "1.EXE");
    rectangle.x = mode == 1 ? 320 : 0; rectangle.y = 0; rectangle.w = 1024; rectangle.h = 512;
    DrawSync(0); VSync(0); ClearImage(&rectangle, 0, 0, 0); DrawSync(0); return VSync(0);
}

uint32 sub_8005A4D8(uint32 filename, GameSceneCallContext *context);
uint32 sub_80041E24(uint32 filename, uint32 mode, GameGeometryCallContext *context);
uint32 sub_8003BEA8(uint32 filename, GameGeometryCallContext *context);
uint32 sub_80039224(void);
uint32 sub_800431EC(GameGeometryCallContext *context);
void sub_8001F850(void);
uint32 sub_8001FF7C(uint32 mode, GameGeometryCallContext *context);
uint32 sub_8006F2B0(void);
uint32 sub_80059E2C(GameSceneCallContext *context);
uint32 sub_800380A8(void);
sint32 LoadPSX(uint32 filename, uint32 header);
sint32 MemCardEndPSX(void);

uint32 sub_8003C958(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x38, filename = frame + 0x10;
    GameSceneCallContext scene = {0}; GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x8003C958, "1.EXE");
    w_u32(frame + 0x34, context->return_address); w_u32(frame + 0x30, context->caller_s0);
    for (uint32 i = 0; i < 25; ++i) w_u8(filename + i, r_u8(0x800A5E6C + i));
    w_u8(filename + 9, r_u8(0x800A8698) + 48);
    scene.stack_pointer = frame; scene.return_address = 0x8003C9F0; scene.caller_s0 = filename;
    if ((sint32)sub_8005A4D8(filename, &scene) > 0) {
        child.stack_pointer = frame; child.return_address = 0x8003CA00; child.caller_s0 = filename;
        sub_80041E24(filename, 477, &child);
    }
    w_u32(0x800A6E18, 8); w_u32(0x800A6E44, 8);
    context->return_address = r_u32(frame + 0x34); context->caller_s0 = r_u32(frame + 0x30); return 8;
}

uint32 sub_800392B4(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0xB8, filename = frame + 0x10, header = frame + 0x70;
    GameGeometryCallContext child = *context; GameSceneCallContext scene = {0}; uint32 result;
    FUNCTION_MARKER(0x800392B4, "1.EXE");
    w_u32(frame + 0xB4, context->return_address); w_u32(frame + 0xB0, context->caller_s0);
    for (uint32 i = 0; i < 26; ++i) w_u8(filename + i, r_u8(0x800A5D28 + i));
    DrawSync(0); VSync(0);
    child.stack_pointer = frame; child.return_address = 0x80039358; child.caller_s0 = 0;
    sub_8003BEA8(0x800A5D44, &child); sub_80039224();
    for (uint32 i = 1; i < 3; ++i) {
        child = *context; child.stack_pointer = frame; child.return_address = 0x80039368; child.caller_s0 = i; sub_800431EC(&child); sub_8001F850(); child = *context; child.stack_pointer = frame; child.return_address = 0x80039378; child.caller_s0 = i;
        sub_8001FF7C(0, &child);
    }
    SetDispMask(1); DrawSync(0); VSync(0); StopCallback();
    w_u32(0x800A6DE4, 0x8012FFF0); w_u32(0x800A87E4, r_u32(0x800A87E4) | 2);
    w_u32(0x8012FFF0, sub_8006F2B0());
    uint32 saved = r_u32(0x800A6DE4); w_u32(0x800A6DE4, 0x8012FFE0);
    w_u32(saved + 4, r_u32(0x800A87E4)); w_u32(saved + 8, r_u32(0x800A8698)); w_u32(saved + 12, r_u32(0x800A8FD4));
    for (uint32 i = 0; i < 4; ++i) w_u32(0x8012FFE0 + i * 4, r_u32(0x800A8504 + i * 4));
    sub_8007FAAC(3u); SetGraphDebug(0);
    scene.stack_pointer = frame; scene.return_address = 0x80039448; scene.caller_s0 = 2; sub_80059E2C(&scene);
    sub_800380A8(); psx_bios_bind_card_end_patch(0x674u, 0x8008628Cu); MemCardEndPSX(); _96_init();
    w_u8(filename + 17, r_u8(0x800A8FD4) + 48);
    while (!LoadPSX(filename, header)) { }
    sub_8007FAAC(0u); SetDispMask(0); result = Exec(header, 0, 0);
    context->return_address = r_u32(frame + 0xB4); context->caller_s0 = r_u32(frame + 0xB0); return result;
}

uint32 sub_80041C9C(uint32 destination, uint32 flags, uint32 width, uint32 height, GameGeometryCallContext *context);
uint32 sub_80041D90(uint32 destination, uint32 color);
void sub_80041DB4(uint32 destination, uint32 x, uint32 y, uint32 rotation);
uint32 sub_80020AB4(uint32 source, uint32 table, uint32 count);
uint32 StopTAP(void);

uint32 sub_800431EC(GameGeometryCallContext *context)
{
    uint32 frame = context->stack_pointer - 0x30, result;
    GameGeometryCallContext child = *context;
    FUNCTION_MARKER(0x800431EC, "1.EXE");
    w_u32(frame + 0x28, context->return_address);
    w_u32(frame + 0x10, 10); w_u32(frame + 0x14, 0); w_u32(frame + 0x18, 0); w_u32(frame + 0x1C, 640); w_u32(frame + 0x20, 480);
    child.stack_pointer = frame; child.return_address = 0x80043230;
    sub_80041C9C(0x800A98D4, 0x55000040, 255, 64, &child);
    sub_80041D90(0x800A98D4, 0x808080); sub_80041DB4(0x800A98D4, -128, -32, 0);
    result = sub_80020AB4(0x800A98D4, r_u32(0x800A9A74) + 720, 1);
    context->return_address = r_u32(frame + 0x28); return result;
}

uint32 sub_8006F2B0(void)
{
    uint32 mask = 0;
    FUNCTION_MARKER(0x8006F2B0, "1.EXE");
    for (uint32 i = 0; i < 20; ++i) if ((sint16)r_u16(0x800A905C + i * 2) == 1) mask |= 1u << i;
    return mask;
}

uint32 sub_800380A8(void)
{
    FUNCTION_MARKER(0x800380A8, "1.EXE");
    psx_bios_bind_tap_interrupt(0x800A7B44u); return StopTAP();
}

static uint32 native_exe_word(const uint8 *bytes)
{
    return bytes[0] | ((uint32)bytes[1] << 8) | ((uint32)bytes[2] << 16) | ((uint32)bytes[3] << 24);
}

sint32 LoadPSX(uint32 filename, uint32 header)
{
    char guest_path[256], host_path[264] = "DATA/";
    uint8 executable_header[2048]; uint32 length = 0, cursor, output = 5, destination, size, physical;
    FILE *file;
    while (length < sizeof(guest_path) - 1) { guest_path[length] = r_u8(filename + length); if (!guest_path[length]) break; ++length; }
    if (length >= sizeof(guest_path) - 1) return 0;
    guest_path[length] = 0; cursor = !strncmp(guest_path, "cdrom:", 6) ? 6 : 0;
    while (guest_path[cursor] == '\\' || guest_path[cursor] == '/') ++cursor;
    for (; guest_path[cursor] && guest_path[cursor] != ';'; ++cursor) {
        if (output >= sizeof(host_path) - 1) return 0;
        host_path[output++] = guest_path[cursor] == '\\' ? '/' : guest_path[cursor];
    }
    host_path[output] = 0; file = xport_fopen(host_path, "rb"); if (!file) return 0;
    if (fread(executable_header, 1, sizeof(executable_header), file) != sizeof(executable_header) || memcmp(executable_header, "PS-X EXE", 8)) { fclose(file); return 0; }
    destination = native_exe_word(executable_header + 24); size = native_exe_word(executable_header + 28); physical = destination & 0x1FFFFFFF;
    if (!size || physical >= 0x200000 || size > 0x200000 - physical || (destination >> 29 != 0 && destination >> 29 != 4 && destination >> 29 != 5)) { fclose(file); return 0; }
    if (fread(psx_addr(destination, size), 1, size, file) != size) { fclose(file); return 0; }
    fclose(file);
    for (uint32 i = 0; i < 0x3C; ++i) w_u8(header + i, executable_header[0x10 + i]);
    return 1;
}
