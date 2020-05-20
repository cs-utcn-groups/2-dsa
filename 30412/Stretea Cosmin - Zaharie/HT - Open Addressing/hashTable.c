#include "hashTable.h"
#include "io.h"

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = INITIAL_HT_SIZE_FACTOR * N;
    hashTable = (char **)malloc(sizeof(char *) * size);
    for (int i = 0; i < size; ++i) {
        hashTable[i] = NULL;
    }
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int filledCount = 0;
    for (int i = 0; i < size; ++i) {
        if(hashTable[i] != NULL)
            filledCount++;
    }

    fillFactor = filledCount / (float) size;

    return fillFactor;
}

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    int newSize = size * 2;
    char ** newHT = (char **)malloc(sizeof(char *) * newSize);
    for (int i = 0; i < newSize; ++i) {
        newHT[i] = NULL;
    }
    char ** oldHT = hashTable;
    hashTable = newHT;

    for (int i = 0; i < size; ++i) {
        if(oldHT[i]) {
            insertElement(oldHT[i]);
        }
    }

    size = newSize;

}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted

    int collisionCount = 0;
    int i = 0;
    int pos = hashFunction(element, i);

    while(hashTable[pos] != NULL){
        collisionCount++;
        i++;
        pos = hashFunction(element, i);
    }

    hashTable[pos] = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(hashTable[pos], element);

    return collisionCount;
}


int hashFunction(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum + i*i) % size;
}
