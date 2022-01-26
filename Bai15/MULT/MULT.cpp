#include <iostream>
#include <fstream>

int Try(int n[])
{
    int dem = 0;
    for (int num = n[0]; num <= n[1]; num++)
    {
        int flag;
        flag = num % n[0];
        if (flag == 0)
        {
            dem++;
            
        }
    }
    return dem;
}

int main()
{
    // chạy 1 vòng for duyệt hết file
    std::fstream inFile("MULT.INP");
    std::ofstream outFile("MULT.OUT");
    int n, dem;

    inFile >> n;
    for (int i = 0; i < n; i++)
    {
        int n[2];
        for (int k = 0; k < 2; k++)
        {
            inFile >> n[k];
        }
       
        outFile << Try(n) << "\n";
        
    }
    outFile.close();
    inFile.close();
}