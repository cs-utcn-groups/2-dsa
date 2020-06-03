#include "io.h"
#include "files.h"
#include "hashTable.h"

int main()
{
    FILE * output = fopen("..//output.txt", "w");
    //int N = _10000;
    int NArray[8] = {_100, _500, _1000, _5000, _10000, _25000,  _50000, _100000};
    //printContentToConsole(content,N);
    fprintf(output, "For size factor %.2f\n", INITIAL_HT_SIZE_FACTOR);
    for(int i=0; i<8; i++) {
        char ** content = readFromFile(NArray[i]);
        initHashTable(NArray[i]);
        for (int j = 0; j < NArray[i]; j++) {
            insertElement(content[j]);
        }
        computeDistributionsPerBucket(NArray[i]);
        double stdDev = computeStandardDeviation();
        fprintf(output, "Standard deviation for %d elements: %.2f\n", NArray[i], stdDev);
    }
    return 0;
}
