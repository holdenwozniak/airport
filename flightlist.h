//	flightlist.h

#ifndef FLIGHTLIST_H_
#define FLIGHTLIST_H_

#include <iostream>
#include <string>
#include <set>
#include "flight.h"
using namespace std;

class FlightList {

	struct Node {
		Flight flight;
		Node *next;
		Node (Flight f);
	};

	Node *head;

	Node *insert(Node *p, Flight f);

	void print(Node *p) const;

	Flight searchFlight(Node *p, int);

	void modifyFlight(Node *p, int);

	int length(Node *p) const;

	void dispose(Node *p);

public:

	FlightList();

	~FlightList();

	void insert(Flight f);

	void print() const;

	Flight searchFlight(int);

	void modifyFlight(int);

	int length() const;

	void clear();
};

#endif
