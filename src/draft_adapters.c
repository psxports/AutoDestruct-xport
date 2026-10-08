#include "draft_adapters.h"
#include <stdlib.h>

static uint32 draft_stack_cursor = 0x801FFFF0u;

uint32 draft_scratch_mark(void) { return draft_stack_cursor; }
void draft_scratch_release(uint32 mark) { draft_stack_cursor = mark; }
uint64 draft_scratch_result(uint32 mark, uint64 value)
{
    draft_scratch_release(mark);
    return value;
}

uint32 draft_scratch_adapter(uint32 bytes)
{
    uint32 rounded = (bytes + 15u) & ~15u;
    uint32 bottom = draft_stack_cursor - rounded;
    if (rounded < bytes || bottom > draft_stack_cursor ||
        bottom < 0x800C15E8u || bottom < r_u32(0x800A63E0u))
    {
        fprintf(stderr, "Native temporary stack exhausted: %08X bytes %u\n", draft_stack_cursor, bytes);
        abort();
    }
    draft_stack_cursor = bottom;
    return bottom;
}

void draft_scratch_guest_frame(uint32 entry_sp, uint32 bytes)
{
    uint32 physical = entry_sp & 0x1FFFFFFFu;
    uint32 bottom;
    if (physical >= 0x200000u) physical &= 0x1FFFFFu;
    entry_sp = physical | 0x80000000u;
    bottom = entry_sp - bytes;
    if (bottom > entry_sp || bottom < r_u32(0x800A63E0u))
    {
        fprintf(stderr, "Native guest frame overlaps heap: SP %08X bytes %u\n", entry_sp, bytes);
        abort();
    }
    if (bottom < draft_stack_cursor) draft_stack_cursor = bottom;
}

void draft_gte_command_adapter(uint32 command)
{
    xport_gte_execute(command);
}

uint32 draft_gte_control_adapter(uint32 index)
{
    PsxGteSnapshot state;
    psx_gte_snapshot(&state);
    if (index < 5u) {
        uint32 component=index*2u;
        uint32 low=(uint16)state.rotation.m[component/3u][component%3u];
        if(component==8u)return (uint32)(sint32)(sint16)low;
        ++component;
        return low|((uint32)(uint16)state.rotation.m[component/3u][component%3u]<<16);
    }
    if(index<8u)return (uint32)state.translation[index-5u];
    switch(index){
    case 24:return (uint32)state.ofx << 16;
    case 25:return (uint32)state.ofy << 16;
    case 31:return (uint32)state.flag;
    default:abort();
    }
}
