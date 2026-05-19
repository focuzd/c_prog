#include <stdio.h>
#include <ctype.h>

#define SENTENCE_LEN 70

double compute_average_word_length(const char* sentence);
int read_line(char* str, int n);

int main(void)
{
    char sentence[SENTENCE_LEN + 1];
    double avg_word_length;

    printf("Enter a sentence: ");
    read_line(sentence, SENTENCE_LEN);

    avg_word_length = compute_average_word_length(sentence);

    printf("Average word length: %.1lf\n", avg_word_length);

    return 0;
}

double compute_average_word_length(const char* sentence)
{
    double length_sum = 0, word_count = 0;
    char prev = ' ';
    int i;

    for (i = 0; sentence[i] != '\0'; i++) {
        if (!isspace(prev) && (isspace(sentence[i]) || sentence[i + 1] == '\0'))
            word_count++;

        if (!isspace(sentence[i]))
            length_sum++;

        prev = sentence[i];
    }

    return (length_sum / word_count);
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