#include <stdio.h>
#include <ctype.h>

#define WORD_LEN 20

int compute_scrabble_value(const char* word);

int main(void)
{
    char word[WORD_LEN + 1];
    int scrabble_value;

    printf("Enter a word: ");
    scanf("%s", word);

    scrabble_value = compute_scrabble_value(word);
    printf("Scrabble value: %d\n", scrabble_value);

    return 0;
}

int compute_scrabble_value(const char* word) {
    int val = 0;

    int letter_to_val[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

    while (*word) {
        val += letter_to_val[*word-'a'];
        word++;
    }

    return val;
}