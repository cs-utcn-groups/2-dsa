#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;

    writeToFile(N);
    char ** content = readFromFile(N);
    //printContentToConsole(content,N);
    initHashTable(N);
    for(int i = 0 ; i < N ; i++){
        insertElement(content[i]);
    }


    printTable();
    return 0;
}
