#include <stdio.h>

unsigned long long arrangements(int n, int k) 
{
    unsigned long long result = 1;
    for (int i = 0; i < k; ++i) 
    {
        result *= (n - i);
    }
    return result;
}

int main() 
{
    int n, k;
    scanf("%d %d", &n, &k);
    unsigned long long result = arrangements(n, k);
    printf("%llu\n", result);
}
