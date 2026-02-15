#pragma once

#include <string>

namespace goose_sim::cli {

struct CliOptions {
    std::string iface;
    std::string scl;
    std::string script;
    bool simulate_all{false};
};

class CommandInterface {
public:
    CliOptions parse(int argc, char** argv) const;
};

}
