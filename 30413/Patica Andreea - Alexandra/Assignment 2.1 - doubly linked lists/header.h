#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int Value;
    struct node *next;
    struct node *prev;
}NODE;

typedef struct s
{
    NODE *First;
    NODE *Last;
}SENTINEL;

SENTINEL *Sentinel;

void Initialize();
void ParseString(char *StrBuf);
