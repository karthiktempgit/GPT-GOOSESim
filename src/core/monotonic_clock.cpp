#include "goose_sim/core/monotonic_clock.hpp"

namespace goose_sim::core {

model::TimePoint MonotonicClock::now() noexcept {
    return model::Clock::now();
}

}  // namespace goose_sim::core
