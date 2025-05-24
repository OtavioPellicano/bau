add_library(
    bau

    include/bau/Scalar.hpp

    include/bau/traits/PowerTraits.hpp
    include/bau/traits/CommonTraits.hpp
    include/bau/traits/AngleTraits.hpp
    include/bau/traits/LengthTraits.hpp
    include/bau/traits/TemperatureTraits.hpp
    include/bau/traits/WeightTraits.hpp
    include/bau/traits/MeasurementTraits.hpp

)

set_target_properties(bau PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(bau PUBLIC
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
