#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectSort(int A[], int n)
{
    int min;
    for (int i=0; i<n-1; i++)
    {
        min =i;
        for (int j=i+1; j<n; j++)
        {
            if (A[min]> A[j])
                min = j;
        }
        swap (&A[i], &A[min]);
    } 
}
int main()
{
    int A[] = {1,9,10,3,5};
    int n = sizeof(A)/sizeof(A[0]);
    SelectSort(A, n);
    printf("\nSorted array:\n");
    for (int i=0; i<n;i++)
    {
        printf("%d\t", A[i]);
    }
}

