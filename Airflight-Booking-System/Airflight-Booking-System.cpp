#include <iostream>
#include <vector>
#include "ConfigReader.h"
#include "Airplane.h"

int main()
{
    vector<Airplane> airflights;
    ConfigReader config_reader;
    config_reader.loadConfig("config.txt");
    config_reader.readConfig(airflights);
}
