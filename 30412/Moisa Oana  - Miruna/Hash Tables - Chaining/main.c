#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _500;
    char ** content = readFromFile(N);
   //printContentToConsole(content,N);
    initHashTable(N);
    for(int i=0;i<N;i++)
    {

        insertElement(content[i]);
    }

     computeDistributionsPerBucket(N);
     standardDeviation();


    return 0;
}
