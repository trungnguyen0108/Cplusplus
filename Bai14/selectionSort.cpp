#include <iostream>
#include <vector>
#include <optional>
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(vector<int> &arr)
{

	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
			if (arr[j] < arr[i])
				swap(&arr[j], &arr[i]);
	}
}

void printArray(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
}

int main()
{
	vector<int> arr({64, 25, 12, 22, 11, 3, 100});

	selectionSort(arr);
	printArray(arr);
}
