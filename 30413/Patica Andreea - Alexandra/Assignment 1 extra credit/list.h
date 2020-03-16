#include <stdlib.h>
#include <stdio.h>

#define MAX_LENGTH 200

typedef struct Node
{
    int Value;
    struct node *Next;
}NODE;

typedef struct List
{
    char *Name;
    int Strength;
    NODE *First;
    NODE *Last;
}LIST;

LIST *Sentinel, **Country;

void Initialize();
void AddLast(LIST *Struct, int Value);
void ParseString (char *StrBuf, int I);
void AttackSuccess(int M);
void LastHit(int M);
void StrongestCountry(int M);
void WeakestCountry(int M);
void DefeatAllSentinels(M);

