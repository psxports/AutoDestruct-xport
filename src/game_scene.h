#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "xport.h"
#include "native_disabled_services.h"

typedef struct GameMainCallContext
{
    uint32 stack_pointer;
    uint32 return_address;
    uint32 caller_s0;
    uint32 caller_s1;
    uint32 caller_s2;
    uint32 caller_s3;
    uint32 caller_a0;
    uint32 caller_a1;
    uint32 caller_a2;
    uint32 caller_a3;
    uint32 caller_s4;
    uint32 caller_s5;
    uint32 caller_s6;
    uint32 caller_s7;
    uint32 caller_fp;
} GameMainCallContext;

typedef struct GameSceneCallContext
{
    uint32 stack_pointer;
    uint32 return_address;
    uint32 caller_s0;
} GameSceneCallContext;

// Required guest-target binding, including callee stack and preserved S0
void game_call_scene_initializer(uint32 target, uint32 destination, uint32 entry_sp);
void game_call_scene_initializer_other(uint32 target, uint32 destination, uint32 entry_sp);
uint32 sub_80064334(uint32 force_default, GameSceneCallContext *context);

typedef struct GameGeometryCallContext
{
    uint32 stack_pointer;
    uint32 return_address;
    uint32 caller_s0;
    uint32 caller_s1;
    uint32 caller_s2;
    uint32 caller_s3;
    uint32 caller_s4;
    uint32 caller_s5;
    uint32 caller_s6;
    uint32 caller_s7;
    uint32 caller_fp;
} GameGeometryCallContext;

// Required InitGeom binding with guest CPU, BIOS, GTE and memory effects
void game_call_init_geom(uint32 entry_sp, uint32 return_address);
sint32 sub_8003C058(uint32 width, uint32 height, uint32 projection, GameGeometryCallContext *context);

// Required original-callee bindings with guest stack and return-address context
void game_call_reset_graph(uint32 mode, uint32 entry_sp, uint32 return_address);
void game_call_init_tap(uint32 first, uint32 second, uint32 third, uint32 fourth, uint32 entry_sp, uint32 return_address);
uint32 game_call_start_tap(uint32 entry_sp, uint32 return_address);
uint32 sub_8003C0C4(GameGeometryCallContext *context);
uint32 sub_8003806C(GameSceneCallContext *context);

uint32 sub_8003C114(GameGeometryCallContext *context);

void game_call_scene_initializer_context(uint32 target, uint32 destination, GameSceneCallContext *context);

typedef struct GameCallbackCallContext
{
    uint32 stack_pointer;
    uint32 return_address;
    uint32 caller_fp;
} GameCallbackCallContext;

uint32 sub_80078D70(GameCallbackCallContext *context);
uint32 sub_80078DB8(GameCallbackCallContext *context);

typedef struct GameRenderCallContext
{
    uint32 stack_pointer;
    uint32 return_address;
    uint32 caller_s0;
    uint32 caller_s1;
    uint32 caller_s2;
    uint32 caller_s3;
    uint32 caller_s4;
    uint32 caller_s5;
    uint32 caller_s6;
    uint32 caller_s7;
} GameRenderCallContext;

void sub_800643EC(GameRenderCallContext *context);

#endif
