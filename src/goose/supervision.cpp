#include "goose_sim/goose/supervision.hpp"

namespace goose_sim::goose {

bool Supervision::ttl_expired(model::TimePoint last_rx, std::uint32_t ttl_ms, model::TimePoint now) const {
    return now - last_rx > model::Milliseconds(ttl_ms);
}

}
