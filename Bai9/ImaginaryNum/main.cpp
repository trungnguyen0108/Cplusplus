#include "ImagiNum.hpp"
#include "ImagiNum.cpp"
#include <iostream>

int main()
{
    Imaginary Num1, Num2;
    std::cout << "So ao 1:\n";
    Num1.Input();
    std::cout << "So ao 2:\n";
    Num2.Input();

    Imaginary result = Num1.Add(Num2);
    std::cout << "Ket qua la: ";
    result.Output();
}