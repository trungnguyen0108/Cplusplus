#include <iostream>
#include <fstream>
#include <string>

int main()

{
    std::fstream inFile("SUMN.INP");
    int data;
    inFile >> data;
    int result = 0;
    while(data!=0)
    {
        int tmp;
        tmp = data % 10;
        result += tmp;
        data /= 10;
    }
    std::ofstream outFile("SUMN.OUT");
    outFile << result;
    outFile.close();
    inFile.close();
}