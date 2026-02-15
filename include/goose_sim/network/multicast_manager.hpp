#pragma once

#include <string>

namespace goose_sim::network {

class MulticastManager {
public:
    static std::string derive_goose_mac(const std::string& app_id_hex);
};

}
