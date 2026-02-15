#include "goose_sim/recording/statistics.hpp"

namespace goose_sim::recording {

void Statistics::on_send() { ++sent_; }
void Statistics::on_retransmit() { ++retransmits_; }
std::uint64_t Statistics::sent() const noexcept { return sent_; }
std::uint64_t Statistics::retransmits() const noexcept { return retransmits_; }

}
