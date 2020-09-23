//	flight.h

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <iostream>
#include <string>
using namespace std;

class Flight {

public:

	Flight(int, string, string, double, bool);
	Flight();

	int getNum();
	void setNum(int);

	string getDestination();
	void setDestination(string);

	string getOrigin();
	void setOrigin(string);

	double getDuration();
	void setDuration(double);

	bool getOnTime();
	void setOnTime(bool);

private:

	int num;
	string destination;
	string origin;
	double duration;
	bool onTime;

};

#endif
