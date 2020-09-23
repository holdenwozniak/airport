#include "flightlist.h"
#include "airport.h"
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;

FlightList::Node::Node(Flight f) :
		flight(f), next(NULL) {
}

FlightList::Node *FlightList::insert(FlightList::Node *current, Flight f) {

	if (current && current->flight.getNum() < f.getNum()) {
		current->next = insert(current->next, f);
	}

	else {
		Node *temp = new Node(f);
		temp->flight = f;
		temp->next = current;
		current = temp;
	}

	return current;

}

Flight FlightList::searchFlight(FlightList::Node *p, int num) {

	while (p && p->flight.getNum() != num)
		p = p->next;

	if (!p) {
		Flight f;
		return f;
	}

	return p->flight;

}

void FlightList::modifyFlight(Node *p, int num) {

	bool isModificationDone = false;
	char modificationSelection;
	int obtainedFlightNumber;
	string flightDestination;
	string flightOrigin;
	Flight f;

	while (p && p->flight.getNum() != num)
		p = p->next;

	if (!p) {

		cout << "Flight not found.\n";
		return;

	}

	else {

		f = p->flight;
		while (!isModificationDone) {
			cout << "\n";
			cout << "\t Modification Options:\n";
			cout << "\n";

			cout << "\t (A)	Modify Flight Number\n";
			cout << "\t (B)	Modify Flight Destination\n";
			cout << "\t (C)	Modify Flight Origin\n";
			cout << "\t (D)	Modify Flight Duration\n";
			cout << "\t (E)	Modify Flight Status\n";
			cout << "\t (Q)	Exit\n";
			cout << endl;
			cout << "Next command ==> ";

			cin >> modificationSelection;
			cin.ignore(80, '\n');

			modificationSelection = toupper(modificationSelection);

			cout << setfill('*') << setw(80) << "*" << endl;

			switch (modificationSelection) {

			case 'A':

				obtainedFlightNumber = obtainFlightNumberFromUser();
				f.setNum(obtainedFlightNumber);
				p->flight = f;
				cout << setfill('*') << setw(80) << "*" << endl;

				break;

			case 'B':

				cout << "Flight Destination ==>" << endl;
				getline(cin, flightDestination);
				f.setDestination(flightDestination);
				p->flight = f;
				cout << setfill('*') << setw(80) << "*" << endl;

				break;

			case 'C':

				cout << "Flight Destination ==>" << endl;
				getline(cin, flightOrigin);
				f.setOrigin(flightOrigin);
				p->flight = f;
				cout << setfill('*') << setw(80) << "*" << endl;

				break;

			case 'D':

				f.setDuration(ingestFlightDuration());
				p->flight = f;
				cout << setfill('*') << setw(80) << "*" << endl;

				break;

			case 'E':

				f.setOnTime(ingestFlightOnTime());
				p->flight = f;
				cout << setfill('*') << setw(80) << "*" << endl;

				break;

			case 'Q':

				isModificationDone = true;
				cout << setfill('*') << setw(80) << "*" << endl;
				cout << "Flight modified." << endl;
				break;
			}

		}
	}

}

int FlightList::length(FlightList::Node *p) const {
	if (p)
		return 1 + length(p->next);
	else
		return 0;
}

void FlightList::print(FlightList::Node *p) const {
	while (p) {
		setfill(' ');
		cout << p->flight.getNum() << setw(20) << p->flight.getDestination()
				<< setw(20) << p->flight.getOrigin() << setw(20)
				<< p->flight.getDuration() << setw(10);
		if (p->flight.getOnTime() == 1) {
			cout << "On Time" << endl;
		} else {
			cout << "Late" << endl;
		}
		p = p->next;
	}
	cout << "\n";
}

void FlightList::dispose(FlightList::Node *p) {
	if (p) {
		dispose(p->next);
		delete p;
	}
}

// Public FlightList operations

FlightList::FlightList() :
		head(NULL) {
}

FlightList::~FlightList() {
	clear();
}

void FlightList::insert(Flight f) {
	head = insert(head, f);	//	Delegate work to private helper method
}

void FlightList::print() const {
	print(head);	//	Delegate work to private helper method
}

Flight FlightList::searchFlight(int num) {
	return searchFlight(head, num);
}

void FlightList::modifyFlight(int num) {
	modifyFlight(head, num);
}

int FlightList::length() const {
	return length(head);
}

void FlightList::clear() {
	dispose(head);
	head = NULL;
}
