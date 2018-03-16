//
//  Rolodex.h
//  Rolodex
//
//  Created by Chris Lawrence on 3/16/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#ifndef Rolodex_h
#define Rolodex_h

#include <stdio.h>
#include <list>
#include "Card.h"

class Rolodex {
public:
    
    Rolodex();
    
    void add(const Card&);
    
    Card* remove();
    
    Card& getCurrentCard();
    
    
    
    

private:
    std::list<Card> cardList;
    std::list<Card>::iterator cardPos;
};
#endif /* Rolodex_h */
