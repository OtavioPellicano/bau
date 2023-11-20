#include "bau/CommonBaseUnit.hpp"

namespace bau
{

CommonBaseUnit::CommonBaseUnit(
    double value, double conversion_factor, Unit unit, const std::string &unit_str, const std::string &unit_str_full)
    : BaseUnit(value, conversion_factor, unit, unit_str, unit_str_full)
{
}

} // namespace bau
