#include "native_call_dispatch.h"

static uint32 reverb_work_occupied(uint32 work)
{
    uint32 address = work << (r_u32(0x800A4E3Cu) & 31u);
    uint32 entry = r_u32(0x800A52ECu);
    if (!entry)
        return 0u;
    for (;;)
    {
        uint32 flags = r_u32(entry);
        if (!(flags & 0x80000000u))
        {
            uint32 start = flags & 0x0FFFFFFFu;
            if (flags & 0x40000000u)
                return 0u;
            if (start >= address || address < start + r_u32(entry + 4u))
                return 1u;
        }
        entry += 8u;
    }
}

static SpuReverbAttr reverb_attributes(uint32 address)
{
    SpuReverbAttr attr;
    attr.mask = r_u32(address);
    attr.mode = (sint32)r_u32(address + 4u);
    attr.depth.left = (sint16)r_u16(address + 8u);
    attr.depth.right = (sint16)r_u16(address + 10u);
    attr.delay = (sint32)r_u32(address + 12u);
    attr.feedback = (sint32)r_u32(address + 16u);
    return attr;
}

uint32 sub_80089138(uint32 address)
{
    SpuReverbAttr attr = reverb_attributes(address);
    uint32 registers = r_u32(0x800A4E14u);
    FUNCTION_MARKER(0x80089138u, "1.EXE");
    SpuSetReverbDepth(&attr);
    if (!attr.mask || (attr.mask & 2u))
    {
        w_u16(registers + 388u, (uint16)attr.depth.left);
        w_u16(0x800A4E98u, (uint16)attr.depth.left);
    }
    if (!attr.mask || (attr.mask & 4u))
    {
        w_u16(registers + 390u, (uint16)attr.depth.right);
        w_u16(0x800A4E9Au, (uint16)attr.depth.right);
    }
    return 0u;
}

uint32 sub_80089238(uint32 enabled)
{
    FUNCTION_MARKER(0x80089238u, "1.EXE");
    if (enabled > 1u)
        return r_u32(0x800A4E84u);
    if (enabled == 1u && r_u32(0x800A4E88u) != 1u && reverb_work_occupied(r_u32(0x800A4E8Cu)))
        enabled = 0u;
    sint32 result = SpuSetReverb((sint32)enabled);
    if (result < 0)
        return (uint32)result;
    uint32 registers = r_u32(0x800A4E14u);
    w_u32(0x800A4E84u, (uint32)result);
    w_u16(registers + 426u, (r_u16(registers + 426u) & 0xFF7Fu) | ((uint32)result << 7));
    return (uint32)result;
}

uint32 sub_80086F78(uint32 address)
{
    SpuReverbAttr attr = reverb_attributes(address);
    uint32 change = !attr.mask || (attr.mask & 1u);
    uint32 mode = change ? ((uint32)attr.mode & ~0x100u) : r_u32(0x800A4E94u);
    uint32 block[17] = {0};
    uint16 *parameters = (uint16 *)(block + 1);
    uint32 delay_change = (!attr.mask || (attr.mask & 8u)) && (sint32)mode >= 7 && (sint32)mode < 9;
    uint32 feedback_change = (!attr.mask || (attr.mask & 16u)) && (sint32)mode >= 7 && (sint32)mode < 9;
    FUNCTION_MARKER(0x80086F78u, "1.EXE");
    if (change && (mode >= 10u || reverb_work_occupied(r_u32(0x800A52F0u + 4u * mode))))
        return 0xFFFFFFFFu;
    sint32 result = SpuSetReverbModeParam(&attr);
    if (result != 0)
        return (uint32)result;
    uint32 registers = r_u32(0x800A4E14u);
    if (change || delay_change || feedback_change)
    {
        for (uint32 i = 0; i < 17u; ++i)
            block[i] = r_u32(0x800A5340u + 68u * mode + 4u * i);
    }
    if (change)
    {
        w_u32(0x800A4E94u, mode);
        w_u32(0x800A4E8Cu, r_u32(0x800A52F0u + 4u * mode));
        w_u32(0x800A4E9Cu, mode == 7u || mode == 8u ? 127u : 0u);
        w_u32(0x800A4EA0u, mode == 7u ? 127u : 0u);
    }
    if (delay_change)
    {
        if (!change)
            block[0] = 0x0C011C00u;
        sint32 d13 = (sint32)((uint32)attr.delay << 13) / 127;
        sint32 d12 = (sint32)((uint32)attr.delay << 12) / 127;
        w_u32(0x800A4E9Cu, (uint32)attr.delay);
        parameters[10] = (uint16)(d13 - parameters[0]);
        parameters[11] = (uint16)(d12 - parameters[1]);
        parameters[16] = (uint16)(parameters[17] + d12);
        parameters[12] = (uint16)(parameters[13] + d12);
        parameters[27] = (uint16)(parameters[29] + d12);
        parameters[26] = (uint16)(parameters[28] + d12);
    }
    if (feedback_change)
    {
        if (!change)
            block[0] = delay_change ? block[0] | 0x80u : 0x80u;
        w_u32(0x800A4EA0u, (uint32)attr.feedback);
        parameters[7] = (uint16)((sint32)((uint32)attr.feedback * 33024u) / 127);
    }
    if (change)
    {
        w_u16(registers + 388u, 0u);
        w_u16(registers + 390u, 0u);
        w_u16(0x800A4E98u, 0u);
        w_u16(0x800A4E9Au, 0u);
    }
    else
    {
        if (!attr.mask || (attr.mask & 2u))
        {
            w_u16(registers + 388u, (uint16)attr.depth.left);
            w_u16(0x800A4E98u, (uint16)attr.depth.left);
        }
        if (!attr.mask || (attr.mask & 4u))
        {
            w_u16(registers + 390u, (uint16)attr.depth.right);
            w_u16(0x800A4E9Au, (uint16)attr.depth.right);
        }
    }
    if (change || delay_change || feedback_change)
    {
        for (uint32 i = 0; i < 32u; ++i)
        {
            if (!block[0] || (block[0] & (1u << i)))
                w_u16(registers + 448u + 2u * i, parameters[i]);
        }
    }
    if (change)
        w_u16(registers + 418u, r_u32(0x800A4E8Cu));
    return 0u;
}
