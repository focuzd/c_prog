#include <stdio.h>

void split_date(int day_of_year, int year, int *month, int *day);

int main(void)
{
    int n, year, month, day;
    scanf("%d %d", &n, &year);

    split_date(n, year, &month, &day);
    printf("%d/%d/%d\n", day, month, year);

    return 0;
}

void split_date(int day_of_year, int year, int *month, int *day)
{
    int i;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        days[1] += 1;

    i = 0;
    while (day_of_year > days[i]) {
        day_of_year -= days[i];
        i++;
    }

    *month = i+1;
    *day = day_of_year;
}
    
