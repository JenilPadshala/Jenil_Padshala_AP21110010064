#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int Board [8][8];
    int Moves [8][2] = {{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
    //Assigned 0 as elements in Board
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            Board[i][j] = 0;
        }
    }

    //Generating random position of Knight

    int i = 5;//rand()%8 + 1;
    int j = 5;//rand()%8 + 1;
    Board[i][j] = 1;
    int k=0, count = 2;
    int Newi, Newj;

    //Moving the knight across the Board
    do{
        Newi = i + Moves[k][0];
        Newj = j + Moves[k][1];

        if (Newi >= 0 && Newi <=7 && Newj >= 0 && Newj <= 7 && Board[Newi][Newj] == 0)
        {
            Board[Newi][Newj] = count++;
            i = Newi;
            j = Newj;
            k = 0;
            //Display the Board
    for (int x=0; x<8; x++)
    {
        for (int y=0; y<8; y++)
        {
            cout << Board[x][y]<< "  ";
        }
        cout << endl;
    }
    cout << endl<< endl;
        }
        else
        {
            k++;
        }

    }while(k<8);

    /*//Display the Board
    for (int x=0; x<8; x++)
    {
        for (int y=0; y<8; y++)
        {
            cout << Board[x][y]<< "  ";
        }
        cout << endl;
    }*/

}