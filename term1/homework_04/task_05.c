#include <stdio.h>
#include <math.h>
#define eps 1e-5

int main() 
{
    double x1, y1, r1, x2, y2, r2;
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    
    if (distance > r1 + r2) 
    {
        printf("Do not intersect\n");
    } 
    else if (fabs(distance - (r1 + r2)) < eps || fabs(distance - fabs(r1 - r2)) < eps) 
    {
        printf("Touch\n");
    } 
    else if (distance < fabs(r1 - r2)) 
    {
        printf("Do not intersect\n");
    } 
    else 
    {
        printf("Intersect\n");
    }
}
