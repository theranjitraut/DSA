#include <stdio.h>
int linearSearch(int arr[ ], int n, int key) 
{
    int i, location; 
    for(i=0; i<n; i++) 
    {
        if(arr[i]==key) 
        {
        printf(“Search is successful\n”); 
        location = i+1;
        return location;
        } 
    }
    printf(“Key not found\n”); 
    location=-1;
    return location;
}
int main()
{
    
}