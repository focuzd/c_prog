#include <stdio.h>

int main(void)
{
    int num, reversed = 0, temp;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    temp = (num >= 0) ? num : -num;

    do {
        reversed *= 10;
        reversed += (temp % 10);
        temp /= 10;
    } while (temp > 0);

    reversed = (num < 0) ? -reversed : reversed;

    printf("Reversed number: %d\n", reversed);

    return 0;
}
