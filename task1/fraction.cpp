#include "fraction.hpp"
#include <stdexcept>
#include <cmath>

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    reduce();
}

Fraction::Fraction(const Fraction& other) 
    : numerator(other.numerator), denominator(other.denominator) {
}

Fraction::~Fraction() {}

int Fraction::gcd(int a, int b) const {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    
    int common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;
}

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

Fraction Fraction::operator+(const Fraction& other) const {
    int new_num = numerator * other.denominator + other.numerator * denominator;
    int new_den = denominator * other.denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int new_num = numerator * other.denominator - other.numerator * denominator;
    int new_den = denominator * other.denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int new_num = numerator * other.numerator;
    int new_den = denominator * other.denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    int new_num = numerator * other.denominator;
    int new_den = denominator * other.numerator;
    return Fraction(new_num, new_den);
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator>(const Fraction& other) const {
    return other < *this;
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(other < *this);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

Fraction Fraction::operator-() const {
    return Fraction(-numerator, denominator);
}

Fraction Fraction::operator+() const {
    return *this;
}

Fraction& Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    *this = *this - other;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    *this = *this * other;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    *this = *this / other;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    if (frac.denominator == 1) {
        os << frac.numerator;
    } else {
        os << frac.numerator << "/" << frac.denominator;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& frac) {
    char slash;
    is >> frac.numerator >> slash >> frac.denominator;
    if (frac.denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    frac.reduce();
    return is;
}

Fraction::operator double() const {
    return static_cast<double>(numerator) / denominator;
}