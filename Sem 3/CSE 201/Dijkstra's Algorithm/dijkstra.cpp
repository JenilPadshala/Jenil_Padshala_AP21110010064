#include <iostream>
using namespace std;

int main()
{
    int N;
    cout <<"Enter the no. of vertices in graph (N):";
    cin >> N;
    int CostM[N][N];
    //Creating the input Cost Matrix;
    for (int i=0; i<N;i++)
    {
        for (int j=0; j<N; j++)
        {
            cout <<i<<" to "<<j<< " = ";
            cin >>CostM[i][j];
        }
    }
}