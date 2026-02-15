#pragma once

#include <cstdint>

namespace goose_sim::recording {

class Statistics {
public:
    void on_send();
    void on_retransmit();
    std::uint64_t sent() const noexcept;
    std::uint64_t retransmits() const noexcept;

private:
    std::uint64_t sent_{0};
    std::uint64_t retransmits_{0};
};

}
