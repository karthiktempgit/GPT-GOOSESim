#include "goose_sim/cli/command_interface.hpp"
#include "goose_sim/scl/scl_parser.hpp"

#include <spdlog/spdlog.h>

int main(int argc, char** argv) {
    goose_sim::cli::CommandInterface cli;
    auto options = cli.parse(argc, argv);

    spdlog::info("Starting goose-tool on iface={} scl={} script={}", options.iface, options.scl, options.script);

    if (!options.scl.empty()) {
        goose_sim::scl::SclParser parser;
        auto ieds = parser.parse_file(options.scl);
        spdlog::info("Loaded {} IEDs", ieds.size());
    }

    return 0;
}
