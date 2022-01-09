#pragma once

class Imaginary
{
private:
    float a;
    float b;

public:
    Imaginary();
    Imaginary(float a, float b);
    void Input();
    void Output();
    Imaginary Add(const Imaginary &);
    Imaginary Subtract(const Imaginary &);
    Imaginary Product(const Imaginary &);
    Imaginary Division(const Imaginary &);
};
