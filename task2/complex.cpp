#include "complex.hpp"
#include <stdexcept>
#include <cmath>

Complex::Complex(double re, double im) : real(re), imaginary(im) {}

Complex::Complex(const Complex& other) 
    : real(other.real), imaginary(other.imaginary) {}

Complex::~Complex() {}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real = other.real;
        imaginary = other.imaginary;
    }
    return *this;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

Complex Complex::operator*(const Complex& other) const {
    double re = real * other.real - imaginary * other.imaginary;
    double im = real * other.imaginary + imaginary * other.real;
    return Complex(re, im);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero complex number");
    }
    
    double re = (real * other.real + imaginary * other.imaginary) / denominator;
    double im = (imaginary * other.real - real * other.imaginary) / denominator;
    return Complex(re, im);
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imaginary == other.imaginary;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

Complex Complex::operator-() const {
    return Complex(-real, -imaginary);
}

Complex Complex::operator+() const {
    return *this;
}

Complex& Complex::operator+=(const Complex& other) {
    *this = *this + other;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    *this = *this - other;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    *this = *this * other;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    *this = *this / other;
    return *this;
}

double Complex::magnitude() const {
    return std::sqrt(real * real + imaginary * imaginary);
}

Complex Complex::conjugate() const {
    return Complex(real, -imaginary);
}

std::ostream& operator<<(std::ostream& os, const Complex& comp) {
    if (comp.imaginary == 0) {
        os << comp.real;
    } else if (comp.real == 0) {
        os << comp.imaginary << "i";
    } else if (comp.imaginary > 0) {
        os << comp.real << " + " << comp.imaginary << "i";
    } else {
        os << comp.real << " - " << -comp.imaginary << "i";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Complex& comp) {
    char plus, i;
    is >> comp.real >> plus >> comp.imaginary >> i;
    
    if (plus == '-' && i == 'i') {
        comp.imaginary = -comp.imaginary;
    } else if (plus != '+' || i != 'i') {
        is.setstate(std::ios::failbit);
    }
    
    return is;
}