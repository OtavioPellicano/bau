#ifndef MASSBASEUNIT_HPP
#define MASSBASEUNIT_HPP

#include "bau/CommonBaseUnit.hpp"

namespace bau
{

class MassBaseUnit : public CommonBaseUnit
{
  public:
    virtual ~MassBaseUnit() = default;
    using CommonBaseUnit::CommonBaseUnit;
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
