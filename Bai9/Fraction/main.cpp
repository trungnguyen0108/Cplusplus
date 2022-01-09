#include "Fraction.hpp"
#include "Fraction.cpp"
#include <iostream>


int main()
{
    Fraction frac1, frac2;
    std::cout << "Phan so 1:\n";
    frac1.Input();
    std::cout << "Phan so 2:\n";
    frac2.Input();

    Fraction result = frac1.Add(frac2);
    std::cout << "Ket qua la: ";
    result.ComPact();
    result.Output();
}