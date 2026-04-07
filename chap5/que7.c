#include <stdio.h>

int main(void)
{
    int num1, num2, num3, num4, min1, max1, min2, max2, min, max;
    
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    
    if (num1 > num2) {
        min1 = num2;
        max1 = num1;
    } else {
        min1 = num1;
        max1 = num2;
    }

    if (num3 > num4) {
        min2 = num4;
        max2 = num3;
    } else {
        min2 = num3;
        max2 = num4;
    }

    if (max1 > max2) {
        max = max1;
    } else {
        max = max2;
    }

    if (min1 < min2) {
        min = min1;
    } else {
        min = min2;
    }

    printf("Largest : %d\n", max);
    printf("Smallest: %d\n", min);

    return 0;
}
    
