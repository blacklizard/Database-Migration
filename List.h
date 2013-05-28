/*
 * File: List.h
 * Author: Jeevan
 *
 * Website: http://www.icodewithlizard.com/
 */

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "layout.h"

class List{

    private:
        typedef struct node{
            rowPtr data;
            node * next;
        }* nodePtr;

        nodePtr head;
        nodePtr curr;
        nodePtr prev;
        nodePtr temp;

        int TRow;
        int listSize;

    public:
        List();
        void AddNode(rowPtr data);
        void PrintList();
        std::vector<std::string> getNodeByID(std::string mbs_email);
        int getSize(){return listSize;};
};

#endif // LIST_H_INCLUDED
