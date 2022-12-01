#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter no. of nodes in the graph:";
    cin >> n;
    int M[n][n], i, j, k, count = 0, m, flag;

    // Data from txt file
    FILE *fdata;
    if ((fdata = fopen("vdata.txt", "r")) == NULL)
    {
        cout << "Cannot open the data file\n";
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                fscanf(fdata, "%d", &M[i][j]);
            }
        }
    }
    cout << "Input Adjacency Matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    flag = 1;
    cout <<"Vertex Cover:\n";
    while (flag)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (M[i][j] == 1)
                {
                    flag = 1;
                    cout<<i<<"\t";
                    count++;
                    goto skip;
                }
                else
                {
                    flag = 0;
                }
            }
        skip:
            if (flag)
            {
                for (k = 0; k < n; k++)
                {
                    M[i][k] = 0;
                    M[k][i] = 0;
                    M[j][k] = 0;
                    M[k][j] = 0;
                }
            }
        }
    }
    // Displaying the new Adj Mat.
    cout << "\nCurrent Adjacency Matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl
         << endl
         << "The optimal vertex cover contains maximum " << count << " vertices." << endl;
}