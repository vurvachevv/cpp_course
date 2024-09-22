#include <stdio.h>

int sum_of_digits_rec(int num) 
{
    if (num == 0) 
    {
        return 0;
    }
    return (num % 10) + sum_of_digits_rec(num / 10); 
}

int main() 
{
    printf("%d\n", sum_of_digits_rec(123));
    printf("%d\n", sum_of_digits_rec(55955));
    printf("%d\n", sum_of_digits_rec(4));
    printf("%d\n", sum_of_digits_rec(0));
}