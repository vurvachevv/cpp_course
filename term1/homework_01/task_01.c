#include <stdio.h>

int main() 
{
    int num;
    printf("Введите число: ");
    scanf("%d", &num);
    if (num % 2 == 0 && ((num >= 0 && num <= 20) || (num > 100 && num < 200))) 
    {
        printf("Yes");
    } 
    else 
    {
        printf("No");
    }
}
