#include <stdio.h>

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int j = 0; j < m; j++) 
    {
        for (int i = 1; i < n; i++) 
        {
            int key = matrix[i][j];
            int k = i - 1;
            while (k >= 0 && matrix[k][j] > key) 
            {
                matrix[k + 1][j] = matrix[k][j];
                k--;
            }
            matrix[k + 1][j] = key;
        }
    }
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
