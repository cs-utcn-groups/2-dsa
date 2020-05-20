#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100,i;

    char ** content = readFromFile(N);
    initHashTable(100);

    for(i = 0 ; i< size ;i++)
    {
        insertElement(content[i]);
    }

    for(i = 0 ; i< size ;i++)
    {
        printf("\n%c%s",i,content[i]);
    }

    //printContentToConsole(content,N);

    return 0;
}
