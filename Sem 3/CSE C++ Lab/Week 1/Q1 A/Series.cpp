#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, x, sum = 1;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter n:";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        sum = sum + pow(x, i);
    }
    cout << "Sum = " << sum;
    return 0;
}