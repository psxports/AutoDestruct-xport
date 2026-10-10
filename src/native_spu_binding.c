#include "psx.h"
#include "psx_spu.h"
#include <stdlib.h>

void native_spu_init_binding(void)
{
    static uint32 bound;
    SpuNativeTransferGuestBinding binding;
    if (bound)
        return;
    binding.requested_mode = 0x800A4E80u;
    binding.normalized_mode = 0x800A4E30u;
    binding.address_units = 0x800A4E2Cu;
    binding.completion = 0x800A4E48u;
    binding.completion_callback = 0x800A4E4Cu;
    binding.source_address = 0x800A4E68u;
    binding.dma_blocks = 0x800A4E6Cu;
    binding.address_shift = r_u32(0x800A4E3Cu);
    if (!spu_bind_native_transfer_guest(&binding))
        abort();
    /* Original SDK work units and ten 68-byte reverb presets */
    spu_bind_reverb_presets((const uint32 *)psx_addr(0x800A52F0u, 40u), (const uint8 *)psx_addr(0x800A5340u, 680u), binding.address_shift);
    bound = 1;
}

void xport_bind_native_spu_transfer(void)
{
    native_spu_init_binding();
}
