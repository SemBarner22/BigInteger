//
// Created by User on 06.07.2019.
//
#include "big_integer.hpp"

big_integer& big_integer::operator+=(const big_integer &other) {
    if (this->sign && other.sign) {
        _add(other);
    }
    if (!this->sign && other.sign) {

    }
    if (this->sign && !other.sign) {

    }
    if (!this->sign && !other.sign) {

    }
    return *this;
}

big_integer& big_integer::operator++() {
    return *this;
}

big_integer operator+(const big_integer & a, const big_integer &) {
    return a;
}

big_integer::big_integer(bool s, std::vector<uint64_t> & v) {
    this->sign = s;
    this->number = v;
}

void big_integer::_add(const big_integer &other) {
    size_t a = this->number.size();
    size_t b = other.number.size();
    for (size_t i = 0; i < std::min(a, b); ++i) {
        this->number[i] += other.number[i];
    }
    if (a < b) {
        for (size_t j = std::min(a, b); j < b; ++j) {
            this->number[j] = other.number[j];
        }
    }
}

big_integer::big_integer(const std::string & s) {
    if (s[0] == '-') {
        this->sign = true;
    }
    for (size_t )
}
