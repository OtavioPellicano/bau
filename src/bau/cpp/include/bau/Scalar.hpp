#ifndef SCALAR_HPP
#define SCALAR_HPP

#include "traits/MeasurementTraits.hpp"

#include <concepts>
#include <format>
#include <ostream>

namespace bau {
template <template <typename> typename UnitTrait, power::PowerTraitT PowerTrait = power::none>
    requires unit::UnitTraitTHelper<UnitTrait, PowerTrait>
class Scalar {
public:
    using type = Scalar<UnitTrait, PowerTrait>;
    using value_type = UnitTrait<PowerTrait>::type;
    using unit_type = typename value_type::unit_type;

    constexpr Scalar(double value) noexcept
        : _value_si(value_type::convert_to_si(value))
    {
    }

    template <template <typename> typename UnitTraitU, power::PowerTraitT PowerTraitU = power::none>
    constexpr double value() const
    {
        static_assert(std::same_as<unit_type, typename UnitTraitU<PowerTraitU>::unit_type>, "It is not possible to convert values from different unit_type");
        return UnitTraitU<PowerTraitU>::convert_from_si(_value_si);
    }

    constexpr double value() const
    {
        return UnitTrait<PowerTrait>::convert_from_si(_value_si);
    }

    constexpr double value_si() const
    {
        return _value_si;
    }

    consteval const char* name_unit() const
    {
        return value_type::name;
    }

    consteval const char* symbol_unit() const
    {
        return value_type::symbol;
    }

    consteval const char* name_unit_type() const
    {
        return value_type::unit_type::name;
    }

    consteval const char* symbol_power_factor() const
    {
        return value_type::value_type::symbol;
    }

    consteval const char* name_power_factor() const
    {
        return value_type::value_type::name;
    }

    consteval double value_power_factor() const
    {
        return value_type::value_type::value;
    }

private:
    const double _value_si {};
};

template <typename ScalarT1, typename ScalarT2>
constexpr ScalarT1 operator+(const ScalarT1& scalar_1, const ScalarT2& scalar_2)
{
    static_assert(std::same_as<typename ScalarT1::unit_type, typename ScalarT2::unit_type>, "This operation should be done using the same unit_type.");
    return ScalarT1(ScalarT1::value_type::convert_from_si(scalar_1.value_si() + scalar_2.value_si()));
}

template <typename ScalarT1, typename ScalarT2>
constexpr ScalarT1 operator-(const ScalarT1& scalar_1, const ScalarT2& scalar_2)
{
    static_assert(std::same_as<typename ScalarT1::unit_type, typename ScalarT2::unit_type>, "This operation should be done using the same unit_type.");
    return ScalarT1(ScalarT1::value_type::convert_from_si(scalar_1.value_si() - scalar_2.value_si()));
}

// template <template <typename> typename UnitTrait, power::PowerTraitT PowerTrait>
// constexpr std::ostream& operator<<(std::ostream& os, const Scalar<UnitTrait, PowerTrait> scalar)
// {
//     os << std::format("{} [{} {}, {}]", scalar.value(), scalar.symbol_power_factor(), scalar.symbol_unit(), scalar.name_unit_type());
//     return os;
// }

}

#endif // SCALAR_HPP
