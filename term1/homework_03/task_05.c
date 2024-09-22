#include <stdio.h>

void print_binary(int num) 
{
    if (num > 0) 
    {
        print_binary(num / 2);
        printf("%d", num % 2);
    } 
}

int main() 
{
    print_binary(6);
    printf("\n");

    print_binary(128);
    printf("\n");

    print_binary(4823564);
    printf("\n");
    
    //это условие позволяет обойти проблему, свяазанную с тем, что если добавить условие на 0 в нашу функцию, то все числа в двоичном
    //представлении будут иметь 0 в самом начале, чего не может быть
    if (0 == 0)
    {    
        printf("0");
    }
    printf("\n");
}