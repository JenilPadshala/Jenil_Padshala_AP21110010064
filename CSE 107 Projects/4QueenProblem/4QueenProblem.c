#include <stdio.h>
#include <stdbool.h>
//#define BOARDSIZE 8
#define DIAGONAL (2*BOARDSIZE-1)
#define DOWNOFFSET 7
void WriteBoard(void);
void AddQueen(void);

int queencol[4];
bool colfree[4];
bool upfree[4];
bool downfree[4];

int queencount = -1,
    numsol = 0;

int main()
{
    int i;
    for (i=0; i< 4;i++)
    {
        colfree[i] = true;
    }
    for (i=0; i< 4; i++)
    {
        upfree[i] = true;
        downfree[i] = true;
    }
    AddQueen();

}

void AddQueen(void)
{
    int col;
    for (col=0; col<8; col++)
    {
        if(colfree[col] && upfree[queencount + col] && downfree[queencount - col + DOWNOFFSET])
        {
            queencol[queencount] = col;
            colfree[col] = false;
            upfree[queencount + col] = false;
            downfree[queencount - col + DOWNOFFSET] = false;

            if(queencount == 4-1)
                WriteBoard();
            else
                AddQueen();
            colfree[col] = true;
            upfree[queencount + col] = true;
            downfree[queencount - col + DOWNOFFSET] = true;
        }
        queencount--;
    }
}