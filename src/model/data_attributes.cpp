#include "goose_sim/model/data_attributes.hpp"

namespace goose_sim::model {

std::optional<DataAttributeValue> DataAttributes::find(const DataSet& set, const std::string& path) {
    for (const auto& value : set.values) {
        if (value.path == path) {
            return value;
        }
    }
    return std::nullopt;
}

}
