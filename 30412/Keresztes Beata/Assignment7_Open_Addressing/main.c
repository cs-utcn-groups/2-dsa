#include "io.h"
#include "files.h"
#include "hashTable.h"
int main()
{
    int N = _1000;

    char ** content = readFromFile(N);
   // printContentToConsole(content,N);
   hashT * hash = initHashTable(getInitialSize(N));
    maxCollisions = 0;
    nrResize = 0;

    for(int i=0; i<N; i++) {
        int collisions = insertElement(content[i],hash);
        printf("element: %d- collisions:%d\n",i,collisions);
        hash = resizeHashTable(hash);
    }
    printf("last size:%d\n",hash->size);
    printf("max collisions: %d\n nr of resizes:%d\n",maxCollisions,nrResize);

    return 0;
}
