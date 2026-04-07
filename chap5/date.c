#include <stdio.h>

int main(void)
{
    int month, day, year;

    printf("Enter date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &month, &day, &year);

    printf("Dated this %d", day);

    switch (day % 10) {
        case 1 : 
            printf("st ");
            break;
        case 2 : 
            printf("nd ");
            break;
        case 3 : 
            printf("rd ");
            break;
        default:
            printf("th ");
            break;
    }

    printf("day of ");

    switch (month) {
        case 1 : printf("January");
                 break;
        case 2 : printf("February");
                 break;
        case 3 : printf("March");
                 break;
        case 4 : printf("April");
                 break;
        case 5 : printf("May");
                 break;
        case 6 : printf("June");
                 break;
        case 7 : printf("July");
                 break;
        case 8 : printf("August");
                 break;
        case 9 : printf("September");
                 break;
        case 10 : printf("October");
                  break;
        case 11 : printf("November");
                  break;
        case 12 : printf("December");
                  break;
    }

    printf(", %d\n", year);

    return 0;
}

