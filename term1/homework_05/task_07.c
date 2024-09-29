#include <stdio.h>
#include <string.h>

void safe_strcpy(char dest[], size_t dest_size, const char src[]) 
{
    for (size_t i = 0; i < dest_size - 1 && src[i] != '\0'; i++) 
    {
        dest[i] = src[i];
    }
    
    dest[dest_size - 1] = '\0';
}

int main() 
{
    char a[10] = "Mouse";
    char b[50] = "LargeElephant";

    safe_strcpy(a, sizeof(a), b);
    printf("%s\n", a);
}
