#include <iostream>
#include <string>

std::string specialCharacter = "!@#$%^&*()123456789<>?:}{_)";

void isStandardizing(std::string str)
{
    // xóa kí tự trắng ở đầu chuỗi
    while (str[0] == ' ')
    {
        str.erase(str.begin());
    }
    // xóa kí trự trắng ở cuối chuỗi
    while (str[str.length() - 1] == ' ')
    {
        str[str.length() - 1] = '\0';
    }
    //xóa kí tự trắng ở giữa các chữ, đồng thời viết thường chuỗi kí tự
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            str.erase(str.begin() + i);
            i--;
        }
        str[i] = std::towlower(str[i]);
    }
    // xóa các kí tự đặc biệt và số
    for (int i = 0; i < str.length(); i++)
    {
        for(int j = 0; j < specialCharacter.length(); j++)
        {
            if(str[i] == specialCharacter[j])
                str.erase(str.begin() + i);
        }
    }
    
    // viết hoa các chữ cái đầu và xuất chuỗi
    for (int i = 0; i < str.length(); i++)
    {
        str[0] = toupper(str[0]);
        if (str[i] == ' ')
        {
            str[i + 1] = toupper(str[i + 1]);
        }
        std::cout << str[i];
    }
}



int main()
{
    std::string str;
    std::getline(std::cin, str);
    isStandardizing(str);
}