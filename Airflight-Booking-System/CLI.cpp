#include <iostream>
#include "CLI.h"
using namespace std;

void CLI::run(vector<Airplane>& airflights, vector<Ticket>& tickets) {
	while (true) {
		int choice;
		cout << "\n\nChoose the command\n";
		cout << "\t0. Exit\n";
		cout << "\t1. Check available places for the flight\n";
		cout << "\t2. Buy a ticket for the flight\n";
		cout << "\t3. Return ticket with refund\n";
		cout << "\t4. View the booking confirmation info\n";
		cout << "\t5. View all booked tickets for a particular user\n>> ";
		cin >> choice;

		if (choice == 0) break;

		switch (choice)
		{
		case 1: {
			checkAvailablePlaces(airflights, tickets);
			break;
		}
		case 2: {
			buyTicket(airflights, tickets);
			break;
		}
		case 3: {
			returnTicket(airflights, tickets);
			break;
		}
		case 4: {
			viewBookingInfo(airflights, tickets);
			break;
		}
		case 5: {
			viewUserTickets(airflights, tickets);
			break;
		}
		default:
			break;
		}
	}
}

void CLI::checkAvailablePlaces(vector<Airplane>& airflights, vector<Ticket>& tickets) {
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
			string seatId = seat.GetId();
			auto itTicket = std::find_if(tickets.begin(), tickets.end(),
				[seatId](const Ticket& ticket) {
					return ticket.getSeat().GetId() == seatId;
				});

			if (itTicket == tickets.end()) cout << seat.GetId() << ' ' << seat.GetPrice() << "$, ";
		}
	}
	else {
		std::cout << "Airplane with such data not found." << endl;
	}
}

void CLI::buyTicket(vector<Airplane>& airflights, vector<Ticket>& tickets) {
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

			unique_ptr<Ticket> ticket(new Ticket(username, foundSeat, foundAirplane.GetFlightNumber(), foundAirplane.GetDate()));
			tickets.push_back(*ticket);

			airflights[it - airflights.begin()] = move(foundAirplane);

			cout << "Confirmed with ID " << ticket->GetId();
		}
		else {
			std::cout << "Seat with such number not found." << endl;
		}
	}
	else {
		std::cout << "Airplane with such data not found." << endl;
	}
}

void CLI::returnTicket(vector<Airplane>& airflights, vector<Ticket>& tickets) {
	int booking_id;
	cout << "Enter booking ID: ";
	cin >> booking_id;

	auto it = std::find_if(tickets.begin(), tickets.end(),
		[booking_id](const Ticket& ticket) {
			return ticket.GetId() == booking_id;
		});

	if (it != tickets.end()) {
		Ticket foundTicket = *it;
		foundTicket.SetBookingStatus("Refund");
		tickets[it - tickets.begin()] = foundTicket;
		cout << "Confirmed " << foundTicket.getSeat().GetPrice() << " refund for " << foundTicket.getPassengerName();
	}
	else {
		std::cout << "Booking ticket not found." << endl;
	}
}

void CLI::viewBookingInfo(vector<Airplane>& airflights, vector<Ticket>& tickets) {
	int booking_id;
	cout << "Enter booking ID: ";
	cin >> booking_id;

	auto it = std::find_if(tickets.begin(), tickets.end(),
		[booking_id](const Ticket& ticket) {
			return ticket.GetId() == booking_id;
		});

	if (it != tickets.end()) {
		Ticket foundTicket = *it;
		cout << "Flight " << foundTicket.getFlightNumber() << ", " << foundTicket.getFlightDate() << ", seat " << foundTicket.getSeat().GetId() << ", price " << foundTicket.getSeat().GetPrice() << "$, " << foundTicket.getPassengerName();
		cout << endl << foundTicket.GetBookingStatus();
	}
	else {
		std::cout << "Booking ticket not found." << endl;
	}
}

void CLI::viewUserTickets(vector<Airplane>& airflights, vector<Ticket>& tickets) {
	string username;
	cout << "Enter username to view booked tickets: ";
	cin >> username;

	for (Ticket ticket : tickets) {
		if (ticket.getPassengerName() != username) continue;
		cout << ticket.GetId() << ". Flight " << ticket.getFlightNumber() << ", " << ticket.getFlightDate() << ", seat " << ticket.getSeat().GetId() << ", price " << ticket.getSeat().GetPrice() << "$, " << ticket.getPassengerName();
		cout << endl << ticket.GetBookingStatus();
	}
}
