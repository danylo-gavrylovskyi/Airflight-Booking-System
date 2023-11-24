#include <string>
#include <iostream>
#include "Airplane.h"

using namespace std;

Airplane::Airplane() {}

Airplane::Airplane(const Airplane& another) {
	this->date = another.date;
	this->flight_number = another.flight_number;
	this->num_of_seats_per_row = another.num_of_seats_per_row;
	this->seats = another.seats;
}

Airplane::Airplane(Airplane&& another) {
	this->date = another.date;
	this->flight_number = another.flight_number;
	this->num_of_seats_per_row = another.num_of_seats_per_row;
	this->seats = another.seats;

	another.date = "";
	another.flight_number = "";
	another.num_of_seats_per_row = 0;
	another.seats = {};
}

void Airplane::operator = (const Airplane& another) {
	this->date = another.date;
	this->flight_number = another.flight_number;
	this->num_of_seats_per_row = another.num_of_seats_per_row;
	this->seats = another.seats;
}

void Airplane::operator = (Airplane&& another) {
	this->date = another.date;
	this->flight_number = another.flight_number;
	this->num_of_seats_per_row = another.num_of_seats_per_row;
	this->seats = another.seats;

	another.date = "";
	another.flight_number = "";
	another.num_of_seats_per_row = 0;
	another.seats = {};
}

void Airplane::SetSeats(vector<Seat>& seats) {
	this->seats = move(seats);
}
void Airplane::SetDate(string date) {
	this->date = date;
}
void Airplane::SetFlightNumber(string flight_number) {
	this->flight_number = flight_number;
}
void Airplane::SetNumOfSeatsPerRow(int num_of_seats_per_row) {
	this->num_of_seats_per_row = num_of_seats_per_row;
}

vector<Seat> Airplane::GetSeats() const {
	return this->seats;
}
string Airplane::GetDate() const {
	return this->date;
}
string Airplane::GetFlightNumber() const {
	return this->flight_number;
}
int Airplane::GetNumOfSeatsPerRow() const {
	return this->num_of_seats_per_row;
}
