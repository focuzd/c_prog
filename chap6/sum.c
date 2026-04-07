#include <stdio.h>

int main(void)
{
    int n, sum = 0;
    
    printf("This program sums of a series of integers\n");
    printf("Enter integers (0 to terminates): ");

    scanf("%d", &n);
    while (n != 0) {
        sum += n;
        scanf("%d", &n);
    }

    printf("The sum is %d\n", sum);

    return 0;
}
