#include <stdio.h>

int main() 
{
    int a, b, c;
    printf("Введите три числа: ");
    scanf("%d %d %d", &a, &b, &c);
    int d = (a % c == 0) ? a : (a + (c - a % c));
    
    for (int i = d; i <= b; i += c) 
    {
        printf("%d ", i);
    }
    
}
