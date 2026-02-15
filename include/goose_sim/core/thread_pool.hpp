#pragma once

#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace goose_sim::core {

class ThreadPool {
public:
    explicit ThreadPool(std::size_t size);
    ~ThreadPool();

    void submit(std::function<void()> work);

private:
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
    bool shutdown_{false};
};

}  // namespace goose_sim::core
