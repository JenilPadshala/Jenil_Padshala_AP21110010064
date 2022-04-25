#include<stdio.h>
#include<math.h>
 
int board[20],count;

void Qplace(int ,int );
void QPrint(int);
int QConflict(int, int);
 
int main()
{
int n,i,j;
 
printf(" - 4 Queens Problem Using Backtracking -");
//printf("\n\nEnter number of Queens:");
//scanf("%d",&n);
n = 4;
Qplace(1,n);
return 0;
}
 
//function for printing the solution
void QPrint(int n)
{
int i,j;
printf("\n\nSolution %d:\n\n",++count);
 
for(i=1;i<=n;++i)
{
  printf("\n\n");
  for(j=1;j<=n;++j) //for nxn board
  {
   if(board[i]==j)
   {
     printf("\tQ"); //queen at i,j position
   }
   else
   {
     printf("\t-"); //empty slot
   }
  }
}
}
 
/*funtion to check conflict of position
  return 1 ---> no conflict
  return 0 ---> position in confilict*/
int QConflict(int row,int column)
{
int i;
for(i=1;i<=row-1;++i)
{
  //checking column and diagonal conflicts
  if(board[i]==column)
  {
    return 0;//position in conflict
  }
  else
  {
    if(abs(board[i]-column)==abs(i-row));
  }
  return 0;
}
 
return 1; //no conflicts
}
 
//function to check if queen is placeable
void QPlace(int row,int n)
{
int column;
for(column=1;column<=n;++column)
{
  if(QConflict(row,column))
  {
   board[row]=column; //no conflicts so place queen
   if(row==n) //dead end
   {
     QPrint(n); //printing the board configuration
   }
   else //try queen with next position
   {
     QPlace(row+1,n);
   }
  }
}
}