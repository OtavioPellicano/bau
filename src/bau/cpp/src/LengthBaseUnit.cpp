#include "bau/LengthBaseUnit.hpp"

namespace bau
{

Meter::Meter(double value)
    : LengthBaseUnit(value, 1.0)
{
}

std::string Meter::unit_str() const
{
    return "m";
}

} // namespace bau
