#include "hashTable.h"
#include "io.h"

void initializeHT(int N) {
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = INITIAL_HT_SIZE_FACTOR * N;
    hT = (char **) malloc(sizeof(char *) * size);
    for (int i = 0; i < size; ++i) {
        hT[i] = NULL;
    }
}

float getFillFactor() {
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int fillCount = 0;
    for (int i = 0; i < size; ++i) {
        if (hT[i] != NULL)
            fillCount++;
    }
    fillFactor = fillCount / (float) size;
    return fillFactor;
}

void resizeHT() {
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR
    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
    int newSize = size * 2;
    char **newHT = (char **) malloc(sizeof(char *) * newSize);
    for (int i = 0; i < newSize; ++i) {
        newHT[i] = NULL;
    }
    char **oldHT = hT;
    hT = newHT;
    for (int i = 0; i < size; ++i) {
        if (oldHT[i]) {
            insert(oldHT[i]);
        }
    }
    size = newSize;
}

int insert(char *element) {
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int collisionCount = 0;
    int i = 0;
    int pos = hashFunction(element, i);
    while (hT[pos] != NULL) {
        collisionCount++;
        i++;
        pos = hashFunction(element, i);
    }
    hT[pos] = (char *) malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(hT[pos], element);
    return collisionCount;
}

int hashFunction(char *content, int i) {
    int length = strlen(content);
    int k, sum;
    for (sum = 0, k = 0; k < length; k++) {
        sum += content[k];
    }
    return (sum + i * i) % size;
}
