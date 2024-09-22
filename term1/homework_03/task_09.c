#include <stdio.h>

void alice(int n);

void bob(int n);

void alice(int n) 
{
    if (n == 1) 
    {
        return;
    }
    int new_n = n * 3 + 1;
    printf("Alice: %d\n", new_n);
    bob(new_n);
}

void bob(int n) 
{
    while (n % 2 == 0) 
    {
        n /= 2;
        printf("Bob: %d\n", n);
    }
    
    if (n != 1) 
    {
        alice(n);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    alice(n);
}
