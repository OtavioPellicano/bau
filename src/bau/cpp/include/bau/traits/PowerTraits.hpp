#ifndef POWERTRAITS_H
#define POWERTRAITS_H

namespace bau::power {

template <typename T>
concept PowerTraitT = requires {
    T::value; // power factor value, e.g. 1e3 for "kilo"
    T::name; // power factor name, e.g. "kilo"
    T::symbol; // power factor symbol, e.g. "k", for "kilo"
};

// unit factor
struct none {
    static constexpr double value = 1.;
    static constexpr const char* name = "none";
    static constexpr const char* symbol = ".";
};

struct kilo {
    static constexpr double value = 1e3;
    static constexpr const char* name = "kilo";
    static constexpr const char* symbol = "k";
};

struct hecto {
    static constexpr double value = 1e2;
    static constexpr const char* name = "hecto";
    static constexpr const char* symbol = "h";
};

struct deca {
    static constexpr double value = 1e1;
    static constexpr const char* name = "deca";
    static constexpr const char* symbol = "da";
};

struct deci {
    static constexpr double value = 1e-1;
    static constexpr const char* name = "deci";
    static constexpr const char* symbol = "d";
};

struct centi {
    static constexpr double value = 1e-2;
    static constexpr const char* name = "centi";
    static constexpr const char* symbol = "c";
};

struct mili {
    static constexpr double value = 1e-3;
    static constexpr const char* name = "mili";
    static constexpr const char* symbol = "m";
};

}

#endif // POWERTRAITS_H
