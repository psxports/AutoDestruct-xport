#include "native_call_dispatch.h"

uint32 sub_80067898(uint32 object)
{
    uint32 flags = r_u8(object + 14);
    FUNCTION_MARKER(0x80067898, "1.EXE");
    w_u8(object + 34, 11);
    w_u32(object, 0x80068124);
    w_u32(object + 16, 0x800910B4);
    w_u16(object + 76, 0);
    w_u16(object + 78, 0);
    w_u16(object + 80, 0);
    w_u16(object + 56, 0);
    w_u8(object + 14, flags | 0x20);
    return 0x800910B4;
}

uint32 sub_80067D7C(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 x_angle, yaw, z_angle, object, model, flags, models, x, z;
    FUNCTION_MARKER(0x80067D7C, "1.EXE");
    x_angle = (r_u16(record + 6) & 31) << 7;
    yaw = (r_u32(record + 4) >> 14) & 0xF80;
    z_angle = (r_u32(record + 4) >> 19) & 0xF80;
    object = (uint32)draft_call_adapter(0x800226E4, 84);
    w_u32(object + 20, base_x + (r_u32(record) & 0xFFF));
    w_u32(object + 28, base_z + ((r_u32(record) >> 12) & 0xFFF));
    w_u32(object + 24, 0 - (uint32)r_u16(record + 4));
    model = r_u8(record + 11);
    models = r_u32(0x800A8FD8);
    flags = r_u8(object + 14);
    model = r_u16(models + 2 * model);
    w_u8(object + 14, flags | 2);
    w_u16(object + 32, model);
    sub_80054F40(x_angle, yaw, z_angle, object + 36);
    x = r_u32(object + 20);
    z = r_u32(object + 28);
    w_u32(object + 8, record);
    w_u16(object + 54, (uint32)((sint32)x >> 12) + 80 * (uint32)((sint32)z >> 12));
    w_u16(object + 60, x_angle);
    w_u16(object + 62, yaw);
    w_u16(object + 68, 0);
    w_u16(object + 70, 0);
    w_u16(object + 72, 0);
    w_u16(object + 64, z_angle);
    sub_80067898(object);
    return object;
}

uint32 sub_80067F70(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object;
    FUNCTION_MARKER(0x80067F70, "1.EXE");
    object = sub_80067D7C(record, base_x, base_z);
    w_u16(object + 82, 0);
    return object;
}

uint32 sub_80067F94(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object;
    FUNCTION_MARKER(0x80067F94, "1.EXE");
    object = sub_80067D7C(record, base_x, base_z);
    w_u16(object + 82, 1);
    return object;
}

uint32 sub_80067FBC(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object;
    FUNCTION_MARKER(0x80067FBC, "1.EXE");
    object = sub_80067D7C(record, base_x, base_z);
    w_u16(object + 82, 2);
    return object;
}

static uint32 map_effect_angle_magnitude(uint32 angle)
{
    sint32 signed_angle = angle >= 2049 ? (sint32)angle - 4096 : (sint32)angle;
    return (uint32)(signed_angle < 0 ? -signed_angle : signed_angle);
}

uint32 sub_80067ED0(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object, packed;
    FUNCTION_MARKER(0x80067ED0, "1.EXE");
    object = sub_80067D7C(record, base_x, base_z);
    w_u16(object + 82, 1);
    packed = r_u32(record + 4);
    if (map_effect_angle_magnitude((packed >> 9) & 0xF80) >= 512)
        return 0;
    if (map_effect_angle_magnitude((packed >> 19) & 0xF80) >= 512)
        return 0;
    return sub_800678D8(object);
}

uint32 sub_80068084(uint32 record, uint32 base_x, uint32 base_z)
{
    uint32 object, packed;
    FUNCTION_MARKER(0x80068084, "1.EXE");
    object = sub_80067D7C(record, base_x, base_z);
    w_u16(object + 82, 2);
    packed = r_u32(record + 4);
    if (map_effect_angle_magnitude((packed >> 9) & 0xF80) >= 64)
        return 0;
    if (map_effect_angle_magnitude((packed >> 19) & 0xF80) >= 64)
        return 0;
    return sub_80067A94(object, (packed >> 14) & 0xF80);
}

uint32 sub_80068988(uint32 position, uint32 category, uint32 repeated)
{
    FUNCTION_MARKER(0x80068988, "1.EXE");
    return (uint32)draft_call_adapter(0x80035A08, category ? 53 : 8, 2048, 0, position, 0);
}

uint32 sub_800682B4(uint32 value)
{
    FUNCTION_MARKER(0x800682B4, "1.EXE");
    return value == 0xFFFFFFFF ? 0 : (uint32)((sint32)value >> 1);
}

uint32 sub_80068124(uint32 object)
{
    uint32 length, random, x_positive, z_positive, vertical, category;
    sint32 impulse;
    FUNCTION_MARKER(0x80068124, "1.EXE");
    if (r_u8(object + 12) < 4)
        return 1;
    if (!r_u16(object + 56))
        return sub_80029970(object, 0, 10, 0, object + 20);
    length = sub_80069BE0((uint32)r_s16(object + 68), (uint32)r_s16(object + 72));
    if ((sint32)length >= 101)
        sub_80065588(object + 68, 100);
    w_u32(object, 0x800682CC);
    w_u16(object + 66, (sub_80069A50() & 0x7F) - 63);
    random = sub_80069A50();
    x_positive = r_s16(object + 68) > 0;
    w_u16(object + 74, (random & 0x7F) - 63);
    random = sub_80069A50() & 15;
    w_u16(object + 68, r_u16(object + 68) + (x_positive ? random : 0 - random));
    z_positive = r_s16(object + 72) > 0;
    random = sub_80069A50() & 15;
    w_u16(object + 72, r_u16(object + 72) + (z_positive ? random : 0 - random));
    impulse = (sint32)length >> 1;
    if (impulse >= 31)
        impulse = 30;
    random = sub_80069A50();
    category = (uint32)r_s16(object + 82);
    vertical = r_u16(object + 70);
    w_u16(object + 56, 0);
    w_u16(object + 70, vertical - ((uint32)impulse + (random & 7)));
    return sub_80068988(object + 20, category, 0);
}

uint32 sub_800686BC(uint32 owner, uint32 model, uint32 contact)
{
    uint32 object, z, flags, matrix[4], record;
    FUNCTION_MARKER(0x800686BC, "1.EXE");
    object = (uint32)draft_call_adapter(0x800226E4, 104);
    w_u8(object + 34, 11);
    w_u32(object + 20, r_u32(owner + 20));
    w_u32(object + 24, r_u32(owner + 24));
    z = r_u32(owner + 28);
    flags = r_u8(object + 14);
    w_u16(object + 32, model);
    w_u8(object + 14, flags | 2);
    w_u32(object + 28, z);
    for (uint32 i = 0; i < 4; ++i)
        matrix[i] = r_u32(owner + 36 + 4 * i);
    for (uint32 i = 0; i < 4; ++i)
        w_u32(object + 36 + 4 * i, matrix[i]);
    w_u32(object + 52, r_u32(owner + 52));
    w_u32(object + 16, 0x800910B4);
    flags = r_u8(object + 14);
    w_u32(object, 0x800687EC);
    w_u8(object + 14, flags | 0x20);
    record = r_u32(owner + 8);
    w_u32(object + 76, 0);
    w_u32(object + 80, 0);
    w_u32(object + 84, 0);
    w_u16(object + 92, 0);
    w_u16(object + 94, 0);
    w_u16(object + 88, 20);
    w_u16(object + 90, 20);
    w_u16(object + 102, contact);
    w_u32(object + 8, record);
    w_u16(object + 96, r_u16(owner + 60) + (uint32)r_u16(owner + 76));
    w_u16(object + 98, r_u16(owner + 62));
    w_u16(object + 100, r_u16(owner + 64) + (uint32)r_u16(owner + 78));
    w_u16(object + 56, 0);
    return object;
}

uint32 sub_800688AC(uint32 owner)
{
    uint32 object, flags, model, matrix[4], x_velocity;
    FUNCTION_MARKER(0x800688AC, "1.EXE");
    object = (uint32)draft_call_adapter(0x800226E4, 84);
    w_u32(object + 20, r_u32(owner + 20));
    w_u32(object + 24, r_u32(owner + 24));
    w_u32(object + 28, r_u32(owner + 28));
    flags = r_u8(object + 14);
    model = r_u16(owner + 32);
    w_u8(object + 14, flags | 2);
    w_u16(object + 32, model);
    for (uint32 i = 0; i < 4; ++i)
        matrix[i] = r_u32(owner + 36 + 4 * i);
    for (uint32 i = 0; i < 4; ++i)
        w_u32(object + 36 + 4 * i, matrix[i]);
    w_u32(object + 52, r_u32(owner + 52));
    w_u32(object + 8, r_u32(owner + 8));
    w_u16(object + 60, r_u16(owner + 96));
    w_u16(object + 62, r_u16(owner + 98));
    w_u16(object + 64, r_u16(owner + 100));
    x_velocity = r_u16(owner + 68);
    w_u16(object + 72, 0);
    w_u16(object + 68, x_velocity);
    w_u16(object + 72, r_u16(owner + 72));
    return sub_80067898(object);
}

uint32 sub_800687EC(uint32 object)
{
    uint32 mark, angles, tile;
    FUNCTION_MARKER(0x800687EC, "1.EXE");
    if (!r_u16(object + 56))
    {
        if (r_s16(object + 102) > 0)
        {
            sub_80052C98(object, object + 76);
            return sub_80029970(object, 0, 10, 0, object + 20);
        }
        mark = draft_scratch_mark();
        angles = draft_scratch_adapter(6);
        w_u16(angles, r_u16(object + 96));
        w_u16(angles + 2, r_u16(object + 98));
        w_u16(angles + 4, r_u16(object + 100));
        tile = sub_80065458(r_u32(object + 8), object, (uint32)r_s16(object + 54), angles);
        w_u16(object + 54, tile);
        draft_scratch_release(mark);
    }
    sub_800688AC(object);
    return sub_8002289C(object);
}

uint32 sub_800682CC(uint32 object)
{
    uint32 tick, mark, scratch, previous, contacts, bounce_x, bounce_z, flags, random, positive;
    uint32 x_rotation, z_rotation, x, y, z, category, result, contact;
    sint32 impulse, vertical, threshold;
    FUNCTION_MARKER(0x800682CC, "1.EXE");
    tick = r_u32(0x800A9010);
    if (r_u16(object + 56))
    {
        w_u16(object + 66, (sub_80069A50() & 0x7F) - 63);
        random = sub_80069A50();
        positive = r_s16(object + 68) > 0;
        w_u16(object + 74, (random & 0x7F) - 63);
        random = sub_80069A50() & 15;
        w_u16(object + 68, r_u16(object + 68) + (positive ? random : 0 - random));
        positive = r_s16(object + 72) > 0;
        random = sub_80069A50() & 15;
        w_u16(object + 72, r_u16(object + 72) + (positive ? random : 0 - random));
        impulse = (sint32)sub_80069BE0((uint32)r_s16(object + 68), (uint32)r_s16(object + 72)) >> 1;
        if (impulse >= 31)
            impulse = 30;
        random = sub_80069A50();
        category = (uint32)r_s16(object + 82);
        w_u16(object + 70, r_u16(object + 70) - ((uint32)impulse + (random & 7)));
        sub_80068988(object + 20, category, 1);
        w_u16(object + 56, 0);
    }
    mark = draft_scratch_mark();
    scratch = draft_scratch_adapter(96);
    previous = scratch;
    contacts = scratch + 16;
    bounce_x = scratch + 80;
    bounce_z = scratch + 84;
    flags = scratch + 88;
    w_u32(previous, r_u32(object + 20));
    w_u32(previous + 4, r_u32(object + 24));
    w_u32(previous + 8, r_u32(object + 28));
    x_rotation = (uint32)r_s16(object + 66) * tick;
    z_rotation = (uint32)r_s16(object + 74) * tick;
    w_u16(object + 76, r_u16(object + 76) + x_rotation);
    x_rotation = r_u16(object + 60) + (uint32)r_u16(object + 76);
    w_u16(object + 78, r_u16(object + 78) + z_rotation);
    z_rotation = r_u16(object + 64) + (uint32)r_u16(object + 78);
    draft_call_adapter(0x80054D38, (uint32)(sint32)(sint16)x_rotation, (uint32)r_s16(object + 62), (uint32)(sint32)(sint16)z_rotation, object + 36);
    x = (uint32)r_s16(object + 68) * tick;
    z = (uint32)r_s16(object + 72) * tick + r_u32(object + 28);
    y = (uint32)r_s16(object + 70) * tick + r_u32(object + 24);
    w_u16(object + 70, r_u16(object + 70) + tick);
    x += r_u32(object + 20);
    w_u32(object + 28, z);
    w_u32(object + 20, x);
    w_u32(object + 24, y);
    if ((uint16)sub_8002F3FC(previous, object + 20))
    {
        w_u32(bounce_x, (uint32)r_s16(object + 68) << 16);
        w_u32(bounce_z, (uint32)r_s16(object + 72) << 16);
        sub_80023918(r_u32(previous), r_u32(previous + 8), bounce_x, bounce_z);
        w_u16(object + 68, r_u16(bounce_x + 2));
        w_u16(object + 72, r_u16(bounce_z + 2));
        w_u32(previous, r_u32(object + 20));
        w_u32(previous + 4, r_u32(object + 24));
        w_u32(previous + 8, r_u32(object + 28));
    }
    result = (uint32)r_s16(object + 70);
    if ((sint32)result >= 0)
    {
        sub_80029DDC(object, contacts, r_u8(r_u32(0x800A8548) + r_u16(object + 32)));
        sub_8002A300(contacts);
        contact = (uint32)(sint32)(sint16)sub_80051328(object, contacts, flags);
        result = 6;
        if (contact)
        {
            if (r_s16(flags) == 6)
            {
                sub_80054934(object, 3);
                sub_800652C0(r_u32(object + 8));
            }
            else
            {
                sub_80029970(object, 0, 10, 0, object + 20);
                sub_80068988(object + 20, (uint32)r_s16(object + 82), 1);
                x = sub_800682B4((uint32)r_s16(object + 66));
                y = (uint32)r_s16(object + 74);
                w_u16(object + 66, x);
                x = sub_800682B4(y);
                y = (uint32)r_s16(object + 68);
                w_u16(object + 74, x);
                x = sub_800682B4(y);
                y = (uint32)r_s16(object + 72);
                w_u16(object + 68, x);
                w_u16(object + 72, sub_800682B4(y));
                threshold = (sint32)(0 - (uint32)((sint32)(5 * tick) >> 1));
                vertical = -(r_s16(object + 70) >> 1);
                result = threshold < vertical;
                w_u16(object + 70, (uint32)vertical);
                if (!result)
                {
                    draft_scratch_release(mark);
                    return result;
                }
                x = (sint32)contact < 0 ? 0 - contact : contact;
                w_u16(object + 80, x);
                sub_800686BC(object, r_u16(object + 32), (uint32)(sint32)(sint16)x);
            }
            result = sub_8002289C(object);
        }
    }
    draft_scratch_release(mark);
    return result;
}
