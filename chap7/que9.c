#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hours, minutes, hours24;
    char m;

    printf("Enter a 12-hour time: ");
    scanf("%d : %d %c", &hours, &minutes, &m);

    if (hours > 12 || hours < 1 || minutes < 0 || minutes > 59) {
        fprintf(stderr, "Ivalid input\n");
        return 1;
    }
    
    if (toupper(m) == 'A') {
        hours24 = hours;
        if (hours == 12) {
            hours24 = 0;
        }
    } else if (toupper(m) == 'P') {
        hours24 = hours + 12;
        if (hours == 12) {
            hours24 = 12;
        }
    } else {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    printf("Equivalent 24-hour time: %d:%d\n", hours24, minutes);

    return 0;
}
