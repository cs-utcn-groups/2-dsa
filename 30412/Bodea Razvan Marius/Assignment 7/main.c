//This sounds like it should be illegal
/*
 Chaining
The Standard Deviation is a measure of how spread out numbers are.
Its symbol is σ (the greek letter sigma)
The formula is easy: it is the square root of the Variance.
The average of the squared differences from the Mean.==Variance

 Open Addressing
In Open Addressing, all elements are stored in the hash table itself. So at any point, size of the table must be greater than or equal to the total number of keys
Insert(k): Keep probing until an empty slot is found. Once an empty slot is found, insert k.
Search(k): Keep probing until slot’s key doesn’t become equal to k or an empty slot is reached.

 Obs: 1)Max fill factor should be ~75% for best result
      2)For bigger files H3 is much faster
 */

// The results are written in the documents
#include "io.h"
#include "files.h"
#include "hashTableChaining.h"
#include "hashTableOpenAddressing.h"

int main()
{
    int N = _5000;
    char ** content = readFromFile(N);
    /*
    initHashTable(N);
    for(int i=0;i<N;i++){
        insertElement(*(content+i));
    }
    printf("The distributions / bucket are: \n");
    computeDistributionsPerBucket(N);
    printf("The standard deviation is: %.4lf\n",calculateStandardDeviation(N));
    */
    int noOfCollisions=0;
    initHashTable(N);
    for(int i=0;i<N;i++){
        noOfCollisions = getMax(noOfCollisions,insertElement(content[i]));
    }
    printf("Max Collisions = %d\n",noOfCollisions);
    printf("Number of Resizes = %d\n",noOfResizes);

    return 0;
}