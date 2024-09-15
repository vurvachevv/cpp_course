#include <stdio.h>

int main() 
{
    int a, b, c;
    printf("Введите три числа: ");
    scanf("%i %i %i", &a, &b, &c);

    int Consecutive = (b == a + 1 && c == b + 1) || (b == a - 1 && c == b - 1);
    int Increasing = a < b && b < c;
    int Decreasing = a > b && b > c;
    int Equal = a == b && b == c;

    if (Consecutive) 
    {
        printf("Consecutive ");
    }
    if (Increasing) 
    {
        printf("Increasing");
    }
    if (Decreasing) 
    {
        printf("Decreasing ");
    }
    if (Equal) 
    {
        printf("Equal");
    }
    if (!Consecutive && !Increasing && !Decreasing && !Equal) 
    {
        printf("None");
    }
}
