#pragma once

#include <cstdint>
#include <functional>
#include <vector>

namespace goose_sim::network {

class CaptureEngine {
public:
    using Callback = std::function<void(const std::vector<std::uint8_t>&)>;
    void set_callback(Callback callback);
    void ingest_frame(const std::vector<std::uint8_t>& frame);

private:
    Callback callback_;
};

}
