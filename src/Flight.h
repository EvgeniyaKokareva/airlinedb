
#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <iostream>
#include "OrderedLinkedList.h"
#include "Passenger.h"
#include <iostream>

using namespace std;

class Flight{
	int numberOfFlight;

public:
	OrderedLinkedList<Passenger> *passengers;
	Flight(int);
	void setNumberOfFlight(int);
	int getNumberOfFlight();

	friend void print(Flight*);
};



#endif /* FLIGHT_H_ */
