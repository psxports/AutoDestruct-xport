#include "draft_signatures.h"

static void object_transfer_words(uint32 destination, uint32 source, uint32 bytes)
{
    uint32 first, second, third, fourth;
    while (bytes >= 16u)
    {
        first = r_u32(source);
        second = r_u32(source + 4u);
        third = r_u32(source + 8u);
        fourth = r_u32(source + 12u);
        w_u32(destination, first);
        w_u32(destination + 4u, second);
        w_u32(destination + 8u, third);
        w_u32(destination + 12u, fourth);
        source += 16u;
        destination += 16u;
        bytes -= 16u;
    }
    if (bytes == 8u)
    {
        first = r_u32(source);
        second = r_u32(source + 4u);
        w_u32(destination, first);
        w_u32(destination + 4u, second);
    }
    else if (bytes == 4u)
    {
        w_u32(destination, r_u32(source));
    }
}

uint32 sub_8004561C(uint32 destination, uint32 source)
{
    uint32 flags, type, index, list, owner, first, second, third;
    sint32 count, reference;
    FUNCTION_MARKER(0x8004561Cu, "1.EXE");

    if (r_u32(0x800A9A58u) == source)
        w_u32(0x800A9A58u, destination);
    if (r_u32(0x800A622Cu) == source)
        w_u32(0x800A622Cu, destination);
    if (r_u16(0x800A9730u) == r_u16(source + 68u))
        w_u16(0x800A9730u, r_u16(destination + 68u));
    if (r_u16(0x800A9A78u) == r_u16(source + 68u))
        w_u16(0x800A9A78u, r_u16(destination + 68u));
    flags = r_u8(destination + 14u) & 8u;
    w_u8(destination + 64u, r_u8(source + 64u));
    w_u8(destination + 14u, flags ? r_u8(source + 14u) | 8u : r_u8(source + 14u) & 0xF7u);
    object_transfer_words(destination + 20u, source + 20u, 36u);
    w_u16(destination + 58u, r_u16(source + 58u));
    w_u16(destination + 176u, r_u16(source + 176u));
    w_u32(destination + 100u, r_u32(source + 100u));
    w_u32(destination + 104u, r_u32(source + 104u));
    w_u16(destination + 182u, r_u16(source + 182u));
    w_u16(destination + 180u, r_u16(source + 180u));
    w_u16(destination + 186u, r_u16(source + 186u));
    w_u16(destination + 184u, r_u16(source + 184u));
    w_u16(destination + 112u, r_u16(source + 112u));
    w_u32(destination + 92u, r_u32(source + 92u));
    w_u32(destination + 96u, r_u32(source + 96u));
    first = r_u32(destination + 20u);
    second = r_u32(destination + 24u);
    third = r_u32(destination + 28u);
    w_u32(destination + 116u, first);
    w_u32(destination + 120u, second);
    w_u32(destination + 124u, third);
    first = r_u32(source + 128u);
    second = r_u32(source + 132u);
    third = r_u32(source + 136u);
    w_u32(destination + 128u, first);
    w_u32(destination + 132u, second);
    w_u32(destination + 136u, third);
    w_u32(destination + 140u, r_u32(source + 140u));
    for (index = 0u; index < 4u; ++index)
        w_u16(destination + 72u + 2u * index, r_u16(source + 72u + 2u * index));
    first = r_u8(source + 67u);
    w_u16(destination + 160u, 0xFFFFu);
    w_u8(destination + 67u, first);

    type = r_u8(source + 197u);
    if (type == 8u || type == 9u)
    {
        object_transfer_words(destination + 280u, source + 280u, 20u);
        object_transfer_words(destination + 200u, source + 200u, 36u);
        object_transfer_words(destination + 236u, source + 236u, 36u);
        sub_80036CFC(source + 194u);
    }
    else if (type == 22u)
    {
        object_transfer_words(destination + 200u, source + 200u, 372u);
        w_u16(destination + 56u, 0u);
    }
    else
    {
        if (type == 7u)
            object_transfer_words(destination + 324u, source + 324u, 36u);
        else
            sub_80036CFC(source + 324u);
        object_transfer_words(destination + 200u, source + 200u, 72u);
        sub_80036CFC(source + 194u);
    }

    count = (sint16)r_u16(0x800A7F3Cu);
    if (count > 0)
    {
        list = r_u32(0x800A851Cu);
        index = 0u;
        do
        {
            if (r_u32(list) == source)
                w_u32(list, destination);
            ++index;
            list += 4u;
        } while ((sint32)index < (sint16)r_u16(0x800A7F3Cu));
    }
    count = (sint16)r_u16(0x800A6094u);
    for (index = 0u; (sint32)index < count; ++index)
        if (r_u32(0x800A8930u + 4u * index) == source)
            w_u32(0x800A8930u + 4u * index, destination);
    w_u16(destination + 158u, 0xFFFFu);
    reference = (sint16)r_u16(source + 162u);
    if (reference != -1)
    {
        owner = r_u32(r_u32(0x800A851Cu) + 4u * (uint32)reference);
        if (r_u8(owner + 64u) == 0u)
        {
            w_u8(owner + 66u, r_u8(owner + 66u) - 1u);
            w_u16(source + 162u, 0xFFFFu);
        }
    }
    w_u8(source + 14u, 1u);
    w_u32(source + 140u, 0u);
    return 1u;
}
