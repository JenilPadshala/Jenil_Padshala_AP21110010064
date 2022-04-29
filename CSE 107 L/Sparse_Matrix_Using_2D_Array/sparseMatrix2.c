#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int scanMatrix();   //function to read elements of matrix
int printMatrix();  //function to display elements of matrix
bool checkMatrix(); //function to check whether matrix is sparse matrix
int sparseRepresentation(); //function to represent sparse matrix as a multi-dimensional array
int intMatrix[10][10],  //initial integer matrix
        i, j,           //loop control variables
        countNZEle = 0; //counts number of non-zero elements
int main() //Driver Function
{
    scanMatrix();
    int t = checkMatrix();
    printMatrix();
    if (t = 1)
        sparseRepresentation();
}

int scanMatrix()
{
    printf("Enter 16 elements for a matrix of order 4 separated by space. \n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &intMatrix[i][j]);
        }
    }
}
bool checkMatrix()
{   //Counting number of non-zero elements
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (intMatrix[i][j] != 0)
            {
                countNZEle += 1;
            }
        }//end of for(j)
    }//end of for(i)
    if (countNZEle <= 8)
    {
        printf("The given matrix is sparse matrix with %d non-zero elements. \n", countNZEle);
        return 1;
    }
    else
    {
        printf("The given matrix is not sparse matrix. \n");
        return 0;
    }
}

int printMatrix()
{
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d\t", intMatrix[i][j]);
        }//end of for(j)
        printf("\n");
    }//end of for(i)
}

int sparseRepresentation()
{
   int compactMatrix[3][countNZEle],
        k = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < countNZEle - 1; j++)
        {
            if (intMatrix[i][j] > 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = intMatrix[i][j];
                k++;
            }
        }//end of for(j)
    }//end of for(i)
    printf("The elements are. \n");
    for (int j = 0; j < countNZEle; j++)
    {
        for (int i = 0; i < 3; i++)
            printf("%d", compactMatrix[i][j]);
        printf("\n");
    } 
}