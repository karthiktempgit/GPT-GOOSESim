#pragma once

#include <cstdint>

namespace goose_sim::network {

class VlanHandler {
public:
    std::uint16_t tci(std::uint16_t vlan_id, std::uint8_t priority) const;
};

}
