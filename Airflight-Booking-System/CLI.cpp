#include <iostream>
#include "CLI.h"
using namespace std;

void CLI::run(vector<Airplane>& airflights) {
	while (true) {
		int choice;
		cout << "\n\nChoose the command\n";
		cout << "\t0. Exit\n";
		cout << "\t1. Check available places for the flight\n";
		cout << "\t2. Buy a ticket for the flight\n";
		cout << "\t3. Return ticket with refund\n";
		cout << "\t4. View the booking confirmation info\n";
		cout << "\t5. Check available places for the flight\n";
		cin >> choice;

		if (choice == 0) break;

		switch (choice)
		{
		case 1: {
			string date;
			string flight_number;
			cout << "Enter flight date: ";
			cin >> date;
			cout << "Enter flight number: ";
			cin >> flight_number;

			auto it = std::find_if(airflights.begin(), airflights.end(),
				[flight_number, date](const Airplane& airplane) {
					return airplane.GetFlightNumber() == flight_number && airplane.GetDate() == date;
				});

			if (it != airflights.end()) {
				Airplane foundAirplane = *it;
				cout << "List of free spaces:\n";
				for (Seat seat : foundAirplane.GetSeats()) {
					cout << seat.GetId() << ' ' << seat.GetPrice() << "$, ";
				}
			}
			else {
				std::cout << "Airplane with such data not found." << endl;
			}
			break;
		}
		case 2: {
			string date;
			string flight_number;
			string place;
			string username;
			cout << "Enter flight date: ";
			cin >> date;
			cout << "Enter flight number: ";
			cin >> flight_number;
			cout << "Enter place: ";
			cin >> place;
			cout << "Enter username: ";
			cin >> username;

			auto it = std::find_if(airflights.begin(), airflights.end(),
				[flight_number, date](const Airplane& airplane) {
					return airplane.GetFlightNumber() == flight_number && airplane.GetDate() == date;
				});

			if (it != airflights.end()) {
				Airplane foundAirplane = *it;
				vector<Seat> seats = foundAirplane.GetSeats();

				auto itSeat = std::find_if(seats.begin(), seats.end(),
					[place](const Seat& seat) {
						return seat.GetId() == place;
					});

				if (itSeat != seats.end()) {
					Seat foundSeat = *itSeat;

					unique_ptr<Ticket> ticket(new Ticket(username, foundSeat));
					foundAirplane.AddTicket(*ticket);

					auto itDeleteSeat = remove_if(seats.begin(), seats.end(), [place](const Seat& seat) {
						return seat.GetId() == place;
						});

					foundAirplane.SetSeats(seats);

					airflights[it - airflights.begin()] = foundAirplane;

					cout << "Confirmed with ID " << ticket->GetId();
				}
				else {
					std::cout << "Seat with such number not found." << endl;
				}
			}
			else {
				std::cout << "Airplane with such data not found." << endl;
			}
			break;
		}
		case 3: {

		}
		case 4: {

		}
		case 5: {

		}
		default:
			break;
		}
	}
}
