#include "goose_sim/scl/sub_goose_config_builder.hpp"

namespace goose_sim::scl {
std::vector<model::GooseControlBlock> SubGooseConfigBuilder::build(const model::IedModel& ied) {
    return ied.subscribers;
}
}
