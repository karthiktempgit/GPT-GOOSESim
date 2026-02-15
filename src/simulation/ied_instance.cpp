#include "goose_sim/simulation/ied_instance.hpp"

namespace goose_sim::simulation {

IedInstance::IedInstance(model::IedModel model) : model_(std::move(model)) {}

const model::IedModel& IedInstance::view() const noexcept {
    return model_;
}

}
