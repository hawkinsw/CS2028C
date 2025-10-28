#ifndef __STACK_HPP
#define __STACK_HPP

// Uncomment the std::cout's (throughout) to get some
// helpful feedback on the behavior of the stack
// implementation as elements are pushed and popped
// and peeked.

#include <iostream>
#include <string>

class invalid_pop_error : public std::logic_error {
 public:
  invalid_pop_error(const std::string& message) : std::logic_error(message) {}
};

class invalid_peek_error : public std::logic_error {
 public:
  invalid_peek_error(const std::string& message) : std::logic_error(message) {}
};

template <typename ValueType>
class Stack {
 public:
  void push(const ValueType& v) {
    /*
    std::cout << "Pushing " << v << " onto a stack with size "
              << m_size << " and capacity " << m_capacity << ".\n";
    */

    // When there is space for the new element within the
    // capacity, we don't need to reallocate more!
    if (m_size < m_capacity) {
      m_data[m_size] = v;
      m_size++;
      return;
    }

    // We are stuck -- no more capacity. We have to make more.
    ValueType* new_data = new ValueType[m_size + 1];

    for (auto i{0}; i < m_size; i++) {
      new_data[i] = m_data[i];
    }

    new_data[m_size] = v;

    delete[] m_data;

    m_data = new_data;

    m_size++;
    m_capacity++;
  }

  ValueType pop() {
    /*
    std::cout << "Popping from a stack with size " << m_size << " and capacity "
              << m_capacity << ".\n";
    */
    if (!m_size) {
      // throw an exception.
      throw invalid_pop_error("No element on the stack to pop.");
    }
    m_size--;

    return m_data[m_size];
  }

  ValueType peek() {
    /*
    std::cout << "Peeking into a stack with size " << m_size << " and capacity "
              << m_capacity << ".\n";
    */
    if (!m_size) {
      throw invalid_peek_error("No element on the stack to peek.");
    }

    return m_data[m_size];
  }

 private:
  ValueType* m_data{};
  int m_size{};
  int m_capacity{};
};

#endif
