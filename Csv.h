/*
 * File: Csv.h
 * Author: Jeevan
 *
 * Website: http://www.icodewithlizard.com/
 */

#ifndef CSV_H_INCLUDED
#define CSV_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "layout.h"

class CSV{

    private:
        int row;
        int cCell;
        List *list;

    public:
        CSV();
        void readAllRow(std::istream& str);
        void writeToFile();
        std::string getRowEmail(std::string row);
};



#endif // CSV_H_INCLUDED
