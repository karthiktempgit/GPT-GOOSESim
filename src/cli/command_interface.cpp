#include "goose_sim/cli/command_interface.hpp"

#include <CLI/CLI.hpp>

namespace goose_sim::cli {

CliOptions CommandInterface::parse(int argc, char** argv) const {
    CliOptions options;
    CLI::App app{"GOOSE simulator and subscriber"};
    app.add_option("--iface", options.iface, "Network interface");
    app.add_option("--scd", options.scl, "SCL file path");
    app.add_option("--script", options.script, "YAML scenario path");
    app.add_flag("--simulate-all", options.simulate_all, "Enable all configured IEDs");
    app.parse(argc, argv);
    return options;
}

}
