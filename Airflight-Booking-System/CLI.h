#include <vector>
#include "Airplane.h"

class ICLI {
	virtual void run(vector<Airplane>& airflights, vector<Ticket>& tickets) = 0;
};

class CLI : public ICLI {
	void checkAvailablePlaces(vector<Airplane>& airflights, vector<Ticket>& tickets);
	void buyTicket(vector<Airplane>& airflights, vector<Ticket>& tickets);
	void returnTicket(vector<Airplane>& airflights, vector<Ticket>& tickets);
	void viewBookingInfo(vector<Airplane>& airflights, vector<Ticket>& tickets);
	void viewUserTickets(vector<Airplane>& airflights, vector<Ticket>& tickets);
public:
	void run(vector<Airplane>& airflights, vector<Ticket>& tickets) override;
};