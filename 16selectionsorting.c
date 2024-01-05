#include <stdio.h>
#define size 100
void selectionsorting(int a[size], int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
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
    selectionsorting(a, n);
}