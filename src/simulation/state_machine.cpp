#include "goose_sim/simulation/state_machine.hpp"

namespace goose_sim::simulation {

void StateMachine::transition_to(std::string state) {
    state_ = std::move(state);
}

const std::string& StateMachine::current_state() const noexcept {
    return state_;
}

}
