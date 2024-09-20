#include <stdio.h>

int main() 
{
    int a[1000];
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int odd_index = 0;
    
    for (int i = 0; i < n; ++i) 
    {
        if (a[i] % 2 != 0) 
        {
            int temp = a[i];
            a[i] = a[odd_index];
            a[odd_index] = temp;
            odd_index++;
        }
    }
    
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}