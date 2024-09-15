#include <stdio.h>

int main() 
{
    int n;
    printf("Введите число: ");
    scanf("%d", &n);
    int length = 1;  
    int max = n;     
    printf("%d ", n);
    while (n != 1) 
    {
        if (n % 2 == 0) 
        {
            n = n / 2;  
        } 
        else 
        {
            n = 3 * n + 1;  
        }
        printf("%d ", n);
        
        length++;
        
        if (n > max) 
        {
            max = n;
        }
    }
    printf("\n");
    printf("Length = %d, Max = %d\n", length, max);
}
