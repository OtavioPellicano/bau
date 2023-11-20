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
    BaseUnit(double value, double conversion_factor, Unit unit);

    void set_value(double value) final;

    double value() const final;
    double value_si() const final;

    double convert_from_si(double value_si) const final;
    double convert_to_si(double value) const final;

    Unit unit() const final;

  protected:
    const double _conversion_factor;

  private:
    double _value_si;
    const Unit _unit;
};
} // namespace bau

#endif // BASEUNIT_HPP
