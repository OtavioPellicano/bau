#include "bau/MassBaseUnit.hpp"

namespace bau
{

Kilogram::Kilogram(double value)
    : MassBaseUnit(value, 1.0, Unit::kg)
{
}

std::string Kilogram::unit_str() const
{
    return "kg";
}

std::string Kilogram::unit_str_full() const
{
    return "Kilogram";
}

Pound::Pound(double value)
    : MassBaseUnit(value, 0.45359237, Unit::lb)
{
}

std::string Pound::unit_str() const
{
    return "lb";
}

std::string Pound::unit_str_full() const
{
    return "Pound";
}

} // namespace bau
