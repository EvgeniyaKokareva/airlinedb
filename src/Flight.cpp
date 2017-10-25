#include "Flight.h"
using namespace std;


Flight :: Flight(int number){
	numberOfFlight = number;
	passengers = new OrderedLinkedList<Passenger>();
}

void Flight :: setNumberOfFlight(int number){
	numberOfFlight = number;
}

int Flight ::  getNumberOfFlight(){
	return numberOfFlight;
}


