#pragma once

#include <string>
#include "Seat.h"
using namespace std;

class ITicket {
	virtual void SetBookingStatus(string booking_status) = 0;
	virtual string GetBookingStatus() const = 0;
	virtual int GetId() const = 0;
};

class Ticket: public ITicket {
	static int current_id;
	int id = 0;
	string passenger_name = "";
	Seat seat;
	string booking_status = "";
public:
	Ticket(string passenger, Seat bookedSeat);

	void SetBookingStatus(string booking_status) override;
	string GetBookingStatus() const override;

	int GetId() const override;
};
