#pragma once

#include "goose_sim/model/types.hpp"

#include <cstdint>

namespace goose_sim::validation {

class LatencyAnalyzer {
public:
    std::uint32_t milliseconds_between(model::TimePoint start, model::TimePoint end) const;
};

}
