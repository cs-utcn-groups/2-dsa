#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;

    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    initHashTable(N);
    int noCollisions = 0;

    for (int i = 0; i < N; i++) {
        noCollisions = insertElement(content[i]);
        if (collisions < noCollisions) {
            collisions = noCollisions;
        }
    }

    printf("there were %d resizes and the max number of collisions was %d\n",resizes,collisions);
    return 0;
}
