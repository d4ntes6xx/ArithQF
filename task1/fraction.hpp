#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;
    
    int gcd(int a, int b) const;
    void reduce();
    
public:
    Fraction(int num = 0, int den = 1);
    Fraction(const Fraction& other);
    ~Fraction(); 

    Fraction& operator=(const Fraction& other);

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
    
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    
    Fraction operator-() const;
    Fraction operator+() const;
    
    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);
    
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
    friend std::istream& operator>>(std::istream& is, Fraction& frac);
    
    operator double() const;
};

#endif