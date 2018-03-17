//
//  Rolodex.h
//  Rolodex
//
//  Created by Chris Lawrence on 3/16/18.
//  Copyright © 2018 Chris Lawrence. All rights reserved.
//

#ifndef Rolodex_h
#define Rolodex_h

#include <list>
#include "Card.h"

class Rolodex {
public:
    
    Rolodex();
    
    void add(const Card&);
    
    Card remove();
    
    const Card getCurrentCard();
    
    const Card flip();
    
    //last name, first name
    bool search(const string&, const string&);
    
    void show(ostream& os);
    
    

private:
    std::list<Card> cardList;
    std::list<Card>::iterator cardPos;
};
#endif /* Rolodex_h */
