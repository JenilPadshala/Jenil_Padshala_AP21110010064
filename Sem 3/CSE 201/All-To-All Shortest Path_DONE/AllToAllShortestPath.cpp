/*
Name: Jenil Padshala
Reg. No.: AP21110010064

ALL TO ALL SHORTEST PATH PROBLEM | DYNAMIC PROGRAMMING
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of vertices:";
    cin >> n;
    int CostM[n][n], i, j, k;
    FILE *data;
    if ((data = fopen("data.txt", "r")) == NULL)
    {
        cout << "Cannot open the data file\n";
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                fscanf(data, "%d", &CostM[i][j]);
            }
        }
    }

    // Showing the input Cost Matrix:
    cout << "Input Cost Matrix:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << CostM[i][j] << "\t";
        }
        cout << endl;
    }

    // Improving distances from a selected to node to all unselected nodes:
    for (k = 0; k < n; k++) // From All
    {
        for (i = 0; i < n; i++) // To All
        {
            for (j = 0; j < n; j++)
            {
                if (CostM[i][j] > CostM[i][k] + CostM[k][j])
                {
                    CostM[i][j] = CostM[i][k] + CostM[k][j];
                }
            }
        }
    }

    // Showing Output Cost Matrix:
    cout << "All to All Shortest Path solution Matrix:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << CostM[i][j] << "\t";
        }
        cout << endl;
    }
}