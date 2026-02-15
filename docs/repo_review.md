# Repository-wide File Review

This document records a full pass over every tracked file in the repository (`rg --files` reported 70 files).

## Executive assessment

- The project is a cleanly organized **architecture baseline** with strong module boundaries and simple, readable implementations.
- A significant portion of the implementation is intentionally minimal/scaffold-level and does not yet match the depth implied by the architecture documents.
- Build reproducibility is currently limited by hard `find_package(...)` requirements and no fallback/dependency bootstrap guidance in the root README.

## Highest-priority findings

1. **GOOSE sequence numbers are reduced to 8-bit values during encoding**, causing wraparound and loss of fidelity for real traffic simulation (`stNum`/`sqNum` are 32-bit in model/API, but only low byte serialized). See `src/goose/pub_goose_encoder.cpp`.
2. **Subscriber decoder accepts any frame with 2+ bytes**, with no Ethernet/GOOSE structure or APDU validation. See `src/goose/sub_goose_decoder.cpp`.
3. **SCL parser currently extracts only a subset of useful GSE metadata** and maps `GSEControl@appID` into `go_id` while leaving multiple communication fields unset. See `src/scl/scl_parser.cpp` and `include/goose_sim/model/types.hpp`.
4. **Scheduler task ordering for equal due times is not deterministic by task ID** (ID exists but is not part of comparator tie-break), which can matter for deterministic simulations. See `include/goose_sim/core/scheduler.hpp`.
5. **Unit-test coverage is very light** (only parser smoke and one scheduler timing test). See `tests/test_scl_parser.cpp` and `tests/test_scheduler.cpp`.

## Build/verification notes from review run

- Configure/build attempt failed in this environment due to missing `libpcap` and `spdlog` package configs.
- Command used: `cmake -S . -B build && cmake --build build -j4 && ctest --test-dir build --output-on-failure`.

## File-by-file review inventory

Reviewed files:

- `CMakeLists.txt`
- `README.md`
- `docs/deliverables.md`
- `docs/system_architecture.md`
- `docs/repo_review.md` (this file)
- `examples/scenario.yaml`
- `examples/station.scd`
- `tests/test_scheduler.cpp`
- `tests/test_scl_parser.cpp`
- `src/main.cpp`
- `src/cli/command_interface.cpp`
- `src/core/monotonic_clock.cpp`
- `src/core/scheduler.cpp`
- `src/core/thread_pool.cpp`
- `src/goose/frame_codec.cpp`
- `src/goose/pub_goose_encoder.cpp`
- `src/goose/publisher.cpp`
- `src/goose/retransmission_engine.cpp`
- `src/goose/sub_goose_decoder.cpp`
- `src/goose/subscriber.cpp`
- `src/goose/supervision.cpp`
- `src/model/data_attributes.cpp`
- `src/model/ied_model.cpp`
- `src/network/capture_engine.cpp`
- `src/network/ethernet_frame_builder.cpp`
- `src/network/multicast_manager.cpp`
- `src/network/raw_socket.cpp`
- `src/network/vlan_handler.cpp`
- `src/recording/pcap_writer.cpp`
- `src/recording/statistics.cpp`
- `src/scl/pub_dataset_builder.cpp`
- `src/scl/pub_goose_config_builder.cpp`
- `src/scl/scl_parser.cpp`
- `src/scl/sub_dataset_builder.cpp`
- `src/scl/sub_goose_config_builder.cpp`
- `src/simulation/event_engine.cpp`
- `src/simulation/ied_instance.cpp`
- `src/simulation/state_machine.cpp`
- `src/validation/latency_analyzer.cpp`
- `src/validation/rule_engine.cpp`
- `include/goose_sim/cli/command_interface.hpp`
- `include/goose_sim/core/monotonic_clock.hpp`
- `include/goose_sim/core/scheduler.hpp`
- `include/goose_sim/core/thread_pool.hpp`
- `include/goose_sim/goose/frame_codec.hpp`
- `include/goose_sim/goose/pub_goose_encoder.hpp`
- `include/goose_sim/goose/publisher.hpp`
- `include/goose_sim/goose/retransmission_engine.hpp`
- `include/goose_sim/goose/sub_goose_decoder.hpp`
- `include/goose_sim/goose/subscriber.hpp`
- `include/goose_sim/goose/supervision.hpp`
- `include/goose_sim/model/data_attributes.hpp`
- `include/goose_sim/model/ied_model.hpp`
- `include/goose_sim/model/types.hpp`
- `include/goose_sim/network/capture_engine.hpp`
- `include/goose_sim/network/ethernet_frame_builder.hpp`
- `include/goose_sim/network/multicast_manager.hpp`
- `include/goose_sim/network/raw_socket.hpp`
- `include/goose_sim/network/vlan_handler.hpp`
- `include/goose_sim/recording/pcap_writer.hpp`
- `include/goose_sim/recording/statistics.hpp`
- `include/goose_sim/scl/pub_dataset_builder.hpp`
- `include/goose_sim/scl/pub_goose_config_builder.hpp`
- `include/goose_sim/scl/scl_parser.hpp`
- `include/goose_sim/scl/sub_dataset_builder.hpp`
- `include/goose_sim/scl/sub_goose_config_builder.hpp`
- `include/goose_sim/simulation/event_engine.hpp`
- `include/goose_sim/simulation/ied_instance.hpp`
- `include/goose_sim/simulation/state_machine.hpp`
- `include/goose_sim/validation/latency_analyzer.hpp`
- `include/goose_sim/validation/rule_engine.hpp`

## Suggested next review phase

1. Add targeted tests for encoder/decoder, scheduler ordering, and parser field extraction.
2. Expand parser to fill `GooseCommProfile` and align field mapping with IEC 61850 naming.
3. Harden wire-format implementation (EtherType, VLAN, BER/ASN.1 boundaries, dataset serialization).
4. Introduce CI preset/toolchain docs to make dependency setup deterministic.
