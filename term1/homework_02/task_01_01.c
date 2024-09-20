#include <stdio.h>

int main() 
{
    int a[1000];
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    
    for (int i = 0; i < n; ++i) 
    {
        a[n + i] = a[i];
    }
    n *= 2;
    
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}