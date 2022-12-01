#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

// Brute force matching

int main()
{
    char t[25], p[6];
    int i, j, k, F[6];

    cout << "Enter 6 characters for pattern & 25 characters for text\n";
    // cannot use cin in input because cin does not take blank space into character counting

    cout << "Input 6 characters pattern: " << endl;
    for (i = 0; i < 6; i++)
    {
        scanf("%c", &p[i]);
    };
    cout << "Input 25 characters text: " << endl;
    for (i = 0; i < 25; i++)
    {
        scanf("%c", &t[i]);
    };

    // Generate Failure function foor the pattern
    cout << "Failure function starting here\n";
    getch();

    F[0] = 0;
    i = 1;
    j = 0;
    while (i < 6)
    {
        if (p[i] == p[j])
        {
            F[i] = j + 1;
            i = i + 1;
            j = j + 1;
        }

        else
        {
            if (j > 0)
                j = F[j - 1];
            else
            {
                F[i] = 0;
                i = i + 1;
            }
        }
    }
    for (i = 0; i < 6; i++)
        cout << F[i] << "  ";
    cout << endl;
    cout << "Failure function ending here\n";
    getch();

    i = 0;
    j = 0;
    while (i < 25)
    {
        if (t[i] == p[j])
        {
            if (j == 5)
            {
                cout << "match found at" << i - j << endl;
                break;
            }
            else
            {
                i = i + 1;
                j = j + 1;
            }
        }
        else
        {
            if (j > 0)
                j = F[j - 1];
            else
                i = i + 1;
        }
    }

    cout << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
