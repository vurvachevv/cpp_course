#include <stdio.h>

int main() 
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int isConsecutive = (b == a + 1 && c == b + 1) || (b == a - 1 && c == b - 1);
    int isIncreasing = a < b && b < c;
    int isDecreasing = a > b && b > c;
    int isEqual = a == b && b == c;

    if (isConsecutive) 
    {
        printf("Consecutive ");
    }
    if (isIncreasing) 
    {
        printf("Increasing");
    }
    if (isDecreasing) 
    {
        printf("Decreasing ");
    }
    if (isEqual) 
    {
        printf("Equal");
    }
    if (!isConsecutive && !isIncreasing && !isDecreasing && !isEqual) 
    {
        printf("None");
    }
}
