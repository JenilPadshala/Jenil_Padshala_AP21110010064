#include <iostream>
#include <string>

using namespace std;
int lastOccurence(string ptrn,char ch, int j)
{
    while (1)
    {
        j--;
        if (ptrn[j]==ch)
        {
            return j;
        }

        if(j==0)
        {
            return -1;
        }
    }
}
int main()
{
    string ptrn, txt;
    int i, j, ptrnlen, txtlen,lo;
    cout << "Enter the pattern: ";
    getline(cin, ptrn);
    cout << "Enter the text: ";
    getline(cin, txt);

    ptrnlen = ptrn.length();
    txtlen = txt.length();

    i = ptrnlen - 1;
    j = ptrnlen - 1;

    do
    {
        do
        {
            if (txt[i] == ptrn[j])
            {
                i--;
                j--;
            }
            else
                break;
        } while (j != 0);
        if (j == 0)
        {
            cout << "Pattern matched at: " << i;
            break;
        }
        //character jump
        lo = lastOccurence(ptrn,txt[i],j);
        if (lo == -1)
        {
            i +=    
        }

    } while (i < txtlen);
}