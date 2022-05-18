#include <stdio.h>
void InsertSort(int A[], int n)
{
    int t,i,j;
    for (i=1; i<n; i++)
    {
        t = A[i];
        for (j=i-1; j>=0 && A[j] > t; j--)
        {
            A[j + 1] = A[j];
        }
        A[j+1] = t;
    } 
}
int main()
{
    int A[] = {1,9,10,3,5};
    int n = sizeof(A)/sizeof(A[0]);
    InsertSort(A, n);
    printf("\nSorted array:\n");
    for (int i=0; i<n;i++)
    {
        printf("%d\t", A[i]);
    }
}

