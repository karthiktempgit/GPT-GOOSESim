#include "goose_sim/goose/subscriber.hpp"

namespace goose_sim::goose {

bool Subscriber::process_frame(const std::vector<std::uint8_t>& frame) {
    auto decoded = decoder_.decode(frame);
    if (!decoded.has_value()) {
        return false;
    }
    last_st_num_ = decoded->st_num;
    last_sq_num_ = decoded->sq_num;
    return true;
}

}  // namespace goose_sim::goose
