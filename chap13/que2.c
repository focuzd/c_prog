#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char* s, int n);

int main(void)
{
    int month, day, i, j, hour, min, num_remind = 0;
    char reminder[MAX_REMIND][MSG_LEN + 9];
    char msg_str[MSG_LEN + 1], timestamp_str[12];

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("--No Space Left--\n");
            break;
        }

        printf("Enter reminder(mm/dd hh:min message): ");
        scanf("%2d / %2d", &month, &day);

        if (day == 0)
            break;
        else if (day < 0 || day > 31) {
            printf("--Invalid Day--\n");
            while (getchar() != '\n');
            continue;
        }

        scanf("%2d : %2d", &hour, &min);
        read_line(msg_str, MSG_LEN);
        sprintf(timestamp_str, "%02d/%02d %02d:%02d", month, day, hour, min);

        for (i = 0; i < num_remind; i++)
            if (strcmp(timestamp_str, reminder[i]) < 0)
                break;

        for (j = num_remind; j > i; j--)
            strcpy(reminder[j], reminder[j - 1]);

        strcpy(reminder[i], timestamp_str);
        strcat(reminder[i], msg_str);
        num_remind++;
    }

    printf("\nMonth/Day Time Reminder\n");
    for (i = 0; i < num_remind; i++)
        puts(reminder[i]);

    return 0;
}

int read_line(char* s, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            s[i++] = ch;
    s[i] = '\0';

    return i;
}