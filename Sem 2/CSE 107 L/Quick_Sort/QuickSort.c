#include <stdio.h>

// function to swap elements
void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

//Function to find the partition position
int partition(int array[], int low, int high) 
{  
  int pivot = array[high];  // select the rightmost element as pivot
  int i = (low - 1);    // pointer for greater element

  for (int j = low; j < high; j++)  // traverse each element of the array, compare them with the pivot 
  {
    if (array[j] <= pivot) 
    {  
      i++;  // if element smaller than pivot is found, swap it with the greater element pointed by i
      swap(&array[i], &array[j]);   // swap elements at i and j
    }
  }
  swap(&array[i + 1], &array[high]);// swap the pivot element with the greater element at i
  return (i + 1);   // returning the partition point
}
//Function to quick sort the elements
void quickSort(int array[], int start, int end) 
{
  if (start < end) 
  {  
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int p = partition(array, start, end);
    
    quickSort(array, start, p - 1); // recursive calling left subarray
    
    quickSort(array, p + 1, end);// recursive calling right subarray
  }
}
// Function to print array elements
void print(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main() 
{
  int n;    //Stores size of the array
  printf("\nEnter the size of array:");
  scanf("%d", &n);  
  int A[n]; //Array to be sorted
  printf("\nEnter the elements:");
  for (int i=0; i<n;i++)
  {
      scanf("%d", &A[i]);
  }
  printf("Unsorted Array\n");
  print(A, n);
  
  // perform quicksort on data
  quickSort(A, 0, n - 1);
  
  printf("Sorted array in ascending order: \n");
  print(A, n);
}