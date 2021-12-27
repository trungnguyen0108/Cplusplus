#include <iostream>
#include <string>

using namespace std;

#define R 3
#define C 14

int x[] = { 0, 1, 1 };
int y[] = { 1, 0, 1 };


bool inputmatrix(char a[R][C], int row, int col, string name)
{
    if (a[row][col] != name[0])
      return false;
    int l = name.length();
    for (int i = 0; i < 3; i++)
    {   
        int k, nrow = row + x[i], ncol = col + y[i];
        for (k = 1; k < l; k++)
        {
            if (nrow >= R || nrow < 0 || ncol >= C || ncol < 0)
                break;
            if (a[nrow][ncol] != name[k])
                break;
            nrow += x[i], ncol += y[i];
        }
        if (k == l)
            return true;
        
    }
    return false;
}

void output(char a[R][C], string name)
{
    for (int row = 0; row < R; row++)
        for (int col = 0; col < C; col++)
            if (inputmatrix(a, row, col, name))
                cout << row << ", " << col << endl;      
}
int main()
{
    char a[R][C] = {"TRUNGVIPPROAS",
                    "STAYWITHVIASV",
                    "THANGMDVCLAAI" };
 
    output(a, "TRUNG");
    cout << endl;
    output(a, "VI");
    return 0;
}