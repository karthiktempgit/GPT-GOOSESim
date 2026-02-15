#include "goose_sim/goose/pub_goose_encoder.hpp"

namespace goose_sim::goose {

std::vector<std::uint8_t> PubGooseEncoder::encode(const model::GooseControlBlock&,
                                                  const model::DataSet& dataset,
                                                  std::uint32_t st_num,
                                                  std::uint32_t sq_num) const {
    std::vector<std::uint8_t> buffer;
    buffer.reserve(64 + dataset.values.size() * 8);
    buffer.push_back(static_cast<std::uint8_t>(st_num & 0xFF));
    buffer.push_back(static_cast<std::uint8_t>(sq_num & 0xFF));
    for (const auto& value : dataset.values) {
        buffer.push_back(static_cast<std::uint8_t>(value.bool_value));
    }
    return buffer;
}

}  // namespace goose_sim::goose
