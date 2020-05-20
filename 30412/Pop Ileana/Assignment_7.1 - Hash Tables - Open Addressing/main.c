#include "files.h"
#include "hashTable.h"
int main()
{
    int N = _100;

    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    initHashTable(N);
    for(int i=0;i<N;i++)
    {
        int collisions = insertElement(content[i],hashFunction1);
        if(collisions>maxNumberOfCollisions)
            maxNumberOfCollisions = collisions;
    }
    printf("\nThe maximum number of collisions which occurred is: %d\n",maxNumberOfCollisions);
    printf("The table was resized %d times",resizes);

    return 0;
}
