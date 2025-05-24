#ifndef ANGLETRAITS_HPP
#define ANGLETRAITS_HPP

#include "CommonTraits.hpp"

#include <cmath>

namespace bau::unit::angle {

template <power::PowerTraitT PowerTrait = power::none>
    requires std::same_as<PowerTrait, power::none>
struct Radians : CommontTraits<Angle, Radians, power::none> {
    static constexpr const char* name = "radians";
    static constexpr const char* symbol = "rad";

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
    requires std::same_as<PowerTrait, power::none>
struct Degrees : CommontTraits<Angle, Degrees, power::none> {
    static constexpr const char* name = "degrees";
    static constexpr const char* symbol = "deg";

    static constexpr double formula_to_si(double value)
    {
        return value * factor_to_si;
    }

    static constexpr double formula_from_si(double value_si)
    {
        return value_si / factor_to_si;
    }

private:
    static constexpr double factor_to_si = M_PI / 180.;
};

template <power::PowerTraitT PowerTrait = power::none>
    requires std::same_as<PowerTrait, power::none>
struct Gradians : CommontTraits<Angle, Gradians, power::none> {
    static constexpr const char* name = "gradians";
    static constexpr const char* symbol = "g";

    static constexpr double formula_to_si(double value)
    {
        return value * factor_to_si;
    }

    static constexpr double formula_from_si(double value_si)
    {
        return value_si / factor_to_si;
    }

private:
    static constexpr double factor_to_si = M_PI / 200.;
};

}

#endif // ANGLETRAITS_HPP
