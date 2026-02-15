#pragma once

#include "goose_sim/model/types.hpp"

#include <string>
#include <vector>

namespace goose_sim::scl {

class SclParser {
public:
    std::vector<model::IedModel> parse_file(const std::string& path) const;
};

}  // namespace goose_sim::scl
