# GOOSE Tool (Publisher + Subscriber + Validator)

This repository contains a production-oriented **C++17** architecture baseline for an IEC 61850 GOOSE simulator/subscriber/validator.

## Why C++17 for this tool
C++17 gives deterministic timing control, no managed runtime pauses, direct raw-Ethernet integration, and predictable memory/CPU behavior required for FAT/SAT-grade substation test workflows.

## Current scope in this baseline
- Modular architecture matching core/scl/goose/network/model/simulation/validation/recording/cli domains.
- SCL parsing baseline (IED/LDevice/LN0/DataSet/GSEControl extraction).
- Publisher/subscriber sequence state handling (`stNum`, `sqNum`) scaffolding.
- Timing scheduler and event engine foundations.
- Validation and latency-rule scaffold.
- Unit tests and example SCD/YAML scenarios.

For architecture details see `docs/system_architecture.md` and `docs/deliverables.md`.
