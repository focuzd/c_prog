#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

bool is_bracket(char ch);

int main(void)
{
    Stack s = create();
    char ch;

    printf("Enter parentheses and/or braces: ");

    while ((ch = getchar()) != '\n') {
        if (!is_bracket(ch))
            continue;

        if (ch == '(' || ch == '{' || ch == '[')
            push(s, ch);

        else if (ch == ')' && peek(s) == '(')
            pop(s);

        else if (ch == ']' && peek(s) == '[')
            pop(s);

        else if (ch == '}' && peek(s) == '{')
            pop(s);
    }

    if (is_empty(s))
        printf("Parentheses/braces are nested properly.\n");
    else
        printf("Parentheses/braces are not nested properly.\n");

    destroy(s);

    return 0;
}

bool is_bracket(char ch)
{
    return (ch == '(' || ch == '[' || ch == '{' || ch == '}' || ch == ']' || ch == ')');
}