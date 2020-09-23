//	airport.cpp

#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <set>
#include "flight.h"
#include "flightlist.h"
#include "airport.h"
using namespace std;

//	Function Prototypes/Global Variables

FlightList list;

bool done = false;

char selectedOption;

set<int> flightNums;
int currentFlightNumber;

string flightDestination;
string flightOrigin;

double flightDuration;

char flightOnTimeSelectedOption;
bool isFlightOnTime;

Flight searchedFlight;

int obtainedNumber;
bool isModificationDone;
char modificationSelection;

//	Main Program

void runProgram() {

	cout << "\n   Holdini International Airports.\n";

	while (!done) {

		displayAirportOptions();
		handleSelectedAirportOption(selectedOption);

	}

}

//	Functions Declarations

void displayAirportOptions() {

	cout << "\n";

	cout << "\t (I)nsert flight to list\n";
	cout << "\t (P)rint list\n";
	cout << "\t (S)earch for flight in list\n";
	cout << "\t (E)dit flight in list\n";
	cout << "\t (R)eplace flight in list\n";
	cout << "\t (C)lear list\n";
	cout << "\t (Q)uit\n";
	cout << endl;
	cout << "Next command ==> ";

	cin >> selectedOption;
	cin.ignore(80, '\n');

	selectedOption = toupper(selectedOption);

	cout << setfill('*') << setw(80) << "*" << endl;

}

void handleSelectedAirportOption(char airportOptionSelection) {

	switch (airportOptionSelection) {

	case 'I':

		insertFlight();
		break;

	case 'P':

		printFlightList();
		break;

	case 'C':

		clearFlightList();
		break;

	case 'S':

		searchFlightList();
		break;

	case 'E':

		modifyFlight();
		break;

	case 'R':

		break;

	case 'Q':

		done = true;
		break;
	}

	cout << setfill('*') << setw(80) << "*" << endl;

}

void insertFlight() {

	ingestFlightNumber();
	ingestFlightDestination();
	ingestFlightOrigin();
	ingestFlightDuration();
	ingestFlightOnTime();

	Flight flight(currentFlightNumber, flightDestination, flightOrigin,
			flightDuration, isFlightOnTime);
	list.insert(flight);

}

int ingestFlightNumber() {

	bool flightNumberIngested = false;
	while (!flightNumberIngested) {

		if (obtainAndValidateFlightNumber() && flightNumberIsNotDuplicate()) {
			flightNums.insert(currentFlightNumber);
			flightNumberIngested = true;
		}

	}

	return currentFlightNumber;
}
int obtainFlightNumberFromUser() {

	bool flightNumberObtained = false;
	while (!flightNumberObtained) {

		if (obtainAndValidateFlightNumber() && flightNumberIsNotDuplicate()) {
			flightNumberObtained = true;
		}

	}

	return currentFlightNumber;

}
bool obtainAndValidateFlightNumber() {

	bool isValidInteger = false;

	cout << "Flight No. ==>" << endl;
	cin >> currentFlightNumber;
	cin.ignore(80, '\n');

	if (cin.fail()) { // Checks to make sure input number is a valid integer
		cin.clear(); // Removes cin from the exception statement if input number is not valid
		cin.ignore(80, '\n'); // Throws out blanks spaces until a new line is hit
		cout << "Bad input, please enter an integer." << endl;
	} else {
		isValidInteger = true;
	}

	return isValidInteger;
}
bool flightNumberIsNotDuplicate() {

	bool ifFlightNumExistsInFlightSet;
	ifFlightNumExistsInFlightSet = flightNums.find(currentFlightNumber)
			!= flightNums.end(); // Returns a const iteratior to the element (i.e. access only) or the find function returns
	if (ifFlightNumExistsInFlightSet) {
		cout << "Flight No. already exists in list.\n";
	} else {
		flightNums.insert(currentFlightNumber);
	}

	return !ifFlightNumExistsInFlightSet;

}

string ingestFlightDestination() {

	cout << "Flight Destination ==>" << endl;
	getline(cin, flightDestination);
	return flightDestination;

}
string ingestFlightOrigin() {

	cout << "Flight Origin ==>" << endl;
	getline(cin, flightOrigin);
	return flightOrigin;

}

double ingestFlightDuration() {

	bool flightDurationIngested = false;
	while (!flightDurationIngested) {

		if (obtainAndValidateFlightDuration()) {
			flightDurationIngested = true;
		}

	}

	return flightDuration;

}
bool obtainAndValidateFlightDuration() {

	bool isValidDouble = false;

	cout << "Flight Duration ==>" << endl;
	cin >> flightDuration;
	cin.ignore(80, '\n');

	if (cin.fail()) { // Checks to make sure input number is a valid integer
		cin.clear(); // Removes cin from the exception statement if input number is not valid
		cin.ignore(80, '\n'); // Throws out blanks spaces until a new line is hit
		cout << "Bad input, please enter an double." << endl;
	} else {
		isValidDouble = true;
	}

	return isValidDouble;

}

bool ingestFlightOnTime() {

	obtainFlightOnTime();
	return isFlightOnTime;

}
void obtainFlightOnTime() {

	do {
		cout << "Flight On Time (Y/N) ==>" << endl;
		cin >> flightOnTimeSelectedOption;
		flightOnTimeSelectedOption = toupper(flightOnTimeSelectedOption);
	} while (flightOnTimeSelectedOption != 'Y'
			&& flightOnTimeSelectedOption != 'N');

	if (flightOnTimeSelectedOption == 'Y') {
		isFlightOnTime = true;
	} else {
		isFlightOnTime = false;
	}

}

void printFlightList() {

	cout << setfill(' ') << "No." << setw(20) << "Destination" << setw(20)
			<< "Origin" << setw(20) << "Duration" << setw(10) << "Status\n";
	list.print();
	cout << "\n";
	cout << "Number of elements: " << list.length() << '\n';

}

void clearFlightList() {

	cout << "Flight list and Flight number set cleared\n";
	flightNums.clear();
	list.clear();

}

void searchFlightList() {

	obtainAndValidateFlightNumber();
	searchedFlight = list.searchFlight(currentFlightNumber);
	checkIfSearchedFlightExists(searchedFlight);

}
void checkIfSearchedFlightExists(Flight flightFound) {

	if (flightFound.getNum() == -1) {
		cout << "Flight not found\n";
	} else {
		cout << setfill(' ') << "No." << setw(20) << "Destination" << setw(20)
				<< "Origin" << setw(20) << "Duration" << setw(10) << "Status\n";

		cout << setfill(' ') << flightFound.getNum() << setw(20)
				<< flightFound.getDestination() << setw(20)
				<< flightFound.getOrigin() << setw(20)
				<< flightFound.getDuration() << setw(10);
		if (flightFound.getOnTime() == 1) {
			cout << "On Time" << endl;
		} else {
			cout << "Late" << endl;
		}
	}

}
bool ifSearchedFlightExists(Flight flightFound) {

	if (flightFound.getNum() == -1) {
		return false;
	} else {
		return true;
	}

}

void modifyFlight() {

	searchFlightList();
	if (!ifSearchedFlightExists(searchedFlight)) {

	}

	else {
		list.modifyFlight(searchedFlight.getNum());
	}

}
