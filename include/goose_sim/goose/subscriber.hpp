#pragma once

#include "goose_sim/goose/sub_goose_decoder.hpp"

#include <cstdint>
#include <vector>

namespace goose_sim::goose {

class Subscriber {
public:
    bool process_frame(const std::vector<std::uint8_t>& frame);
    std::uint32_t last_st_num() const noexcept { return last_st_num_; }
    std::uint32_t last_sq_num() const noexcept { return last_sq_num_; }

private:
    SubGooseDecoder decoder_;
    std::uint32_t last_st_num_{0};
    std::uint32_t last_sq_num_{0};
};

}  // namespace goose_sim::goose
