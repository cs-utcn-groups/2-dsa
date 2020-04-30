#include <stdio.h>
#include "io.h"
#include "hashTable.h"

int main() {
    FILE* tableFile = fopen("table.txt", "w");
    int noFunctions = 4, noPossibleSizeFactors = 6, noPossibleSizes = 8, functionNr, N;
    int noStrings[8]={100, 500, 100, 5000, 10000, 25000, 50000, 100000};
    float initSizeFactor, maxFillFactor;
    int maxCollisions=0, currentCollisions = 0, totalCollisions=0;
    for(int i=0; i<noPossibleSizes; i++){
        N = noStrings[i];
        fprintf(tableFile, "-----------------------------------For %d strings--------------------------------------\n", N);
        char** content = readFromFile(N);
        FILE* inputs = fopen("inputs.txt", "r");
        for(int j=1; j<=noFunctions*noPossibleSizeFactors; j++){
            fscanf(inputs, "%d %f %f", &functionNr, &initSizeFactor, &maxFillFactor);
            setInitialSizeFactor(initSizeFactor);
            setMaxFillFactor(maxFillFactor);
            initHashTable(N, functionNr);
            totalCollisions=0;
            maxCollisions=0;
            for(int k=0; k<N; k++) {
                currentCollisions = insertElement(content[k]);
                totalCollisions+=currentCollisions;
                if(currentCollisions>maxCollisions){
                    maxCollisions=currentCollisions;
                }
            }
            printf("finished test nr %d\n", j);
            fprintf(tableFile, "For hashFunction nr.%d, ISF = %f and MFF = %f --> Max.collisions = %d, Avg.collisions = %lf, No. resizes = %d\n", functionNr, initSizeFactor, maxFillFactor, maxCollisions, (double)totalCollisions/(double)N, noResizes);
        }
        printf("finished size %d\n", i);
        fclose(inputs);
    }
    return 0;
}