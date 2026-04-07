#include <stdio.h>

#define N 16

int main(void)
{
    char phone_no[N], ch;
    int i;

    i = 0;
    printf("Enter a phone number: ");
    while ((ch = getchar()) != '\n') {
        switch (ch) {
            case 'A': case 'B': case 'C':
                phone_no[i] = '2'; break;
            case 'D': case 'E': case 'F':
                phone_no[i] = '3'; break;
            case 'G': case 'H': case 'I':
                phone_no[i] = '4'; break;
            case 'J': case 'K': case 'L':
                phone_no[i] = '5'; break;
            case 'M': case 'N': case 'O':
                phone_no[i] = '6'; break;
            case 'P': case 'R': case 'S':
                phone_no[i] = '7'; break;
            case 'T': case 'U': case 'V':
                phone_no[i] = '8'; break;
            case 'W': case 'X': case 'Y':
                phone_no[i] = '9'; break;
            default:
                phone_no[i] = ch; break;    
        }

        i++;
    }
    phone_no[i] = '\n';
    
    printf("In numeric form: ");
    i = 0;
    while (phone_no[i] != '\n') {
        putchar(phone_no[i]);
        i++;
    }
    printf("\n");

    return 0;
}
