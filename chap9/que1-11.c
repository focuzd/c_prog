#include <stdio.h>
#include <ctype.h>

float compute_GPA(char grades[], int n);

int main()
{
    char grades[] = {'A', 'B', 'A', 'D', 'F', 'C', 'C', 'A', 'B', 'B', 'C', 'D'};
    int n = sizeof(grades) / sizeof(grades[0]);
    
    double avg_gpa = compute_GPA(grades, n);
    printf("%g\n", avg_gpa);
    return 0;
}

float compute_GPA(char grades[], int n) {
    int i, sum = 0;
    char ch;
    int int_grades[] = {4, 3, 2, 1};

    for (i = 0; i < n; i++) {
        if (grades[i] == 'F') continue;
        sum += int_grades[toupper(grades[i]) - 'A'];
    }

    return ((double) sum) / n;
}
