#include "native_call_dispatch.h"

uint32 sub_80065220(uint32 object, uint32 output)
{
    uint32 result;
    FUNCTION_MARKER(0x80065220, "1.EXE");
    w_u16(output, r_u16(object + 60));
    w_u16(output + 2, r_u16(object + 62));
    result = r_u16(object + 64);
    w_u16(output + 4, result);
    return result;
}

uint32 sub_800660B0(uint32 record, uint32 base_x, uint32 base_z)
{
    FUNCTION_MARKER(0x800660B0, "1.EXE");
    return sub_800660D0(record, base_x, base_z, 4);
}

uint32 sub_8006754C(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object, height, flags, models;
    FUNCTION_MARKER(0x8006754C, "1.EXE");
    object = sub_800227C4(40);
    w_u32(object + 20, base_x + (r_u32(record) & 0xFFF));
    w_u32(object + 28, base_z + ((r_u32(record) >> 12) & 0xFFF));
    height = r_u16(record + 4);
    flags = r_u8(object + 14);
    w_u32(object, 0x80067690);
    w_u8(object + 14, flags | 0x20);
    models = r_u32(0x800A62EC);
    w_u32(object + 24, 0 - height);
    sub_8006749C(object, (uint32)r_s16(models + 76));
    w_u8(object + 13, 255);
    return 255;
}

uint32 sub_80068B64(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object;
    FUNCTION_MARKER(0x80068B64, "1.EXE");
    object = sub_80066984(record, base_x, base_z);
    w_u8(object + 13, 1);
    w_u16(object + 82, 40);
    return object;
}

uint32 sub_80068B94(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object;
    FUNCTION_MARKER(0x80068B94, "1.EXE");
    object = sub_80066984(record, base_x, base_z);
    w_u8(object + 13, 4);
    w_u16(object + 82, 0);
    return object;
}

uint32 sub_80068BC0(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object;
    FUNCTION_MARKER(0x80068BC0, "1.EXE");
    object = sub_80066984(record, base_x, base_z);
    w_u8(object + 13, 3);
    w_u16(object + 82, 30);
    return object;
}

uint32 sub_80068C44(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object;
    FUNCTION_MARKER(0x80068C44, "1.EXE");
    object = sub_80066984(record, base_x, base_z);
    w_u8(object + 13, 2);
    w_u16(object + 82, 30);
    return object;
}

uint32 sub_80067220(uint32 object)
{
    uint32 delta, phase, result;
    FUNCTION_MARKER(0x80067220, "1.EXE");
    delta = (uint32)r_s8(object + 13) * r_u32(0x800A9010);
    phase = r_u32(object + 16) + delta;
    result = (uint32)draft_call_adapter(0x80054D38, 0, (uint32)r_s16(object + 54), phase, object + 36);
    w_u32(object + 16, phase);
    return result;
}

uint32 sub_80067284(uint32 record, uint32 base_x, uint32 base_z, uint32 speed)
{
    uint32 object, model_index, models, flags, model, result;
    FUNCTION_MARKER(0x80067284, "1.EXE");
    object = (uint32)draft_call_adapter(0x800226E4, 56);
    w_u32(object + 20, base_x + (r_u32(record) & 0xFFF));
    w_u32(object + 28, base_z + ((r_u32(record) >> 12) & 0xFFF));
    w_u32(object + 24, 0 - (uint32)r_u16(record + 4));
    model_index = r_u8(record + 11);
    models = r_u32(0x800A8FD8);
    flags = r_u8(object + 14);
    model = r_u16(models + 2 * model_index);
    w_u32(object + 16, 0);
    w_u8(object + 14, flags | 2);
    flags = r_u8(object + 14);
    w_u8(object + 34, 14);
    w_u32(object, 0x80067220);
    w_u16(object + 32, model);
    w_u8(object + 14, flags | 0x20);
    w_u16(object + 54, (r_u32(record + 4) >> 14) & 0xF80);
    result = sub_800551CC((r_u32(record + 4) >> 14) & 0xF80, object + 36);
    w_u8(object + 13, speed);
    return result;
}

uint32 sub_80067200(uint32 record, uint32 base_x, uint32 base_z)
{
    FUNCTION_MARKER(0x80067200, "1.EXE");
    return sub_80067284(record, base_x, base_z, 0xFFFFFFF0);
}
