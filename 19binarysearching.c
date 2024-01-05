#include <stdio.h>
int binarySearch(int a[ ], int low, int high, int key)
{
    int mid;
    while (high >= low)
    {
        mid = (low+high)/2;
        if(key == a[mid])
        {
            printf(“Search is successful\n”);
            return mid+1;
        }
        else if(key < a[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    printf(“Item not found\n”);
    return -1;
}