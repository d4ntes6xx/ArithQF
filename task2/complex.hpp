#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
private:
    double real;
    double imaginary;
    
public:
    Complex(double re = 0.0, double im = 0.0);
    Complex(const Complex& other);
    ~Complex();
    
    Complex& operator=(const Complex& other);
    
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
    
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    
    Complex operator-() const;
    Complex operator+() const;
    
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);
    
    double magnitude() const;
    Complex conjugate() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Complex& comp);
    friend std::istream& operator>>(std::istream& is, Complex& comp);
};

#endif