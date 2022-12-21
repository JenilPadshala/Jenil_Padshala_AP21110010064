#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int place(int);
int  X[9], i, j, k, flag;
main()
{
    k = 1;
    X[k] = 0;
    int count = 1;
    while (k > 0)
    {
        X[k] += 1;
        while (place(k) == 0 && X[k] < 9)
        {
            X[k] = X[k] + 1;
        };
        if (X[k] < 9)
        {
            if (k == 8)
            {
                cout << "The solution number "
                     << count << "= ";
                for (i = 1; i < 9; i++)
                    cout << X[i] << " ";

                count++;

                cout << endl;
                cout << "For the next solution press any key\n ";
            }
            else
            {
                k = k + 1;
                X[k] = 0;
            };
        }
        else
            k = k - 1;
    };
}

int place(int j)
{
    flag = 1;
    for (i = 1; i < j; i++)
    {

        if (X[i] == X[j] || abs(i - j) == abs(X[i] - X[j]))
            flag = 0;
    }
    return flag;
}