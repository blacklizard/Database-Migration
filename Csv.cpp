/*
 * File: Csv.cpp
 * Author: Jeevan
 *
 * Website: http://www.icodewithlizard.com/
 */
#include <iostream>
#include "List.h"
#include "Csv.h"

CSV::CSV(){
    row = 0;
    cCell = 1;
    list = new List();
}

void CSV::readAllRow(std::istream& str){
    std::string line;

    while(std::getline(str,line,'\n') /*&& row!=2*/){
        std::stringstream lineStream(line);
        std::string cell;
        ROW * newPtrData = new ROW;
        while(std::getline(lineStream,cell,','))
        {
            std::string result = cell.substr (1,cell.length()-2/*why 2? because at this very moment, in cell var, the starting double quote still exist*/);


            switch(cCell){
                case 6:
                    newPtrData->mbs_email = result;
                case 9:
                    newPtrData->mbs_dob = result;
                case 11:
                    newPtrData->mbs_gender = result;
                case 12:
                    newPtrData->mbs_address1 = result;
                case 13:
                    newPtrData->mbs_address2 = result;
                case 14:
                    newPtrData->mbs_city = result;
                case 15:
                    newPtrData->mbs_postcode = result;
                case 16:
                    newPtrData->mbs_state = result;
                case 17:
                    newPtrData->mbs_country = result;
                case 20:
                    newPtrData->mbs_mode = result;
                case 25:
                    newPtrData->mbs_promo = result;
                case 26:
                    newPtrData->mbs_comm = result;
                case 28:
                    newPtrData->mbs_type = result;
                case 29:
                    newPtrData->mbs_cardyear = result;
                case 30:
                    newPtrData->mbs_kadmesrano = result;
                case 31:
                    newPtrData->mbs_unsubscribe = result;
                case 32:
                    newPtrData->mbs_mypref1 = result;
                case 33:
                    newPtrData->mbs_mypref2 = result;
                case 34:
                    newPtrData->mbs_mypref3 = result;
                case 35:
                    newPtrData->mbs_rank = result;
                case 36:
                    newPtrData->mbs_language = result;

            }
            cCell++;

        }
        list->AddNode(newPtrData);
        cCell=1;
        delete newPtrData;
        row++;
    }
    std::cout<<row<<" row processed"<<std::endl;

}

void CSV::writeToFile(){

    std::ofstream outputFile;
    outputFile.open ("/home/blacklizard/Desktop/MigrationLIst/bin/Debug/save.csv");

    std::ifstream file("/home/blacklizard/Desktop/MigrationLIst/bin/Debug/userdone1.csv");

    std::string line;
    std::vector<std::string> data(21);
    //int count = 0;
    while(std::getline(file,line,'\n')){
        data = list->getNodeByID(getRowEmail(line));
        if(data[0].empty()){
            outputFile <<line;
            outputFile <<";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\";\"\""<<std::endl;
        }else{
            outputFile <<line;
            outputFile <<";\""<<data[1]<<"\";\""<<data[2]<<"\";\""<<data[3]<<"\";\""<<data[4];
            outputFile <<"\";\""<<data[5]<<"\";\""<<data[6]<<"\";\""<<data[7]<<"\";\""<<data[8]<<"\";\""<<data[9]<<"\";\""<<data[10];
            outputFile <<"\";\""<<data[11]<<"\";\""<<data[12]<<"\";\""<<data[13]<<"\";\""<<data[14]<<"\";\""<<data[15]<<"\";\""<<data[16];
            outputFile <<"\";\""<<data[17]<<"\";\""<<data[18]<<"\";\""<<data[19]<<"\";\""<<data[20]<<"\""<<std::endl;
        }
        //count++;
    }
      outputFile.close();
}

std::string CSV::getRowEmail(std::string row){

    std::stringstream lineStream(row);
    std::string cell;
    int count = 1;
    while(std::getline(lineStream,cell,';') && count!=17){
        count++;
    }
    return cell.substr (1,cell.length()-2);
}
