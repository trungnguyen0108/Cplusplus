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

                // dem so lan xuat hien trong 1 file
                for (auto file : entry.path().filename())
                {
                    a[tmp]++;
                    std::cout << file << "\n";
                }
                std::cout << a[tmp];
                a[tmp] = 0;
            }
        }

        inFile.close();
    }
}
