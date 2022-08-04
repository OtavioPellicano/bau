#define BOOST_TEST_MODULE test_dummy

#include <boost/test/included/unit_test.hpp>

#include <bau/Dummy.hpp>

BOOST_AUTO_TEST_CASE(test_dummy)
{
    auto dummy = Dummy();

    BOOST_TEST(dummy.value() == 0);
}
