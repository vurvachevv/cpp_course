#include <stdio.h>
#include <string.h>

void alternate_strings(const char* s1, const char* s2) 
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int min_len = len1 < len2 ? len1 : len2;
    
    for (int i = 0; i < min_len; i++) 
    {
        printf("%c%c", s1[i], s2[i]);
    }
    if (len1 > len2) 
    {
        printf("%s", s1 + min_len);
    }
    else if (len2 > len1) 
    {
        printf("%s", s2 + min_len);
    }
}

int main() 
{
    char s1[100], s2[100];
    
    scanf("%s %s", s1, s2);
    alternate_strings(s1, s2);
}
