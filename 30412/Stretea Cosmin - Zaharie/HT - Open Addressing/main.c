#include "io.h"
#include "files.h"
#include "hashTable.h"
int main()
{
    int N = _1000;

    char ** content = readFromFile(N);
    int maxCollisions = 0, resizes = 0;
    float fillFactor = getFillFactor();

    //printContentToConsole(content,N);
    initHashTable(N);
    for (int i = 0; i < N; ++i) {
        if(fillFactor > MAX_FILL_FACTOR){
            resizeHashTable();
            resizes++;
        }
        int currCollisions = insertElement(content[i]);
        if(currCollisions > maxCollisions)
            maxCollisions = currCollisions;
        fillFactor = getFillFactor();
    }

    printf("Max Collisions: %d\nResizes: %d\n", maxCollisions, resizes);

//    for (int i = 0; i < size; ++i) {
//        printf("%s \n", hashTable[i]);
//    }
    return 0;
}
