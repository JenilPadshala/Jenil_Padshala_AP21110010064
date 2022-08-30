#include <iostream>
using namespace std;
/*Function to swap two elements in an array*/
void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*This function places elements smaller than the pivot 
    to left of pivot and the element greater than pivot to the right side.*/
int partition(int A[], int low, int high)
{
    int pivot = A[high];    //last element of the array
    int i = (low - 1); 

    for (int j = low; j<= high -1; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap (&A[i], &A[j]);
        }
    }
    swap (&A[i+1], &A[high]);
    return (i+1);
}

/*This function implements quick sort*/
void QSort(int A[], int low, int high)
{
    if (low < high)
    {
        int index = partition (A, low, high);

        QSort(A, low, index-1);
        QSort(A, index+1, high);
    }
    
}


int main()
{
    int A[] = {9, 6, 7, 2, 5};
    int n = sizeof(A) / sizeof(A[0]);
    QSort(A, 0, n-1);
    cout << "Sorted: ";

    for (int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}