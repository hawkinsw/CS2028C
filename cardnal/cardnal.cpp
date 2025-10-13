#include <iostream>
#include "include/cardnal.hpp"

int main() {

    // In the parlance of a linked list, the pointer to the node
    // at the start of the list is usually called head. Let's get
    // a pointer to enough space to hold a node that holds the first
    // card in the hand.
    Node<Card> *head = new Node<Card>{};
    head->value = Card(2, "Club");
    head->next = nullptr;

    // Let's add a node to the end of the list that will hold the
    // 5 of Spades.
    head->next = new Node<Card>{};
    head->next->value = Card(5, "Spade");
    // Because the new node that we just added to the linked list
    // is the last node in the list, we _should_ set its' next
    // pointer to nullptr so that it gives us a signal that there
    // are no more nodes. But, the code above (on line 16) has
    // already accomplished this feat. Do you know why?

    // The list currently has two elements. The _head_ of the list
    // is the node that holds the 2 of Clubs. The node in the list
    // that comes next after the node at the head of the list holds
    // the 5 of Spades.

    // To see that, we will traverse the list and print out the value
    // of each of the nodes.
    // We do not want to lose track of the head of the list as we walk
    // from node to node. Therefore, we will need to use another pointer
    // to keep track of the nodes that we visit. Programmers commonly
    // name the variable used in this manner the iterator.
    auto iterator = head;
    while (iterator) {
        std::cout << iterator->value << "\n";
        iterator = iterator->next;
    }

    // Create a node to hold the 8 of Hearts ...
    auto t = new Node<Card>{};
    t->value = Card(8, "Heart");


    // ... and insert it _after_ the first card in the list.
    t->next = head->next;
    head->next = t;
    // Notice how it will always take two operations to insert
    // a new element into a linked list ... no matter how many
    // other elements there are in the list. That seems much
    // faster than the process of insertion when we represented
    // a hand of cards using a dynamically allocated array!


    // To see that we did the insert correctly, we will traverse
    // the list and print out the value of each of the nodes.
    std::cout << "The contents of the list after inserting the 8 of Hearts:\n";
    iterator = head;
    while (iterator) {
        std::cout << iterator->value << "\n";
        iterator = iterator->next;
    }

    // Now, let's walk the list and free the linked list.
    iterator = head;
    while (iterator) {

        // We will need to hold on to the "current" node ...
        auto temp = iterator;
        // ... so that we can move to the next node before ...
        iterator = iterator->next;
        // ... deleting it. If we waited until "after" deleting
        // the node in order to find the next one, we would be
        // using memory after freeing it -- a bad thing!
        delete temp;
    }

    return 0;
}