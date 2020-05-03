#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _1000;
    char ** content = readFromFile(N);
    initHashTable(N);
    int r=0;
    for(int i=0;i<N;i++)
    {
        int c=insertElement(*(content+i));
        if(c>maxcol)
            maxcol=c;
        if(getFillFactor(size)>=MAX_FILL_FACTOR)
        {
            r++;
            resizeHashTable();
        }
    }
    printf("H1: %d %d\n",maxcol,r);
    //printContentToConsole(content,N);
    for(int i=0;i<N;i++)
        free(content[i]);
    free(content);
    free(hashTable);
    return 0;
}
