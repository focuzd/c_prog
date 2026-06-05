#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

bool is_operator(int ch);
bool is_digit(int ch);

int main(void)
{
    int ch, prev, num, op1, op2, res;
    Stack s = create();

    num = 0;
    for (;;) {
        printf("Enter an RPN expression: ");
        while ((ch = getchar()) != '\n') {
            if (ch == 'q')
                return 0;

            if (ch == ' ' && is_digit(prev)) {
                push(s, num);
                num = 0;
            }

            if (is_digit(ch)) {
                num *= 10;
                num += (ch - '0');
            }

            if (is_operator(ch)) {
                op2 = pop(s);
                op1 = pop(s);

                switch (ch) {
                    case '+':
                        res = op1 + op2;
                        break;

                    case '-':
                        res = op1 - op2;
                        break;

                    case '*':
                        res = op1 * op2;
                        break;

                    case '/':
                        if (op2 == 0) {
                            printf("Error: Division by zero.\n");
                            exit(EXIT_FAILURE);
                        }
                        res = op1 / op2;
                        break;

                    case '%':
                        if (op2 == 0) {
                            printf("Error: Division by zero.\n");
                            exit(EXIT_FAILURE);
                        }
                        res = op1 % op2;
                        break;
                }

                push(s, res);
            }
            prev = ch;
        }

        printf("Value of expression: %d\n", pop(s));
    }

    return 0;
}

bool is_operator(int ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

bool is_digit(int ch)
{
    return (ch >= '0' && ch <= '9');
}