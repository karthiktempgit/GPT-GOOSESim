#include "goose_sim/network/multicast_manager.hpp"

namespace goose_sim::network {

std::string MulticastManager::derive_goose_mac(const std::string& app_id_hex) {
    return "01:0c:cd:01:" + app_id_hex.substr(0, 2) + ":" + app_id_hex.substr(2, 2);
}

}
