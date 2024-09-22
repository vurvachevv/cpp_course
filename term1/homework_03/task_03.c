#include <stdio.h>

void print_even(int a, int b) 
{
    if (a > b) 
    {
        int temp = a;
        a = b;
        b = temp;
    }

    for (int i = a; i <= b; i++) 
    {
        if (i % 2 == 0) 
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() 
{
    print_even(2, 15);
    print_even(1, 15);
    print_even(-7, 3);
}