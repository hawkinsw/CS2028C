#include <iostream>
#include "include/cardnale.hpp"

int main() {
    List<Card> lc{};

    lc.add(Card{4, "Hearts"});
    lc.add(Card{1, "Spade"});
    lc.add(Card{2, "Club"});
    lc.add(Card{12, "Diamonds"});

    std::cout << "Printing the linked list with four (4) cards:\n";
    std::cout << lc << "\n";

    std::cout << "Removing the 4 of Hearts:\n";
    lc.remove(Card{4, "Hearts"});

    std::cout << "Printing the linked list with three (3) cards:\n";
    std::cout << lc << "\n";

    std::cout << "Removing the 2 of Clubs:\n";
    lc.remove(Card{2, "Club"});

    std::cout << "Printing the linked list with two (2) cards:\n";
    std::cout << lc << "\n";

    std::cout << "Removing the 12 of Diamonds:\n";
    lc.remove(Card{12, "Diamonds"});

    std::cout << "Printing the linked list with one (1) card:\n";
    std::cout << lc << "\n";

    std::cout << "Removing the 1 of Spades:\n";
    lc.remove(Card{1, "Spade"});

    std::cout << "Printing the linked list with zero (0) cards:\n";
    std::cout << lc << "\n";

    lc.remove(Card{18, "Spade"});
    return 0;
}
