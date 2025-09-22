#include <iostream>
#include <vector>

// See 
// https://godbolt.org/z/vcW7aqTc8
// for running example. See
// https://cppinsights.io/s/bb69919d
// for demonstration of the work of the compiler on the templates.

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

  bool isFresh() const { return m_is_veggie; }

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

template <typename ContentsType>
class Tupperware {
public:
  Tupperware(const ContentsType food) : m_food(food) {}
  bool contentsEdible() { return m_food.isFresh(); }

private:
  ContentsType m_food;
};

template <typename T>
bool eat_whats_inside(const Tupperware<T> &t) {
    return t.contentsEdible();
}

int main() {

  Slice s{{"Pineapple", "Cheese", "Cheese", "More Cheese"}};
  FriedRice chicken_fr{false}; // Not vegetable fried rice!
  FriedRice veggie_fr{true}; // Vegetable fried rice!

  Tupperware<Slice> tupperware{s};
  Tupperware<FriedRice> chinese_tupperware{chicken_fr};

  // Because Slices are always fresh (see line 8), these
  // contents are always going to be edible.
  if (tupperware.contentsEdible()) {
    std::cout << "The contents are edible ... yum.\n";
  } else {
    std::cout << "The contents are not edible ... blah.\n";
  }

  // Because FriedRice lefovers are fresh depending
  // on whether they are veggie-based (see line 18),
  // these contents are sometimes going to be edible.
  if (chinese_tupperware.contentsEdible()) {
    std::cout << "The Chinese leftovers are edible ... yum.\n";
  } else {
    std::cout << "The Chinese leftovers are not edible ... blah.\n";
  }

  // Does this print the same thing?
  chinese_tupperware = Tupperware<FriedRice>(veggie_fr);
  if (chinese_tupperware.contentsEdible()) {
    std::cout << "The Chinese leftovers are edible ... yum.\n";
  } else {
    std::cout << "The Chinese leftovers are not edible ... blah.\n";
  }

  return 0;
}
