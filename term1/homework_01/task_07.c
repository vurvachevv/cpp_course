#include <stdio.h>

int main() 
{
    int n, m;
    int sum = 0;

    printf("Введите два числа: ");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            sum += ( (i + j) % 2 == 0 ? 1 : -1 ) * (i * j);
        }
    }
    printf("%d", sum);
}
