#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <string>
#include <iostream>

using namespace std;

class Passenger{
	string firstName;
	string lastName;
	string address;
	string phoneNumber;

	public:
		Passenger(){}
		Passenger(string, string, string, string);
		void setFirstName(string);
		void setLastName(string);
		void setAddress(string);
		void setNumber(string);

		string getFirstName();
		string getLastName();
		string getAddress();
		string getNumber();

		bool operator> (Passenger);
		bool operator< (Passenger);
		bool operator== (Passenger);
		bool operator!= (Passenger);

		void print();
};

ostream& operator<< (ostream& oStream, Passenger& passenger);

#endif /* PASSENGER_H_ */
