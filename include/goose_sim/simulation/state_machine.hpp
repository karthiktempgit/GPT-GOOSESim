#pragma once

#include <string>

namespace goose_sim::simulation {

class StateMachine {
public:
    void transition_to(std::string state);
    const std::string& current_state() const noexcept;

private:
    std::string state_{"INIT"};
};

}
