#ifndef UNIT_HPP
#define UNIT_HPP

#include "bau/LengthBaseUnit.hpp"
#include "bau/MassBaseUnit.hpp"

namespace bau
{

template <typename T, typename U> constexpr T operator+(const T &lhs, const U &rhs)
{
    return CommonBaseUnit::calculate_operator(lhs, rhs, std::plus<double>());
}

template <typename T, typename U> constexpr T operator-(const T &lhs, const U &rhs)
{
    return CommonBaseUnit::calculate_operator(lhs, rhs, std::minus<double>());
}

template <typename T> constexpr T operator-(const T &other)
{
    return CommonBaseUnit::calculate_operator(other, std::negate<double>());
}

template <typename T, typename U>
requires std::is_class_v<T> && std::is_class_v<U>
constexpr T operator*(const T &lhs, const U &rhs)
{
    // TODO: I need to enhance this to make it work for other bases beside bau::MassBaseUnit
    return CommonBaseUnit::calculate_operator(lhs, rhs, std::multiplies<double>());
}

template <typename T, typename U>
requires std::is_arithmetic_v<U>
constexpr T operator*(const T &lhs, U value)
{
    return CommonBaseUnit::calculate_operator(lhs, value, std::multiplies<double>());
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
    return CommonBaseUnit::calculate_operator(lhs, rhs, std::divides<double>());
}

template <typename T, typename U>
requires std::is_arithmetic_v<U>
constexpr T operator/(const T &lhs, U value)
{
    return CommonBaseUnit::calculate_operator(lhs, value, std::divides<double>());
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
