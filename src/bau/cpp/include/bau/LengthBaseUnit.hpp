#ifndef LENGTHBASEUNIT_HPP
#define LENGTHBASEUNIT_HPP

#include "bau/BaseUnit.hpp"

namespace bau
{

class LengthBaseUnit : public BaseUnit
{
  public:
    virtual ~LengthBaseUnit() = default;
    using BaseUnit::BaseUnit;
};

class Meter : public LengthBaseUnit
{
  public:
    Meter(double value);
};

} // namespace bau

#endif // LENGTHBASEUNIT_HPP
