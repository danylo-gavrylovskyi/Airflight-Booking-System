#include <iostream>
#include <fstream>

#include "ConfigReader.h"

void ConfigReader::loadConfig(const char* fileName) {
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            this->config += line;
        }
        myfile.close();
    }

    else cout << "Unable to open file";
}