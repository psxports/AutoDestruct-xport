#ifndef NATIVE_IMPACT_SOUND_H
#define NATIVE_IMPACT_SOUND_H
#include "psx.h"

typedef struct IMPACT_SOUND
{
    uint32 sample;
    uint32 pitch;
} IMPACT_SOUND;

uint32 native_impact_ground(uint32 position, uint32 normal, uint32 tag, IMPACT_SOUND *sound);
void native_impact_allocated_sound(IMPACT_SOUND *sound);
uint32 sub_80060320(uint32 object, IMPACT_SOUND *sound);
#endif
