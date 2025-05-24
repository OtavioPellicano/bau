#ifndef TEMPERATURETRAITS_HPP
#define TEMPERATURETRAITS_HPP

#include "CommonTraits.hpp"

namespace bau::unit::temperature {

template <power::PowerTraitT PowerTrait = power::none>
struct Kelvin : CommontTraits<Temperature, Kelvin, PowerTrait> {
    static constexpr const char* name = "kelvin";
    static constexpr const char* symbol = "K";

    static constexpr double formula_to_si(double value)
    {
        return value;
    }

    static constexpr double formula_from_si(double value_si)
    {
        return value_si;
    }
};

template <power::PowerTraitT PowerTrait = power::none>
struct Fahrenheit : CommontTraits<Temperature, Fahrenheit, PowerTrait> {
    static constexpr const char* name = "fahrenheit";
    static constexpr const char* symbol = "F";

    static constexpr double formula_to_si(double value)
    {
        return (value - 32) / 1.8 + 273.15;
    }

    static constexpr double formula_from_si(double value_si)
    {
        return ((value_si - 273.15) * 1.8) + 32;
    }
};

template <power::PowerTraitT PowerTrait = power::none>
struct Celsius : CommontTraits<Temperature, Celsius, PowerTrait> {
    static constexpr const char* name = "celsius";
    static constexpr const char* symbol = "C";

    static constexpr double formula_to_si(double value)
    {
        return value + 273.15;
    }

    static constexpr double formula_from_si(double value_si)
    {
        return value_si - 273.15;
    }
};

}
#endif // TEMPERATURETRAITS_HPP
