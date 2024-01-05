#include <stdio.h>
#define size 100
void insertionsorting(int a[size], int n)
{
    int temp, j;
    for(int i=1;i<=n-1;i++)
    {
        temp=a[i];
        j=i-1;
        while(a[j]>temp && j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
    for(int k=0;k<n;k++)
    {
        printf("%d ", a[k]);
    }
}
int main()
{
    int a[size], n;
    printf("Enter no. of entries: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        printf("Enter %d number: ", i+1);
        scanf("%d", &a[i]);
    }
    insertionsorting(a, n);
}