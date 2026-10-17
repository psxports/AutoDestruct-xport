#include "draft_signatures.h"

uint32 sub_8005CBC8(uint32 mode, uint32 position)
{
    FUNCTION_MARKER(0x8005CBC8u, "1.EXE");
    return sub_8005CB04(mode, position, 0u);
}

uint32 sub_8005CC08(uint32 position)
{
    uint32 result;
    FUNCTION_MARKER(0x8005CC08u, "1.EXE");
    w_u32(0x800A8808u, r_u32(position));
    w_u32(0x800A880Cu, r_u32(position + 4u));
    result = r_u32(position + 8u);
    w_u32(0x800A8810u, result);
    return result;
}

uint32 sub_8005CC34(uint32 object)
{
    uint32 mode;
    FUNCTION_MARKER(0x8005CC34u, "1.EXE");
    mode = r_u8(object + 47u);
    if (mode != r_u8(object + 45u))
        return 0u;
    return r_u8(object + 44u) == mode;
}
