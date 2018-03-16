//
//  Rolodex.cpp
//  Rolodex
//
//  Created by Chris Lawrence on 3/16/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#include "Rolodex.h"

Rolodex::Rolodex() {
    cardPos = cardList.begin();
}

void Rolodex::add(const Card& myCard) {
    cardList.insert(cardPos, myCard);
    --cardPos;
}

Card& Rolodex::getCurrentCard() {
    return *cardPos;
}
