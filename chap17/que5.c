#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20
#define MAX_WORDS 50

int read_line(char* str, int n);

int main(void)
{
    char* words[MAX_WORDS];
    char word[WORD_LEN + 1];
    int i, j, word_len, num_words = 0;

    for (;;) {
        if (num_words == MAX_WORDS) {
            printf("-- No space left. --\n");
            return 0;
        }

        printf("Enter word: ");
        word_len = read_line(word, WORD_LEN);

        if (word_len == 0)
            break;

        for (i = 0; i < num_words; i++)
            if (strcmp(word, words[i]) < 0)
                break;

        for (j = num_words; j > i; j--)
            words[j] = words[j - 1];

        words[i] = malloc(word_len + 1);
        strcpy(words[i], word);
        num_words++;
    }

    printf("In sorted order: ");
    for (i = 0; i < num_words; i++)
        printf(" %s", words[i]);
    printf("\n");
    
    for (i = 0; i < num_words; i++)
        free(words[i]);

    return 0;
}

int read_line(char* str, int n)
{
    int ch, i = 0;
    while ((ch = getchar()) && (ch == ' ' || ch == '\t'));

    while (ch != '\n') {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}