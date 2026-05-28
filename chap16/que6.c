#include <stdio.h>
#include <stdbool.h>

struct date {
    int month, day, year;
};

int compare_date(struct date d1, struct date d2)
{
    if (d1.year != d2.year)
        return (d1.year < d2.year) ? -1 : 1;
    if (d1.month != d2.month)
        return (d1.month < d2.month) ? -1 : 1;
    if (d1.day != d2.day)
        return (d1.day < d2.day) ? -1 : 1;
    return 0;
}

int main(void)
{
    struct date d1, d2;
    int res;

    printf("Enter first date: (mm/dd/yyyy): ");
    scanf("%2d / %2d / %4d", &d1.month, &d1.day, &d1.year);

    printf("Enter second date: (mm/dd/yyyy): ");
    scanf("%2d / %2d / %4d", &d2.month, &d2.day, &d2.year);

    res = compare_date(d1, d2);
    if (res == 0)
        printf("Dates are the same.\n");
    else if (res == -1)
        printf("%d/%d/%d is earlier than %d/%d/%d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
    else
        printf("%d/%d/%d is earlier than %d/%d/%d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);

    return 0;
}