//
//  Rolodex.cpp
//  Rolodex
//
//  Created by Chris Lawrence on 3/16/18.
//  See header file for function descriptions
//


#include "Rolodex.h"
#include <list>

Rolodex::Rolodex() {
    //set the Iterator to the head of the list
    cardPos = cardList.begin();
}

// add card in the proper position in the sort order
// rather than just inserting and calling the sort function
// it should prove more efficient over time
void Rolodex::add(const Card& myCard) {
    
    bool inserted = false;
    
    //get the input comparison once rather than repeatedly
    //accessing the object
    string insertKey = myCard.getLastName()+myCard.getFirstName();
    
    //check for current position name match or empty list
    //if either is true, just insert the card
    if (cardList.empty() || cardPos->getLastName()+cardPos->getFirstName() == insertKey) {
        cardList.insert(cardPos, myCard);
        --cardPos;
    }
    else {
        
        //need a temp iterator to cycle through the list
        std::list<Card>::iterator it;
        
        //if the value to insert is > the current value
        //start the comparisons at the head of list,
        // otherwise start at the current position

        insertKey > cardPos->getLastName()+cardPos->getFirstName()
        ? it = cardPos : it= cardList.begin();

        //the goal is to find the first value that is greater than the
        //value to insert and insert prior to that value
        //loop through until the card has been inserted
        while (!inserted) {
            //have to check for cardList.end first or there is an access violation
            if (it == cardList.end() || insertKey < it->getLastName()+it->getFirstName()) {
                cardList.insert(it, myCard);
                cardPos = --it;
                inserted = true;
            }
            ++it;
        }
    }
}

Card Rolodex::remove() {
    //create a card object to hold the card that will be
    //removed and returned
    Card removedCard;
    removedCard = *cardPos;
    //erase returns a new iterator at the next position
    cardPos = cardList.erase(cardPos);
    //if it was the last card, go to the first card
    if (cardPos == cardList.end()) {
        cardPos = cardList.begin();
    }
    return removedCard;
}

const Card Rolodex::getCurrentCard() {
    return *cardPos;
}

const Card Rolodex::flip() {
    
    ++cardPos;
    
    //if it was the last card, go to the first card
    if (cardPos == cardList.end()) {
        cardPos = cardList.begin();
    }

    return *cardPos;
}

bool Rolodex::search(const string& lastName, const string& firstName) {
    
	//assume not found
	bool found = false;

    //check for current position match
    if (cardPos->getLastName() == lastName
        && cardPos->getFirstName() == firstName) {
        found = true;
    }
	else {

		//temp iterator
		std::list<Card>::iterator it;

		lastName + firstName > cardPos->getLastName() + cardPos->getFirstName()
			? it = next(cardPos,1) : it = cardList.begin();

		// if the current position is beyond the search input,
		// search from the beginning 
		// else search from the current position


		do {
			if (it->getLastName() == lastName
				&& it->getFirstName() == firstName) {
				cardPos = it;
				found = true;
			}
			else {
				++it;
			}
		// stop the search on a match, the end of the list,
		// or if the search string is no longer greater than 
		// the current string
		} while (!found && it != cardList.end() && 
			lastName + firstName >= it->getLastName() + it->getFirstName());
 	}

    return found;
   
}

void Rolodex::show(ostream& os) {
    //temp iterator to loop through the list
    //and call show on each Card
    //put a blank line after each card for readability
    std::list<Card>::iterator it;
    for (it=cardList.begin();it!=cardList.end();++it) {
        it->show(os);
        os << endl;
    }
}
