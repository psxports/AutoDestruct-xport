#include "psx.h"
#include "xport.h"

extern uint32 sub_8006F710(void);
extern uint32 sub_80070A0C(uint32 type);

uint32 sub_80070700(uint32 menu)
{
    uint32 result = r_u32(0x800A646Cu);
    uint32 index = 0u;
    uint32 entry = 0x800A75CCu;
    FUNCTION_MARKER(0x80070700u, "1.EXE");
    if ((sint32)result <= 0)
        return result;
    for (;;)
    {
        if (r_u32(entry) == menu)
        {
            result = index + 2u;
            if (r_u32(0x800A645Cu) != 7u)
            {
                w_u32(0x800A646Cu, result);
                result = sub_8006F710();
                w_u32(0x800A6460u, result);
                result = sub_8006F710();
                w_u32(0x800A645Cu, result);
            }
            return result;
        }
        result = r_u32(0x800A646Cu);
        index += 2u;
        result = (sint32)index < (sint32)result;
        entry += 8u;
        if (!result)
            return result;
    }
}

uint32 sub_80070938(uint32 selection)
{
    uint32 previous = 255u;
    uint32 following = 255u;
    uint32 index = 0u;
    FUNCTION_MARKER(0x80070938u, "1.EXE");
    if ((sint32)r_u32(0x800A75C4u) > 0)
    {
        do
        {
            uint32 menu = r_u32(0x800A645Cu);
            uint32 table = r_u32(0x80091EE0u + menu * 12u);
            if (sub_80070A0C(r_u32(table + index * 16u)))
            {
                if ((sint32)index >= (sint32)selection)
                {
                    following = index;
                    break;
                }
                previous = index;
            }
            ++index;
        } while ((sint32)index < (sint32)r_u32(0x800A75C4u));
    }
    if (previous != 255u)
        return previous;
    return following == 255u ? 0u : following;
}
