#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

struct Password {
    char service[64];
    char password[128];
};

const char *format = "%s : %s\n";
const char *fname = "./passvoid.txt";

int load_from_file(struct Password passwords[]) {
    int i = 0;
    FILE *fp = fopen(fname, "r");
    
    if (!fp) {
        return -1;
    }

    while (fscanf(fp, format, passwords[i].service, passwords[i].password) == 2){
        i++;
    };

    fclose(fp);
    return i;
}

int save_to_file(struct Password passwords[], int count) {
    int i;
    FILE *fp = fopen(fname, "w");
    for (i = 0; i < count; i++) {
        fprintf(fp, format, passwords[i].service, passwords[i].password);
    }
    fclose(fp);
    return 0;
}
    
bool add(char *service_name, struct Password passwords[], int count) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(passwords[i].service, service_name) == 0) {
            printf("Password for this service already exists.\n");
            return false;
        }
    }

    char pass[128]; 
    // you cannot use char *pass, do not know but we need a fixed length for the string to be read by scanf
    printf("Enter password: ");
    scanf(" %s", pass); 

    strcpy(passwords[count].service, service_name);
    strcpy(passwords[count].password, pass);
    
    return true;
}

void list(struct Password passwords[], int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%d. %s\n", i+1, passwords[i].service);
    }
}

void get(char *service_name, struct Password passwords[], int count) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(passwords[i].service, service_name) == 0) {
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Error: Service not found.\n");
}

int main(int argc, char *argv[])
{
    struct Password passwords[MAX];
    int count;

    if (argc < 2) {
        printf("Usage: ./passman [add|list|get]\n");
        return 1;
    }

    count = load_from_file(passwords);
    
    // compare the third argument with the strings "add", "list", "get"
    if (strcmp(argv[1], "add") == 0) {
        if (count >= 10) {
            printf("Maximum capacity of passman reached.\n");
            return 1;
        }
        
        if (argc != 3) {
            printf("Usage: ./passman add service_name\n");
            return 1;
        }
        
        if (add(argv[2], passwords, count)) {
            printf("Saved password for '%s'.\n", argv[2]);
            count++;
        } else {
            printf("Error: Failed to save password.\n");
            return 1;
        }

    } else if (strcmp(argv[1], "list") == 0) {
        list(passwords, count);
    } else if (strcmp(argv[1], "get") == 0) {
        if (argc != 3) {
            printf("Usage: ./passman get service_name\n");
            return 1;
        }
        get(argv[2], passwords, count);
    } else {
        printf("Usage: ./passman [add|list|get]\n");
        return 1;
    }

    save_to_file(passwords, count);

    return 0;
}
