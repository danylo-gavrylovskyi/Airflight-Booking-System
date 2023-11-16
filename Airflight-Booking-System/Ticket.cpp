#include <string>
#include "Ticket.h"
using namespace std;

int Ticket::current_id = 0;

Ticket::Ticket(string passenger, Seat bookedSeat) {
	this->passenger_name = passenger;
	this->seat = bookedSeat;
	this->id = current_id++;
	this->booking_status = "Confirmed";
};

void Ticket::SetBookingStatus(string booking_status) {
	this->booking_status = booking_status;
}
string Ticket::GetBookingStatus() const {
	return this->booking_status;
}

int Ticket::GetId() const {
	return this->id;
}
