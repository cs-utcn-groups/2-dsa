#include <stdio.h>
#include "head.h"

int main() {
    inp = fopen("../input.txt","r");
    readGraph();
    transformGraphToList();
    printLists();
    bfsList(2);
    dfsRecursList(2);
    return 0;
}