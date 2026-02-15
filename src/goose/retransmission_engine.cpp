#include "goose_sim/goose/retransmission_engine.hpp"

#include <algorithm>

namespace goose_sim::goose {

model::Milliseconds RetransmissionEngine::next_delay(std::uint32_t retransmit_count, std::uint32_t min_ms, std::uint32_t max_ms) const {
    const auto value = std::min(max_ms, min_ms << std::min<std::uint32_t>(retransmit_count, 8));
    return model::Milliseconds(value);
}

}
