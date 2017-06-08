#include <boost/test/auto_unit_test.hpp>
#include <boost/test/unit_test.hpp>


#include "Garage.h"

Garage garage;

BOOST_AUTO_TEST_CASE(garage_with_added_vehicle_is_not_empty)
{
 	 garage.addVehicle(std::unique_ptr<Vehicle> (new Car("ABC1234",5,5,4)));
	BOOST_CHECK_EQUAL(garage.baseSize(),1);
   
}

BOOST_AUTO_TEST_CASE(lending_vehicle_from_garage_makes_it_not_available)
{
	garage.lendVehicle(1);
	 BOOST_CHECK_EQUAL(garage.lendVehicle(1),false);   
}
BOOST_AUTO_TEST_CASE(returning_vehicle_to_garage_makes_it_available)
{
	garage.returnVehicle(1);
	 BOOST_CHECK_EQUAL(garage.lendVehicle(1),true);   
}
BOOST_AUTO_TEST_CASE(removing_vehicle_from_garage_makes_makes_garage_size_zero)
{
	garage.removeVehicle(1);
	 BOOST_CHECK_EQUAL(garage.baseSize(),0);   
}

