#include <stdio.h>

int main(void) 
{
    int day1, month1, year1, day2, month2, year2, flag = 0;

    printf("Enter first date (mm/dd/yyyy): ");
    scanf("%d / %d / %d", &month1, &day1, &year1);

    printf("Enter second date (mm/dd/yyyy): ");
    scanf("%d / %d / %d", &month2, &day2, &year2);

    if (year1 < year2) {
        flag = 1;
    } else if (year1 > year2) {
        flag = 2;
    }

    if (flag == 0 && month1 < month2) {
        flag = 1;
    } else if (flag == 0 && month1 > month2) {
        flag = 2;
    }

    if (flag == 0 && day1 < day2) {
        flag = 1;
    } else if (flag == 0 && day1 > day2) {
        flag = 2;
    }

    if (flag == 0) {
        printf("Both dates are same\n");
    } else if (flag == 1) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month1, day1,
                year1, month2, day2, year2);
    } else {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month2, day2,
                year2, month1, day1, year1);
    }

    return 0;
}
