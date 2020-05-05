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
        existingElementsNo = 0;
        content = readFromFile(N);
        int resizesNo = 0;
        initHashTable(N);
        for (int i = 0; i < N; i++)
        {
            if (getFillFactor() > MAX_FILL_FACTOR)
            {
                resizesNo++;
                resizeHashTable();
            }
            int collisions = insertElement(content[i]);
            if (collisions > maxCollisions)
                maxCollisions = collisions;
            existingElementsNo++;
        }
        //printContentToConsole(content, N);
        int a = 0;
        printf("%d\n", resizesNo);
        printf("%d\n", maxCollisions);
    }
    return 0;
}
