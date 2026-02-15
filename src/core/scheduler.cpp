#include "goose_sim/core/scheduler.hpp"

namespace goose_sim::core {

Scheduler::Scheduler() = default;

Scheduler::~Scheduler() {
    stop();
}

void Scheduler::start() {
    if (running_.exchange(true)) {
        return;
    }
    worker_ = std::thread(&Scheduler::run, this);
}

void Scheduler::stop() {
    if (!running_.exchange(false)) {
        return;
    }
    cv_.notify_all();
    if (worker_.joinable()) {
        worker_.join();
    }
}

std::uint64_t Scheduler::schedule_at(model::TimePoint when, Task task) {
    const auto id = next_id_.fetch_add(1);
    {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(ScheduledTask{when, id, std::move(task)});
    }
    cv_.notify_one();
    return id;
}

std::uint64_t Scheduler::schedule_after(model::Milliseconds delay, Task task) {
    return schedule_at(model::Clock::now() + delay, std::move(task));
}

void Scheduler::run() {
    while (running_) {
        std::unique_lock<std::mutex> lock(mutex_);
        if (queue_.empty()) {
            cv_.wait(lock, [this] { return !running_ || !queue_.empty(); });
            continue;
        }

        auto next_due = queue_.top().due;
        if (cv_.wait_until(lock, next_due, [this, next_due] {
                return !running_ || queue_.empty() || queue_.top().due < next_due;
            })) {
            continue;
        }

        auto task = std::move(queue_.top().task);
        queue_.pop();
        lock.unlock();
        task();
    }
}

}  // namespace goose_sim::core
