//
// Created by Chris Lawrence on 3/13/18.
//

#include <string>
using namespace std;

#ifndef Card_h
#define Card_h

#include <stdio.h>
#include <ostream>

class Card {

public:

    Card() {}

    const string &getFirstName() const;

    void setFirstName(const string &firstName);

    const string &getLastName() const;

    void setLastName(const string &lastName);

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getOccupation() const;

    void setOccupation(const string &occupation);

    const string &getPhoneNumber() const;

    void setPhoneNumber(const string &phoneNumber);

    friend ostream &operator<<(ostream &os, const Card &card);

    bool operator<(const Card &rhs) const;


private:
    string firstName;
    string lastName;
    string address;
    string occupation;
    string phoneNumber;
};

#endif /* Card_h */
