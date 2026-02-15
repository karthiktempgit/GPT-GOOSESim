#pragma once

#include <cstdint>
#include <vector>

namespace goose_sim::goose {

class FrameCodec {
public:
    std::vector<std::uint8_t> add_ethernet_header(const std::vector<std::uint8_t>& payload) const;
};

}  // namespace goose_sim::goose
