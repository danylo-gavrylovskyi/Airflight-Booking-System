#pragma once

#include <string>
using namespace std;

class Seat {
	double price = 0;
	string id = "";
public:
	Seat(double price, string id) : price(price), id(id) {};
	Seat() : price(0), id("") {};

	Seat(Seat&& another) {
		this->price = another.price;
		this->id = another.id;

		another.price = 0;
		another.id = "";
	}

	Seat(const Seat& another) {
		this->price = another.price;
		this->id = another.id;
	}

	void operator = (const Seat& another) {
		this->price = another.price;
		this->id = another.id;
	}

	double GetPrice() const {
		return this->price;
	}
	string GetId() const {
		return this->id;
	}
};