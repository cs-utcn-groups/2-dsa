#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    int N = _100;
    n = m = 0;

    char ** content = readFromFile(N);
    initHashTable(N);
    for(int i = 0; i < N; i++)
    {
        printf("%d -> %d (%d)\n ", i, insertElement(content[i], N), hashFunction3(content[i], 0));
        if(getFillFactor(N) > MAX_FILL_FACTOR)
        {
            resizeHashTable(N, i, content);
        }
    }
    printf("%d - %d", m , n);
    return 0;
}
