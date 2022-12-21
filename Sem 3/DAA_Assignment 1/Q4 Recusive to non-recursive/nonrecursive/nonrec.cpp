#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter an integer : ";
    cin >> n;

    int stack[n], top=-1;
    int factorial = 1;

    for (int i=1; i<=n;i++)
    {
        stack[++top] = i;
        
    }
    while (top != -1)
    {
        factorial = factorial * stack[top--];
    }
    cout << "Factorial of "<< n << " is "<< factorial;
}

