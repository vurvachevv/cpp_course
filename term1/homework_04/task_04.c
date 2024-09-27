#include <stdio.h>

double calculate_pi(int n) 
{
    double pi_over_4 = 0.0;
    for (int i = 1; i <= n; ++i) 
    {
        double term = (i % 2 == 1 ? 1.0 : -1.0) / (2 * i - 1);  
        pi_over_4 += term;
    }
    return pi_over_4 * 4; 
}

int main() 
{
    int n;
    scanf("%d", &n);
    double pi_approx = calculate_pi(n);
    printf("%.15f\n", pi_approx); 
}
