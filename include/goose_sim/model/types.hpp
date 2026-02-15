#pragma once

#include <chrono>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace goose_sim::model {

using Clock = std::chrono::steady_clock;
using TimePoint = Clock::time_point;
using Milliseconds = std::chrono::milliseconds;

struct DataAttributeValue {
    std::string path;
    bool bool_value{false};
    std::uint32_t quality{0};
    TimePoint timestamp{Clock::now()};
};

struct DataSet {
    std::string reference;
    std::vector<DataAttributeValue> values;
};

struct GooseCommProfile {
    std::string app_id;
    std::string dst_mac;
    std::uint16_t vlan_id{0};
    std::uint8_t vlan_priority{4};
    std::uint32_t min_time_ms{4};
    std::uint32_t max_time_ms{1000};
    std::uint32_t conf_rev{1};
};

struct GooseControlBlock {
    std::string ied_name;
    std::string ld_inst;
    std::string ln0;
    std::string cb_name;
    std::string go_cb_ref;
    std::string data_set_ref;
    std::string go_id;
    GooseCommProfile profile;
};

struct IedModel {
    std::string name;
    std::unordered_map<std::string, DataSet> datasets;
    std::vector<GooseControlBlock> publishers;
    std::vector<GooseControlBlock> subscribers;
};

}  // namespace goose_sim::model
