#include <iostream>
#include <random>
#include <ctime>



int inputmatrix(int b[][10], int row, int column)
{
    std::srand(std::time(NULL));
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<column; j++)
        {
            b[i][j] = std::rand() % 5 + 1;
            std::cout << b[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

int kernel(int a[][10], int kernelrow, int kernelcolumn) 
{
    std::srand(std::time(NULL));
    int number = std::rand();
    for (int i=0; i<kernelrow; i++)
    {
        for (int j=0; j<kernelcolumn; j++)
        {
            a[i][j] = std::rand() % 5 + 1;
            std::cout << a[i][j] << "\t";
        }
        std::cout << "\n";
    }
}


int main()
{
    int a[10][10],b[10][10],out[10][10];
    int row, column, kernelrow, kernelcolumn;
    std::cout << "nhap so cot so hang: ";
    std::cin >> row >> column;
    inputmatrix(b,row,column);
    std::cout << "\n";
    std::cout << "nhap so cot so hang: ";
    std::cin >> kernelrow >> kernelcolumn;
    kernel(a,kernelrow,kernelcolumn);

    const int dx = 3 / 2;
    const int dy = 3 / 2;

    for (int i = 0; i< row; i++) 
    {
        for (int j = 0; j< column; j++) 
        {
            int tmp = 0;
            for (int k = 0; k < kernelrow; k++) 
            {
              for (int l = 0; l < kernelcolumn; l++) 
              {
                int x = j - dx + l;
                int y = i - dy + k;
                if (x >= 0 && x < row && y >= 0 && y < column)
                    tmp += a[y][x] * b[k][l];
              }
            }
            out[i][j] = tmp;
            std::cout << out[i][j];
        }
    }
}