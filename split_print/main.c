#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char *vorname, *nachname;
} person;

void split(char** namen, person** personen);
void print(person** personen);

int main(void) {
    char *namen[MAX] = {"Max Mueller", "Maria Meier", "Sven Kunze", NULL};
    person *personen[MAX];

    split(namen, personen);
    print(personen);
    return 0;
}

void split(char** namen, person** personen) {
    int i = 0;
    while (namen[i] != NULL) {
        personen[i] = (person*)malloc(sizeof(person));
        char* name_copy = strdup(namen[i]);
        personen[i]->vorname = strtok(name_copy, " ");
        personen[i]->nachname = strtok(NULL, " ");
        i++;
    }
    personen[i] = NULL;
}

void print(person **personen) {
    for (int i = 0; personen[i] != NULL; i++) {
        printf("Vorname: %-6s Nachname: %s\n", personen[i]->vorname, personen[i]->nachname);
    }
}