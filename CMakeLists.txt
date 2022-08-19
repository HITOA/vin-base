cmake_minimum_required(VERSION 3.2)
project(vin-base CXX)

file(GLOB_RECURSE vin_base_src "src/*.cpp" "src/*.hpp")

add_library(vin_base STATIC ${vin_base_src})

target_include_directories(vin_base PUBLIC src)
set_target_properties(vin_base PROPERTIES LINKER_LANGUAGE CXX)