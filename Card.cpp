//
// Created by Chris Lawrence on 3/13/18.
//

#include "Card.h"

const string &Card::getFirstName() const {
    return firstName;
}

void Card::setFirstName(const string &firstName) {
    Card::firstName = firstName;
}

const string &Card::getLastName() const {
    return lastName;
}

void Card::setLastName(const string &lastName) {
    Card::lastName = lastName;
}

const string &Card::getAddress() const {
    return address;
}

void Card::setAddress(const string &address) {
    Card::address = address;
}

const string &Card::getOccupation() const {
    return occupation;
}

void Card::setOccupation(const string &occupation) {
    Card::occupation = occupation;
}

const string &Card::getPhoneNumber() const {
    return phoneNumber;
}

void Card::setPhoneNumber(const string &phoneNumber) {
    Card::phoneNumber = phoneNumber;
}

ostream &operator<<(ostream &os, const Card &card) {
    os << "firstName: " << card.firstName << " lastName: " << card.lastName << " address: " << card.address
       << " occupation: " << card.occupation << " phoneNumber: " << card.phoneNumber;
    return os;
}

bool Card::operator<(const Card &rhs) const {
    if (lastName + firstName < rhs.lastName + rhs.firstName) {
        return true;
    }
    else {
        return false;
    }

}
