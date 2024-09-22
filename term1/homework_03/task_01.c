#include <stdio.h>

int cube(int num) 
{
    return num * num * num;
}

int main() 
{
    printf("%i\n", cube(5));
    return 0;
}