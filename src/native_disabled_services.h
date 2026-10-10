#ifndef AD_NATIVE_DISABLED_SERVICES_H
#define AD_NATIVE_DISABLED_SERVICES_H
#include "psx.h"
// TODO Implement memory card and pad tap in a later pass
sint32 ad_todo_service(void);
uint32 ad_todo_service_unsigned(void);
sint32 ad_todo_init_tap(uint32 first, uint32 second, sint32 mode0, sint32 mode1);
uint32 ad_todo_card_exist(uint32 channel);
uint32 ad_todo_card_sync(uint32 mode, uint32 command, uint32 result);
uint32 ad_todo_card_open(uint32 channel, uint32 filename, uint32 mode);
uint32 ad_todo_card_read(uint32 channel, uint32 filename, uint32 output, uint32 offset, uint32 length);
#define InitTAP ad_todo_init_tap
#define StartTAP ad_todo_service
#define StopTAP ad_todo_service_unsigned
#define MemCardInitPSX ad_todo_service
#define MemCardStartPSX ad_todo_service
#define MemCardEndPSX ad_todo_service
#define MemCardClosePSX ad_todo_service_unsigned
#define MemCardExistPSX ad_todo_card_exist
#define MemCardSyncPSX ad_todo_card_sync
#define MemCardOpenPSX ad_todo_card_open
#define MemCardReadFilePSX ad_todo_card_read
#endif
