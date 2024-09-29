#include <stdio.h>
#include <ctype.h>

void encrypt(char* str, int k) 
{
    for (int i = 0; str[i] != '\0'; i++) 
    {
        char c = str[i];
        
        if (isalpha(c)) 
        {
            char base = islower(c) ? 'a' : 'A';
            str[i] = (c - base + k) % 26 + base;
        }
    }
}

int main() 
{
    char str[1000];
    int k;
    
    scanf("%d", &k);
    scanf("%s", str);
    encrypt(str, k);
    printf("%s\n", str);
}
