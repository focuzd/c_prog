#include <stdio.h>
#include <string.h>

int main(void)
{
    char* tens_to_word[] = { "", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety " };
    char* ones_to_word[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    char* outliers[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

    int tens_digit, ones_digit, num;
    char word[20];
    printf("Enter a two digit number: ");
    scanf("%2d", &num);

    tens_digit = num / 10;
    ones_digit = num % 10;

    if (tens_digit != 1) {
        strcpy(word, tens_to_word[tens_digit]);
        strcat(word, ones_to_word[ones_digit]);
    }
    else {
        strcpy(word, outliers[ones_digit]);
    }

    printf("You entered the number %s.\n", word);

    return 0;
}