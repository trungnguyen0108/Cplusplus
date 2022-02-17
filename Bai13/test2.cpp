#include <iostream>
#include <thread>
#include <fstream>
#include <chrono>
#include <ctime>
#include <random>
#include <vector>
#define N 1000000

using namespace std;

struct Timer
{
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
    Timer()
    {
        start = std::chrono::steady_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << duration.count();
    }
};


void Search(int key)
{
    std::fstream inFile("number.txt");
    int tmp;
    while(inFile >> tmp)
    {
        if(tmp == key)
        {
            std::cout << tmp;
        }
    }
}

int main()
{
    int toFind;
    std::cin >> toFind;

    Search(toFind);
}