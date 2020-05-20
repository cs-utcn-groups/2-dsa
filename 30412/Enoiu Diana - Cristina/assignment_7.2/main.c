#include "io.h"
#include "files.h"
#include "hashTable.h"

void hash (int N,char ** content);
int main()
{
    int N = _1000;

    char ** content = readFromFile(N);
    out = fopen("../output.data","w");
    isf_mmf = fopen("../ISF_MMF.data","r");

    enum States { H1, H2, H3};
    int done = 0;
    state = 0;
    while(done != 1) {
        switch (state) {
            case H1: {
                fprintf(out,"//////////////////////////////////////////////////////////////////////////////////////////////\n"
                            "Hash Function 1:\n");
                hash(N,content);
                state++;
                break;
            }
            case H2: {
                fprintf(out,"//////////////////////////////////////////////////////////////////////////////////////////////\n"
                            "Hash Function 2:\n");
                hash(N,content);
                state++;
                break;
            }
            case H3: {
                fprintf(out,"//////////////////////////////////////////////////////////////////////////////////////////////\n"
                            "Hash Function 3:\n");
                hash(N,content);
                state++;
                done = 1;
                break;
            }

        }
    }

    return 0;
}

void hash (int N,char ** content) {
    for (int j = 0; j < 6; j++) {
        fscanf(isf_mmf, "%f%f", &INITIAL_HT_SIZE_FACTOR, &MAX_FILL_FACTOR);
        initHashTable(N);
        int noOfCollisions = 0, maxCollisions = 0;
        for (int i = 0; i < N; i++) {
            noOfCollisions = insertElement(*(content + i));
            if (maxCollisions < noOfCollisions) {
                maxCollisions = noOfCollisions;
            }
        }
        fprintf(out, "For ISF = %.2lf and MMF = %.2lf\n", INITIAL_HT_SIZE_FACTOR, MAX_FILL_FACTOR);
        fprintf(out, "No of collisions:%d\nNo of resizes:%d\n\n", maxCollisions, noOfResizes);
    }
}