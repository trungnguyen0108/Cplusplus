#include <iostream>
#include <fstream>

#define N 9
int grid[N][N];

bool isPresentInCol(int col, int num)
{
    for (int row = 0; row < N; row++)
    {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool isPresentInRow(int row, int num)
{
    for (int col = 0; col < N; col++)
    {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool isPresentInBox(int boxStartRow, int boxStartCol, int num)
{

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
        }
    }
    return false;
}

void sudokuGrid()
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << "\n";
    }
}

bool findEmptyPlace(int &row, int &col)
{
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool isValidPlace(int row, int col, int num)
{

    return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3, col - col % 3, num);
}

bool solveSudoku()
{
    int row, col;
    if (!findEmptyPlace(row, col))
        return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isValidPlace(row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku())
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main()
{

    std::fstream inFile("sodoku.txt");
    
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                inFile >> grid[i][j];
            }
        }

        if (solveSudoku() == true)
            sudokuGrid();
        else
            std::cout << "No solution exists";

        std::cout << "\n";
    }

    inFile.close();
}