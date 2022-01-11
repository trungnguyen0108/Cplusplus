#pragma once
#include <fstream>

class Fraction
{
private:
    int num;
    int den;
public:
    Fraction();
    Fraction(int num, int den);

    void Compact();
    Fraction operator+(const Fraction &);
    Fraction operator-(const Fraction &);
    Fraction operator*(const Fraction &);
    Fraction operator/(const Fraction &);

    Fraction operator+=(const Fraction &fraction);
    Fraction operator-=(const Fraction &fraction);
    Fraction operator*=(const Fraction &fraction);
    Fraction operator/=(const Fraction &fraction);

    Fraction operator++();  
    Fraction operator--();  
    Fraction operator++(int);  
    Fraction operator--(int);    

    bool operator>(const Fraction &fraction);
    bool operator<(const Fraction &fraction);
    bool operator==(const Fraction &fraction);
    bool operator!=(const Fraction &fraction);

    std::string ToString() const;
};

std::ostream &operator<<(std::ostream &outStream, const Fraction &fraction);
