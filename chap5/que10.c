#include <stdio.h>

int main(void) 
{
    int grade, tens_digit;
    char letter_grade;

    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    tens_digit = grade / 10;
    
    switch (tens_digit) {
        case 10: case 9:
            letter_grade = 'A';
            break;
        case 8:
            letter_grade = 'B';
            break;
        case 7:
            letter_grade = 'C';
            break;
        case 6:
            letter_grade = 'D';
            break;
        case 5: case 4: case 3: case 2: case 1:
            letter_grade = 'F';
            break;
        case 0:
            if (grade < 0) {
                printf("Error: Invalid grade\n");
                return 1;
            }
            letter_grade = 'F';
            break;
        default:
            printf("Error: Invalid grade\n");
            return 1;
    }

    printf("Letter grade: %c\n", letter_grade);

    return 0;
}
