#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
    string txt, ptrn;
    int i = -1, j, k = -1;

    cout << "Enter pattern: ";
    getline(cin, ptrn);

    cout << "Enter text: ";
    getline(cin, txt);
    do
    {
        j = k;
        do
        {
            i++;
            j++;
        } while (txt[j]==ptrn[i] && i<ptrn.length());

        if (i<ptrn.length())
        {
            i=-1;
            k +=1;
        }
        else
        {
            cout << "Match found at index "<<k+1<<" in the text."<<endl;
            cout <<txt<<endl;
            break;
        }
        
    } while (k<txt.length());

    if (i<ptrn.length())
    {
        cout <<"Match not found"<<endl;
    }
}