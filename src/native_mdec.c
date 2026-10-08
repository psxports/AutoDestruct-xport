#include "psx.h"

// TODO Implement MDEC video decoding in a later pass
static uint32 mdec_callback, mdec_pending, mdec_dispatching;
extern void native_sdk_dispatch_callback(uint32 target, uint32 a0, uint32 a1);
uint32 sub_80086B58(uint32 source, uint32 destination)
{
    (void)source; (void)destination;
    return 0;
}
void sub_800863C4(uint32 mode)
{
    (void)mode; mdec_pending=0;
}
uint32 sub_80086530(uint32 buffer, uint32 mode)
{
    (void)buffer; (void)mode;
    return 0;
}
uint32 sub_800865AC(uint32 buffer, uint32 words)
{
    // TODO Produce decoded pixels instead of blank output
    xport_guest_fill(buffer,0,(words>>5)*128u);
    if(mdec_callback){
        ++mdec_pending;
        if(!mdec_dispatching){
            mdec_dispatching=1;
            while(mdec_pending){--mdec_pending;native_sdk_dispatch_callback(mdec_callback,0,0);}
            mdec_dispatching=0;
        }
    }
    return 0;
}
uint32 sub_80086668(uint32 callback)
{
    uint32 previous=mdec_callback;mdec_callback=callback;return previous;
}
