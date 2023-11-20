#ifndef COMMONBASEUNIT_HPP
#define COMMONBASEUNIT_HPP

#include "bau/BaseUnit.hpp"

#include <cmath>

namespace bau
{
class MassBaseUnit;
class LengthBaseUnit;

class CommonBaseUnit : public BaseUnit
{
  public:
    virtual ~CommonBaseUnit() = default;
    CommonBaseUnit(double value, double conversion_factor);
};

} // namespace bau

#endif // COMMONBASEUNIT_HPP
