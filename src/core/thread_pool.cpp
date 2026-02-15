#include "goose_sim/core/thread_pool.hpp"

namespace goose_sim::core {

ThreadPool::ThreadPool(std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        workers_.emplace_back([this] {
            while (true) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(mutex_);
                    cv_.wait(lock, [this] { return shutdown_ || !queue_.empty(); });
                    if (shutdown_ && queue_.empty()) {
                        return;
                    }
                    task = std::move(queue_.front());
                    queue_.pop();
                }
                task();
            }
        });
    }
}

ThreadPool::~ThreadPool() {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        shutdown_ = true;
    }
    cv_.notify_all();
    for (auto& worker : workers_) {
        if (worker.joinable()) {
            worker.join();
        }
    }
}

void ThreadPool::submit(std::function<void()> work) {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(std::move(work));
    }
    cv_.notify_one();
}

}  // namespace goose_sim::core
