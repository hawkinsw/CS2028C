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

        bool operator==(const Card &other) {
            return other.getValue() == getValue() && other.getSuit() == getSuit();
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
struct Node {
        ValueType value;
        Node *next;
};

template <typename ValueType>
class List;

template <typename V>
std::ostream &operator<<(std::ostream &os, const List<V> list);

template <typename ValueType>
class List {
    public:
        void add(const ValueType &v)  {
            // We are going to add to the front.

            Node<ValueType> *newnode = new Node<ValueType>{};
            newnode->value = v;

            newnode->next = m_head;
            m_head = newnode;
        }

        void remove(const ValueType &v)  {
            auto iterator = m_head;

            if (!iterator) {
                return;
            }

            // When removing nodes from the linked list, it's oftentimes
            // nice to treat the head as a special case. There _are_ ways
            // to write code to delete a node where the head is not treated
            // as a special case, but ...
            if (iterator->value == v) {
                m_head = iterator->next;
                delete iterator;
                return;
            }

            // Because we can assume that iterator is not null, we can immediately
            // use it to access it's next member. Why are we concerned about finding
            // the node who's _next_ contains the value that we want to delete?
            while (iterator->next) {
                if (iterator->next->value != v) {
                    iterator = iterator->next;
                    continue;
                }

                auto to_delete = iterator->next;
                iterator->next = iterator->next->next;
                delete to_delete;
                return;
            }
        }

        template <typename V>
        friend std::ostream &operator<<(std::ostream &os, const List<V> list);

    
    private:
        Node<ValueType> *m_head;
};

template <typename ValueType>
std::ostream &operator<<(std::ostream &os, const List<ValueType> list) {
    for (auto iterator{list.m_head}; iterator; iterator = iterator->next) {
        os << iterator->value << " -- ";
    }
    return os;
}
#endif