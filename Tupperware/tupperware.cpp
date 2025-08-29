#include <iostream>
#include <vector>

class Slice {
public:
  Slice(std::vector<std::string> toppings) : m_toppings(toppings) {}

  bool isFresh() const { return true; }

private:
  std::vector<std::string> m_toppings;
};

class PizzaContainer {
public:
  PizzaContainer(const Slice s) : m_s(s) {}
  bool contentsEdible() {
    return m_s.isFresh();
  }

private:
  Slice m_s;
};

bool eat_whats_inside(const PizzaContainer &t) { return true; }

int main() {

    Slice s{{"Pineapple", "Cheese", "Cheese", "More Cheese"}};

    PizzaContainer tupperware{s};

    if (tupperware.contentsEdible()) {
        std::cout << "The contents are edible ... yum.\n";
    } else {
        std::cout << "The contents are not edible ... blah.\n";
    }
    return 0;
}