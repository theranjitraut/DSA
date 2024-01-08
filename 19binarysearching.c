#include <stdio.h>
#define size 10
int binarysearching(int a[ ], int low, int high, int key)
{
    int mid;
    while (high >= low)
    {
        mid = (low+high)/2;
        if(key == a[mid])
        {
            printf("Search is successful\n");
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
    printf("Search is unsuccessful\n");
    return -1;
}
int main()
{
    int a[size], n, key;
    printf("Enter no. of entires: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        printf("Enter %d number: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("Enter key to find: ");
    scanf("%d", &key);
    printf("The location is: %d\n", binarysearching(a, 0, n, key));
}
