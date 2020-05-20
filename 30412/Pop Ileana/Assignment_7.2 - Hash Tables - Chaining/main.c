#include "io.h"
#include "hashTable.h"
#include "files.h"

int main()
{
    int N = _100;
    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    initHashTable(N);

    for(int i=0;i<N;i++)
        insertElement(content[i],hashFunction3);

    printf("The Distribution per Bucket is: (Press ENTER to continue)");
    getchar();

    computeDistributionsPerBucket(N);
    computeStandardDeviation(N);
    return 0;
}
