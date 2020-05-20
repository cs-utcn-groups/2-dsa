#include "hashTable.h"


void initHashTable(int N)
{
    size = INITIAL_HT_SIZE_FACTOR * N;
    hashTable = (char**)malloc(sizeof(char*)*size);
    for (int i = 0; i < size; i++){
        hashTable[i] = NULL;
    }

    collisions = 0;
    resizes = 0;
}

float getFillFactor()
{
    float fillFactor = -1;
    int noOccupiedPositions =0;

    for (int i = 0; i < size; i++){
         if (hashTable[i] != NULL)
            noOccupiedPositions++;
    }

    fillFactor = (float)noOccupiedPositions/size;
    return fillFactor;
}

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    resizes++;
    char **lastHashTable = hashTable;

    int lastSize = size;
    size = size*2;
    hashTable = (char **) malloc(size * sizeof(char*));

    for (int i = 0; i < size; i++) {
        hashTable[i] = NULL;
    }

    for (int j = 0; j < lastSize; j++) {
        if (lastHashTable[j] != NULL) {
            insertElement(lastHashTable[j]);
        }
    }

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted

    int length = strlen(element);

    int index, noOfCollisions = 0;
    int i = 0;
    float fillFactor = 0;
    while (1) {
        index = hash3(element, i++);
        if (hashTable[index] == NULL) {
            hashTable[index] = (char *) malloc(sizeof(char)*length);
            strcpy(hashTable[index], element);

            fillFactor = getFillFactor();
            if (fillFactor > MAX_FILL_FACTOR) {
                resizeHashTable();
            }
            
            return noOfCollisions;
        }
        noOfCollisions++;
    }
    return noOfCollisions;
}


int hash1(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i) % size;
}

int hash2(char * content, int i)
{
    int length = strlen(content);
    long sum = 0, mul = 1;
    for (int i = 0; i < length; i++) {
        mul = (i % 4 == 0) ? 1 : mul * 256;
        sum += content[i] * mul;
    }
    return labs(sum + i) % size;
}

int hash3(char * content, int i)
{
    int hash = 5381;

    for (int i = 0; i < strlen(content);i++)
        hash = ((hash << 5) + hash) + content[i];

    return abs(hash + i) % size;
}

