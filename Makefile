

CPPFLAGS = --std=c++11 -Wall  -DBOOST_TEST_DYN_LINK
LINKFLAGS = --std=c++11 -lboost_unit_test_framework

lib_SOURCES = \
	vehicle.cpp \
	vehicle.h \
	motorcycle.cpp \
	motorcycle.h \
	Car.cpp \
	Car.h \
	Garage.cpp \
	Garage.h \
	Observer.h \
	NrObs.cpp \
	NrObs.h \
	WriteObs.cpp \
	WriteObs.h \
	interface.h \
	interface.cpp \
	Truck.h \
	Truck.cpp 

lib_OBJECTS=$(lib_SOURCES:.cpp=.o)

tests_SOURCES = \
	vehicleTests.cpp 
	

tests_OBJECTS=$(tests_SOURCES:.cpp=.o)

app_SOURCES = \
	main.cpp

app_OBJECTS=$(app_SOURCES:.cpp=.o)

tests_EXECUTABLE = tests_bin

all: calc tests

%.o : %.c
	$(CXX) -c $(CPPFLAGS) $< -o $@

$(tests_EXECUTABLE): $(tests_OBJECTS) $(lib_OBJECTS)
	$(CXX) -o $@ $(tests_OBJECTS) $(lib_OBJECTS) $(LINKFLAGS)

tests: $(tests_EXECUTABLE)
	./$(tests_EXECUTABLE)

calc: $(lib_OBJECTS) $(app_OBJECTS)
	$(CXX) -o $@ main.cpp $(app_OBJECTS) $(lib_OBJECTS) --std=c++11

.PHONY: clean tests

clean:
	- rm *.o
	- rm tests_bin

