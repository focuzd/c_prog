#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD_LEN 20
#define MAX_WORDS 30

int read_line(char* str, int n);

int main(void)
{
    char words[MAX_WORDS][WORD_LEN + 1];
    char sentence[MAX_WORDS * WORD_LEN + 1];
    int i, num_words = 0;
    char* p, * q;
    char punctuation;


    printf("Enter a sentence: ");
    read_line(sentence, MAX_WORDS * WORD_LEN);

    p = q = sentence;
    while (*p) {
        if (!isspace(*p)) {
            q = p;
            while (!isspace(*q) && *(q+1) != '\0')
                q++;
            strncpy(words[num_words], p, q - p);
            words[num_words][q - p] = '\0';
            num_words++;
            p = q;
        }
        p++;
    }

    punctuation = *(p - 1);
    printf("Reversal of Sentence: ");
    for (i = num_words - 1; i >= 0; i--) {
        printf(" %s", words[i]);
    }
    printf("%c\n", punctuation);

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