#include <iostream>

using namespace std;

int fact(int n);
int main(void) 
{

	int n,f;
	cout << "Enter the value of n:";
	cin >> n;
	f=fact(n);
	cout << "Factorial of a given Number: " << f;
}

int fact(int n)
{
 if(n==0)   
 {
 return 1;
 }
 else if(n==1)
 {
 return 1;
 }
 else
 {
     return n*fact(n-1);
 }
}