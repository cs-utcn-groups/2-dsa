#include "hashTable.h"
#include <stdlib.h>
#include <string.h>


void initHashTable(int N)
{
    size = 100;
    cnt = 0;
    hashTable = (char**)malloc(sizeof(char*) * size);
    for( int i = 0 ; i < size ; i++)
        hashTable[i] = (char*)malloc(sizeof(char));

}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;

    return fillFactor;
}

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
}

int insertElement(char * element)
{
    //! insert an element
    //    //! returns the number of collisions which occurred before the element was inserted
    if(cnt == size)
        exit(EXIT_FAILURE);
    int index = hashFunction(element);
    while(hashTable[index] != NULL && strcmp(hashTable[index],"stop")==0)
        index = (index+1) % size;
    hashTable[index] = element;
    cnt ++;

    return 0;
}


int hashFunction(char * content)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum) % size;
}

