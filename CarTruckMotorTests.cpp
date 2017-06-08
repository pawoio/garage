

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/unit_test.hpp>


#include "vehicle.h"
#include "Car.h"
#include "motorcycle.h"
#include "Truck.h"


BOOST_AUTO_TEST_CASE(created_car_has_proper_door_number)
{
   Car vl=Car("ABC1234",5,5,4);

    BOOST_CHECK_EQUAL(vl.viewAdditionalInfo(),4);
   
}

BOOST_AUTO_TEST_CASE(created_Truck_has_wheel_number)
{

  	 Truck vl;
	vl=Truck("ABC1234",5,5,7);


    BOOST_CHECK_EQUAL(vl.viewAdditionalInfo(),7);
   
}
