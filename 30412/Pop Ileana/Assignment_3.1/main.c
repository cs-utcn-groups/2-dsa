#include "conversions.h"

#define DATA_PATH "../input1.dat"


int main() {

    fin=fopen(DATA_PATH,"r");
    if(fin==NULL)
    {
        perror("Could not open the file");
        exit(EXIT_FAILURE);
    }
    NodeT * root = createBinTree();
    prettyPrint(root,0);
    NodeL * firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    root=getTreeFromList(firstFromList);
    prettyPrint(root,0);
    return 0;
}

