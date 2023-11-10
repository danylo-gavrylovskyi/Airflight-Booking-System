#pragma once

#include <string>
#include <vector>
#include "Seat.h"
using namespace std;

class IAirplane {
	virtual void SetSeats(vector<Seat> seats) = 0;
	virtual void SetDate(string date) = 0;
	virtual void SetFlightNumber(string flight_number) = 0;
	virtual void SetNumOfSeatsPerRow(int num_of_seats_per_row) = 0;
};

class Airplane: public IAirplane {
	vector<Seat> seats = {};
	string date = "";
	string flight_number = "";
	int num_of_seats_per_row = 0;
public:
	Airplane();
	Airplane(const Airplane& another);
	Airplane(Airplane&& another);

	void SetSeats(vector<Seat> seats) override;
	void SetDate(string date) override;
	void SetFlightNumber(string flight_number) override;
	void SetNumOfSeatsPerRow(int num_of_seats_per_row) override;
};
