#pragma once

#include <string>
#include "Seat.h"
using namespace std;

class ITicket {
	virtual void SetBookingStatus(string booking_status) = 0;
	virtual string GetBookingStatus() const = 0;
	virtual int GetId() const = 0;
	virtual Seat getSeat() const = 0;
	virtual string getPassengerName() const = 0;
	virtual string getFlightNumber() const = 0;
	virtual string getFlightDate() const = 0;
};

class Ticket: public ITicket {
	static int current_id;
	int id = 0;
	string passenger_name = "";
	Seat seat;
	string booking_status = "";
	string flight_number = "";
	string date = "";
public:
	Ticket(string passenger, Seat bookedSeat, string flight_number, string date);

	void SetBookingStatus(string booking_status) override;
	string GetBookingStatus() const override;

	Seat getSeat() const override;

	int GetId() const override;

	string getPassengerName() const override;

	string getFlightNumber() const override;

	string getFlightDate() const override;
};
