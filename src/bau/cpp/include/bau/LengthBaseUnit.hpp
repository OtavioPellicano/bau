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
};

class Meter : public LengthBaseUnit
{
  public:
    Meter(double value);
    std::string unit_str() const final;
    std::string unit_str_full() const final;
};

} // namespace bau

#endif // LENGTHBASEUNIT_HPP
