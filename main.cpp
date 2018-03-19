#include <iostream>

#include "Card.h"
#include "Rolodex.h"

//menu function prototypes
void view(Rolodex& rolo);
void listRolodex(Rolodex& rolo);
void flip(Rolodex& rolo);
void add(Rolodex& rolo);
void remove(Rolodex& rolo);
void search(Rolodex& rolo);
void loadData(Rolodex& rolo);


int main() {
    
    int menuInput = 0;
    const int menuSize = 7;
    
    Rolodex rolo;
    
    loadData(rolo);
    
    //quit will always be the last command in the menu
    string menuCommands[] = {"List", "View", "Flip", "Add", "Remove", "Search", "Quit"};
    
    std::cout << "Hello Rolodex User - Please choose a command by typing the number:" << std::endl;
    
    //quit will always be the last command in the menu
    while (menuInput != menuSize-1) {
        for (int i = 0; i < menuSize; ++i) {
            std::cout << i << " - " << menuCommands[i] << std::endl;
        }
        
        std::cout << "Enter your choice:";
        std::cin >> menuInput;
        
        switch (menuInput) {
            case 0:
                listRolodex(rolo);
                break;
            case 1:
                view(rolo);
                break;
            case 2:
                flip(rolo);
                break;
            case 3:
                add(rolo);
                break;
            case 4:
                remove(rolo);
                break;
            case 5:
                search(rolo);
                break;
            case 6:
                return 0;
            default:
                break;
        }


    }
    
    return 0;
}

void loadData(Rolodex& rolo) {
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
}

void view(Rolodex& rolo) {
    
    ostream &os = cout;

    Card currentCard = rolo.getCurrentCard();
    
    currentCard.show(os);
    
}

void listRolodex(Rolodex& rolo) {
    
    ostream &os = cout;
    
    rolo.show(os);
    
}

void flip(Rolodex& rolo) {
    
    ostream &os = cout;
    
    //Card myCard;
    
    Card currentCard = rolo.flip();
        
    currentCard.show(os);
    
}

void add(Rolodex& rolo) {
    std::cout << "Feature coming soon" << endl;
}

void remove(Rolodex& rolo) {
    
    char input;
    
    std::cout << "Are you sure you want to remove this card (y/N)?"  << endl;
    
    ostream &os = cout;
    
    Card currentCard = rolo.getCurrentCard();
    
    currentCard.show(os);
    
    std::cin >> input;
    
    if (input == 'y' || input == 'Y') {
        rolo.remove();
        std::cout << "Card removed";
    }
    else {
        std::cout << "Card not removed";
    }
}
    

void search(Rolodex& rolo) {
    
    ostream &os = cout;
    bool found = false;
    found = rolo.search("Pipisquee", "Fernando");
    Card currentCard;
    
    if (found) {
        cout << "found" << endl;
        currentCard = rolo.getCurrentCard();
        currentCard.show(os);
        cout << endl;
    }
}
    

    
    


