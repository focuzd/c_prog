#include <stdio.h>

int main(void)
{
    int digit1, digit2, digit3, reversed;

    printf("Enter a three digit number : ");
    scanf("%1d%1d%1d", &digit3, &digit2, &digit1);

    reversed = (digit1 * 10 + digit2) * 10 + digit3;
    
    printf("The reversal is: %d\n", reversed);

    return 0;
}
