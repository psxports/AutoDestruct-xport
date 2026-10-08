#include "native_disabled_services.h"
sint32 ad_todo_service(void) { return 0; }
uint32 ad_todo_service_unsigned(void) { return 0; }
sint32 ad_todo_init_tap(uint32 first,uint32 second,sint32 mode0,sint32 mode1)
{
    (void)mode0; (void)mode1;
    if(first)xport_guest_fill(first,255,8);
    if(second)xport_guest_fill(second,255,8);
    return 0;
}
uint32 ad_todo_card_exist(uint32 channel) { (void)channel; return 0; }
uint32 ad_todo_card_sync(uint32 mode,uint32 command,uint32 result)
{
    (void)mode;
    if(command)w_u32(command,0);
    if(result)w_u32(result,1);
    return 1;
}
uint32 ad_todo_card_open(uint32 channel,uint32 filename,uint32 mode)
{ (void)channel;(void)filename;(void)mode;return 1; }
uint32 ad_todo_card_read(uint32 channel,uint32 filename,uint32 output,uint32 offset,uint32 length)
{ (void)channel;(void)filename;(void)output;(void)offset;(void)length;return 1; }
