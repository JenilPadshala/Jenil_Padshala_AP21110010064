#include <iostream>

using namespace std;

int main()
{
    int a, b, result;
    char op;

    cout << "Enter two numbers:";
    cin >> a >> b;
    cout << "Enter the operator sign:";
    cin >> op;

    switch (op)
    {
    case '+':
    {
        result = a + b;
        break;
    }
    case '-':
    {
        result = a - b;
        break;
    }
    case '*':
    {
        result = a * b;
        break;
    }
    case '/':
    {
        result = a / b;
        break;
    }
    }
    cout << "Result: " << result;
}