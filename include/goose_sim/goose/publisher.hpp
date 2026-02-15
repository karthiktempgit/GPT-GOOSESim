#pragma once

#include "goose_sim/goose/pub_goose_encoder.hpp"
#include "goose_sim/model/types.hpp"

#include <cstdint>
#include <functional>
#include <vector>

namespace goose_sim::goose {

class Publisher {
public:
    using FrameSink = std::function<void(const std::vector<std::uint8_t>&)>;

    Publisher(model::GooseControlBlock gcb, model::DataSet dataset, FrameSink sink);
    void on_dataset_change(model::DataSet dataset);
    void retransmit_tick();

private:
    model::GooseControlBlock gcb_;
    model::DataSet dataset_;
    FrameSink sink_;
    PubGooseEncoder encoder_;
    std::uint32_t st_num_{1};
    std::uint32_t sq_num_{0};
};

}  // namespace goose_sim::goose
