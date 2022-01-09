#include "ImagiNum.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

Imaginary::Imaginary()
{
    a = 0.0;
    b = 0.0;
}

Imaginary::Imaginary(float a, float b)
{
    this->a = a;
    this->b = b;
}

void Imaginary::Input()
{
    std::cout << "Nhap phan thuc va phan ao: ";
    std::cin >> a >> b;
}

void Imaginary::Output()
{
    std::cout << a << " + " << b << "i"
              << "\n";
}

Imaginary Imaginary::Add(const Imaginary &i)
{
    return {(this->a + i.a), (this->b + i.b)};
}

Imaginary Imaginary::Subtract(const Imaginary &i)
{
    return {this->a - i.a, (this->b - i.b)};
}

Imaginary Imaginary::Product(const Imaginary &i)
{
    return {(this->a * i.a - this->b * i.b), (this->a * i.b + this->b * i.a)};
}

Imaginary Imaginary::Division(const Imaginary &i)
{
    Imaginary rt;
    rt.a = (this->a * i.a + this->b * i.b) / std::pow(this->a, 2) + std::pow(this->b, 2);
    rt.b = (this->a * i.b + this->b * i.a) / std::pow(this->a, 2) + std::pow(this->b, 2);
    return rt;
}
