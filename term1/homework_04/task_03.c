#include <stdio.h>

int leap_year(int year) 
{
    return (year % 4 == 0);
}

float yearfrac(int year, int day) 
{
    int days_in_year = leap_year(year) ? 366 : 365;
    return (float)day / days_in_year;
}

int main() 
{
    int year, day;
    scanf("%d %d", &year, &day);
    printf("%.5f\n", yearfrac(year, day));
}
