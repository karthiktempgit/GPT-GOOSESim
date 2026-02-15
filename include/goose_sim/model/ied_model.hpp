#pragma once

#include "goose_sim/model/types.hpp"

namespace goose_sim::model {

class IedRepository {
public:
    void add(IedModel ied);
    const std::vector<IedModel>& all() const noexcept;

private:
    std::vector<IedModel> ieds_;
};

}
