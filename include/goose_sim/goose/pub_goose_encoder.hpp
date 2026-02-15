#pragma once

#include "goose_sim/model/types.hpp"

#include <cstdint>
#include <vector>

namespace goose_sim::goose {

class PubGooseEncoder {
public:
    std::vector<std::uint8_t> encode(const model::GooseControlBlock& gcb,
                                     const model::DataSet& dataset,
                                     std::uint32_t st_num,
                                     std::uint32_t sq_num) const;
};

}  // namespace goose_sim::goose
