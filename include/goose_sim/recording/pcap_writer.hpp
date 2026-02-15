#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace goose_sim::recording {

class PcapWriter {
public:
    bool write(const std::string& path, const std::vector<std::vector<std::uint8_t>>& frames) const;
};

}
