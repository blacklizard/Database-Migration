/*
 * File: layout.h
 * Author: Jeevan
 *
 * Website: http://www.icodewithlizard.com/
 */

#ifndef LAYOUT_H_INCLUDED
#define LAYOUT_H_INCLUDED

typedef struct ROW{
    std::string mbs_email;
    std::string mbs_dob;
    std::string mbs_gender;
    std::string mbs_address1;
    std::string mbs_address2;
    std::string mbs_city;
    std::string mbs_postcode;
    std::string mbs_state;
    std::string mbs_country;
    std::string mbs_mode;
    std::string mbs_promo;
    std::string mbs_comm;
    std::string mbs_type;
    std::string mbs_cardyear;
    std::string mbs_kadmesrano;
    std::string mbs_unsubscribe;
    std::string mbs_mypref1;
    std::string mbs_mypref2;
    std::string mbs_mypref3;
    std::string mbs_rank;
    std::string mbs_language;
}*rowPtr;

#endif // LAYOUT_H_INCLUDED
