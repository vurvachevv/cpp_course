#include <stdio.h>

int main() 
{
    int a[1000];
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    for (int i = n - 1; i >= 0; --i) 
    {
        a[2 * i + 1] = a[i];
        a[2 * i] = a[i];
    }
    n *= 2;

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}