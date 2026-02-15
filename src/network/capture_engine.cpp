#include "goose_sim/network/capture_engine.hpp"

namespace goose_sim::network {

void CaptureEngine::set_callback(Callback callback) {
    callback_ = std::move(callback);
}

void CaptureEngine::ingest_frame(const std::vector<std::uint8_t>& frame) {
    if (callback_) {
        callback_(frame);
    }
}

}
