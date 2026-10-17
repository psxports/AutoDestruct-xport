#include "native_call_dispatch.h"

uint32 sub_80035730(void)
{
    FUNCTION_MARKER(0x80035730, "1.EXE");
    return sub_800205C8(1, 32, 1);
}

uint32 sub_800375CC(void)
{
    FUNCTION_MARKER(0x800375CC, "1.EXE");
    return sub_800899C0(0, 1);
}

uint32 sub_80059A48(uint32 progress)
{
    FUNCTION_MARKER(0x80059A48, "1.EXE");
    return (uint32)draft_call_adapter(0x80059990, progress);
}

uint32 sub_80059A68(uint32 progress)
{
    FUNCTION_MARKER(0x80059A68, "1.EXE");
    return (uint32)draft_call_adapter(0x80059990, progress);
}

uint32 sub_80031F20(void)
{
    uint32 mode, flags;
    FUNCTION_MARKER(0x80031F20, "1.EXE");
    mode = r_u32(0x800A854C);
    flags = r_u32(0x800A7C6C);
    return (mode << 17) | flags;
}

uint32 sub_8005E178(uint32 object)
{
    FUNCTION_MARKER(0x8005E178, "1.EXE");
    return sub_8005E114(object, 50);
}

uint32 sub_800623B0(uint32 object)
{
    uint32 count, model;
    FUNCTION_MARKER(0x800623B0, "1.EXE");
    count = (sub_80069A50() & 3) + 1;
    model = (uint32)r_s16(r_u32(0x800A62EC) + 76);
    return sub_800623F8(object, model, 0x4000, count);
}

uint32 sub_8005A08C(uint32 filename)
{
    uint32 result;
    FUNCTION_MARKER(0x8005A08C, "1.EXE");
    result = sub_8007D3F0(0x800A8670, 0x800A6290);
    if (!result)
        result = (uint32)draft_call_adapter(0x80059E4C, filename);
    return result;
}

uint32 sub_80044074(uint32 y)
{
    uint32 mark, text, result;
    FUNCTION_MARKER(0x80044074, "1.EXE");
    mark = draft_scratch_mark();
    text = draft_scratch_adapter(32);
    w_u16(text, (uint32)r_s16(0x800A5F8C));
    w_u8(text + 2, (uint32)r_s8(0x800A5F8E));
    draft_call_adapter(0x80079CA0, text, r_u32(0x800A8D80));
    result = sub_80044534(0x808080, text, 0, (uint32)(sint32)(sint16)y);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_8003C580(uint32 bytes, uint32 count)
{
    uint32 result = 0;
    FUNCTION_MARKER(0x8003C580, "1.EXE");
    for (uint32 i = 0; i < count; ++i)
    {
        uint32 value = r_u8(bytes) + i;
        ++bytes;
        result += value % 255;
    }
    return result;
}
