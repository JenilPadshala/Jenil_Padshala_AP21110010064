#include <stdio.h>
#include <stdbool.h>
void PrintQueen(bool PrintMatrix);  //Print correct Arrangement
void RemoveQueen(); //Remove queen from QueenMatrix
void InsertQueen(); //Add Queen in QueenMatrix
void CheckDownDiagonal();   //Check if any other Queen down diagonal
void CheckUpDiagonal();     //Check if any other Queen in up diagonal
void CheckColumn();     //Check if any other Queen present in same column
int main ();
{
    int GuardMatrix[4][4];  //Keep record of places guarded
    int i,j;
    bool QueenMatrix[4][4]; //Keep record of position of Queens
    int a,b;

    bool QueenCol[4];   //Keep track of columns occupied by Queen

    for (i=0; i<4; i++)     //Setting all values in GuardMatrix to 0.
    {
        for (j=0; j<4;j++)
        {
            GuardMatrix[i][j] = 0;
        }
    }
    for (a=0; a<4; a++)     //Setting all values in QueenMatrix to 0.
    {
        for (b=0; b<4;b++)
        {
            QueenMatrix[a][b] = true;
        }
    }
}