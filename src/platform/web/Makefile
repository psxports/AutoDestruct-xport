PROJECT_ROOT := ../../..
SHORT_NAME := AD
FULL_NAME := Auto Destruct
APP_SOURCES := \
	../../../src/game_main.c \
	../../../src/render_frontier.c \
	../../../src/game_batch1.c \
	../../../src/game_batch2.c \
	../../../src/game_batch3.c \
	../../../src/game_batch4.c \
	../../../src/game_batch5.c \
	../../../src/draft_adapters.c \
	../../../src/draft_group_0.c \
	../../../src/draft_group_0_round1.c \
	../../../src/draft_group_0_round2.c \
	../../../src/draft_group_0_round3.c \
	../../../src/draft_group_0_tail.c \
	../../../src/draft_group_1.c \
	../../../src/draft_group_1_round1.c \
	../../../src/draft_group_1_round2.c \
	../../../src/draft_group_1_round3.c \
	../../../src/draft_group_2.c \
	../../../src/draft_group_2_render.c \
	../../../src/draft_group_2_round1.c \
	../../../src/draft_group_2_round1_render.c \
	../../../src/draft_group_2_round2.c \
	../../../src/draft_group_2_round2_render.c \
	../../../src/draft_group_2_round3.c \
	../../../src/draft_root_0.c \
	../../../src/draft_root_1.c \
	../../../src/draft_root_10.c \
	../../../src/draft_root_11.c \
	../../../src/draft_root_12.c \
	../../../src/draft_root_13.c \
	../../../src/draft_root_14.c \
	../../../src/draft_root_15.c \
	../../../src/draft_root_16.c \
	../../../src/draft_root_17.c \
	../../../src/draft_root_18.c \
	../../../src/draft_root_19.c \
	../../../src/draft_root_2.c \
	../../../src/draft_root_3.c \
	../../../src/draft_root_4.c \
	../../../src/draft_root_5.c \
	../../../src/draft_root_6.c \
	../../../src/draft_root_7.c \
	../../../src/draft_root_8.c \
	../../../src/draft_root_9.c \
	../../../src/native_missing_1.c \
	../../../src/native_missing_2.c \
	../../../src/native_sdk_bindings.c \
	../../../src/native_call_dispatch.c \
	../../../src/native_call_dispatch_0.c \
	../../../src/native_call_dispatch_1.c \
	../../../src/native_call_dispatch_2.c \
	../../../src/native_call_dispatch_3.c \
	../../../src/native_mdec.c \
	../../../src/native_disabled_services.c \
	../../../src/native_input.c \
	../../../src/native_spu_binding.c \
	../../../src/native_spu_common.c \
	../../../src/native_spu_reverb.c \
	../../../src/native_bios_callbacks.c \
	../../../src/native_terrain_1ABB0.c \
	../../../src/native_effects.c \
	../../../src/native_effect_60404.c \
	../../../src/native_collision_helpers.c \
	../../../src/native_collision_effects.c \
	../../../src/native_collision_effect_helpers.c \
	../../../src/native_3F814.c \
	../../../src/native_collision_particles.c \
	../../../src/native_impact_effects.c \
	../../../src/native_3DB40.c \
	../../../src/native_2E190.c \
	../../../src/native_impact_dependencies.c \
	../../../src/native_40478.c \
	../../../src/native_impact_trails.c \
	../../../src/native_3F5CC.c \
	../../../src/native_destruction_effect.c \
	../../../src/native_player_destruction.c \
	../../../src/native_camera_modes.c \
	../../../src/native_menu_frontier.c \
	../../../src/native_reverb_bindings.c \
	../../../src/native_camera_follow.c \
	../../../src/native_menu_music.c \
	../../../src/native_object_motion_modes.c \
	../../../src/native_frontier_scalars.c \
	../../../src/native_motion_update.c \
	../../../src/native_object_state_transfer.c \
	../../../src/native_frontier_effects.c \
	../../../src/native_text_frontier.c \
	../../../src/native_motion_angles.c \
	../../../src/native_motion_contacts.c \
	../../../src/native_effect_callbacks.c \
	../../../src/native_frontier_actions.c \
	../../../src/native_hud_frontier.c \
	../../../src/native_object_frontier.c \
	../../../src/native_remaining_wrappers.c \
	../../../src/native_final_frontier.c \
	../../../src/native_terrain_query.c \
	../../../src/native_stored_callbacks.c \
	../../../src/native_attachment_motion.c \
	../../../src/native_actor_steering.c \
	../../../src/native_actor_state.c \
	../../../src/native_object_table_methods.c \
	../../../src/native_projectile_volleys.c \
	../../../src/native_projectile_motion.c \
	../../../src/native_projectile_bounces.c \
	../../../src/native_world_weapon_effects.c \
	../../../src/native_map_effect_entries.c \
	../../../src/native_map_effect_particles.c \
	../../../src/native_map_effect_records.c \
	../../../src/native_map_effect_physics.c \
	../../../src/native_map_emitters.c \
	../../../src/native_map_interactive_effects.c \
	../../../src/native_menu_settings.c \
	../../../src/native_proximity_callback.c \
	../../../src/native_actor_remaining_motion.c \
	../../../src/native_stream_object_entries.c \
	../../../src/native_remaining_game_entries.c \
	../../../src/native_bootstrap.c \
	../../../src/native_input_remaining.c \
	../../../src/native_analog_calibration.c \
	../../../src/native_menu_calibration.c \
	../../../src/native_debug_memory.c
APP_SOURCES += ../../../src/native_data_cd.c
APP_DEFINES := -DFIELD_RATE=50 -DWND_TITLE=\"AD\" -DWND_WIDTH=960 -DWND_HEIGHT=720
ifneq ($(CONFIG),Debug)
# Return-address diagnostics build a JavaScript stack for every marker
APP_DEFINES += -DXPORT_DISABLE_FUNCTION_MARKERS
endif
WEB_PACKAGER_FLAGS := --extra-file ../../../orig/1.EXE BOOT/1.EXE --include-str DATA/LANGUAGE/00.STR
include ../../../../xport/src/platform/web/Makefile

# File loads unwind the original nested game call chain
LINK_FLAGS += -sASYNCIFY_STACK_SIZE=65536
