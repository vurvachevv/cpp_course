#include <stdio.h>


int main() 
{
    int n;
    scanf("%d", &n);
    
    int INT_MAX = 2147483647;
    int min = INT_MAX;

    for (int i = 0; i < n; ++i) 
    {
        int a;
        scanf("%d", &a);
        if (a < min) 
        {
            min = a;
        }
    }

    printf("%d", min);
}
