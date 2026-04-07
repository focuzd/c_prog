#include <stdio.h>

int main(void)
{
    int total_days, start_day, i;
    
    printf("Enter number of days in month: ");
    scanf("%d", &total_days);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start_day);

    for (i = 1; i < start_day; i++) {
        printf("   ");
    }

    for (i = 1; i <= total_days; i++) {
        printf("%2d ", i);

        if ( (i + start_day - 1) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}
