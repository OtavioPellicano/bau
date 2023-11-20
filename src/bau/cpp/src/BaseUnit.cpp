#include "bau/BaseUnit.hpp"

namespace bau
{

BaseUnit::BaseUnit(
    double value, double conversion_factor, Unit unit, const std::string &unit_str, const std::string &unit_str_full)
    : _conversion_factor(conversion_factor)
    , _unit(unit)
    , _unit_str(unit_str)
    , _unit_str_full(unit_str_full)
{
    this->set_value(value);
}

void BaseUnit::set_value(double value)
{
    _value_si = this->convert_to_si(value);
}

double BaseUnit::value() const
{
    return this->convert_from_si(_value_si);
}

double BaseUnit::value_si() const
{
    return _value_si;
}

double BaseUnit::convert_from_si(double value_si) const
{
    return value_si / _conversion_factor;
}

double BaseUnit::convert_to_si(double value) const
{
    return value * _conversion_factor;
}

Unit BaseUnit::unit() const
{
    return _unit;
}

std::string BaseUnit::unit_str() const
{
    return _unit_str;
}

std::string BaseUnit::unit_str_full() const
{
    return _unit_str_full;
}

} // namespace bau
