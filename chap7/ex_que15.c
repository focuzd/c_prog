#include <stdio.h>

int main(void)
{
    int curr_fact = 1, prev_fact = 1;
    int num;
    
    num = 1;
    while(curr_fact >= prev_fact) {
        prev_fact = curr_fact;
        curr_fact = 1;
        for (int i = 1; i <= num; i++) {
            curr_fact *= i;
        }
        printf("%-5d %15d\n", num, curr_fact);
        num++;
    }

    printf("Overflow occured at %d\n", num);

    return 0;
}

// Smallest number for which overflow occured:
// short: 9
// int: 
// long:
// long long:
// float:
// double:
// long double: 
