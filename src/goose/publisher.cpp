#include "goose_sim/goose/publisher.hpp"

namespace goose_sim::goose {

Publisher::Publisher(model::GooseControlBlock gcb, model::DataSet dataset, FrameSink sink)
    : gcb_(std::move(gcb)), dataset_(std::move(dataset)), sink_(std::move(sink)) {}

void Publisher::on_dataset_change(model::DataSet dataset) {
    dataset_ = std::move(dataset);
    ++st_num_;
    sq_num_ = 0;
    sink_(encoder_.encode(gcb_, dataset_, st_num_, sq_num_));
}

void Publisher::retransmit_tick() {
    ++sq_num_;
    sink_(encoder_.encode(gcb_, dataset_, st_num_, sq_num_));
}

}  // namespace goose_sim::goose
