#ifndef LENGTHTRAITS_HPP
#define LENGTHTRAITS_HPP

#include "CommonTraits.hpp"

namespace bau::unit::length {

template <power::PowerTraitT PowerTrait = power::none>
struct Meters : CommontTraits<Length, Meters, PowerTrait> {
    static constexpr const char* name = "meters";
    static constexpr const char* symbol = "m";

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
struct Miles : CommontTraits<Length, Miles, PowerTrait> {
    static constexpr const char* name = "miles";
    static constexpr const char* symbol = "mi";

    static constexpr double formula_to_si(double value)
    {
        return value * factor_to_si;
    }

    static constexpr double formula_from_si(double value_si)
    {
        return value_si / factor_to_si;
    }

private:
    static constexpr double factor_to_si = 1609.34449789;
};

template <power::PowerTraitT PowerTrait = power::none>
struct Yards : CommontTraits<Length, Yards, PowerTrait> {
    static constexpr const char* name = "yards";
    static constexpr const char* symbol = "yd";

    static constexpr double formula_to_si(double value)
    {
        return value * factor_to_si;
    }

    static constexpr double formula_from_si(double value_si)
    {
        return value_si / factor_to_si;
    }

private:
    static constexpr double factor_to_si = 0.91440276;
};

}
#endif // LENGTHTRAITS_HPP
