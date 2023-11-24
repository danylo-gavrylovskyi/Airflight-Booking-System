#include "Seat.h"

Seat::Seat(Seat&& another) {
	this->price = another.price;
	this->id = another.id;

	another.price = 0;
	another.id = "";
}

Seat::Seat(const Seat& another) {
	this->price = another.price;
	this->id = another.id;
}

void Seat::operator = (const Seat& another) {
	this->price = another.price;
	this->id = another.id;
}

double Seat::GetPrice() const {
	return this->price;
}
string Seat::GetId() const {
	return this->id;
}