#include "goose_sim/network/ethernet_frame_builder.hpp"

namespace goose_sim::network {

std::vector<std::uint8_t> EthernetFrameBuilder::build(const std::vector<std::uint8_t>& payload) const {
    std::vector<std::uint8_t> frame(18, 0);
    frame.insert(frame.end(), payload.begin(), payload.end());
    return frame;
}

}
