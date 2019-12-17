#pragma once

#include <cmath>
#include <iostream>
#include "config.h"

namespace lr6 {
    /**
     * Double - primitive double data type wrapper
     */
    class Double {
    public:
        Double() {}
        Double(double value) : value(value) {}

        bool operator==(const Double &other) const;

        Double &operator*=(const Double &other);

        Double operator-() const;
        Double operator-(const Double &other) const;
        Double operator+(const Double &other) const;
        Double operator*(const Double &other) const;
        Double operator/(const Double &other) const;

        bool operator<(const Double &other) const;
        bool operator>(const Double &other) const;

        /**
         * Exponentiation operator
         * @param exponent
         * @return pow(value, exponent)
         */
        Double operator^(const Double &exponent) const;

        double value = 0;
    };

    Double abs(const Double &num);
    std::istream& operator>>(std::istream& stream, Double& num);
    std::ostream& operator<<(std::ostream& stream, const Double& num);

    int to_integer(const Double &num);
}