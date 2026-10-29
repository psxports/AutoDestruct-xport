#include "native_call_dispatch.h"
#include <string.h>

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
    return sub_800623F8(object, model, 0x4000, count, 0);
}

uint32 sub_8005A08C(uint32 filename)
{
    FUNCTION_MARKER(0x8005A08C, "1.EXE");
    // Extracted DATA replaces the original SLUS disc-identity check
    return 1u;
}

uint32 sub_80044074(uint32 y)
{
    uint32 mark, text, result, source;
    size_t available;
    const char *suffix;
    FUNCTION_MARKER(0x80044074, "1.EXE");
    mark = draft_scratch_mark();
    text = draft_scratch_adapter(32);
    w_u16(text, (uint32)r_s16(0x800A5F8C));
    w_u8(text + 2, (uint32)r_s8(0x800A5F8E));
    source = r_u32(0x800A8D80);
    if (source)
    {
        // The original three-byte prefix includes its terminator
        available = 32 - strlen((const char *)psx_addr(text, 3));
        suffix = (const char *)psx_addr(source, (uint32)available);
        if (!memchr(suffix, 0, available))
            abort();
        strcat((char *)psx_addr(text, 32), suffix);
    }
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

uint32 sub_8003D0D4(uint32 destination, uint32 value)
{
    FUNCTION_MARKER(0x8003D0D4, "1.EXE");
    if ((sint32)value > 0)
    {
        --value;
        w_u16(destination, value);
    }
    return value;
}

// Recovered entry 8003D0BC supplies the counter loaded before the exported tail
uint32 decrement_weapon_stock(uint32 weapon)
{
    uint32 counter = 0x800A5EAC + ((uint32)(sint32)(sint16)weapon << 1);
    return sub_8003D0D4(counter, (uint32)r_s16(counter));
}

uint32 sub_80055A44(uint32 matrix, uint32 product)
{
    uint32 result;
    FUNCTION_MARKER(0x80055A44, "1.EXE");
    w_u16(matrix + 14, 0);
    w_u16(matrix + 10, 0);
    w_u16(matrix + 6, 0);
    w_u16(matrix + 2, 0);
    result = (uint32)((sint32)product >> 12);
    w_u16(matrix + 16, result);
    return result;
}

// Recovered entry 800559C4 supplies the product consumed by the exported tail
uint32 build_scaled_yaw_matrix(uint32 angle, uint32 matrix, uint32 scale)
{
    uint32 offset = (angle & 4095) << 1;
    uint32 sine = (uint32)r_s16(0x80010AE0 + offset);
    uint32 product = sine * r_u32(scale);
    uint32 cosine = (uint32)r_s16(0x800102E0 + offset);
    w_u16(matrix, (uint32)((sint32)product >> 12));
    product = cosine * r_u32(scale + 8);
    w_u16(matrix + 4, (uint32)((sint32)product >> 12));
    w_u16(matrix + 8, r_u16(scale + 4));
    product = (0 - cosine) * r_u32(scale);
    w_u16(matrix + 12, (uint32)((sint32)product >> 12));
    product = sine * r_u32(scale + 8);
    return sub_80055A44(matrix, product);
}

// Recovered unexported entry 800558C4 scales the nine rotation coefficients
void scale_rotation_columns(uint32 matrix, uint32 scale)
{
    /* TODO Review incidental original V0 use when a semantic caller is recovered */
    ScaleMatrix((MATRIX *)psx_addr(matrix, 18u), (VECTOR *)psx_addr(scale, 12u));
}
