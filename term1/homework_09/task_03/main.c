#include <stdio.h>

int main() 
{
#ifdef COUNT
    for (int i = 1; i <= COUNT; ++i) 
    {
        printf("%d ", i);
    }
    printf("\n");
#else
    printf("No Count!\n");
#endif
}
