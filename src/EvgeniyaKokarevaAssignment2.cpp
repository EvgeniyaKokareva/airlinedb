#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "Passenger.h"
#include "Flight.h"
#include <sstream>
using namespace std;

string toUpper (string);
bool validateStringInput(string);
bool validationNumericInput(string);
int flightNumberInput(Flight**, int);
string firstNameInput();
string lastNameInput();
void processPassengerAddition(Flight**, int);
void processSearch(Flight**, int);
void processDelete(Flight**, int);
void processList(Flight**, int);
void print(Flight*);

int main() {

	int flightsAmount = 4;
	int firstFlightNumber = 100;
	int secondFlightNumber = 200;
	int thirdFlightNumber = 300;
	int fourthFlightNumber = 400;

	Flight* flights[flightsAmount];

	flights[0] = new Flight(firstFlightNumber);
	flights[1] = new Flight(secondFlightNumber);
	flights[2] = new Flight(thirdFlightNumber);
	flights[3] = new Flight(fourthFlightNumber);

	string choiceString;
	char choice;
	string input;

	cout << "*** DELTA AITLINES ***" << endl;

	while(choice != 'Q') {
			cout<< endl;
			cout << "Please	choose	an	operation: " << endl;
			cout << "A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit):";
			getline(cin, choiceString);

			if (choiceString.length() == 0) {
				continue;
			}

			choice = choiceString[0];
			choice = toupper(choice);
			switch (choice){
				//add new passenger to the flight
				case 'A':
					processPassengerAddition(flights, flightsAmount);
					break;
				//search passenger
				case 'S':
					processSearch(flights, flightsAmount);
					break;
				//delete the passenger from the flight
				case 'D':
					processDelete(flights, flightsAmount);
					break;
				//print all passengers from one flight
				case 'L':
					processList(flights, flightsAmount);
					break;
				//exit
				case 'Q':
					break;
				default:
					cout << "invalid input. try again" << endl;
					break;
			}
		}


	return 0;
}

string toUpper (string input){
	for(uint i = 0; i < input.length(); i++){
		input[i] = toupper(input[i]);
	}
	return input;
}

bool validateStringInput(string input){
	bool goodInput = true;
	for(uint i = 0; i < input.length(); i++){
		if(!isalpha(input[i])){
			goodInput = false;
			return goodInput;
		}
	}
	return goodInput;
}

bool validationNumericInput(string input){
	bool isGoodInput = true;
	for(uint i = 0; i < input.length(); i++){
		if(isalpha(input[i])){
			isGoodInput = false;
			break;
		}
	}
	return isGoodInput;
}

int flightNumberInput(Flight** flights, int numberOfFlights){
	bool isGoodInput = false;
	string input;
	int flNumber;
	while (isGoodInput == false){
		cout << endl;
		cout << "Enter flight number:	";
		getline (cin, input);
		if(validationNumericInput(input) == true){
			istringstream (input) >> flNumber;
			for(int i = 0; i < numberOfFlights; i++){
				if(flights[i]->getNumberOfFlight() == flNumber){
					isGoodInput = true;
					break;
				}
			}
		}
		if (isGoodInput == false) {
			cout << "wrong input. try again\n";
		}
	}
	 return flNumber;
}

string firstNameInput(){
	string input;
	bool isGoodInput = false;

	do{
		cout << "\nEnter first name: ";
		getline(cin, input);
		input = toUpper(input);

		//validate input
		isGoodInput = validateStringInput(input);
		if (isGoodInput != true){
			cout << "wrong input. try again" << endl;
		}
	}while (isGoodInput != true);

	return input;
}

string lastNameInput(){
	string input;
	bool isGoodInput = false;

	do{
		cout << "Enter last name: ";
		getline(cin, input);
		input = toUpper(input);

		//validate input
		isGoodInput = validateStringInput(input);

		//add data to passenger
		if (isGoodInput != true){
			cout << "wrong input. try again" << endl;
		}
	}while (isGoodInput != true);

	return input;
}

void processPassengerAddition(Flight** flights, int numberOfFlights) {
	string input;
	Passenger newPassenger;

	//choose the flight
	int flNumber = flightNumberInput(flights, numberOfFlights);

	//enter the passenger's first name
	newPassenger.setFirstName(firstNameInput());

	//enter the passenger's last name
	newPassenger.setLastName(lastNameInput());

	//enter the passenger's address
	cout << "Enter passenger's address: ";
	getline (cin, input);
	newPassenger.setAddress(input);

	//enter the passenger's phone number
	cout << "Enter passenger's phone number: ";
	getline(cin, input);
	newPassenger.setNumber(input);

	//add new passenger to the flight
	for(int i = 0; i < numberOfFlights; i++){
		if(flights[i]->getNumberOfFlight() == flNumber){
			flights[i]->passengers->insert(newPassenger);
			//print(flights[i]);
		}
	}
}

void processSearch(Flight** flights, int numberOfFlights) {
	Passenger tempPassenger;

	tempPassenger.setFirstName(firstNameInput());
	tempPassenger.setLastName(lastNameInput());

	bool foundAtLeastOnce = false;
	for(int i = 0; i < numberOfFlights; i++){
		Passenger* foundPassenger = flights[i]->passengers->searchNode(tempPassenger);

		if (foundPassenger != NULL) {
			foundAtLeastOnce = true;
			cout << endl;
			cout << "In flight " << flights[i]->getNumberOfFlight() << ": " << endl;
			cout << "First name: " << foundPassenger->getFirstName() << endl;
			cout << "Last name: " << foundPassenger->getLastName() << endl;
			cout << "Address: " << foundPassenger->getAddress() << endl;
			cout << "Phone number: " << foundPassenger->getNumber() << endl;
		}
	}
	if (!foundAtLeastOnce) {
		cout << "sorry, passenger " << tempPassenger.getFirstName() << " " << tempPassenger.getLastName();
		cout << " isn't found" << endl;
	}
}

void processDelete(Flight** flights, int numberOfFlights){
	Passenger tempPassenger;
	int flNumber = flightNumberInput(flights, numberOfFlights);
	tempPassenger.setFirstName(firstNameInput());
	tempPassenger.setLastName(lastNameInput());

	for(int i = 0; i < numberOfFlights; i++){
		if(flights[i]->getNumberOfFlight() == flNumber){
			flights[i]->passengers->deleteNode(tempPassenger);
		}
	}
}

void print(Flight* fl){
	cout << endl;
	cout << "the flight # " << fl->getNumberOfFlight() << ": " << endl;
	fl->passengers->print();

}

void processList(Flight** flights, int numberOfFlights){

	int flNumber = flightNumberInput(flights, numberOfFlights);
	for(int i = 0; i < numberOfFlights; i++){
		if(flights[i]->getNumberOfFlight() == flNumber){
			print(flights[i]);
			cout << endl;
		}
	}

}
