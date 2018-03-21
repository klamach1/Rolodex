#include <iostream>

#include "Card.h"
#include "Rolodex.h"

//menu function prototypes
void view(Rolodex& rolo, ostream& os);
void listRolodex(Rolodex& rolo, ostream& os);
void flip(Rolodex& rolo, ostream& os);
void add(Rolodex& rolo);
void remove(Rolodex& rolo, ostream& os);
void search(Rolodex& rolo, ostream& os);
void loadData(Rolodex& rolo);


int main() {
    
    int menuInput = 0;
    const int menuSize = 7;
    
    Rolodex rolo;
    
    ostream &os = cout;
    
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
        std::cin.get();
        
        switch (menuInput) {
            case 0:
                listRolodex(rolo, os);
                break;
            case 1:
                view(rolo, os);
                break;
            case 2:
                flip(rolo, os);
                break;
            case 3:
                add(rolo);
                break;
            case 4:
                remove(rolo, os);
                break;
            case 5:
                search(rolo, os);
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

void view(Rolodex& rolo, ostream& os) {

    Card currentCard = rolo.getCurrentCard();
    
    currentCard.show(os);
    
}

void listRolodex(Rolodex& rolo, ostream& os) {
    
    rolo.show(os);
    
}

void flip(Rolodex& rolo, ostream& os) {
    
    Card currentCard = rolo.flip();
        
    currentCard.show(os);
    
}

void add(Rolodex& rolo) {
    string response;
    Card newCard = Card();
    std::cout << "Please enter the last name:" << endl;
    std::getline(std::cin, response);
    newCard.setFirstName(response);
    std::cout << "Please enter the last name:" << endl;
    std::getline(std::cin, response);
    newCard.setLastName(response);
    std::cout << "Please enter the address:" << endl;
    std::getline(std::cin, response);
    newCard.setAddress(response);
    std::cout << "Please enter the occupation:" << endl;
    std::getline(std::cin, response);
    newCard.setOccupation(response);
    std::cout << "Please enter the phone number (xxx) xxx-xxxx:" << endl;
    std::getline(std::cin, response);
    newCard.setPhoneNumber(response);
    rolo.add(newCard);
    std::cout << "Card added" << endl;
}



void remove(Rolodex& rolo, ostream& os) {
    
    char input;
    
    std::cout << "Are you sure you want to remove this card (y/N)?"  << endl;
    
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
    

void search(Rolodex& rolo, ostream& os) {

    bool found = false;
    string name[2];
    cout << "Enter a first naee and last name to search" << endl;
    
    cin >> name[0];
    cin >> name[1];
    
    found = rolo.search(name[1], name[0]);
    Card currentCard;
    
    if (found) {
        cout << "found" << endl;
        currentCard = rolo.getCurrentCard();
        currentCard.show(os);
        cout << endl;
    }
}
    

    
    


