#include "psx.h"
#include "psx_press.h"

static uint32 mdec_callback;
extern void native_sdk_dispatch_callback(uint32 target, uint32 a0, uint32 a1);

static void native_mdec_complete(void)
{
    if (mdec_callback)
        native_sdk_dispatch_callback(mdec_callback, 0u, 0u);
}

uint32 sub_80086B58(uint32 source, uint32 destination)
{
    uint32 bytes = (r_u32(source) & 0xFFFFu) * 4u + 4u;
    return (uint32)DecDCTvlc((uint32 *)psx_addr(source, 12u), (uint32 *)psx_addr(destination, bytes));
}

void sub_800863C4(uint32 mode)
{
    DecDCTReset((sint32)mode);
}

uint32 sub_80086530(uint32 buffer, uint32 mode)
{
    uint32 bytes = (r_u32(buffer) & 0xFFFFu) * 4u + 4u;
    DecDCTin((uint32 *)psx_addr(buffer, bytes), (sint32)mode);
    return 0;
}

uint32 sub_800865AC(uint32 buffer, uint32 words)
{
    DecDCTout((uint32 *)psx_addr(buffer, (words & ~31u) * 4u), (sint32)words);
    return 0;
}

uint32 sub_80086668(uint32 callback)
{
    uint32 previous = mdec_callback;
    mdec_callback = callback;
    DecDCToutCallback(callback ? native_mdec_complete : NULL);
    return previous;
}
