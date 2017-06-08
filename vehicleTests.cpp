#define BOOST_TEST_MODULE testy
#include <boost/test/auto_unit_test.hpp>
#include <boost/test/unit_test.hpp>



#include "vehicle.h"

BOOST_AUTO_TEST_CASE(created_vehicle_has_proper_license_numer)
{
   Vehicle vl=Vehicle("ABC1234");

    BOOST_CHECK_EQUAL(std::strcmp(vl.getLicenseNr().c_str(),std::string("ABC1234").c_str()),0);
}

BOOST_AUTO_TEST_CASE(created_vehicle_has_proper_production_year)
{
   Vehicle vl=Vehicle("ABC1234",5);

    BOOST_CHECK_EQUAL(vl.getProductionYear(),5);
   
}
BOOST_AUTO_TEST_CASE(created_vehicle_has_proper_enigine_power)
{
   Vehicle vl=Vehicle("ABC1234",5,7);

    BOOST_CHECK_EQUAL(vl.getEnginePower(),7);
}

BOOST_AUTO_TEST_CASE(created_vehicle_is_available)
{
   Vehicle vl=Vehicle("ABC1234",5,7);

    BOOST_CHECK_EQUAL(vl.isAvailable(),1);
}


