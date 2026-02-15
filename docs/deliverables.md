# Deliverables (Strict Order)

## 1. System architecture
See `docs/system_architecture.md`.

## 2. Architecture explanation
See sections 1-8 in `docs/system_architecture.md`.

## 3. Module interfaces
- `include/goose_sim/core/*.hpp`
- `include/goose_sim/scl/*.hpp`
- `include/goose_sim/goose/*.hpp`
- `include/goose_sim/network/*.hpp`
- `include/goose_sim/model/*.hpp`
- `include/goose_sim/simulation/*.hpp`
- `include/goose_sim/validation/*.hpp`
- `include/goose_sim/recording/*.hpp`
- `include/goose_sim/cli/*.hpp`

## 4. Class diagrams
```text
SclParser --> IedModel --> PubGooseConfigBuilder/SubGooseConfigBuilder
Publisher --> PubGooseEncoder --> FrameCodec --> RawSocket
CaptureEngine --> Subscriber --> SubGooseDecoder --> Supervision
EventEngine --> Scheduler
RuleEngine --> LatencyAnalyzer
```

## 5. Threading design
- Dedicated Tx scheduler thread (`core::Scheduler`).
- Capture callback thread (`network::CaptureEngine` integration point).
- Independent simulation orchestration thread.
- Optional validation worker threadpool.

## 6. Build instructions (Win + Linux)
See `docs/system_architecture.md` section 8.

## 7. Complete compilable code
Source tree under `src/` and headers under `include/`.

## 8. Full source code
Contained in repository.

## 9. Example SCD
`examples/station.scd`.

## 10. Example YAML test
`examples/scenario.yaml`.

## 11. Unit tests
`tests/test_scl_parser.cpp`, `tests/test_scheduler.cpp`.
