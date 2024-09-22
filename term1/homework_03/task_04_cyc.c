#include <stdio.h>

int sum_of_digits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        sum += num % 10; 
        num /= 10;       
    }
    return sum;
}

int main() 
{
    printf("%d\n", sum_of_digits(123));
    printf("%d\n", sum_of_digits(55955));
    printf("%d\n", sum_of_digits(4));
    printf("%d\n", sum_of_digits(0));
}