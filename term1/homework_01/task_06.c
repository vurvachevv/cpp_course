#include <stdio.h>

int hailstone_length(int n) 
{
    int length = 1;
    
    while (n != 1) 
    {
        if (n % 2 == 0) 
        {
            n = n / 2;
        } else 
        {
            n = 3 * n + 1;
        }
        length++; 
    }
    
    return length;
}

int main() {
    int a, b;
    
    printf("Введите два числа: ");
    scanf("%d %d", &a, &b);
    
    int max_n = a;
    int max_length = hailstone_length(a);
    
    for (int n = a + 1; n <= b; n++) 
    {
        int current_length = hailstone_length(n);
        if (current_length > max_length) 
        {
            max_n = n;
            max_length = current_length;
        }
    }
    printf("%d %d\n", max_n, max_length);
}
