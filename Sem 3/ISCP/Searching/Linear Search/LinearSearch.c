#include <stdio.h>
void linearSearch(int A[], int n)
{
    int len = sizeof(A)/sizeof(int);
    int flag =0;
    for (int i=0; i<len; i++)
    {
        if (A[i]==n)
        {
            printf("Element is found.");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Element is not present in the array.");
    }
}
int main()
{
    int arr[] = {7,4,24,10,55};
    int n;
    printf("Enter a number to search for in the array:");
    scanf("%d", &n);
    linearSearch(arr,n);
}