#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;

    char ** content = readFromFile(N);
    printContentToConsole(content,N);

    initHashTable(N);
    for (int i = 0; i < N; i++) {
        insertElement(*(content + i));
    }
    computeDistributionsPerBucket(N);
    printf("%.2f\n", calculateSD(N));

    return 0;
}
