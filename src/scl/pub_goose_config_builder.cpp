#include "goose_sim/scl/pub_goose_config_builder.hpp"

namespace goose_sim::scl {
std::vector<model::GooseControlBlock> PubGooseConfigBuilder::build(const model::IedModel& ied) {
    return ied.publishers;
}
}
