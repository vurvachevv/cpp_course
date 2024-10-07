#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double* px1, double* px2) 
{
    const double eps = 1e-10;
    double discriminant = b * b - 4 * a * c;

    if (fabs(discriminant) < eps) 
    {
        *px1 = -b / (2 * a);
        return 1;
    } 
    else if (discriminant > eps) 
    {
        double sqrt_d = sqrt(discriminant);
        *px1 = (-b + sqrt_d) / (2 * a);
        *px2 = (-b - sqrt_d) / (2 * a);
        return 2;
    } 
    else 
    {
        return 0;
    }
}

int main() 
{
    double x1, x2;
    int result = solve_quadratic(1, -3, 2, &x1, &x2);

    if (result == 0) 
    {
        printf("Корней нет\n");
    } 
    else if (result == 1) 
    {
        printf("Один корень: %.10f\n", x1);
    } 
    else if (result == 2) 
    {
        printf("Два корня: %.10f и %.10f\n", x1, x2);
    }
}
