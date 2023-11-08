#include "Airplane.h"
#include <string>

using namespace std;

Airplane::Airplane(int seats, string date, string flight_number, int num_of_seats_per_row) {
	this->seats = seats;
	this->date = date;
	this->flight_number = flight_number;
	this->num_of_seats_per_row = num_of_seats_per_row;
}

Airplane::Airplane(const Airplane&) = delete;
Airplane::Airplane(Airplane&&) = delete;
