#ifndef GAME_ENTRY_H
#define GAME_ENTRY_H

#include "xport.h"

// Main's original startup-memory block, with incoming S0 supplied explicitly
void game_main_initialize_globals(uint32 initial_state);

#endif
