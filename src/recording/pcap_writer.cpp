#include "goose_sim/recording/pcap_writer.hpp"

#include <fstream>

namespace goose_sim::recording {

bool PcapWriter::write(const std::string& path, const std::vector<std::vector<std::uint8_t>>& frames) const {
    std::ofstream file(path, std::ios::binary);
    if (!file) {
        return false;
    }
    for (const auto& frame : frames) {
        file.write(reinterpret_cast<const char*>(frame.data()), static_cast<std::streamsize>(frame.size()));
    }
    return true;
}

}
