#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int sum = 0;
    char ch;
    int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1,
                    1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    printf("Enter a word: ");
    while((ch = getchar()) != '\n') {
        sum += values[tolower(ch) - 'a'];
    }

    printf("Scrabble value: %d\n", sum);

    return 0;
}
