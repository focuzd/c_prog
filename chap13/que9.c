#include <stdio.h>
#include <ctype.h>

#define SENTENCE_LEN 50

int compute_vowel_count(const char* sentence);
int read_line(char* str, int n);

int main(void)
{
    char sentence[SENTENCE_LEN + 1];
    int count;

    printf("Enter a sentence: ");
    read_line(sentence, SENTENCE_LEN);

    count = compute_vowel_count(sentence);
    printf("Your sentence contains %d vowels\n",count);

    return 0;
}

int compute_vowel_count(const char* sentence)
{
    const char* p = sentence;
    int count = 0;

    while (*p) {
        switch (tolower(*p)) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            count++; break;
        }
        p++;
    }

    return  count;
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