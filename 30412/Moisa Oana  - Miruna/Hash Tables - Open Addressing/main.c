#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _500;

    float fillFactor=0;
    char ** content = readFromFile(N);
    int *collisions=(int*)malloc(N*sizeof(int));
     int maxCollisions=0;
   // printContentToConsole(content,N);
    initHashTable(N);
    for(int i=0;i<size;i++)
        printf("%s \n",hashTable[i]);
    for(int k=0;k<N;k++)
    {

        collisions[k]=insertElement(content[k]);
        fillFactor=getFillFactor();
        if(fillFactor>=MAX_FILL_FACTOR)
        {
            resizeHashTable();
            nrOfResizes++;
        }
    }

    for(int k=0;k<N;k++)
    {

        if(strcmp(hashTable[k],"*")!=0)
        {
            printf("*  \n");
        }

        else
        {
            printf("No element\n");
        }
    }

    for(int i=0;i<N;i++)
    {
        if(collisions[i]>maxCollisions)
            maxCollisions=collisions[i];
    }
    printf("maximum number of collisions: %d\n",maxCollisions);
    printf("number of resizes: %d\n",nrOfResizes);



    return 0;
}

