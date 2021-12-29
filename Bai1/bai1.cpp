#include <iostream>


void InputArray(int a[][10], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << "Nhap [" << i << "][" << j << "] = ";
            std::cin >> a[i][j];
        }
    }
}

void Outputarray(int a[][10], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}


int main()
{  
    int a[10][10], b[10][10], c[10][10];
    int row, column, row2, column2;
    std::cout << "Nhap vao so cot ma tran 1: ";
    std::cin >> row;
    std::cout << "Nhap vao so hang ma tran 1: ";
    std::cin >> column;
    InputArray(a, row, column);
   

    std::cout << "Nhap vao so cot ma tran 2: ";
    std::cin >> row2;
    std::cout << "Nhap vao so hang ma tran 2: ";
    std::cin >> column2;
    InputArray(b, row2, column2);
    
    for (int i=0; i < row; i++)
    {
        for ( int j=0; j < column2; j++)
        {
            for (int k=0; k < column; k++)
            {
                c[i][j] += a[i][k] * b[k][j]; 
                std::cout << c[i][j];
            }
            std::cout << "\n";
        }
    }
}