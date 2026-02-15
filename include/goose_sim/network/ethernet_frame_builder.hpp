#pragma once

#include <cstdint>
#include <vector>

namespace goose_sim::network {

class EthernetFrameBuilder {
public:
    std::vector<std::uint8_t> build(const std::vector<std::uint8_t>& payload) const;
};

}
