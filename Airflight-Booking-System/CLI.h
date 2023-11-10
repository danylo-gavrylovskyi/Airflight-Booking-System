#include <vector>
#include "Airplane.h"

class ICLI {
	virtual void run(vector<Airplane> airflights) = 0;
};

class CLI : public ICLI {
public:
	void run(vector<Airplane> airflights) override;
};