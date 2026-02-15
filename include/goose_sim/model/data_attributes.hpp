#pragma once

#include "goose_sim/model/types.hpp"

#include <optional>

namespace goose_sim::model {

class DataAttributes {
public:
    static std::optional<DataAttributeValue> find(const DataSet& set, const std::string& path);
};

}
