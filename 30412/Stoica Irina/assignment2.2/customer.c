//
// Created by Irina on 10/03/2020.
//
#include "customer.h"
#include "node.h"
void readTime(int * time, int *count, FILE * input){
    char * timeLine = (char*)malloc(MAX_LENGTH * sizeof(char));
    char * auxTimeLine = (char*)malloc(MAX_LENGTH * sizeof(char));
    fgets(timeLine, MAX_LENGTH, input);
    //printf("%s", timeLine);
    strcpy(auxTimeLine, timeLine);
    //printf("%s", timeLine);
    *count = 0;
    char * token = strtok(timeLine, " ");
    while(token != NULL){
        token = strtok(NULL, " ");
        (*count)++;
    }
    //printf("\n%d", *count);
    token = strtok(auxTimeLine, " ");
    time[0] = atoi(token);
    int k=0;
    while(k<(*count)-1){
        k++;
        token = strtok(NULL, " ");
        time[k] = atoi(token);
    }
}
void addCustomer(int rubles, int seconds) {
    if(first == NULL){
        first = (node*)malloc(sizeof(node));
        first->next = last;
        first->rubles = rubles;
        first->seconds = seconds;
        last = first;
    } else {
        node * newNode = (node*)malloc(sizeof(node));
        last->next = newNode;
        newNode->next = NULL;
        newNode->rubles = rubles;
        newNode->seconds = seconds;
        last = newNode;
    }

}
void printCustomer(FILE * output, int * time, int count){
    node * currentNode = first;
    node * previous = first;
    int k=0;
    while(k<count) {
        if(currentNode == first){
            fprintf(output, "After %d seconds: %d\n", time[0], currentNode->rubles);
            currentNode = currentNode->next;
            k++;
        } else {
            if(currentNode->seconds + previous->seconds <= time[k]){
                fprintf(output, "After %d seconds: %d\n", time[k], currentNode->rubles + previous->rubles);
                currentNode->rubles = currentNode->rubles + previous->rubles;
                k++;
            } else {
                fprintf(output, "After %d seconds: %d\n", time[k], previous->rubles);
                currentNode->rubles = previous->rubles;
                k++;
            }
            currentNode->seconds = currentNode->seconds + previous->seconds;
            previous = currentNode;
            currentNode = currentNode->next;
        }
    }
}
void readCustomers(FILE * input){
    int rubles, seconds;
    char * name = (char*)malloc(MAX_NAME* sizeof(char));
    initializeList();
    while(!feof(input)){
        fscanf(input, "%s ", name);
        //printf("\n%s\n", name);
        fscanf(input, "%d %d", &rubles, &seconds);
        //printf("%d %d  ", rubles, seconds);
        addCustomer(rubles, seconds);
    }
}