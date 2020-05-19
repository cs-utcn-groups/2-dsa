#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _1000;

    char ** content = readFromFile(N);
    //printContentToConsole(content,N);


    initHashTable(N);
    for(int i=0;i<N;i++)
    {
        insertElement(content[i]);
    }
    computeDistributionsPerBucket(N);
    return 0;
}