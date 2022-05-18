#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Bsort(int A[], int n)
{
    int flag =0;
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1-i; j++)
        {
            if (A[j]> A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if (flag ==0)
            break;
    } 
}
int main()
{
    int A[] = {1,9,10,3,5};
    int n = sizeof(A)/sizeof(A[0]);
    Bsort(A, n);
    printf("\nSorted array:\n");
    for (int i=0; i<n;i++)
    {
        printf("%d\t", A[i]);
    }
}

