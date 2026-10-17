#include "draft_signatures.h"

void sub_80041E10(uint32 packet, uint32 scale_x, uint32 scale_y)
{
    FUNCTION_MARKER(0x80041E10u, "1.EXE");
    w_u16(packet + 24u, scale_x);
    w_u16(packet + 26u, scale_y);
}

uint32 sub_80044988(uint32 ignored, uint32 value, uint32 x, uint32 y)
{
    uint32 glyph, result = 0u;
    sint32 shift;
    FUNCTION_MARKER(0x80044988u, "1.EXE");
    for (shift = 28; shift >= 0; shift -= 4)
    {
        glyph = r_u8(0x800A5F90u + ((value >> shift) & 15u));
        result = (uint32)draft_call_adapter(0x8004328Cu, r_u32(0x800A5F68u), 0x54000040u, glyph, 0x00808080u, x, y, 0u);
        if (shift != 0)
            x += r_u8(r_u32(0x800A5F68u) + 5u * glyph + 2u);
    }
    return result;
}

uint32 sub_800446D8(void)
{
    uint32 first_x, first_y, second_x, second_y, distance;
    FUNCTION_MARKER(0x800446D8u, "1.EXE");
    first_x = 639u - (uint32)((sint32)r_u32(0x800A7E20u) / 512);
    first_y = (uint32)((sint32)r_u32(0x800A7E14u) / 512);
    second_y = (uint32)((sint32)r_u32(0x800A9698u) / 512);
    second_x = 639u - (uint32)((sint32)r_u32(0x800A969Cu) / 512);
    distance = (uint32)draft_call_adapter(0x80069BE0u, first_x - second_x, first_y - second_y);
    sub_80044988(1u, r_u32(0x800A8668u), (uint32)-60, 64u);
    sub_80044988(1u, (uint32)draft_call_adapter(0x80069B38u, 10u), (uint32)-60, 76u);
    sub_80044C78(4u, r_u32(0x800A8FD4u), 46u, 64u);
    sub_80044C78(4u, r_u32(0x800A8698u), 64u, 64u);
    sub_80044C78(4u, r_u32(0x800A87E4u), 82u, 64u);
    sub_80044C78(2u, first_x, (uint32)-60, 88u);
    sub_80044C78(2u, first_y, (uint32)-60, 95u);
    sub_80044C78(2u, second_x, (uint32)-42, 88u);
    sub_80044C78(2u, second_y, (uint32)-42, 95u);
    sub_80044C78(1u, distance, (uint32)-24, 95u);
    sub_80044C78(3u, r_u8(0x800A5F5Cu), (uint32)-24, 88u);
    sub_80044C78(3u, r_u8(0x800A5F5Du), (uint32)-16, 88u);
    sub_80044C78(3u, r_u32(0x800A5F60u), (uint32)-8, 88u);
    sub_80044C78(4u, r_u32(0x800A5628u), 10u, 88u);
    sub_80044C78(4u, r_u32(0x800A9010u), 10u, 95u);
    sub_80044C78(2u, (uint32)((sint32)r_u32(0x800A8538u) / 18204), 28u, 88u);
    sub_80044C78(2u, r_u32(0x800A5630u) >> 9u, 28u, 95u);
    sub_80044C78(2u, r_u32(0x800A853Cu) >> 10u, 46u, 88u);
    sub_80044C78(2u, r_u32(0x800A853Cu) >> 9u, 64u, 88u);
    return sub_80044C78(2u, (uint32)((sint32)r_u32(0x800A87E8u) / 1024), 46u, 95u);
}

uint32 sub_80043BBC(uint32 color, uint32 icon, uint32 x, uint32 y)
{
    uint32 record, palette, packet = 0x800A98D4u, scale_x, scale_y, result;
    sint32 step;
    FUNCTION_MARKER(0x80043BBCu, "1.EXE");
    icon &= 255u;
    if (r_u32(0x800A5F78u) == icon)
    {
        step = (sint16)(2u * (uint32)((sint32)r_u32(0x800A63D8u) >> 8));
        scale_x = r_u32(0x800A5F70u) - (uint32)step;
        scale_y = r_u32(0x800A5F74u) - (uint32)step;
        w_u32(0x800A5F70u, scale_x);
        w_u32(0x800A5F74u, scale_y);
        if ((sint32)scale_x <= 0)
        {
            w_u32(0x800A5F70u, 0u);
            w_u32(0x800A9868u, 0u);
        }
        if ((sint32)scale_y <= 0)
        {
            w_u32(0x800A5F74u, 0u);
            w_u32(0x800A9868u, 0u);
        }
    }
    else
    {
        w_u32(0x800A5F70u, 28672u);
        w_u32(0x800A5F74u, 28672u);
        w_u32(0x800A5F78u, icon);
    }
    record = 0x80090982u + 5u * icon;
    palette = 2u * r_u8(record + 2u);
    draft_call_adapter(0x80041C9Cu, packet, 0x74000040u, (uint32)(sint32)(sint16)(r_u8(record) - 1u), r_u8(record + 1u), r_u16(0x800903B4u + palette), (uint32)(sint32)(sint16)(r_u8(record - 2u) + r_u16(0x800903E4u + palette)), r_u8(record - 1u), (uint32)(sint32)(sint16)r_u16(0x800903C4u + palette), 481u);
    draft_call_adapter(0x80041D90u, packet, color);
    draft_call_adapter(0x80041DB4u, packet, x, y, 0u);
    draft_call_adapter(0x80041DE0u, packet, r_u8(record) >> 1u, r_u8(record + 1u) >> 1u);
    sub_80041E10(packet, r_u32(0x800A5F70u), r_u32(0x800A5F74u));
    sub_80020764(packet, r_u32(0x800A9A74u) + 720u, 1u, 0u);
    result = r_u32(0x800A9868u);
    if (result == 0u)
    {
        result = 28672u;
        if (icon == 0u)
        {
            w_u32(0x800A5F70u, 28672u);
            w_u32(0x800A5F74u, 28672u);
            w_u32(0x800A5F78u, 4u);
            result = 4u;
        }
    }
    return result;
}
