//
// Created by Chris Lawrence on 3/13/18.
// Card class represents a Card that holds
// contact information:
// First Name, Last Name, Address
// Occupation and Phone Number
//

#include <string>
using namespace std;

#ifndef Card_h
#define Card_h


#include <ostream>

class Card {

public:

    //default ctor
    Card() {};
    
    //ctor to fully populate card on creation
    Card(const string& firstName,const string& lastName, const string& occupation,
         const string& address,const string& phoneNumber) : firstName(firstName),
    lastName(lastName), occupation(occupation), address(address),
    phoneNumber(phoneNumber){};

    //getters and setters
    
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

    // << operator overload to facilitate display
    friend ostream &operator<<(ostream &os, const Card &card);

    //comparator to allow sorting
    bool operator<(const Card &rhs) const;
    
    // function to show the card
    void show(ostream& os);
    
    //comparators to allow equality tests
    bool operator==(const Card &rhs) const;
    
    bool operator!=(const Card &rhs) const;
    
private:
    string firstName;
    string lastName;
    string address;
    string occupation;
    string phoneNumber;
};

#endif /* Card_h */
