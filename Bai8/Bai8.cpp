#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <map>

namespace fs = std::filesystem;

int main()
{
    std::map<std::string, int> a;

    std::string word;
    std::cin >> word;

    std::string path = "vocabulary";
    for (const auto &entry : fs::directory_iterator(path))
    {
        std::fstream inFile(entry.path());
        std::string tmp;
        
        while (inFile >> tmp)
        {
            
            if(tmp == word)
            {   
                {
                    std::cout << entry.path().filename() << "\n";
                }
            }
        }

        inFile.close();
        
    }
}
