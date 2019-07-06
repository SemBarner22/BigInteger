#include <iostream>
#include "big_integer.hpp"

int main() {
    std::vector<uint64_t> a;
    a.push_back(345);
    std::vector<uint64_t> b;
    b.push_back(758);
    big_integer f = big_integer(0, a);
    big_integer s = big_integer(0, b);
    f += s;

    return 0;
}