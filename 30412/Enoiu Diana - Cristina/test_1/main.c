#include <stdio.h>
#include "head.h"
#include "stdlib.h"
#define ELEM_SIZE 100
int main() {
    FILE * in, *out;
    in = fopen("../input.dat","r");
    out = fopen("../output.dat","a");
    char * element;
    element = (char *)malloc(ELEM_SIZE * sizeof(char));
    int data;
    char *ptr;
    initializeOrgList();
    initializeSublist1();
    initializeSublist2();
    while(fscanf(in,"%s",element) != EOF) {
        data = strtol(element,&ptr,10);
        addFirst(data);
    }
    printAllOrgList(out);
    originalList * source = first;
    AlternatingSplit(source);
    printAllSublist1(out);
    printAllSublist2(out);
    return 0;
}
