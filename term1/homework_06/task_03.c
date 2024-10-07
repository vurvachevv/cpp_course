#include <stdio.h>

void cube(float* px) 
{
    *px = (*px) * (*px) * (*px);
}

int main() 
{
    float num;
    
    scanf("%f", &num);
    cube(&num);
    printf("%.2f\n", num);
}
