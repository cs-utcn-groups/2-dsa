#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define MAX_LENGTH 200

int main()
{
    FILE *f = fopen("input.dat", "r");
    FILE *g = fopen("output.dat", "w");

    Initialize();

    int N;
    fscanf(f, "%d", &N);
    int Value;
    Sentinel->Strength =0;
    for (int i=0; i<N; i++)
    {
        fscanf(f, "%d", &Value);
        AddLast(Sentinel, Value);
        Sentinel->Strength+=Value;
    }

    int M;
    fscanf(f, "%d%*c", &M);
    char *StrBuf=(char*)malloc(sizeof(char)*MAX_LENGTH);
    for (int i=0; i<M; i++)
    {
        fgets(StrBuf, MAX_LENGTH, f);
        ParseString(StrBuf, i);
    }

    AttackSuccess(M);
    LastHit(M);
    StrongestCountry(M);
    WeakestCountry(M);
    DefeatAllSentinels(M);

    return 0;
}
