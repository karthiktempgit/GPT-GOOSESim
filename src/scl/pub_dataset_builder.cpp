#include "goose_sim/scl/pub_dataset_builder.hpp"

namespace goose_sim::scl {
std::vector<model::DataSet> PubDatasetBuilder::build(const model::IedModel& ied) {
    std::vector<model::DataSet> result;
    for (const auto& [_, ds] : ied.datasets) {
        result.push_back(ds);
    }
    return result;
}
}
