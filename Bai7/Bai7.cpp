#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <map>

namespace fs = std::filesystem;

int main()
{
    std::map<std::string,int> a;
    std::string path = "vocabulary";
    for (const auto &entry : fs::directory_iterator(path))
    {
        std::fstream inFile(entry.path());
        std::string tmp;

        while (inFile >> tmp)
        {
            a[tmp]++;
        }

        inFile.close();
    }

    std::ofstream outFile("vocabulary/result.txt");
    for(auto it : a)
    {
        outFile << it.first << " : " << it.second << " lan" << "\n";   
    }
    outFile.close();
}
