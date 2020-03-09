#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "head.h"

int main() {
    allocMemory();
    initializeQueue();
    fgets(stringForTime,MAX_STRING_SIZE,in);
    stringForTime[strlen(stringForTime)-1] = '\0';
    while(fscanf(in,"%s",personName) != EOF) {
        readCustomerData();
        addCustomer();
    }
    ptr = stringForTime;
    char *pt;
    pt = strtok(stringForTime," ");
    while(pt != NULL) {
        afterXSeconds = strtol(pt,&ptr,10);
        printValue();
        pt = strtok(NULL," ");
    }
    return 0;
}
