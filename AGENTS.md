# Auto Destruct

Resolve `[XPORT_ROOT]` from `xport-project.json` and read `[XPORT_ROOT]/AGENTS.md`. Keep only stable game-specific facts and task-routing links here; put detailed evidence under `status`.

## Project facts

- Native short name: `AD`; language: C
- Solution: `src/platform/win/AD.sln`; executable: `bin/AD.exe`; working directory: `bin`; intermediates: `_build`
- Runtime data: `bin/DATA`; Red Book output when applicable: `bin/MUSIC`
- Reviewed `1.EXE` runtime GP: `0x800A5628`; evidence: `status/audits/1.EXE-gp.md`
- Memory-card and PAD TAP hardware services remain disabled: `src/native_disabled_services.h`. Game progress uses `xport_load`/`xport_save` through `src/native_game_save.h`; the card manager is bypassed. Main-menu Load and pause-menu Save are direct actions; evidence: `status/web-integration-browser.json`
- Pause-menu extensions reuse obsolete card-menu storage `0x80091C68..0x80091D58`; original card services and their historical deferred bodies remain separate from the native save replacement
- Extracted XA files use the shared CD owner through `src/native_data_cd.h`; `status/xa-file-source-index.json` binds the original sector addresses and hashes. Prepare file reads before entering the shared audio lock; no runtime ISO source
- Fullscreen intro/outro use shared FMV with original source-frame limits 1005/477. Web MP4 registrations are in `xport-project.json` and `bin/VIDEO/manifest.json`; `DATA/LANGUAGE/00.STR` is language data and remains packaged
- Web entry: `src/platform/web/Makefile`; publication: `../.github/site/AD`; Web Asyncify stack is 64 KiB after an observed 29,740-byte unwind during game loading
- Web Release disables function markers with `XPORT_DISABLE_FUNCTION_MARKERS`; collecting a return address otherwise builds a JavaScript stack on every marked call
- Loading bomb/countdown and explosion frames are omitted by user request; XA metadata discovery remains active in `sub_8005A69C`
- Shared xport has no frame-skip API or scheduler; do not restore project-local frame skipping or obsolete API stubs
- Before relying on them, record reviewed image identities, language decision, dummy scope, hooks/layouts, adapter contract and evidence links here

- Reviewed original `1.EXE` SHA-256: `5e0b17a557b69f470a03ae885fb5a75cc450c7b3b5766f35a3ae969a4c161768`; graph-type word binding: `xport_gpu_graph_type_address=0x80093C84`; evidence: `status/audits/SetDefDrawEnv-static.json`
- Impact sound fallthrough carries explicit sample/pitch through game-only terrain/allocation outputs: `src/native_impact_sound.h`; evidence and unobserved branches: `status/audits/impact-sound-3CCE0-repair.json`
- Legacy translation inventory and boundary repairs: `status/goal-scope-all-game-functions.json` and `status/audits/all-game-functions-queue-20261020.json`; these historical records do not establish functional completeness
- Reviewed original `SLUS_005.22` SHA-256: `479c31ef9f7a7b8df31ad61cc36c96782aa5ddfad74e80bc771b10dfff805594`; runtime GP: `0x80156B84`; evidence: `status/audits/SLUS_005.22-gp.json`
