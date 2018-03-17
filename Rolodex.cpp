//
//  Rolodex.cpp
//  Rolodex
//
//  Created by Chris Lawrence on 3/16/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

//TODO: remove
//for debug
#include <iostream>
#include "Rolodex.h"
#include <list>

Rolodex::Rolodex() {
    cardPos = cardList.begin();
}
/*
void Rolodex::add(const Card& myCard) {
    cardList.insert(cardPos, myCard);
    --cardPos;
    cardList.sort();
}
 */

void Rolodex::add(const Card& myCard) {
    
    bool inserted = false;
    
    //get the input comparison once rather than repeatedly
    //accessing the object
    string insertKey = myCard.getLastName()+myCard.getFirstName();
    
    //check for current position name match or empty list
    if (cardList.empty() || cardPos->getLastName()+cardPos->getFirstName() == insertKey) {
        cardList.insert(cardPos, myCard);
        --cardPos;
    }
    else {
        std::list<Card>::iterator it;
        
        //if the value to insert is > the current value
        //start the comparison at beginning, otherwise start at the current

        insertKey > cardPos->getLastName()+cardPos->getFirstName()
        ? it = cardPos : it= cardList.begin();

        //the goal is to find the first value that is greater than the
        //value to insert and insert prior to that value
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
    Card removedCard;
    removedCard = *cardPos;
    cardPos = cardList.erase(cardPos);
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
    
    if (cardPos == cardList.end()) {
        cardPos = cardList.begin();
    }

    return *cardPos;
}

bool Rolodex::search(const string& lastName, const string& firstName) {
    
    //check for current position match
    if (cardPos->getLastName() == lastName
        && cardPos->getFirstName() == firstName) {
        return true;
    }
    
    std::list<Card>::iterator it;
    
    if (cardPos->getLastName()+cardPos->getFirstName() > lastName+firstName) {
        for (it=cardList.begin();it!=cardPos;++it) {
            if (it->getLastName() == lastName
                && it->getFirstName() == firstName) {
                cardPos = it;
                return true;
            }
        }
    } else {
        for (it=cardList.end();it!=cardPos;--it) {
            if (it->getLastName() == lastName
                && it->getFirstName() == firstName) {
                cardPos = it;
                return true;
            }
        }
    }
    //if we made it here, no match
    return false;
   
}

void Rolodex::show(ostream& os) {
    std::list<Card>::iterator it;
    for (it=cardList.begin();it!=cardList.end();++it) {
        it->show(os);
        os << endl;
    }
}
