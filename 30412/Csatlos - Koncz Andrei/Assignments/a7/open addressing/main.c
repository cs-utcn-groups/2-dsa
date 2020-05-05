#include <windef.h>
#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100000;
    numberOfResizes = 0;
    char ** content = readFromFile(N);
    //printContentToConsole(content,N);


    int maxCollisions = 0;
    initHashTable(N);
    for(int i=0;i<N;i++)
    {
        maxCollisions = max(maxCollisions,insertElement(content[i]));
    }
    printf("Max Collisions = %d\n",maxCollisions);
    printf("Number of Resizes = %d\n",numberOfResizes);
    return 0;
}