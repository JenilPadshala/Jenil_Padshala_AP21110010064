#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


int main()
{
    string t, p;
    int i, j, k, n, flag, s, ptrnlen, txtlen;
    cout << "Input pattern: " << endl;
    getline(cin,p);
    cout << "Input text: " << endl;
    getline(cin, t);

    ptrnlen = p.length();
    txtlen = t.length();
    i = -1;
    k = -1;

    do
    {
        j = k;
        do
        {
            i = i + 1;
            j = j + 1;
        } while (t[j] == p[i] && i < ptrnlen);

        if (i < 4)
        {
            cout << "Match not found\n";
            flag = 0;
            for (n = 3; n >= 0; n--)
            {
                if (p[n] == t[j])
                {
                    flag = 1;
                    s = n;
                    cout << "n= " << n << endl;
                }
            }

            if (flag == 0)
            {
                i = -1;
                k = k + ptrnlen;
                cout << "k= " << k << endl;
            }
            else
            {
                i = -1;
                k = j - s - 1;
                cout << "k= " << k << endl;
            }
        }

        if (i == 4)
        {
            cout << "Match found at " << k + 1;
            break;
        }

    } while (k < txtlen);

    if (i < ptrnlen)
        cout << "Match not found"<<endl;
}
