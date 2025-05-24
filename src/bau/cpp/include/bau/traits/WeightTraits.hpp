#ifndef WEIGHTTRAITS_HPP
#define WEIGHTTRAITS_HPP

#include "CommonTraits.hpp"

namespace bau::unit::weight {

template <power::PowerTraitT PowerTrait = power::none>
struct Grams : CommontTraits<Weight, Grams, PowerTrait> {
    static constexpr const char* name = "grams";
    static constexpr const char* symbol = "g";

    static constexpr double formula_to_si(double value)
    {
        return value * power::mili::value;
    }

    static constexpr double formula_from_si(double value_si)
    {
        return value_si * power::kilo::value;
    }
};

template <power::PowerTraitT PowerTrait = power::none>
struct Pounds : CommontTraits<Weight, Pounds, PowerTrait> {
    static constexpr const char* name = "pounds";
    static constexpr const char* symbol = "lb";

    static constexpr double formula_to_si(double value)
    {
        return value * factor_to_si;
    }

    static constexpr double formula_from_si(double value_si)
    {
        return value_si / factor_to_si;
    }

private:
    static constexpr double factor_to_si = 0.45359291;
};

}

#endif // WEIGHTTRAITS_HPP
