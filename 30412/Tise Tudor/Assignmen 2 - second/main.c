#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include "lists.h"
#define INSTRUCTION_LENGHT 255

int main() {

    FILE *f = fopen("../input.dat", "r+");

    char line[INSTRUCTION_LENGHT];
    char name[NAME_SIZE];
    char *token;
    int rubles, seconds;

    initializeList();
    setUpFile();

    if (f != NULL) {
            //reading the time segments
            fgets(line, INSTRUCTION_LENGHT, f);
            token = strtok(line, " ");
            while( token != NULL ) {
                appendToListSeconds(atoi(token));
                token = strtok(NULL, " ");
            }

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

        //computing the rubles for each time segment
        NodeCustomer *currentCustomer = firstC;
        NodeTime * currentTime = firstT;
        int s = 0;
        int sum = 0;

        while(currentTime != NULL)
        {
            while ((currentCustomer!= NULL) && (s + currentCustomer->seconds <= currentTime->data)){
                s = s + currentCustomer->seconds;
                sum = sum + currentCustomer->rubles;
                currentCustomer = currentCustomer->next;
            }
            printf("After %d seconds there are %d rubles\n",currentTime->data,sum);

            currentTime = currentTime->next;
        }


    } else {
        printf("Cannot open the file");
        exit(1);
    }


    fclose(f);
    fclose(g);

    return 0;
}