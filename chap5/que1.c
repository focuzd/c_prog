#include <stdio.h>

int main(void)
{
    int num, digits;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num >= 0 && num <= 9) {
        digits = 1;
    } else if (num >= 10 && num <= 99) {
        digits = 2;
    } else if(num >= 100 && num <= 999) {
        digits = 3;
    } else if (num >= 1000 && num <= 9999) {
        digits = 4;
    }

    printf("The number %d has %d digits\n", num, digits);

    return 0;
}
