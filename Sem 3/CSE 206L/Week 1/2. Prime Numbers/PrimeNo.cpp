#include <iostream>
using namespace std;

int  main()
{
    int i,j,n;
    
    cout << "Enter n:";
    cin >> n;
    
    cout << "Prime numbers are:" << endl;    
    for(i=2;i<=n;i++)
    {
        int c=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                c++;
            }
        }
         
       if(c==2)
        {
            cout << i<< " ";
        }
    }
}