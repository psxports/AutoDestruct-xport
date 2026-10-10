#include "draft_signatures.h"

static void draft_root_rotation(uint32 matrix)
{
    uint32 first = r_u32(matrix);
    uint32 second = r_u32(matrix + 4u);
    xport_gte_write_control(0u, first);
    xport_gte_write_control(1u, second);
    first = r_u32(matrix + 8u);
    second = r_u32(matrix + 12u);
    uint32 third = r_u32(matrix + 16u);
    xport_gte_write_control(2u, first);
    xport_gte_write_control(3u, second);
    xport_gte_write_control(4u, third);
}

static void draft_root_translation(uint32 translation)
{
    uint32 first = r_u32(translation);
    uint32 second = r_u32(translation + 4u);
    uint32 third = r_u32(translation + 8u);
    xport_gte_write_control(5u, first);
    xport_gte_write_control(6u, second);
    xport_gte_write_control(7u, third);
}

static void draft_root_vector(uint32 vector)
{
    uint32 xy = r_u16(vector) | ((uint32)r_u16(vector + 4u) << 16u);
    xport_gte_write_data(0u, xy);
    xport_gte_write_data(1u, r_u32(vector + 8u));
}

static void draft_root_mac(uint32 destination)
{
    w_u32(destination, xport_gte_read_data(25u));
    w_u32(destination + 4u, xport_gte_read_data(26u));
    w_u32(destination + 8u, xport_gte_read_data(27u));
}

uint32 sub_80040E78(uint32 a0, uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80040E78u, "1.EXE");
    w_u32(a0 + 0x1B0u, (uint32)r_s16(a1 + 2u));
    uint32 result = (uint32)r_s16(a1 + 10u);
    w_u32(a0 + 0x1B4u, 0u);
    w_u32(a0 + 0x1B8u, result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

void sub_80031EA8(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80031EA8u, "1.EXE");
    draft_root_rotation(a0);
    draft_root_translation(a1);
    draft_root_vector(a2);
    xport_gte_mvmva(0x480012u);
    draft_root_mac(a2);

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800407C0(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800407C0u, "1.EXE");
    uint32 step = r_u32(0x800A9010u);
    uint32 product = (uint32)r_s16(a0 + 10u) * step;
    uint32 position = r_u16(a0 + 36u) + step * 5u;
    w_u16(a0 + 36u, (uint16)position);
    w_u16(a0 + 38u, (uint16)(r_u16(a0 + 38u) + product));
    uint32 result = (r_s16(a0 + 10u) >> 2) < (sint16)position;
    if (result != 0u)
    {
        uint32 resource = r_u32(0x800A62ECu);
        w_u32(a0, 0x80040840u);
        result = (uint32)r_s16(resource + 0x36u);
        w_u16(a0 + 32u, (uint16)result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80040840(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80040840u, "1.EXE");
    uint32 step = r_u32(0x800A9010u);
    uint32 product = step * (uint32)r_s16(a0 + 10u);
    uint32 position = r_u16(a0 + 36u) + step * 5u;
    w_u16(a0 + 36u, (uint16)position);
    w_u16(a0 + 38u, (uint16)(r_u16(a0 + 38u) + product));
    uint32 result = (r_s16(a0 + 8u) >> 1) < (sint16)position;
    if (result != 0u)
    {
        uint32 resource = r_u32(0x800A62ECu);
        w_u32(a0, 0x800408C0u);
        result = (uint32)r_s16(resource + 0x3Cu);
        w_u16(a0 + 32u, (uint16)result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8004094C(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8004094Cu, "1.EXE");
    uint32 step = r_u32(0x800A9010u);
    uint32 product = step * (uint32)r_s16(a0 + 10u);
    // Original range falls through with its LO product
    return draft_scratch_result(native_stack_mark, (uint64)(sub_80040964(step, a0, product)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80040964(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80040964u, "1.EXE");
    // The third argument carries LO from the preceding entry
    uint32 position = r_u16(a1 + 36u) + a0 * 5u;
    w_u16(a1 + 36u, (uint16)position);
    w_u16(a1 + 38u, (uint16)(r_u16(a1 + 38u) + a2));
    sint32 limit = r_s16(a1 + 8u);
    uint32 result = limit < (sint16)position;
    if (result != 0u)
    {
        sint32 delay = r_s16(a1 + 16u);
        w_u16(a1 + 36u, (uint16)limit);
        if (delay != 0)
            result = 0x800409E4u;
        else
        {
            result = 0x80040A38u;
            w_u16(a1 + 18u, 0u);
        }
        w_u32(a1, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800409E4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x800409E4u, "1.EXE");
    uint32 step = r_u32(0x800A9010u);
    uint32 product = step * (uint32)r_s16(a0 + 10u);
    uint32 delay = r_u16(a0 + 16u) - step;
    w_u16(a0 + 16u, (uint16)delay);
    uint32 result = r_u16(a0 + 38u) + product;
    w_u16(a0 + 38u, (uint16)result);
    if ((sint16)delay < 0)
    {
        result = 0x80040AECu;
        w_u32(a0, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

void sub_80031E30(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80031E30u, "1.EXE");
    draft_root_rotation(a0);
    draft_root_translation(a1);
    draft_root_vector(a2);
    xport_gte_mvmva(0x480012u);
    draft_root_mac(a1);

    draft_scratch_release(native_stack_mark);
}

void sub_80031BBC(uint32 a0, uint32 a1, uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80031BBCu, "1.EXE");
    draft_root_rotation(a0);
    draft_root_vector(a1);
    // TODO Bind the zero-translation MVMVA command
    draft_gte_command_adapter(0x486012u);
    draft_root_mac(a2);

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006DF90(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8006DF90u, "1.EXE");
    uint32 offset = r_u32(0x800A6440u) * 12u;
    uint32 first = r_u32(a0);
    uint32 second = r_u32(a0 + 4u);
    uint32 third = r_u32(a0 + 8u);
    w_u32(0x800A74F8u + offset, first);
    w_u32(0x800A74FCu + offset, second);
    w_u32(0x800A7500u + offset, third);
    uint32 result = r_u32(0x800A6440u) + 1u;
    w_u32(0x800A6440u, result);
    if (result == 8u)
        w_u32(0x800A6440u, 0u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

void sub_8007040C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8007040Cu, "1.EXE");
    w_u32(0x800A646Cu, 0u);
    w_u32(0x800A6454u, 0u);
    w_u32(0x800A8B30u, 0u);
    w_u32(0x800A6468u, 0u);

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8002A8F0(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8002A8F0u, "1.EXE");
    uint32 result = r_u8(0x800A5774u + (uint32)r_s16(a0 + 58u));
    w_u16(a0 + 56u, (uint16)result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005F478(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8005F478u, "1.EXE");
    uint32 step = r_u32(0x800A9010u);
    uint32 product = step * (uint32)r_s16(a0 + 18u);
    w_u8(a0 + 13u, (uint8)(r_u8(a0 + 13u) - step));
    uint32 cursor = r_u32(a0 + 24u);
    sint32 remaining = (sint8)r_u8(a0 + 13u);
    uint32 result = r_u16(a0 + 38u);
    w_u32(a0 + 24u, cursor - step * 12u);
    result += product;
    w_u16(a0 + 38u, (uint16)result);
    if (remaining < 0)
    {
        result = 0x8005F4E4u;
        w_u32(a0, result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003DB0C(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8003DB0Cu, "1.EXE");
    if ((r_u8(a0 + 13u) & 0x7Fu) != 1u)
        return draft_scratch_result(native_stack_mark, (uint64)(0u));
    return draft_scratch_result(native_stack_mark, (uint64)((r_u32(0x800A7E80u) & 0xFF00FF00u) == 0u));

    draft_scratch_release(native_stack_mark);
}

void sub_80031D50(uint32 a0, uint32 a1, uint32 a2, uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80031D50u, "1.EXE");
    draft_root_rotation(a0);
    draft_root_translation(a1);
    draft_root_vector(a2);
    xport_gte_mvmva(0x480012u);
    draft_root_mac(a3);

    draft_scratch_release(native_stack_mark);
}

void sub_8006525C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x8006525Cu, "1.EXE");
    uint32 count = r_u32(0x800A7C70u);
    if ((sint32)count > 0)
    {
        uint32 cursor = r_u32(0x800A9A80u) + (count << 4u);
        do
        {
            cursor -= 16u;
            uint32 upper = r_u16(cursor + 14u);
            uint32 lower = r_u16(cursor + 6u);
            uint32 target = lower | (upper << 16u);
            uint32 value = r_u32(target);
            --count;
            w_u32(target, value & 0x7FFFFFFFu);
        } while ((sint32)count > 0);
    }
    w_u32(0x800A7C70u, 0u);
    // TODO Original leaves V0 unchanged when the count is nonpositive

    draft_scratch_release(native_stack_mark);
}
