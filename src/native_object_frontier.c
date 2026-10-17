#include "native_call_dispatch.h"

uint32 sub_8002230C(uint32 slot, uint32 tile)
{
    const uint32 gp = 0x800A5628u;
    FUNCTION_MARKER(0x8002230Cu, "1.EXE");
    sint32 row = (sint32)tile / 80;
    uint32 x = ((tile - (uint32)row * 80u) << 12) - r_u32(gp + 0x115Cu);
    uint32 z = ((uint32)row << 12) - r_u32(gp + 0x1164u);
    uint32 result = r_u32(0x800A84F8u) + 8u * tile + 2u * r_u32(gp + 16u);
    uint32 first = r_u16(result);
    if (!first)
        return result;
    uint32 count = r_u16(r_u32(0x800A7E24u) + 2u * (first - 1u));
    uint32 output = (uint32)draft_call_adapter(0x80064B04u, count * 16u);
    w_u32(0x800A9D7Cu + 12u * slot, output);
    uint32 end = output + count * 16u;
    if (count)
        do
        {
            uint32 index = r_u16(r_u32(0x800A7E24u) + 2u * first);
            if ((index & 32767u) == 32767u)
                w_u8(output + 3u, 4u);
            else
            {
                uint32 source = r_u32(0x800A7BFCu) + 8u * index;
                w_u8(output + 3u, r_u16(source + 2u) >> 14);
                source = r_u32(0x800A7BFCu) + 8u * index;
                w_u32(output + 4u, x + (r_u16(source + 2u) & 4095u));
                w_u8(output + 3u, r_u16(source + 2u) >> 14);
                source = r_u32(0x800A7BFCu) + 8u * index;
                w_u32(output + 8u, 0u - r_u16(source + 6u));
                uint32 source_z = r_u16(source + 4u);
                w_u8(output + 2u, 0u);
                source = r_u32(0x800A7BFCu) + 8u * index;
                w_u32(output + 12u, z + (source_z & 4095u));
                w_u16(output, r_u16(source));
            }
            output += 16u;
            ++first;
        } while ((sint32)output < (sint32)end);
    result = 12u * slot;
    w_u16(0x800A9D78u + result, count);
    w_u16(0x800A9D7Au + result, tile);
    return result;
}

uint32 sub_80022528(void)
{
    FUNCTION_MARKER(0x80022528u, "1.EXE");
    for (uint32 i = 0; i < 196u; ++i)
    {
        uint32 entry = 0x800A9D78u + 12u * i;
        if (r_u16(entry))
        {
            sub_80064D60(r_u32(entry + 4u));
            w_u16(entry, 0u);
        }
    }
    uint32 result = 0u;
    for (sint32 i = 195; i >= 0; --i)
    {
        sint32 tile = (sint16)r_u16(0x800A9D7Au + 12u * (uint32)i);
        if (tile != -1)
            result = sub_8002230C((uint32)i, (uint32)tile);
    }
    return result;
}

uint32 sub_800225D8(uint32 packed)
{
    const uint32 gp = 0x800A5628u;
    FUNCTION_MARKER(0x800225D8u, "1.EXE");
    uint32 tile = packed >> 16, row = tile / 80u;
    uint32 x = tile - 80u * row - r_u32(gp + 24u);
    if (x >= 14u)
        return 0u;
    uint32 z = row - r_u32(gp + 28u);
    if (z >= 14u)
        return 0u;
    sint32 column = (sint32)(x + r_u32(gp + 32u)) % 14;
    sint32 ring_row = (sint32)(z + r_u32(gp + 36u)) % 14;
    uint32 result = r_u32(0x800A9D7Cu + 12u * (uint32)(14 * ring_row + column)) + 16u * (packed & 65535u);
    w_u8(result + 3u, 4u);
    return result;
}

uint32 sub_80029538(uint32 index)
{
    FUNCTION_MARKER(0x80029538u, "1.EXE");
    uint32 resource = r_u32(0x800A62ECu), object = r_u32(0x800A7BACu), models = r_u32(0x800A8548u);
    w_u16(object + 32u, r_u16(resource + (uint32)((sint32)(sint16)index * 2)));
    uint32 model = r_u8(models + r_u16(object + 32u));
    w_u32(object + 548u, 65536u);
    uint32 shape = r_u32(0x800A9750u) + 40u * r_u8(models + r_u16(object + 32u));
    uint32 size = (uint32)(5 * ((sint16)r_u16(shape + 34u) >> 8));
    uint32 product = (uint32)((sint32)(size << 24) >> 8) * 110u;
    w_u32(object + 508u, size << 8);
    uint32 portion = (uint32)((sint32)product >> 16);
    w_u32(object + 524u, portion);
    w_u32(object + 528u, r_u32(object + 508u) - portion);
    uint32 radius = (uint32)(sint32)(sint16)r_u16(r_u32(0x800A90ACu) + 40u * model + 36u);
    uint32 mass = r_u32(object + 508u);
    w_u32(object + 512u, (uint32)((sint32)(radius * radius + mass * mass) / 1632));
    if (r_u16(object + 32u) == (uint32)(sint32)(sint16)r_u16(resource + 26u))
    {
        w_u8(object + 14u, r_u8(object + 14u) | 128u);
        w_u32(0x800A56C8u, 1u);
        return (uint32)draft_call_adapter(0x80063888u, object);
    }
    uint32 result = r_u8(object + 14u) & 127u;
    w_u8(object + 14u, result);
    w_u32(0x800A56C8u, 0u);
    return result;
}

uint32 sub_800582D4(uint32 kind)
{
    const uint32 gp = 0x800A5628u;
    FUNCTION_MARKER(0x800582D4u, "1.EXE");
    uint32 best = 0u, i = 0u, table = r_u32(0x800A8694u);
    sint32 distance = 10000;
    while ((sint16)r_u16(table + 8u * i) != -1)
    {
        uint32 entry = table + 8u * i;
        if ((uint32)(sint32)(sint16)r_u16(entry) == kind)
        {
            sint32 current = (sint32)sub_80069C78((uint32)((sint32)r_u32(gp + 0x27F8u) / 8) - r_u16(entry + 4u), (uint32)((sint32)r_u32(gp + 0x27ECu) / 8) - r_u16(entry + 2u));
            if (current < distance)
            {
                distance = current;
                best = i;
            }
        }
        ++i;
        table = r_u32(0x800A8694u);
    }
    uint32 entry = r_u32(0x800A8694u) + 8u * best;
    return (sub_80055A9C(8u * r_u16(entry + 2u) - r_u32(gp + 0x27ECu), 8u * r_u16(entry + 4u) - r_u32(gp + 0x27F8u)) - r_u32(gp + 0x2EF0u) - 1024u) & 4095u;
}

void sub_80031770(void)
{
    const uint32 gp = 0x800A5628u;
    FUNCTION_MARKER(0x80031770u, "1.EXE");
    if (r_u32(0x800A9688u) && r_u32(0x800A968Cu))
    {
        w_u32(gp + 0x160Cu, 60u);
        if (r_u32(0x800A9688u) == r_u32(gp + 0x1614u) && r_u32(0x800A968Cu) == r_u32(gp + 0x1618u))
        {
            uint32 elapsed = r_u32(gp + 0x1610u), tick = r_u32(0x800A9010u);
            if (((sint32)elapsed < 15 && (sint32)(elapsed + tick) >= 15) || ((sint32)elapsed < 30 && (sint32)(elapsed + tick) >= 30) || ((sint32)elapsed < 45 && (sint32)(elapsed + tick) >= 45))
            {
                draft_call_adapter(0x80035A08u, 27u, 2048u, 255u, 0u, 0u);
                elapsed = r_u32(gp + 0x1610u);
            }
            if ((sint32)elapsed < 50)
                w_u32(gp + 0x1610u, elapsed + r_u32(0x800A9010u));
        }
        else
        {
            if (r_u32(gp + 0x1614u))
            {
                draft_call_adapter(0x80035A08u, 27u, 2048u, 255u, 0u, 0u);
                w_u32(gp + 0x1610u, 0u);
            }
            else
                w_u32(gp + 0x1610u, 50u);
            w_u32(gp + 0x1614u, r_u32(0x800A9688u));
            w_u32(gp + 0x1618u, r_u32(0x800A968Cu));
        }
        uint32 angle = (sub_80055A9C(r_u32(gp + 0x1614u) - r_u32(0x800A7E14u), r_u32(gp + 0x1618u) - r_u32(0x800A7E20u)) - r_u16(0x800A8518u) + 2048u) & 4095u;
        sint32 signed_angle = (sint16)(angle >= 2049u ? angle | 0xF000u : angle);
        uint32 target = (uint32)((signed_angle + 512) >> 10) << 10;
        uint32 current = r_u16(gp + 0x1606u), delta = (current - target) & 4095u;
        sint32 difference = (sint16)(delta >= 2049u ? delta | 0xF000u : delta);
        sint32 step = (sint32)(r_u32(0x800A63D8u) << 6) >> 16;
        if (difference < 0)
        {
            if (difference < -step)
                target = current + (uint32)step;
        }
        else if (step < difference)
            target = current - (uint32)step;
        w_u16(gp + 0x1606u, target);
    }
    else
    {
        uint32 remaining = r_u32(gp + 0x160Cu);
        if ((sint32)remaining <= 0)
            return;
        w_u32(gp + 0x160Cu, remaining - r_u32(0x800A9010u));
    }
    w_u16(gp + 0x1604u, 200u);
    w_u16(gp + 0x1608u, 0u);
    w_u32(gp + 0x15F4u, 0u);
    w_u32(gp + 0x15F8u, 0u);
    w_u32(gp + 0x15FCu, 500u);
    uint32 mark = draft_scratch_mark(), local = draft_scratch_adapter(40u);
    w_u32(local, 0u);
    w_u32(local + 4u, 0u);
    w_u32(local + 8u, 500u);
    w_u16(local + 12u, r_u16(r_u32(0x800A62ECu) + 452u));
    draft_call_adapter(0x80055134u, 0x800A6C2Cu, local + 16u);
    sub_80020300(local, r_u32(0x800A9A74u), 70u, 0u, (uint32)-88);
    draft_scratch_release(mark);
}
