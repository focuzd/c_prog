#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define WORD_LEN 20

bool are_anagrams(const char* word1, const char* word2);
int read_line(char* str, int n);

int main(void)
{
    char word1[WORD_LEN + 1], word2[WORD_LEN + 1];

    printf("Enter first word: ");
    read_line(word1, WORD_LEN);
    printf("Enter second word: ");
    read_line(word2, WORD_LEN);

    if (are_anagrams(word1, word2))
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}

bool are_anagrams(const char* word1, const char* word2)
{
    int is_present[26] = { 0 };
    int i;

    for (i = 0; word1[i] != '\0'; i++)
        if (isalpha(word1[i]))
            is_present[tolower(word1[i]) - 'a']++;

    for (i = 0; word2[i] != '\0'; i++)
        if (isalpha(word2[i]))
            is_present[tolower(word2[i]) - 'a']--;

    for (i = 0; i < 26; i++)
        if (is_present[i] != 0)
            return false;

    return true;
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