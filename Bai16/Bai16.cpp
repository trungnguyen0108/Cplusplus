#include <iostream>
#include <vector>
using namespace std;

void findLIS(vector<int> const &arr)
{
    int n = arr.size();

    vector<vector<int>> LIS(n);

    LIS[0].push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size())
            {
                LIS[i] = LIS[j];
            }
        }
        LIS[i].push_back(arr[i]);
    }

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (LIS[j].size() < LIS[i].size())
        {
            j = i;
        }
    }

    for (int i : LIS[j])
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> arr = {9, 5, 7, 8};

    findLIS(arr);
}