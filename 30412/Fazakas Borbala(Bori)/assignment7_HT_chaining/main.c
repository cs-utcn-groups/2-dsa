#include "io.h"
#include "files.h"
#include "hashTable.h"
#include <stdio.h>


int main()
{
    int noFunctions = 4;
    int noPossibleSizeFactors = 6;
    int noPossibleSizes = 8;
    int noStrings[8]={100, 500, 100, 5000, 10000, 25000, 50000, 100000};
    int functionNr, N;
    float sizeFactor;
    double avgSD[4]={0}, SD;
    for(int i=0; i<noPossibleSizes; i++){
        N = noStrings[i];
        char** content = readFromFile(N);
        FILE* inputs = fopen("inputs.txt", "r");
        for(int j=1; j<=noFunctions*noPossibleSizeFactors; j++){
            fscanf(inputs, "%d %f", &functionNr, &sizeFactor);
            setInitialSizeFactor(sizeFactor);
            initHashTable(N, functionNr);
            for(int k=0; k<N; k++) {
                insertElement(content[k]);
            }
            SD = standartDeviationOfBucketLengths();
            avgSD[functionNr]+=SD;
            printf("SD for hash function %d with %d data rows, and initial size factor %f is: %.3lf\n", functionNr, N, sizeFactor, SD);
        }
        fclose(inputs);
    }

    for(int i=0; i<4; i++){
        avgSD[i]/=noPossibleSizeFactors*noPossibleSizes;
        printf("Average standard deviation for hash function nr. %d is %.3lf\n", i, avgSD[i]);
    }



    return 0;
}