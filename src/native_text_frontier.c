#include "draft_signatures.h"

void sub_80076FE8(uint32 value)
{
    FUNCTION_MARKER(0x80076FE8u, "1.EXE");
    w_u32(0x800A7788u, value);
}

void sub_80076FF4(uint32 value)
{
    FUNCTION_MARKER(0x80076FF4u, "1.EXE");
    w_u32(0x800A778Cu, value);
}

void sub_80077000(uint32 value)
{
    FUNCTION_MARKER(0x80077000u, "1.EXE");
    w_u32(0x800A7790u, value);
}

uint32 sub_800325BC(uint32 text, uint32 value)
{
    FUNCTION_MARKER(0x800325BCu, "1.EXE");
    uint32 tens = (uint8)((sint32)value / 10);
    uint32 remainder = (uint8)(value - 10u * tens);
    w_u8(text, tens + 48u);
    uint32 result = remainder + 48u;
    w_u8(text + 1u, result);
    return result;
}

uint32 sub_80044588(uint32 color, uint32 text, uint32 x, uint32 y)
{
    FUNCTION_MARKER(0x80044588u, "1.EXE");
    return sub_800442FC(1u, 0x8009091Cu, color, text, (uint32)(sint32)(sint16)x, (uint32)(sint32)(sint16)y, 180u);
}

uint32 sub_80044040(void)
{
    FUNCTION_MARKER(0x80044040u, "1.EXE");
    return sub_800436D4(128u, r_u32(0x800A8D4Cu), (uint32)-142, 92u, 0u);
}

uint32 sub_80032E6C(uint32 unused, uint32 color, uint32 first, uint32 second, uint32 third, uint32 x, uint32 y)
{
    FUNCTION_MARKER(0x80032E6Cu, "1.EXE");
    uint32 mark = draft_scratch_mark();
    uint32 text = draft_scratch_adapter(16u);
    uint32 word0 = r_u32(0x800A5BECu);
    uint32 word1 = r_u32(0x800A5BF0u);
    uint32 word2 = r_u32(0x800A5BF4u);
    w_u32(text, word0);
    w_u32(text + 4u, word1);
    w_u32(text + 8u, word2);
    sub_800325BC(text + 2u, first);
    sub_800325BC(text + 5u, second);
    sub_800325BC(text + 8u, third);
    w_u8(text + 4u, 18u);
    w_u8(text + 7u, 18u);
    uint32 result = sub_80044588(color, text, x, y);
    draft_scratch_release(mark);
    return result;
}

uint32 sub_800781CC(uint32 glyph, uint32 color, uint32 x, uint32 y, uint32 depth)
{
    FUNCTION_MARKER(0x800781CC, "1.EXE");
    uint32 entry = r_u32(0x800A5F68) + 5 * glyph;
    uint32 category = r_u8(entry + 4);
    uint32 width = r_u8(entry + 2);
    uint32 height = r_u8(entry + 3);
    uint32 page = r_u16(0x800903B4 + 2 * category);
    uint32 u = r_u8(entry);
    uint32 v = r_u8(entry + 1);
    category = r_u8(entry + 4);
    uint32 clut_x = (uint32)(sint32)(sint16)r_u16(0x800903C4 + 2 * category);
    draft_call_adapter(0x80041C9C, 0x800A98D4, 0x54000040, width, height, page, u, v, clut_x, 481);
    draft_call_adapter(0x80041D90, 0x800A98D4, color);
    draft_call_adapter(0x80041DB4, 0x800A98D4, x, y, 0);
    return (uint32)draft_call_adapter(0x80020AB4, 0x800A98D4, r_u32(0x800A9A74) + 4 * depth, 1, 0);
}
