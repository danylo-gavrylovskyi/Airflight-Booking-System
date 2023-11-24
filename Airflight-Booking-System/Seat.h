#pragma once

#include <string>
using namespace std;

class Seat {
	double price = 0;
	string id = "";
public:
	Seat(double price, string id) : price(price), id(id) {};
	Seat() : price(0), id("") {};

	Seat(Seat&& another);

	Seat(const Seat& another);

	void operator = (const Seat& another);

	double GetPrice() const;
	string GetId() const;
};