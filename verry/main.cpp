#include <iostream>
#include <vector>
#include "verry.hpp"

int main() {
    Verry<int> v{};

    v.push_back(41);
    v.push_back(39);
    v.push_back(18);
    v.push_back(12);
    v.push_back(32);

    std::cout << "v: " << v << "\n";

    return 0;
}