#include "goose_sim/goose/frame_codec.hpp"

namespace goose_sim::goose {

std::vector<std::uint8_t> FrameCodec::add_ethernet_header(const std::vector<std::uint8_t>& payload) const {
    std::vector<std::uint8_t> frame(14, 0);
    frame.insert(frame.end(), payload.begin(), payload.end());
    return frame;
}

}  // namespace goose_sim::goose
