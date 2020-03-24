#include <stdio.h>
#include "AVLTree.h"

int main() {
    FILE* inFile = fopen("data.in", "r");
    AVLTree* myTree = createEmptyAVLTree();
    int newData;
    char opCode;
    char c;
    while(!feof(inFile))
    {
        fscanf(inFile, "%c %d", &opCode, &newData);
        while((c=fgetc(inFile))!='\n' && c!=EOF);
        switch (opCode)
        {
            case 'd': deleteNode(&myTree, newData);
                break;
            case 'i': insertNode(&myTree, newData);
                break;
        }
        printf("\nafter %c %d\n", opCode, newData);
        inOrder(myTree, stdout);
    }


    return 0;
}