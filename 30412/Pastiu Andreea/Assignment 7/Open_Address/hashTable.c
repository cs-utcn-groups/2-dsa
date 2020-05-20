#include "hashTable.h"
#include "io.h"
#include <math.h>


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = N * INITIAL_HT_SIZE_FACTOR;
    hashTable = (char**) malloc(size * sizeof(char*));
    for(int i = 0; i < size; i++)
    {
        hashTable[i] = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
        strcpy(hashTable[i], "nu e nimic");
    }

    maxCollisions = 0;
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = (float)existingElementsNo /size;

    return fillFactor;
}

void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
    /*for(int i = 0; i < size; i++)
    {
        free(hashTable[i]);
    }*/
    //free(hashTable);
    size *= 2;
    hashTable = (char**) malloc(size * sizeof(char*));
    for(int i = 0; i < size; i++)
    {
        hashTable[i] = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
        strcpy (hashTable[i], "nu e nimic");
    }
    for(int i = 0; i < existingElementsNo; i++)
    {
        int collisions = insertElement(content[i]);
        if(collisions > maxCollisions)
        {
            maxCollisions = collisions;
        }
    }
}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int ok = 0, i = 0;
    while(ok == 0)
    {
        int position = hashFunction(element, i);
        if(strcmp(hashTable[position], "nu e nimic") != 0)
        {
            i++;
        }
        else
        {
            strcpy(hashTable[position], element);
            ok = 1;
        }
    }

    return i;
}


int hashFunction(char * content, int i)
{
    /*long sum = 0, mul = 1;
    for (int j = 0; j < strlen(content); j++) {
        mul = (j % 4 == 0) ? 1 : mul * 256;
        sum += (content[j] + i) * mul;
    }
    return (int)(abs(sum) % size);*/
    long sum = 0;
    for (int j = 0; j < strlen(content); j++)
    {
        sum += content[j];
        sum += (sum << 5);
        sum ^= (sum >> 3);
        sum += i;
    }
    sum += (sum << 3);
    sum ^= (sum >> 6);
    sum += (sum << 4);
    return (int)(abs(sum) % size);
}
