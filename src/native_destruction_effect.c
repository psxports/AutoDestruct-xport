#include "native_call_dispatch.h"

uint32 sub_80060A60(uint32 effect, uint32 count, uint32 size);

uint32 sub_800608F8(uint32 owner)
{
    uint32 effect;
    FUNCTION_MARKER(0x800608F8u, "1.EXE");
    effect = sub_800227C4(40u);
    w_u16(effect + 36u, 200u);
    w_u16(effect + 38u, 0u);
    w_u32(effect + 20u, r_u32(owner + 20u));
    w_u32(effect + 24u, r_u32(owner + 24u));
    w_u8(effect + 34u, 11u);
    w_u32(effect + 28u, r_u32(owner + 28u));
    uint32 resource = r_u32(0x800A62ECu);
    uint32 flags = r_u8(effect + 14u);
    uint32 model = r_u16(resource + 62u);
    w_u8(effect + 14u, flags | 2u);
    flags = r_u8(effect + 14u);
    w_u32(effect, 0x800609A4u);
    w_u16(effect + 18u, 4096u);
    w_u16(effect + 16u, 0u);
    w_u32(effect + 8u, owner);
    w_u8(effect + 13u, 255u);
    w_u16(effect + 32u, model);
    w_u8(effect + 14u, flags | 64u);
    return effect;
}

uint32 sub_800609A4(uint32 effect)
{
    uint32 tick = r_u32(0x800A9010u);
    FUNCTION_MARKER(0x800609A4u, "1.EXE");
    uint32 phase = r_u16(effect + 38u);
    uint32 owner = r_u32(effect + 8u);
    w_u16(effect + 38u, phase + 20u * tick);
    w_u32(effect + 20u, r_u32(owner + 20u));
    w_u32(effect + 24u, r_u32(owner + 24u));
    uint32 elapsed = r_u16(effect + 16u);
    uint32 z = r_u32(owner + 28u);
    elapsed += tick;
    w_u16(effect + 16u, elapsed);
    w_u32(effect + 28u, z);
    sint32 count = (sint16)elapsed / 2;
    if (count != 0)
        w_u16(effect + 16u, 0u);
    sub_800369E0(effect + 20u, effect + 13u, 2048u, 16u);
    return sub_80060A60(effect, (uint32)count, (uint32)(sint32)(sint16)r_u16(effect + 36u));
}

uint32 sub_80060A60(uint32 effect, uint32 count, uint32 size)
{
    FUNCTION_MARKER(0x80060A60u, "1.EXE");
    while ((sint32)count > 0)
    {
        uint32 particle = sub_800227C4(40u);
        w_u32(particle, 0x80060738u);
        w_u8(particle + 34u, 11u);
        uint32 resource = r_u32(0x800A62ECu);
        uint32 flags = r_u8(particle + 14u);
        w_u16(particle + 36u, size);
        w_u16(particle + 38u, 0u);
        uint32 model = r_u16(resource + 62u);
        w_u8(particle + 14u, flags | 2u);
        w_u16(particle + 32u, model);
        uint32 random = sub_80069A50();
        w_u32(particle + 20u, r_u32(effect + 20u) - 127u + (random & 255u));
        w_u32(particle + 24u, r_u32(effect + 24u));
        random = sub_80069A50();
        --count;
        uint32 z = r_u32(effect + 28u);
        w_u16(particle + 8u, 0u);
        w_u32(particle + 28u, z - 127u + (random & 255u));
        random = sub_80069A50();
        w_u16(particle + 10u, (random & 127u) + 92u);
        random = sub_80069A50();
        w_u16(particle + 16u, (random & 127u) - 64u);
    }
    uint32 tick = r_u32(0x800A9010u);
    uint32 remaining = r_u16(effect + 18u) - 8u * tick;
    w_u16(effect + 18u, remaining);
    uint32 result = remaining << 16;
    if ((sint32)result < 0)
    {
        sub_80036CFC(effect + 13u);
        return sub_8002289C(effect);
    }
    return result;
}
