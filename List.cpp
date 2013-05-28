/*
 * File: List.cpp
 * Author: Jeevan
 *
 * Website: http://www.icodewithlizard.com/
 */
#include <iostream>

#include <string>
#include <vector>
//#include <algorithm>
#include "List.h"

//using namespace std;

List::List(){

    head = NULL;
    curr = NULL;
    prev = NULL;
    temp = NULL;
    TRow = 0;
    listSize = 0;
}

void List::AddNode(rowPtr data){

    nodePtr n = new node;
    n->next = NULL;
    n->data = new ROW;
    n->data->mbs_email = data->mbs_email;
    n->data->mbs_dob = data->mbs_dob;
    n->data->mbs_gender = data->mbs_gender;
    n->data->mbs_address1 = data->mbs_address1;
    n->data->mbs_address2 = data->mbs_address2;
    n->data->mbs_city = data->mbs_city;
    n->data->mbs_postcode = data->mbs_postcode;
    n->data->mbs_state = data->mbs_state;
    n->data->mbs_country = data->mbs_country;
    n->data->mbs_mode = data->mbs_mode;
    n->data->mbs_promo = data->mbs_promo;
    n->data->mbs_comm = data->mbs_comm;
    n->data->mbs_cardyear = data->mbs_cardyear;
    n->data->mbs_kadmesrano = data->mbs_kadmesrano;
    n->data->mbs_unsubscribe = data->mbs_unsubscribe;
    n->data->mbs_mypref1 = data->mbs_mypref1;
    n->data->mbs_mypref2 = data->mbs_mypref2;
    n->data->mbs_mypref3 = data->mbs_mypref3;
    n->data->mbs_rank = data->mbs_rank;
    n->data->mbs_language = data->mbs_language;
    n->data->mbs_type = data->mbs_type;

    if(head == NULL){
        head = n;
        curr = head;
    }else{
        //O(1)
        prev = curr;
        curr = n;
        prev->next= curr;

        //O(n)
//        curr = head;
//        while(curr->next !=NULL){
//            curr = curr->next;
//        }
//        curr->next = n;
    }
    listSize++;
}

void List::PrintList(){

    temp = head;
    while(temp!= NULL){
        std::cout<<temp->data->mbs_email<<std::endl;
        temp = temp->next;
    }
    temp = NULL;
}


std::vector<std::string> List::getNodeByID(std::string mbs_email){

    temp = head;
    bool found = false;
    std::vector<std::string> data(21);
    while(temp!= NULL && found!=true){

        if(temp->data->mbs_email.find(mbs_email)!= std::string::npos) {
            found = true;
            data[0] = temp->data->mbs_email;
            data[1] = temp->data->mbs_dob;
            data[2] = temp->data->mbs_gender;
            data[3] = temp->data->mbs_address1;
            data[4] = temp->data->mbs_address2;
            data[5] = temp->data->mbs_city;
            data[6] = temp->data->mbs_postcode;
            data[7] = temp->data->mbs_state;
            data[8] = temp->data->mbs_country;
            data[9] = temp->data->mbs_mode;
            data[10] = temp->data->mbs_promo;
            data[11] = temp->data->mbs_comm;
            data[12] = temp->data->mbs_type;
            data[13] = temp->data->mbs_cardyear;
            data[14] = temp->data->mbs_kadmesrano;
            data[15] = temp->data->mbs_unsubscribe;
            data[16] = temp->data->mbs_mypref1;
            data[17] = temp->data->mbs_mypref2;
            data[18] = temp->data->mbs_mypref3;
            data[19] = temp->data->mbs_rank;
            data[20] = temp->data->mbs_language;
        }else{
            temp = temp->next;
        }
    }
    return data;
}
