#pragma once

#include "goose_sim/model/types.hpp"

namespace goose_sim::goose {

class RetransmissionEngine {
public:
    model::Milliseconds next_delay(std::uint32_t retransmit_count, std::uint32_t min_ms, std::uint32_t max_ms) const;
};

}
