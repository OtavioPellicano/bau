#ifndef COMMONTRAITS_HPP
#define COMMONTRAITS_HPP

#include <concepts>

#include "PowerTraits.hpp"

namespace bau::unit {

template <typename T>
concept UnitTypeT = requires {
    T::name; // The unit type name, e.g. "length", "temperature"
};

struct Length {
    static constexpr const char* name = "length";
};
struct Temperature {
    static constexpr const char* name = "temperature";
};
struct Angle {
    static constexpr const char* name = "angle";
};
struct Weight {
    static constexpr const char* name = "weight";
};

template <template <typename> typename T, typename PowerTrait>
concept UnitTraitTHelper = requires {
    typename T<PowerTrait>::unit_type; // @see UnitTypeT concept
    typename T<PowerTrait>::type; // Refers to UnitTrait specialization, e.g. Meters<PowerTrait>
    typename T<PowerTrait>::value_type; // @see PowerTraitT concept

    {
        T<PowerTrait>::convert_to_si(std::declval<double>())
    } -> std::same_as<double>;
    {
        T<PowerTrait>::convert_from_si(std::declval<double>())
    } -> std::same_as<double>;

    // Trait specialization parameters
    T<PowerTrait>::name; // The UnitTrait name, e.g. "meters"
    T<PowerTrait>::symbol; // The UnitTrait symbol, e.g. "m"

    {
        T<PowerTrait>::formula_to_si(std::declval<double>())
    } -> std::same_as<double>; // conversion formula  to SI (universal system of units)
    {
        T<PowerTrait>::formula_from_si(std::declval<double>())
    } -> std::same_as<double>; // conversion formula from SI (universal system of units)
};

template <UnitTypeT UnitType, template <typename> typename UnitTrait, power::PowerTraitT PowerTrait>
struct CommontTraits {
    using unit_type = UnitType;
    using type = UnitTrait<PowerTrait>;
    using value_type = PowerTrait;

    static constexpr double convert_to_si(double value)
    {
        return UnitTrait<PowerTrait>::formula_to_si(value) * PowerTrait::value;
    }

    static constexpr double convert_from_si(double value_si)
    {
        return UnitTrait<PowerTrait>::formula_from_si(value_si) / PowerTrait::value;
    }
};

}

#endif // COMMONTRAITS_HPP
