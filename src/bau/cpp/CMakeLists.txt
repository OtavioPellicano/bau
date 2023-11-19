add_library(
    bau

    src/BaseUnit.cpp
    src/CommonBaseUnit.cpp
    src/MassBaseUnit.cpp
    src/LengthBaseUnit.cpp

)

target_include_directories(bau PUBLIC
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
