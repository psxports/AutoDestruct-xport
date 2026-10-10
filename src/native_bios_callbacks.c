#include "psx.h"
#include "draft_adapters.h"
#include <stdlib.h>

static sint32 native_bios_callback(void *context, uint32 target)
{
    switch (target)
    {
        case 0x80078D70u:
        case 0x80078DB8u:
            draft_call_adapter(target);
            return 1;
        default:
            fprintf(stderr, "Unbound native BIOS callback %08X\n", target);
            abort();
    }
}

void native_bios_init_callbacks(void)
{
    psx_bios_bind_guest_callback_service(native_bios_callback, NULL);
}
