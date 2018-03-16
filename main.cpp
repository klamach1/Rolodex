#include <iostream>

#include "Card.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Card firstCard;

    Card secondCard;

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


    return 0;
}