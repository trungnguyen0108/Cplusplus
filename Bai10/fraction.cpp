#include "fraction.hpp"

Fraction::Fraction()
{
    num = 0;
    den = 1;
}

Fraction::Fraction(int num, int den)
{
    if (den == 0)
        throw new std::invalid_argument("Denominator cannot be zero");
    
    this->num = num;
    this->den = den;
    Compact();
}

Fraction::Fraction(int number) 
{
    num = number;
    den = 1;
}

Fraction Fraction::operator+(const Fraction &fraction) const
{
    return {num * fraction.den + den * fraction.num, den * fraction.den};
}

Fraction Fraction::operator-(const Fraction &fraction) const
{
    return {num * fraction.den - den * fraction.num, den * fraction.den};
}

Fraction Fraction::operator*(const Fraction &fraction) const
{
    return {num * fraction.num, den * fraction.den};
}

Fraction Fraction::operator/(const Fraction &fraction) const
{
    return {num * fraction.den, den * fraction.num};
}

Fraction& Fraction::operator+=(const Fraction &fraction)
{
    num = num * fraction.den + den * fraction.num;
    den = den + fraction.den;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction &fraction)
{
    num = num * fraction.den - den * fraction.num;
    den = den + fraction.den;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction &fraction)
{
    num = num * fraction.num;
    den = this->den * fraction.den;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction &fraction)
{
    num = num * fraction.den;
    den = this->den * fraction.num;
    return *this;
    return *this;
}

Fraction& Fraction::operator++()
{
    num = num + den;
    den = den * 1;
    return *this;
}

Fraction& Fraction::operator--()
{
    num = num - den;
    den = den * 1;
    return *this;
}

Fraction Fraction::operator++(int i)
{
    Fraction tmp;
    num = num + den;
    den = den * 1;
    return tmp;
}

Fraction Fraction::operator--(int i)
{
    Fraction tmp;
    num = num - den;
    den = den * 1;
    return tmp;
}

Fraction::operator double() const
{
    return (double)num / den;
}

void Fraction::Compact()
{
    int value = std::__gcd(num, den);
    num = num / value;
    den = den / value;
}

void Fraction::Set(int num, int den) 
{
    if (den == 0)
        throw std::invalid_argument("Denominator cannot be zero");
        
    this->num = num;
    this->den = den;
}

std::string Fraction::ToString() const
{
    if (den == 1)
        return std::to_string(num);
    else if (den == 0)
        return "ERROR, the denominator must not be zero";
    else
        return std::to_string(num) + "/" + std::to_string(den);
}

std::ostream &operator<<(std::ostream &outStream, const Fraction &fraction)
{
    outStream << fraction.ToString();
    return outStream;
}

std::istream &operator>>(std::istream& inStream, Fraction& fraction)
{
    int num, den;

    inStream >> num >> den;

    fraction.Set(num, den);
    return inStream;
}