#include <stdio.h>

int main(void) 
{
    float result, op1;
    char operation;
    
    printf("Enter an expression: ");
    scanf(" %f", &result);

    while ((operation = getchar()) != '\n') {
        scanf(" %f", &op1);

        switch (operation) {
            case '+':
                result += op1; break;
            case '-':
                result -= op1; break;
            case '*':
                result *= op1; break;
            case '/':
                if (op1 == 0) {
                    fprintf(stderr, "Error: Divison by zero.\n");
                    return 1;
                } 

                result /= op1; break;
            default:
                fprintf(stderr, "Invalid operation\n");
                return 1;
        }
    }

    printf("The value of expression: %f\n", result); 
    
    return 0;
}
