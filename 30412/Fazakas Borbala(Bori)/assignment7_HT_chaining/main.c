#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;

    char ** content = readFromFile(N);
    //printContentToConsole(content,N);

    initHashTable(N);
    for(int i=0; i<N; i++){
        printf("%s\n", content[i]);
        insertElement(content[i]);
    }

    return 0;
}