#include "Passenger.h"
using namespace std;


Passenger :: Passenger(string fn, string ln, string add, string number){
	firstName = fn;
	lastName = ln;
	address = add;
	phoneNumber = number;
}

void Passenger :: setFirstName(string fn){
	firstName = fn;
}

void Passenger :: setLastName(string ln){
	lastName = ln;
}

void Passenger :: setAddress(string add){
	address = add;
}

void Passenger :: setNumber(string number){
	phoneNumber = number;
}

string Passenger :: getFirstName(){
	return firstName;
}

string Passenger :: getLastName(){
	return lastName;
}

string Passenger :: getAddress(){
	return address;
}

string Passenger :: getNumber(){
	return phoneNumber;
}

bool Passenger :: operator> (Passenger other){
	if (this->getLastName() != other.getLastName()){
		return this->getLastName() > other.getLastName();
	}
	else{
		return this->getFirstName() > other.getFirstName();
	}
}

bool Passenger :: operator< (Passenger other){
	if (this->getLastName() != other.getLastName()){
		return this->getLastName() < other.getLastName();
	}
	else{
		return this->getFirstName() < other.getFirstName();
	}
}
bool Passenger :: operator== (Passenger other){
	return this->getLastName() == other.getLastName() && this->getFirstName() == other.getFirstName();
}

bool Passenger :: operator!= (Passenger other){
	return this->getLastName() != other.getLastName() || this->getFirstName() != other.getFirstName();
}

//void Passenger :: print() {
//	cout << this->getFirstName() << " " << this->getLastName() << " ";
//	cout << "[" << this->getAddress() << "] [" << this->getNumber() << "]" << endl;
//}


ostream& operator<< (ostream& oStream, Passenger& passenger)
{
	oStream << passenger.getFirstName() << " " << passenger.getLastName() << " ";
	oStream << "[" << passenger.getAddress() << "] [" << passenger.getNumber() << "]" << endl;

	return oStream;
}

