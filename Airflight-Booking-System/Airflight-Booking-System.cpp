#include <iostream>
#include <vector>
#include "ConfigReader.h"
#include "Airplane.h"
#include "CLI.h"

int main()
{
    vector<Airplane> airflights;
    ConfigReader config_reader;
    CLI cli;
    vector<Ticket> tickets = {};

    config_reader.loadConfig("config.txt");
    config_reader.readConfig(airflights);
    cli.run(airflights, tickets);
    return 0;
}
