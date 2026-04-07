#include <stdio.h>

int main(void)
{
    float num, max = -1e8;

    for (;;) {
        printf("Enter a number: ");
        scanf("%f", &num);

        if (num > max){
            max = num;
        }

        if (num <= 0) {
            break;
        }
    }

    printf("\nThe largest number entered was %f\n", max);

    return 0;
}
