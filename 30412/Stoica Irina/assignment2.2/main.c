#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "node.h"

void openFile(FILE * file);

int main() {
    FILE * input = fopen("..//input.dat", "r");
    openFile(input);
    FILE * output = fopen("..//output.dat", "w");
    openFile(output);
    int count;
    int * time = (int*)malloc(MAX_LENGTH * sizeof(int));

    readTime( time, &count, input);

    node * sentinel = getSentinel();

    readCustomers(input);

    printCustomer(output, time, count);

    return 0;
}
void openFile(FILE * file){
    if (file == NULL){
        perror("File could not be opened");
        exit(-1);
    }
}