#include <boost/test/unit_test.hpp>
#include <raw_io/Dummy.hpp>

using namespace raw_io;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    raw_io::DummyClass dummy;
    dummy.welcome();
}
