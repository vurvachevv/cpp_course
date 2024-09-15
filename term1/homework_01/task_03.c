#include <stdio.h>

int main() 
{
    int n;
    printf("Введите число: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        printf("%3d -> %3d -> %3d\n", i, i * i, i * i * i);
    }
}
