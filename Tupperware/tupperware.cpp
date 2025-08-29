#include <iostream>
#include <vector>

class Slice {
public:
  Slice(std::vector<std::string> toppings) : m_toppings(toppings) {}

  bool isFresh() const { return true; }

private:
  std::vector<std::string> m_toppings;
};

class FriedRice {
public:
  FriedRice(bool is_veggie) : m_is_veggie(is_veggie) {}

  bool isFresh() const { return false; }

private:
  bool m_is_veggie;
};

class PizzaTupperware {
public:
  PizzaTupperware(const Slice food) : m_food(food) {}
  bool contentsEdible() { return m_food.isFresh(); }

private:
  Slice m_food;
};

class ChineseTupperware {
public:
  ChineseTupperware(const FriedRice food) : m_food(food) {}
bool m_is_veggie;
  bool contentsEdible() { return m_food.isFresh(); }

private:
  FriedRice m_food;
};

bool eat_whats_inside(const PizzaTupperware &t) { return true; }

int main() {

  Slice s{{"Pineapple", "Cheese", "Cheese", "More Cheese"}};

  PizzaTupperware tupperware{s};

  if (tupperware.contentsEdible()) {
    std::cout << "The contents are edible ... yum.\n";
  } else {
    std::cout << "The contents are not edible ... blah.\n";
  }
  return 0;
}