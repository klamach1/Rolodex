//
//  Rolodex.cpp
//  Rolodex
//
//  Created by Chris Lawrence on 3/16/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#include "Rolodex.h"
#include <list>

Rolodex::Rolodex() {
    cardPos = cardList.begin();
}

void Rolodex::add(const Card& myCard) {
    cardList.insert(cardPos, myCard);
    --cardPos;
    cardList.sort();
}

Card Rolodex::remove() {
    Card removedCard;
    removedCard = *cardPos;
    cardPos = cardList.erase(cardPos);
    //++cardPos;
    if (cardPos == cardList.end()) {
        cardPos = cardList.begin();
    }
    //cardList.remove(removedCard);
    return removedCard;
}

const Card Rolodex::getCurrentCard() {
    return Card(cardPos->getFirstName(),
                cardPos->getLastName(),
                cardPos->getOccupation(),
                cardPos->getAddress(),
                cardPos->getPhoneNumber());
}

const Card Rolodex::flip() {
    
    ++cardPos;
    
    if (cardPos == cardList.end()) {
        cardPos = cardList.begin();
    }

    return Card(cardPos->getFirstName(),
                cardPos->getLastName(),
                cardPos->getOccupation(),
                cardPos->getAddress(),
                cardPos->getPhoneNumber());
}

void Rolodex::show(ostream& os) {
    cardList.sort();
    std::list<Card>::iterator it;
    for (it=cardList.begin();it!=cardList.end();++it) {
        it->show(os);
        os << endl;
    }
}
