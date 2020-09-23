//	flight.cpp

#include <iostream>
#include <iomanip>
#include "flight.h"

using namespace std;

Flight::Flight(int n, string d, string o, double dd, bool ot) {

	num = n;
	destination = d;
	origin = o;
	duration = dd;
	onTime = ot;

}
Flight::Flight() {

	num = -1;
	destination = "DEFAULT";
	origin = "DEFAULT";
	duration = -1;
	onTime = NULL;

}

int Flight::getNum() {

	return num;

}
void Flight::setNum(int n) {

	num = n;

}

string Flight::getDestination() {

	return destination;

}
void Flight::setDestination(string d) {

	destination = d;

}

string Flight::getOrigin() {

	return origin;

}
void Flight::setOrigin(string o) {

	origin = o;

}

double Flight::getDuration() {

	return duration;

}
void Flight::setDuration(double dd) {

	duration = dd;

}

bool Flight::getOnTime() {

	return onTime;

}
void Flight::setOnTime(bool oT) {

	onTime = oT;

}
