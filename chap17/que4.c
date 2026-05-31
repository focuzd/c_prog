#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD_LEN 20
#define MAX_LINE_LEN 60

struct node {
    char word[WORD_LEN + 2];
    struct node* next;
};

struct node* first = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    struct node* p, * q;
    for (p = first; p != NULL; p = q) {
        q = p->next;
        free(p);
    }
    first = NULL;
}

void add_word(const char* word) {
    struct node* new_node, *p;
    new_node = malloc(sizeof(*new_node));

    if (new_node == NULL) {
        printf("Error: malloc failed in add_word.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_node->word, word);
    new_node->next = NULL;
    line_len += strlen(word);
    num_words++;

    if (first == NULL) {
        first = new_node;
        return;
    }

    p = first;
    while (p->next != NULL)
        p = p->next;
    p->next = new_node;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len - (num_words - 1);
    // here we dont store spaces in the buffer so to account for the a single space between to consequtive word
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert, j;
    struct node* p;

    extra_spaces = MAX_LINE_LEN - line_len - (num_words - 1);
    for (p = first; p != NULL; p = p->next) {
        printf("%s", p->word);
        spaces_to_insert = extra_spaces / (num_words - 1);
        for (j = 0; j < spaces_to_insert + 1; j++)
            putchar(' ');
        extra_spaces -= spaces_to_insert;
        num_words--;
    }
    putchar('\n');
}

void flush_line(void) {
    struct node* p;
    for (p = first; p != NULL; p = p->next) {
        if (p->next == NULL)
            printf("%s", p->word);
        else
            printf("%s ", p->word);
    }
    printf('\n');
}