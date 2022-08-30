#include <iostream>
using namespace std;

int main()
{
    int X[10] = {2, 3, 45, 6, 7, 12, 8, 80, 10, 9};
    double A[10];
    for (int j = 0; j <= 10; j++)
    {
        double sum = 0, avg;
        for (int i = 0; i <= j; i++)
        {
            sum = sum + X[i];
        }
        avg = sum / (j + 1);
        A[j] = avg;
    }
    cout << "Prefix Average Array:\n ";
    for (int i = 0; i <= 10; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}