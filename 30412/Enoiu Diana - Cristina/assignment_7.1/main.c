#include "io.h"
#include "files.h"
#include "hashTable.h"

void hash(int N,char ** content);
int main()
{
    int N = _100000;
    out = fopen("../output.data","w");
    ISF = fopen("../ISF.data","r");

    char ** content = readFromFile(N);

    enum States { H0, H1, H2, H3};
    int done = 0;
    state = 0;
    while(done != 1) {
        switch (state) {
            case H0: {
                fprintf(out,"//////////////////////////////////////////////////////////////////////////////////////////////\n"
                            "Hash Function 0:\n");
                hash(N,content);
                state++;
                break;
            }
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
    if(N>1000) printf("Distribution per bucket takes some time..\n");
    return 0;
}
void hash(int N,char ** content) {
    for(int j=0; j<6; j++) {
        fscanf(ISF,"%f",&INITIAL_HT_SIZE_FACTOR);
        fprintf(out,"ISF is %.2lf\n",INITIAL_HT_SIZE_FACTOR);
        initHashTable(N);
        for (int i = 0; i < N; i++) {
            insertElement(*(content + i));
        }
        if(N<=1000)computeDistributionsPerBucket(N);

        fprintf(out, "Standard Deviation: %.3lf\n\n", calculateStandardDeviation());
    }
}
