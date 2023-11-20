#define BOOST_TEST_MODULE test_mass

#include <boost/test/included/unit_test.hpp>

#include <bau/Unit.hpp>

BOOST_AUTO_TEST_CASE(test_unit_string)
{
    auto p = bau::Pound(1);
    auto k = bau::Kilogram(0.45359237);
    auto m = bau::Meter(2);

    BOOST_CHECK(p.unit() == bau::Unit::lb);
    BOOST_CHECK(k.unit() == bau::Unit::kg);
    BOOST_CHECK(m.unit() == bau::Unit::m);

    BOOST_CHECK(p.unit_str() == "lb");
    BOOST_CHECK(k.unit_str() == "kg");
    BOOST_CHECK(m.unit_str() == "m");

    BOOST_CHECK(p.unit_str_full() == "Pound");
    BOOST_CHECK(k.unit_str_full() == "Kilogram");
    BOOST_CHECK(m.unit_str_full() == "Meter");
}

BOOST_AUTO_TEST_CASE(test_set_get_value)
{
    auto p = bau::Pound(1);
    auto k = bau::Kilogram(0.45359237);

    p.set_value(2);
    k.set_value(53.1);

    BOOST_CHECK(p.value() == p.convert_from_si(p.value_si()));
    BOOST_CHECK(k.value() == k.convert_from_si(k.value_si()));
    BOOST_CHECK(k.value_si() == k.convert_from_si(k.value()));
    BOOST_CHECK(p.value_si() == p.convert_to_si(p.value()));
}

BOOST_AUTO_TEST_CASE(test_arithmetic_operators)
{
    auto p = bau::Pound(1);
    auto k = bau::Kilogram(0.45359237);

    // is_approx_equal_check
    BOOST_CHECK(bau::common_functions::is_approx_equal(p, k));
    BOOST_CHECK(bau::common_functions::is_approx_equal(k, p));
    BOOST_CHECK(bau::common_functions::is_approx_equal(k, k));

    // negate_check
    BOOST_CHECK(bau::common_functions::is_approx_equal(p, -(-p)));
    BOOST_CHECK(bau::common_functions::is_approx_equal(p, -(-k)));
    BOOST_CHECK(bau::common_functions::is_approx_equal(-p, -k));

    // plus_check
    BOOST_CHECK(bau::common_functions::is_approx_equal(p + k, k + p));

    // minus_check
    BOOST_CHECK(bau::common_functions::is_approx_equal(p - k, -(k - p)));

    // multiplies_check
    BOOST_CHECK(bau::common_functions::is_approx_equal(p * k, k * p));
    BOOST_CHECK(bau::common_functions::is_approx_equal(5 * k, p * 5.));

    // divides_check
    BOOST_CHECK(bau::common_functions::is_approx_equal(2 * p / k, 1 / (p / k * 2)));
}
