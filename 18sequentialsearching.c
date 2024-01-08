#include <stdio.h>
int linearsearching(int arr[ ], int n, int key) 
{
    for(int i=0; i<n; i++) 
    {
        if(key == a[i]) 
        {
        printf(“Search is successful\n”); 
        return i+1;
        } 
    }
    printf(“Search is unsuccessful\n”); 
    return -1;
}
int main()
{
    int a[size], n, key;
    printf("Enter no. of entries: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        printf("Enter %d number: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("Enter key to find: ");
    scanf("%d", &key);
    printf("The location is: %d\n", linearsearching(a, n, key));
}
