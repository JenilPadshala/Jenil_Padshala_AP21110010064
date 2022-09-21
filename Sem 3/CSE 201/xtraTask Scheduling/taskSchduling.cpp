#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter no. of tasks:";
    cin >> n;

    int time [n][2];
    cout << "Enter start time and finish time pair for each task:";
    for (int i =0; i<n; i++)
    {
        for (int j=0; j<2; j++)
        {
            cin >> time[i][j];
        }
    }

    //Bubble sort
    int flag =0;
    for (int i=0; i<n;i++)
    {
        for (int j=0; j<n-1-i; j++)
        {
            if (time[j][0] > time [j+1][0])
            {
                int temp = time [j][0];
                time [j][0] = time [j+1][0];
                time [j+1][0] = temp;

                int temp = time [j][1];
                time [j][1] = time [j+1][1];
                time [j+1][1] = temp;
            }
        }
    }

    
}