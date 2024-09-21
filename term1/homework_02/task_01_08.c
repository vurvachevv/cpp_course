#include <stdio.h>

int main() 
{
    int a[1000];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int k;
    scanf("%d", &k);
    int temp[1000];
    
    for (int i = 0; i < n; ++i) 
    {
        temp[(i + k) % n] = a[i];
    }
    
    for (int i = 0; i < n; ++i) 
    {
        a[i] = temp[i];
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}