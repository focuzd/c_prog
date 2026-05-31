#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_LEN 60
#define MAX_REMIND 50

struct vstring {
    int len;
    char chars[];
};

int read_line(char* str, int n);

int main(void)
{
    struct vstring* reminder[MAX_REMIND];
    char msg_str[MSG_LEN + 1], day_str[3];
    int i, j, num_remind = 0, day;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left. --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);

        if (day == 0)
            break;

        sprintf(day_str, "%02d", day);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strncmp(day_str, reminder[i]->chars, 2) < 0)
                break;

        for (j = num_remind; j > i; j--)
            reminder[j] = reminder[j - 1];

        reminder[i] = malloc(sizeof(struct vstring) + strlen(msg_str) + strlen(day_str));
        if (reminder[i] == NULL) {
            printf("-- No space left. --\n");
            break;
        }

        reminder[i]->len = strlen(msg_str) + strlen(day_str);
        strcpy(reminder[i]->chars, day_str);
        strcat(reminder[i]->chars, msg_str);
        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminder[i]->chars);

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