#define BOOST_TEST_MODULE test_mass

#include <boost/test/included/unit_test.hpp>

namespace utf = boost::unit_test;
double tol = 1e-4;

#include <bau/Scalar.hpp>

BOOST_AUTO_TEST_CASE(test_power_traits)
{
    BOOST_CHECK(bau::power::kilo::value == 1e3);
    BOOST_CHECK(bau::power::kilo::name == "kilo");
    BOOST_CHECK(bau::power::kilo::symbol == "k");

    BOOST_CHECK(bau::power::hecto::value == 1e2);
    BOOST_CHECK(bau::power::hecto::name == "hecto");
    BOOST_CHECK(bau::power::hecto::symbol == "h");

    BOOST_CHECK(bau::power::deca::value == 1e1);
    BOOST_CHECK(bau::power::deca::name == "deca");
    BOOST_CHECK(bau::power::deca::symbol == "da");

    BOOST_CHECK(bau::power::none::value == 1.);
    BOOST_CHECK(bau::power::none::name == "none");
    BOOST_CHECK(bau::power::none::symbol == ".");

    BOOST_CHECK(bau::power::deci::value == 1e-1);
    BOOST_CHECK(bau::power::deci::name == "deci");
    BOOST_CHECK(bau::power::deci::symbol == "d");

    BOOST_CHECK(bau::power::centi::value == 1e-2);
    BOOST_CHECK(bau::power::centi::name == "centi");
    BOOST_CHECK(bau::power::centi::symbol == "c");

    BOOST_CHECK(bau::power::mili::value == 1e-3);
    BOOST_CHECK(bau::power::mili::name == "mili");
    BOOST_CHECK(bau::power::mili::symbol == "m");
}

BOOST_AUTO_TEST_CASE(test_name_unit_type)
{
    BOOST_CHECK(bau::unit::Angle::name == "angle");
    BOOST_CHECK(bau::unit::Length::name == "length");
    BOOST_CHECK(bau::unit::Temperature::name == "temperature");
    BOOST_CHECK(bau::unit::Weight::name == "weight");
}

BOOST_AUTO_TEST_CASE(test_angle_traits, *utf::tolerance(tol))
{
    BOOST_CHECK(bau::unit::angle::Radians<bau::power::none>::name == "radians");
    BOOST_CHECK(bau::unit::angle::Radians<bau::power::none>::symbol == "rad");
    BOOST_TEST(bau::unit::angle::Radians<bau::power::none>::formula_to_si(1.) == 1.);
    BOOST_TEST(bau::unit::angle::Radians<bau::power::none>::formula_from_si(1.) == 1.);

    BOOST_CHECK(bau::unit::angle::Degrees<bau::power::none>::name == "degrees");
    BOOST_CHECK(bau::unit::angle::Degrees<bau::power::none>::symbol == "deg");
    BOOST_TEST(bau::unit::angle::Degrees<bau::power::none>::formula_to_si(1.) == M_PI / 180.);
    BOOST_TEST(bau::unit::angle::Degrees<bau::power::none>::formula_from_si(M_PI / 180.) == 1.);

    BOOST_CHECK(bau::unit::angle::Gradians<bau::power::none>::name == "gradians");
    BOOST_CHECK(bau::unit::angle::Gradians<bau::power::none>::symbol == "g");
    BOOST_TEST(bau::unit::angle::Gradians<bau::power::none>::formula_to_si(1.) == M_PI / 200.);
    BOOST_TEST(bau::unit::angle::Gradians<bau::power::none>::formula_from_si(M_PI / 200.) == 1.);
}

BOOST_AUTO_TEST_CASE(test_length_traits, *utf::tolerance(tol))
{
    BOOST_CHECK(bau::unit::length::Meters<bau::power::none>::name == "meters");
    BOOST_CHECK(bau::unit::length::Meters<bau::power::none>::symbol == "m");
    BOOST_TEST(bau::unit::length::Meters<bau::power::none>::formula_to_si(1.) == 1.);
    BOOST_TEST(bau::unit::length::Meters<bau::power::none>::formula_from_si(1.) == 1.);

    BOOST_CHECK(bau::unit::length::Miles<bau::power::none>::name == "miles");
    BOOST_CHECK(bau::unit::length::Miles<bau::power::none>::symbol == "mi");
    BOOST_TEST(bau::unit::length::Miles<bau::power::none>::formula_to_si(1.) == 1609.34449789);
    BOOST_TEST(bau::unit::length::Miles<bau::power::none>::formula_from_si(1609.34449789) == 1.);

    BOOST_CHECK(bau::unit::length::Yards<bau::power::none>::name == "yards");
    BOOST_CHECK(bau::unit::length::Yards<bau::power::none>::symbol == "yd");
    BOOST_TEST(bau::unit::length::Yards<bau::power::none>::formula_to_si(1.) == 0.91440276);
    BOOST_TEST(bau::unit::length::Yards<bau::power::none>::formula_from_si(0.91440276) == 1.);
}

BOOST_AUTO_TEST_CASE(test_temperature_traits, *utf::tolerance(tol))
{
    BOOST_CHECK(bau::unit::temperature::Kelvin<bau::power::none>::name == "kelvin");
    BOOST_CHECK(bau::unit::temperature::Kelvin<bau::power::none>::symbol == "K");
    BOOST_TEST(bau::unit::temperature::Kelvin<bau::power::none>::formula_to_si(1.) == 1.);
    BOOST_TEST(bau::unit::temperature::Kelvin<bau::power::none>::formula_from_si(1.) == 1.);

    BOOST_CHECK(bau::unit::temperature::Fahrenheit<bau::power::none>::name == "fahrenheit");
    BOOST_CHECK(bau::unit::temperature::Fahrenheit<bau::power::none>::symbol == "F");
    BOOST_TEST(bau::unit::temperature::Fahrenheit<bau::power::none>::formula_to_si(1.) == 255.9277778);
    BOOST_TEST(bau::unit::temperature::Fahrenheit<bau::power::none>::formula_from_si(255.9277778) == 1.);

    BOOST_CHECK(bau::unit::temperature::Celsius<bau::power::none>::name == "celsius");
    BOOST_CHECK(bau::unit::temperature::Celsius<bau::power::none>::symbol == "C");
    BOOST_TEST(bau::unit::temperature::Celsius<bau::power::none>::formula_to_si(1.) == 274.15);
    BOOST_TEST(bau::unit::temperature::Celsius<bau::power::none>::formula_from_si(274.15) == 1.);
}

BOOST_AUTO_TEST_CASE(test_weight_traits, *utf::tolerance(tol))
{
    BOOST_CHECK(bau::unit::weight::Grams<bau::power::none>::name == "grams");
    BOOST_CHECK(bau::unit::weight::Grams<bau::power::none>::symbol == "g");
    BOOST_TEST(bau::unit::weight::Grams<bau::power::none>::formula_to_si(1.) == bau::power::mili::value);
    BOOST_TEST(bau::unit::weight::Grams<bau::power::none>::formula_from_si(bau::power::mili::value) == 1.);

    BOOST_CHECK(bau::unit::weight::Pounds<bau::power::none>::name == "pounds");
    BOOST_CHECK(bau::unit::weight::Pounds<bau::power::none>::symbol == "lb");
    BOOST_TEST(bau::unit::weight::Pounds<bau::power::none>::formula_to_si(1.) == 0.45359291);
    BOOST_TEST(bau::unit::weight::Pounds<bau::power::none>::formula_from_si(0.45359291) == 1.);
}

BOOST_AUTO_TEST_CASE(test_scalar, *utf::tolerance(tol))
{
    constexpr auto scalar_1 = bau::Scalar<bau::unit::length::Miles, bau::power::kilo>(1.);
    BOOST_TEST(scalar_1.value() == 1.);
    BOOST_TEST(scalar_1.value<bau::unit::length::Yards>() == 1760000.0);
    // BOOST_TEST(scalar_1.value<bau::unit::length::Yards, bau::power::kilo>() == 1760.0);  // For some reason it is not working in boost.test
    BOOST_TEST(scalar_1.value<bau::unit::length::Meters>() == scalar_1.value_si());
    BOOST_CHECK(scalar_1.name_unit() == bau::unit::length::Miles<>::name);
    BOOST_CHECK(scalar_1.symbol_unit() == bau::unit::length::Miles<>::symbol);
    BOOST_CHECK(scalar_1.name_unit_type() == bau::unit::Length::name);
    BOOST_CHECK(scalar_1.symbol_power_factor() == bau::power::kilo::symbol);
    BOOST_CHECK(scalar_1.name_power_factor() == bau::power::kilo::name);
    BOOST_CHECK(scalar_1.value_power_factor() == bau::power::kilo::value);

    auto scalar_2 = bau::Scalar<bau::unit::angle::Degrees>(1.);
    BOOST_TEST(scalar_2.value() == 1.);
    BOOST_TEST(scalar_2.value<bau::unit::angle::Gradians>() == 1.1111111);
    BOOST_TEST(scalar_2.value<bau::unit::angle::Radians>() == scalar_2.value_si());
    BOOST_CHECK(scalar_2.name_unit() == bau::unit::angle::Degrees<>::name);
    BOOST_CHECK(scalar_2.symbol_unit() == bau::unit::angle::Degrees<>::symbol);
    BOOST_CHECK(scalar_2.name_unit_type() == bau::unit::Angle::name);
    BOOST_CHECK(scalar_2.symbol_power_factor() == bau::power::none::symbol);
    BOOST_CHECK(scalar_2.name_power_factor() == bau::power::none::name);
    BOOST_CHECK(scalar_2.value_power_factor() == bau::power::none::value);

    constexpr auto scalar_3 = bau::Scalar<bau::unit::temperature::Fahrenheit>(1.);
    BOOST_TEST(scalar_3.value() == 1.);
    BOOST_TEST(scalar_3.value<bau::unit::temperature::Celsius>() == -17.222222);
    BOOST_TEST(scalar_3.value<bau::unit::temperature::Kelvin>() == scalar_3.value_si());
    BOOST_CHECK(scalar_3.name_unit() == bau::unit::temperature::Fahrenheit<>::name);
    BOOST_CHECK(scalar_3.symbol_unit() == bau::unit::temperature::Fahrenheit<>::symbol);
    BOOST_CHECK(scalar_3.name_unit_type() == bau::unit::Temperature::name);
    BOOST_CHECK(scalar_3.symbol_power_factor() == bau::power::none::symbol);
    BOOST_CHECK(scalar_3.name_power_factor() == bau::power::none::name);
    BOOST_CHECK(scalar_3.value_power_factor() == bau::power::none::value);

    constexpr auto scalar_4 = bau::Scalar<bau::unit::weight::Grams, bau::power::kilo>(1.);
    BOOST_TEST(scalar_4.value() == 1.);
    BOOST_TEST(scalar_4.value<bau::unit::weight::Pounds>() == 2.20462);
    // BOOST_TEST(scalar_4.value<bau::unit::weight::Grams, bau::power::kilo>() == scalar_4.value_si()); // For some reason it is not working in boost.test
    BOOST_CHECK(scalar_4.name_unit() == bau::unit::weight::Grams<>::name);
    BOOST_CHECK(scalar_4.symbol_unit() == bau::unit::weight::Grams<>::symbol);
    BOOST_CHECK(scalar_4.name_unit_type() == bau::unit::Weight::name);
    BOOST_CHECK(scalar_4.symbol_power_factor() == bau::power::kilo::symbol);
    BOOST_CHECK(scalar_4.name_power_factor() == bau::power::kilo::name);
    BOOST_CHECK(scalar_4.value_power_factor() == bau::power::kilo::value);
}

BOOST_AUTO_TEST_CASE(test_arithmetic_operators, *utf::tolerance(tol))
{
    constexpr auto k = bau::Scalar<bau::unit::weight::Grams, bau::power::kilo>(1);
    constexpr auto p = bau::Scalar<bau::unit::weight::Pounds>(.45359237);

    constexpr auto kg_res = k + p;
    constexpr auto pounds_res = p + k;

    BOOST_TEST(kg_res.value<bau::unit::weight::Pounds>() == pounds_res.value());

    constexpr auto kg_res_value = pounds_res.value<bau::unit::weight::Grams, bau::power::kilo>();
    BOOST_TEST(kg_res.value() == kg_res_value);

    constexpr auto kg_res_m = k - p;
    constexpr auto pounds_res_m = p - k;

    BOOST_TEST(kg_res_m.value<bau::unit::weight::Pounds>() == -pounds_res_m.value());

    constexpr auto kg_res_m_value = pounds_res_m.value<bau::unit::weight::Grams, bau::power::kilo>();
    BOOST_TEST(kg_res_m.value() == -kg_res_m_value);
}
