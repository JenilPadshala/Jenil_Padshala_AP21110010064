#include <iostream>
using namespace std;

int main()
{
    int X[10] = {2, 3, 45, 6, 7, 12, 8, 80, 10, 9};
    double sum = 0, avg;

    double A[10];
    for (int i = 0; i <= 10; i++)
    {
        sum = sum + X[i];
        avg = sum / (i + 1);
        A[i] = avg;
    }

    cout << "Prefix Average Array:\n ";
    for (int i = 0; i <= 10; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}