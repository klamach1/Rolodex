#include <iostream>

#include "Card.h"
#include "Rolodex.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Card firstCard;

    Card secondCard;
    
    Rolodex rolo;

    firstCard.setLastName("Young");
    secondCard.setLastName("Young");

    firstCard.setFirstName("ZzAbe");
    secondCard.setFirstName("Zack");

    if (firstCard < secondCard) {
        std::cout << "Less than" << std::endl;
    }
    else {
        std::cout << "Not less than" << std::endl;
    }

    rolo.add(Card("Tony", "Hansen", "Writer", "12 E. St. NY, NY 33333", "555-9999"));
    rolo.add(Card("Jon", "Smyth", "Computer Hardware", "CMU Computer Services Pittsburgh, PA", "555-1324"));
    rolo.add(Card("Alonza", "Heard", "Mechanic",  "123 Anyplace Ave Malden, MA", "555-5678"));
    rolo.add(Card("Jen", "Reyes", "Graphic artist", "325 Oak Rd Wilmington, MA", "555-4950"));
    rolo.add(Card("Alan", "Lupine", "Vet", "1 Bigelow Ave. Lawrence, MA", "555-7654"));
    rolo.add(Card("Jewel", "Proverb", "Landscaper", "34 Washington St. Waltham, MA", "555-3333"));
    rolo.add(Card("Paul", "Revere", "Radical Revolutionary", "45 Commonwealth Ave. Boston, MA", "555-1776"));
    rolo.add(Card("Adolf", "Coors", "Beer Manufacturer", "Boston MA", "555-2337"));
    rolo.add(Card("Seymour", "Papert", "Lego Professor", "MIT", "555-1111"));
    rolo.add(Card("Fred", "Milton",    "Sales", "12 Freedom Way Nashua, NH", "555-9981"));
    
    Card currentCard = rolo.getCurrentCard();
    
    ostream &os = cout;
    

    currentCard.show(os);
    
    
    
    
    

    return 0;
}
