#include "goose_sim/scl/scl_parser.hpp"

#include <gtest/gtest.h>

TEST(SclParser, ParsesIedAndDataSet) {
    goose_sim::scl::SclParser parser;
    auto ieds = parser.parse_file("examples/station.scd");
    ASSERT_EQ(ieds.size(), 1U);
    EXPECT_EQ(ieds.front().name, "P1");
    EXPECT_FALSE(ieds.front().datasets.empty());
    EXPECT_EQ(ieds.front().publishers.size(), 1U);
}
