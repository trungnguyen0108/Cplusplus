#pragma once

class Fraction
{
private:
    int x;
    int y;

public:
    Fraction();
    Fraction(int x, int y);
    void Input();
    void Output();
    void ComPact();
    Fraction Add(const Fraction &);
    Fraction Subtract(const Fraction &);
    Fraction Product(const Fraction &);
    Fraction Division(const Fraction &);
};
