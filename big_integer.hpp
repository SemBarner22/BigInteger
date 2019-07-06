#include <iostream>
#include <vector>

class big_integer {
public:
    big_integer(bool, std::vector<uint64_t>&);
    big_integer(const big_integer &) = default;
    big_integer(const std::string &);
    big_integer(uint64_t);
    big_integer() = default;
    ~big_integer() = default;

    big_integer& operator+=(const big_integer&);
    big_integer& operator-=(const big_integer&);
    big_integer& operator*=(const big_integer&);
    big_integer& operator/=(const big_integer&);
    big_integer& operator=(const big_integer&);

    big_integer& operator++();
    big_integer& operator--();
    big_integer& operator++(int);
    big_integer& operator--(int);

    friend big_integer operator+(const big_integer&, const big_integer&);
    friend big_integer operator-(const big_integer&, const big_integer&);
    friend big_integer operator/(const big_integer&, const big_integer&);
    friend big_integer operator*(const big_integer&, const big_integer&);

    friend bool operator<(const big_integer&, const big_integer&);
    friend bool operator>(const big_integer&, const big_integer&);
    friend bool operator<=(const big_integer&, const big_integer&);
    friend bool operator>=(const big_integer&, const big_integer&);
    friend bool operator==(const big_integer&, const big_integer&);
    friend bool operator!=(const big_integer&, const big_integer&);

    friend std::ostream& operator<<(std::ostream&, const big_integer&);
    friend std::istream& operator>>(std::istream&, big_integer&);

    big_integer& operator<<=(size_t);
    friend big_integer operator<<(const big_integer&, size_t);
    big_integer& operator>>=(size_t);
    friend big_integer operator>>(const big_integer&, size_t);

    friend std::string to_string(const big_integer&);
    bool is_zero() const;

private:
    bool sign = 0;
    std::vector<uint64_t> number;

    void _add(const big_integer &);
};
