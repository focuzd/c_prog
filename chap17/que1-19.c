#include <stdio.h>
#include <string.h>

struct {
    char *cmd_name;
    void (*cmd_pointer)(void);
} file_cmd[] = {
    {"new", new_cmd},
    {"open", open_cmd},
    {"close", close_cmd},
    {"close all", close_all_cmd},
    {"save", save_cmd},
    {"save as", save_as_cmd},
    {"save all", save_all_cmd},
    {"print", print_cmd},
    {"exit", exit_cmd}
};

void call(char* str, int n)
{
    for (int i = 0; i < n; i++)
        if (strcmp(str, file_cmd[i].cmd_name) == 0)
            (*(file_cmd[i].cmd_pointer))();
}