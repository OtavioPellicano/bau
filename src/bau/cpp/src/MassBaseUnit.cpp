#include "bau/MassBaseUnit.hpp"

namespace bau
{

Kilogram::Kilogram(double value)
    : MassBaseUnit(value, 1.0, Unit::kg, "kg", "Kilogram")
{
}

Pound::Pound(double value)
    : MassBaseUnit(value, 0.45359237, Unit::lb, "lb", "Pound")
{
}

} // namespace bau
