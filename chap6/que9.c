#include <stdio.h>

int main(void)
{
    float amount, interest, monthly_payment;
    int count, i;

    printf("Enter amount of loan: ");
    scanf("%f", &amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);
    printf("Enter the number of payments: ");
    scanf("%d", &count);
    
    for (i = 1; i <= count; i++) {
        amount = amount + (amount * (interest / 12.0f) /
                100.0f) - monthly_payment;
        printf("Balance remaining after payment %d: %.2f\n",
                i, amount);
    }

    return 0;
}
