#include "goose_sim/goose/sub_goose_decoder.hpp"

namespace goose_sim::goose {

std::optional<DecodedGooseFrame> SubGooseDecoder::decode(const std::vector<std::uint8_t>& frame) const {
    if (frame.size() < 2) {
        return std::nullopt;
    }
    return DecodedGooseFrame{frame[0], frame[1]};
}

}  // namespace goose_sim::goose
