#include <string>
#include "Airplane.h"
using namespace std;

class IConfigReader {
	virtual void loadConfig(const char* fileName) = 0;
	virtual void readConfig(vector<Airplane>& airflight) = 0;
	virtual string GetConfig() = 0;
};

class ConfigReader: public IConfigReader {
	string config = "";
	vector<std::string> split(string text, char delimeter);
public:
	void loadConfig(const char* fileName) override;
	void readConfig(vector<Airplane>& airflight) override;
	string GetConfig() override;
};