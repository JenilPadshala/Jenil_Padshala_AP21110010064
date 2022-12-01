#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int notPlaceable(int);
int col[9], i, j, row, flag;
main()
{
    row = 1;
    col[row] = 0;
    int count = 1;
    while (row > 0)
    {
        col[row] += 1;
        while (notPlaceable(row) && col[row] < 9)
        {
            col[row] = col[row] + 1;
        }
        if (col[row] < 9)
        {
            if (row == 8)
            {
                cout << "Solution number "
                     << count << ": " << endl;
                for (i = 1; i < 9; i++)
                {
                    for (j = 1; j < 9; j++)
                    {
                        if (col[i] == j)
                        {
                            cout << "Q  ";
                        }
                        else
                        {
                            cout << "-  ";
                        }
                    }
                    cout << endl;
                }
                count++;

                cout << endl;
                cout << "For the next solution press any key\n ";
                cin.get();

            }
            else
            {
                row = row + 1;
                col[row] = 0;
            };
        }
        else
            row = row - 1;
    };
}

int notPlaceable(int j)
{
    flag = 0;
    for (i = 1; i < j; i++)
    {

        if (col[i] == col[j] || abs(i - j) == abs(col[i] - col[j]))
            flag = 1;
    }
    return flag;
}