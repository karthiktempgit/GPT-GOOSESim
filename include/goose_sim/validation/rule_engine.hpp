#pragma once

#include "goose_sim/model/types.hpp"

#include <string>
#include <vector>

namespace goose_sim::validation {

struct RuleResult {
    std::string name;
    bool passed{false};
};

class RuleEngine {
public:
    void add_latency_rule(std::string name, std::uint32_t max_ms);
    std::vector<RuleResult> evaluate(std::uint32_t measured_ms) const;

private:
    std::vector<std::pair<std::string, std::uint32_t>> latency_rules_;
};

}
