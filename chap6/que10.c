#include <stdio.h>

int main(void)
{
    int month, day, year, emonth = 12, eday = 31, eyear = 9999,
        is_early = 0;

    for (;;) {
        printf("Enter a date (mm/dd/yyyy): ");
        scanf("%d / %d / %d", &month, &day, &year);
        is_early = 0;
            
        if (day == 0 && month == 0 && year == 0) {
            break;
        }

        if (year < eyear) {
            is_early = 1;
        }

        if (year == eyear && month < emonth) {
            is_early = 1;
        }

        if (year == eyear && month == emonth && day < eday) {
            is_early = 1;
        }

        if (is_early) {
            eday = day;
            emonth = month;
            eyear = year;
        }
        
    }

    printf("%d/%d/%d is the earliest date\n", emonth, eday, 
            eyear);
    return 0;
}
