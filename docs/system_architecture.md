# IEC 61850 GOOSE Simulator + Subscriber Architecture (C++17)

## 1) Technology choice and determinism rationale
- **C++17** is used for deterministic control of memory layout, thread affinity, lock-free queues, and raw socket integrations without managed-runtime jitter.
- **libiec61850** integration point is `goose/` encoder/decoder boundary for standards-compliant APDU composition.
- **libpcap/Npcap abstraction** is in `network/` to isolate OS differences.
- **pugixml** is used in `scl/` for low-overhead SCL parsing.
- **CLI11** drives a deterministic CLI front-end.
- **spdlog** provides bounded, async-capable structured logging.

## 2) Module architecture

```text
+-------------------+      +--------------------+      +-------------------+
| cli/              | ---> | simulation/        | ---> | goose/            |
| command_interface |      | event_engine       |      | publisher         |
+---------+---------+      +----------+---------+      +----------+--------+
          |                           |                           |
          v                           v                           v
+---------+---------+      +----------+---------+      +----------+--------+
| scl/              | ---> | model/             | <--- | goose/subscriber  |
| scl_parser        |      | ied_model          |      | supervision       |
+---------+---------+      +----------+---------+      +----------+--------+
          |                           |                           |
          v                           v                           v
+---------+---------+      +----------+---------+      +----------+--------+
| core/             | ---> | network/           | ---> | recording/        |
| scheduler/clock   |      | raw_socket/capture |      | pcap/statistics   |
+-------------------+      +--------------------+      +-------------------+

+-------------------+
| validation/       |
| rule_engine       |
+-------------------+
```

## 3) Threading model
- **Tx thread**: deterministic send path for periodic + event GOOSE retransmissions.
- **Rx thread**: libpcap capture callback path, no blocking decode in callback; frames enqueue to worker.
- **Logic thread**: event engine + scenario execution + state changes.
- **Validation thread**: rule evaluation and latency checks.

## 4) Memory ownership model
- Configuration objects (`IedModel`, `GooseControlBlock`, `DataSet`) are immutable after startup and shared read-only.
- Runtime mutable state per publisher/subscriber stays thread-confined where possible.
- Cross-thread transfers use value-semantics events and bounded queues.

## 5) Timing model
- Monotonic steady clock only.
- Scheduler dispatch based on `wait_until` with strict due-time ordering.
- Retransmission curve follows bounded exponential sequence clamped by MinTime/MaxTime.
- No blocking calls in deterministic loop.

## 6) Threat model
- **Malformed frames**: decoder returns optional and rejects short/invalid payloads.
- **Config spoofing/confRev mismatch**: supervision + validation flags incompatible streams.
- **Resource exhaustion**: bounded queues, pre-allocation strategy in production send loop.
- **Privilege misconfiguration**: startup checks for capture/send capabilities.

## 7) Class responsibilities
- `core::Scheduler`: deterministic delayed execution.
- `scl::SclParser`: parse SCL (SCD/CID/IID) into internal model.
- `goose::Publisher`: stNum/sqNum state and frame emission.
- `goose::Subscriber`: frame sequence tracking.
- `network::RawSocket`: OS-neutral send abstraction.
- `simulation::EventEngine`: scheduled scenario execution.
- `validation::RuleEngine`: expectations + pass/fail outcomes.

## 8) Build instructions
### Linux
1. Install dependencies: CMake, compiler, libpcap, spdlog, CLI11, pugixml, GoogleTest.
2. `cmake -S . -B build`
3. `cmake --build build -j`
4. `ctest --test-dir build --output-on-failure`

### Windows
1. Install Visual Studio 2022, CMake, vcpkg, Npcap SDK.
2. Install libraries via vcpkg: `spdlog cli11 pugixml gtest libpcap`.
3. Configure: `cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=<vcpkg.cmake>`
4. Build + test using CMake.
