#include <stdio.h>
#include <math.h>
#define DIFF 1e-5

int main(void)
{
    double num, prev_est = 1, new_est = 1;
    printf("Enter a positive number: ");
    scanf("%lf", &num);

    do {   
        prev_est = new_est;
        new_est = (prev_est + (num/prev_est))/2;
    } while (fabs(prev_est - new_est) >= DIFF);

    printf("Square root: %lf\n", new_est);
    
    return 0;
}
