#include <iostream>
#include <fstream>

int main()
{
    std::fstream inFile("ZERO.INP");
    int length;
    int size;
    int MAX;
    inFile >> size;
    for (int l = 0; l < size; l++)
    {
        int n[size];
        inFile >> n[l];
        for (int i = 0; i < size; i++)
        {
            int sum = 0;
            for (int j = i; j < size; j++)
            {
                sum = sum + n[j];
                if (sum == 0)
                {

                    int length;
                    length = j - i + 1;
                    if (length > MAX)
                    {
                        MAX = length;
                    }
                }
            }
        }
    }
    std::ofstream outFile("ZERO.OUT");
    outFile << MAX;
    outFile.close();
    inFile.close();
}
