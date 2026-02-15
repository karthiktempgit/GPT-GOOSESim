#include "goose_sim/network/raw_socket.hpp"

namespace goose_sim::network {

bool RawSocket::open(const std::string& interface_name) {
    interface_name_ = interface_name;
    return !interface_name_.empty();
}

bool RawSocket::send(const std::vector<std::uint8_t>& frame) {
    return !interface_name_.empty() && !frame.empty();
}

}
