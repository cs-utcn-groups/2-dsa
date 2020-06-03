#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;

    char ** content = readFromFile(N);
    //printContentToConsole(content,N);

    initHashTable(N);
    for(int i= 0; i<sizeTable; i++){
            int nrOfCol = insertElement(i, content[i]);
            if(nrOfCol > nrOfCollisions){
                nrOfCollisions = nrOfCol;
            }
    }
    printf("\n");
    for(int i=0; i<sizeTable; i++){
        printf("%s", hashTable[i]);
    }
    printf("Number of resizes is: %d\nNumber of Collisions is: %d\n", nrOfResizes, nrOfCollisions);
    return 0;
}
