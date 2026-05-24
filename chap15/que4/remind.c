#include <stdio.h>
#include <string.h>
#include "readline.h"

#define MSG_LEN 60
#define MAX_REMIND 50

int main(void)
{
    char msg_str[MSG_LEN + 1], day_str[3];
    char remind[MAX_REMIND][MSG_LEN + 3];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind >= MAX_REMIND) {
            printf("-- No more space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        
        sprintf(day_str, "%02d", day);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, remind[i]) < 0)
                break;

        for (j = num_remind; j > i; j--)
            strcpy(remind[j], remind[j - 1]);

        strcpy(remind[i], day_str);
        strcat(remind[i], msg_str);
        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        puts(remind[i]);

    return 0;
}