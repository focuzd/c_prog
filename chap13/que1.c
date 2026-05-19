#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main(void)
{
    char s[MAX_LEN + 1], smallest[MAX_LEN + 1], largest[MAX_LEN + 1];

    printf("Enter word: ");
    scanf("%s", s);
    strcpy(smallest, s);
    strcpy(largest, s);

    do {
        printf("Enter word: ");
        scanf("%s", s);

        if (strcmp(s, smallest) < 0)
            strcpy(smallest, s);

        else if (strcmp(s, largest) > 0)
            strcpy(largest, s);
    } while (strlen(s) != 4);

    printf("\nSmallest word: ");
    puts(smallest);
    printf("Largest word: ");
    puts(largest);
}