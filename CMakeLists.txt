cmake_minimum_required(VERSION 3.2)
project(vin-base CXX)


set(EXTERNAL_PATH ${CMAKE_SOURCE_DIR}/3rdparty)

add_subdirectory(${EXTERNAL_PATH}/mimalloc)

file(GLOB_RECURSE vin_base_src "src/*.cpp" "src/*.hpp")

add_library(vin_base STATIC ${vin_base_src})

target_link_libraries(vin_base mimalloc-static)
target_include_directories(vin_base PUBLIC src)
set_target_properties(vin_base PROPERTIES LINKER_LANGUAGE CXX)

add_executable(vin_base_test test/main.cpp)

target_link_libraries(vin_base_test vin_base)