#include "boost/test/auto_unit_test.hpp"
#include <boost/test/unit_test.hpp>

#include "Garage.h"

BOOST_AUTO_TEST_CASE()
{
   Car vl=Car("ABC1234",5,5,4);

    BOOST_CHECK_EQUAL(vl.viewAdditionalInfo(),5);
   
}
