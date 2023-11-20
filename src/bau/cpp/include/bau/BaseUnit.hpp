#ifndef BASEUNIT_HPP
#define BASEUNIT_HPP

#include "bau/IUnit.hpp"

namespace bau
{

class BaseUnit : public IUnit
{
  public:
    using IUnit::convert_from_si;
    using IUnit::convert_to_si;

    virtual ~BaseUnit() = default;
    BaseUnit(
        double value, double conversion_factor, Unit unit, const std::string &unit_str,
        const std::string &unit_str_full);

    void set_value(double value) final;

    double value() const final;
    double value_si() const final;

    double convert_from_si(double value_si) const final;
    double convert_to_si(double value) const final;

    Unit unit() const final;
    std::string unit_str() const final;
    std::string unit_str_full() const final;

  protected:
    const double _conversion_factor;

  private:
    double _value_si;
    const Unit _unit;
    const std::string _unit_str;
    const std::string _unit_str_full;
};
} // namespace bau

#endif // BASEUNIT_HPP
