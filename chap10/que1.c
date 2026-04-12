#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

int top = 0;
char data[STACK_SIZE];

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    char ch, tos;
    make_empty();

    printf("Enter parentheses and or braces: ");
    while((ch = getchar()) != '\n') {
        if (ch == '(' || ch == '{') {
            push(ch);
        }
        else if (ch == ')' || ch == '}') {
            tos = pop();
            if ((ch == ')' && tos == '(') || (ch == '}' && tos == '{')) {
                continue;
            } else {
                break;
            }
        }
    }

    if (is_empty() && ch == '\n') {
        printf("Parentheses/braces are nested properly\n");
    } else {
        printf("Parentheses/braces aren't nested properly\n");
    }

    return 0;
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

void push(char ch)
{
    if (is_full()) {
        stack_overflow();
    }

    data[top] = ch;
    top++;
}

char pop(void)
{
    if (is_empty()) {
        stack_underflow();
        return '\0';
    }
    
    --top;
    return data[top];
}

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{}
