#ifndef MASSBASEUNIT_HPP
#define MASSBASEUNIT_HPP

#include "bau/BaseUnit.hpp"

namespace bau
{

class MassBaseUnit : public BaseUnit
{
  public:
    virtual ~MassBaseUnit() = default;
    using BaseUnit::BaseUnit;
};

class Kilogram : public MassBaseUnit
{
  public:
    Kilogram(double value);
};

class Pound : public MassBaseUnit
{
  public:
    Pound(double value);
};

} // namespace bau

#endif // MASSBASEUNIT_HPP
