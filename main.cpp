//
// main.cpp
// Created by Chris Lawrence 3/10/18
//
// this module presents the user interface
// to a Rolodex.  It creates a Rolodex object
// and loads the initial data set.  It then presents an
// interactive menu that allows the user to
// view the current card, flip to the next card and view,
// list the entire contents ofd the Rolodex, add a new Card,
// remove the current card, and search for a card by first and
// last name.


#include <iostream>
#include <sstream>

#include "Card.h"
#include "Rolodex.h"

//menu function prototypes
//see definitions for comments
void view(Rolodex& rolo, ostream& os);
void listRolodex(Rolodex& rolo, ostream& os);
void flip(Rolodex& rolo, ostream& os);
void add(Rolodex& rolo);
void remove(Rolodex& rolo, ostream& os);
void search(Rolodex& rolo, ostream& os);
void loadData(Rolodex& rolo);


int main() {

	ostringstream osMenu;
	string menuDisplay;
    int menuInput = -1;
    //set our menu size
    const int menuSize = 7;
    
    Rolodex rolo;

    //output stream tied to console out for display
    ostream &os = std::cout;
    
    //load the default data
    loadData(rolo);
    
    //quit will always be the last command in the menu
    string menuCommands[] = {"List", "View", "Flip", "Add", "Remove", "Search", "Quit"};
    
	for (int i = 0; i < menuSize; ++i) {
		osMenu << i << " - " << menuCommands[i] << endl;
	}

	menuDisplay = osMenu.str();

    //greet the user
    std::cout << "Hello Rolodex User - Please choose a command by typing the number:" << std::endl;
    
    //display the menu and prompts for entry
    while (menuInput != menuSize-1) {


		std::cout << menuDisplay;
        std::cout << "Enter your choice:" << endl;
		std::cin >> menuInput;

			//clear the newline to prevent unexpected menu command behavior
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

//load the default data into the Rolodex
//this function could be refactored later to support file-based storage
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

//function to view the current card in the Rolodex
//takes the Rolodex and output stream by reference
void view(Rolodex& rolo, ostream& os) {

    Card currentCard = rolo.getCurrentCard();
    
    currentCard.show(os);
    
}

//function to list the contents of the Rolodex
//takes the Rolodex and output stream by reference
void listRolodex(Rolodex& rolo, ostream& os) {
    
    rolo.show(os);
    
}

//function to move to the next card and display it
//takes the Rolodex and output stream by reference
void flip(Rolodex& rolo, ostream& os) {
    
    Card currentCard = rolo.flip();
        
    currentCard.show(os);
    
}

//function to add new card by collecting user input
//takes the Rolodex by reference
//uses std::getline to capture full line input as a single string
void add(Rolodex& rolo) {
    string response;
    Card newCard = Card();
    std::cout << "Please enter the first name:" << endl;
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


//function to remove current card
//takes the Rolodex and outputstream by reference
//displays the current card and prompts the user
//for confirmation
//if affirmative confirmation is not received, card is not removed
//takes the Rolodex by reference
void remove(Rolodex& rolo, ostream& os) {
    
    char input;
    
	//output the current card
	view(rolo, os);
	
	//confirm removal
	std::cout << "Are you sure you want to remove this card (y/N)?"  << endl;

    std::cin >> input;
    
    if (input == 'y' || input == 'Y') {
        rolo.remove();
        std::cout << "Card removed" << endl;
    }
    else {
        std::cout << "Card not removed" << endl;
    }
}
    

void search(Rolodex& rolo, ostream& os) {

    bool found = false;
    string name[2];
	std::cout << "Enter a first name and last name to search" << endl;
    
	std::cin >> name[0];
	std::cin >> name[1];
    
    found = rolo.search(name[1], name[0]);
    Card currentCard;
    
    if (found) {
        //output the current card
        view(rolo, os);
		std::cout << endl;
	}
	else {
		std::cout << "Card not found" << endl;
	}
}
    

    
    


