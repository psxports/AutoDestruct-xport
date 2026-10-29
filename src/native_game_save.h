#ifndef AD_NATIVE_GAME_SAVE_H
#define AD_NATIVE_GAME_SAVE_H
#include "xport.h"
sint32 ad_save_game(void);
sint32 ad_load_game(void);
sint32 ad_restore_loaded_game(void);
void ad_init_save_menu(void);
const char *ad_save_notice(uint32 menu);
#endif
