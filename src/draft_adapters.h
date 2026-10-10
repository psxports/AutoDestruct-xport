#ifndef DRAFT_ADAPTERS_H
#define DRAFT_ADAPTERS_H

#include "psx.h"

// TODO Bind unavailable guest calls during integration
uint64 draft_call_adapter_counted(uint32 argument_count, uint32 target, ...);

// Count target plus up to 24 arguments without reading absent values
#define DRAFT_ADAPTER_ARG_COUNT_I(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, N, ...) N
#define DRAFT_ADAPTER_ARG_COUNT_EXPAND(tuple) DRAFT_ADAPTER_ARG_COUNT_I tuple
#define DRAFT_ADAPTER_ARG_COUNT(...) DRAFT_ADAPTER_ARG_COUNT_EXPAND((__VA_ARGS__, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))
#define draft_call_adapter(...) draft_call_adapter_counted(DRAFT_ADAPTER_ARG_COUNT(__VA_ARGS__) - 1u, __VA_ARGS__)

// TODO Bind addressable temporary guest buffers during integration
uint32 draft_scratch_adapter(uint32 bytes);
uint32 draft_scratch_mark(void);
void draft_scratch_guest_frame(uint32 entry_sp, uint32 bytes);
void draft_scratch_release(uint32 mark);
uint64 draft_scratch_result(uint32 mark, uint64 value);

// TODO Bind GTE commands and control registers during integration
void draft_gte_command_adapter(uint32 command);
uint32 draft_gte_control_adapter(uint32 index);

#endif
