#pragma once

#include "goose_sim/model/types.hpp"

namespace goose_sim::simulation {

class IedInstance {
public:
    explicit IedInstance(model::IedModel model);
    const model::IedModel& view() const noexcept;

private:
    model::IedModel model_;
};

}
