/*
 * File: main.cpp
 * Author: Jeevan
 *
 * Website: http://www.icodewithlizard.com/
 */
#include <iostream>
#include <fstream>
//#include <sstream>
//#include <vector>
//#include <string>

#include "List.h"
#include "Csv.h"


int main(){

    std::ifstream file("/home/blacklizard/Desktop/MigrationLIst/bin/Debug/member.csv");
    CSV * data = new CSV;
    data->readAllRow(file);
    data->writeToFile();
    return 0;
}
