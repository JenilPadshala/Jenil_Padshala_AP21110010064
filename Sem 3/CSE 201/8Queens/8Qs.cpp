#include <iostream>
#include <cstdlib>

using namespace std;

int row, col[9], Board[9][9];
void printSolution()
{
    for (int i=0; i<9; i++)
    {
        cout << col[i]<<endl;
    }
}
int notPlace(int k)
{
    int flag = 0;
    for (int i = 1; i < k; i++)
    {
        if (col[i] == col[k] && abs(i-k) == abs(col[i]- col[k]))
            flag = 1;
    }
    return flag;
}

int main()
{

    row = 1;
    col[row] = 0;

    while (row > 0)
    {
        col[row] = col[row] + 1;
        while (col[row] < 9 && notPlace(row))
        {
            col[row] = col[row] + 1;
            if (col[row] < 9)
            {
                if (row == 8)
                    printSolution();
                else
                {
                    row = row + 1;
                    col[row] = 0;
                }
            }
            else
                row = row - 1;
        }
    }
}