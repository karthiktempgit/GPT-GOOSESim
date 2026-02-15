#pragma once
#include "goose_sim/model/types.hpp"
#include <vector>

namespace goose_sim::scl {
class PubDatasetBuilder {
public:
    static std::vector<model::DataSet> build(const model::IedModel& ied);
};
}
