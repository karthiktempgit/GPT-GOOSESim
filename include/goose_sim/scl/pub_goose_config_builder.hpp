#pragma once
#include "goose_sim/model/types.hpp"
#include <vector>

namespace goose_sim::scl {
class PubGooseConfigBuilder {
public:
    static std::vector<model::GooseControlBlock> build(const model::IedModel& ied);
};
}
