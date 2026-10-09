# Auto Destruct

Resolve `[XPORT_ROOT]` from `xport-project.json` and read `[XPORT_ROOT]/AGENTS.md`. Keep only stable game-specific facts and task-routing links here; put detailed evidence under `status`.

## Project facts

- Native short name: `AD`; language: C
- Solution: `src/platform/win/AD.sln`; executable: `bin/AD.exe`; working directory: `bin`; intermediates: `_build`
- Runtime data: `bin/DATA`; Red Book output when applicable: `bin/MUSIC`
- Reviewed `1.EXE` runtime GP: `0x800A5628`; evidence: `status/audits/1.EXE-gp.md`
- Before relying on them, record reviewed image identities, language decision, dummy scope, hooks/layouts, adapter contract and evidence links here

- Reviewed original `1.EXE` SHA-256: `5e0b17a557b69f470a03ae885fb5a75cc450c7b3b5766f35a3ae969a4c161768`; graph-type word binding: `xport_gpu_graph_type_address=0x80093C84`; evidence: `status/audits/SetDefDrawEnv-static.json`
