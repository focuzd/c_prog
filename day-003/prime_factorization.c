#include <stdio.h>
#include <math.h>

int is_prime(int num) {
 
    if (num == 0 || num == 1) {
        return 0;
    }

    for(int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

void prime_factorize(int num) {
    
    if (num == 1 || num == 0) {
        printf("Cannot be decomposed into prime factors\n");
        return;
    }

    printf("Prime factoriztion of %d:\n", num);

    int unique = 0, largest = 0, smallest = num, count = 0,
        square_free = 1, temp = num;

    for (int i = 2; i <= temp; i++) {
        int exponent = 0;

        if (temp % i == 0) {
            unique++;

            if (i < smallest) {
                smallest = i;
            }

            if (i > largest) {
                largest = i;
            }
            

            while(temp % i == 0) {
                exponent++;
                temp = temp / i;
            }
            
            if(exponent > 1) {
                square_free = 0;
            }

            count += exponent;
            printf("%d^%d x ", i, exponent);
        }
    }

    printf("\n\nStatistics:\n");

    printf("Unique prime factors: %d\n", unique);
    printf("Total prime factors (with multiplicity): %d\n", count);
    printf("Largest prime factor: %d\n", largest);
    printf("Smallest prime factor: %d\n", smallest);
    
    if (largest == 2 && smallest == 2) {
        printf("Is power of 2: Yes\n");
    } else {
        printf("Is power of 2: No\n");
    }

    if (square_free) {
        printf("Is square-free: Yes\n");
    } else {
        printf("Is square-free: No\n");
    }
    
}

int main(void) {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        fprintf(stderr, "Error: Enter a non-negative number.\n");
        return 1;
    }

    prime_factorize(num);

    return 0;
}
