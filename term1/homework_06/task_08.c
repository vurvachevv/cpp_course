#include <stdio.h>

int* max(int* pa, int* pb) 
{
    return (*pa > *pb) ? pa : pb;
}

int main() 
{
    int a = 10;
    int b = 30;
    int c = 20;

    *max(max(&a, &b), &c) += 1;
    printf("%i %i %i\n", a, b, c);
}
