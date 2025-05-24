cmake_minimum_required(VERSION 3.12)

project(bau)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost COMPONENTS REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

set(
    BUILD_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/build
)

set(
    ARTIFACTS_DIR_CPP
    ${BUILD_DIR}/artifacts/cpp
)

add_definitions(-fPIC)
# Workaround to use boost-test from conda environment.
# @see https://github.com/conda-forge/boost-cpp-feedstock/issues/48
add_definitions(-DBoost_NO_BOOST_CMAKE=ON)

add_subdirectory(src/bau/cpp)

file(MAKE_DIRECTORY ${ARTIFACTS_DIR_CPP})

add_executable(test_boost src/bau/cpp/_tests/test_scalar.cpp)
target_link_libraries(test_boost PRIVATE bau)

add_custom_command(
    TARGET test_boost
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:test_boost> ${ARTIFACTS_DIR_CPP}
)
