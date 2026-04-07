#include <stdio.h>

int main(void)
{
    float amount, taxed_amount;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    taxed_amount = amount + (amount * 5.0f / 100.0f);

    printf("With tax added: %.2f\n", taxed_amount);

    return 0;
}
