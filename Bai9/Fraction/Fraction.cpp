#include "Fraction.hpp"
#include <iostream>
#include <algorithm>
Fraction::Fraction()
{
    x = 0;
    y = 1;
}

Fraction::Fraction(int x, int y)
{
    this->x = x;
    if (y != 0)
    {
        this->y = y;
    }
    else
    {
        y = 1;
    }
}

void Fraction::Input()
{
    std::cout << "Nhap tu so va mau so: ";
    std::cin >> x >> y;
}

void Fraction::Output()
{
    std::cout << x << "/" << y << "\n";
}

void Fraction::ComPact()
{
    int value = std::__gcd(x, y);
    x = x / value;
    y = y / value;
}

Fraction Fraction::Add(const Fraction &b)
{
    return {(this->x * b.y) + (this->y * b.x), (this->y * b.y)};
}

Fraction Fraction::Subtract(const Fraction &b)
{
    return {(this->x * b.y) - (this->y * b.x), (this->y * b.y)};
}

Fraction Fraction::Product(const Fraction &b)
{
    return {this->x * b.x, this->y * b.y};
}

Fraction Fraction::Division(const Fraction &b)
{
    return {this->x * b.y, this->y * b.x};
}
