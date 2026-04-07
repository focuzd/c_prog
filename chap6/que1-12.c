#include <stdio.h>

int main(void)
{
    int num, d;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (d = 2; d*d <= num; d++) {
        if (num % d == 0) {
            break;
        }
    }

    // if d * d <= num - premature break
    // if d * d > num - normal break, condition becomes false

    if (d * d <= num || num == 1) {
        printf("%d is not prime\n", num);
    } else {
        printf("%d is prime\n", num);
    }

    return 0;
}
