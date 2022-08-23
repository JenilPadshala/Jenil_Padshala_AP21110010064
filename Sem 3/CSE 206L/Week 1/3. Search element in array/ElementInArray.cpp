#include <iostream>
using namespace std;

int main()
{
    int A[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n, flag = 0;

    cout << "Enter the number to search in array:";
    cin >> n;
    for (int i=0; i< 10; i++)
    {
        if (A[i] == n)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << n << " is present in the array.";
    }
    else
    {
        cout << n << " is not present in the array.";
    }
}