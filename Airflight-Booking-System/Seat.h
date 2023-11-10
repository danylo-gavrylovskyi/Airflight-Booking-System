#pragma once

#include <string>
using namespace std;

class Seat {
	double price = 0;
	string id = "";
public:
	Seat(double price, string id) {
		this->price = price;
		this->id = id;
	}

	double GetPrice() const {
		return this->price;
	}
	string GetId() const {
		return this->id;
	}
};