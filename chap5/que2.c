#include <stdio.h>

int main(void)
{
    int hours, minutes;
    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hours, &minutes);
    
    if(hours < 0 || hours > 23) {
        printf("Invalid time\n");
        return 1;
    }

    if (minutes < 0 || minutes > 59) {
        printf("Invalid time\n");
        return 1;
    }
    
    printf("Equivalent 12-hour time: ");
    
    if (hours == 0) {
        printf("%.2d:%.2d AM\n", 12, minutes);
    } else if (hours < 12) {
        printf("%.2d:%.2d AM\n", hours, minutes); 
    } else if (hours == 12) {
        printf("%.2d:%.2d PM\n", hours, minutes);
    } else {
        printf("%.2d:%.2d PM\n", hours % 12, minutes);
    }

    return 0;
}
