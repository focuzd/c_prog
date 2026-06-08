#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
//define constants for better code readability

int is_even(int num) {
    return (num % 2 == 0);
}

int is_prime(int num) {
    if (num == 0 || num == 1) {
        return FALSE;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return FALSE;
            // if the number is divisible by any number smaller than its square root, the number is not prime
        }
    }

    return TRUE;
}

int is_perfect(int num) {
    if (num == 0) {
        return FALSE;
    }

    int sum = 0;

    printf("Divisors: ");

    for(int i = 1; i <= num/2; i++) {
        //if num is even, num/2 is the largest proper divisor
        if (num % i == 0) {
            sum += i;
            printf("%d ", i); 
            //print the divisors so we would not need to store them in an array, since did not cover them yet
        }
    }

    printf("%d\n", num); 
    //print the number itself

    return (num == sum);
}

int digit_sum(int num) {
    int sum = 0;

    while (num > 0) {
        sum += (num % 10);
        num /= 10;
    }

    return sum; 
}

int digit_count(int num) {
    int count = 0;
    
    //using do while since a non negative integer would have atleast one digit
    do {
        count++;
        num /= 10;
    } while(num > 0);
    
    return count;
}

// above functions num is a formal parameter updating it won't change the actual variable num, pass by value


int main(void)
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        fprintf(stderr, "Error: Enter a non-negative number\n");
        return 1;
    }

    printf("Number: %d\n", num);
    
    if (is_even(num)) {
        printf("Even: Yes\n");
    } else {
        printf("Even: No\n");
    }

    if (is_prime(num)) {
        printf("Prime: Yes\n");
    } else {
        printf("Prime: No\n");
    }
    
    if (is_perfect(num)) {
        printf("Perfect: Yes\n");
    } else {
        printf("Perfect: No\n");
    }

    printf("Sum of digits: %d\n", digit_sum(num));
    printf("Digit count: %d\n", digit_count(num));

    return 0;
}
