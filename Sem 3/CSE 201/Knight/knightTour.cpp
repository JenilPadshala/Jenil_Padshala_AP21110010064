#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
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
    srand(time(0));
    int i =rand()%8;
    int j =rand()%8;

    //Placing Horse at position 1
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
        }
        else
        {
            k++;
        }

    }while(k<8);

    
    for (int x=0; x<8; x++)
    {
        for (int y=0; y<8; y++)
        {
            cout <<setw(2)<< Board[x][y]<< "  ";
        }
        cout << endl;
    }

}