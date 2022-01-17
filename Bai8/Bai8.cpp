#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <map>

namespace fs = std::filesystem;
std::vector<std::string> file;


int main()
{
    std::string word;
    std::cin >> word;
    int k = 0;
    static std::map<std::string, int> a;

    std::string path = "vocabulary";
    for (const auto &entry : fs::directory_iterator(path))
    {
        std::fstream inFile(entry.path());
        std::string tmp;

        while (inFile >> tmp)
        {
            if (tmp == word)
            {
                k++;
                file.push_back(entry.path());
            }
        }
        
        inFile.close();
    }

    
    
}
