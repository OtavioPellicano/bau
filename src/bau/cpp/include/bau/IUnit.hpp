#ifndef IUNIT_HPP
#define IUNIT_HPP

#include <string>

// It was used the conversion factors available at http://conversion.org/

namespace bau
{
class IUnit
{
  public:
    ~IUnit() = default;

    virtual void set_value(double value) = 0;

    virtual double value() const = 0;
    virtual double value_si() const = 0;

    virtual double convert_from_si(double value_si) const = 0;
    virtual double convert_to_si(double value) const = 0;

    virtual std::string unit_str() const = 0;
};
} // namespace bau

#endif // IUNIT_HPP
