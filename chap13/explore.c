#include <stdio.h>

int main(void)
{
    /*
    char s[] = "Compiler joins two string literals" 
        "separated only by whitespace"; 
    // but this example also has a newline character in between
    // this works and the compiler does not add any character between the two string literal

    printf("%s\n", s);
    */
    
    /*
    char s[4] = {'0', '1', '2', '3'};
    s[4] = 12;
    // we are not terminating the string with a null character
    printf("%s\n", s);
    printf("%d\n", s[4]);
    */
    // why accessing s[4] here does not lead to segmentation fault 
    // does creating a character array of length 4 update the character after after the last character as '\0'
    // if I change null character to some other character I get:
    /*  0123
        ���
            6P�כ�
        12
        *** stack smashing detected ***: terminated
        Aborted (core dumped)

    */

    // above case is accidental s[4] will create a character array of length 4 and does not update the succeeding character to
    // null character


    return 0;
}
