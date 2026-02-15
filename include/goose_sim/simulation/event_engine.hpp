#pragma once

#include "goose_sim/core/scheduler.hpp"

#include <functional>

namespace goose_sim::simulation {

class EventEngine {
public:
    explicit EventEngine(core::Scheduler& scheduler);
    void at(std::uint32_t offset_ms, std::function<void()> callback);

private:
    core::Scheduler& scheduler_;
};

}
