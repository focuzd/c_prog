#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_SIZE 30
#define EXPR_LEN 50

double data[STACK_SIZE];
double* top;

double evaluate_RPN_expression(const char* expression);
int read_line(char* str, int n);
bool is_empty(void);
bool is_full(void);
void empty_stack(void);
void push(double x);
double pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    double value;
    char expr[EXPR_LEN + 1];
    empty_stack();

    for (;;) {
        printf("Enter an RPN expression: ");
        read_line(expr, EXPR_LEN);

        if (expr[0] == 'q')
            break;

        value = evaluate_RPN_expression(expr);
        printf("Value of expression: %g\n", value);
    }

    return 0;
}

double evaluate_RPN_expression(const char* expression)
{
    const char* p = expression;
    double op1, op2, res;

    while (*p) {
        if (isdigit(*p))
            push(*p - '0');

        else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            op2 = pop();
            op1 = pop();

            switch (*p) {
            case '+': res = op1 + op2; break;
            case '-': res = op1 - op2; break;
            case '*': res = op1 * op2; break;
            case '/':
                if (op2 == 0) {
                    printf("Error: Division by 0.\n");
                    exit(1);
                }
                res = op1 / op2; break;
            }

            push(res);
        }

        else if (*p == '=')
            return pop();

        p++;
    }

    printf("Error: Incomplete expression.\n");
    exit(1);
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


bool is_empty(void)
{
    return (top == data);
}

bool is_full(void)
{
    return (top == &data[STACK_SIZE]);
}

void empty_stack(void)
{
    top = data;
}

void push(double x)
{
    if (is_full())
        stack_overflow();

    *top = x;
    top++;
}

double pop(void)
{
    if (is_empty())
        stack_underflow();

    return *--top;
}

void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(1);
}

void stack_underflow(void)
{
    printf("Not enough operands in the expression.\n");
    exit(1);
}