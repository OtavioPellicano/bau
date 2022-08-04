add_library(
    bau

    src/Dummy.cpp
    include/bau/Dummy.hpp
)

target_include_directories(bau PUBLIC
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
