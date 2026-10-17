#include "psx.h"
#include "xport_trace.h"
#include "native_debug_memory.h"
#include <stdlib.h>

#if defined(_WIN32) && defined(_DEBUG)
    #include <windows.h>

typedef struct NATIVE_MEMORY_WRITER
{
    uint32 sequence;
    uint32 offset;
    uint32 width;
    uint32 before;
    uint32 after;
    uint32 depth;
    void *frames[10];
} NATIVE_MEMORY_WRITER;

NATIVE_MEMORY_WRITER *native_memory_writers;
static uint32 native_memory_write_sequence;

typedef struct NATIVE_HEAP_EVENT
{
    uint32 sequence;
    uint32 kind;
    uint32 pointer;
    uint32 size;
    uint32 depth;
    void *frames[10];
} NATIVE_HEAP_EVENT;

NATIVE_HEAP_EVENT *native_heap_events;
uint32 native_heap_event_count;
uint32 native_heap_region_state[6];
volatile uint32 native_heap_region_failures;

void native_debug_heap_mismatch(void)
{
    ++native_heap_region_failures;
}

static void native_debug_memory_write(void *user, XportMemoryOperation operation, XportMemoryRegion region, uint32 offset, size_t width, uint32 before, uint32 after, uint32 byte_mask)
{
    NATIVE_MEMORY_WRITER record;
    uint32 first, last;
    if (operation != XPORT_MEMORY_WRITE || region != XPORT_MEMORY_DRAM || offset < 0xA0000 || !width || width > 4 || offset + width > 0x200000)
        return;
    record.sequence = ++native_memory_write_sequence;
    record.offset = offset;
    record.width = (uint32)width;
    record.before = before;
    record.after = after;
    record.depth = CaptureStackBackTrace(1, 10, record.frames, NULL);
    first = offset / 4;
    last = (offset + (uint32)width - 1) / 4;
    for (uint32 index = first; index <= last; ++index)
        native_memory_writers[index] = record;
}
#endif

void native_debug_heap_region(uint32 block, uint32 available)
{
#if defined(_WIN32) && defined(_DEBUG)
    uint32 first, second, gap;
    if (!native_heap_events)
        return;
    first = r_u32(block);
    second = r_u32(block + 4);
    gap = (first & 0xFFFFF) - ((first >> 20) << 12) - (second >> 20) - 8;
    if (gap != available)
    {
        native_heap_region_state[0] = block;
        native_heap_region_state[1] = available;
        native_heap_region_state[2] = first;
        native_heap_region_state[3] = second;
        native_heap_region_state[4] = gap;
        native_heap_region_state[5] = r_u32(0x800A748C);
        native_debug_heap_mismatch();
    }
#endif
}

void native_debug_heap_event(uint32 kind, uint32 pointer, uint32 size)
{
#if defined(_WIN32) && defined(_DEBUG)
    NATIVE_HEAP_EVENT *event;
    if (!native_heap_events)
        return;
    event = &native_heap_events[native_heap_event_count % 32768];
    event->sequence = ++native_heap_event_count;
    event->kind = kind;
    event->pointer = pointer;
    event->size = size;
    event->depth = CaptureStackBackTrace(1, 10, event->frames, NULL);
#endif
}

void native_debug_memory_init(void)
{
#if defined(_WIN32) && defined(_DEBUG)
    const char *enabled = getenv("AD_DEBUG_MEMORY_WRITERS");
    if (!enabled || enabled[0] != '1' || enabled[1])
        return;
    native_memory_writers = calloc(0x80000, sizeof(*native_memory_writers));
    if (!native_memory_writers)
        abort();
    native_heap_events = calloc(32768, sizeof(*native_heap_events));
    if (!native_heap_events)
        abort();
    // Record host call stacks without changing guest memory
    xport_memory_bind_observer(native_debug_memory_write, NULL);
#endif
}
