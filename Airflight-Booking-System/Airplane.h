#include <string>
using namespace std;

class IAirplane {
	virtual void Airplane(int seats, string date, string flight_number, int num_of_seats_per_row) = 0;
};

class Airplane {
	int seats;
	string date;
	string flight_number;
	int num_of_seats_per_row;
public:
	Airplane(int seats, string date, string flight_number, int num_of_seats_per_row);
	Airplane(const Airplane&) = delete;
	Airplane(Airplane&&) = delete;
};