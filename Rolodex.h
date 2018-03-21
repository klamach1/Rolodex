//
//  Rolodex.h
//  Created by Chris Lawrence on 3/16/18.
//  Class that represents a Rolodex
//  Implements a STL List object to hold the card objects in
//  A-Z last name, first name order
//  in the Rolodex.  Implementa a STL Iterator to keep track
//  of the current card.
//  Includes basic functions to add card, remove current card,
//  return the current card, search for a card by first & last name
//  and display all of the card contents
//

#ifndef Rolodex_h
#define Rolodex_h

#include <list>
#include "Card.h"

class Rolodex {
public:
    
    Rolodex();
    
    //adds a Card to the List
    //maintains A-Z lastname, firstname sort order
    void add(const Card&);
    
    //removes the current Card from the list and returns a copy
    Card remove();
    
    //returns a copy of the current card
    const Card getCurrentCard();
    
    //moves to the next card (A-Z sort order)
    const Card flip();
    
    //last name, first name search
    bool search(const string&, const string&);
    
    //takes a stream and populates with the
    //list of all cards in order
    void show(ostream& os);
    
    

private:
    std::list<Card> cardList;
    std::list<Card>::iterator cardPos;
};
#endif /* Rolodex_h */
