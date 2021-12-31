#include <iostream>

#define max 100

using namespace std;

int flag[max] = {0};
int A[max];
int a[5]={1,3,5,7,9};

void Output() 
{
    for (int i = 1; i <= sizeof a / sizeof a[0]; i++)
        cout << A[i] << " ";
    cout << endl;
}
 
void Try(int k) 
{
    for (int i = 0; i < sizeof a / sizeof a[0]; i++) 
    {
        if (!flag[i])
        {
            A[k] = a[i];
            flag[i] = 1;
            if (k == sizeof a / sizeof a[0])
                Output();
            else
                Try(k + 1);
            flag[i] = 0; 
        }
    }
}
 
int main() {
    Try(1);
}