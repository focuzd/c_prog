#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PERROR 10e-6 // precision error arbitrarily assumed

// altough did not wanted to include functions since did not cover them yet, but was feeling lazy repeating code

int is_int(double value) {
    // works only if 1.0 is never stored as 0.999998, should not be below the integer value
    int temp = value;

    if (fabs(value - temp) > PERROR) {
        return 0;
    } 

    return 1;
}


int main(void)
{
    double operand1, operand2, result; //double - floating point numbers with higher precision
    char operator;
    int items_assigned;

    printf("Enter an expression: ");
    items_assigned = scanf("%lf %c %lf", &operand1, &operator, &operand2);
    // scanf return the number of arguments to which the value is successfully assigned
    // l is a length modifier, %f: float , %lf: double
    // affects conversion accuracy and overflow rules, as scanf converts sequence of strings to the type specified by conversion specification

    if (items_assigned != 3) {
        fprintf(stderr, "Error: Invalid input format\n");
        return 1;
    }

    // fprintf is same as the printf function, but we can specify the stream to which the output is displayed
    // there are two standard streams, standard output(stdout) and standard error(stderr), printf writes onto stdout

    switch (operator) {
        case '+':
            result = operand1 + operand2;
            break;

        case '-':
            result = operand1 - operand2;
            break;

        case '*':
            result = operand1 * operand2;
            break;

        case '/':
            if (operand2 == 0) {
                fprintf(stderr, "Error: Division by zero\n");
                return 1; 
                // we can have different return values for different error types, which is the practice, but since this is a simple program
                // I am choosing a single integer value to represent error
            }
            
            result = operand1 / operand2;
            break;

        case '%':
            if (is_int(operand1) && is_int(operand2)) {
                int op1 = operand1, op2 = operand2;
                
                if (op2 == 0) {
                    fprintf(stderr, "Error: Division by zero\n");
                    return 1;
                }

                result = op1 % op2;
            } else {
                fprintf(stderr, "Error: Invalid operand type with modulus\n");
                return 1;
            }

            break;

        default: 
            fprintf(stderr, "Invalid operator\n");
            return 1;
    }

    if (is_int(operand1) && is_int(operand2) && operator != '/') {
        int res = result;
        printf("Value of expression: %d\n", res);
    } else {
        printf("Value of expression: %lf\n", result);
    }


    return 0;
}
