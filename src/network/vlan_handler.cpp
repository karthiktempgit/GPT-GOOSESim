#include "goose_sim/network/vlan_handler.hpp"

namespace goose_sim::network {

std::uint16_t VlanHandler::tci(std::uint16_t vlan_id, std::uint8_t priority) const {
    return static_cast<std::uint16_t>(((priority & 0x7U) << 13U) | (vlan_id & 0x0FFFU));
}

}
