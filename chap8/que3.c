#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool digit_seen[10] = {false};
    int digit, i;
    long num, n;

    do {
        printf("Enter a number: ");
        scanf("%ld", &num);
        n = num;

        while (n > 0) {
            digit = n % 10;
            if (digit_seen[digit]) {
                break;
            }

            digit_seen[digit] = true;
            n /= 10;
        }
        
        if (num > 0) {
            if (n > 0) {
                printf("Repeated digit\n");
            } else {
                printf("No repeated digit\n");
            }
        }

        for(i = 0; i < 10; i++) {
            digit_seen[i] = false;
        }
    } while (num > 0);
    
    return 0;
}
