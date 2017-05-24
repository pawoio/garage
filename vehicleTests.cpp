
#include "boost/test/auto_unit_test.hpp"
#include <boost/test/unit_test.hpp>



#include "vehicle.h"

BOOST_AUTO_TEST_CASE(created_vehicle_has_proper_license_numer)
{
   Vehicle vl=Vehicle("ABC1234");

    BOOST_CHECK_EQUAL(std::strcmp(vl.getLicenseNr().c_str(),std::string("ABC1234").c_str()),0);
}
