#include <stdlib.h>
#include "hashTable.h"
#include "io.h"


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    sizeTable = N * INITIAL_HT_SIZE_FACTOR;
    hashTable = (char**)malloc(sizeTable * sizeof(char*));
    for(int i=0; i<sizeTable; i++){
        hashTable[i] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
        hashTable[i] = NULL;
    }
    nrOfCollisions = nrOfResizes = 0;
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int nrOfBucketsFilled = 0;
    for(int i=0; i<sizeTable; i++){
        if(hashTable[i] != NULL){
            nrOfBucketsFilled++;
        }
    }
    fillFactor = (float)nrOfBucketsFilled/(float)sizeTable;
    return fillFactor;
}

void resizeHashTable(int index, char * element)
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
    nrOfResizes++;
    sizeTable = sizeTable * 2;
    hashTable = (char**)realloc(hashTable, sizeTable * sizeof(char*));
    for(int i=0; i<sizeTable; i++){
        hashTable[i] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
        hashTable[i] = NULL;
    }
    for(int i=0; i<index; i++){
        int nrOfCol = insertElement(index, element);
        if(nrOfCol > nrOfCollisions){
            nrOfCollisions = nrOfCol;
        }
    }
}

int insertElement(int index, char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    if(getFillFactor() > MAX_FILL_FACTOR){
        resizeHashTable(index, element);
    }
    int i = 0;
    int position = H3(i, element);
    if(hashTable[position] == NULL){
        hashTable[position] = element;
    }
    else {
        while (hashTable[position] != NULL) {
            nrOfCollisions++;
            i++;
            position = H3(i, element);
        }
        hashTable[position] = element;
    }
    return nrOfCollisions;
}

int hashFunction(int i)
{
    return i % sizeTable;
}

int H2(int i, char * content){
    int k, sum;
    for (sum=0, k=0; k < MAX_STRING_LENGTH; k++){
        sum += content[k];
    }
    return (sum+i) % sizeTable;
}

int H3(int i, char * content){
    int result = content[0];
    for(int j=1; j<MAX_STRING_LENGTH; j++) {
        result = abs(result * 31 + content[j]);
    }
    return (result*i + i) % sizeTable;
}

int computeMaximumCollisionNumber(int collision){
    static int maxNrOfCollisions = 0;
    if(collision > maxNrOfCollisions){
        maxNrOfCollisions = collision;
    }
    return maxNrOfCollisions;
}