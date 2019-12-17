#include <sstream>

#include "double.h"

using namespace lr6;

bool Double::operator==(const Double &other) const {
    return abs(*this - other).value < EPSILON;
}

Double Double::operator-(const Double &other) const {
    return {value - other.value};
}

Double Double::operator-() const {
    return {-this->value};
}

Double Double::operator+(const Double &other) const {
    return {value + other.value};
}

Double Double::operator*(const Double &other) const {
    return {value * other.value};
}

Double Double::operator^(const Double &exponent) const {
    return {pow(value, exponent.value)};
}

Double Double::operator/(const Double &other) const {
    return {value / other.value};
}

Double &Double::operator*=(const Double &other) {
    return (*this = *this * other);
}

bool Double::operator<(const Double &other) const {
    return value < other.value;
}

bool Double::operator>(const Double &other) const {
    return value > other.value;
}

Double lr6::abs(const Double &num) {
    return {fabs(num.value)};
}

std::istream &lr6::operator>>(std::istream &stream, Double &num) {
    stream >> num.value;
    return stream;
}

std::ostream &lr6::operator<<(std::ostream &stream, const Double &num) {
    stream << num.value;
    return stream;
}

int lr6::to_integer(const Double &num) {
    return (int) num.value;
}
