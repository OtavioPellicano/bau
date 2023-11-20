#include "bau/CommonBaseUnit.hpp"

namespace bau
{

CommonBaseUnit::CommonBaseUnit(double value, double conversion_factor, Unit unit)
    : BaseUnit(value, conversion_factor, unit)
{
}

} // namespace bau
