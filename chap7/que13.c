#include <stdio.h>

int main(void)
{
    int word_count = 0, length_sum = 0;
    char curr_ch, prev_ch = ' ';

    printf("Enter a sentence: ");

    while((curr_ch = getchar()) != '\n') {
        if (curr_ch != ' ') {
            length_sum++;
        }

        if (prev_ch != ' ' && curr_ch == ' ') {
            word_count++;
        }

        prev_ch = curr_ch;
    }

    if (prev_ch != ' ') {
        word_count++;
    }

    printf("Average word length: %.1f\n",
            length_sum/(float)word_count);

    return 0;
}
