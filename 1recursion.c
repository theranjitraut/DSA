// Sum of n natural number
// Factorial
// #include <stdio.h>
// int factorial(int n)
// {
//     if(n==1) return 1;
//     else return n*factorial(n-1);
// }
// int main()
// {
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     printf("The factorial of %d is %d", n, factorial(n));
// }
// Fibonacci Series
// Multiplication of n natural numbers
// Tower of Hanoi
#include <stdio.h>
void towerofHanoi(int, char, char, char);
int main()
{
    int n;
    printf("Enter no. of disk in peg A: ");
    scanf("%d", &n);
    towerofHanoi(n, 'A', 'C', 'B');
}
void towerofHanoi(int n, char from, char to, char aux)
{
    if(n==1)
    {
        printf("Move disk %d from %c to %c\n", n, from, to);
        return;
    }
    towerofHanoi(n-1,from,aux,to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerofHanoi(n-1,aux,to,from);
}
