#include <vector>
#include "Airplane.h"

class ICLI {
	virtual void run(vector<Airplane>& airflights) = 0;
};

class CLI : public ICLI {
	void checkAvailablePlaces(vector<Airplane>& airflights);
	void buyTicket(vector<Airplane>& airflights);
public:
	void run(vector<Airplane>& airflights) override;
};