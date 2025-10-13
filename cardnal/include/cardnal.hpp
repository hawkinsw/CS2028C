#ifndef __FRAME_HPP
#define __FRAME_HPP

#include <iostream>
#include <string>

class Card {
    public:
        /** Construct a playing card with no value and no suit.
         */
        Card(): m_value(0), m_suit("NA") {}
        /** Construct a playing card with a set value and suit.
         */
        Card(int value, std::string suit): m_value(value), m_suit(suit) {}

        /** Update the value of the card's value.
         */
        void setValue(int value) {
            m_value = value;
        }

        /** Update the value of the card's suit.
         */
        void setSuit(const std::string &suit) {
            m_suit = suit;
        }

        /** Get the card's value.
         */
        int getValue() const {
            return m_value;
        }

        /** Get the card's suit.
         */
        std::string getSuit() const {
            return m_suit;
        }

    private:
        std::string m_suit;
        int m_value;
};


std::ostream &operator<<(std::ostream &os, const Card &card) {
    if (card.getValue() == 0) {
        os << "Default card.";
        return os;
    }
    os << "Card: value: " << card.getValue() << "; suit: " << card.getSuit();

    return os;
}

template <typename ValueType>
class Node {
    public:
        ValueType value;
        Node *next;
};

#endif