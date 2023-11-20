#include "bau/LengthBaseUnit.hpp"

namespace bau
{

Meter::Meter(double value)
    : LengthBaseUnit(value, 1.0, Unit::m, "m", "Meter")
{
}

} // namespace bau
