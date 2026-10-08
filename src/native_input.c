#include "psx.h"

void native_input_publish_basic_pad(void)
{
    uint32 index;
    uint32 released = (PadRead(0) ^ 0xFFFFu) & 0xFFFFu;

    /* Publish the native keyboard/gamepad independently of disabled TAP */
    for (index = 0u; index < 34u; ++index)
        w_u8(0x800A9984u + index, 0xFFu);
    w_u8(0x800A9984u, 0u);
    w_u8(0x800A9985u, 0x41u);
    /* The game parser assembles these bytes high first */
    w_u8(0x800A9986u, released >> 8u);
    w_u8(0x800A9987u, released & 0xFFu);
}
