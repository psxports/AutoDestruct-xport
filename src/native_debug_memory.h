#ifndef NATIVE_DEBUG_MEMORY_H
#define NATIVE_DEBUG_MEMORY_H
#include "psx.h"

void native_debug_heap_event(uint32 kind, uint32 pointer, uint32 size);
void native_debug_heap_region(uint32 block, uint32 available);

#endif
