#include <stdio.h>

int main(void)
{
    int num, denom, rem, num1, num2;

    printf("Enter a fraction: ");
    scanf("%d / %d", &num, &denom);

    if (denom == 0) {
        printf("Error: Invalid fraction\n");
        return 1;
    }
    
    num1 = (num >= 0) ? num : -num;
    num2 = (denom > 0) ? denom : -denom;
    
    // no need to swap them, they get swapped if num1 < num2

    while (num2 != 0) {
        rem = num1 % num2;
        num1 = num2;
        num2 = rem;
    }

    num /= num1;
    denom /= num1;

    printf("In lowest terms: %d/%d\n", num, denom);

    return 0;
}
