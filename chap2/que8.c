#include <stdio.h>

int main(void)
{
    float amount, interest, monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    amount = amount + (amount * (interest / 12.0f) / 100.0f) - monthly_payment;
    printf("Balance remaining after first payment: %.2f\n", amount);

    amount = amount + (amount * (interest / 12.0f) / 100.0f) - monthly_payment;
    printf("Balance remaining after second payment: %.2f\n", amount);

    amount = amount + (amount * (interest / 12.0f) / 100.0f) - monthly_payment;
    printf("Balance remaining after third payment: %.2f\n", amount);

    return 0;
}
