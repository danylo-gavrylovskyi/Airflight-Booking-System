#include <string>
#include "Ticket.h"
using namespace std;

int Ticket::current_id = 0;

Ticket::Ticket(string passenger, Seat bookedSeat, string flight_number, string date) {
	this->passenger_name = passenger;
	this->seat = bookedSeat;
	this->id = current_id++;
	this->booking_status = "Confirmed";
	this->flight_number = flight_number;
	this->date = date;
};

void Ticket::SetBookingStatus(string booking_status) {
	this->booking_status = booking_status;
}
string Ticket::GetBookingStatus() const {
	return this->booking_status;
}

Seat Ticket::getSeat() const {
	return this->seat;
}

int Ticket::GetId() const {
	return this->id;
}

string Ticket::getPassengerName() const {
	return this->passenger_name;
}

string Ticket::getFlightNumber() const {
	return this->flight_number;
}

string Ticket::getFlightDate() const {
	return this->date;
}
