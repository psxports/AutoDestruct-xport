#include "native_call_dispatch.h"

uint32 sub_800689DC(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object, index, models, flags, model, result;
    FUNCTION_MARKER(0x800689DC, "1.EXE");
    object = (uint32)draft_call_adapter(0x800226E4, 56);
    w_u32(object + 20, base_x + (r_u32(record) & 0xFFF));
    w_u32(object + 28, base_z + ((r_u32(record) >> 12) & 0xFFF));
    w_u32(object + 24, 0 - (uint32)r_u16(record + 4));
    index = r_u8(record + 11);
    models = r_u32(0x800A8FD8);
    flags = r_u8(object + 14);
    model = r_u16(models + 2 * index);
    w_u8(object + 14, flags | 2);
    flags = r_u8(object + 14);
    w_u8(object + 34, 17);
    w_u32(object, 0x80068AD0);
    w_u16(object + 32, model);
    w_u8(object + 14, flags | 0x20);
    w_u32(object + 16, sub_80069A50() & 0x7FF);
    result = sub_800551CC((r_u32(record + 4) >> 14) & 0xF80, object + 36);
    w_u32(object + 8, record);
    return result;
}

uint32 sub_80068AD0(uint32 object)
{
    uint32 record, phase, packed, tick, mark, angles, result;
    FUNCTION_MARKER(0x80068AD0, "1.EXE");
    record = r_u32(object + 8);
    phase = r_u32(object + 16);
    packed = r_u32(record + 4);
    tick = r_u32(0x800A9010);
    mark = draft_scratch_mark();
    angles = draft_scratch_adapter(6);
    w_u16(angles + 2, (packed >> 21) & 31);
    packed = (uint32)r_s16(0x80010AE0 + 2 * (phase & 0xFFF));
    w_u16(angles + 4, 0);
    w_u16(angles, (uint32)((sint32)packed >> 4));
    result = sub_80055288(angles, object + 36);
    w_u32(object + 16, phase + ((tick << 3) & 0xFFF));
    draft_scratch_release(mark);
    return result;
}

uint32 sub_8006909C(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object, index, models, flags, model, packed, x, y, z, result;
    FUNCTION_MARKER(0x8006909C, "1.EXE");
    object = (uint32)draft_call_adapter(0x800226E4, 88);
    w_u32(object + 20, base_x + (r_u32(record) & 0xFFF));
    w_u32(object + 28, base_z + ((r_u32(record) >> 12) & 0xFFF));
    w_u32(object + 24, 0 - (uint32)r_u16(record + 4));
    index = r_u8(record + 11);
    models = r_u32(0x800A8FD8);
    flags = r_u8(object + 14);
    model = r_u16(models + 2 * index);
    w_u8(object + 14, flags | 2);
    flags = r_u8(object + 14);
    w_u8(object + 34, 8);
    w_u32(object, 0x8006922C);
    w_u16(object + 32, model);
    w_u8(object + 14, flags | 0x20);
    sub_800551CC((r_u32(record + 4) >> 14) & 0xF80, object + 36);
    x = r_u32(object + 20);
    z = r_u32(object + 28);
    w_u32(object + 8, record);
    w_u32(object + 16, 0x800910B4);
    w_u16(object + 60, 0);
    w_u16(object + 54, (uint32)((sint32)x >> 12) + 80 * (uint32)((sint32)z >> 12));
    packed = r_u32(record + 4);
    x = r_u32(object + 20);
    y = r_u32(object + 24);
    w_u16(object + 64, 0);
    w_u32(object + 80, y);
    model = r_u16(object + 32);
    w_u32(object + 76, x);
    models = r_u32(0x800A8548);
    w_u16(object + 62, (packed >> 14) & 0xF80);
    index = r_u8(models + model);
    models = r_u32(0x800A90AC) + 40 * index;
    z = r_u32(object + 28);
    result = r_u16(models + 32);
    w_u16(object + 56, 0);
    result = (uint32)((sint32)(result << 16) >> 17);
    w_u32(object + 84, z - 30 + result);
    return result;
}

uint32 sub_8006922C(uint32 object)
{
    FUNCTION_MARKER(0x8006922C, "1.EXE");
    if (r_u16(object + 56))
    {
        w_u32(object, 0x800692B0);
        w_u16(object + 58, 1);
        w_u16(object + 56, 0);
        draft_call_adapter(0x80035A08, 48, 2048, 128, object + 20, 1);
    }
    return sub_80029970(object, 1, 7, 0, object + 20);
}

uint32 sub_800692B0(uint32 object)
{
    uint32 mark, offset, model, index, height, phase, player;
    FUNCTION_MARKER(0x800692B0, "1.EXE");
    if (r_u16(object + 56))
    {
        w_u16(object + 58, 1);
        w_u16(object + 56, 0);
        draft_call_adapter(0x80035A08, 48, 2048, 128, object + 20, 1);
    }
    model = r_u16(object + 32);
    index = r_u8(r_u32(0x800A8548) + model);
    height = r_u16(r_u32(0x800A90AC) + 40 * index + 32);
    height = (uint32)((sint32)(height << 16) >> 17);
    mark = draft_scratch_mark();
    offset = draft_scratch_adapter(8);
    w_u16(offset, 0);
    w_u16(offset + 2, 0);
    w_u16(offset + 4, 30 - height);
    sub_80055288(object + 60, object + 36);
    sub_80031CE8(object + 36, object + 76, offset, object + 20);
    if (r_s16(object + 58) == 1)
    {
        phase = r_u16(object + 60) - 20 * r_u32(0x800A9010);
        w_u16(object + 60, phase);
        if ((sint16)phase < -1024)
        {
            w_u16(object + 60, 0xFC00);
            player = r_u32(0x800A9A58);
            phase = sub_80069BE0(r_u32(object + 20) - r_u32(player + 20), r_u32(object + 28) - r_u32(player + 28));
            if ((sint32)phase >= 1001)
                w_u16(object + 58, 2);
        }
    }
    else
    {
        phase = r_u16(object + 60) + 20 * r_u32(0x800A9010);
        w_u16(object + 60, phase);
        if ((sint16)phase > 0)
        {
            w_u16(object + 60, 0);
            w_u32(object, 0x8006922C);
            w_u16(object + 58, 0);
        }
    }
    draft_scratch_release(mark);
    return sub_80029970(object, 1, 7, 0, object + 20);
}

uint32 sub_8006946C(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object, index, models, flags, model, x, z;
    FUNCTION_MARKER(0x8006946C, "1.EXE");
    object = (uint32)draft_call_adapter(0x800226E4, 84);
    w_u32(object + 20, base_x + (r_u32(record) & 0xFFF));
    w_u32(object + 28, base_z + ((r_u32(record) >> 12) & 0xFFF));
    w_u32(object + 24, 0 - (uint32)r_u16(record + 4));
    index = r_u8(record + 11);
    models = r_u32(0x800A8FD8);
    flags = r_u8(object + 14);
    model = r_u16(models + 2 * index);
    w_u8(object + 14, flags | 2);
    flags = r_u8(object + 14);
    w_u8(object + 34, 17);
    w_u32(object, 0x800695C0);
    w_u16(object + 32, model);
    w_u8(object + 14, flags | 0x20);
    sub_800551CC((r_u32(record + 4) >> 14) & 0xF80, object + 36);
    x = r_u32(object + 20);
    z = r_u32(object + 28);
    w_u32(object + 8, record);
    w_u32(object + 16, 0x800910B4);
    w_u16(object + 54, (uint32)((sint32)x >> 12) + 80 * (uint32)((sint32)z >> 12));
    w_u16(object + 62, (r_u32(record + 4) >> 14) & 0xF80);
    w_u16(object + 76, sub_80069A50());
    w_u16(object + 78, 0xFFFF);
    w_u16(object + 80, 3);
    w_u16(object + 56, 0);
    w_u8(object + 13, 0);
    w_u16(object + 82, 40);
    return 40;
}

uint32 sub_800695C0(uint32 object)
{
    uint32 length, remaining, phase, mode, sine, cosine, x, z;
    FUNCTION_MARKER(0x800695C0, "1.EXE");
    if (r_u32(0x800A9A38) != 3)
    {
        if (r_u8(object + 14) & 1)
            sub_800369E0(object + 20, object + 78, 1024, 69);
        else
            sub_80036CFC(object + 78);
    }
    if (r_u8(object + 12) < 4)
        return 1;
    if (r_u16(object + 56))
    {
        length = sub_80069BE0((uint32)r_s16(object + 68), (uint32)r_s16(object + 72));
        remaining = r_u16(object + 80) - 1;
        mode = (sint32)length > r_s16(object + 82);
        w_u16(object + 80, remaining);
        if (mode && !(uint16)remaining)
        {
            sub_80054934(object, 4);
            sub_800652C0(r_u32(object + 8));
            return sub_8002289C(object);
        }
        w_u16(object + 56, 0);
    }
    else
        sub_80029970(object, 1, 7, 0, object + 20);
    phase = r_u16(object + 76) + (r_u32(0x800A9010) << 4);
    mode = r_u32(0x800A9A38);
    w_u16(object + 76, phase);
    sine = (uint32)(r_s16(0x800102E0 + 2 * (phase & 0xFFF)) >> 6);
    phase = r_u16(object + 76);
    cosine = (uint32)(r_s16(0x80010AE0 + 2 * (phase & 0xFFF)) >> 7);
    x = mode == 1 ? cosine : sine;
    z = mode == 1 ? sine : cosine;
    return (uint32)draft_call_adapter(0x80054D38, x, (uint32)r_s16(object + 62), z, object + 36);
}
