#include <iostream>
using namespace std;
int main()
{
	int n, k,flag=0;
	cin >> n;
	int stack[50];
	for (int i = 0; i < n; i++)
	{
		cin >> stack[i];
	}

	cin >> k;
	for (int i = 0; i < n; i++)
	{
		if (k == stack[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		cout << "Element found";
	}
	else
	{
		cout << "Element not found";
	}


}
