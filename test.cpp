#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string IP = "123.12.2.2";
    std::vector<std::string> v;

    std::string dot = ".";
    // xóa dấu chấm
    size_t pos = 0;
    while ((pos = IP.find(dot)) != std::string::npos)
    {
        v.push_back(IP.substr(0, pos));
        IP.erase(0, pos + dot.length());
    }
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << "\n";
    }
    // chuyển các octet thành kiểu dữ liệu int

    // tiến hành đổi sang nhị phân
    // ghép lại với nhau
}