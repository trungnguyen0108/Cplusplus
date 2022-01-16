#pragma once
#include <fstream>
#include <algorithm>
#include <iostream>
#include <exception>

class Fraction
{
private:
    int num;
    int den;
public:
    Fraction();
    Fraction(int, int);
    Fraction(int);

    Fraction operator+(const Fraction &) const;
    Fraction operator-(const Fraction &) const;
    Fraction operator*(const Fraction &) const;
    Fraction operator/(const Fraction &) const;

    Fraction& operator+=(const Fraction &fraction);
    Fraction& operator-=(const Fraction &fraction);
    Fraction& operator*=(const Fraction &fraction);
    Fraction& operator/=(const Fraction &fraction);

    Fraction& operator++();  
    Fraction& operator--();  
    Fraction operator++(int);  
    Fraction operator--(int);

    operator double() const;

    void Compact();
    void Set(int, int);
    std::string ToString() const;
};

std::ostream& operator<<(std::ostream&, const Fraction&);
std::istream& operator>>(std::istream&, Fraction&);
