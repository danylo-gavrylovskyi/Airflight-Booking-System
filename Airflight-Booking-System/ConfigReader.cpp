#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "ConfigReader.h"

using namespace std;

void ConfigReader::loadConfig(const char* fileName) {
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            this->config += "\n" + line;
        }
        myfile.close();
    }

    else cout << "Unable to open file";
}

void ConfigReader::readConfig(vector<Airplane>& airflights) {
    if (this->config.empty()) {
        cout << "Error: no config found";
        return;
    }

    Airplane airplane = {};

    vector<string> lines = split(this->config, '\n');

    for (string line : lines) {
        if (line.size() < 2) continue;

        vector<string> dataLine = split(line, ' ');

        vector<Seat> seats = {};

        int num_of_seats_per_row = stoi(dataLine[2]);

        airplane.SetDate(dataLine[0]);
        airplane.SetFlightNumber(dataLine[1]);
        airplane.SetNumOfSeatsPerRow(num_of_seats_per_row);

        for (int i = 3; i < dataLine.size(); i++) {
            vector<string> range = split(dataLine[i], '-');
            for (int seat_num = stoi(range[0]); seat_num < stoi(range[1]) + 1; seat_num++)
            {
                int shift = seat_num % num_of_seats_per_row == 0 ? num_of_seats_per_row : seat_num % num_of_seats_per_row;
                string id = std::to_string(seat_num) + char(64 + shift);
                int price = stoi(dataLine[i + 1].substr(0, dataLine[i + 1].size() - 1));
                seats.push_back(Seat(price, id));
            }
            i++;
        }
        airplane.SetSeats(seats);

        airflights.push_back(airplane);
    }
}

string ConfigReader::GetConfig() {
    return this->config;
}

vector<string> ConfigReader::split(const string& text, char delimeter) {
    istringstream iss(text);

    vector<string> lines = {};

    string line;
    while (getline(iss, line, delimeter)) {
        lines.push_back(move(line));
    }

    return lines;
}