#include <stdio.h>
#include <stdbool.h>

struct date {
    int month, day, year;
};

bool isleap(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0));
}

int day_of_year(struct date d)
{
    int i, day;
    int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isleap(d.year))
        days_in_month[2]++;

    day = d.day;
    for (i = 0; i < d.month; i++)
        day += days_in_month[i];

    return day;
}

int compare_date(struct date d1, struct date d2)
{
    if (d1.year < d2.year)
        return -1;
    else if (d1.year > d2.year)
        return 1;
    else {
        if (d1.month < d2.month)
            return -1;
        else if (d1.month > d2.month)
            return 1;
        else {
            if (d1.day < d2.day)
                return -1;
            else if (d1.day > d2.day)
                return 1;
            else
                return 0;
        }         
    }
}

int main(void)
{
    struct date d1 = { 1, 1, 2008 };
    struct date d2 = { 3, 1, 2008 };
    printf("%d\n", compare_date(d1, d2));
}