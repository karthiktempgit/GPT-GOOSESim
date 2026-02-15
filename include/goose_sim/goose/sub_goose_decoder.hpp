#pragma once

#include "goose_sim/model/types.hpp"

#include <cstdint>
#include <optional>
#include <vector>

namespace goose_sim::goose {

struct DecodedGooseFrame {
    std::uint32_t st_num{0};
    std::uint32_t sq_num{0};
};

class SubGooseDecoder {
public:
    std::optional<DecodedGooseFrame> decode(const std::vector<std::uint8_t>& frame) const;
};

}  // namespace goose_sim::goose
