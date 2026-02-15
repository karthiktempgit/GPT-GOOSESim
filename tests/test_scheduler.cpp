#include "goose_sim/core/scheduler.hpp"

#include <atomic>
#include <gtest/gtest.h>
#include <thread>

TEST(Scheduler, ExecutesScheduledWork) {
    goose_sim::core::Scheduler scheduler;
    std::atomic<int> count{0};

    scheduler.start();
    scheduler.schedule_after(goose_sim::model::Milliseconds(5), [&count] { ++count; });
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    scheduler.stop();

    EXPECT_EQ(count.load(), 1);
}
