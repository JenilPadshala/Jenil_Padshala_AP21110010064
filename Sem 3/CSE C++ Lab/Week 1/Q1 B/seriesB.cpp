#include <iostream>
using namespace std;

int main()
{
    int n, x, sum = 1, num = 1;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter n:";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        num = num * x;
        sum = sum + num;
    }
    cout << "Sum = " << sum;
    return 0;
}