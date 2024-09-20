#include <stdio.h>

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);
    int sum[m];
    
    for (int i = 0; i < m; i++) 
    {
        sum[i] = 0;
    }
    
    for (int i = 0; i < n; i++) 
    {
        
        for (int j = 0; j < m; j++) 
        {
            int x;
            scanf("%d", &x);
            sum[j] += x;
        }
    }
    
    for (int i = 0; i < m; i++) 
    {
        printf("%d ", sum[i]);
    }
}
