#include <stdio.h>

int main(void)
{
    long int num, max_value = 1;
    int even_steps = 0, odd_steps = 0;

    printf("Enter a number: ");
    scanf("%ld", &num);

    if (num <= 0) {
        fprintf(stderr, "Error: Enter a positive number\n");
        return 1;
    }

    while (num != 1) {
    
        printf("%ld -> ", num);

        if (num > max_value) {
            max_value = num;
        }

        if (num % 2 == 0) {
            num = num / 2;
            even_steps++;
        } else {
            num = (3*num) + 1;
            odd_steps++;
        }
            
        if ((even_steps + odd_steps) % 10 == 0) {
            printf("\n");
        }
    }

    if ((even_steps + odd_steps) % 10 == 0) {
            printf("\n");
    }

    printf("%ld\n\n", num);

    printf("Statistics:\n");
    printf("Steps to reach one: %d\n", even_steps + odd_steps);
    printf("Maximum value reached: %ld\n", max_value);
    printf("Even steps: %d\n", even_steps);
    printf("Odd steps: %d\n", odd_steps);
    printf("Sequence length: %d\n", even_steps + odd_steps + 1);

    return 0;
}

