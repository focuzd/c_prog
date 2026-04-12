#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

int top = 0;
double data[STACK_SIZE];

double evaluate_exp(void);
bool is_operation(char ch);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(double value);
double pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    double value;
    for(;;) {
        printf("Enter an RPN expression: ");
        make_empty();
        value = evaluate_exp();
        printf("Value of expression: %g\n", value);
    }

    return 0;
}

double evaluate_exp(void)
{
    char ch; 
    double op1, op2;
    while ((ch = getchar()) != '=') {
        if (ch == 'q') exit(EXIT_SUCCESS);
        else if (ch >= '0' && ch <= '9') {
            push(ch-'0');
        } else if (is_operation(ch)) {
            op2 = pop();
            op1 = pop();

            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': if (op2 != 0) push(op1/op2);
                          else {
                              printf("Divison by 0.\n");
                              exit(EXIT_FAILURE);
                          }
                          break;
            }
        }
    }

    return pop();
}

bool is_operation(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void make_empty(void) 
{
    top = 0;
}

bool is_empty(void)
{
    return (top == 0);
} 

bool is_full(void)
{
    return (top == STACK_SIZE);
}

void push(double value)
{
    if (is_full()) stack_overflow();

    data[top++] = value;
}

double pop(void)
{
    if (is_empty()) stack_underflow();

    return data[--top];
}

void stack_overflow(void)
{
    printf("Expression is too complex.\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Not enough operands in expression.\n");
    exit(EXIT_FAILURE);
}
