#include "goose_sim/validation/rule_engine.hpp"

namespace goose_sim::validation {

void RuleEngine::add_latency_rule(std::string name, std::uint32_t max_ms) {
    latency_rules_.push_back({std::move(name), max_ms});
}

std::vector<RuleResult> RuleEngine::evaluate(std::uint32_t measured_ms) const {
    std::vector<RuleResult> results;
    for (const auto& [name, limit] : latency_rules_) {
        results.push_back({name, measured_ms <= limit});
    }
    return results;
}

}
