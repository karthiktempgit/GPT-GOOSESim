#pragma once

#include "goose_sim/model/types.hpp"

#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>

namespace goose_sim::core {

class Scheduler {
public:
    using Task = std::function<void()>;
    Scheduler();
    ~Scheduler();

    std::uint64_t schedule_at(model::TimePoint when, Task task);
    std::uint64_t schedule_after(model::Milliseconds delay, Task task);
    void start();
    void stop();

private:
    struct ScheduledTask {
        model::TimePoint due;
        std::uint64_t id;
        Task task;

        bool operator<(const ScheduledTask& other) const {
            return due > other.due;
        }
    };

    void run();

    std::priority_queue<ScheduledTask> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
    std::atomic<bool> running_{false};
    std::atomic<std::uint64_t> next_id_{1};
    std::thread worker_;
};

}  // namespace goose_sim::core
