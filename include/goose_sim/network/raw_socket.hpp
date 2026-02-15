#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace goose_sim::network {

class RawSocket {
public:
    bool open(const std::string& interface_name);
    bool send(const std::vector<std::uint8_t>& frame);

private:
    std::string interface_name_;
};

}
