#include <iostream>
#include "fraction.hpp"
#include <algorithm>
#include <fstream>

Fraction::Fraction()
{
    num = 0;
    den = 1;
}

Fraction::Fraction(int num, int den)
{
    this->num = num;
    if (den == 0)
    {
        std::cout << "the denominator must not be zero";
        exit(0);
    }
    else
        this->den = den;
}

Fraction Fraction::operator+(const Fraction &fraction)
{
    return {num * fraction.den + den * fraction.num, den * fraction.den};
}

Fraction Fraction::operator-(const Fraction &fraction)
{
    return {num * fraction.den - den * fraction.num, den * fraction.den};
}

Fraction Fraction::operator*(const Fraction &fraction)
{
    return {num * fraction.num, den * fraction.den};
}

Fraction Fraction::operator/(const Fraction &fraction)
{
    return {num * fraction.den, den * fraction.num};
}

Fraction Fraction::operator+=(const Fraction &fraction)
{
    num = num * fraction.den + den * fraction.num;
    den = den + fraction.den;
    return *this;
}

Fraction Fraction::operator-=(const Fraction &fraction)
{
    num = num * fraction.den - den * fraction.num;
    den = den + fraction.den;
    return *this;
}

Fraction Fraction::operator*=(const Fraction &fraction)
{
    num = num * fraction.num;
    den = this->den * fraction.den;
    return *this;
}

Fraction Fraction::operator/=(const Fraction &fraction)
{
    num = num * fraction.den;
    den = this->den * fraction.num;
    return *this;
    return *this;
}

Fraction Fraction::operator++()
{
    num = num + den;
    den = den * 1;
    return *this;
}

Fraction Fraction::operator--()
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

bool Fraction::operator>(const Fraction &fraction)
{
    if ((num / den) > (fraction.num / fraction.den))
        return true;
    return false;
}

bool Fraction::operator<(const Fraction &fraction)
{
    if ((num / den) < (fraction.num / fraction.den))
        return true;
    return false;
}

bool Fraction::operator==(const Fraction &fraction)
{
    if ((num / den) == (fraction.num / fraction.den))
        return true;
    return false;
}

bool Fraction::operator!=(const Fraction &fraction)
{
    if ((num / den) == (fraction.num / fraction.den))
        return false;
    return true;
}

void Fraction::Compact()
{
    int value = std::__gcd(num, den);
    num = num / value;
    den = den / value;
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