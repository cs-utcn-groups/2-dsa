#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int Value;
    struct node *next;
}NODE;

NODE* First, *Last;

void Initialize();
void ParseString(char *StrBuf);
