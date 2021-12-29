#include <iostream>
#include <random>
#include <ctime>


int matrix(int a[][10], int row, int col)
{
    std::srand(std::time(NULL));
    for (int i=0; i < row; i++)
    {
        for (int j=0; j < col; j++)
        {
            a[i][j] = rand() % 10 + 1;
            std::cout << a[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

int outputmatrix(int a[][10], int row, int col)
{
    int R = row - 1, C = col - 1;
	int i = 0, j = 0, index = 0;

	while (index <= R * C)
	{
		for (int k = j; k <= C; k++) std::cout << a[i][k] << '\t';
		i++;
		for (int k = i; k <= R; k++) std::cout << a[k][C] << '\t';
		C--;
		for (int k = C; k >= j; k--) std::cout << a[R][k] << '\t';
		R--;
		for (int k = R; k >= i; k--) std::cout << a[k][j] << '\t';
		j++;

		index++;
	}
}

int main()
{
    int a[10][10], row, col;
    std::cout << "nhap so dong: ";
    std::cin >> row;
    std::cout << "nhap so cot: ";
    std::cin >> col;
    matrix(a,row,col);
    std::cout << "ma tran xoan oc la: ";
    outputmatrix(a,row,col);
}