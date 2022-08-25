#include <iostream>
using namespace std;

int Factorial (int fac)
{
    if (fac >=1)
    {
        return fac*Factorial(fac - 1);
    }
    else
        return 1;
}

int main()
{
    int n;
    cout<<"Enter an integer : ";
    cin >> n;
    cout << "Factorial of "<< n << " is "<< Factorial(n);
}