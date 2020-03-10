#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include "lists.h"
#define INSTRUCTION_LENGHT 255

int main() {

    FILE *f = fopen("../input.dat", "r+");

    char line[INSTRUCTION_LENGHT];
    char name[INSTRUCTION_LENGHT];
    char *token;
    int rubles, seconds;

    initializeList();
    setUpFile();

    if (f != NULL) {
            //reading the seconds
            fgets(line, INSTRUCTION_LENGHT, f);
            token = strtok(line, " ");
            while( token != NULL ) {
                appendToListSeconds(atoi(token));
                token = strtok(NULL, " ");
            }
            printAllSeconds();

            //getting the customer data
        while (!feof(f)) {
            fgets(line, INSTRUCTION_LENGHT, f);

            token = strtok(line, " ");
            strcpy(name, token);

            token = strtok(NULL, " ");
            rubles = atoi(token);
            token = strtok(NULL, " ");
            seconds = atoi(token);

           appendToListCustomer(name,rubles,seconds);
        }

        printAllCustomers();

    } else {
        printf("Cannot open the file");
        exit(1);
    }


    fclose(f);
    fclose(g);

    return 0;
}