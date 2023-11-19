#ifndef LENGTHBASEUNIT_HPP
#define LENGTHBASEUNIT_HPP

#include "bau/CommonBaseUnit.hpp"

namespace bau
{

class LengthBaseUnit : public CommonBaseUnit
{
  public:
    virtual ~LengthBaseUnit() = default;
    using CommonBaseUnit::CommonBaseUnit;
    using CommonBaseUnit::is_approx_equal;
};

class Meter : public LengthBaseUnit
{
  public:
    Meter(double value);
    std::string unit_str() const final;
};

} // namespace bau

#endif // LENGTHBASEUNIT_HPP
