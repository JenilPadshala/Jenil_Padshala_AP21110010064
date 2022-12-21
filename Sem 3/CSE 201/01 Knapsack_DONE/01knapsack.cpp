#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int N, i, j, k, Nn;
    cout << "Enter the number of items:";
    cin >> N;
    Nn = pow(2, N);
    // Initializing Array
    int A[Nn][N];
    for (i = 0; i < Nn; i++)
    {
        for (j = 0; j < N; j++)
        {
            A[i][j] = 0;
        }
    }
    // Converting Decimal to Binary for each possible combinations of items:
    // Creating all subsets
    for (j = 0; j < Nn; j++)
    {
        k = j, i = N - 1;
        while (k > 0)
        {
            A[j][i--] = k % 2;
            k = k / 2;
        }
    }

    // Weight of Knapsack:
    float KW;
    cout << "Enter weight of the knapsack:";
    cin >> KW;

    // Weight and Price of items:
    float W[N], P[N];
    cout << "Enter Weight and Price of each item separated by a space:" << endl;
    for (i = 0; i < N; i++)
    {
        cout << "Weight of item " << i + 1 << ":";
        cin >> W[i];
        cout << "Price of item " << i + 1 << ":";
        cin >> P[i];
    }

    // Finding the ideal solution:
    float MW[Nn], MP[Nn];
    int t = N - 1;
    for (i = 0; i < Nn; i++)
    {
        MW[i] = 0;
        MP[i] = 0;
        for (j = 0; j < N; j++)
        {
            MW[i] += A[i][t - j] * W[j];
            MP[i] += A[i][t - j] * P[j];
        }
        if (MW[i] > KW)
            MP[i] = 0;
    }

    float MAX = 0;
    for (i = 0; i < Nn; i++)
    {
        if (MP[i] > MAX)
        {
            MAX = MP[i];
        }
    }
    cout << "The highest profit is $" << MAX << endl;
}