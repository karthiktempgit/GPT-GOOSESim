#include "goose_sim/validation/latency_analyzer.hpp"

namespace goose_sim::validation {

std::uint32_t LatencyAnalyzer::milliseconds_between(model::TimePoint start, model::TimePoint end) const {
    return static_cast<std::uint32_t>(std::chrono::duration_cast<model::Milliseconds>(end - start).count());
}

}
