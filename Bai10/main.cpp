#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction a(2, 1);
    Fraction b(3, 2);

    if (a < b)
    {
        std::cout << "true";
    }
    else
        std::cout << "false";
}