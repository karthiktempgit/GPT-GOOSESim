#pragma once

#include "goose_sim/model/types.hpp"

namespace goose_sim::goose {

class Supervision {
public:
    bool ttl_expired(model::TimePoint last_rx, std::uint32_t ttl_ms, model::TimePoint now) const;
};

}
