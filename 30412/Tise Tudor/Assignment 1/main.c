#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listManagement.h"

#define INSTRUCTION_LENGHT 50
#define ADD_FIRST "AF"
#define ADD_LAST "AL"
#define DELETE_FIRST "DF"
#define DELETE_LAST "DL"
#define REMOVE_ELEMENTS "DOOM_THE_LIST"
#define DELETE_ELEMENT "DE"
#define PRINT_ALL "PRINT_ALL"
#define PRINT_FIRST "PRINT_F"
#define PRINT_LAST "PRINT_L"

int main() {

    FILE *f = fopen("../input.dat", "r+");

    char line[INSTRUCTION_LENGHT];
    char command[INSTRUCTION_LENGHT];
    char *token;
    int number;

    initializeList();
    setUpFile();

    if (f != NULL) {
        while (!feof(f)) {
            fgets(line, INSTRUCTION_LENGHT, f);
            printf("%s", line);

            token = strtok(line, " ");
            strcpy(command,token);
            token = strtok(NULL, " ");

            if (token != NULL) {
                number = atoi(token);
            } else {
                command[strlen(command)-1] = '\0';
            }

            if (strcmp(command,ADD_FIRST)== 0){
                addFirst(number);
            }
            if (strcmp(command,ADD_LAST)== 0){
                addLast(number);
            }
            if (strcmp(command,DELETE_FIRST)== 0){
                removeFirst();
            }
            if (strcmp(command,DELETE_LAST)== 0){
                removeLast();
            }
            if (strcmp(command,PRINT_ALL)== 0){
                printAll();
            }
            if (strcmp(command,PRINT_FIRST)== 0){
                printFirst(number);
            }
            if (strcmp(command,PRINT_LAST)== 0){
                printLast(number);
            }
            if (strcmp(command,REMOVE_ELEMENTS)== 0){
                removeAll();
            }
            if (strcmp(command,DELETE_ELEMENT)== 0){
                removeElement(number);
            }

        }
    } else {
        printf("Cannot open the file");
        exit(1);
    }

    fclose(f);

    return 0;
}

