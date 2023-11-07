#include <string>
using namespace std;

class IConfigReader {
	virtual void loadConfig() = 0;
};

class ConfigReader: public IConfigReader {
	string config;

public:
	void loadConfig(const char* fileName);
};