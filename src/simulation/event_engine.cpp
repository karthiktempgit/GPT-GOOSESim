#include "goose_sim/simulation/event_engine.hpp"

namespace goose_sim::simulation {

EventEngine::EventEngine(core::Scheduler& scheduler) : scheduler_(scheduler) {}

void EventEngine::at(std::uint32_t offset_ms, std::function<void()> callback) {
    scheduler_.schedule_after(model::Milliseconds(offset_ms), std::move(callback));
}

}
