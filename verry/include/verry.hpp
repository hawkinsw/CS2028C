#ifndef _VERRY_HPP
#define _VERRY_HPP

template <typename T>
class Verry;

template <typename T>
std::ostream &operator<<(std::ostream &os, const Verry<T> &v);

template <typename T>
class Verry
{
public:
    Verry() : m_size(0), m_data{nullptr} {}

    int size() const {
        return m_size;
    }

    void push_back(T new_value) {
        // 1. Allocate enough space for the existing elements _and_
        // the new_value.
        T *new_data = new T[m_size + 1];

        // 2. Copy the existing elements from m_data to new_data.
        for (auto i{0}; i < m_size; i++) {
            new_data[i] = m_data[i];
        }

        // 3. Add new_value to new_data.
        new_data[m_size] = new_value;

        // 4. Release the existing, too-small storage back to the
        // OS for reuse.
        delete[] m_data;

        // 5. Track new_data as the place where existing elements
        // are to prepare for when we push_back the next time.
        m_data = new_data;

        // 6. Record that there is one more value in our verry.
        m_size++;
    }

    ~Verry() {
        delete[] m_data;
        m_size = 0;
    }

    friend std::ostream& operator<< <> (std::ostream& out, const Verry<T> &v);
private:
    int m_size;
    T *m_data;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Verry<T> &v) {
    for (auto i = 0; i < v.m_size; i++) {
        std::cout << i << ": " << v.m_data[i] << ", ";
    }
    return os;
}
#endif