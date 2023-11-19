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

    template <typename T, typename U> static constexpr bool is_the_same_base()
    {
        if constexpr (std::is_base_of_v<MassBaseUnit, T> && std::is_base_of_v<MassBaseUnit, U>)
            return true;
        else if constexpr (std::is_base_of_v<LengthBaseUnit, T> && std::is_base_of_v<LengthBaseUnit, U>)
            return true;
        else
            return false;
    }

    template <typename T, typename U, typename Op>
    requires std::is_class_v<T> && std::is_class_v<U>
    static constexpr T calculate_operator(const T &lhs, const U &rhs, Op op)
    {
        static_assert(is_the_same_base<T, U>());
        return T{lhs.convert_from_si(op(lhs.value_si(), rhs.value_si()))};
    }

    template <typename T, typename U, typename Op>
    requires std::is_arithmetic_v<U> && std::is_class_v<T>
    static constexpr T calculate_operator(const T &other, U value, Op op)
    {
        return T{other.convert_from_si(op(other.value_si(), value))};
    }

    template <typename T, typename Op> static constexpr T calculate_operator(const T &other, Op op)
    {
        return T{other.convert_from_si(op(other.value_si()))};
    }

  protected:
    template <typename T, typename U>
    static constexpr bool is_approx_equal(const T &lhs, const U &rhs, double tol = 1e-6)
    {
        static_assert(is_the_same_base<T, U>());
        return std::fabs(lhs.value_si() - rhs.value_si()) < tol;
    }
};

} // namespace bau

#endif // COMMONBASEUNIT_HPP
