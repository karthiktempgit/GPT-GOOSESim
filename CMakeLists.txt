cmake_minimum_required(VERSION 3.20)
project(goose_tool VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(GOOSE_SIM_BUILD_TESTS "Build tests" ON)

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBPCAP libpcap)

find_package(spdlog REQUIRED)
find_package(CLI11 REQUIRED)
find_package(pugixml REQUIRED)
find_package(GTest REQUIRED)

add_library(goose_sim
    src/core/monotonic_clock.cpp
    src/core/scheduler.cpp
    src/core/thread_pool.cpp
    src/scl/scl_parser.cpp
    src/scl/pub_dataset_builder.cpp
    src/scl/pub_goose_config_builder.cpp
    src/scl/sub_dataset_builder.cpp
    src/scl/sub_goose_config_builder.cpp
    src/goose/publisher.cpp
    src/goose/pub_goose_encoder.cpp
    src/goose/subscriber.cpp
    src/goose/sub_goose_decoder.cpp
    src/goose/frame_codec.cpp
    src/goose/retransmission_engine.cpp
    src/goose/supervision.cpp
    src/network/raw_socket.cpp
    src/network/capture_engine.cpp
    src/network/ethernet_frame_builder.cpp
    src/network/vlan_handler.cpp
    src/network/multicast_manager.cpp
    src/model/ied_model.cpp
    src/model/data_attributes.cpp
    src/simulation/ied_instance.cpp
    src/simulation/event_engine.cpp
    src/simulation/state_machine.cpp
    src/validation/rule_engine.cpp
    src/validation/latency_analyzer.cpp
    src/recording/pcap_writer.cpp
    src/recording/statistics.cpp
    src/cli/command_interface.cpp)

target_include_directories(goose_sim PUBLIC include)
target_link_libraries(goose_sim
    PUBLIC Threads::Threads spdlog::spdlog CLI11::CLI11 pugixml::pugixml)
if(LIBPCAP_FOUND)
  target_include_directories(goose_sim PRIVATE ${LIBPCAP_INCLUDE_DIRS})
  target_link_libraries(goose_sim PRIVATE ${LIBPCAP_LINK_LIBRARIES})
endif()

add_executable(goose-tool src/main.cpp)
target_link_libraries(goose-tool PRIVATE goose_sim)

if(GOOSE_SIM_BUILD_TESTS)
  enable_testing()
  add_executable(goose_sim_tests tests/test_scl_parser.cpp tests/test_scheduler.cpp)
  target_link_libraries(goose_sim_tests PRIVATE goose_sim GTest::gtest GTest::gtest_main)
  add_test(NAME goose_sim_tests COMMAND goose_sim_tests)
endif()
