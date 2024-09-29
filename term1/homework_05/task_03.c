#include <stdio.h>
#include <string.h>

int is_palindrom(const char* s) 
{
    int len = strlen(s);
    
    for (int i = 0; i < len / 2; i++) 
    {
        if (s[i] != s[len - i - 1]) 
        {
            return 0;
        }
    }
    return 1;
}

int main() 
{
    char s[100];
    scanf("%s", s);
    
    if (is_palindrom(s)) 
    {
        printf("Yes\n");
    } 
    else 
    {
        printf("No\n");
    }
}
