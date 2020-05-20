#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N;
    int fileArray[8] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000};
    for(int j = 0; j < 8; j++)
    {
        N = fileArray[j];
        char **content = readFromFile(N);
        initHashTable(N);
        for (int i = 0; i < N; i++)
        {
            insertElement(content[i]);
        }
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            count += hashTable[i]->size;
        }
        //printContentToConsole(content,N);
        double deviation = computeDistributionsPerBucket();
    }

    return 0;
}
