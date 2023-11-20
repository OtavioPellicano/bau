#ifndef UNIT_HPP
#define UNIT_HPP

#include "bau/LengthBaseUnit.hpp"
#include "bau/MassBaseUnit.hpp"

namespace bau
{

namespace common_functions
{
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

template <typename T, typename U> static constexpr bool is_approx_equal(const T &lhs, const U &rhs, double tol = 1e-6)
{
    static_assert(is_the_same_base<T, U>());
    return std::fabs(lhs.value_si() - rhs.value_si()) < tol;
}
} // namespace common_functions

template <typename T, typename U> constexpr T operator+(const T &lhs, const U &rhs)
{
    return common_functions::calculate_operator(lhs, rhs, std::plus<double>());
}

template <typename T, typename U> constexpr T operator-(const T &lhs, const U &rhs)
{
    return common_functions::calculate_operator(lhs, rhs, std::minus<double>());
}

template <typename T> constexpr T operator-(const T &other)
{
    return common_functions::calculate_operator(other, std::negate<double>());
}

template <typename T, typename U>
requires std::is_class_v<T> && std::is_class_v<U>
constexpr T operator*(const T &lhs, const U &rhs)
{
    // TODO: I need to enhance this to make it work for other bases beside bau::MassBaseUnit
    return common_functions::calculate_operator(lhs, rhs, std::multiplies<double>());
}

template <typename T, typename U>
requires std::is_arithmetic_v<U>
constexpr T operator*(const T &lhs, U value)
{
    return common_functions::calculate_operator(lhs, value, std::multiplies<double>());
}

template <typename T, typename U>
requires std::is_arithmetic_v<U>
constexpr T operator*(U value, const T &rhs)
{
    return rhs * value;
}

template <typename T, typename U>
requires std::is_class_v<T> && std::is_class_v<U>
constexpr T operator/(const T &lhs, const U &rhs)
{
    // TODO: I need to enhance this to make it work for other bases beside bau::MassBaseUnit
    return common_functions::calculate_operator(lhs, rhs, std::divides<double>());
}

template <typename T, typename U>
requires std::is_arithmetic_v<U>
constexpr T operator/(const T &lhs, U value)
{
    return common_functions::calculate_operator(lhs, value, std::divides<double>());
}

template <typename T, typename U>
requires std::is_arithmetic_v<U>
constexpr T operator/(U value, const T &rhs)
{
    return rhs / value;
}

// TODO: I need to find a better way to call this function for all my bau::CommonBaseUnit
template <typename T>
requires std::is_base_of_v<bau::MassBaseUnit, T> || std::is_base_of_v<bau::LengthBaseUnit, T>
constexpr std::ostream &operator<<(std::ostream &os, const T &other)
{
    os << std::to_string(other.value()) << " [" << other.unit_str() << "]";
    return os;
}

} // namespace bau

#endif // UNIT_HPP
