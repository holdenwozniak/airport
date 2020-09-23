//	airport.h

#ifndef AIRPORT_H_
#define AIRPORT_H_

#include "flight.h"

using namespace std;

void displayAirportOptions();
void handleSelectedAirportOption(char);

void insertFlight();

int ingestFlightNumber();
int obtainFlightNumberFromUser();
bool obtainAndValidateFlightNumber();
bool flightNumberIsNotDuplicate();

string ingestFlightDestination();
string ingestFlightOrigin();

double ingestFlightDuration();
bool obtainAndValidateFlightDuration();

bool ingestFlightOnTime();
void obtainFlightOnTime();

void printFlightList();

void clearFlightList();

void searchFlightList();
void checkIfSearchedFlightExists(Flight);
bool ifSearchedFlightExists(Flight);

void modifyFlight();

void replaceFlight();

void runProgram();

#endif
