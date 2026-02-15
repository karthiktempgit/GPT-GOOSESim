#pragma once

#include "goose_sim/model/types.hpp"

namespace goose_sim::core {

class MonotonicClock {
public:
    static model::TimePoint now() noexcept;
};

}  // namespace goose_sim::core
