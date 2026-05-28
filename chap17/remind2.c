#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char* str, int n);

int main(void)
{
    char* reminder[MAX_REMIND];
    char msg_str[MSG_LEN + 1], day_str[3];
    int i, j, day, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left. --\n");
            break;
        }

        printf("Enter a day and reminder: ");
        scanf("%2d", &day);

        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminder[i]) < 0)
                break;

        for (j = num_remind; j > i; j--)
            reminder[j] = reminder[j - 1];

        reminder[i] = malloc(2 + strlen(msg_str) + 1);
        if (reminder[i] == NULL) {
            printf("-- No space left. --\n");
            break;
        }

        strcpy(reminder[i], day_str);
        strcat(reminder[i], msg_str);

        num_remind++;
    }

    printf("Day Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminder[i]);

    return 0;
}

int read_line(char* str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';

    return i;
}