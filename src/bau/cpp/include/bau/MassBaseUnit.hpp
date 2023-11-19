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
    using CommonBaseUnit::is_approx_equal;
};

class Kilogram : public MassBaseUnit
{
  public:
    Kilogram(double value);
    std::string unit_str() const final;
};

class Pound : public MassBaseUnit
{
  public:
    Pound(double value);
    std::string unit_str() const final;
};

} // namespace bau

#endif // MASSBASEUNIT_HPP
