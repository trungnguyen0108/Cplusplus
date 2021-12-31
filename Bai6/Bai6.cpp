#include <iostream>

int x1,y1,x2,y2;

struct Vector
{
    int x,y;
};

Vector tong (Vector v1, Vector v2)
{
    Vector kq = {(v1.x + v2.x),(v1.y + v2.y)};
    return kq;
}

Vector hieu (Vector v1, Vector v2)
{
    Vector kq1 = {(v1.x - v2.x),(v1.y - v2.y)};
    return kq1;
}

Vector Tich (Vector v1, Vector v2)
{
    Vector kq2 = {(v1.x * v2.x),(v1.y * v2.y)};
    return kq2;
}


void Output (int x1, int x2, int y1, int y2)
{
    Vector v1 = {x1,y1};
    Vector v2 = {x2,y2};

    Vector kq = tong (v1,v2);
    Vector kq1 = hieu (v1,v2);
    Vector kq2 = Tich (v1,v2);

    std::cout << "tong 2 vecto la: " << kq.x << "," << kq.y << "\n";
    std::cout << "hieu 2 vecto la: " << kq1.x << "," << kq1.y << "\n";
    std::cout << "tich 2 vecto la: " << kq2.x + kq2.y;
}

int main()
{
    std::cout << "nhap vector thu nhat: ";
    std::cin >> x1 >> y1;
    std::cout << "nhap vector thu hai: ";
    std::cin >> x2 >> y2;
    Output(x1,x2,y1,y2);
} 
