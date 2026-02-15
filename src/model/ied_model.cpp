#include "goose_sim/model/ied_model.hpp"

namespace goose_sim::model {

void IedRepository::add(IedModel ied) {
    ieds_.push_back(std::move(ied));
}

const std::vector<IedModel>& IedRepository::all() const noexcept {
    return ieds_;
}

}
