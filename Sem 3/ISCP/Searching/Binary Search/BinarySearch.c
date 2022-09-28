#include <stdio.h>

int main()
{
    int arr[] = {4,8,15,24,37,54,66,78,92};
    int len = sizeof(arr)/sizeof(int);

    //Binary search
    int flag = 0;
    int low = 0;
    int high = len-1;
    int key;
    printf("Enter the number to search:");
    scanf("%d",&key);
    while (low <= high)
    {
        int mid = (low+high)/2;
        if (key == arr[mid])
        {
            printf("Number is present.");
            flag = 1;
            break;
        }
        else if (key >arr[mid])
        {
            low = mid + 1;
            continue;
        }
        else if (key < arr[mid])
        {
            high = mid-1;
            continue;
        }
        
    }
    if (flag==0)
    {
        printf("Given number is not present in the array.");
    }
}